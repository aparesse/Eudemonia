#include "ch_13_ex_49_Message.h"

int main()
{
	Message first_mail("hello");
	Message sign_in_mail("welcome to c++primer");
	Folder mail_box;

	first_mail.save(mail_box);
	sign_in_mail.save(mail_box);
	mail_box.print_debug();

	std::cout << "before std::move call" << std::endl;
	first_mail = std::move(sign_in_mail);
	mail_box.print_debug();
}
