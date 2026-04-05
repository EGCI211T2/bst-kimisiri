class TreeNode {           
  private:
    TreeNode *leftPtr;
    int data;                            
    TreeNode *rightPtr;
  public:
    TreeNode(int x) {
      data =x;
      leftPtr=NULL;
      rightPtr=NULL;
      cout << data << "inserted" << endl;
    }
    ~TreeNode() {
      cout<<"Deleting "<< data<<endl;
    }
    void set_left(TreeNode* t){leftPtr=t;}
    void set_right(TreeNode* t){rightPtr=t;}
    int get_value(){return data;}
    TreeNode* move_right(){ return rightPtr; }
    TreeNode* move_left(){ return leftPtr; }
};