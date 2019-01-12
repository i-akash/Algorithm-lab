/**
a[]={5,2,3,1,4,6}
b[]={1,2,3,4,5,6}
 **/
#include <bits/stdc++.h>

#define mx 1000
#define mod 1000007
#define ll long long

using namespace std;

int lis(int a[], int n)
{

      int least[n + 5], length = 0;
      least[0] = -10;

      for (int i = 0; i < n; i++)
      {
            int pos = lower_bound(least, least + length + 1, a[i]) - least;
            length = max(length, pos);
            least[pos] = a[i];
      }
      return length;
}

void lcs()
{
      int a[] = {1, 3, 2, 0};
      int b[] = {3, 2, 1, 0};
      int n = sizeof(a) / sizeof(a[0]);
      int posa[n + 5], posra[n + 5];

      for (int i = 0; i < n; i++)
      {
            posa[a[i]] = i;
      }

      for (int i = 0; i < n; i++)
      {
            posra[i] = posa[b[i]];
      }

      cout << lis(posra, n) << "\n";
}

int main(int argc, char const *argv[])
{
      ios::sync_with_stdio(false);
      lcs();
      return 0;
}