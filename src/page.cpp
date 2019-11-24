#include "page.h"
#include <iostream>
#include <iomanip>
#include <exception>

Page::Page(const std::string& className, const std::vector<std::string>& students, const std::vector<std::string>& coursesNames) {
	this->className = className;
	for(auto& student : students) {
		Line line(coursesNames);
		this->insert({ student, line });
	}
}

void Page::write(const std::string& name) {
	try {
		Line& line = this->at(name);
		if (line.empty()) {
			std::cout << name << " is not in the page." << std::endl;
			return;
		}
		for (std::pair<const std::string, Cell>& course : line) {
			std::cout << course.first << " = ";
			int grade;
			std::cin >> grade;
			course.second.grade = grade;
		}
	}
	catch (std::exception& e) {
		std::cout << name << " does not exists in class : " << className << "\n";
	}
}

std::ostream& operator<<(std::ostream& os, Page& page) {
	const int tabWidth = 20;
	const int leftWidth = 15;
	if(page.empty()) {
		os << "page is empty";
		return os;
	}
	std::string className = page.className;
	for (auto& c : className) c = toupper(c);
	os << className << "\n";
	auto firstLine = page.begin();
	auto& courses = firstLine->second;
	// print the courses names in header
	os << std::setw(leftWidth) << "\\";
	for(auto& course: courses) {
		os << std::setw(tabWidth) << course.first << "\t";
	}
	os << "\n";
	// for every student, print name then grades
	for(auto& lines : page) {
		os << std::setw(leftWidth) << lines.first; // student name
		for(auto& grade: lines.second) {
			os << std::setw(tabWidth) << grade.second << "\t";
		}
		os << "\n";
	}
	return os;
}
