#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector< vector< pair<int, int> > > G;
vector<int> vis, color, shortest_path;

// void dfs(int u)
// {
//     vis[u] = 1;
//     cout<<u<<endl;
//     for(int v: G[u])
//         if(!vis[v])
//             dfs(v);
// }

// void bfs(int r)
// {
//     queue<int> q;
//     q.push(r);
//     while(!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//         if(vis[u])
//             continue;
//         vis[u] = 1;
//         cout<<u<<endl;
//         for(int v: G[u])
//             if(!vis[v])
//                 q.push(v);
//     }
// }

// bool bipartite(int u = 1, int current_color = 0)
// {
//     color[u] = current_color;
//     for(int v: G[u])
//     {
//         if(color[v] == -1)
//         {
//             if(!bipartite(v, 1 - current_color))
//                 return false;
//         }
//         else if(color[v] == current_color)
//             return false;
//     }
//     return true;
// }

// def bipartite_check(u, current_color):
//     color[u] = current_color
//     for v in G[u]:
//         if color[v] == -1:
//             if not bipartite_check(v, 1 - current_color):
//                 return False
//         elif color[v] == current_color:
//             return False
//     return True

void dijkstra(int source)
{
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
    pq.push({0, source});
    while(!pq.empty())
    {
        int u = pq.top().second, current_distance = pq.top().first;
        pq.pop();
        if(shortest_path[u] != -1)
            continue;
        shortest_path[u] = current_distance;
        for(auto v: G[u])
            if(shortest_path[v.first] == -1)
                pq.push({current_distance + v.second, v.first});
    }
}

int main()
{
    int n, m, s, t;
    cin>>n>>m;

    // Adjacency List
    G.resize(n+1);
    vis.resize(n+1); 
    color.resize(n+1, -1);
    shortest_path.resize(n+1, -1);
    // vis[i] = 0 => i is not visited
    // vis[i] = 1 => i is visited

    // Input format
    // u v
    for(int i = 0;i<m;i++)
    {
        int u, v, w;
        cin>>u>>v>>w;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    // dfs(1);
    // bfs(1);

    // Counting number of connected components
    // int cnt = 0;
    // for(int i = 1;i<=n;i++)
    // {
    //     if(!vis[i])
    //     {
    //         cnt++;
    //         bfs(i);
    //     }
    // }
    // cout<<cnt<<endl;

    // Check if graph is bipartite in a connected graph
    // if(bipartite())
    //     cout<<"Graph is bipartite"<<endl;
    // else
    //     cout<<"Graph is not bipartite"<<endl;
    cin>>s>>t;

    dijkstra(s);
    cout<<shortest_path[t]<<endl;

    return 0;
}