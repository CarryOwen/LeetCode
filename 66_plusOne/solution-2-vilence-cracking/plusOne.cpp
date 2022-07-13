#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        for (int i = n - 1; i >= 0; --i) {
            //如果最后面不等于9，直接＋1返回，等于9则寻找向前寻找第一个不等于9的数＋1，后面的全部置位0
            if (digits[i] != 9) {
                ++digits[i];
                for (int j = i + 1; j < n; ++j) {
                    digits[j] = 0;
                }
                return digits;
            }
        }

        // digits 中所有的元素均为 9
        vector<int> ans(n + 1);
        ans[0] = 1;
        return ans;
    }
};
int main()
{

    return 0;
}