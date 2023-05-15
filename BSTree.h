#pragma once
#include <iostream>
#include <stdio.h>
#include "Node.h"

#define TREE_ERR_NOTFOUND 1
#define TREE_ERR_EMPTY 2
#define TREE_ERR_OTHER 4

class BSTree{
 private:
  Node *root;
  std::string traverse(Node *n);

public:
  BSTree();

  void setup();

  std::string get_debug_string();

  int search(int n);
  void insert(int n);

  int treesum();
  int treesum(Node *n);
  int countodds();
  int countodds(Node *n);
  int oddsum();
  int oddsum(Node *n);
  int searchr(int val); // recursive search
  int searchr(int val, Node *p);
  // void insertr(int n);
  // void insertr(int n, Node *p);
  void deleten(int val);
};
