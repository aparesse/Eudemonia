#ifndef CH_13_EX_34_36_37_H
#define CH_13_EX_34_36_37_H

#include <set>
#include <string>

class Folder;

class Message 
{
	friend void swap(Message&, Message&);
	friend void swap(Folder&, Folder&);
	friend class Folder;

public:
	//隐式的将folders初始化为空集合
	//因为此构造函数拥有一个默认参数，因此也成为default constructor
	explicit Message(const std::string& str = "") : contents(str)
	{
	}

	Message(const Message&); //copy constructor

	Message& operator=(const Message&); //copy assignment operator

	~Message();

	void save(Folder&);

	void remove(Folder&);

	void print_debug();

private:
	std::string contents;
	std::set<Folder*> folders;

	void add_to_Folders(const Message&);
	void remove_from_Folders();

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
	Folder() = default; //默认构造函数(合成构造函数，使用的default将隐式地声明为內联函数)
	
	Folder(const Folder&); //copy constructor

	Folder& operator=(const Folder&); //copy assignment operator

	~Folder(); //deconstructor

	void print_debug();

private:
	std::set<Message*> msgs;

	void add_to_Messages(const Folder&);
	void remove_from_Messages();

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
