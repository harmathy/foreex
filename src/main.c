/* main.c
 *
 * Copyright 2022 Max Harmathy <harmathy@alumni.tum.de>
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
#include <stdio.h>

int main(int argc, char* argv[]) {
    FcBool fontconfigInit = FcInit();
    if (fontconfigInit == FcFalse) {
        fprintf(stderr, "Fontconfig initialization failed");
        return EXIT_FAILURE;
    }
    FcConfig* fontConfig = FcInitLoadConfigAndFonts();
    char* font = "Helvetica";
    const char* path = foreex_retrieve_path(fontConfig, font);
    printf("Would load file \"%s\" for font \"%s\"\n", path, font);
    free(fontConfig);
    return EXIT_SUCCESS;
}
