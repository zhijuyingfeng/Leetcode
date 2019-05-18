#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

class Solution
{
public:
    static int Get(const int&x,const int&m,const int&n)
    {
        int root=sqrt(x),sum=0;
        for(int i=1;i<=m;i++)
        {
            sum+=min(x/i,n);
        }
        return sum;
    }
    int findKthNumber(int m, int n, int k)
    {
        int l=1,r=k,mid,temp;
        while(l<r)
        {
            mid=(l+r)>>1;
            temp=Get(mid,m,n);
            if(temp>=k)
                r=mid;
            else if(temp<k)
                l=mid+1;
        }
        return l;
    }
};
int main()
{
    vector<int>vec={2,1,5,6,2,3};
    Solution S;
    int m=2,n=3,k=6;
    cout<<S.findKthNumber(m,n,k)<<endl;
//    cout<<Solution::Get(16,6,6)<<endl;
    return 0;
}
