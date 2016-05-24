/*
 *  ___  _  ___  _____ _______  _____ ___.__.______   | Swiss Army Project
 * / _/_| |_\_ \ \__  \\_  __ \/     <   |  |\____ \  | Project in C/C++ Language
 * || |_   _| ||  / __ \|  | \/  Y Y  \___  ||  |_> > |
 * ||_  |_|  _|| (____  /__|  |__|_|  / ____||   __/  | @author Luís Ferreira
 * \__\     /__/      \/            \/\/     |__|     | @license GNU Public License v3
 *
 * Copyright (c) 2016 - Luís Ferreira. All right reserved
 * More information in: https://github.com/ljmf00/ (Github Page)
 */

#ifndef COLORDEF_H_INCLUDED
#define COLORDEF_H_INCLUDED
/*
    0 = Black       8 = Gray
    1 = Blue        9 = Light Blue
    2 = Green       A = Light Green
    3 = Aqua        B = Light Aqua
    4 = Red         C = Light Red
    5 = Purple      D = Light Purple
    6 = Yellow      E = Light Yellow
    7 = White       F = Bright White
*/

enum win_color {
	COLOR_BLACK = 0x0,
	COLOR_BLUE = 0x1,
	COLOR_GREEN = 0x2,
	COLOR_AQUA = 0x3,
	COLOR_RED = 0x4,
	COLOR_PURPLE = 0x5,
	COLOR_YELLOW = 0x6,
	COLOR_WHITE = 0x7,
	COLOR_GRAY = 0x8,
	COLOR_LIGHT_BLUE = 0x9,
	COLOR_LIGHT_GREEN = 0xA,
	COLOR_LIGHT_AQUA = 0xB,
	COLOR_LIGHT_RED = 0xC,
	COLOR_LIGHT_PURPLE = 0xD,
	COLOR_LIGHT_YELLOW = 0xE,
	COLOR_BRIGHT_WHITE = 0xF,
};

#endif // COLORDEF_H_INCLUDED
