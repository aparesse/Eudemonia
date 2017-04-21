#ifndef CH_13_EX_49_MESSAGE_H
#define CH_13_EX_49_MESSAGE_H

#include <set>
#include <string>
#include <iostream>

class Folder;

class Message
{
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
	friend class Folder;

public:
	explicit Message(const std::string& str = "") : contents(str)
	{
		std::cout << "Message class default constructor" << std::endl;
	}

	Message(const Message&);

	Message& operator=(const Message&);

	Message(Message&&);

	Message& operator=(Message&&);

	~Message();

	void save(Folder&);

	void remove(Folder&);

	void print_debug();

private:
	std::string contents;
	std::set<Folder*> folders;

	void add_to_Folders(const Message&);

	void remove_from_Folders();

	void move_Folders(Message*);

	void addFldr(Folder* f)
	{
		folders.insert(f);
	}

	void remFldr(Folder* f)
	{
		folders.erase(f);
	}
};

void swap(Message&, Message&);

class Folder
{
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
	friend class Message;

public:
	Folder() = default;
	Folder(const Folder&);
	Folder& operator=(const Folder&);

	Folder(Folder&&);

	Folder& operator=(Folder&&);

	~Folder();

	void print_debug();

private:
	std::set<Message*> msgs;

	void add_to_Messages(const Folder&);

	void remove_from_Messages();

	void move_Messages(Folder*);

	void addMsg(Message* m)
	{
		msgs.insert(m);
	}
	
	void remMsg(Message* m)
	{
		msgs.erase(m);
	}
};

void swap(Folder&, Folder&);

#endif
