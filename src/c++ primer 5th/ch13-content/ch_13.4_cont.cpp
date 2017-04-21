#include "ch_13.4_cont.h"

void Message::save(Folder& f)
{
	folders.insert(&f); //将给定Folder添加到我们的Folder列表中
//	f.addMsg(this); //将本Message添加到f的Message集合中
}

void Message::remove(Folder& f)
{
	folders.erase(&f); //将给定Folder从我们的Folder列表中删除
//	f.remMsg(this); //将本Message从f的Message集合中删除
}

//specific 13.6
//移动构造函数和移动赋值运算符都需要更新Folder指针，因此定义move_Folders函数
//完成此工作
void Message::move_Folders(Message* m)
{
	folders = std::move(m->folders); //使用set的移动赋值运算符
	for(auto f : folders) { //对每个Folder
		f->remMsg(m); //从Folder中删除旧的Message
		f->addMsg(this); //将本Message添加到Folder中
	}
	m->folders.clear(); //确保销毁m是无害的
}

//specific 13.6
//move contructor
Message::Message(Message&& m)
	//使用string的移动赋值运算符来移动contents，并默认初始化自己的folders成员
	: contents(std::move(m.contents)) 
{
	move_Folders(&m); //移动folders并更新Folder指针
}

//specific 13.6
//move-assignment operator
Message& Message::operator=(Message&& rhs)
{
	if(this != &rhs) { //直接检查自赋值情况
		//移动赋值运算符也必须销毁左侧运算对象的旧状态
		//移动赋值运算符左侧运算对象要求我们先从现有folders中删除指向本Message
		//的指针
		remove_from_Folders(); 
		contents = std::move(rhs.contents); //移动赋值运算符
		move_Folders(&rhs); //重置Folders指向本Message
	}
	return *this;
}

//将本Message添加到指向m的Folder中
void Message::add_to_Folders(const Message& m)
{
	for (auto f : m.folders) //对每个包含m的Folder
		f->addMsg(this); //向该Folder添加一个指向本Message的指针
}

//Message的拷贝构造函数拷贝给定对象的数据成员，并调用add_to_Folders将
//新创建的Message的指针添加到每个包含原Message的Folder中
Message::Message(const Message& m) :
	contents(m.contents), folders(m.folders)
{
	add_to_Folders(m); //将本消息添加到指向m的Folder中
}

//从对应的Folder中删除本Message
void Message::remove_from_Folders()
{
	for (auto f : folders) //对folders中的每个指针
		f->remMsg(this); //从该Folder中删除本Message
}

Message::~Message()
{
	//调用remove_from_Folders确保没有任何Folder保存正在销毁的Message指针
	//编译器自动调用string的析构函数来释放contents,并自动调用set的析构函数来
	//清理集合成员使用的内存
	remove_from_Folders();
}

Message& Message::operator=(const Message& rhs)
{
	//通过先删除指针再插入它们来处理自赋值情况
	remove_from_Folders(); //更新已有Folder，即从左侧运算对象的folders中删除此Message的指针
	contents = rhs.contents; //从rhs拷贝消息内容
	folders = rhs.folders; //从rhs拷贝Folder指针
	add_to_Folders(rhs); //将本message添加到那些Folder中，即将指针添加到右侧运算对象的folders中
	return *this;
}

void swap(Message& lhs, Message& rhs)
{
	using std::swap; //在本例中严格来说并不需要，但这是一个好习惯

	//将每个消息的指针从它（原来）所在的Folder中删除
	for(auto f: lhs.folders)
		f->remMsg(&lhs);
	for(auto f: rhs.folders)
		f->remMsg(&rhs);

	//交换contents和Folder指针set
	swap(lhs.folders, rhs.folders); //使用swap(set&, set&)
	swap(lhs.contents, rhs.contents); //使用swap(string&, string&)

	//将每个Message的指针添加到它的（新）Folder中
	for(auto f: lhs.folders)
		f->addMsg(&lhs);
	for(auto f: rhs.folders)
		f->addMsg(&rhs);
}
