#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
//DFS   递归·深度优先
/*
    题目要求：
    最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
    因此如果根节点的的一个节点为空，另一个不为空，那么最小节点不能是0，
    说明：叶子节点是指没有子节点的节点。
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
    int minDepth(TreeNode* root) {
        if (root ==nullptr) 
            return 0;
        else if(root->left == nullptr && root->right == nullptr) //左右节点都为空，说明为叶子节点，返回当前的高度
            return 1;
        else if(root->right == nullptr)
            return minDepth(root->left)+1;
        else if(root->left == nullptr)
            return minDepth(root->right)+1;
        else
            return min(minDepth(root->left), minDepth(root->right))+1;
    }
};
int main()
{
    return 0;
}