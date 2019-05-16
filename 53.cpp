#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int ans=nums[0],sum=0;
        int n=nums.size();
        int i;
        for(i=0;i<n;i++)
        {
            if(nums[i]>=0)
                break;
            ans=max(ans,nums[i]);
        }
        if(i==n)
        {
            return ans;
        }
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum<0)
                sum=0;
            ans=max(ans,sum);
        }
        return ans;
    }
};

int main()
{
    vector<int>vec={-1};
    Solution S;
    cout<<S.maxSubArray(vec)<<endl;
    return 0;
}
