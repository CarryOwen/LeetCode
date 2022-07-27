#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
using namespace std;
//深度搜索-递归如果两个二叉树都不为空，
/*那么首先判断它们的根节点的值是否相同，若不相同则两个二叉树一定不同，
若相同，再分别判断两个二叉树的左子树是否相同以及右子树是否相同。
这是一个递归的过程，因此可以使用深度优先搜索，递归地判断两个二叉树是否相同。*/

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p ==NULL & q==NULL)
            return true;
        else if(p==NULL||q==NULL)
            return false;
        bool res=isSameNode(p,q);
        return res;
        
    }
    bool isSameNode(TreeNode* p, TreeNode* q) {
        bool left ,right;
        if (p->val==q->val)
        {
            if (p->left !=NULL && q->left !=NULL)
            {
                left=isSameNode(p->left,q->left);
            }else if(p->left == NULL && q->left == NULL)
                return true;
            else 
                return false;
        }else
            return false;
            
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        } else if (p->val != q->val) {
            return false;
        } else {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }
};
int main() {
    Solution so;
    TreeNode *tr1=new TreeNode ;
    tr1->val= 1;
    TreeNode *tr11=tr1->left= new TreeNode;
    tr11->val=1;
    tr11->left=nullptr;
    tr11->right=nullptr;

    TreeNode * tr2= new TreeNode;
    tr2->val= 1;
    TreeNode *tr22=tr2->left= new TreeNode;
    tr22->val=1;
    tr22->left=nullptr;
    tr22->right=nullptr;
    
    so.isSameTree(tr1,tr2);
    return 0;
}