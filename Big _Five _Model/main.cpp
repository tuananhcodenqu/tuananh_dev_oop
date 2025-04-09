#include <bits/stdc++.h>
using namespace std;
class TAMLY{
    private:
        int O, C, E, A, N; // Điểm số cho 5 yếu tố tính cách
    public:
        TAMLY(){
            O = C = E = A = N = 0;
        }
        void Nhap(){
            cout << "Nhap diem (0-100) cho 5 yeu to: " << endl;
            cout << "1. San sang trai nghiem (O): "; cin >> O;
            cout << "2. Tu chu tan tam (C): "; cin >> C;
            cout << "3. Huong ngoai (E): "; cin >> E;
            cout << "4. Hoa dong de chiu (A): "; cin >> A;
            cout << "5. Bat on cam xuc (N): "; cin >> N;
        }
        void MoTa(){
            cout << "San sang trai nghiem (O = " << O << ") : ";
            if(O>=70)
                cout << "Nguoi nay thich nhung y tuong moi, thich hieu biet nhieu linh vuc nhung dong thoi cung thich tu do, khong thich bi rang buoc...\n";
            else if(O<=30)
                cout << "Nguoi nay thuong kha bao thu, kho tiep nhan nhung y tuong moi, la. Ho thich su on dinh quen thuoc va thuc te.\n";
            else
                cout << "Khong xac dinh ro.\n";
            cout << "Tu chu tan tam (C = " << C << ") : ";
            if(C>=70)
                cout << "Nguoi co diem co o yeu to nay thuong la nguoi cham chi, co kha nang chiu ap luc tot. Ho thuong la nguoi gan bo, trung thanh voi to chuc.\n";
            else if(C<=30)
                cout << "Nguoi co diem thap o yeu to nay thuong de bo cuoc, kha nang chiu ap luc, tuan thu ky luat to chuc kem.\n";
            else
                cout << "Khong xac dinh ro.\n";
            cout << "Huong ngoai (E = " << E << ") : ";
            if(E>=70)
                cout << "Nguoi nay thuong la nguoi nhiet tinh, nang dong, giao tiep to, thich the hien ban than.\n";
            else if(E<=30)
                cout << "nguoi nay thuong ngai giao tiep, khong thich su noi bat, thich duoc lam viec doc lap\n";
            else
                cout << "Khong xac dinh ro.\n";
            cout << "Hoa dong de chiu (A = " << A << ") : ";
            if(A>=70)
                cout << "Nguoi nay thong than thien, coi mo, dong cam voi moi nguoi nhung nhieu khi 'thieu chinh kien'.\n";
            else if(A<=30)
                cout << "Nguoi nay thuong dat loi ich cua ban than len tren, it dong cam, chia se voi dong nghiep, co tinh canh tranh cao\n";
            else
                cout << "Khong xac dinh ro.\n";
            cout << "Bat on cam xuc (N = " << N << ") : ";
            if(N>=70)
                cout << "Nguoi nay thuong co cam xuc tieu cuc nhu: lo lang, buc boi, tu ti, yeu duoi va kha nang chiu ap luc kem.\n";
            else if(N<=30)
                cout << "Nguoi nay thuong kiem soat duoc cam xuc, ung pho voi cang thang tot, it bi ben ngoai anh huong den tam trang cua ban than.\n";
            else
                cout << "Khong xac dinh ro.\n";

        }
        bool CoNguyCoCao(){
            return (E <= 30 && N >= 70);
        }
        void kiemTraNguyCo(){
        if (CoNguyCoCao())
            cout << "-> NGUY CO CAO can duoc to chuc/tuyen dung luu y.\n";
        else
            cout << "-> Khong nam trong nhom nguy co cao.\n";
    }
};
class DANHSACH{
    private:
        int soluong;
        TAMLY *DS;
    public:
        DANHSACH(){
            soluong = 0; DS = nullptr;
        }
        void NhapDanhSach(){
            cout << "Nhap so luong nguoi can danh gia: ";
            cin >> soluong;
            DS= new TAMLY[soluong];
            for(int i=0;i<soluong;i++){
                cout << "\n=== Thong tin cua nguoi thu " << i+1 << " ===\n";
                DS[i].Nhap();
            }
        }
        void Xuat(){
            for(int i=0;i<soluong;i++){
                cout << "\n=== Thong tin cua nguoi thu " << i+1 << " ===\n";
                DS[i].MoTa();
            }
        }
        void KiemTra(){
            cout << "\n===== DANH SACH NGUY CO CAO =====\n";
            for (int i = 0; i < soluong; i++) {
            cout << "\nNguoi thu " << i + 1 << ": ";
            DS[i].kiemTraNguyCo();
        }
        }
        ~DANHSACH(){
            delete[] DS;
        }
};
int main()
{
    DANHSACH DS;
    DS.NhapDanhSach();
    DS.Xuat();
    DS.KiemTra();
    return 0;
}
