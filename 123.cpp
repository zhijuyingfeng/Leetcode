#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    static int maxProfit(vector<int>& prices)
    {
        int n=prices.size();
        if(n<2)
            return 0;
        vector<int>L,R;
        int Min=0,Max=0,MAX=0;
        for(int i=0;i<n;i++)
        {
            if(prices[i]>prices[Max])
            {
//                Min=i;
                Max=i;
            }
            if(prices[i]<prices[Min])
            {
                Min=i;
                Max=i;
            }
            MAX=max(MAX,prices[Max]-prices[Min]);
            L.push_back(MAX);
        }
        R.resize(n);
        Max=n-1,Min=n-1,MAX=0;
        for(int i=n-1;i>=0;i--)
        {
            if(prices[i]>prices[Max])
            {
                Max=i;
                Min=i;
            }
            if(prices[i]<prices[Min])
            {
                Min=i;
//                Max=i;
            }
            MAX=max(MAX,prices[Max]-prices[Min]);
            R[i]=MAX;
        }
        int ans=R[0];
        for(int i=0;i<n-1;i++)
        {
            ans=max(ans,L[i]+R[i+1]);

        }
        return ans;
    }
};

int main()
{
    vector<int> vec={2,1,2,0,1};
    cout<<Solution::maxProfit(vec)<<endl;
}
