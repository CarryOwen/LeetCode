#include "iostream"
#include "vector"
#include "algorithm"
#include "string"
using namespace std;
//暴力法：morris 遍历两个树，然后比较是否相同,,,,无法通过58,，，，例如[1,null,1] 和[1,1]会判定相同
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
        vector<int> vector_p,vector_q;
        if (p ==NULL & q==NULL)
            return true;
        else if(p==NULL||q==NULL)
            return false;
        inorderTreeversal(p,vector_p);
        inorderTreeversal(q,vector_q);
        if (vector_p==vector_q)
            return true;
        else
            return false;
    }
    vector<int> inorderTreeversal(TreeNode *root,vector<int> &result)
    {
        TreeNode * mostRight=NULL;
        TreeNode * cur=root;
        //p Tree 遍历
        while(cur!=NULL){
            mostRight=cur->left;
            if(mostRight != NULL){
                while (mostRight->right != NULL && mostRight->right != cur)
                    mostRight=mostRight->right;
                if(mostRight->right==NULL)
                {
                    mostRight->right=cur;
                    cur=cur->left;
                    continue;
                }else{
                    mostRight->right=NULL;
                }
            }
            result.push_back(cur->val);
            cur=cur->right;
        }
        return result;
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