#include <iostream>
#include <vector>
using namespace std;
// 动态规划
/*
我们用 f(i)代表以第 i 个数结尾的「连续子数组的最大和」
因此我们只需要求出每个位置的 f(i)，然后返回 f 数组中的最大值即可
虑 nums[i] 单独成为一段还是加入f(i−1) 对应的那一段，这取决于 nums[i] 和 f(i-1) +f(i−1)+nums[i] 的大小，我们希望获得一个比较大的，
于是可以写出这样的动态规划转移方程：
f(i)=max{f(i−1)+nums[i],nums[i]}
意思就是，如果前边累加后还不如自己本身大，那就把前边的都扔掉，从此自己本身重新开始累加。
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
		// 逐个取出nums的元素
        for (const auto &x: nums) {
			// 前边累加后还不如自己本身大，那就把前边的都扔掉，从此自己本身重新开始累加
            pre = max(pre + x, x);
			// 找到最大值
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};
int main()
{
	Solution so;
	vector<int> nums={1,5,2,6,121,545};
	so.maxSubArray(nums);
	system("pause");
	return 0;
}