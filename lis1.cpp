/**
10
1 9 8 10 2 3 4 6 5 7
 **/

#include <bits/stdc++.h>

#define mx 1000
#define mod 1000007
#define ll long long

using namespace std;

struct ut
{
      int ans, index;
      ut(int value)
      {
            ans = index = value;
      }
};

ut lis(int ar[], int parent[], int n)
{
      int dp[n + 5];
      ut ans(0);

      for (int i = 0; i < n; i++)
      {
            dp[i] = 1;
            for (int j = 0; j < i; j++)
            {
                  if (ar[j] < ar[i] && dp[j] + 1 > dp[i])
                        dp[i] = dp[j] + 1, parent[i] = j;
                  if (ans.ans < dp[i])
                  {
                        ans.ans = dp[i];
                        ans.index = i;
                  }
            }
      }
      return ans;
}

int main()
{
      ios::sync_with_stdio(false);
      int n;
      cin >> n;
      int ar[n + 5], parent[n + 5];
      for (int i = 0; i < n; i++)
            cin >> ar[i], parent[i] = -1;
      ut ans = lis(ar, parent, n);
      cout << "lis: " << ans.ans << "\nlast index: " << ans.index << "\nSeq: \n";
      int seq = ans.index;
      while (seq != -1)
      {
            cout << ar[seq] << " ";
            seq = parent[seq];
      }
      cout << "\n";
      return 0;
}