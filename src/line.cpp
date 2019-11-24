#include "line.h"
#include <algorithm>
#include "cell.h"
#include <iostream>

Line::Line(const std::vector<std::string>& courseNames) {
	std::for_each(courseNames.begin(), courseNames.end(), [&](const std::string& name) {
		this->insert(std::make_pair( name, Cell()));
	});
}

double Line::average() {
	double sum = 0;
	int examsDone = size();
	for(std::pair<const std::string, Cell>& pair : *this) {
		// if student was present we take the grade
		if(pair.second.grade.has_value()) {
			sum += pair.second.grade.value();
		} else {
			// otherwise we don't count it in the average
			--examsDone;
		}
	}
	// no grades, we don't want to divide by zero
	if(examsDone == 0) {
		return 0;
	}
	return sum / examsDone;
}

void Line::write(std::istream& stream) {
	stream >> *this;
}


std::ostream& operator<<(std::ostream& os, Line& line) {
	for(auto& value: line) {
		os << value.second << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, Line& line) {
	for(auto& cell: line) {
		is >> cell.second;
	}
	return is;
}

