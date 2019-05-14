#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;

class Solution
{
public:
    static bool cmp(const vector<int>&a,const vector<int>&b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    static int maxEnvelopes(vector<vector<int>>& nums)
    {
        int n=nums.size();
        if(n<1)
            return 0;
        vector<vector<int>>dp;
        sort(nums.begin(),nums.end(),cmp);
        int L=0,cnt=1,R=cnt-1;
        dp.resize(n);
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            L=0,R=cnt-1;
            if(nums[i][1]>dp[R][1])
            {
                dp[cnt++]=nums[i];
            }
            else
            {
                int mid=(L+R)>>1;
                while(L<R)
                {
                    if(nums[i][1]<dp[mid][1])
                        R=mid;
                    else if(nums[i][1]>dp[mid][1])
                        L=mid+1;
                    else
                        break;
                    mid=(L+R)>>1;
                }
                dp[mid]=nums[i];
            }
        }
        return cnt;
    }
};

int main()
{
    vector<vector<int>>vec={{1,2},{2,3},{3,4},{3,5},{4,5},{5,5},{5,6},{6,7},{7,8}};
    cout<<Solution::maxEnvelopes(vec)<<endl;
    return 0;
}
