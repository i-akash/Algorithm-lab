#include <bits/stdc++.h>

#define mx 1000
#define mod 1000007
#define ll long long

using namespace std;
const int node = 6;

bool bfs(int graph[][node], int s, int t, int parent[])
{
    int vis[node + 5];
    memset(vis, 0, sizeof(vis));
    queue<int> q;
    vis[s] = 1;
    q.push(s);
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 0; v < node; v++)
        {
            if (!vis[v] && graph[u][v])
            {
                parent[v] = u;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return (vis[t] == 1);
}

int Ford(int graph[][node])
{

    int parent[node + 5];
    int flow = 0;
    int s = 0, t = node - 1;
    while (bfs(graph, 0, 5, parent))
    {

        int pflow = INT_MAX;
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            pflow = min(pflow, graph[u][v]);
        }

        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            graph[u][v] -= pflow;
            graph[v][u] += pflow;
        }
        flow += pflow;
    }

    return flow;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int graph[node][node] = {{0, 16, 13, 0, 0, 0},
                             {0, 0, 10, 12, 0, 0},
                             {0, 4, 0, 0, 14, 0},
                             {0, 0, 9, 0, 0, 20},
                             {0, 0, 0, 7, 0, 4},
                             {0, 0, 0, 0, 0, 0}};
    cout << Ford(graph) << "\n";
    return 0;
}