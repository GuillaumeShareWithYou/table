#include "inc.h"
#include "page.h"

TEST(Page, DISABLED_try_access_unknown_name) {

	Page page( "classe de toto", { "Toto" }, { "Maths" });
	page.write("titi", std::istringstream("1 1 1"));
	
}
TEST(Page, try_access_known_name) {
	const std::string toto = "Toto";
	const std::string titi = "Titi";
	const std::string tata = "Tata";
	Page page( "classe de toto", { toto, titi, tata }, { "Maths", "French", "Japanese" });

	std::stringstream ss{ "10 11 12" };
	page.write(toto, ss);

	ss.str("10 10 10");
	page.write(titi, ss);

	ss.str("10 -1 8");
	page.write(tata, ss);
	
	std::cout << page;
}
TEST(Page, DISABLED_average_by_course) {
	const std::string toto = "Toto";
	const std::string titi = "Titi";
	Page page( "classe de toto", { toto, titi }, { "Maths" });

	std::stringstream ss{ "10" };
	page.write(toto, ss);

	ss.str("16");
	page.write(titi, ss);

	EXPECT_EQ(page.average("Maths"), 13);
}