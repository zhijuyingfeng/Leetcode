#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    static void traversal(TreeNode* root,vector<int>& vec)
    {
        if(!root)
            return;
        if(root)
            vec.push_back(root->val);
        if(root->left)
            traversal(root->left,vec);
        if(root->right)
            traversal(root->right,vec);
    }
    static void traversal(TreeNode* root,vector<int>& vec,int &i)
    {
        if(!root)
            return;
        if(root->left)
            traversal(root->left,vec,i);
        root->val=vec[i];
        i++;
        if(root->right)
            traversal(root->right,vec,i);
    }
    static void recoverTree(TreeNode* root)
    {
        vector<int>vec;
        traversal(root,vec);
        sort(vec.begin(),vec.end());
        int i=0;
        traversal(root,vec,i);
    }
};

int main()
{
    TreeNode *T=new TreeNode(1);
    TreeNode *temp=new TreeNode(3);
    TreeNode *temp2=new TreeNode(2);
    temp->right=temp2;
    T->left=temp;
    Solution::recoverTree(T);
    delete T,temp,temp2;
    return 0;
}
