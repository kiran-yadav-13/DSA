# include <iostream>
# include <vector>
using namespace std;


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

void inorderTraversalHelper(TreeNode *node, vector<int>&inorder){
 
  if(node==NULL){
  return;
  }
  inorderTraversalHelper(node->left, inorder);
  inorder.push_back(nade->val);
  inorderTraversalHelper(node->right, inorder);
}

vector<int> inorderTraversal(TreeNode* root){
 vector<int> inorder;
   inorderTraversalHelper(root, inrder);
  return inorder;
}


void PostorderHelper(TreeNode *node, vector<int>&ans){
 if(node==NULL){
  return; 
 }
  PostorderHelper(node->left, ans);
  PostorderHelper(node->right, ans);
  ans.push_back(node->val);
}

vector<int>PostOrder(TreeNode *root){
 vector<int> ans;
  
  PostorderHelper(root,ans);
}


void PreOrderHelper(TreeNode* node, vector<int>&ans){
 if(node==NULL)
 {
   return;
 }
  ans.push_back(node->val);
  PreOrderHelper(node->left, ans);
  PreOrderHelper(node->right, ans);
  
}

vector<int> PostOrder(TreeNode* root){
 vector<int> ans;
  PostOrderHelper(root, ans);
}
