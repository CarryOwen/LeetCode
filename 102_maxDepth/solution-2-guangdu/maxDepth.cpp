#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
// 广度搜索，，，，其实就是用队列的形式
/*
    我们广度优先搜索的队列里存放的是「当前层的所有节点」。
    每次拓展下一层的时候，不同于广度优先搜索的每次只从队列里拿出一个节点，
    我们需要将队列里的所有节点都拿出来进行拓展，
    这样能保证每次拓展完的时候队列里存放的是当前层的所有节点
    ，即我们是一层一层地进行拓展，最后我们用一个变量 ans 来维护拓展的次数，
    该二叉树的最大深度即为 ans
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
        if (root == nullptr) return 0;
        queue<TreeNode*> Q;
        Q.push(root);
        int ans = 0;
        while (!Q.empty()) {
            int sz = Q.size();
            while (sz > 0) {//所谓的广度优先其实就是把横向的数据先存起来
                TreeNode* node = Q.front();
                Q.pop();
                //通过sz和下面的push，保证了每次都能将一层的数据全部放进Q中，
                if (node->left) 
                    Q.push(node->left);
                if (node->right) 
                    Q.push(node->right);
                sz = sz-1;
            }
            ans += 1;
        } 
        return ans;
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