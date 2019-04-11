#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    static int maxProfit(vector<int>& prices)
    {
        int high=0,bought=0,ans=0;
        int n=prices.size();
        bool goingLow=1;
        for(int i=1;i<n;i++)
        {
            if(prices[i]<prices[i-1])
            {
                if(bought==i-1)
                {
                    bought=i;
                    high=i;
                }
                else
                {
                    ans+=prices[high]-prices[bought];
                    bought=i;
                    high=i;
                }
            }
            else if(prices[i]>=prices[i-1])
            {
                if(prices[i]>=prices[high])
                {
                    high=i;
                }
            }
        }
        if(high==n-1)
        {
            ans+=prices[high]-prices[bought];
        }
        return ans;
    }
};
int main()
{
    vector<int>prices={1,9,6,9,1,7,1,1,5,9,9,9};
    cout<<Solution::maxProfit(prices)<<endl;
    return 0;
}
