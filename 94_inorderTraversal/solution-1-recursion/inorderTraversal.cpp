#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
//递归 中序遍历即根在中间，前序遍历是根在前，后序是根在后
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
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) {
            return;
        }
        // res.push_back(root->val);//先序
        inorder(root->left, res);
        res.push_back(root->val);//中序
        inorder(root->right, res);
        // res.push_back(root->val);//后序
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};
int main()
{
    return 0;
}