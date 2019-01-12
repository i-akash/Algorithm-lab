#include <bits/stdc++.h>

#define mx 1000
#define ll long long

using namespace std;

void lis(int a[], int parent[], int n)
{
      int least[n + 5], seq[n + 5], length = 0;
      least[0] = -10;
      seq[0] = -1;

      for (int i = 0; i < n; i++)
      {
            int pos = lower_bound(least, least + length + 1, a[i]) - least;
            if (pos > length)
                  length = pos;
            parent[i] = seq[pos - 1];
            least[pos] = a[i];
            seq[pos] = i;
      }
      cout << "lis : " << length << "\nSeq : \n";

      int index = seq[length];
      while (index != -1)
      {
            cout << a[index] << " ";
            index = parent[index];
      }
      cout << "\n";
}

int main(int argc, char const *argv[])
{
      ios::sync_with_stdio(false);

      int n;
      cin >> n;
      int ar[n + 5], parent[n + 5];
      for (int i = 0; i < n; i++)
            cin >> ar[i], parent[i] = -1;
      lis(ar, parent, n);
      return 0;
}
