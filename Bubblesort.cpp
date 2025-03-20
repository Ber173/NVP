#include <bits/stdc++.h>
#define ll long long 
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;

int n;
vector <ll> ar;

void input()
{
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        ar.push_back(x);
    }
}

void print(){
    for(int i = 0; i < n; i++) cout << ar[i] << ' ';
    cout << '\n';
}

void BubbleSort(vector<ll> &a)
{
    for(int i = 0; i < n; i++)
    {
        bool check = 0;
        for(int j = 0; j < n - 1; j++)
        {
            if(a[j] > a[j + 1]) {
                check = 1;
                swap(a[j], a[j + 1]);
                print();
            }
        }
        if(!check) break;
    }
}

void solve(){
    input();
    BubbleSort(ar);
}

int main(){
    solve();
    return 0;
}