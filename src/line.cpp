#include "line.h"
#include <algorithm>
#include "cell.h"
#include <iostream>

Line::Line(const std::vector<std::string>& courseNames) {
	std::for_each(courseNames.begin(), courseNames.end(), [&](const std::string& name) {
		this->insert(std::make_pair( name, Cell()));
	});
}



std::ostream& operator<<(std::ostream& os, Line& line) {
	for(auto& value: line) {
		os << value.first << ": " << value.second << std::endl;
	}
	return os;
}

