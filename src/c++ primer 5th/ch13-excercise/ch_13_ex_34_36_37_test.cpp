#include "ch_13_ex_34_36_37.h"

int main()
{
	Message firstMail("hello");
	Message signInMail("welcome to c++primer");

	Folder mailBox;

	firstMail.print_debug(); //print: "hello"
	firstMail.save(mailBox); //send to mailBox
	mailBox.print_debug(); //print: "hello"

	signInMail.print_debug(); //print: "welcome to c++primer"
	signInMail.save(mailBox); //send to mailBox
	mailBox.print_debug(); //print "welcome to c++primer hello"

	firstMail = firstMail; //test for assignment to self
	firstMail.print_debug(); //print "hello"
	mailBox.print_debug(); //print "welcome to c++primer hello"
}
