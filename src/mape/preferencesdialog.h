/*
 * mape - C4 Landscape.txt editor
 *
 * Copyright (c) 2005-2009, Armin Burgmeier
 *
 *
 *
 */

#ifndef INC_MAPE_PREFERENCESDIALOG_H
#define INC_MAPE_PREFERENCESDIALOG_H

#include <gtk/gtk.h>
#include "mape/forward.h"

struct MapePreferencesDialog_ {
	GtkWidget* dialog;

	GtkWidget* hbox_tab_width;
	GtkWidget* lbl_tab_width;
	GtkWidget* ent_tab_width;

	GtkWidget* cbx_tab_to_spaces;
	GtkWidget* cbx_auto_indentation;
	GtkWidget* cbx_text_wrapping;
	GtkWidget* cbx_line_numbers;
	GtkWidget* cbx_highlight_line;
	GtkWidget* cbx_bracket_matching;
	GtkWidget* cbx_fixed_seed;

	GtkWidget* hbox_random_seed;
	GtkWidget* lbl_random_seed;
	GtkWidget* ent_random_seed;
	
	GtkWidget* hbox_map_width;
	GtkWidget* lbl_map_width;
	GtkWidget* ent_map_width;
	GtkWidget* hbox_map_height;
	GtkWidget* lbl_map_height;
	GtkWidget* ent_map_height;
	GtkWidget* hbox_map_zoom;
	GtkWidget* lbl_map_zoom;
	GtkWidget* ent_map_zoom;
};

MapePreferencesDialog* mape_preferences_dialog_new(GtkWindow* parent,
                                                   MapePreferences* prefs);
void mape_preferences_dialog_destroy(MapePreferencesDialog* dialog);

MapePreferences mape_preferences_dialog_get(MapePreferencesDialog* dialog);

#endif /* INC_MAPE_PREFERENCESDIALOG_H */
