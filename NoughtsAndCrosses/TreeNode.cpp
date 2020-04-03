#include "TreeNode.h"

int TreeNode::ChildQty()
{
	return 9 - level;
}

TreeNode::TreeNode():TreeNode(*(new PlayField()), 0, nullptr) {};

TreeNode::TreeNode(PlayField field, int nowLevel, TreeNode* node)
{
	parent = node;
	playField = field;
	level = nowLevel;
	children = *(new vector<TreeNode*>());
}

bool TreeNode::IsTerminal()
{
	return (&playField)->GetEmptyCells().size() == 0;
}

void TreeNode::AddChild()
{
	if(ChildCount() >= ChildQty())
		assert(ChildCount() > ChildQty());
	CellPos position = (&playField)->GetEmptyCells()[ChildCount()];
	children.push_back(new TreeNode((&playField)->MakeMove(position), level + 1, this));
}

TreeNode& TreeNode::operator[](int number)
{
	if(number >= children.size())
		assert(number >= children.size());
	return *children[number];
}

int TreeNode::ChildCount()
{
	return children.size();
}
FieldStatus TreeNode::Value()
{
	return (&playField)->CheckFieldStatus();
}