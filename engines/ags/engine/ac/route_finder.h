/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef AGS_ENGINE_AC_ROUTEFND_H
#define AGS_ENGINE_AC_ROUTEFND_H

#include "ac/game_version.h"

// Forward declaration
namespace AGS { namespace Common { class Bitmap; }}
struct MoveList;

void init_pathfinder(GameDataVersion game_file_version);
void shutdown_pathfinder();

void set_wallscreen(AGS::Common::Bitmap *wallscreen);

int can_see_from(int x1, int y1, int x2, int y2);
void get_lastcpos(int &lastcx, int &lastcy);
// NOTE: pathfinder implementation mostly needs to know proportion between x and y speed
void set_route_move_speed(int speed_x, int speed_y);

int find_route(short srcx, short srcy, short xx, short yy, AGS::Common::Bitmap *onscreen, int movlst, int nocross = 0, int ignore_walls = 0);
void calculate_move_stage(MoveList * mlsp, int aaa);

#endif