# foreex
#
# Copyright (C) 2022 Max Harmathy <harmathy@secure.mailbox.org>
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU Affero General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Affero General Public License for more details.
#
# You should have received a copy of the GNU Affero General Public License
# along with this program.  If not, see <http://www.gnu.org/licenses/>.

cmake_minimum_required(VERSION 3.1)

project(foreex LANGUAGES C)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_C_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Freetype REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(FONTCONFIG REQUIRED fontconfig)
pkg_check_modules(HARFBUZZ REQUIRED harfbuzz)

set(foreex_SRCS
  src/main.c
)

add_executable(${PROJECT_NAME} ${foreex_SRCS})

target_include_directories(${PROJECT_NAME} PUBLIC
  "${FREETYPE_INCLUDE_DIRS}"
  "${FONTCONFIG_INCLUDE_DIRS}"
  "${HARFBUZZ_INCLUDE_DIRS}"
)

target_compile_definitions(${PROJECT_NAME} PRIVATE )

target_link_libraries(${PROJECT_NAME} PRIVATE
  "${FREETYPE_LIBRARIES}"
  "${FONTCONFIG_LIBRARIES}"
  "${HARFBUZZ_LIBRARIES}"
)
