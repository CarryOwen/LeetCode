#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
//DFS 
/*
    定义函数 height，用于计算二叉树中的任意一个节点 p 的高度：
height(p)=      0                                      :p 是空节点      
                max(height(p.left),height(p.right))+1  :p 是非空节点    
    有了计算节点高度的函数，即可判断二叉树是否平衡。
    具体做法类似于二叉树的前序遍历，
    即对于当前遍历到的节点，首先计算左右子树的高度，
    如果左右子树的高度差是否不超过 1，
    再分别递归地遍历左右子节点，并判断左子树和右子树是否平衡。
    这是一个自顶向下的递归的过程。
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
    int height(TreeNode* root) {
        if (root == NULL) {
            return 0;
        } else {
            return max(height(root->left), height(root->right)) + 1;
        }
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL) {
            return true;
        } else {  //这个过程其实是跟自己写的一样，只不过更简单
            return abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
    }
};
int main()
{
    Solution so;
    TreeNode *tr=new TreeNode ;
    tr->val= 1;
    TreeNode *tr1=tr->left= new TreeNode;
    TreeNode * tr2=tr->right= new TreeNode;

    tr1->val=2;
    tr1->left=new TreeNode;
    // tr1->right=new TreeNode;
    tr1->left->val=3;
    // tr1->right->val=3;
    tr1->left->left=new TreeNode;
    // tr1->left->right=new TreeNode;
    // tr1->right->left=nullptr;
    // tr1->right->right=nullptr;
    tr1->left->left->val=4;
    // tr1->left->right->val=4;

    tr2->val=2;
    tr2->left=nullptr;
    tr2->right=nullptr;
    // tr2->left=new TreeNode;
    tr2->right=new TreeNode;
    // tr2->left->val=4;
    tr2->right->val=3;
    // tr2->left->left=nullptr;
    // tr2->left->right=nullptr;
     tr2->right->right=new TreeNode;
    // tr2->right->right=nullptr;
    tr2->right->right->val=4;
    so.isBalanced(tr);
    return 0;
}