#include <iostream>
using namespace std;

// 1. Định nghĩa Struct phân số
struct PhanSo
{
	int tuso;
	int mauso;
};

// 2. Hàm nhập phân số
void Nhap(PhanSo &x)
{
	cout << "Nhap tu so: ";
	cin >> x.tuso;
	cout << "Nhap mau so: ";
	cin >> x.mauso;
}

// 3. Hàm xuất phân số
void Xuat(PhanSo x)
{
	cout << x.tuso << "/" << x.mauso << endl;
}

// 4. Tìm ước chung lớn nhất
int findGCD(int a, int b) {
	// Ước của 12 = {1,2,3,4,6,12}
	// Ước của 18 = {1,2,3,6,9,18}
	// Ước chung lớn nhất 12, 18 GCD(12, 18) = 6

	// Cách tìm: a = 12, b = 18
	// Step 1: du = 12%18 = 12, gan a = b = 18, b = du = 12
	// Step 2: du = 18%12 = 6, gan a = b = 12, b = du = 6
	// Step 3: du = 12%6 = 0, gan a = b = 6, b = du = 0
	// Dung thuat toan b = 0

	while (b != 0) {
		int du = a % b;
		a = b;
		b = du;
	}

	return abs(a);
}

// 5. Rút gọn phân số
void rutGonPhanSo(PhanSo &ps) {
	int gcd = findGCD(ps.tuso, ps.mauso);

	ps.tuso /= gcd;
	ps.mauso /= gcd;

	if (ps.mauso < 0) {
		ps.tuso = -ps.tuso;
		ps.mauso = -ps.mauso;
	}
}

// 6. Tổng hiệu tích thương hai phân số
PhanSo tongPhanSo(PhanSo ps1, PhanSo ps2)
{
	PhanSo PhanSoTong;
	PhanSoTong.tuso = ps1.tuso * ps2.mauso + ps2.tuso * ps1.mauso;
	PhanSoTong.mauso = ps1.mauso * ps2.mauso;

	rutGonPhanSo(PhanSoTong);
	return PhanSoTong;
}
PhanSo hieuPhanSo(PhanSo ps1, PhanSo ps2){
    PhanSo PhanSoHieu;
    PhanSoHieu.tuso=ps1.tuso*ps2.mauso-ps2.tuso*ps1.mauso;
    PhanSoHieu.mauso=ps1.mauso*ps2.mauso;
    return PhanSoHieu;
}
PhanSo tichPhanSo(PhanSo ps1, PhanSo ps2){
    PhanSo PhanSoTich;
    PhanSoTich.tuso=ps1.tuso*ps2.tuso;
    PhanSoTich.mauso=ps1.mauso*ps2.mauso;
    return PhanSoTich;
}PhanSo thuongPhanSo(PhanSo ps1, PhanSo ps2){
    PhanSo PhanSoThuong;
    PhanSoThuong.tuso=ps1.tuso*ps2.mauso;
    PhanSoThuong.mauso=ps1.mauso*ps2.tuso;
    return PhanSoThuong;
}

// Nhập 2 phân số và xuất hai phân số
int main() {
	PhanSo ps1, ps2;
	cout << "Nhap phan so thu 1" << endl;
	Nhap(ps1);
	cout << "Nhap phan so thu 2" << endl;
	Nhap(ps2);
	cout << "Hai phan so vua nhap la: " << endl;
	Xuat(ps1);
	Xuat(ps2);

	cout << "Rut gon phan so 1" << endl;
	rutGonPhanSo(ps1);
	Xuat(ps1);

	cout << "Rut gon phan so 2" << endl;
	rutGonPhanSo(ps2);
	Xuat(ps2);

	// Tổng hiệu tích thương hai phân số
	cout << "Tong hai phan so: ";
	PhanSo PhanSoTong = tongPhanSo(ps1, ps2);
	Xuat(PhanSoTong);
	cout << "Hieu hai phan so: ";
	PhanSo PhanSoHieu = hieuPhanSo(ps1, ps2);
	Xuat(PhanSoHieu);
	cout << "Tich hai phan so: ";
	PhanSo PhanSoTich = tichPhanSo(ps1, ps2);
	Xuat(PhanSoTich);
	cout << "Thuong hai phan so: ";
	PhanSo PhanSoThuong = thuongPhanSo(ps1, ps2);
	Xuat(PhanSoThuong)  ;

	return 0;
}
