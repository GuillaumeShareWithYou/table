#pragma once
#include "line.h"

class Page : public std::map<std::string, Line>{
public:
	Page(const std::string&, const std::vector<std::string>& students, const std::vector<std::string>& coursesName);
	void write(const std::string& name);
	friend std::ostream& operator<<(std::ostream& os, Page& page);
private:
	std::string className;
};
