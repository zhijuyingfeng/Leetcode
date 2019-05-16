#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

class Solution {
public:
    void queen(int cur,const int&n,int& total,vector<int>*vis)
    {
        if(n==cur)
            total++;
        else
        {
            for(int i=0;i<n;i++)
            {
                if(!vis[0][i]&&!vis[1][i+cur]&&!vis[2][i-cur+n])
                {
                    vis[0][i]=vis[1][i+cur]=vis[2][i-cur+n]=1;
                    queen(cur+1,n,total,vis);
                    vis[0][i]=vis[1][i+cur]=vis[2][i-cur+n]=0;
                }
            }
        }
    }
    int totalNQueens(int n)
    {
        vector<int>vis[3];
        vis[0].resize(n<<1);
        vis[1].resize(n<<1);
        vis[2].resize(n<<1);
        int cur=0,total=0;
        queen(cur,n,total,vis);
        return total;
    }
};
int main()
{
    Solution S;
    cout<<S.totalNQueens(8)<<endl;
    return 0;
}
