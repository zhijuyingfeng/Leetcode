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
	struct Node
	{
		int s,t;
		//Node(int s,int t):s(s),t(t){}
	};

	class MinCmp
	{
	public:
		bool operator()(const Node&a,const Node&b)
		{
			return a.s>b.s;
		}
	};

	static string minWindow(string s, string t)
	{
		int s_len=s.length(),t_len=t.length();
		if(t_len>s_len)
		{
			return "";
		}
		sort(t.begin(),t.end());

//		vector<int> *vec=new vector<int>[t_len];
//		int *pos=new int[t_len];
//		int *size=new int[t_len];
//		memset(size,0,sizeof(int)*t_len);
//		memset(pos,0,sizeof(int)*t_len);

		vector<int>vec[3];
		int pos[3]={0};
		int size[3]={0};

		vector<int>CharSet[128];
		for(int i=0;i<s_len;i++)
		{
			CharSet[s[i]].push_back(i);
		}

		for(int i=0;i<t_len;i++)
		{
			vec[i]=CharSet[t[i]];
		}

		for(int i=0;i<t_len;i++)
		{
			int j=i;
			while(j+1<t_len&&t[j]==t[j+1])
			{
				j++;
			}
			int cnt=j-i+1;
			if(cnt==1)
				continue;
			vector<int>temp=vec[i];
			int n=temp.size();
			for(int k=0;k<cnt;k++)
			{
				vec[i+k].clear();
			}
			for(int k=0;k<n;k++)
			{
				vec[i+k%cnt].push_back(temp[k]);
			}
			i=j;
		}
		bool ok=1;
		for(int i=0;i<t_len;i++)
		{
			size[i]=vec[i].size();
			if(size[i]<=0)
			{
				ok=0;
				break;
			}
		}
		string ans;
		if(!ok)
		{
			ans="";
		}
		else
		{
//			int min=0,max=0,start=0,end=s_len-1;
//			while(pos[min]<size[min])
//			{
//				for(int i=0;i<t_len;i++)
//				{
//					if(vec[i][pos[i]]<vec[min][pos[min]])
//					{
//						min=i;
//					}
//					if(vec[i][pos[i]]>vec[max][pos[max]])
//					{
//						max=i;
//					}
//				}
//				if(vec[max][pos[max]]-vec[min][pos[min]]<end-start)
//				{
//					start=vec[min][pos[min]];
//					end=vec[max][pos[max]];
//				}
//				pos[min]++;
//			}
//			ans=s.substr(start,end-start+1);
			priority_queue<Node,vector<Node>,MinCmp>MinHeap;
			int max=0,min=0,start=0,end=s_len-1;
			Node MinNode;
			for(int i=0;i<t_len;i++)
			{
				Node temp;
				temp.s=vec[i][pos[i]];
				temp.t=i;
				MinHeap.push(temp);
				if(vec[max][pos[max]]<vec[i][pos[i]])
				{
					max=i;
				}
			}
			while(1)
			{
				MinNode=MinHeap.top();
				MinHeap.pop();
				min=MinNode.t;
				if(vec[max][pos[max]]-vec[min][pos[min]]<end-start)
				{
					start=vec[min][pos[min]];
					end=vec[max][pos[max]];
				}
				pos[min]++;
				if(pos[min]>=size[min])
				{
					break;
				}
				Node temp;
				temp.t=min;
				temp.s=vec[min][pos[min]];
				MinHeap.push(temp);
				if(vec[min][pos[min]]>vec[max][pos[max]])
				{
					max=min;
				}
			}
			ans=s.substr(start,end-start+1);
		}
//		delete[]size;
//		delete[]pos;
//		delete[]vec;
		return ans;
	}
};

int main()
{
	//string S="ADOBECODEBANC",T="ABC";
	string S="ADOBECODEBANC",T="ABC";
	string t=Solution::minWindow(S,T);
	cout<<t<<endl;
	return 0;
}
