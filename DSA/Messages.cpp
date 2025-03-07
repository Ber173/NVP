#include <bits/stdc++.h>
#define ll long long 
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;

const int MAXN = 1e6 + 6;
const ll base = 173;
const ll INF = 1e18;
const ll mod = 1e9 + 7;

string a, b;
int res, k;

void input()
{
    cin >> a >> b;
    k = min(a.size(), b.size());
}

void solve()
{
    input();

    for(int i = k; i >= 1; i--)
    {
        if(a.substr(a.size() - i, i) == b.substr(0, i))
        {
            res = i;
            break;
        }
    }

    string s = a + b.substr(res);
    cout << s.size() << '\n';
    cout << s;
}

int main()
{
    fastio
    solve();
    return 0;
}