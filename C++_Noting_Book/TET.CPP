#include"iostream"
#include "algorithm"
#include "string"
using namespace std;
int N_Return(int k)
{
    if(k==1||k==2)
        return 1;
    return N_Return(k-1)+N_Return(k-2);
}
bool cpm(int x ,int y)
{
    return x>y?1:0;
}
int main() {
    string a="abcd:efghi:jklmnopq:rstuvwxyz";
    cout<<a.find(":",0)<<endl;

    auto it=a.begin();
    a.insert(it+3,'a');
    cout<<a<<endl;
    system("pause");
    return 0;
}