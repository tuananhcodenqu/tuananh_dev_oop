#include <iostream>

using namespace std;
class MATRAN3x3{
    int num[3][3];
    public:
        MATRAN3x3(){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    num[i][j] = 0;
                }
            }
        }
        friend istream& operator>>(istream& is, MATRAN3x3& mt){
            for(int i =0;i<3;i++){
                for(int j=0;j<3;j++){
                    cout << "Nhap phan tu [" << i << "][" << j << "]: ";
                    is >> mt.num[i][j];
                }
            }
            return is;
        }
        friend ostream& operator<<(ostream& os, MATRAN3x3& mt){
            for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                os << mt.num[i][j] << "\t";
            }
            os << endl;
        }
        return os;
        }
        MATRAN3x3 operator+(const MATRAN3x3 &other) const{
            MATRAN3x3 res;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    res.num[i][j] = num[i][j] + other.num[i][j];
                }
            }
        return res;
        }
        MATRAN3x3 operator-(const MATRAN3x3 &other) const{
            MATRAN3x3 res;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    res.num[i][j] = num[i][j] - other.num[i][j];
                }
            }
        return res;
        }
        MATRAN3x3 operator*(const MATRAN3x3 &other) const{
            MATRAN3x3 res;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    res.num[i][j] = 0;
                    for (int k = 0; k < 3; k++) {
                        res.num[i][j] += num[i][k] * other.num[k][j];
                        }
                }
        }
        return res;
        }
        MATRAN3x3 operator*(int number) const {
        MATRAN3x3 res;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                res.num[i][j] = num[i][j] * number;
            }
        }
        return res;
    }
} ;

int main()
{
   MATRAN3x3 mt1, mt2;

    cout << "Nhap ma tran 1:\n";
    cin >> mt1;

    cout << "Nhap ma tran 2:\n";
    cin >> mt2;

    cout << "\nMa tran 1:\n" << mt1;
    cout << "\nMa tran 2:\n" << mt2;

    MATRAN3x3 tong = mt1 + mt2;
    cout << "\nTong hai ma tran:\n" << tong;

    MATRAN3x3 hieu = mt1 - mt2;
    cout << "\nHieu hai ma tran:\n" << hieu;

    MATRAN3x3 tich = mt1 * mt2;
    cout << "\nTich hai ma tran:\n" << tich;
    int number;
    cout << "Nhap 1 so nguyen: "; cin >> number;
    MATRAN3x3 nhanSoNguyen = mt1 * number;
    cout << "\nMa tran 1 nhan voi " << number << ":\n" << nhanSoNguyen;

    return 0;
}
