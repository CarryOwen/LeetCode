#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
// 递归法 自己写的
/*

*/
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        else if (root->left == nullptr && root->right == nullptr)
            return true;
        else if (root->right == nullptr || root->left ==nullptr)
            return false;
        else{//左右节点均不为空
            return isSymmetric(root->left,root->right);
        }
    }
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if(left->val != right->val)
            return false;
        else if(left->left ==nullptr && left->right == nullptr && right->right == nullptr&& right->left == nullptr)
            return true;
        else if(left->left ==nullptr && right->right == nullptr && left->right != nullptr &&right->left!=nullptr)
            return isSymmetric(left->right,right->left);
        else if(left->left !=nullptr && right->right != nullptr && left->right == nullptr &&right->left==nullptr)
            return isSymmetric(left->left,right->right);
        else if(left->left ==nullptr || left->right == nullptr || right->right == nullptr|| right->left == nullptr)
            return false;
        else{
            bool reL=isSymmetric(left->left,right->right);
            bool reR=isSymmetric(left->right,right->left);
            return reL && reR;
        }
    }
};
 int main()
  {
      Solution so;
    TreeNode *tr=new TreeNode ;
    tr->val= 2;
    TreeNode *tr1=tr->left= new TreeNode;
    TreeNode * tr2=tr->right= new TreeNode;

    tr1->val=3;
    tr1->left=new TreeNode;
    tr1->right=new TreeNode;
    tr1->left->val=4;
    tr1->right->val=5;
    tr1->left->left=nullptr;
    tr1->left->right=nullptr;
    tr1->right->left=nullptr;
    tr1->right->right=nullptr;


    tr2->val=3;
    tr2->left=new TreeNode;
    tr2->right=new TreeNode;
    tr2->left->val=4;
    tr2->right->val=5;
    tr2->left->left=nullptr;
    tr2->left->right=nullptr;
    tr2->right->left=nullptr;
    tr2->right->right=nullptr;



    so.isSymmetric(tr);
    return 0;
  }