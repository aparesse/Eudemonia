#include <string>
#include <stdlib.h>
class HasPtr {
public:
	HasPtr(const std::string& s = std::string()): // constructor
		ps(new std::string(s)), i(0) {}

	HasPtr(const HasPtr& hp): // copy constructor
		ps(new std::string(*hp.ps)), i(hp.i) {}
private:
	std::string* ps;
	int i;
};
