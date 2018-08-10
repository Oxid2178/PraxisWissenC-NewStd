#include "stdafx.h"
#include "BinaryTreeNode.h"


BinaryTreeNode::BinaryTreeNode(int value, BinaryTreeNode* left, BinaryTreeNode* right) : value_(value), left_(left), right_(right)
{
}


BinaryTreeNode::~BinaryTreeNode()
{
}


void BinaryTreeNode::accept(std::function<void(BinaryTreeNode& node)> visitor)
{
	visitor(*this);
	if (left_ != nullptr) left_->accept(visitor);
	if (right_ != nullptr) right_->accept(visitor);
}


int BinaryTreeNode::getValue() const
{
	return value_;
}