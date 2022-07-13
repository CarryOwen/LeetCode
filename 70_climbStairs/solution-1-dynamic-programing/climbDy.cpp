#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
// 动态规划 -动态数组
class Solution {
public:
    int climbStairs(int n) {
        int p = 0, q = 0, r = 1;
        for (int i = 1; i <= n; ++i) {
            p = q; 
            q = r; 
            r = p + q;
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