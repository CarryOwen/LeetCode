#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
//中序遍历   递归初始化搜索二叉树
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
    TreeNode* height_relevant(vector<int>& nums,int left,int right)
    {
        if(left>right)//说明数组内的数值已经全部分配结束，这里不可用用等号,如果用了等号，说明可能会有一个根节点漏掉
            return nullptr;
        int mid=(left+right)/2;//以中间的值为根节点，向下取整，需要注意下面mid区间的问题
        TreeNode * root=new TreeNode(nums[mid]) ;

        root->left=height_relevant(nums,left,mid-1);//这里为什么填left，用0作为左区间呢，因为第二次递归的时候，即运行下面一句的时候，left的值为mid+1，

        root->right=height_relevant(nums,mid+1,right);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return height_relevant(nums,0,nums.size()-1);
    }
};

int main()
{
    return 0;
}