#pragma once
#include <optional>
#include <ostream>
#include <map>

class Cell {

public:
	Cell() = default;
	explicit Cell(int note);
	std::optional<int> grade;
	

	Cell& operator=(const int value);
	friend std::ostream& operator<<(std::ostream& os, Cell& cell);
};
