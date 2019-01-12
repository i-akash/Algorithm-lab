/**txt[] =  "AABAACAADAABAABA"
        pat[] =  "AABA"**/

#include <bits/stdc++.h>

#define mx 1000
#define mod 1000007
#define ll long long

using namespace std;

#define distinct 300

void transition(string pat, int ttable[][distinct])
{
      int states = pat.size();
      int lps = 0;

      for (int i = 0; i < distinct; i++)
            ttable[0][i] = 0;
      ttable[0][pat[0]] = 1;

      for (int i = 1; i <= states; i++)
      {
            for (int j = 0; j < distinct; j++)
                  ttable[i][j] = ttable[lps][j];
            cout << lps << endl;
            if (i < states)
            {
                  ttable[i][pat[i]] = i + 1;
                  lps = ttable[lps][pat[i]];
            }
      }
}

void matching(string pat, string text)
{
      int lp = pat.size();
      int lt = text.size();
      int ttable[lp + 5][distinct];

      transition(pat, ttable);
      
      int state = 0;
      for (int i = 0; i < lt; i++)
      {
            state = ttable[state][text[i]];

            if (state == lp)
            {
                  cout << "Matched at " << i - lp + 1 << "\n";
            }
      }
}

int main(int argc, char const *argv[])
{
      ios::sync_with_stdio(false);
      string pat, text;
      cin >> pat >> text;

      matching(pat, text);
      return 0;
}
