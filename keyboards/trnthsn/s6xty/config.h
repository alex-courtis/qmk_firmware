/*
Copyright 2024 ThanhSon.Mech

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define WS2812_SPI_DRIVER SPID2
#define WS2812_SPI_SCK_PIN B13

// this is necessary only for the right side !?
#ifdef NKRO_ENABLE
#define FORCE_NKRO
#endif

#define USE_SERIAL

#undef PRODUCT
#define PRODUCT "Dactyl Manuform 6x6"

// #define MASTER_LEFT
#define MASTER_RIGHT

//#define EE_HANDS
