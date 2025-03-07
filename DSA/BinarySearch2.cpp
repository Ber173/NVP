#include <bits/stdc++.h>
#define ll long long
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);
using namespace std;

const int MAXN = 1e6 + 6;
const int base = 173;

string x;
int n, cnt, res;
vector <string> s(MAXN);

void online()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);   
}

void input()
{
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> s[i];
    cin >> x;
}

void solve()
{
    input();

    int l = 1, r = n;    
    while(l <= r)
    {
        cnt++;
        int mid = (l + r) >> 1;
        if(s[mid] < x) l = mid + 1;
        else if(s[mid] == x) {
            res = mid;
            break;
        }
        else r = mid - 1;
    }

    if(s[res] == x) {
        cout << res - 1 << '\n' << cnt;
    }
    else cout << -1;
}

int main()
{
    //online();
    fastio
    solve();
}