#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
using namespace std;

class Solution
{
    int n,total;
public:
    void queen(int cur,vector<int>*vis,vector<vector<string>>&ans,vector<string>& lines)
    {
        if(cur==n)
        {
            total++;
            ans.push_back(lines);
        }
        else
        {
            string line="";
            for(int i=0;i<n;i++)
            {
                if(!vis[0][i]&&!vis[1][cur+i]&&!vis[2][i-cur+n])
                {
                    line.push_back('Q');
                    vis[0][i]=vis[1][cur+i]=vis[2][i-cur+n]=1;
                    int len=line.length();
                    for(int j=len;j<n;j++)
                        line.push_back('.');
                    lines.push_back(line);
                    queen(cur+1,vis,ans,lines);
                    vis[0][i]=vis[1][cur+i]=vis[2][i-cur+n]=0;
                    lines.pop_back();
                    len=line.length();
                    for(int j=len;j>i;j--)
                        line.pop_back();
                    line.push_back('.');
                }
                else
                    line.push_back('.');
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        this->n=n;
        this->total=0;
        vector<int> vis[3];
        vis[0].resize(n<<1);
        vis[1].resize(n<<1);
        vis[2].resize(n<<1);
        int cur=0;
        vector<string> lines;
        vector<vector<string>>ans;
        queen(cur,vis,ans,lines);
        return ans;
    }
};

int main()
{
    Solution S;
    S.solveNQueens(8);
    return 0;
}
