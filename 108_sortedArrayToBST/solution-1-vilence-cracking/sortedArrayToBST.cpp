#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;
//中序遍历   
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
    }
};
int main()
{
    return 0;
}