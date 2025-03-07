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

string s;
int k;

void input()
{
    cin >> k;
    cin.ignore();
    getline(cin, s);
}

void solve()
{
    input();
    for(int i = 0; i <= int(s.size()) - 1; i++)
    {
        if('A' <= s[i] && s[i] <= 'Z') cout << char(((s[i] + k - 'A')% 26) + 'A');
        else cout << s[i];
    }
}

int main()
{
    solve();
}