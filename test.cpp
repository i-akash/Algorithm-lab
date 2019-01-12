#include <bits/stdc++.h>

#define mx 4;
#define mod 1000007
#define ll long long

using namespace std;
vector<int> ad[10];
int n;

void col()
{
    int result[n + 5];
    int used[n + 5];

    memset(result, -1, sizeof(result));

    for (int u = 0; u < n; u++)
    {
        memset(used, 0, sizeof(used));
        for (auto v : ad[u])
        {
            if (result[v] != -1)
                used[result[v]] = 1;
        }

        for (int c = 0; c < n; c++)
        {
            if (used[c] == 0)
            {
                result[u] = c;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << result[i] << endl;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    n = 5;
    int ed = 6;

    while (ed--)
    {
        int u, v;
        cin >> u >> v;

        ad[u].push_back(v);
        ad[v].push_back(u);
    }
    col();
    return 0;
}