#include "pch.h"
#include "../Building/Cont.h"

Container c;
const char* file_output_test = "result_test_file.txt";

TEST(Rent_Container, CreatingAndPulling) {
	c.read_from_file("info.txt");
	ASSERT_EQ(c.get_top(), 4);
}

TEST(Rent_Contaniner, CheckTotalCost) {
	ASSERT_EQ(c.calc_total_cost("Kovalcheyko 1"), 4250);
}

TEST(Rent_Container, ManualPushinRent) {
	ASSERT_TRUE(c.add_rent(Rent(30, 6000., "Teatralna 3", 86., 4)));
}

TEST(Rent_Container, LastElementCheck) {
	ASSERT_EQ(c[c.get_top()-1].getStreet(), "Teatralna 3");
}
TEST(Rent_Container, DeleteExistingRent) {
	size_t before = c.get_top();
	ASSERT_TRUE(c.delete_rent("Dmytro 2"));
	ASSERT_EQ(c.get_top(), before - 1);
}
TEST(Rent_Container, SaveToFile) {
	ASSERT_TRUE(c.save_to_file(file_output_test));
}
TEST(Rent_Container, LoadAfterSavingRentsFromFile) {
	Container m;
	m.read_from_file(file_output_test);
	ASSERT_EQ(m.get_top(), 4);
}