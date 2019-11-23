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