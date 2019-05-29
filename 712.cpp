#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

class Solution
{
public:
    static int minimumDeleteSum(string s1, string s2)
    {
        size_t len1=s1.size(),len2=s2.size();
        vector<vector<int>>dp;
        dp.resize(len1);
        for(size_t i=0;i<len1;i++)
            dp[i].resize(len2);
        for(size_t i=0;i<len1;i++)
        {
            for(size_t j=0;j<len2;j++)
            {
                if(s1[i]==s2[j])
                {
                    if(i&&j)
                        dp[i][j]=dp[i-1][j-1]+s1[i];
                    else
                        dp[i][j]=s1[i];
                }
                else
                {
                    if(i>0)
                        dp[i][j]=dp[i-1][j];
                    if(j>0)
                        dp[i][j]=max(dp[i][j],dp[i][j-1]);
                }
            }
        }
        int sum=0;
        for(size_t i=0;i<len1;i++)
            sum+=s1[i];
        for(size_t i=0;i<len2;i++)
            sum+=s2[i];
        return sum-(dp[len1-1][len2-1]<<1);
    }
};

int main()
{
    cout<<Solution::minimumDeleteSum("sea","eat")<<endl;
    return 0;
}
