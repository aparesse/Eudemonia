#ifndef CH_13_4_CONT_H
#define CH_13_4_CONT_H

#include <string>
#include <set>

class Folder;

class Message
{
	friend void swap(Message&, Message&); //this function can view the class Message private members
	friend class Folder; //this class can view the class Message private members
public:
	//folders被隐式初始化为空集合,即构造函数的初始化列表中未显示的初始化folders成员变量
	//由于此构造函数有一个默认参数，因此这个构造函数也就是默认构造函数
	explicit Message(const std::string& str = "") :
		contents(str)
		{
		}
	//拷贝控制成员，用来管理指向本Message的指针
	Message(const Message&); //copy constructor

	Message& operator=(const Message&); //copy assignment constructor

	~Message();

	//specific 13.6
	//move constructor
	Message(Message&& m);

	//specific 13.6
	//move-assignment operator
	Message& operator=(Message&& rhs);

	//从给定Folder集合中添加/删除本Message
	void save(Folder&);

	void remove(Folder&);

private:
	std::string contents; //实际消息文本

	//folders保存指向本Message所在Folder的指针
	std::set<Folder*> folders; //包含本message的Folder

	//拷贝构造函数、拷贝赋值运算符和析构函数所使用的工具函数
	//将本Message添加到指向参数的Folder中
	void add_to_Folders(const Message&);

	//从folders中的每个Folder中删除Message
	void remove_from_Folders();

	//specifi 13.6
	void move_Folders(Message* m);
};

class Folder
{
	friend class Message; //this class can view the class Folder private members
	friend void swap(Message&, Message&); //this function can view the class Folder private members

private:
	std::set<Message*> msgs;
	void addMsg(Message* m)
	{
		msgs.insert(m);
	}

	void remMsg(Message* m)
	{
		msgs.erase(m);
	}
};

#endif

