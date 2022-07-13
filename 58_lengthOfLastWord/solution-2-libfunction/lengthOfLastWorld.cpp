#include "vector"
#include "algorithm"
#include "iostream"
using namespace std;
class Solution {
public:
    //C++ 去字符串两边的空格,tirm函数其他库有，标准c++没有
    void trim(string &s) 
    {
        if (s.empty()) 
        {
            return ;
        }
        s.erase(0,s.find_first_not_of(" "));//擦除前面所有空格
        s.erase(s.find_last_not_of(" ") + 1);//擦除后面所有空格
    }
    int lengthOfLastWord(string s) {
        trim(s);
        return s.length()-s.find_last_of(' ')-1;
    }
};
int main()
{
    string s=" fly me   to   the moon ";
    Solution so;
    so.lengthOfLastWord(s);
    system("pause");
    return 0;
}