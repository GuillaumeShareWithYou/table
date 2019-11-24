#include "page.h"
#include <iostream>
#include <iomanip>
#include <exception>
#include <string>
#include <sstream>
#include <windows.h>

Page::Page(const std::string& className, const std::vector<std::string>& students, const std::vector<std::string>& coursesNames) {
	this->className = className;
	for(auto& student : students) {
		Line line(coursesNames);
		this->insert({ student, line });
	}
}

void Page::write(const std::string& name, std::istream& stream) {
	try {
		Line& line = this->at(name);
		if (line.empty()) {
			std::cout << name << " is not in the page." << std::endl;
			return;
		}
		std::stringstream ss("");
		for(auto& course: line) {
			ss << course.first + " ";
		}
		std::cout << ss.str() << std::endl;
		for (auto& course : line) {
			int grade;
			stream >> grade;
			course.second.grade = grade;
		}
	}
	catch (std::exception& e) {
		std::cout << name << " does not exists in class : " << className << "\n";
	}

	stream.clear();
}

template <typename T>
void fillWithSpace(std::ostream& os, T content, int size, const char* color="") {
	const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if(std::strcmp(color, "red") == 0) {
		// if color is red
	
		SetConsoleTextAttribute(hConsole, 12);
	} else if(std::strcmp(color, "green") == 0) {
		SetConsoleTextAttribute(hConsole, 2);
	}
	os << std::setw(size) << content;
	// go back to black
	SetConsoleTextAttribute(hConsole, 7);
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
	fillWithSpace(os, "\\", leftWidth);
	for(auto& course: courses) {
		fillWithSpace(os, course.first, tabWidth);
		os << "\t"; // maybe
	}
	fillWithSpace(os, "Average", tabWidth);
	os << "\n";
	// for every student, print name then grades
	for(auto& line : page) {
		auto studentName = line.first;
		Line& studentGrades = line.second;
		os << std::setw(leftWidth) << studentName; // student name
		for(auto& grade: studentGrades) {
			fillWithSpace(os, grade.second, tabWidth);
			os << "\t";
		}
		const auto avg = studentGrades.average();
		fillWithSpace(os, avg, tabWidth, avg < 10.0 ? "red": avg > 15 ? "green" : "");
		os << "\n";
	}
	return os;
}
