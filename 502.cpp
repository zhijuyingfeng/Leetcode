#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution 
{
public:
	struct Node
	{
		bool used;
		int captial, profit;
		Node(const int&c, const int&p):captial(c),profit(p),used(0){}
		Node():captial(0),profit(0),used(0){}
	};
	static bool cmp(const Node&a, const Node&b)
	{
		if (a.captial == b.captial)
			return a.profit < b.profit;
		return a.captial < b.captial;
	}
	static int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) 
	{
		int n = Profits.size();
		if (k >= n)
		{
			for (int i = 0; i < n; i++)
				W += Profits[i];
			return W;
		}
		vector<Node>vec;
		vec.resize(n);
		for (int i = 0; i < n; i++)
		{
			vec[i].profit = Profits[i];
			vec[i].captial = Capital[i];
		}
		priority_queue<int, vector<int> >H;
		sort(vec.begin(), vec.end(), cmp);
		for (int i = 0; i < n&&k>0; )
		{
			while (i<n&&W >= vec[i].captial)
			{
				H.push(vec[i].profit);
				i++;
			}
			if (!H.empty())
			{
				W += H.top();
				H.pop();
				k--;
			}
			else
				break;
		}
		while (k > 0&&!H.empty())
		{
			W += H.top();
			H.pop();
			k--;
		}
		return W;
	}
};

int main()
{
	vector<int> Profits = { 1,2,3 }, Captial = { 1,1,2 };
	cout << Solution::findMaximizedCapital(1, 0, Profits, Captial) << endl;
    return 0;
}

