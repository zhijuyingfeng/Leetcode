#include <cmath>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>
using namespace std;



class Solution
{
    struct point
    {
        int x, y;
        point(const int&X, const int&Y) :x(X), y(Y) {}
        point() :x(-1), y(-1) {}
    };
    const int X[8] = { -1,-1,0,1,1,1,0,-1 };
    const int Y[8] = { 0,1,1,1,0,-1,-1,-1 };
public:
    bool inBorder(const int& x, const int&y, const int&n)
    {
        if (x >= 0 && x<n&&y >= 0 && y<n)
            return true;
        return false;
    }
    bool inBorder2(const int&i,const int&j,const int&k,const int&n)
    {
        if(!inBorder(i,j,n))
            return false;
        if(k<n&&k>=i&&k<=i+j)
            return true;
        return false;
    }
    int cherryPickup(vector<vector<int>>& grid)
    {
        int n = grid.size();
        bool **visited = new bool*[n];
        bool blocked = 0;
        for (int i = 0; i<n; i++)
        {
            visited[i] = new bool[n];
            memset(visited[i], 0, sizeof(bool)*n);
        }
        vector<int>bottom, right,left;
        for (int i = 0; i<n; i++)
        {
            if (grid[n - 1][i]<0)
                bottom.push_back(i);
            if (grid[i][n - 1]<0)
                right.push_back(i);
            if(grid[i][0]<0)
                left.push_back(i);
        }
        int bs = bottom.size(), rs = right.size(),ls=left.size();
        point temp;
        for (int i = 0; i<bs; i++)
        {
            if (visited[n - 1][bottom[i]])
                continue;
            queue<point>Q;
            Q.push(point(n - 1, bottom[i]));
            while (!Q.empty())
            {
                temp = Q.front();
                Q.pop();
                visited[temp.x][temp.y] = true;
                if (temp.x == 0 || n - 1 == temp.y)
                {
                    blocked = true;
                    break;
                }
                for (int j = 0; j<8; j++)
                {
                    int x = temp.x + X[j];
                    int y = temp.y + Y[j];
                    if (inBorder(x, y, n) && !visited[x][y] && grid[x][y]<0)
                    {
                        Q.push(point(temp.x + X[j], temp.y + Y[j]));
                    }
                }
            }
            if (blocked)
                break;
        }
        if (!blocked)
        {
            for (int i = 0; i<rs; i++)
            {
                if (visited[right[i]][n - 1])
                    continue;
                queue<point>Q;
                Q.push(point(right[i], n - 1));
                while (!Q.empty())
                {
                    temp = Q.front();
                    Q.pop();
                    visited[temp.x][temp.y] = true;
                    if (temp.x == n - 1 || temp.y == 0)
                    {
                        blocked = true;
                        break;
                    }
                    for (int j = 0; j<8; j++)
                    {
                        int x = temp.x + X[j];
                        int y = temp.y + Y[j];
                        if (inBorder(x, y, n) && !visited[x][y] && grid[x][y]<0)
                        {
                            Q.push(point(temp.x + X[j], temp.y + Y[j]));
                        }
                    }
                }
                if (blocked)
                    break;
            }
        }
        if(!blocked)
        {
            for(int i=0;i<ls;i++)
            {
                if(visited[left[i]][0])
                    continue;
                queue<point>Q;
                Q.push(point(left[i],0));
                while(!Q.empty())
                {
                    temp=Q.front();
                    Q.pop();
                    visited[temp.x][temp.y] = true;
                    if(temp.x==0||temp.y==n-1)
                    {
                        blocked=true;
                        break;
                    }
                    for(int j=0;j<8;j++)
                    {
                        int x = temp.x + X[j];
                        int y = temp.y + Y[j];
                        if (inBorder(x, y, n) && !visited[x][y] && grid[x][y]<0)
                        {
                            Q.push(point(temp.x + X[j], temp.y + Y[j]));
                        }
                    }
                }
                if (blocked)
                    break;
            }
        }
        if (blocked)
        {
            for (int i = 0; i<n; i++)
            {
                delete[]visited[i];
            }
            delete[]visited;
            return 0;
        }
        int ***dp=new int**[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=new int*[n];
            for(int j=0;j<n;j++)
            {
                dp[i][j]=new int[n];
                memset(dp[i][j],0,sizeof(int)*n);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]<0)
                {
                    memset(dp[i][j],0xff,sizeof(int)*n);
                    continue;
                }
                else
                {
                    int Max;
                    for(int k=i;k<=i+j&&k<n;k++)
                    {
                        if(grid[k][i+j-k]<0)
                            continue;
                        Max=-1;
                        if(inBorder2(i,j-1,k,n))
                            Max=max(Max,dp[i][j-1][k]);
                        if(inBorder2(i,j-1,k-1,n))
                            Max=max(Max,dp[i][j-1][k-1]);
                        if(inBorder2(i-1,j,k,n))
                            Max=max(dp[i-1][j][k],Max);
                        if(inBorder2(i-1,j,k-1,n))
                            Max=max(Max,dp[i-1][j][k-1]);
                        if(Max<0)
                        {
//                            dp[i][j][k]=-1;
                            continue;
                        }
                        dp[i][j][k]=Max+grid[i][j];
                        if(i!=k)
                            dp[i][j][k]+=grid[k][i+j-k];
                        printf("dp[%d][%d][%d]:%d\n",i,j,k,dp[i][j][k]);
                    }
                }
            }
        }
        int ans=dp[n-1][n-1][n-1];
        for(int i=0;i<n;i++)
        {
            delete []visited[i];
            for(int j=0;j<n;j++)
            {
                delete []dp[i][j];
            }
            delete []dp[i];
        }
        delete[]visited;
        delete[]dp;
        return ans;
    }
};

