#include "inc.h"
#include "page.h"

TEST(Page, try_access_unknown_name) {

	Page page( "classe de toto", { "Toto" }, { "Maths" });
	page.write("titi");
	
}
TEST(Page, try_access_known_name) {
	std::string toto = "Toto";
	Page page( "classe de toto", { toto, "titi" }, { "Maths", "French", "Japanese" });
	page.write(toto);
	page.write("titi");
	page.write("tata"); // [] operator actually create tata, that's an issue
	
	std::cout << page;
}