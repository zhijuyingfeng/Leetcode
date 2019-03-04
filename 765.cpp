#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int find(int par[],int x)
	{
		if(par[x]==-1)
			return -1;
		return x==par[x]?x:par[x]=find(par,par[x]);
	}
	int minSwapsCouples(vector<int>& row)
	{
		int par[60];
		memset(par,0xff,sizeof(int)*60);
		int n=row.size();
		int arr[4],res[4];
		for(int i=0;i<n>>1;i++)
		{
			arr[0]=row[i<<1];
			arr[1]=arr[0]^1;
			arr[2]=row[(i<<1)+1];
			arr[3]=arr[2]^1;
			for(int j=0;j<4;j++)
				res[j]=find(par,arr[j]);
			if(res[1]==-1&&res[3]==-1)
			{
				par[arr[0]]=arr[0];
				par[arr[2]]=arr[0];
			}
			else if(res[1]>=0&&res[3]>=0)
			{
				par[arr[0]]=res[1];
				par[arr[2]]=res[1];
				par[res[3]]=res[1];
			}
			else if(res[1]>=0)
			{
				par[arr[0]]=res[1];
				par[arr[2]]=res[1];
			}
			else if(res[3]>=0)
			{
				par[arr[0]]=res[3];
				par[arr[2]]=res[3];
			}

		}
		int cnt[60]={0};
		for(int i=0;i<n;i++)
		{
			int p=find(par,row[i]);
			cnt[p]++;
		}
		int ans=0;
		for(int i=0;i<60;i++)
		{
			if(cnt[i])
			{
				ans+=(cnt[i]>>1)-1;
			}
		}
		return ans;
	}
};


int main()
{
	vector<int> vec={10,7,4,2,3,0,9,11,1,5,6,8};
	Solution S;
	int ans=S.minSwapsCouples(vec);
	cout<<ans<<endl;
	return 0;
}
