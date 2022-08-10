#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
//DFS   
//这样我们使用两个队列，分别存储将要遍历的节点，以及根节点到这些节点的路径和即可。
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
        
    }
};
int main()
{
    return 0;
}