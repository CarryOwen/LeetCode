#include "vector"
#include "iostream"
#include "algorithm"
#include "stack"
using namespace std;
//morris中序遍历   参考：https://blog.csdn.net/weixin_40374341/article/details/109560701?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522165845904016782390586714%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=165845904016782390586714&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~blog~top_positive~default-1-109560701-NULL-NULL.185^v2^control&utm_term=morris%E9%81%8D%E5%8E%86&spm=1018.2226.3001.4450
/*
    避免用栈结构，而是让下层到上层有指针连接，即从最下层的左侧开始，用指针将下层的右节点和连接到上层的根节点。
    步骤1：我们记当前节点的指针为 cur，如果 cur 所指向的节点没有左孩子，那么 cur 指针向右移动，即 cur = cur.right。
    步骤2：如果 cur 所指向的节点有左孩子，那么先找到 cur 左子树的最右的节点，并使用 mostright 指针指向该最右节点。
            1.如果 mostright 所指向的节点的 right 指针为空，那么让mostright 的 right 指针指向 cur，然后cur 指针向左移动；
            2.如果 mostright 所指向的节点的 right 指向 cur，那么让 right 重新指向空，然后 cur 向右移动。
    
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
    // Morris先序遍历
    void morrisPre(TreeNode *root) {
        if (root == NULL)
            return;
        TreeNode *cur = root;
        TreeNode *mostright = NULL;
        vector<int> result;
        while (cur != NULL) {

            mostright = cur->left;// 当前节点的左孩子
            // 当前节点的左子树存在，则将mostright定位到该左子树的最右节点
            if (mostright != NULL) {
                while (mostright->right != NULL && mostright->right != cur) {
                    mostright = mostright->right;
                }
                // 如果左子树最右节点的right指针为空，让其指向当前节点，cur往左走
                if (mostright->right == NULL) {
                    mostright->right = cur;
                    result.push_back(cur->val);
                    cur = cur->left;
                    continue;// 继续访问左子树
                } else {
                    // 说明mostright的right指向了cur，重新置为空
                    mostright->right = NULL;
                    // 逆序打印左子树右边界
                    printEdge(cur->left,result);
                }
            } 
            // 当前节点的左子树不存在或已经访问过，cur往右走
            cur = cur->right;
        }
        // 逆序打印该树的右边界
        printEdge(root,result);
    }
    // 打印右边界
    void printEdge(TreeNode *head,vector<int> &result) {
        TreeNode *tail = reverseEdge(head);
        while (tail != NULL) {
            result.push_back(tail->val);
            tail = tail->right;
        }
        //这里是恢复右边界原来的顺序
        reverseEdge(head);
    }

    // 右边界逆序
    TreeNode* reverseEdge(TreeNode *from) {
        TreeNode *pre = NULL;
        TreeNode *next = NULL;
        while (from != NULL) {
            next = from->right;
            from->right = pre;
            pre = from;
            from = next;
        }
        return pre;
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
    tr1->left=nullptr;
    tr1->right=nullptr;

    tr2->val=3;
    tr2->left=nullptr;
    tr2->right=nullptr;
    
    so.inorderTraversal(tr);
    return 0;
  }