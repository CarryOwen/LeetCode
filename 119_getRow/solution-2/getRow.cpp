#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> vec(rowIndex+1);
        
        for (int i =0; i < rowIndex+1; i++)
        {
            vec[i].resize(i+1);
            vec[i][0]=vec[i][i]=1;
            for (int j=1; j<i; j++)
            {
                vec[i][j]=vec[i-1][j-1]+vec[i-1][j];
            }
        }
        return vec[rowIndex];

    }
};
// 示例 1:
// 输入: rowIndex = 3
// 输出: [1,3,3,1]
int main() {
    Solution so;
    so.getRow(3);
    system("pause");
    return 0;
}