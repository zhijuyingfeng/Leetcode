#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	static vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
	{
		vector<Interval> ans;
		int n=intervals.size();
		Interval temp,left,right;
		for(int i=0;i<n;i++)
		{
			if(newInterval.start>=intervals[i].start&&newInterval.start<=intervals[i].end)
				left=intervals[i];
			if(newInterval.end>=intervals[i].start&&newInterval.end<=intervals[i].end)
				right=intervals[i];
		}
		if(left.start!=left.end)
			temp.start=left.start;
		else
			temp.start=newInterval.start;
		if(right.start!=right.end)
			temp.end=right.end;
		else
			temp.end=newInterval.end;
		bool used=0;
		int i=0;
		while(!used&&i<n)
		{
			if(intervals[i].start<temp.start)
			{
				if(temp.start>intervals[i].end)
					ans.push_back(intervals[i]);
				i++;
			}
			else
			{
				ans.push_back(temp);
				used=1;
			}
		}
		if(!used)
			ans.push_back(temp);
		while(i<n)
		{
			if(intervals[i].start>temp.end)
				ans.push_back(intervals[i]);
			i++;
		}
		return ans;
	}
};

int main()
{
	vector<Interval> vec={{1,3},{6,9}};
	vector<Interval> temp= Solution::insert(vec,Interval(2,5));

	return 0;
}
