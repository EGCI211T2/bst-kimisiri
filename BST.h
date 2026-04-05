#include "Treenode.h"

class BST {

  int size;
  TreeNode *rootPtr;

public:
  BST();
  ~BST();

  void insert_node(int);
  void print(int = 0);
};

// Additional functions
  void inOrder(TreeNode*);
  void preOrder(TreeNode*);
  void postOrder(TreeNode*);
  void printTree(TreeNode*,int); //The real lab
  void kill(TreeNode*);

void BST::insert_node(int value) {
  int inserted = 0;
  TreeNode* new_node, *t;
  new_node = new TreeNode(value);
  if (new_node) {
    if (rootPtr == NULL) {
      rootPtr  = new_node;
    } else {
      t = rootPtr;
      TreeNode* next;
      while (true) {
        bool is_less = value < t->get_value();
        next = is_less ? t->move_left() : t->move_right();
        if (next) {
          t = next;
        } else {
          is_less ? t->set_left(new_node) : t->set_right(new_node);
          break;
        }
      }
    }
    size+=1;
  }
}


void BST::print(int option) {
  switch (option) {
  case 0:
    inOrder(rootPtr);
    cout << endl;
    break;
  case 1:
    preOrder(rootPtr);
    cout << endl;
    break;
  case 2:
    postOrder(rootPtr);
    cout << endl;
    break;
  case 3:
    cout << "inOrder" << endl;
    inOrder(rootPtr);
    cout << endl;
    cout << "preOrder" << endl;
    preOrder(rootPtr);
    cout << endl;
    cout << "postOrder" << endl;
    postOrder(rootPtr);
    cout << endl;
    cout << "Tree" << endl;
      default:
    printTree(rootPtr,0);
    cout << endl;
  }
}


BST::BST() {
  rootPtr=NULL;
  size=0;
}

BST::~BST() { 
  cout << "Kill BST" << endl; 
  delete rootPtr;
}

void inOrder(TreeNode* treePtr) {
  // TreeNode* treePtr=rootPtr;
  if (treePtr) {
    // if tree is not empty, then traverse
    inOrder(treePtr->move_left()); // Recursion to the left
    cout << setw(3) << treePtr->get_value(); // print the value
    inOrder(treePtr->move_right()); // Recursion to the right
  }                                 // end if
} // end function

void printTree(TreeNode* treePtr, int l = 0) {
  if (treePtr == NULL) {return;}
  printTree(treePtr->move_right(), l+1);
  cout << setw(l*2) << treePtr->get_value() << endl;
  printTree(treePtr->move_left(), l+1);
}


void postOrder(TreeNode* treePtr) {
  if (treePtr == NULL) {return;}
  postOrder(treePtr->move_left());
  postOrder(treePtr->move_right());
  cout << setw(3) << treePtr->get_value();
}

void kill(TreeNode* treePtr) {
  if (treePtr == NULL) {return;}
  postOrder(treePtr->move_left());
  postOrder(treePtr->move_right());
  delete treePtr;
} // end function

void preOrder(TreeNode* treePtr) {
  if (treePtr == NULL) {return;}
  cout << setw(3) << treePtr->get_value(); 
  postOrder(treePtr->move_left());
  postOrder(treePtr->move_right());
} // end function

