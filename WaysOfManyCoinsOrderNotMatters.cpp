/**
 total=4 
 coin[]={1,2,3}
 **/
#include <bits/stdc++.h>

#define mx 1000
#define mod 1000007
#define ll long long

using namespace std;

void fun()
{
      int total = 4;
      int coin[] = {1, 2, 3};
      int cn = sizeof(coin) / sizeof(coin[0]);
      int dp[total + 5];

      memset(dp, 0, sizeof(dp));
      dp[0] = 1;

      for (int c = 0; c < cn; c++)
      {
            for (int taka = 1; taka <= total; taka++)
            {

                  if (taka >= coin[c])
                        dp[taka] += dp[taka - coin[c]];
            }
      }

      cout << dp[4] << "\n";
}

int main(int argc, char const *argv[])
{
      ios::sync_with_stdio(false);
      fun();
      return 0;
}