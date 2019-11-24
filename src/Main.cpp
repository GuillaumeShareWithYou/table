#include "inc.h"
#include "line.h"

int main() {
	std::vector<std::string> courses = { "Maths", "English", "French", "Physics" };
	std::vector<std::string> students = { "Jonathan", "Guillaume", "Lucien", "Etienne" };

	Page page("les 4 fantastiques", students, courses);

	for (auto& student : students) {
		std::cin >> page[student];
	}
	std::cout << page << std::endl;
	return 0;
}
