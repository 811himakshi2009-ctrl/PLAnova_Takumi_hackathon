/*
 * mape - C4 Landscape.txt editor
 *
 * Copyright (c) 2005-2009, Armin Burgmeier
 */

#ifndef INC_MAPE_C4_TEXTURE_HANDLE_H
#define INC_MAPE_C4_TEXTURE_HANDLE_H

#include <glib.h>

#include "mape/cpp-handles/group-handle.h"

G_BEGIN_DECLS

typedef struct _C4TextureMapHandle C4TextureMapHandle;

C4TextureMapHandle* c4_texture_map_handle_new(void);
void c4_texture_map_handle_free(C4TextureMapHandle* texture_map);

guint c4_texture_map_handle_load_map(C4TextureMapHandle* texture_map, C4GroupHandle* group, const char* entry_name, gboolean* overload_materials, gboolean* overload_textures);
gboolean c4_texture_map_handle_add_texture(C4TextureMapHandle* texture_map, const char* texture, guint32 avg_color);
const char* c4_texture_map_handle_get_texture(C4TextureMapHandle* texture_map, guint index);

const char* c4_texture_handle_get_entry_material_name(C4TextureMapHandle* texture_map, guint index);
const char* c4_texture_handle_get_entry_texture_name(C4TextureMapHandle* texture_map, guint index);

guint32 c4_texture_handle_get_average_texture_color(C4TextureMapHandle* texture_map, const char* name);

G_END_DECLS

#endif /* INC_MAPE_C4_TEXTURE_HANDLE_H */
