#include <bits/stdc++.h>

#define mx 1000
#define mod 1000007
#define ll long long

using namespace std;
void egcd1(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return;
    }
    int x1, y1;
    egcd1(b % a, a, &x1, &y1);

    *x = y1 - (b / a) * x1;
    *y = x1;
}

int CRT(int rem[], int m[], int n)
{
    int prod = 1;
    int ppi[n + 5];

    for (int i = 0; i < n; i++)
        prod *= m[i];
    for (int i = 0; i < n; i++)
        ppi[i] = prod / m[i];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int mmi, y;
        egcd1(ppi[i], m[i], &mmi, &y);
        mmi = (mmi + m[i]) % m[i];

        ans += (rem[i] * ppi[i] * (mmi));
        ans %= prod;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    int rem[] = {2, 3, 1};
    int m[] = {3, 4, 5};
    cout << CRT(rem, m, 3) << endl;
    return 0;
}