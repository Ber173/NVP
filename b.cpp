#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (int i = (a); i <= int(b); i++)
#define fd(i, a, b) for (int i = (a); i >= int(b); i--)
#define X first
#define Y second
#define INF 1e18
#define ed << '\n';
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;

const ll maxn = 1e6 + 6;
const ll mod = 1e9 + 7;

ll n, Q, a[maxn];

struct segment_tree
{
    vector<ll> lazy, st;
    ll n;

    segment_tree(ll _n = 0)
    {
        n = _n;
        lazy = vector<ll>(n, 0);
        st = vector<ll>(n, 0);
    }

    void down(int id)
    {
        ll k = lazy[id];

        lazy[id << 1] += k;
        lazy[id << 1 | 1] += k;

        st[id << 1] += k;
        st[id << 1 | 1] += k;

        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, ll vl)
    {
        if (r < u || l > v)
            return;
        if (u <= l && r <= v)
        {
            st[id] += vl;
            lazy[id] += vl;
            return;
        }
        int m = (l + r) >> 1;
        down(id);
        update(id << 1, l, m, u, v, vl);
        update(id << 1 | 1, m + 1, r, u, v, vl);

        st[id] = max(st[id << 1], st[id << 1 | 1]);
    }

    ll get(int id, int l, int r, int u, int v)
    {
        if (r < u || l > v)
            return -INF;
        if (u <= l && r <= v)
            return st[id];
        int m = (l + r) >> 1;
        down(id);
        return max(get(id << 1, l, m, u, v), get(id << 1 | 1, m + 1, r, u, v));
    }
};

segment_tree tree(400000);

void input()
{
    cin >> n;
    fu(i, 1, n) cin >> a[i], tree.update(1, 1, n, i, i, a[i]);
    ll x, y;
    cin >> Q;
}

void solve()
{
    input();

    while (Q--)
    {
        ll k, x, y, z;
        cin >> k >> x >> y;
        if (k == 1)
        {
            cin >> z;
            tree.update(1, 1, n, x, y, z);
        }
        else
            cout << tree.get(1, 1, n, x, y) ed
    }
}

int main()
{
    fastio
    solve();
}
