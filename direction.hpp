#pragma once

#include <vector>
#include <array>

enum class Direction: uint8_t{ // intentionally not enum class now
	UTTAR = 0,	// North
	PURVA,		// EAST
	PASHCHIM,	// WEST
	DAKSHIN,	// SOUTH
	ISHANYA,	// North-East
	AGNEYA,		// South-East
	NAIRUTYA,	// South-West
	VAYAVYA,	// North-West
	URDHWA,		// (Akash) Skywards/Upwards
	ADHARASTHA	// (Patal) Downwards
};

namespace util {
    bool areDirectionsOpposite(Direction d1, Direction d2) {
		switch (d1)
		{
		case Direction::UTTAR:
			return d2 == Direction::PURVA;
		case Direction::PURVA:
			return d2 == Direction::UTTAR;
		case Direction::PASHCHIM:
			return d2 == Direction::DAKSHIN;
		case Direction::DAKSHIN:
			return d2 == Direction::PASHCHIM;
		case Direction::ISHANYA:
			return d2 == Direction::NAIRUTYA;
		case Direction::AGNEYA:
			return d2 == Direction::VAYAVYA;
		case Direction::NAIRUTYA:
			return d2 == Direction::ISHANYA;
		case Direction::VAYAVYA:
			return d2 == Direction::AGNEYA;
		case Direction::URDHWA:
			return d2 == Direction::ADHARASTHA;
		case Direction::ADHARASTHA:
			return d2 == Direction::URDHWA;
		}
	}
}

namespace statics{
	inline namespace graph_statics {
		static std::array<Direction, 10> directions{ Direction::UTTAR, Direction::PURVA, Direction::PASHCHIM, Direction::DAKSHIN, Direction::ISHANYA, Direction::AGNEYA, Direction::NAIRUTYA, Direction::VAYAVYA, Direction::URDHWA, Direction::ADHARASTHA };
	}
}

// could use std::queue or std::list too, that would allow popping too, but i have not done so that the allocations are at minimum
typedef std::vector<Direction>  directionalPath;