#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i) {
            //第几行就有几个元素，例如第三行，里面有{1,2,1}
            ret[i].resize(i + 1);
            //第一个元素和最后一个元素都是1
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                //该行的元素值为上一行的左侧值和右侧值相加
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return ret;
    }
};
int main()
{

    system("pause");
    return 0;
}