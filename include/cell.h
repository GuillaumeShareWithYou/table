#pragma once
#include <optional>
#include <iostream>
#include <map>

class Cell {

public:
	Cell() = default;
	explicit Cell(int note);
	std::optional<int> grade;
	

	Cell& operator=(const int value);
	friend std::ostream& operator<<(std::ostream& os, Cell& cell);
	friend std::istream& operator>>(std::istream& is, Cell& cell);
};
