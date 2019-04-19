#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class MyCalendarThree1
{
    map<int,int>time;
public:
    MyCalendarThree1()
    {

    }

    int book(int start, int end)
    {
        time[start]++;
        time[end]--;
        int n=time.size();
        int ans=0,tmp=0;
        for(pair<int,int> it:time)
        {
            tmp+=it.second;
            ans=max(tmp,ans);
        }
        return ans;
    }
};

class MyCalendarThree2
{
public:
    struct node
    {
        int L,R;
    };
    vector<node>vec;
    int cur;
    static bool cmp(const node&a,const node&b)
    {
        if(a.L==b.L)
            return a.R<b.R;
        return a.L<b.L;
    }
public:
    MyCalendarThree2()
    {
        cur=0;
    }

    int book(int start, int end)
    {
        int n=vec.size();
        vector<node>temp;
        for(int i=0;i<n;i++)
        {
            if(end<=vec[i].L||start>=vec[i].R)
                continue;
            else
            {
                temp.push_back(node{max(start,vec[i].L),min(end,vec[i].R)});
            }
        }
        temp.push_back(node{start,end});
        sort(temp.begin(),temp.end(),cmp);
        n=temp.size();
        int tmp=1;
        for(int i=0;i<n;i++)
        {
            priority_queue<int,vector<int>,greater<int> >H;
            tmp=0;
            H.push(temp[i].R);
            for(int j=i;j<n;j++)
            {
                if(temp[j].L<H.top())
                {
                    tmp++;
                    this->cur=max(cur,tmp);
                    H.push(temp[j].R);
                }
                else
                {
                    if(H.empty())
                        break;
                    H.pop();
                    tmp--;
                    j--;
                }
            }
        }
        vec.push_back(node{start,end});
        return this->cur;
    }
};

int main()
{}
