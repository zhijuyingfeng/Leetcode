#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
using namespace std;

class Solution
{
public:
	static string shortestPalindrome(string s)
	{
		int len=s.length(),i,j,pos=0;
		bool ok=1;
		for(int k=len>>1;k>=0;k--)
		{
			i=k-1;j=k+1;
			while(i>=0&&j<len)
			{
				if(s[i]!=s[j])
					break;
				i--;j++;
			}
			if(i<0)
			{
				pos=k;
				break;
			}

			i=k-1;j=k;
			while(i>=0&&j<len)
			{
				if(s[i]!=s[j])
					break;
				i--;j++;
			}
			if(i<0)
			{
				pos=k;
				ok=0;
				break;
			}
		}
		string ans;
		if(ok)
		{
			for(int k=len-1;k>pos;k--)
			{
				ans.push_back(s[k]);
			}
			ans.push_back(s[pos]);
			for(int k=pos+1;k<len;k++)
				ans.push_back(s[k]);
		}
		else
		{
			for(int k=len-1;k>=pos;k--)
				ans.push_back(s[k]);
			for(int k=pos;k<len;k++)
				ans.push_back(s[k]);
		}
		return ans;
	}
};

int main()
{
	cout<<Solution::shortestPalindrome("aabababababaababaa")<<endl;
	return 0;
}
//aababaabababababaababaa
//aabababababaababaa
