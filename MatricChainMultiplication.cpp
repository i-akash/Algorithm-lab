#include <bits/stdc++.h>

#define mx 1000
#define mod 1000007
#define ll long long

using namespace std;

void MCM(int p[], int n)
{
    int dp[n + 5][n + 5];
    memset(dp, 0, sizeof(dp));

    for (int l = 2; l < n; l++)
    {
        for (int i = 1; i + l - 1 < n; i++)
        {
            int j = i + l - 1;
            int mini = INT_MAX;
            for (int k = i; k < j; k++)
            {
                mini = min(dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j], mini);
            }
            dp[i][j] = mini;
        }
    }

    cout << dp[1][n - 1] << "\n";
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    MCM(arr, size);
    return 0;
}