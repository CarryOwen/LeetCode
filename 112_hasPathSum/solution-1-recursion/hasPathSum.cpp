#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
//DFS   递归·
//从根节点到当前节点的值之和为 val，转化为：是否存在从当前节点的子节点到叶子的路径，满足其路径和为 sum - val
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return 0==(targetSum-root->val);
        if (root->left == nullptr&&root->right == nullptr)//叶子节点
            return targetSum==root->val;
        else //左右节点可能有一个为空或者都不为空
            return hasPathSum(root->left, targetSum-root->val)  || hasPathSum(root->right, targetSum-root->val); 
    }
};
int main()
{
    return 0;
}