int main()
{
    Solution S;
    vector<vector<int>> vec={{1,-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-1,1,1},{1,1,1,1,1,1,1,1,-1,-1,1,1,1,1,1,1,1,1,1,-1},{1,-1,-1,-1,1,1,1,1,1,1,1,1,1,1,-1,1,1,1,1,1},{-1,1,1,1,0,1,1,1,1,1,1,1,-1,1,1,-1,1,-1,1,1},{1,1,1,1,1,-1,-1,1,1,1,-1,1,-1,1,-1,1,1,1,-1,-1},{1,1,1,1,1,-1,1,1,1,1,1,1,1,-1,1,1,1,1,-1,1},{1,1,1,1,-1,1,1,1,1,1,1,-1,1,1,1,1,-1,1,1,1},{1,1,1,1,-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-1},{-1,1,1,1,1,1,1,-1,1,-1,1,-1,1,1,1,1,1,1,1,-1},{1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1},{-1,1,-1,1,-1,-1,-1,1,1,1,1,-1,-1,1,-1,1,0,1,1,1},{-1,1,1,1,1,1,1,1,1,1,1,-1,1,1,1,-1,1,1,1,1},{1,1,1,1,1,1,1,1,1,1,1,1,-1,1,1,-1,1,1,-1,-1},{1,1,1,1,1,1,1,1,-1,1,1,1,1,1,1,1,1,1,1,1},{0,1,1,-1,1,1,1,1,-1,1,-1,1,1,1,-1,-1,-1,1,1,1},{1,-1,1,1,1,-1,1,1,1,-1,1,-1,1,1,1,1,1,1,-1,1},{1,1,1,-1,1,1,1,-1,1,1,1,1,1,-1,1,1,1,1,1,1},{1,1,1,1,-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},{1,1,-1,1,1,-1,1,1,1,1,-1,1,1,1,1,1,1,-1,0,1},{-1,1,1,1,1,1,1,1,1,1,1,1,1,1,-1,1,1,1,-1,1}}
;
//    for(int i=0;i<vec.size();i++)
//    {
//        for(int j=0;j<vec[i].size();j++)
//        {
//            cout<<vec[i][j]<<',';
//        }
//        cout<<endl;
//    }
    cout<<S.cherryPickup(vec)<<endl;
    return 0;
}
