#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
////DFS   递归·深度优先,,。。。自己写的  垃圾啊
/*
    找出左右节点的最大高度，然后比较，相差大于1即为false,否则为true
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
//这样只是求出来的根节点的左右两个子树的高度，这样也只是保证了第一层即root是平衡的（左右高度相同），无法保证子节点左右相同,所以需要改动一下
// class Solution {
// public:
//     int find_Depth(TreeNode *root) const {
//         if (root == nullptr)
//             return 0;
//         return max(find_Depth(root->left),find_Depth(root->right))+1;
        
//     }
//     bool isBalanced(TreeNode* root) {
//         if (root == nullptr)
//             return true;
//         int L=find_Depth(root->left);
//         int R=find_Depth(root->right);
//         if (abs(L-R)<2)
//             return true;
//         else
//             return false;
//     }
// };
class Solution {
public:
    int find_Depth(TreeNode *root) const {
        if (root == nullptr)
            return 0;
        return max(find_Depth(root->left),find_Depth(root->right))+1;
        
    }
    bool chileIsBalanced(TreeNode* root)  {
        int L=find_Depth(root->left);//找到左节点深度
        int R=find_Depth(root->right);//找到右节点深度
        if(abs(L-R)>1)
            return false;
        else//说明左右节点深度相差不超过1，再判断子节点的的左右深度
        {
            if(root->left !=nullptr)
                if(!chileIsBalanced(root->left))//这里是防止左侧平衡的话，直接返回就不会去判断右侧了
                    return false;
            if(root->right !=nullptr)
                return chileIsBalanced(root->right);
        }
        return true;
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        return chileIsBalanced(root);
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