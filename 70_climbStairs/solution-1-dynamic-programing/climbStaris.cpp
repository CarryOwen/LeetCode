#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
//动态规划   递归超时
/*
我们用 f(x)表示爬到第 x 级台阶的方案数，考虑最后一步可能跨了一级台阶，也可能跨了两级台阶，所以我们可以列出如下式子：

            f(x) = f(x - 1) + f(x - 2)
    它意味着爬到第 x 级台阶的方案数是爬到第 x - 1 级台阶的方案数和爬到第 x - 2 级台阶的方案数的和。
   很好理解，因为每次只能爬 1 级或 2 级，所以 f(x)只能从 f(x - 1)和 f(x - 2)转移过来，而这里要统计方案总数，
   我们就需要对这两项的贡献求和。
   边界条件，f(0)=1,从0级开始爬，f(1)=1; 
   则f(2)=f(0)+f(1)=2;
   以此类推，即可求得f(n)
 */
class Solution {
public:
    int method_dep(int n) {
        if(n==1||n==0)
        {
          return 1;  
        }else{
            n=method_dep(n-1)+method_dep(n-2);
        }
        return n;
    }
    int climbStairs(int n) {
        int k=method_dep(n);
        cout << "method:"<<k <<endl;
        return k;
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