/*
 * mape - C4 Landscape.txt editor
 *
 * Copyright (c) 2005-2009, Armin Burgmeier
 */

#ifndef INC_MAPE_C4_LOG_HANDLE_H
#define INC_MAPE_C4_LOG_HANDLE_H

#include <glib.h>

G_BEGIN_DECLS

typedef struct _C4MapgenHandle C4MapgenHandle;

void c4_log_handle_clear();
const char* c4_log_handle_get_first_log_message();
unsigned int c4_log_handle_get_n_log_messages();

G_END_DECLS

#endif /* INC_MAPE_C4_LOG_HANDLE_H */
