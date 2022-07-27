#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
// 迭代法
/*
    首先我们引入一个队列，这是把递归程序改写成迭代程序的常用方法。初始化时我们把根节点入队两次。
    每次提取两个结点并比较它们的值（队列中每两个连续的结点应该是相等的，而且它们的子树互为镜像），
    然后将两个结点的左右子结点按相反的顺序插入队列中。当队列为空时，
    或者我们检测到树不对称（即从队列中取出两个不相等的连续结点）时，该算法结束.
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
    bool check(TreeNode* left, TreeNode *right)
    {
        queue<TreeNode *> q;
        //现将左右根节点入队列
        q.push(left);
        q.push(right);
        while (!q.empty())
        {
            //取出两个节点
            left=q.front();
            q.pop();
            right=q.front();
            q.pop();
            //如果两个节点都为空
            if(left==nullptr && right==nullptr)
                continue;
            //值不相等或者有一个为null的
            if(left->val != right->val || (left==nullptr || right == nullptr))
                return false;
            //两个节点都不为空,则两两入列
            q.push(left->left);
            q.push(right->right);

            q.push(left->right);
            q.push(right->left);

        }

    }
    bool isSymmetric(TreeNode* root) 
    {
       return check(root,root);
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
    tr1->left=nullptr;
    tr1->right=new TreeNode;
    // tr1->left->val=4;
    tr1->right->val=5;
    // tr1->left->left=nullptr;
    // tr1->left->right=nullptr;
    tr1->right->left=nullptr;
    tr1->right->right=nullptr;

    tr2->val=3;
    tr2->left=new TreeNode;
    tr2->right=nullptr;
    tr2->left->val=5;
    // tr2->right->val=5;
    tr2->left->left=nullptr;
    tr2->left->right=nullptr;
    // tr2->right->left=nullptr;
    // tr2->right->right=nullptr;
    so.isSymmetric(tr);

    return 0;
}