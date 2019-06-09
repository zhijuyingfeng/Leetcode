#include <vector>
#include <cstdlib>
#include <iostream>
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
    string s;
    size_t len;
    TreeNode* insert(size_t& p,TreeNode* T,int last)
    {
        if(p>=len)
            return T;
        int cur=0;
        while(s[p]=='-')
        {
            p++;
            cur++;
        }
        int val=atoi(s.c_str()+p);
        if(cur>last)
        {
            T=new TreeNode(val);
            while(p<len&&s[p]!='-')
            {p++;}
            T->left=insert(p,T->left,cur);
            T->right=insert(p,T->right,cur);
            return T;
        }
        else
        {
            p-=static_cast<size_t>(cur);
            return nullptr;
        }
    }
public:
    TreeNode* recoverFromPreorder(string S)
    {
        s=S;
        len=S.size();
        TreeNode* ans=nullptr;
        size_t p=0;
        int last=-1;
        ans=insert(p,ans,last);
        return ans;
    }
};

void DesTroy(TreeNode* T)
{
    if(!T)
        return;
    if(T->left)
        DesTroy(T->left);
    if(T->right)
        DesTroy(T->right);
    delete T;
}

int main()
{
    Solution S;
    TreeNode* ans=S.recoverFromPreorder("1-2--3---4-5--6---7");
    DesTroy(ans);
    return 0;
}
