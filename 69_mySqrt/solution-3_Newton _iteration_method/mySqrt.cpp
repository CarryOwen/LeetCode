#include "vector"
#include "iostream"
#include "algorithm"
#include "math.h"
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        double C = x, x0 = x;
        while (true) {
            //f(x)=x^2-C,C为待求出平方根的整数
            //求C的平方根即为求f(x)的正数零点x。即0=x^2-C，C^1/2=x
            //xi的斜率为2*xi,经过的点为（xi,xi^2-C）对应的直线方程为f(x)=2*xi(x-xi)+xi^2-C
            //然后求与x轴的交点x的坐标，即令2*xi(x-xi)+xi^2-C=0,求出x的值
            //因为都是非负整数，所以最小为1，平方根不可能超过其本身，所以将x0=x作为初始值
            //其实问题的本质是已知一点的斜率和一个坐标，求直线方程，并一直迭代，一直到小于1e^-7
            double xi = 0.5 * (x0 + C / x0);
            if (fabs(x0 - xi) < 1e-7) {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};

int main()
{
    return 0;
}