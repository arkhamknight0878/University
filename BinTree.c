#include "BinTree.h"
#include <stdlib.h>
#include <stdio.h>

BinTree* CreateNode (int data_)
{
    BinTree* node = malloc(sizeof(BinTree));
    if (node == NULL)
        return NULL;
    
    node->data = data_;
    node->parent = 0;
    node->left = 0;
    node->right = 0;
    
    return node;
}

void Insert(BinTree** tree_, BinTree* node_)
{
    if (*tree_ == 0)
        *tree_ = node_;
    else
    {
        node_->parent = *tree_;
        if (node_->data > (*tree_)->data)
            Insert(&(*tree_)->right, node_);
        else if (node_->data < (*tree_)->data)
            Insert(&(*tree_)->left, node_);
    }
}

void Remove(BinTree* tree_, int data_)
{
     if (tree_ == 0)
      return;
      
      if (data_ > tree_->data)
          Remove(tree_->right, data_);
      else if (data_ < tree_->data)
          Remove(tree_->left, data_);
      else 
      {
          BinTree** child = 0;
          
          if (tree_->parent != 0)
          {
                if (tree_->parent->left == tree_)
                    child = &tree_->parent->left;
                else
                    child = &tree_->parent->right;
          }
                
          if (tree_->left == 0 && tree_->right == 0)
          {
              if (child != 0)
                *child = 0;
          }
          else if (!tree_->left != !tree_->right)
          {
              if (tree_->left != 0)
                *child = tree_->left;
              else
                *child = tree_->right;
          }
          else
          {
              if (tree_->right->left == 0)
              {
                  tree_->right->left = tree_->left;
                  *child = tree_->right;
              }
              else
              {
                  BinTree* copy = tree_->right;
                  
                  while (copy->left != 0)
                    copy = copy->left;
                      
                  tree_->data = copy->data;
                  copy->parent->left = 0;
                  tree_ = copy;
              }
          }
          
          free(tree_);
      }
}

void Prefix_Traverse(BinTree* tree_, void(*fptr)(BinTree* node_))
{
    if (tree_ == 0)
        return;
        
    fptr(tree_);
    
    Prefix_Traverse(tree_->left, fptr);
    Prefix_Traverse(tree_->right, fptr);
}