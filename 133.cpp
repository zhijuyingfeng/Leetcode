#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class Node
{
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    static void DFS(Node* node,bool* visited,map<int,int>& M,vector<Node*>&nodes)
    {
        int n=node->neighbors.size();
        visited[M[node->val]]=1;
        int pos;
        for(int i=0;i<n;i++)
        {
            pos=M[node->neighbors[i]->val];
            if(!pos)
            {
                Node *add=new Node;
                add->val=node->neighbors[i]->val;
                //add->neighbors.push_back(node);
                nodes[M[node->val]]->neighbors.push_back(add);
                M[add->val]=nodes.size();
                nodes.push_back(add);
            }
            else
            {
                //nodes[pos]->neighbors.push_back(node);
                nodes[M[node->val]]->neighbors.push_back(nodes[pos]);
            }
            if(!visited[pos])
            {
                DFS(node->neighbors[i],visited,M,nodes);
            }
        }
    }

    static Node* cloneGraph(Node* node)
    {
        bool visited[101]={0};
        map<int,int> M;
        vector<Node*>nodes;
        nodes.push_back(NULL);
        nodes.push_back(new Node);
        nodes[1]->val=node->val;
        M[node->val]=1;
        DFS(node,visited,M,nodes);
        return nodes[1];
    }
};

int main()
{
    Node *one=new Node,*two=new Node,*three=new Node,*four=new Node;
    one->val=1;
    two->val=2;
    three->val=3;
    four->val=4;
    one->neighbors.push_back(two);
    one->neighbors.push_back(four);
    two->neighbors.push_back(one);
    two->neighbors.push_back(three);
    three->neighbors.push_back(two);
    three->neighbors.push_back(four);
    four->neighbors.push_back(one);
    four->neighbors.push_back(three);
    Node* ans=Solution::cloneGraph(one);
    return 0;
}
