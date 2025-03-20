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

void merge(vector <ll>&a, int l, int mid, int r)
{
    int n1 = mid - l + 1;
    int m1 = r - mid;

    vector <int> L(n1), R(m1);

    for(int i = 0; i < n1; i++) L[i] = a[l + i];
    for(int i = 0; i < m1; i++) R[i] = a[mid + i + 1];
    
    int i = 0, j = 0, k = l;
    while(i < n1 && j < m1)
    {
       if(L[i] <= R[j]) a[k] = L[i++];
       else a[k] = R[j++];
       k++;
    }    
    while(i < n1) a[k] = L[i++], k++;
    while(j < m1) a[k] = R[j++], k++;

    for(i = 0; i < l; i++) cout << ar[i] << ' ';
    cout << "[ ";
    for(i = l; i <= r; i++) cout << ar[i] << ' ';
    cout << "] ";
    for(i = r + 1; i < n; i++) cout << ar[i] << ' ';
    cout << '\n';
}

void Mergesort(vector<ll>&a, int l, int r)
{
    if(l < r){
        int mid = l + (r - l) / 2;

        Mergesort(a, l, mid);
        Mergesort(a, mid + 1, r);

        merge(a, l, mid, r);
    }
}

void solve()
{
    input();
    Mergesort(ar, 0, n - 1);
}

int main()
{
    fastio
    solve();
    return 0;
}