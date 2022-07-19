#include "iostream"
#include "algorithm"
#include "vector"
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       
        if(head == nullptr)
            return nullptr;
        ListNode *tmphead = head->next;
        ListNode *curr = head;
        while (curr->next != nullptr)
        {
            if (curr->val == tmphead->val)//如果当前的和下一个节点的值相等，则删除下一个节点
            {
                curr->next =tmphead->next;
                tmphead=curr->next;
            }
            else//如果两个值不相等，则移动curr
            {
                curr=curr->next;
                tmphead=curr->next;
            }
            
        }
        return head;
    }
};
void insertList(ListNode* head ,int val)
{
    ListNode * tmphead=head,*insertNode=nullptr;
    
    while (tmphead->next != nullptr)
    {
        tmphead=tmphead->next;
    }
    insertNode=new ListNode;
    insertNode->val=val;
    insertNode->next=nullptr;
    tmphead->next=insertNode;
    
}
int main()
{
    Solution so;
    ListNode head(1);
    insertList(&head,1);
    insertList(&head,2);
    insertList(&head,2);
    insertList(&head,1);
    insertList(&head,1);
    insertList(&head,5);
    so.deleteDuplicates(&head);
    return 0;
}