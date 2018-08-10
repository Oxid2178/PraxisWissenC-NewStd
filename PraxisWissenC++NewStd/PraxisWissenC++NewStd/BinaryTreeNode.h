#pragma once

#include <functional>

class BinaryTreeNode
{
public:
	BinaryTreeNode(int value, BinaryTreeNode* left, BinaryTreeNode* right);
	virtual ~BinaryTreeNode();
	void accept(std::function<void(BinaryTreeNode& node)> visitor);
	int getValue() const;

private:
	int value_;
	BinaryTreeNode* left_ = nullptr;
	BinaryTreeNode* right_ = nullptr;


};

