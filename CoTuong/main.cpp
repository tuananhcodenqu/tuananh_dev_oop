#include <iostream>
#include <vector>
using namespace std;

class Chess {
protected:
    string mau;
    int x, y;
public:
    Chess(string mau, int x, int y) {
        this->mau = mau;
        this->x = x;
        this->y = y;
    }
    virtual ~Chess() {}  // Sửa lỗi destructor
    virtual void Move() = 0;
};

// Tướng
class Tuong : public Chess {
public:
    Tuong(string mau, int x, int y) : Chess(mau, x, y) {}  // Sửa lỗi constructor
    void Move() {
        cout << "Tuong di tung o mot, di ngang, doc va chi di trong pham vi cung.\n";
    }
};

// Sĩ
class Si : public Chess {
public:
    Si(string mau, int x, int y) : Chess(mau, x, y) {}  // Sửa lỗi constructor
    void Move() {
        cout << "Si di cheo 1 o, chi di trong pham vi cung.\n";
    }
};

// Tượng
class TuongJ : public Chess {
public:
    TuongJ(string mau, int x, int y) : Chess(mau, x, y) {}  // Sửa lỗi constructor
    void Move() {
        cout << "TuongJ di cheo 2 o va khong duoc qua song.\n";
    }
};

// Xe
class Xe : public Chess {
public:
    Xe(string mau, int x, int y) : Chess(mau, x, y) {}  // Sửa lỗi constructor
    void Move() {
        cout << "Xe di ngang di doc khong gioi han o mien la khong bi block.\n";
    }
};

// Mã
class Ma : public Chess {
public:
    Ma(string mau, int x, int y) : Chess(mau, x, y) {}  // Sửa lỗi constructor
    void Move() {
        cout << "Ma di ngang 2 o di doc 1 o (ngang 1 o doc 2 o), tuc la di theo chu L.\n";
    }
};

// Pháo
class Phao : public Chess {
public:
    Phao(string mau, int x, int y) : Chess(mau, x, y) {}  // Sửa lỗi constructor
    void Move() {
        cout << "Phao di ngang va doc giong Xe, neu Phao muon an 1 quan thi phai co 1 quan co o giua.\n";
    }
};

// Tốt
class Tot : public Chess {
public:
    Tot(string mau, int x, int y) : Chess(mau, x, y) {}  // Sửa lỗi constructor
    void Move() {
        cout << "Tot di thang 1 o, qua song co the di ngang.\n";
    }
};

int main() {
    string trang = "trang";
    string den = "den";
    cout << "Ban co 32 quan co, nhap lua chon tu 0-31 \n";
    Chess *a[32];

    // Tạo các quân cờ
    a[0] = new Tuong(trang, 1, 5);
    a[1] = new Tuong(den, 10, 5);
    a[2] = new Si(trang, 1, 4);
    a[3] = new Si(trang, 1, 6);
    a[4] = new Si(den, 10, 4);
    a[5] = new Si(den, 10, 6);
    a[6] = new TuongJ(trang, 1, 3);
    a[7] = new TuongJ(trang, 1, 7);
    a[8] = new TuongJ(den, 10, 3);
    a[9] = new TuongJ(den, 10, 7);
    a[10] = new Ma(trang, 1, 2);
    a[11] = new Ma(trang, 1, 8);
    a[12] = new Ma(den, 10, 2);
    a[13] = new Ma(den, 10, 8);
    a[14] = new Xe(trang, 1, 1);
    a[15] = new Xe(trang, 1, 9);
    a[16] = new Xe(den, 10, 1);
    a[17] = new Xe(den, 10, 9);
    a[18] = new Phao(trang, 3, 2);
    a[19] = new Phao(trang, 3, 8);
    a[20] = new Phao(den, 8, 2);
    a[21] = new Phao(den, 8, 8);
    a[22] = new Tot(trang, 4, 1);
    a[23] = new Tot(trang, 4, 3);
    a[24] = new Tot(trang, 4, 5);
    a[25] = new Tot(trang, 4, 7);
    a[26] = new Tot(trang, 4, 9);
    a[27] = new Tot(den, 7, 1);
    a[28] = new Tot(den, 7, 3);
    a[29] = new Tot(den, 7, 5);
    a[30] = new Tot(den, 7, 7);
    a[31] = new Tot(den, 7, 9);

    int choose;
    cin >> choose;
    a[choose]->Move();

    // Giải phóng bộ nhớ
    for (int i = 0; i < 32; i++) {
        delete a[i];
    }

    cout << "Ket thuc chuong trinh!";
    return 0;
}
