#include "ch_13_ex_49_Message.h"
#include <iostream>

void swap(Message& lhs, Message& rhs)
{
	std::cout << "swap Message" << std::endl;
	using std::swap;
	lhs.remove_from_Folders();
	rhs.remove_from_Folders();

	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);

	lhs.add_to_Folders(lhs);
	rhs.add_to_Folders(rhs);

}

//Message Implementation
Message::Message(const Message& m) : contents(m.contents), folders(m.folders)
{
	std::cout << "Message class copy constructor" << std::endl;
	add_to_Folders(m);
}

Message& Message::operator=(const Message& rhs)
{
	std::cout << "Message class copy-assignment operator" << std::endl;
	remove_from_Folders();
	contents = rhs.contents;
	folders = rhs.folders;
	add_to_Folders(rhs);
	return *this;
}

Message::Message(Message&& m) : contents(std::move(m.contents))
{
	std::cout << "Message class move constructor" << std::endl;
	move_Folders(&m);
}

Message& Message::operator=(Message&& rhs)
{
	std::cout << "Message class move-assignment operator" << std::endl;
	if(this != &rhs) {
		remove_from_Folders();
		contents = std::move(rhs.contents);
		move_Folders(&rhs);
	}
	return *this;
}

Message::~Message()
{
	remove_from_Folders();
}

void Message::save(Folder& f)
{
	addFldr(&f);
	f.addMsg(this);
}

void Message::remove(Folder& f)
{
	remFldr(&f);
	f.remMsg(this);
}

void Message::print_debug()
{
	std::cout << contents << std::endl;
}

void Message::add_to_Folders(const Message& m)
{
	for(auto f : m.folders)
		f->addMsg(this);
}

void Message::remove_from_Folders()
{
	for(auto f : folders)
		f->remMsg(this);
}

void Message::move_Folders(Message* m)
{
	folders = std::move(m->folders);
	for(auto f : folders) {
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

//Folder Implementation
void swap(Folder& lhs, Folder& rhs)
{
	std::cout << "swap Folder" << std::endl;
	using std::swap;
	lhs.remove_from_Messages();
	rhs.remove_from_Messages();

	swap(lhs.msgs, rhs.msgs);

	lhs.add_to_Messages(lhs);
	rhs.add_to_Messages(rhs);
}

Folder::Folder(const Folder& f) : msgs(f.msgs)
{
	std::cout << "Folder class copy constructor" << std::endl;
	add_to_Messages(f);
}

Folder& Folder::operator=(const Folder& rhs)
{
	std::cout << "Folder class copy-assignment operator" << std::endl;
	remove_from_Messages();
	msgs = rhs.msgs;
	add_to_Messages(rhs);
	return *this;
}

Folder::Folder(Folder&& f)
{
	std::cout << "Folder class move constructor" << std::endl;
	move_Messages(&f);
}

Folder& Folder::operator=(Folder&& f)
{
	std::cout << "Folder class move-assignment operator" << std::endl;
	if(this != &f) {
		remove_from_Messages();
		move_Messages(&f);
	}
	return *this;
}

Folder::~Folder()
{
	remove_from_Messages();
}

void Folder::print_debug()
{
	for(auto m : msgs) 
		std::cout << m->contents << " ";
	std::cout << std::endl;
}

void Folder::add_to_Messages(const Folder& f)
{
	for(auto m : f.msgs)
		m->addFldr(this);
}

void Folder::remove_from_Messages()
{
	for(auto m : msgs)
		m->remFldr(this);
}

void Folder::move_Messages(Folder* f)
{
	msgs = std::move(f->msgs);
	for(auto m : msgs) {
		m->remFldr(f);
		m->addFldr(this);
	}
	f->msgs.clear();
}
