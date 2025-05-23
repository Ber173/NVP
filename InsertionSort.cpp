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

void Insertsort(vector <ll> &a)
{
    for(int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = a[i];

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        printArray(a);
        }
        a[j + 1] = key;
        printArray(a);
    }    

    
}

void solve()
{
    input();
    Insertsort(ar);
}

int main()
{
    solve();
    return 0;
}