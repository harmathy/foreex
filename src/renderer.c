/* renderer.c
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

#include "renderer.h"
#include <string.h>

const char* foreex_copy_fc_string(const FcChar8* fcString) {
    const char* tmp = (const char*) (fcString);
    size_t len = strlen(tmp) + 1;
    char* result = malloc(sizeof(char) * len);
    strncpy(result, tmp, len);
    return result;
}

const char* foreex_retrieve_path(FcConfig* fontConfig, const char* font) {
    FcPattern* pattern = FcNameParse((const FcChar8*) font);
    FcConfigSubstitute(NULL, pattern, FcMatchPattern);
    FcDefaultSubstitute(pattern);

    // actual font substitution
    FcResult fcResult;
    FcPattern* match = FcFontMatch(fontConfig, pattern, &fcResult);
    if (fcResult != FcResultMatch) {
        FcPatternDestroy(match);
        return "";
    }

    // select the font file from the result
    FcChar8* fontFacePath;
    FcResult result = FcPatternGetString(match, FC_FILE, 0, &fontFacePath);
    const char* path = (result == FcResultMatch) ? foreex_copy_fc_string(fontFacePath) : "";

    // and clean up
    FcPatternDestroy(pattern);
    FcPatternDestroy(match);

    return path;
}
