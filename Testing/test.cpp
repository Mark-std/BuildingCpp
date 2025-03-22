#include "pch.h"
#include "Cont.h"

Container c;

TEST(Rent_Container, CreatingAndPulling) {
	c.read_from_file("info.txt");
	ASSERT_EQ(c.get_top(), 3);
}

TEST(Rent_Contaniner, CheckTotalCost) {
	ASSERT_EQ(c.calc_total_cost("Kovalcheyko 1"), 4250);
}

TEST(Rent_Container, manualPushinRent) {
	ASSERT_TRUE(c.add_rent(Rent(30, 6000., "Teatralna 3", 86., 4)));
}

TEST(Rent_Container, LastElementCheck) {
	ASSERT_EQ(c[c.get_top()-1].getStreet(), "Teatralna 3");
}