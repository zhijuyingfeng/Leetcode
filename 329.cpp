#include <iostream>
#include <stack>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

class Solution
{
    int m,n;
public:
    bool minElement(const vector<vector<int>>& matrix,const int&i,const int&j)
    {
        if(i>0&&matrix[i-1][j]<matrix[i][j])
            return false;
        if(j>0&&matrix[i][j-1]<matrix[i][j])
            return false;
        if(i+1<matrix.size()&&matrix[i+1][j]<matrix[i][j])
            return false;
        if(j+1<matrix[0].size()&&matrix[i][j+1]<matrix[i][j])
            return false;
        return true;
    }

    bool inBorder(const int &i,const int &j)
    {
        if(i<0||i>=m)
            return false;
        if(j<0||j>=n)
            return false;
        return true;
    }

    void DFS(const vector<vector<int>>& matrix,int& ans,int i,int j,int cnt,int** dp)
    {
        ans=max(ans,cnt);
        int X[4]={i-1,i,i+1,i};
        int Y[4]={j,j-1,j,j+1};
        bool searched=0;
        for(int k=0;k<4;k++)
        {
            if(inBorder(X[k],Y[k])&&matrix[X[k]][Y[k]]>matrix[i][j])
            {
                if(!dp[X[k]][Y[k]])
                    DFS(matrix,ans,X[k],Y[k],cnt+1,dp);
                dp[i][j]=max(dp[i][j],dp[X[k]][Y[k]]+1);
                searched=true;
            }
        }
        if(!searched)
            dp[i][j]=1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix)
    {
        m=matrix.size();
        if(!m)return 0;
        n=matrix[0].size();
        int ans=0;
        int **dp=new int*[m];
        for(int i=0;i<m;i++)
        {
            dp[i]=new int[n];
            memset(dp[i],0,sizeof(int)*n);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(minElement(matrix,i,j))
                {
                    int cnt=1,back=1;
                    DFS(matrix,ans,i,j,cnt,dp);
                    ans=max(ans,dp[i][j]);
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            delete []dp[i];
        }
        delete []dp;
        return ans;
    }
};

int main()
{
    Solution S;
//    vector<vector<int>>matrix={{1,4,7,9},{0,3,8,5},{3,6,0,6},{1,4,5,6}};
//    vector<vector<int>>matrix={{9,9,4},{6,6,8},{2,1,1}};
//    vector<vector<int>>matrix={{3,4,5},{3,2,6},{2,2,1}};
    vector<vector<int>>matrix={{7,8,9},{9,7,6},{7,2,3}};
//    vector<vector<int>>matrix={{0,1,2,3},{7,6,5,4},{8,9,10,11},{15,14,13,12}};
//    vector<vector<int>>matrix={{7,6,1,1},{2,7,6,0},{1,3,5,1},{6,6,3,2}};
    cout<<S.longestIncreasingPath(matrix)<<endl;
    return 0;
}
