#include "ch_13.6.3_cont.h"
#include <string>
using std::string;
int main()
{
	StrVec vec; //空StrVec
	string s = "some string or another";

	vec.push_back(s); //调用push_back(const string&)

	vec.push_back("done"); //调用push_back(string&&) 字面值是右值，此处是(从"done"创建的临时string)

	return 0;
}
