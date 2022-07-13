#include"iostream"
#include"vector"
#include"algorithm"
#include"math.h"
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }
        int ans = exp(0.5 * log(x));
        /*
        x^1/2=(e^lnx)^1/2=e^(1/2*lnx)=exp(0.5 * log(x))
        exp是用来计算e的n次幂，log()函数：返回以e为底的对数值也就是lnx
        由于计算机无法存储浮点数的精确值（浮点数的存储方法可以参考 IEEE 754，这里不再赘述），而指数函数和对数函数的参数和返回值均为浮点数，因此运算过程中会存在误差。例如当 x = 2147395600 时，
  的计算结果与正确值 4634046340 相差 10^-11，这样在对结果取整数部分时，会得到 46339 这个错误的结果。因此在得到结果的整数部分ans 后，我们应当找出 ans 与 ans+1 中哪一个是真正的答案*/
        return ((long long)(ans + 1) * (ans + 1) <= x ? ans + 1 : ans);
    }
};
int main(int argc, char** argv) {
    return 0;
}