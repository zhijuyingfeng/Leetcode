#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class LRUCache
{
    struct node
    {
        int key,val;
        int cnt,last;
        node():key(0),val(0),cnt(0x3f3f3f3f),last(0x3f3f3f3f){}
    };

    vector<node>vec;
    vector<int>tree;
    int op,cap,size;
    map<int,int> M;

    int lowbit(const int&x)
    {return x&(-x);}

    void update(const int& pos)
    {
        int temp=pos,lb;

        while(temp<this->cap*4)
        {
            if(temp<=this->cap)
                tree[temp]=temp;
            lb=lowbit(temp);
            for(int i=1;i<lb;i<<=1)
            {
                if(vec[tree[temp]].last>vec[tree[temp-i]].last)
                {
                    tree[temp]=tree[temp-i];
                }
//                else if(vec[tree[temp-i]].cnt>vec[tree[temp]].cnt)
//                {
//                    tree[temp]=temp;
//                }
//                else if(vec[tree[temp]].cnt==vec[tree[temp-i]].cnt)
//                {
//                    if(vec[tree[temp]].last>vec[tree[temp-i]].last)
//                    {
//                        tree[temp]=tree[temp-i];
//                    }
//                    else if(vec[tree[temp]].last<vec[tree[temp-i]].last)
//                    {
//                        tree[temp]=temp;
//                    }
//                }
            }
            temp+=lowbit(temp);
        }
    }

    int query(const int& x)
    {
        int ans=tree[x];
        for(int i=x;i>0;i-=lowbit(i))
        {
            if(vec[tree[i]].cnt<vec[ans].cnt)
            {
                ans=tree[i];
            }
            else if(vec[tree[i]].cnt==vec[ans].cnt&&vec[tree[i]].last<vec[ans].last)
            {
                ans=tree[i];
            }
        }
        return ans;
    }


public:
    LRUCache(int capacity)
    {
        this->cap=capacity;
        vec.resize(this->cap+1);
        tree.resize(this->cap<<2);
        op=0;
        size=0;
    }

    int get(int key)
    {
        if(this->cap<=0||!M[key])
            return -1;
        int pos=M[key];
        vec[pos].cnt++;
        vec[pos].last=op;
        this->update(pos);
        op++;
        return vec[pos].val;
    }

    void put(int key, int value)
    {
        if(this->cap<=0)
            return;
        if(!M[key])//cache is not in cache
        {
            if(this->size<this->cap)//cache is not full
            {
                size++;
                this->vec[size].cnt=1;
                this->vec[size].last=op;
                this->vec[size].val=value;
                this->vec[size].key=key;
                this->update(size);
                M[key]=size;
                op++;
            }
            else//cache is full
            {
                int pos=this->query(this->cap*4-1);
                M.erase(vec[pos].key);
                vec[pos].key=key;
                vec[pos].val=value;
                vec[pos].cnt=1;
                vec[pos].last=op;
                this->update(pos);
                op++;
                M[key]=pos;
            }
        }
        else//the key is in cache
        {
            int pos=M[key];
            vec[pos].val=value;
            vec[pos].cnt++;
            vec[pos].last=op;
            op++;
            this->update(pos);
        }
    }
};


int main()
{
    LRUCache cache (2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout<<cache.get(1)<<endl;       // returns 1
    cache.put(3, 3);    // evicts key 2
    cout<<cache.get(2)<<endl;       // returns -1 (not found)
    cache.put(4, 4);    // evicts key 1
    cout<<cache.get(1)<<endl;       // returns -1 (not found)
    cout<<cache.get(3)<<endl;       // returns 3
    cout<<cache.get(4)<<endl;       // returns 4
    return 0;
}
