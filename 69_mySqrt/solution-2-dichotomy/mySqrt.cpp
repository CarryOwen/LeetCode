#include"vector"
#include"algorithm"
#include"iostream"
using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        //二分法的左右边界
        int l = 0, r = x, ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            //如果中间值的平方小于目标值，则说明目标值在右侧空间，所以将左侧边界l右移，l=mid=+1
            if ((long long)mid * mid <= x) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
int main()
{
    return 0;
}