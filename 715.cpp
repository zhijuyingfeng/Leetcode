#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

class RangeModule
{
    struct interval
    {
        int L,R;
        interval* next;
        interval(const int&l,const int&r):L(l),R(r),next(nullptr){}
        interval():L(0),R(0),next(nullptr){}
    };

    interval* LL;
public:
    RangeModule()
    {
        LL=new interval;
    }

    ~RangeModule()
    {
        interval* temp;
        while(LL->next)
        {
            temp=LL->next;
            LL->next=temp->next;
            delete temp;
        }
        delete LL;
    }

    void addRange(int left, int right)
    {
        interval *p=LL,*temp;
        int l,r=0;
        while(p&&p->next)
        {
            if(left<p->next->L&&left>p->R)
            {
                l=left;
                while(p&&p->next)
                {
                    if(right<p->next->L&&right>p->R)
                    {
                        r=right;
                        break;
                    }
                    else if(right>=p->next->L&&right<=p->next->R)
                    {
                        r=p->next->R;
                        temp=p->next;
                        p->next=temp->next;
                        delete temp;
                        break;
                    }
                    else if(right>p->next->R)
                    {
                        temp=p->next;
                        p->next=temp->next;
                        delete temp;
                    }
                }
                if(!p->next&&!r)
                    r=right;
                interval* node=new interval(l,r);
                node->next=p->next;
                p->next=node;
                return;
            }
            else if(left>=p->next->L&&left<=p->next->R)
            {
                l=p->next->L;
                while(p&&p->next)
                {
                    if(right>=p->next->L&&right<=p->next->R)
                    {
                        r=p->next->R;
                        temp=p->next;
                        p->next=temp->next;
                        delete temp;
                        break;
                    }
                    else if(right<p->next->L&&right>p->R)
                    {
                        r=right;
                        break;
                    }
                    else if(right>p->next->R)
                    {
                        temp=p->next;
                        p->next=temp->next;
                        delete temp;
                    }
                }
                if(!p->next&&!r)
                    r=right;
                interval* node=new interval(l,r);
                node->next=p->next;
                p->next=node;
                return;
            }
            p=p->next;
        }
        if(!p->next)
        {
            interval* node=new interval(left,right);
            p->next=node;
        }
    }

    bool queryRange(int left, int right)
    {
        interval* p=LL->next;
        while(p)
        {
            if(left>=p->L&&right<=p->R)
                return true;
            if(p->L>right)
                return false;
            p=p->next;
        }
        return false;
    }

    void removeRange(int left, int right)
    {
        interval *p=LL, *temp;
        while(p&&p->next)
        {
            if(p->next->L>right)
                return;
            else if(left<=p->next->L&&left>=p->R)
            {
                while(p&&p->next)
                {
                    if(right>p->R&&right<=p->next->L)
                    {
                        return;
                    }
                    else if(right>=p->next->L&&right<p->next->R)
                    {
                        p->next->L=right;
                        return;
                    }
                    else if(right>=p->next->R)
                    {
                        temp=p->next;
                        p->next=temp->next;
                        delete temp;
                    }
                }
            }
            else if(left>p->next->L&&left<p->next->R)
            {
                p=p->next;
                if(right<p->R)
                {
                    interval *node=new interval(right,p->R);
                    p->R=left;
                    node->next=p->next;
                    p->next=node;
                    return;
                }
                else if(right==p->R)
                {
                    p->R=left;
                    return;
                }
                while(p&&p->next)
                {
                    if(right>=p->R&&right<=p->next->L)
                    {
                        p->R=left;
                        return;
                    }
                    else if(right>p->next->L&&right<p->next->R)
                    {
                        p->next->L=right;
                        p->R=left;
                        return;
                    }
                    else if(right>=p->next->R)
                    {
                        temp=p->next;
                        p->next=temp->next;
                        delete temp;
                    }
                }
                if(!p->next)
                {
                    p->R=left;
                }
                return;
            }
            p=p->next;
        }
    }
};

int main()
{
    RangeModule RM;
    RM.addRange(44,53);
    RM.addRange(69,89);
    RM.removeRange(86,91);
    RM.addRange(87,94);
    RM.removeRange(34,52);
    RM.addRange(1,59);
    RM.removeRange(62,96);
    RM.removeRange(34,83);
    cout<<RM.queryRange(11,59)<<endl;
    cout<<RM.queryRange(59,79)<<endl;
    cout<<RM.queryRange(1,13)<<endl;
    return 0;
}
