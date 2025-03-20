#include <bits/stdc++.h>
#define ll long long 
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;

int n;
vector <ll> ar;

void input()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ar.push_back(x);
    }
}

void printArray(vector<ll>a) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Selectionsort(vector <ll> &a)
{
    for(int i = 0; i < n; i++)
    {
       int minn = i;
       for(int j = i + 1; j < n; j++){
            if(a[j] < a[minn]) minn = j;
       }
       if(i != minn){
           swap(a[i], a[minn]);
         printArray(a);
       }
    }    
}

void solve()
{
    input();
    Selectionsort(ar);
}

int main()
{
    solve();
    return 0;
}