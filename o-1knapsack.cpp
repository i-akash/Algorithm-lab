#include <bits/stdc++.h>

#define mx 1000
#define mod 1000007
#define ll long long

using namespace std;
int n, dp[mx][mx], weight[mx], value[mx];
int c = 0;

int rec(int i, int w)
{
      c++;
      if (i >= n)
            return 0;
      if (dp[i][w] != -1)
            return dp[i][w];
      int ans = 0;
      if (w >= weight[i])
            ans = max(ans, rec(i + 1, w - weight[i]) + value[i]);
      ans = max(ans, rec(i + 1, w));

      dp[i][w] = ans;
      return ans;
}

int main(int argc, char const *argv[])
{
      ios::sync_with_stdio(false);
      int w;
      cin >> n >> w;

      for (int i = 0; i < n; i++)
            cin >> value[i];
      for (int i = 0; i < n; i++)
            cin >> weight[i];

      memset(dp, -1, sizeof(dp));
      cout << rec(0, w) << " " << c << "\n";
      return 0;
}