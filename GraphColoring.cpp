#include <bits/stdc++.h>

#define mx 100
#define mod 1000007
#define ll long long

using namespace std;

vector<int> ad[mx];
int node;

void coloring()
{
    int color[node + 5], avail[node + 5];
    memset(color, -1, sizeof(color));

    for (int u = 0; u < node; u++)
    {
        memset(avail, 0, sizeof(avail));
        for (auto v : ad[u])
            if (color[v] != -1)
                avail[color[v]] = 1;
        for (int c = 0; c < node; c++)
            if (!avail[c])
            {
                color[u] = c;
                break;
            }
    }
    for (int u = 0; u < node; u++)
    {
        cout << "node : " << u << " color: " << color[u] << "\n";
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    node = 5;
    int ed;
    cin >> ed;

    while (ed--)
    {
        int u, v;
        cin >> u >> v;
        ad[u].push_back(v);
        ad[v].push_back(u);
    }
    coloring();
    return 0;
}
