#include "inc.h"
#include "line.h"

int main() {
	Line line({ "Maths", "English", "French", "Physics" });
	for (auto& value : line) {
		value.second = rand() % 21;
	}
	std::cout << line << std::endl;

	return 0;
}
