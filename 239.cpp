#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
	struct Node
	{
		int num,pos;
	};
	class cmp
	{
	public:
		bool operator()(const Node&a,const Node&b)
		{
			return a.num<b.num;
		}
	};
	vector<int> maxSlidingWindow(vector<int>& nums, int k)
	{
		if(1==k)
			return nums;
		int n=nums.size();
		vector<int>ans;
		if(!n)
			return ans;
		priority_queue<Node,vector<Node>,cmp>H;
		for(int i=0;i<k;i++)
		{
			H.push(Node{nums[i],i});
		}
		ans.push_back(H.top().num);
		int temp;
		for(int i=1;i<=n-k;i++)
		{
			while(1)
			{
				temp=H.top().pos;
				if(temp>=i&&temp<i+k)
					break;
				H.pop();
			}
			H.push(Node{nums[i+k-1],i+k-1});
			ans.push_back(H.top().num);
		}
		return ans;
	}
};

int main()
{
	vector<int> vec={};
	Solution S;
	vector<int>ans=S.maxSlidingWindow(vec,3);
	return 0;
}
