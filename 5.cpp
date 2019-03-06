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
	static int longest(int i,int j,const string& s)
	{
		int len=s.length();
		int temp=1;
		while(i>=0&&j<len)
		{
			if(s[i]==s[j])
			{
				temp=j-i+1;
				i--,j++;
			}
			else
			{
				break;
			}
		}
		return temp;
	}
	static string longestPalindrome(string s)
	{
		int len=s.length(),max=0,temp,pos=-1;
		for(int i=0;i<len;i++)
		{
			temp=longest(i-1,i+1,s);
			if(temp>max)
			{
				max=temp;
				pos=i;
			}
			temp=longest(i,i+1,s);
			if(temp>max)
			{
				max=temp;
				pos=i;
			}
		}
		if(max==1)
		{
			return s.substr(0,1);
		}
		string ans;
		int start=pos-((max-1)>>1);
		for(int i=0;i<max;i++)
		{
			ans.push_back(s[start+i]);
		}
		return ans;
	}
};

int main()
{
	string ans=Solution::longestPalindrome("cbbd");
	cout<<ans<<endl;
	return 0;
}
