#include <bits/stdc++.h>

#define mx 100
#define mod 1000007
#define ll long long

using namespace std;

int quPos[mx], col[mx], diag1[mx], diag2[mx], n;

void queen(int r)
{
    if (r == n + 1)
    {
        cout << "row::col :\n";
        for (int i = 1; i <= n; i++)
            cout << i << " " << quPos[i] << "\n";
        return;
    }

    for (int c = 1; c <= n; c++)
    {
        if (col[c] || diag1[c + r] || diag2[n + c - r])
            continue;

        quPos[r] = c;
        col[c] = diag1[c + r] = diag2[n + c - r] = 1;
        queen(r + 1);

        col[c] = diag1[c + r] = diag2[n + c - r] = 0;
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    memset(col, 0, sizeof(col));
    memset(diag1, 0, sizeof(diag1));
    memset(diag2, 0, sizeof(diag2));
    n = 4;
    queen(1);

    return 0;
}