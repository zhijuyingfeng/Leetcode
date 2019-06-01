#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;

struct node
{
    int key,value,num;
    node(const int&k,const int&v,const int&n):
        key(k),value(v),num(n){}
};

class cmp
{
public:
    bool operator()(const node&a,const node&b)
    {
        if(a.value==b.value)
            return a.num<b.num;
        return a.value<b.value;
    }
};

class FreqStack
{
public:
    priority_queue<node,vector<node>,cmp>H;
    map<int,int>M;
    int num;
    FreqStack()
    {
        num=0;
    }

    void push(int x)
    {
        M[x]++;
        H.push(node(x,M[x],num));
        num++;
    }

    int pop()
    {
        node p(0,0,0);
        while(1)
        {
            p=H.top();
            H.pop();
            if(p.value==M[p.key])
            {
                M[p.key]--;
                break;
            }
        }
        return p.key;
    }
};

int main()
{
    FreqStack FS;
    int arr[]={5,7,5,7,4,5};
    int n=sizeof(arr)/sizeof (int);
    for(int i=0;i<n;i++)
        FS.push(arr[i]);
    for(int i=0;i<4;i++)
        cout<<FS.pop()<<endl;
    return 0;
}
