#pragma once
#include <map>
#include <string>
#include <vector>
#include "cell.h"

class Line : public std::map<std::string, Cell> {
public:
	Line() = default;
	explicit Line(const std::vector<std::string>& courseNames);

	double average();
	void write(std::istream& stream);
	
	friend std::ostream& operator<<(std::ostream& os, Line& line);
	friend std::istream& operator>>(std::istream& is, Line& line);
};
