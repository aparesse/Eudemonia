#include "ch_13_ex_30.h"

int main()
{
	HasPtr hp_a("testa");
	HasPtr hp_b("testb");

	hp_a.show();
	hp_b.show();

	swap(hp_a, hp_b);

	std::cout << "==========" << std::endl;

	hp_a.show();
	hp_b.show();
}
