#include <bits/stdc++.h>

#define mx 1000
#define mod 1000007
#define ll long long

using namespace std;

void precal(string pat, int lps[])
{
    int i = 0, j = 1;
    int l = pat.size();
    lps[i] = 0;

    while (j < l)
    {
        if (pat[i] == pat[j])
        {
            lps[j] = i + 1;
            i++, j++;
        }
        else
        {
            if (i == 0)
            {
                lps[j] = 0;
                j++;
            }
            else
            {
                i = lps[i - 1];
            }
        }
    }
}

void kmp(string text, string pat)
{
    int lt = text.size();
    int ls = pat.size();
    int lps[ls + 5];
    precal(pat, lps);

    int i = 0, j = 0;
    while (j < lt)
    {
        if (pat[i] == text[j])
        {
            i++, j++;
        }
        else
        {
            if (i == 0)
            {
                j++;
            }
            else
            {
                i = lps[i - 1];
            }
        }

        if (i == ls)
        {
            cout << "matched: " << j - ls << "\n";
            i = lps[j - 1];
        }
    }
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    kmp(txt, pat);
    return 0;
}
