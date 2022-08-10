#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
//DFS 
/*
    自底向上递归的做法类似于后序遍历，
    对于当前遍历到的节点，先递归地判断其左右子树是否平衡，
    再判断以当前节点为根的子树是否平衡。如果一棵子树是平衡的，
    则返回其高度（高度一定是非负整数），
    否则返回 −1。如果存在一棵子树不平衡，则整个二叉树一定不平衡。
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
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
            return -1;
        } else {
            return max(leftHeight, rightHeight) + 1;
        }
    }
    bool isBalanced(TreeNode* root) {
        return height(root) >= 0;
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