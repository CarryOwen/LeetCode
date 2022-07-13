#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
class Solution {
public:
    void result(int len,vector<int>& digits)
    {
        if(digits[len-1]<9)
        {
            digits[len-1]=digits[len-1]+1;
        }else
        {
            digits[len-1]=0;
            len=len-1;
            if(len<=0)
            {
                digits.insert(digits.begin(),1);
                return;
            }
            result(len,digits);
        }
    }
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        result(len,digits);
        return digits;
    }
};
int main() {
    Solution so;
    vector<int> digits={9,9,9};
    so.plusOne(digits);
    return 0;
}