#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>
#include <vector>
#include <stack>
#include <set>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
	int MAX;
public:
	Solution()
	{
		MAX=0xf0000000;
	}
	int maxPathSum(TreeNode* root)
	{
		recur(root);
		return this->MAX;
	}
	int recur(TreeNode* root)
	{
		int L=0,R=0;
		if(root->val>MAX)
		{
			MAX=root->val;
		}
		if(root->left)
		{
			L=recur(root->left);
			if(L>MAX)
			{
				MAX=L;
			}
		}
		if(root->right)
		{
			R=recur(root->right);
			if(R>MAX)
			{
				MAX=R;
			}
		}
		int ans,temp;
//		if(root->val>=0)
		{
			ans=root->val;
			temp=ans;
			int bigger=max(L,R);
			if(bigger>0)
			{
				ans+=bigger;
			}
			if(L>0)
			{
				temp+=L;
			}
			if(R>0)
			{
				temp+=R;
			}
			if(temp>MAX)
			{
				MAX=temp;
			}
			if(ans>MAX)
			{
				MAX=ans;
			}
		}
		if(ans<0)
		{
			ans=0xf0000000;
		}
		return ans;
	}
};

int main()
{
	TreeNode *T=new TreeNode(8);
	TreeNode *node=new TreeNode(9);
	T->left=node;
	node=new TreeNode(-6);
	T->right=node;
	node=new TreeNode(5);
	T->right->left=node;
	node=new TreeNode(9);
	T->right->right=node;
	Solution S;
	cout<<S.maxPathSum(T)<<endl;
	delete T;
	return 0;
}
