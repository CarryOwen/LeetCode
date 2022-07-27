#include "vector"
#include "iostream"
#include "algorithm"
#include "stack"
using namespace std;
//morris中序遍历   参考：https://blog.csdn.net/weixin_40374341/article/details/109560701?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522165845904016782390586714%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=165845904016782390586714&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~blog~top_positive~default-1-109560701-null-null.185^v2^control&utm_term=morris%E9%81%8D%E5%8E%86&spm=1018.2226.3001.4450
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root==NULL)
            return result;
        TreeNode * mostRight=NULL;
        TreeNode * cur=root;
        while(cur!=NULL) {
            mostRight=cur->left;
            //左孩子不为空的时候（步骤2）
            if(mostRight != NULL){
                //找到左孩子的最右孩子
                while (mostRight->right != NULL && mostRight->right !=cur)
                    mostRight=mostRight->right;
                if (mostRight->right==NULL)//while中的第1个判断，即步骤2.1
                {
                    mostRight->right=cur;
                    // 1. cur 要走向左子树之前先打印根节点--先序遍历
                    // result.push_back(cur->val);//先序遍历打印节点位置1
                    cur=cur->left;//cur左移
                    continue;
                }else//while中的第2个判断，即步骤2.2
                {
                    mostRight->right=NULL;
                }
            }
            // 2. 左子树为空时打印根节点
            //  else{
            //      result.push_back(cur->val);//先序遍历打印节点位置2
            // }
            //运行到这里左子树为空
            //或者说明左子树已经处理完毕，即mostRight->right=NULL运行过了，此时cur要右移了，中序遍历
            result.push_back(cur->val);   //中序遍历打印节点位置
           
            cur=cur->right;
        }
        return result;
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