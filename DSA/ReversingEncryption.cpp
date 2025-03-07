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

void input(){
    cin >> s;
}

void solve()
{
    input();
    int n = s.size();
    for(int i = 2; i <= n; i++)
    {
        if(!(n % i)) reverse(s.begin(), s.begin() + i);
    }
    cout << s;
}

int main()
{
    fastio
   // online();
    solve();
}