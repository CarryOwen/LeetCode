#include "vector"
#include "iostream"
#include "algorithm"
#include "stack"
using namespace std;
//迭代法
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        //当stk非空：意味着，压栈的数据还没有被释放完毕，也就是存在左孩子的值没有被取出
        //root不为null,意味着，存在右孩子，需要将右孩子的左节点入栈
        while (root != nullptr || !stk.empty()) 
        {
            while (root != nullptr) 
            {
                //只要左孩子存在，压栈
                stk.push(root);
                root = root->left;
            }
            //不存在子节点，则当前为最左侧的值，将栈顶值赋给root
            root = stk.top();
            //删除栈顶
            stk.pop();
            //取出当前节点的值
            res.push_back(root->val);

            root = root->right;
        }
        return res;
    }
};
int main() {
    Solution so;
    TreeNode *tr=new TreeNode ;
    tr->val= 1;
    TreeNode *tr1=tr->left= new TreeNode;
    TreeNode * tr2=tr->right= new TreeNode;

    tr1->val=2;
    tr1->left=nullptr;
    tr1->right=nullptr;

    tr2->val=3;
    tr2->left=nullptr;
    tr2->right=nullptr;
    
    so.inorderTraversal(tr);
    return 0;
}