#include"iostream"
#include "algorithm"
#include "string"
#include "vector"
using namespace std;

void Calculate(int amount ,vector<int> & vec)
{
    if(amount==50||amount==70||amount==90)
    {
        vec.push_back(1);
        vec.push_back(amount%50/20);
    }
    else
    {
        vec.push_back(0);
        vec.push_back(amount/20);
    }
}
int main() {
    int INDEX_FLAG=1;
    int bred=1;
    while(true)
    {
        INDEX_FLAG++;
        bred++;
        INDEX_FLAG==9?INDEX_FLAG=1:INDEX_FLAG=INDEX_FLAG;
        cout<<"INDEX_FLAG: "<<INDEX_FLAG<<endl;
        if(bred==20)
            break;
        
    }
    system("pause");
    return 0;
}