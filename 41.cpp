#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	static int firstMissingPositive(vector<int>& nums) {
		int n=nums.size();
		int temp;
		for(int i=0;i<n;i++)
		{
			if(nums[i]<=0||nums[i]>n)
			{
				nums[i]=-1;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(nums[i]<=0||nums[i]>n)
				continue;
			if(nums[i]==i+1)
			{
				nums[i]=0;
				continue;
			}
			if(nums[nums[i]-1]==0)
				continue;
			temp=nums[nums[i]-1];
			nums[nums[i]-1]=0;
			nums[i]=temp;
			i--;
		}
		for(int i=0;i<n;i++)
		{
			if(nums[i])
				return i+1;
		}
		return n+1;
	}
};
int main()
{
	vector<int> vec={3,4,-1,1};
	cout<<Solution::firstMissingPositive(vec)<<endl;
	return 0;
}
