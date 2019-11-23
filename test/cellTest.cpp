#include "inc.h"
#include "cell.h"

TEST(Cell, default_value) {
	const Cell cell;
	const int defaultValue = 10;
	EXPECT_FALSE(cell.grade.has_value());
	EXPECT_EQ(cell.grade.value_or(defaultValue), defaultValue);
}
TEST(Cell, with_value) {
	const int grade = 20;
	const Cell cell(grade);
	EXPECT_TRUE(cell.grade.has_value());
	EXPECT_EQ(cell.grade.value(), grade);
}
TEST(Cell, handle_empty) {
	const Cell cellEmpty;
	const char* expectedMessage = "absent";
	const char* message = cellEmpty.grade.has_value() ? "" : expectedMessage;
	EXPECT_STRCASEEQ(expectedMessage, message);
}