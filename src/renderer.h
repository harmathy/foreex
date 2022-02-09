/* renderer.h
 *
 * Copyright 2022 Max Harmathy <harmathy@mailbox.org>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef FOREEX_RENDERER_H
#define FOREEX_RENDERER_H

#include <ft2build.h>
#include FT_FREETYPE_H
#include <fontconfig/fontconfig.h>
#include <hb.h>

/**
 * @brief frx_retrieve_path fetches the path of a specified font.
 *
 * Here the Fontconfig library is used to substitute the font according to the
 * system settings and to locate the font file. The font file path can be used
 * to load the font in FreeType. The path is copied from the Fontconfig data
 * structures which are destroyed after this method call.
 *
 * @param font name to specify the font
 * @return path to the font file
 */
const char* foreex_retrieve_path(FcConfig* fontConfig, const char* font);


#endif // FOREEX_RENDERER_H
