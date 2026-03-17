#include "config.h"

#include <gmodule.h>
#include <windows.h>

#include "notification-win32.h"
#include "../common/plugin.h"

static GModule *notification_module;
static void (*winrt_show) (const char *title, const char *text);
static int (*winrt_init) (const char **error);
static void (*winrt_deinit) (void);
static feicon notification_icon;

static const char *
fe_win32_notification_title (fenotify kind)
{
	switch (kind)
	{
	case FE_NOTIFY_HIGHLIGHT:
		return "Highlighted message";
	case FE_NOTIFY_PRIVATE:
		return "Private message";
	case FE_NOTIFY_FILEOFFER:
		return "File offer";
	case FE_NOTIFY_MESSAGE:
	default:
		return "Channel message";
	}
}

static BOOL
fe_win32_flash_taskbar (void)
{
	HWND window;
	FLASHWINFO info;

	window = GetConsoleWindow ();
	if (!window)
		return FALSE;

	info.cbSize = sizeof (info);
	info.hwnd = window;
	info.dwFlags = FLASHW_TRAY | FLASHW_TIMERNOFG;
	info.uCount = 3;
	info.dwTimeout = 0;
	return FlashWindowEx (&info);
}

void
fe_win32_notification_init (void)
{
	UINT original_error_mode;
	const char *error = NULL;

	notification_icon = FE_ICON_NORMAL;
	original_error_mode = GetErrorMode ();
	SetErrorMode (SEM_FAILCRITICALERRORS);
	notification_module = module_load (ZOITECHATLIBDIR "\\hcnotifications-winrt.dll");
	SetErrorMode (original_error_mode);
	if (!notification_module)
		return;

	g_module_symbol (notification_module, "notification_backend_show", (gpointer *) &winrt_show);
	g_module_symbol (notification_module, "notification_backend_init", (gpointer *) &winrt_init);
	g_module_symbol (notification_module, "notification_backend_deinit", (gpointer *) &winrt_deinit);
	if (!winrt_init || !winrt_show)
		return;
	if (!winrt_init (&error))
	{
		winrt_show = NULL;
		winrt_deinit = NULL;
	}
}

void
fe_win32_notification_cleanup (void)
{
	if (winrt_deinit)
		winrt_deinit ();
	winrt_show = NULL;
	winrt_init = NULL;
	winrt_deinit = NULL;
	notification_module = NULL;
}

void
fe_win32_notification_set_icon (feicon icon)
{
	notification_icon = icon;
	if (icon != FE_ICON_NORMAL)
		fe_win32_flash_taskbar ();
}

void
fe_win32_notification_set_tooltip (const char *text)
{
	(void) text;
}

void
fe_win32_notification_show (fenotify kind)
{
	const char *title;
	const char *body;

	switch (kind)
	{
	case FE_NOTIFY_HIGHLIGHT:
		fe_win32_notification_set_icon (FE_ICON_HIGHLIGHT);
		break;
	case FE_NOTIFY_PRIVATE:
		fe_win32_notification_set_icon (FE_ICON_PRIVMSG);
		break;
	case FE_NOTIFY_FILEOFFER:
		fe_win32_notification_set_icon (FE_ICON_FILEOFFER);
		break;
	case FE_NOTIFY_MESSAGE:
	default:
		fe_win32_notification_set_icon (FE_ICON_MESSAGE);
		break;
	}

	title = fe_win32_notification_title (kind);
	body = "ZoiteChat";
	if (winrt_show)
		winrt_show (title, body);
	fe_win32_flash_taskbar ();
}
