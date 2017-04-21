#include "ch_13_ex_53.h"
#include <iostream>
int main()
{
	HasPtr hp1("hello"), hp2("world"), *pH = new HasPtr("World");
	hp1 = hp2;
	hp1= std::move(*pH);
	std::cout << "will end" << std::endl;
}


// when used copy-and-swap
//
// // call constructor
// // call constructor
// // call constructor
// // call copy constructor !!!
// // call swap             !!!
// // call destructor       !!!
// // call move constructor !!!
// // call swap             !!!
// // call destructor       !!!
// // call destructor
// // call destructor
//
// // when used two assignment operator.
//
// // call constructor
// // call constructor
// // call constructor
// // call copy assignment  !!!
// // call move assignment  !!!
// // call destructor
// // call destructor
