#include <bits/stdc++.h>
using namespace std;

struct PhanSo
{
    int tu, mau;

    PhanSo rutgon()
    {
        bool check = 0;
        if ((tu < 0 && mau < 0) || (tu > 0 && mau < 0))
        {
            tu *= -1;
            mau *= -1;
        }

        if (tu < 0 && mau > 0)
        {
            tu *= -1;
            check = 1;
        }

        int k = __gcd(tu, mau);
        tu /= k;
        mau /= k;

        if (check)
            tu *= -1;
    }
};

int M[13];

PhanSo operator+(PhanSo a, PhanSo b)
{
    a.rutgon();
    b.rutgon();
    PhanSo c = {a.tu * b.mau + b.tu * a.mau, a.mau * b.mau};
    c.rutgon();
    return c;
}

PhanSo operator-(PhanSo a, PhanSo b)
{
    a.rutgon();
    b.rutgon();
    PhanSo c = {a.tu * b.mau - b.tu * a.mau, a.mau * b.mau};
    c.rutgon();
    return c;
}

PhanSo operator*(PhanSo a, PhanSo b)
{
    a.rutgon();
    b.rutgon();
    PhanSo c = {a.tu * b.tu, a.mau * b.mau};
    c.rutgon();
    return c;
}

PhanSo operator/(PhanSo a, PhanSo b)
{
    a.rutgon();
    b.rutgon();
    swap(b.tu, b.mau);
    PhanSo c = {a.tu * b.tu, a.mau * b.mau};
    c.rutgon();
    return c;
}

PhanSo FindMax(PhanSo a, PhanSo b)
{
    PhanSo c = a - b;
    if (c.tu < 0)
        return b;
    return a;
}

void solve1()
{
    PhanSo a;
    cout << "Nhap tu so va mau so cua Phan so : ";
    cin >> a.tu >> a.mau;
    a.rutgon();
    cout << "Ket qua cua phan so da rut gon la : " << a.tu << '/' << a.mau;
}

void solve2()
{
    PhanSo a, b;
    cout << "Nhap tu so va mau so cua phan so thu nhat : ";
    cin >> a.tu >> a.mau;
    cout << "Nhap tu so va mau so cua phan so thu hai : ";
    cin >> b.tu >> b.mau;
    PhanSo c = FindMax(a, b);
    cout << "Phan so lon nhat la : " << c.tu << '/' << c.mau;
}

void solve3()
{
    PhanSo a, b;
    cout << "Nhap phan so thu nhat : ";
    cin >> a.tu >> a.mau;
    cout << "Nhap phan so thu hai : ";
    cin >> b.tu >> b.mau;
    PhanSo c1, c2, c3, c4;
    c1 = a + b;
    c2 = a - b;
    c3 = a * b;
    c4 = a / b;
    cout << "Tong cua hai phan so la " << c1.tu << '/' << c1.mau << '\n';
    cout << "Hieu cua hai phan so la " << c2.tu << '/' << c2.mau << '\n';
    cout << "Tich cua hai phan so la " << c3.tu << '/' << c3.mau << '\n';
    cout << "Thuong cua hai phan so la " << c4.tu << '/' << c4.mau << '\n';
}

void solve4()
{
    int DD, MM, YY;
    cout << "Nhap ngay thang nam : ";
    cin >> DD >> MM >> YY;
    if (!(YY % 4))
        M[2] = 29;
    else
        M[2] = 28;

    cout << "Ngay thang nam ke tiep la : ";
    if (DD + 1 <= M[MM])
        cout << DD + 1 << ' ' << MM << ' ' << YY << '\n';
    else
    {
        if (MM == 12)
            cout << "1 1 " << YY + 1 << '\n';
        else
        {
            cout << "1 " << MM + 1 << ' ' << YY << '\n';
        }
    }
}

void Menu()
{
    cout << "MENU" << '\n';
    cout << "0. Ket thuc chuong trinh" << '\n';
    cout << "1. Rut gon phan so." << '\n';
    cout << "2. Tim phan so lon nhat." << '\n';
    cout << "3. Tim Tong, Hieu, Tich va Thuong." << '\n';
    cout << "4. Tim ngay ke tiep." << '\n';
    cout << "Nhap tu 0 -> 4 de lua chon : ";
}

void solve()
{
    int k;
    while (true)
    {
        cout << '\n';
        cout << '\n';
        Menu();
        cin >> k;
        if (!k)
        {
            cout << "THE END";
            break;
        }
        else if (k == 1)
            solve1();
        else if (k == 2)
            solve2();
        else if (k == 3)
            solve3();
        else
            solve4();
    }
}

int main()
{
    M[1] = M[3] = M[5] = M[7] = M[8] = M[10] = M[12] = 31;
    M[4] = M[6] = M[9] = M[11] = 30;
    solve();
}