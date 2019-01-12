/**
 QWERTYTREWQWERT
 **/

#include <bits/stdc++.h>

#define mx 1000
#define mod 1000007
#define ll long long

using namespace std;

int main(int argc, char const *argv[])
{
      ios::sync_with_stdio(false);
      string given = "QWERTYTREWQWERT";
      int ls = given.size();

      int pal[ls + 5][ls + 5], ppart[ls + 5];
      memset(pal, 0, sizeof(pal));

      for (int l = 1; l <= ls; l++)
      {
            for (int i = 0; i + l - 1 < ls; i++)
            {
                  int j = i + l - 1;

                  if (l <= 2)
                        pal[i][j] = (given[i] == given[j]);
                  else
                        pal[i][j] = (given[i] == given[j] && pal[i + 1][j - 1]);
            }
      }

      for (int i = 0; i < ls; i++)
      {
            if (pal[0][i])
                  ppart[i] = 0;
            else
            {
                  int mini = INT_MAX;
                  for (int j = 0; j < i; j++)
                  {
                        if (pal[j + 1][i] && ppart[j] + 1 < mini)
                              mini = ppart[j] + 1;
                  }
                  ppart[i] = mini;
            }
      }
      cout << ppart[ls - 1] << "\n";

      return 0;
}