#include <bits/stdc++.h>

#define mx 1000
#define mod 1000007
#define ll long long

using namespace std;
int la, lb, lcs[mx][mx];
string a, b;

void lcsf()
{

      for (int i = 0; i <= la; i++)
      {
            for (int j = 0; j <= lb; j++)
            {
                  if (i == 0 || j == 0)
                        lcs[i][j] = 0;
                  else if (a[i - 1] == b[j - 1])
                        lcs[i][j] = lcs[i - 1][j - 1] + 1;
                  else
                        lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
      }

      cout << lcs[la][lb] << "\n";
}

string seq = "";

void printlcs(int indexA, int indexB)
{
      if (!indexA && !indexB)
            return;

      if (indexA > 0 && lcs[indexA][indexB] == lcs[indexA - 1][indexB])
            printlcs(indexA - 1, indexB);
      else if (indexB > 0 && lcs[indexA][indexB] == lcs[indexA][indexB - 1])
            printlcs(indexA, indexB - 1);
      else if (indexA > 0 && indexB > 0 && lcs[indexA][indexB] == lcs[indexA - 1][indexB - 1] + 1)
      {
            printlcs(indexA - 1, indexB - 1);
            seq += a[indexA - 1];
      }
}

int main(int argc, char const *argv[])
{
      ios::sync_with_stdio(false);
      cin >> a >> b;
      la = a.size();
      lb = b.size();
      lcsf();
      printlcs(la, lb);
      cout << seq << "\n";
      return 0;
}