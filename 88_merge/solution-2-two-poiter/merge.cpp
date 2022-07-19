#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
//双指针
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0;
        int sorted[m + n];
        int cur;
        //将两个数组的元素都取出来，比较后放入新的数组sorted中
        while (p1 < m || p2 < n) {
            if (p1 == m) {
                cur = nums2[p2++];
            } else if (p2 == n) {
                cur = nums1[p1++];
            } else if (nums1[p1] < nums2[p2]) {
                cur = nums1[p1++];
            } else {
                cur = nums2[p2++];
            }
            sorted[p1 + p2 - 1] = cur;
        }
        for (int i = 0; i != m + n; ++i) {
            nums1[i] = sorted[i];
        }
    }
};
int main()
{
    Solution so;
    vector<int> nums1={1,2,3,0,0,0},nums2={2,5,6};
    so.merge(nums1,3,nums2,3);
    return 0;
}
