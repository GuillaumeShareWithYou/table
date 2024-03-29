#include "cell.h"
#include <ostream>
Cell::Cell(const int note) {
	this->grade = note; // WORKS because overloaded operator=
}

Cell& Cell::operator=(const int value) {
	this->grade = value;
	return *this;
}


std::ostream& operator<<(std::ostream& os, Cell& cell) {
	std::optional<int>& grade = cell.grade;
	if(grade.has_value()) {
		os << grade.value();
	} else {
		os << "absent";
	}
	return os;
}

std::istream& operator>>(std::istream& is, Cell& cell) {
	int value = 0;
	is >> value;
	if(value != -1) {
		cell.grade = value;
	}
	return is;
}

