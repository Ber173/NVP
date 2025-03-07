#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 6;

struct NhanVien
{
    int MANV;
    string FullName;
    string PhongBan;
    int Salary, Reward;
    int ThucLuong() const
    {
        return Salary + Reward;
    }
};

void online()
{
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
}

bool cmp(NhanVien &A, NhanVien &B)
{
    if (A.PhongBan == B.PhongBan)
        return A.MANV > B.MANV;
    return A.PhongBan < B.PhongBan;
}

int n;
vector<NhanVien> List;

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        NhanVien a;
        cin >> a.MANV;

        cin.ignore();
        getline(cin, a.FullName);
        getline(cin, a.PhongBan);

        cin >> a.Salary >> a.Reward;
        List.push_back(a);
    }
}

void output()
{
    for (int i = 0; i <= int(List.size()) - 1; i++)
    {
        cout << List[i].MANV << '\n';
        cout << List[i].FullName << '\n';
        cout << List[i].PhongBan << '\n';
        cout << List[i].ThucLuong() << '\n';
        cout << '\n';
    }
}

void SumSalary(const vector<NhanVien> &a)
{
    int sum = 0;
    for (int i = 0; i <= int(a.size()) - 1; i++)
    {
        sum += a[i].ThucLuong();
    }
    cout << "Tong thuc lanh thang cua tat ca nhan vien trong cong ty la " << sum << '\n';
}

void NhanVienCoLuongCoBanThap(const vector<NhanVien> &ds)
{
    int minn = INT_MAX;
    for (int i = 0; i <= int(ds.size()) - 1; i++)
    {
        minn = min(minn, ds[i].Salary);
    }

    cout << "Nhung nhan vien co luong co ban thap nhat la " << '\n';
    for (int i = 0; i <= int(ds.size()) - 1; i++)
    {
        if (ds[i].Salary == minn)
        {
            cout << ds[i].MANV << " - " << ds[i].FullName << " - " << ds[i].Salary << '\n';
        }
    }
}

void Filter(const vector<NhanVien> &ds)
{
    int cnt = 0;
    for (int i = 0; i <= (ds.size()) - 1; i++)
    {
        if (ds[i].Reward >= 1200000)
            cnt++;
    }
    cout << "Dem so luong nhan vien co muc thuong >= 1200000 : " << cnt << '\n';
}

void Filter2(vector<NhanVien> &ds)
{
    sort(ds.begin(), ds.end(), cmp);

    for (int i = 0; i <= int(ds.size()) - 1; i++)
    {
        cout << ds[i].MANV << " - " << ds[i].FullName << " - " << ds[i].PhongBan << " - " << ds[i].Salary << '\n';
    }
}

void Menu()
{
    cout << '\n';
    cout << "Nhap tu 0 den 4 de lua chon." << '\n';
    cout << "0. Ket thuc chuong trinh." << '\n';
    cout << "1. Tinh tong thuc lanh thang cua tat ca nhan vien trong cong ty." << '\n';
    cout << "2. In danh sach nhung nhan vien co muc luong co ban thap nhat." << '\n';
    cout << "3. Dem so luong nhan vien co muc thuong >= 1200000." << '\n';
    cout << "4. In danh sach cac nhan vien tang dan theo phong ban, neu phong ban trung nhau thi giam dan theo ma nhan vien." << '\n';
}

int k;

void solve()
{
    input();

    while (true)
    {
        Menu();
        cin >> k;
        if (!k)
        {
            cout << "THE END";
            break;
        }
        else if (k == 1)
            SumSalary(List);
        else if (k == 2)
            NhanVienCoLuongCoBanThap(List);
        else if (k == 3)
            Filter(List);
        else
            Filter2(List);
    }
}

int main()
{
    solve();
}
