#include "iostream"
#include "vector"
#include "algorithm"
#include "sstream"
#include "bitset"
#include "string"
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int lenA=a.length();
        int lenB=b.length();
        string result;
        int delta=0;
        if(lenA>lenB)
        {
            for(int i=lenB-1,j=lenA-1; i>=0; i--,j--) {
                if(delta)//有进位
                {
                    if(a[j]==b[i]&&a[j]=='1')//两个都为1
                    {
                        result.insert(result.begin(),'1');
                        delta=1;
                    }else if(a[j]=='1'||b[i]=='1')//两个有一个为1
                    {
                        result.insert(result.begin(),'0');
                        delta=1;
                    }else if(a[j]==b[i]&&a[j]=='0')//两个都为0
                    {
                        result.insert(result.begin(),'1');
                        delta=0;
                    }
                }else{//无进位
                    if(a[j]==b[i]&&a[j]=='1')//两个都为1
                    {
                        result.insert(result.begin(),'0');
                        delta=1;
                    }else if(a[j]=='1'||b[i]=='1')//两个有一个为1
                    {
                        result.insert(result.begin(),'1');
                        delta=0;
                    }else if(a[j]==b[i]&&a[j]=='0')//两个都为0
                    {
                        result.insert(result.begin(),'0');
                        delta=0;
                    }
                }

             }
            for(int j=lenA-lenB-1; j>=0;j--)
            {
                     if(delta)//有进位
                     {
                        if(a[j]=='1')
                        {
                            result.insert(result.begin(),'0');
                            delta=1;
                            if(j-1<0)
                                result.insert(result.begin(),'1');
                        }else if(a[j]=='0')
                        {
                            result.insert(result.begin(),'1');
                            delta=0;
                        }
                     }else  
                     {
                        result.insert(result.begin(),a[j]);
                     }
                   
            }
        }else if(lenA==lenB)
        {
            for(int i=lenB-1,j=lenA-1; i>=0; i--,j--) {
                if(delta)//有进位
                {
                    if(a[j]==b[i]&&a[j]=='1')//两个都为1
                    {
                        result.insert(result.begin(),'1');
                        delta=1;
                    }else if(a[j]=='1'||b[i]=='1')//两个有一个为1
                    {
                        result.insert(result.begin(),'0');
                        delta=1;
                    }else if(a[j]==b[i]&&a[j]=='0')//两个都为0
                    {
                        result.insert(result.begin(),'1');
                        delta=0;
                    }
                }else{//无进位
                    if(a[j]==b[i]&&a[j]=='1')//两个都为1
                    {
                        result.insert(result.begin(),'0');
                        delta=1;
                    }else if(a[j]=='1'||b[i]=='1')//两个有一个为1
                    {
                        result.insert(result.begin(),'1');
                        delta=0;
                    }else if(a[j]==b[i]&&a[j]=='0')//两个都为0
                    {
                        result.insert(result.begin(),'0');
                        delta=0;
                    }
                } 
                if(i-1<0&&delta==1)
                    result.insert(result.begin(),'1');
             }
        } else{
            for(int i=lenB-1,j=lenA-1; j>=0; j--,i--) {
                if(delta)//有进位
                {
                    if(a[j]==b[i]&&a[j]=='1')//两个都为1
                    {
                        result.insert(result.begin(),'1');
                        delta=1;
                    }else if(a[j]=='1'||b[i]=='1')//两个有一个为1
                    {
                        result.insert(result.begin(),'0');
                        delta=1;
                    }else if(a[j]==b[i]&&a[j]=='0')//两个都为0
                    {
                        result.insert(result.begin(),'1');
                        delta=0;
                    }
                }else{//无进位
                    if(a[j]==b[i]&&a[j]=='1')//两个都为1
                    {
                        result.insert(result.begin(),'0');
                        delta=1;
                    }else if(a[j]=='1'||b[i]=='1')//两个有一个为1
                    {
                        result.insert(result.begin(),'1');
                        delta=0;
                    }else if(a[j]==b[i]&&a[j]=='0')//两个都为0
                    {
                        result.insert(result.begin(),'0');
                        delta=0;
                    }
                }  
             }
            for(int j=lenB-lenA-1; j>=0;j--)
            {
                     if(delta)//有进位
                     {
                        if(b[j]=='1')
                        {
                            result.insert(result.begin(),'0');
                            delta=1;
                            if(j-1<0)
                                result.insert(result.begin(),'1');
                        }else if(b[j]=='0')
                        {
                            result.insert(result.begin(),'1');
                            delta=0;
                        }
                     }else  
                     {
                        result.insert(result.begin(),b[j]);
                     }
                   
            }
        }
        return result;
    }
};
int main()
{
    Solution so;
    string a="100";
    string b="110010";
    so.addBinary(a,b);
    return 0;
}