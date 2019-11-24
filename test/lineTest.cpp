#include "inc.h"
#include "line.h"
#include <vector>
#include <algorithm>
#include <string>
#include "cell.h"
TEST(Line, empty_line) {
	const Line line;
	EXPECT_TRUE(line.empty());
}
TEST(Line, courses_no_grade) {
	std::vector<std::string> names;
	names.emplace_back(std::string("Maths"));
	names.emplace_back(std::string("English"));
	const Line line(names);
	EXPECT_FALSE(line.empty());

	std::for_each(line.begin(), line.end(), [](std::pair<std::string, Cell> pair) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	});
	
}
TEST(Line, courses_with_random_grade) {
	std::vector<std::string> names;
	names.emplace_back(std::string("Maths"));
	names.emplace_back(std::string("English"));
	Line line(names);
	for(auto& x: line) {
		x.second.grade = rand() % 21;
	}
	std::for_each(line.begin(), line.end(), [](std::pair<const std::string, Cell> pair) {
		std::cout << pair.first << ": " << pair.second << std::endl;
	});
	
	EXPECT_FALSE(line.empty());
	EXPECT_EQ(line.size(), 2);
}

TEST(Line, write) { // skip tests because I don't want to type every time
	Line line({ "A", "V", "C" });
	std::istringstream is("11 9 12");
	line.write(is);
	std::cout << line;
}
TEST(Line, average) {
	Line line({ "A", "V", "C" });
	line["A"] = 10;
	line["V"] = 12;
	line["C"] = 14;
	const auto mean = line.average();
	EXPECT_EQ(mean, 12);
}