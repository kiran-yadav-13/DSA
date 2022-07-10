class TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(){
    val=0;
    left=NULL;
    right=NULL;
  }
  TreeNode(int x){
    val=x;
  }
  TreeNode(int x, int l, int r){
   val=x;
   left=l;
   right=r;
  }
  
};
