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

#ifndef AGS_SHARED_AC_INVENTORYITEMINFO_H
#define AGS_SHARED_AC_INVENTORYITEMINFO_H

namespace AGS { namespace Common { class Stream; } }
using namespace AGS; // FIXME later

#define IFLG_STARTWITH 1
struct InventoryItemInfo {
    char name[25];
    int  pic;
    int  cursorPic, hotx, hoty;
    int  reserved[5];
    char flags;

    void ReadFromFile(Common::Stream *in);
    void WriteToFile(Common::Stream *out);
    void ReadFromSavegame(Common::Stream *in);
    void WriteToSavegame(Common::Stream *out) const;
};

#endif