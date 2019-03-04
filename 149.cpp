#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point
{
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution
{
public:
	static bool comp(const Point&a,const Point&b)
	{
		if(a.x==b.x)
			return a.y<b.y;
		return a.x<b.x;
	}
	int maxPoints(vector<Point>& points)
	{
		int n=points.size();
		if(n<=2)
			return n;
		sort(points.begin(),points.end(),comp);
		int same=0,cnt=0;
		for(int i=0;i<n-1;i++)
		{
			if(points[i].x==points[i+1].x&&points[i].y==points[i+1].y)
			{
				cnt++;
				if(cnt>same)
					same=cnt;
			}
			else
			{
				cnt=0;
			}
		}
		if(same<n)
			same++;
		int dp[900][900]={0};
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				dp[i][j]=2;
				for(int k=0;k<n;k++)
				{
					if(k==i||k==j)
						continue;
					unsigned long long a=points[k].x-points[i].x;
					unsigned long long b=points[k].y-points[j].y;
					unsigned long long c=points[k].x-points[j].x;
					unsigned long long d=points[k].y-points[i].y;
					if(a==c&&b==d)
						continue;
					if(a*b==c*d)
						dp[i][j]++;
				}
			}
		}
		int max=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(dp[i][j]>max)
					max=dp[i][j];
			}
		}

		return max>same?max:same;
	}
};

int main()
{
	vector<Point> vec={{84,250},{0,0},{1,0},{0,-70},{0,-70},{1,-1},{21,10},{42,90},{-42,-230}};
	Solution S;
	int ans=S.maxPoints(vec);
	cout<<ans<<endl;
	return 0;
}
