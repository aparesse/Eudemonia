#include "ch_13_ex_28b.h"

TreeNode& TreeNode::operator=(const TreeNode& rhs)
{
	++*rhs.count;
	if (--*count == 0) {
		if (left) {
			delete left;
			left = nullptr;
		}

		if (right) {
			delete right;
			right = nullptr;
		}

		delete count;
		count = nullptr;
	}

	value = rhs.value;
	left = rhs.left;
	right = rhs.right;
	count = rhs.count;
	return *this;
}


BinStrTree& BinStrTree::operator=(const BinStrTree& bst)
{
	TreeNode* new_root = new TreeNode(*bst.root);
	delete root;
	root = new_root;
	return *this;
}
