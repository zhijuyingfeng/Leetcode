#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;

class MyCalendarTwo
{
    struct node
    {
        int L,R;
    };
    static bool cmp(const node&a,const node&b)
    {
        if(a.L==b.L)
            return a.R<b.R;
        return a.L<b.L;
    }
    vector<node> vec;
public:
    MyCalendarTwo()
    {

    }

    bool book(int start, int end)
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
        sort(temp.begin(),temp.end(),cmp);
        n=temp.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n-1;j++)
            {
                if(temp[j].R>temp[j+1].L)
                    return false;
            }
        }
        vec.push_back(node{start,end});
        return true;
    }
};

int main()
{}
