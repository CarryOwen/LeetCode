#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
// 官方递归
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
    bool check(TreeNode *p, TreeNode *q) const {
        if (!p && !q) return true;
        if (!p || !q) return false;
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
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