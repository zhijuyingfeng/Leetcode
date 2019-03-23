#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <cstring>
using namespace std;

class Solution
{
public:
	static int power(const int&x,const int&n)
	{
		if(!n)
			return 1;
		else if(1==n)
			return x;
		int temp=power(x,n>>1);
		if(n&1)
			return temp*temp*x;
		else
			return temp*temp;
	}
	static int countDigitOne(int n)
	{
		if(n<=0)
			return 0;
		int cnt=0,temp=n;
//		for(int i=1;i<=n;i++)
//		{
//			temp=i;
//			while(temp>0)
//			{
//				if(temp%10==1)
//				{
//					cnt++;
//				}
//				temp/=10;
//			}
//		}
		vector<int>vec;
		while(temp>0)
		{
			vec.push_back(temp%10);
			temp/=10;
		}
		temp=n;
		int digits=vec.size(),cur,back;
		while(digits>1)
		{
			cur=power(10,digits-1);
			back=vec.back();
			cur*=back;
			cur-=1;
			cnt+=(digits-1)*power(10,digits-2)*back;
			if(back>1)
			{
				cnt+=power(10,digits-1);
			}
			else if(1==back)
			{
				cnt+=temp-cur;
			}
			vec.pop_back();
			digits--;
			temp=0;
			for(int i=0;i<digits;i++)
			{
				temp+=vec[i]*power(10,i);
			}
		}
		if(vec.back()>=1)
			cnt+=1;
		return cnt;
	}
};
int main()
{
	cout<<Solution::countDigitOne(1)<<endl;
	return 0;
}
