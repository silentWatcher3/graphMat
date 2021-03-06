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

// equivalent to {x,y} in a matrix, this typedef defines the position of a box/point, in an intuitive way (to me atleast :D), and feels more closer to the implementation than to give indices, since here we have directions mostly
typedef std::vector<std::pair< Direction, uint16_t >> graph_position;

namespace util {
	inline auto getOppositeDirection(Direction d) {
		switch (d)
		{
		case Direction::UTTAR:
			return Direction::PURVA;
		case Direction::PURVA:
			return Direction::UTTAR;
		case Direction::PASHCHIM:
			return Direction::DAKSHIN;
		case Direction::DAKSHIN:
			return Direction::PASHCHIM;
		case Direction::ISHANYA:
			return Direction::NAIRUTYA;
		case Direction::AGNEYA:
			return Direction::VAYAVYA;
		case Direction::NAIRUTYA:
			return Direction::ISHANYA;
		case Direction::VAYAVYA:
			return Direction::AGNEYA;
		case Direction::URDHWA:
			return Direction::ADHARASTHA;
		case Direction::ADHARASTHA:
			return Direction::URDHWA;
		}
	}

	inline bool areDirectionsOpposite(Direction d1, Direction d2) {
		return d2 == getOppositeDirection(d1);
	}
}

namespace statics{
	inline namespace graph_statics {
		static std::array<Direction, 10> directions{ Direction::UTTAR, Direction::PURVA, Direction::PASHCHIM, Direction::DAKSHIN, Direction::ISHANYA, Direction::AGNEYA, Direction::NAIRUTYA, Direction::VAYAVYA, Direction::URDHWA, Direction::ADHARASTHA };
	}
}

struct directionalPath {	// @note - DONT provide front() or back() methods here ! It will be confusing, since WHILE construction, directions added to back, then when moving accessed in reverse order
	std::vector<Direction> data;

	const auto begin() const { return data.rbegin(); }
	const auto end() const { return data.rend(); }

	auto begin() { return data.rbegin(); }
	auto end() { return data.rend(); }

	//auto size() const { return data.size(); }
	auto empty() const { return data.empty(); }
	auto reserve(int sz) { data.reserve(sz); }

	auto next_dir() const {
		return data.back();
	}

	void pop() {
		data.pop_back();
	}

	directionalPath() noexcept = default;
};

// could use std::queue or std::list too, that would allow popping too, but i have not done so that the allocations are at minimum
//typedef std::vector<Direction>  directionalPath;
	// @order -> directionalPath::front() is the first one leading from the entity_head, the directions are FROM entity_head and TO end
// note - Actually std::vector is the good option here, but the ONLY problem was that we use path.front() to move, then remove, this is a O(N) shift operation, so created the wrapper struct above
