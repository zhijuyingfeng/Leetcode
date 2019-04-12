#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    static int canCompleteCircuit(vector<int>& gas, vector<int>& cost)
    {
        int n=gas.size();
        int sum1=0,sum2=0;
        vector<int>dp;
        dp.resize(n*2-1);
        for(int i=0;i<n;i++)
        {
            sum1+=gas[i];
            sum2+=cost[i];
            dp[i]=gas[i]-cost[i];
        }
        for(int i=0;i<n-1;i++)
        {
            dp[n+i]=dp[i];
        }
        if(sum1<sum2)
            return -1;
        int pos=0,Max=0,ans=0;
        sum1=0;
        for(int i=0;i<2*n-1;i++)
        {
            if(sum1+dp[i]>0)
            {
                sum1+=dp[i];
                if(sum1>Max)
                {
                    Max=sum1;
                    ans=pos;
                }
            }
            else
            {
                sum1=0;
                pos=i+1;
            }
        }
        return ans;
    }
};
int main()
{
    vector<int> gas={5,8,2,8},cost={6,5,6,6};
    cout<<Solution::canCompleteCircuit(gas,cost)<<endl;
    return 0;
}
