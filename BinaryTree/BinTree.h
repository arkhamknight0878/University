#pragma once

#include<stdbool.h>

typedef struct BinTreeNode
{
	struct BinTreeNode* parent;
	struct BinTreeNode* left;
	struct BinTreeNode* right;
	int data;

} BinTreeNode;

BinTreeNode* Find(BinTreeNode* tree_, int data_);

bool Insert(BinTreeNode** tree_, BinTreeNode* node_);

BinTreeNode* Remove(BinTreeNode* tree_, int data_);