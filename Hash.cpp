#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for(int i = (a); i <= int(b); i++)
#define fd(i, a, b) for(int i = (a); i >= int(b); i--)
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;

const ll maxn = 1e6 + 6;
const ll mod = 1e9 + 7;
const ll base = 173;

ll hashA[maxn], Pow[maxn];
string a, b;
ll n, m, hashB;

void input()
{
    cin >> a >> b;
    n = a.size();
    m = b.size();
    a = ' ' + a;
    b = ' ' + b;

}

ll GetHash(int i, int j)
{
    return (hashA[j] - hashA[i - 1] * Pow[j - i + 1] + mod * mod) % mod;
}

void solve()
{
    input();

    Pow[0] = 1;
    fu(i, 1, n)
    {
        Pow[i] = (Pow[i - 1] * base) % mod;
        hashA[i] = (hashA[i - 1] * base + a[i] - 'a' + 1) % mod;
    }

    fu(i, 1, m) hashB = (hashB * base + b[i] - 'a' + 1) % mod;

    for(int i = 1; i + m - 1 <= n; i++)
    {
        if(GetHash(i, i + m - 1) == hashB) cout << i << ' ';
    }
}

int main()
{
    fastio
    solve();
}
