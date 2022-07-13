#include "vector"
#include "iostream"
#include "algorithm"
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int index = s.size() - 1;
        //最后一个有可能是连续空格
        while (s[index] == ' ') {
            index--;
        }
        int wordLength = 0;
        //找到单词长度
        while (index >= 0 && s[index] != ' ') {
            wordLength++;
            index--;
        }

        return wordLength;
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