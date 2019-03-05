#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

class Solution
{
	int cnt;
public:
	void MergeSort(vector<int>& nums,const int &L,const int &R)
	{
		int M=(L+R)>>1;
//		if(R-L==1)
//		{
//			if(nums[L]>nums[R])
//			{
//				long long a=nums[L],b=2*(long long)nums[R];
//				if(a>b)
//					cnt++;
//				swap(nums[L],nums[R]);
//			}
//		}
//		else
			if(R-L>0)
		{
			MergeSort(nums,L,M);
			MergeSort(nums,M+1,R);
		}
		static int temp[50000];
		for(int i=L;i<=R;i++)
		{
			temp[i]=nums[i];
		}
		int i=L,j=M+1,pos=L;

		while(i<=M&&j<=R)
		{
			long long a=temp[i],b=2*(long long)temp[j];
			if(a>b)
			{
				j++;
				cnt+=M-i+1;
			}
			else
			{
				i++;
			}
		}

		i=L,j=M+1,pos=L;
		while(i<=M&&j<=R)
		{
			if(temp[i]<=temp[j])
			{
				nums[pos++]=temp[i++];
			}
			else
			{
				nums[pos++]=temp[j++];
			}
		}
		while(i<=M)
		{
			nums[pos++]=temp[i++];
		}
		while(j<=R)
		{
			nums[pos++]=temp[j++];
		}
	}
	int reversePairs(vector<int>& nums)
	{
		int n=nums.size();
		MergeSort(nums,0,n-1);
//		for(int i=0;i<n;i++)
//		{
//			cout<<nums[i]<<" ";
//		}
//		cout<<endl;
		return cnt;
	}
	Solution()
	{
		cnt=0;
	}
};

int main()
{
	Solution S;
	vector<int>vec={5,5,5,1,2,2,2};
	cout<<S.reversePairs(vec)<<endl;
	return 0;
}
