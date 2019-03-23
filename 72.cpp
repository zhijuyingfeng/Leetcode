#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;

class Solution
{
public:
	static int minDistance(string word1, string word2)
	{
		int len1=word1.length(),len2=word2.length();
		int **dp=new int*[len1+1];
		for(int i=0;i<=len1;i++)
		{
			dp[i]=new int[len2+1];
			memset(dp[i],0x3f,sizeof(int)*(1+len2));
		}
//		int dp[10][10];
		for(int i=0;i<=len1;i++)
		{
			dp[i][0]=i;
		}
		for(int i=0;i<=len2;i++)
		{
			dp[0][i]=i;
		}
		for(int i=1;i<=len1;i++)
		{
			for(int j=1;j<=len2;j++)
			{
				dp[i][j]=min(min(dp[i-1][j],dp[i][j-1])+1,dp[i-1][j-1]+(word1[i-1]==word2[j-1]?0:1));
			}
		}
		int temp=dp[len1][len2];
		for(int i=0;i<=len1;i++)
			delete[]dp[i];
		delete[]dp;
		return temp;
	}
};
int main()
{
	cout<<Solution::minDistance("intention","execution")<<endl;
	return 0;
}
