#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
// 动态规划 -滚动数组

/*
思路 一般看到题目有多少种方案，这种题意思不需要你列出来具体的多少种方案只需要计算有多少种方案，基本上就可以尝试用动态规划算法来解决问题。想好用动态规划就想想动态规划五步曲。

关键词：有多少种方案 算法

确定dp数组以及下标的含义 定义dp[i]为爬上第 i 级台阶有多少种方案；
确定状态转移方程 因为每次只可以爬1或者2个台阶所以，爬上当前台阶的方案应该是前面两个状态的方案的和即，dp[i] = dp[i-1] + dp[i-2]。
初始化状态 i = 0 级开始爬的，所以从第 0 级爬到第 0 级我们可以看作只有一种方案，即 dp(0)=1； i = 1 代表从第 0 级到第 1 级也只有一种方案，即爬一级，dp(1) = 1。
遍历顺序 由状态转移方程知道dp[i] 是从 dp[i−1] 和 dp[i−2] 转移过来所以从前往后遍历。
返回值 因为一共计算 n 阶楼梯有多少方案，所以返回dp[n]。
*/
class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            //这里实现了数组的滚动
            p = q; 
            q = r; 
            r = p + q;//每次爬楼梯的方法都是前两次的和
        }
         cout << "method:"<<r<<endl;
        return r;
    }
};
int main()
{
    int n=44;
    Solution so;
    so.climbStairs(n);
    system("pause");
    return 0;
}