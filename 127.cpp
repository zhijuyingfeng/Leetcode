#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Solution
{
public:
    static int getDiff(const string&a,const string&b)
    {
        int len=a.length();
        int ans=0;
        for(int i=0;i<len;++i)
        {
            if(a[i]!=b[i])
                ans++;
        }
        return ans;
    }
    static int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        int n=wordList.size();
        int begin=-1,end=-1;
        for(int i=0;i<n;++i)
        {
            if(beginWord.compare(wordList[i])==0)
            {
                begin=i;
            }
            if(wordList[i].compare(endWord)==0)
            {
                end=i;
            }
        }
        if(end<0)
            return 0;
        if(begin<0)
        {
            wordList.push_back(beginWord);
            begin=n;
            n++;
        }
        int *dp=new int[n];
        memset(dp,-1,sizeof(int)*n);
        queue<int>Q;
        Q.push(begin);
        dp[begin]=1;
        string temp;
        int index;
        while(!Q.empty())
        {
            index=Q.front();
            temp=wordList[index];
            Q.pop();
            if(0==temp.compare(endWord))
                return dp[index];
            for(int i=0;i<n;++i)
            {
                if(dp[i]>=0)
                    continue;
                if(1==getDiff(temp,wordList[i]))
                {
                    dp[i]=dp[index]+1;
                    Q.push(i);
                }
            }
        }
        return 0;
    }
};

int main()
{
    vector<string>wordList={"hot","dot","dog","lot","log","cog"};
    cout<<Solution::ladderLength("hit","cog",wordList)<<endl;
    return 0;
}
