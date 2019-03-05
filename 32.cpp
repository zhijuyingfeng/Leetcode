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
	static int longestValidParentheses(string s)
	{
		int len=s.length();
		int max=0,temp;
		for(int i=0;i<len;i++)
		{
			if(s[i]=='(')
			{
				stack<int> S;
				S.push(i);
				int j;
				for(j=i+1;j<len;j++)
				{
					if(s[j]=='(')
					{
						S.push(j);
					}
					else if(s[j]==')')
					{
						if(S.empty())
						{
							break;
						}
						S.pop();
						if(S.empty())
						{
							temp=j-i+1;
							if(temp>max)
							{
								max=temp;
							}
						}
					}
				}
				temp=j;
				int top;
				while(!S.empty())
				{
					top=S.top();
					if(temp-top-1>max)
					{
						max=temp-top-1;
					}
					temp=top;
					S.pop();
				}
				i=j;
			}
		}
		return max;
	}
};

int main()
{
	int ans=Solution::longestValidParentheses("(()");
	cout<<ans<<endl;
	return 0;
}
