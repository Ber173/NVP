#include <bits/stdc++.h>
#define ll long long
#define fu(i, a, b) for (ll i = int(a); i <= int(b); i++)
#define fd(i, a, b) for (ll i = int(a); i >= int(b); i--)
#define ed << '\n';
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);
#pragma GCC optimize("O2")
#define INF 1e18

using namespace std;

ll n, m, low[100100], cnt, num[100100], res;
vector<ll> a[10010];
stack<ll> st;

void input()
{
    cin >> n >> m;
    fu(i, 1, m)
    {
        ll x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
}

void tarjan(int u)
{
    st.push(u);
    low[u] = num[u] = ++cnt;
    fu(i, 0, a[u].size() - 1)
    {
        if (num[a[u][i]])
            low[u] = min(low[u], num[a[u][i]]);
        else
            tarjan(a[u][i]),
                low[u] = min(low[a[u][i]], low[u]);
    }

    if (num[u] == low[u])
    {
        res++;
        ll tmp;

        do
        {
            tmp = st.top();
            st.pop();
            num[tmp] = low[tmp] = INF;
        } while (tmp != u);
        cout ed
    }
}

int main()
{
    input();
    fu(i, 1, n) if (!num[i])
        tarjan(i);
    cout << res;
    return 0;
}
