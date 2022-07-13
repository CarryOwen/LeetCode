#include "vector"
#include "iostream"
using namespace std;
/*分治法
我们定义一个操作 get(a, l, r) 表示查询 a序列 [l,r]区间内的最大子段和，那么最终我们要求的答案就是 get(nums, 0, nums.size() - 1)。
如何分治实现这个操作呢？对于一个区间 [l,r]，我们取 m = {(l + r)/2}
对区间 [l,m] 和 [m+1,r]
分治求解。当递归逐层深入直到区间长度缩小为 1 的时候，递归「开始回升」。
这个时候我们考虑如何通过 [l,m] 区间的信息和[m+1,r] 区间的信息合并成区间 [l,r] 的信息。
最关键的两个问题是：
我们要维护区间的哪些信息呢？
我们如何合并这些信息呢？
对于一个区间 [l,r]，我们可以维护四个量：
lSum 表示 [l,r]内以 l 为左端点的最大子段和
rSum 表示 [l,r]内以 r 为右端点的最大子段和
mSum 表示 [l,r]内的最大子段和
iSum 表示 [l,r] 的区间和
以下简称 [l,m]为 [l,r] 的「左子区间」，[m+1,r]为 [l,r]的「右子区间」。
我们考虑如何维护这些量呢（如何通过左右子区间的信息合并得到 [l,r]的信息）？对于长度为 1 的区间 [i, i]，四个量的值都和 nums[i] 相等。
对于长度大于 1 的区间：
首先最好维护的是 iSum，区间 [l,r] 的 iSum 就等于「左子区间」的 iSum 加上「右子区间」的iSum。
对于 [l,r]的 lSum，存在两种可能，它要么等于「左子区间」的 lSum，要么等于「左子区间」的 iSum 加上「右子区间」的 lSum(这个iSum是以m+1为左端点的最大子段和)，二者取大。
对于 [l,r]的 rSum，同理，它要么等于「右子区间」的 rSum，要么等于「右子区间」的 iSum 加上「左子区间」的 rSum（这个rSum是以m为右端点的最大子段和），二者取大。
当计算好上面的三个量之后，就很好计算 [l,r]的 mSum 了。
我们可以考虑 [l,r] 的 mSum 对应的区间是否跨越 m——它可能不跨越 m，
也就是说 [l,r] 的 mSum 可能是「左子区间」的 mSum 和 「右子区间」的 mSum 中的一个；
它也可能跨越 m，可能是「左子区间」的 rSum 和 「右子区间」的 lSum 求和。三者取大。
*/
class Solution {
public:
    struct Status {
        int lSum, rSum, mSum, iSum;
    };

    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;//左右区间和等于总的区间和
        int lSum = max(l.lSum, l.iSum + r.lSum);
        int rSum = max(r.rSum, r.iSum + l.rSum);
        int mSum = max(max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status) {lSum, rSum, mSum, iSum};
    };

    Status get(vector<int> &a, int l, int r) {
        if (l == r) {//数组长度为1的时候
            return (Status) {a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;//右移1位即除2，取中点
        //层层递归，就是从长度为1开始，找lSub,再找长度为2的lSub.
        //每个lSub都有自己的lSum, rSum, mSum, iSum
        //最终找到l,m的四个参数lSum, rSum, mSum, iSum
        Status lSub = get(a, l, m);
        //同理
        Status rSub = get(a, m + 1, r);
        return pushUp(lSub, rSub);
    }

    int maxSubArray(vector<int>& nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
};
int main()
{
    vector<int> tmpvector={2,-1,3}  ;
    Solution so;
    so.maxSubArray(tmpvector);
    return 0;
}