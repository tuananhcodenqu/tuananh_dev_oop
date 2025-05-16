#include <iostream>
#include <algorithm>
using namespace std;

class KimLoai {
protected:
    string name;
    double KhoiLuongMol;
    double KhoiLuongReal;
    string CongThucOxit;
    int heso1, heso2, heso3;
public:
    KimLoai(string name, double KhoiLuongMol, string CongThucOxit, int a, int b, int c)
        : name(name), KhoiLuongMol(KhoiLuongMol), CongThucOxit(CongThucOxit), heso1(a), heso2(b), heso3(c) {}

    void Nhap() {
        cout << "Nhap khoi luong thuc te cua " << name << " (gam): ";
        cin >> KhoiLuongReal;
    }

    double MolCal() const {
        return KhoiLuongReal/KhoiLuongMol;
    }

    virtual double tinhKhoiLuongOxit(double soMolO2) const = 0;
    virtual double tinhSoMolCanThiet(double soMolO2) const = 0;

    string getName() const { return name; }
    string getCongThucOxit() const { return CongThucOxit; }
    double getKhoiLuongThucTe() const { return KhoiLuongReal; }

    virtual ~KimLoai() {}
};

class Sat: public KimLoai {
public:
    Sat() : KimLoai("Sat (Fe)", 55.85, "Fe2O3", 4, 3, 2) {}

    double tinhKhoiLuongOxit(double soMolO2) const override {
        double soMolFe = MolCal();
        double soMolFeCt = (heso1 * 1.0 / heso2) * soMolO2;
        double molPhanUng = min(soMolFe, soMolFeCt);
        double soMolOxit = (heso3*1.0/heso1) * molPhanUng;
        double M_Oxit = 2*55.85 + 3*16; // Fe2O3
        return soMolOxit * M_Oxit;
    }

    double tinhSoMolCanThiet(double soMolO2) const override {
        return (heso1 * 1.0 / heso2) * soMolO2;
    }
};

class Nhom: public KimLoai {
public:
    Nhom() : KimLoai("Nhom (Al)", 26.98, "Al2O3", 4, 3, 2) {}

    double tinhKhoiLuongOxit(double soMolO2) const override {
        double soMolAl = MolCal();
        double soMolAlCt = (heso1 * 1.0 / heso2) * soMolO2;
        double molPhanUng = min(soMolAl, soMolAlCt);
        double soMolOxit = (heso3*1.0/heso1) * molPhanUng;
        double M_Oxit = 2*26.98 + 3*16; // Al2O3
        return soMolOxit * M_Oxit;
    }

    double tinhSoMolCanThiet(double soMolO2) const override {
        return (heso1 * 1.0 / heso2) * soMolO2;
    }
};

class Dong: public KimLoai {
public:
    Dong() : KimLoai("Dong (Cu)", 63.55, "CuO", 2, 1, 2) {}

    double tinhKhoiLuongOxit(double soMolO2) const override {
        double soMolCu = MolCal();
        double soMolCuCt = (heso1 * 1.0 / heso2) * soMolO2;
        double molPhanUng = min(soMolCu, soMolCuCt);
        double soMolOxit = (heso3*1.0/heso1) * molPhanUng;
        double M_Oxit = 63.55 + 16; // CuO
        return soMolOxit * M_Oxit;
    }

    double tinhSoMolCanThiet(double soMolO2) const override {
        return (heso1 * 1.0 / heso2) * soMolO2;
    }
};

int main() {
    KimLoai* ds[3] = {new Sat(), new Nhom(), new Dong()};

    cout << "NHAP THONG TIN KIM LOAI:\n";
    for (int i = 0; i < 3; i++) {
        ds[i]->Nhap();
    }

    double soMolO2 = 8.96 / 22.4;
    KimLoai* KlMaxOxit = ds[0];
    double maxKlOxit = KlMaxOxit->tinhKhoiLuongOxit(soMolO2);

    for(int i = 0; i < 3; i++) {
        double khoiLuongOxit = ds[i]->tinhKhoiLuongOxit(soMolO2);
        cout << ds[i]->getName() << " tao ra " << khoiLuongOxit
             << " gam " << ds[i]->getCongThucOxit() << endl;

        if(khoiLuongOxit > maxKlOxit) {
            maxKlOxit = khoiLuongOxit;
            KlMaxOxit = ds[i];
        }
    }

    cout << "\nPhan ung tao oxit co khoi luong lon nhat la: " << KlMaxOxit->getName()
         << " voi " << maxKlOxit << " gam " << KlMaxOxit->getCongThucOxit() << endl;

    int count = 0;
    for(int i = 0; i < 3; i++) {
        if(ds[i]->MolCal() < ds[i]->tinhSoMolCanThiet(soMolO2)) count++;
    }

    cout << "\nSo kim loai co so mol thuc te nho hon so mol can thiet: " << count << endl;

    for (int i = 0; i < 3; i++) {
        delete ds[i];
    }

    return 0;
}
