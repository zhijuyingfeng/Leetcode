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
public:
	void post(const TreeNode* root,vector<int>&vec)
	{
		if(!root)
			return;
		if(root->left)
			post(root->left,vec);
		if(root->right)
			post(root->right,vec);
		if(root)
			vec.push_back(root->val);
	}
	vector<int> postorderTraversal(TreeNode* root)
	{
		vector<int>ans;
		post(root,ans);
		return ans;
	}
};

int main()
{

	return 0;
}
