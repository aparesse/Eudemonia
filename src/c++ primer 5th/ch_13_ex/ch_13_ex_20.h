#ifndef CH_13_EX_20_H
#define CH_13_EX_20_H

#include <vector>
#include <iostream>
class QueryResult; //为了定义函数query的返回类型，这个定义是必须的
class TextQuery
{
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstreanm&);
	QueryResult query(const std::string&) const;
	
	TextQuery(const TextQuery&) = delete; //forbid copy constructor
	TextQuery& operator=(const TextQuery) = delete; //forbid copy operator
private:
	std::shared_ptr<std::vector<std::string>> file; //输入文件
	//每个单词到它所在的行号的集合的映射
	std::map<std::string,
		std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult
{
public:
	QueryResult(const QueryResult&) = delete; //forbid copy constructor
	QueryResult& operator=(const QueryResult&) = delete; //forbid copy operator
};
