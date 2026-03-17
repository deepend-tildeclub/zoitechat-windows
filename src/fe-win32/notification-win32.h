#ifndef ZOITECHAT_FE_WIN32_NOTIFICATION_WIN32_H
#define ZOITECHAT_FE_WIN32_NOTIFICATION_WIN32_H

#include "../common/fe.h"

void fe_win32_notification_init (void);
void fe_win32_notification_cleanup (void);
void fe_win32_notification_show (fenotify kind);
void fe_win32_notification_set_icon (feicon icon);
void fe_win32_notification_set_tooltip (const char *text);

#endif
