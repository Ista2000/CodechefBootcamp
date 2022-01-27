#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector< vector<int> > G;
vector<int> lvl;
int anc[100005][20];

void dfs(int u, int p = 0, int l = 0)
{   
    lvl[u] = l;
    anc[u][0] = p;
    for(int i: G[u])
        if(i != p)
            dfs(i, u, l+1);
}
int xth_ancestor(int u, int x)
{
    for(int i = 0;i<20;i++)
        if(x&(1<<i))
            u = anc[u][i];
    return u;
}

int lca(int u, int v)
{
    if(lvl[u] > lvl[v])
        swap(u, v);
    if(lvl[u] != lvl[v])
        v = xth_ancestor(v, lvl[v] - lvl[u]);
    if(u == v)
        return u;
    for(int i = 19;i>=0;i--)
        if(anc[u][i] != anc[v][i])
            u = anc[u][i], v = anc[v][i];
    return anc[u][0];
}

int main()
{
    int n, q, r;
    cin>>n>>q>>r;

    G.resize(n+1);
    lvl.resize(n+1);
    
    for(int i = 0;i<n-1;i++)
    {
        int u, v;
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(r);
    
    // Calculate anc
    for(int j = 1;j<20;j++)
        for(int i = 1;i<=n;i++)
            anc[i][j] = anc[anc[i][j-1]][j-1];

    while(q--)
    {
        int u, v;
        cin>>u>>v;
        cout<<lca(u, v)<<endl;
    }

    return 0;
}