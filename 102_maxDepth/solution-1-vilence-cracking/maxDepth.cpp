#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
//DFS   递归·深度优先
/*
找出终止条件：当前节点为空
找出返回值：节点为空时说明高度为 0，所以返回 0；
节点不为空时则分别求左右子树的高度的最大值，同时加1表示当前节点的高度，返回该数值
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
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
    tr2->left=nullptr;
    tr2->right=nullptr;
    // tr2->left=new TreeNode;
    // tr2->right=new TreeNode;
    // tr2->left->val=4;
    // tr2->right->val=5;
    // tr2->left->left=nullptr;
    // tr2->left->right=nullptr;
    // tr2->right->left=nullptr;
    // tr2->right->right=nullptr;

    so.maxDepth(tr);
    return 0;
}