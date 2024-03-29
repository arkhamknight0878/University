#include"BinTree.h"
#include<stdlib.h>

BinTreeNode* Find(BinTreeNode* tree_, int data_)
{
	if (tree_ == NULL)
		return NULL;

	if (data_ == tree_->data)
		return tree_;

	if (data_ > tree_->data)
		return Find(tree_->right, data_);
	else
		return Find(tree_->left, data_);
}

bool Insert(BinTreeNode** tree_, BinTreeNode* node_)
{
	if (*tree_ == NULL)
		*tree_ = node_;
	else
	{
		node_->parent = *tree_;

		if (node_->data > (*tree_)->data)
		{
			
			return Insert((*tree_)->right, node_);
		}
		else if (node_->data < (*tree_)->data)
		{
			return Insert((*tree_)->left, node_);
		}
	}

	return true;
}
