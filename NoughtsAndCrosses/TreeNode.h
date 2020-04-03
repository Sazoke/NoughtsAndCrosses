#pragma once
#include "PlayField.h"
#include <cassert>

class TreeNode
{
private:
	PlayField playField;
	TreeNode* parent;
	vector<TreeNode*> children;
	int level;

public:
	TreeNode();

	TreeNode(PlayField, int, TreeNode*);

	bool IsTerminal();

	void AddChild();

	TreeNode& operator[](int);

	int ChildQty();

	int ChildCount();

	FieldStatus Value();
};

