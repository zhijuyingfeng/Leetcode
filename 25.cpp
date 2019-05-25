#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* add(ListNode* L,const int &x)
{
    ListNode*node=new ListNode(x);
    node->next=L->next;
    L->next=node;
    return L;
}

void destroy(ListNode* L)
{
    ListNode *p=L,*temp;
    while(L->next)
    {
        temp=L->next;
        L->next=temp->next;
        delete temp;
    }
    delete L;
}

void show(ListNode* L)
{
    ListNode *p=L;
    while(p)
    {
        cout<<p->val<<"-->";
        p=p->next;
    }
    cout<<"NULL"<<endl;
}

class Solution
{
public:
    static ListNode* reverseKGroup(ListNode *head, int k)
    {
        ListNode* L=new ListNode(0);
        L->next=head;
        ListNode *p=L,*start,*temp;
        bool end=0;
        while(p)
        {
            start=p;
            for(int i=0;i<k;i++)
            {
                p=p->next;
                if(!p)
                {
                    end=1;
                    break;
                }
            }
            if(end)
                break;
            for(int i=0;i<k-1;i++)
            {
                temp=start->next;
                start->next=temp->next;
                temp->next=p->next;
                p->next=temp;
            }
            for(int i=0;i<k-1;i++)
            {p=p->next;}
        }
        temp=L->next;
        delete L;
        return temp;
    }
};

int main()
{
    ListNode* L=new ListNode(1);
    for(int i=5;i>1;i--)
        L=add(L,i);
    L=Solution::reverseKGroup(L,2);
    show(L);
    destroy(L);
    return 0;
}
