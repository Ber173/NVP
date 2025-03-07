#include <bits/stdc++.h>
#define ll long long 
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;

const int maxn = 1e6 + 6;
const int mod = 1e9 + 7;
const int base = 173;
const ll INF = 1e18;

int n, m;
ll res = INF;

int get(int x1, int y1, int x2, int y2, int a[][])
{
    return (a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1]);
}



void input()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
        }
    }
}

void solve()
{
    input();
    int a[n + 10][m + 10];
    for(int i = 1; i + 2 <= n; i++)
    {
        for(int j = 1; j + 2 <= m; j++)
        {
            res = min(res, (ll)get(i, j, i + 2, j + 2, a));
        }
    }
    cout << res;
}

int main()
{
    fastio
    solve();
}