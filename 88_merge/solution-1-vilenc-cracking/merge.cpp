#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //合并后排序
        for (int i = 0; i < n; i++)
        {
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
    }
        

};
int main()
{
    Solution so;
    vector<int> nums1={1,2,3,0,0,0},nums2={2,5,6};
    so.merge(nums1,3,nums2,3);
    return 0;
}