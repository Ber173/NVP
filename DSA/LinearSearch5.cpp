#include <bits/stdc++.h>
#define ll long long 
#define fasito ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;

const int maxn = 1e6 + 6;
const int mod = 1e9 + 7;
const int base = 173;

int n, a[maxn];

void input()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int sum1 = a[n] - a[1];
    int sum2 = 0;
    if(n > 3) sum2 = a[n - 1] - a[2];
    cout << sum1 + sum2 << '\n';
}

void solve()
{
    int T;
    cin >> T;
    while(T--)
    {
        input();
    }
}

int main()
{
    fasito
    solve();
}