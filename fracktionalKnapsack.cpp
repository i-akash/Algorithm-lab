#include <bits/stdc++.h>

#define mx 1000
#define mod 1000007
#define ll long long

using namespace std;

struct item
{
      int value, weight;

      bool operator<(item a)
      {
            return (((double)a.value / a.weight) < ((double)value / weight));
      }
};

int fraction()
{
      int n, w, ans = 0;
      cin >> n >> w;
      item ar[n + 5];

      for (int i = 0; i < n; i++)
      {
            int a, b;
            cin >> a >> b;
            ar[i].value = a;
            ar[i].weight = b;
      }

      sort(ar, ar + n);

      for (int i = 0; i < n; i++)
      {
            if (w >= ar[i].weight)
                  ans += ar[i].value, w -= ar[i].weight;
            else
                  ans += w * ar[i].value / ar[i].weight, w = 0;
      }

      return ans;
}

int main(int argc, char const *argv[])
{
      ios::sync_with_stdio(false);
      cout << fraction() << endl;
      return 0;
}