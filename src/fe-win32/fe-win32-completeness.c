#include "../common/fe.h"
#include <glib.h>

typedef void (*fe_any_fn) (void);

static fe_any_fn const fe_required_symbols[] = {
	(fe_any_fn) fe_args,
	(fe_any_fn) fe_init,
	(fe_any_fn) fe_main,
	(fe_any_fn) fe_cleanup,
	(fe_any_fn) fe_exit,
	(fe_any_fn) fe_timeout_add,
	(fe_any_fn) fe_timeout_add_seconds,
	(fe_any_fn) fe_timeout_remove,
	(fe_any_fn) fe_new_window,
	(fe_any_fn) fe_new_server,
	(fe_any_fn) fe_add_rawlog,
	(fe_any_fn) fe_message,
	(fe_any_fn) fe_input_add,
	(fe_any_fn) fe_input_remove,
	(fe_any_fn) fe_idle_add,
	(fe_any_fn) fe_set_topic,
	(fe_any_fn) fe_set_tab_color,
	(fe_any_fn) fe_flash_window,
	(fe_any_fn) fe_update_mode_buttons,
	(fe_any_fn) fe_update_channel_key,
	(fe_any_fn) fe_update_channel_limit,
	(fe_any_fn) fe_is_chanwindow,
	(fe_any_fn) fe_add_chan_list,
	(fe_any_fn) fe_chan_list_end,
	(fe_any_fn) fe_add_ban_list,
	(fe_any_fn) fe_ban_list_end,
	(fe_any_fn) fe_notify_update,
	(fe_any_fn) fe_notify_ask,
	(fe_any_fn) fe_text_clear,
	(fe_any_fn) fe_close_window,
	(fe_any_fn) fe_progressbar_start,
	(fe_any_fn) fe_progressbar_end,
	(fe_any_fn) fe_print_text,
	(fe_any_fn) fe_userlist_insert,
	(fe_any_fn) fe_userlist_remove,
	(fe_any_fn) fe_userlist_rehash,
	(fe_any_fn) fe_userlist_update,
	(fe_any_fn) fe_userlist_numbers,
	(fe_any_fn) fe_userlist_clear,
	(fe_any_fn) fe_userlist_set_selected,
	(fe_any_fn) fe_uselect,
	(fe_any_fn) fe_dcc_add,
	(fe_any_fn) fe_dcc_update,
	(fe_any_fn) fe_dcc_remove,
	(fe_any_fn) fe_dcc_open_recv_win,
	(fe_any_fn) fe_dcc_open_send_win,
	(fe_any_fn) fe_dcc_open_chat_win,
	(fe_any_fn) fe_clear_channel,
	(fe_any_fn) fe_session_callback,
	(fe_any_fn) fe_server_callback,
	(fe_any_fn) fe_url_add,
	(fe_any_fn) fe_pluginlist_update,
	(fe_any_fn) fe_buttons_update,
	(fe_any_fn) fe_dlgbuttons_update,
	(fe_any_fn) fe_dcc_send_filereq,
	(fe_any_fn) fe_set_channel,
	(fe_any_fn) fe_set_title,
	(fe_any_fn) fe_set_nonchannel,
	(fe_any_fn) fe_set_nick,
	(fe_any_fn) fe_ignore_update,
	(fe_any_fn) fe_beep,
	(fe_any_fn) fe_lastlog,
	(fe_any_fn) fe_set_lag,
	(fe_any_fn) fe_set_throttle,
	(fe_any_fn) fe_set_away,
	(fe_any_fn) fe_serverlist_open,
	(fe_any_fn) fe_get_bool,
	(fe_any_fn) fe_get_str,
	(fe_any_fn) fe_get_int,
	(fe_any_fn) fe_get_file,
	(fe_any_fn) fe_ctrl_gui,
	(fe_any_fn) fe_gui_info,
	(fe_any_fn) fe_gui_info_ptr,
	(fe_any_fn) fe_confirm,
	(fe_any_fn) fe_get_inputbox_contents,
	(fe_any_fn) fe_get_inputbox_cursor,
	(fe_any_fn) fe_set_inputbox_contents,
	(fe_any_fn) fe_set_inputbox_cursor,
	(fe_any_fn) fe_open_url,
	(fe_any_fn) fe_menu_del,
	(fe_any_fn) fe_menu_add,
	(fe_any_fn) fe_menu_update,
	(fe_any_fn) fe_server_event,
	(fe_any_fn) fe_tray_set_flash,
	(fe_any_fn) fe_tray_set_file,
	(fe_any_fn) fe_tray_set_icon,
	(fe_any_fn) fe_tray_set_tooltip,
	(fe_any_fn) fe_open_chan_list,
	(fe_any_fn) fe_get_default_font,
};

G_STATIC_ASSERT (FE_COLOR_NONE == 0);
G_STATIC_ASSERT (FE_COLOR_NEW_DATA == 1);
G_STATIC_ASSERT (FE_COLOR_NEW_MSG == 2);
G_STATIC_ASSERT (FE_COLOR_NEW_HILIGHT == 3);
G_STATIC_ASSERT (FE_COLOR_FLAG_NOOVERRIDE == 8);
G_STATIC_ASSERT (FE_GUI_HIDE == 0);
G_STATIC_ASSERT (FE_GUI_SHOW == 1);
G_STATIC_ASSERT (FE_GUI_FOCUS == 2);
G_STATIC_ASSERT (FE_GUI_FLASH == 3);
G_STATIC_ASSERT (FE_GUI_COLOR == 4);
G_STATIC_ASSERT (FE_GUI_ICONIFY == 5);
G_STATIC_ASSERT (FE_GUI_MENU == 6);
G_STATIC_ASSERT (FE_GUI_ATTACH == 7);
G_STATIC_ASSERT (FE_GUI_APPLY == 8);
G_STATIC_ASSERT (FE_ICON_NORMAL == 0);
G_STATIC_ASSERT (FE_ICON_MESSAGE == 2);
G_STATIC_ASSERT (FE_ICON_HIGHLIGHT == 5);
G_STATIC_ASSERT (FE_ICON_PRIVMSG == 8);
G_STATIC_ASSERT (FE_ICON_FILEOFFER == 11);

size_t fe_win32_completeness_count (void)
{
	return G_N_ELEMENTS (fe_required_symbols);
}
