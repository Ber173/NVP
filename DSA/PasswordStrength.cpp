#include <bits/stdc++.h>
#define ll long long 
#define fastio ios_base::sync_with_stdio(0), cin.tie(0);

using namespace std;

const int MAXN = 1e6 + 6;

void online()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
}

string s;

void input()
{
    cin >> s;
}

const int BaseScore = 40;
const int Bonus_Excess = 3;
const int Bonus_Upper = 4;
const int Bonus_Numbers = 5;
const int Bonus_Symbols = 5;

int Bonus_Combo, Bonus_FlatLower, Bonus_FlatNumber;
int Number_Execess, Number_Symbols, Number_Upper, Number_Lower, Number_Numbers;

int check()
{
    int Number_Execess = s.size();
    if(Number_Execess < 8) return INT_MIN;
    
    for(int i = 0; i <= int(s.size()) - 1; i++)
    {
        if(s[i] == '!') Number_Symbols++;
        else if(s[i] == '@') Number_Symbols++;
        else if(s[i] == '#') Number_Symbols++;
        else if(s[i] == '$') Number_Symbols++;
        else if(s[i] == '%') Number_Symbols++;
        else if(s[i] == '^') Number_Symbols++;
        else if(s[i] == '&') Number_Symbols++;
        else if(s[i] == '*') Number_Symbols++;
        else if(s[i] == '?') Number_Symbols++;
        else if(s[i] == '_') Number_Symbols++;
        else if(s[i] == '~') Number_Symbols++;
        else if('0' <= s[i] && s[i] <= '9') Number_Numbers++;
        else if('A' <= s[i] && s[i] <= 'Z') Number_Upper++;
        else if('a' <= s[i] && s[i] <= 'z') Number_Lower++;
        else if(s[i] == '.') return INT_MIN;
        else if(s[i] == '\\') return INT_MIN;
        else if(s[i] == '/') return INT_MIN;
        else if(s[i] == ' ') return INT_MIN;
        else if(s[i] == ',') return INT_MIN;
    }

    if(Number_Upper && Number_Symbols && Number_Numbers) Bonus_Combo = 25;
    else if(Number_Upper && Number_Symbols && !Number_Numbers) Bonus_Combo = 15;
    else if(Number_Upper && !Number_Symbols && Number_Numbers) Bonus_Combo = 15;
    else if(!Number_Upper && Number_Symbols && Number_Numbers) Bonus_Combo = 15;

    if(Number_Lower == Number_Execess) Bonus_FlatLower = -15;

    if(Number_Numbers == Number_Execess)  Bonus_FlatNumber = -35;

    Number_Execess -= 8;
    int score = BaseScore + Number_Execess*Bonus_Excess + Number_Upper*Bonus_Upper + Number_Numbers*Bonus_Numbers + Number_Symbols*Bonus_Symbols + Bonus_Combo + Bonus_FlatLower + Bonus_FlatNumber;
    return score;
}

void res(int x)
{
    if(x == INT_MIN) cout << "KhongHopLe";
    else if(x < 50) cout << "Yeu";
    else if(50 <= x && x < 75) cout << "Vua";
    else if(75 <= x && x < 100) cout << "Manh";
    else cout << "RatManh";
}

void solve()
{
    input();
    res(check());
}

int main()
{
    fastio
    solve();
}