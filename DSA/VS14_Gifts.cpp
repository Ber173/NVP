#include <bits/stdc++.h>
#define ll long long 
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;

const int MAXN = 1e6 + 6;
const int base = 173;
const ll INF = 1e18;

void online()
{
    fastio
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
}

int n, k, res = INT_MIN, a[MAXN];

void input()
{
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}

void solve()
{
    input();

    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <=  i - 1; j++)
        {
            if(a[i] + a[j] > k) break;
            res = max(res, a[i] + a[j]);
        }
        if(res == k) break;
    }
    cout << res;
}

int main()
{
    fastio
    solve();
}