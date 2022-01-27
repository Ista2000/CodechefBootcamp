#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector< pair<int, pair<int, int> > > edges;
vector<int> id, sz;

// Returns the leader of u and also does path compression
int root(int u)
{
    if(id[u] == u) return u;
    return id[u] = root(id[u]);
}

// Merges u and v if they are in different components
bool merge(int u, int v)
{
    u = root(u);
    v = root(v);
    if(u == v) return false;
    if(sz[u] < sz[v]) swap(u, v);
    id[v] = u;
    sz[u] += sz[v];
    return true;
}

int main()
{
    int n, m;
    cin>>n>>m;

    edges.resize(m);
    id.resize(n+1);
    sz.resize(n+1, 1);

    for(int i = 1;i<=n;i++)
        id[i] = i;

    for(int i = 0;i<m;i++)
        cin>>edges[i].second.first>>edges[i].second.second>>edges[i].first;
    sort(edges.begin(), edges.end());
    
    int mst_sum = 0;
    for(int i = 0;i<m;i++)
        if(merge(edges[i].second.first, edges[i].second.second))
            mst_sum += edges[i].first;
    
    cout<<mst_sum<<endl;

    return 0;
}