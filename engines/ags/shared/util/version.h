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

//=============================================================================
//
// Class, depicting version of the AGS engine
//
//=============================================================================

#ifndef AGS_SHARED_UTIL_VERSION_H
#define AGS_SHARED_UTIL_VERSION_H

#include "ags/shared/util/string.h"

namespace AGS3 {
namespace AGS {
namespace Shared {

using Shared::String;

struct Version {
	int Major;
	int Minor;
	int Release;
	int Revision;
	String  Special;
	String  BuildInfo;

	String  LongString;
	String  ShortString;
	String  BackwardCompatibleString;

	// Last engine version, using different version format than AGS Editor (3.22.1120 / 3.2.2.1120)
	static const Version LastOldFormatVersion;

	Version();
	Version(int major, int minor, int release);
	Version(int major, int minor, int release, int revision);
	Version(int major, int minor, int release, int revision, const String &special);
	Version(int major, int minor, int release, int revision, const String &special, const String &build_info);
	Version(const String &version_string);

	inline int AsNumber() const {
		return Major * 10000 + Minor * 100 + Release;
	}

	inline int64 AsLongNumber() const {
		return (int64)Major * 100000000L + (int64)Minor * 1000000L + (int64)Release * 10000L + Revision;
	}

	inline int AsSmallNumber() const {
		return Major * 100 + Minor;
	}

	void SetFromString(const String &version_string);

	inline bool operator < (const Version &other) const {
		return AsLongNumber() < other.AsLongNumber();
	}

	inline bool operator <= (const Version &other) const {
		return AsLongNumber() <= other.AsLongNumber();
	}

	inline bool operator > (const Version &other) const {
		return AsLongNumber() > other.AsLongNumber();
	}

	inline bool operator >= (const Version &other) const {
		return AsLongNumber() >= other.AsLongNumber();
	}

	inline bool operator == (const Version &other) const {
		return AsLongNumber() == other.AsLongNumber();
	}

	inline bool operator != (const Version &other) const {
		return AsLongNumber() != other.AsLongNumber();
	}

private:
	void MakeString();
};

} // namespace Shared
} // namespace AGS
} // namespace AGS3

#endif