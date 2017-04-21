#ifndef CH_13_EX_28B_H
#define CH_13_EX_28B_H

#include "ch_13_ex_28a.h"

class BinStrTree
{
public:
	BinStrTree() : root(new TreeNode())
	{
	}
	
	BinStrTree(const BinStrTree& bst) : root(new TreeNode(*bst.root))
	{
	}
	
	BinStrTree& operator=(const BinStrTree& bst);

	~BinStrTree()
	{
		delete root;
	}

private:
	TreeNode* root;
};
#endif
