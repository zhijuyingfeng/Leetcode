#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
	static int jump(vector<int>& nums)
	{
		int n=nums.size();
		int *dp=new int[n];
		memset(dp,0x3f,sizeof(int)*n);
		dp[0]=0;
		int far=1;
		for(int i=0;i<n-1;i++)
		{
			for(int j=far;j<=i+nums[i];j++)
			{
				if(j<n&&dp[j]==0x3f3f3f3f)
				{
					dp[j]=dp[i]+1;
				}
			}
			far=far>(i+nums[i])?far:(nums[i]+i);
		}
		int ans=dp[n-1];
		delete[]dp;
		return ans;
	}
};

int main()
{
	vector<int> vec={2,3,1,1,4};
	cout<<Solution::jump(vec)<<endl;
	return 0;
}
