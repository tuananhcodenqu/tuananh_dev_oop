#include <bits/stdc++.h>
using namespace std;
class KyHieu{
    protected:
        float TruongDo;
    public:
        KyHieu(){};
        virtual void Nhap(){
            cout << "Nhap cac not nhac: \n";
            cout << "CHON:  \n 1. NOT TRON\n 2. NOT TRANG\n 3. NOT DEN\n 4. NOT MOC DON\n 5. NOT MOC KEP\n 6. NOT MOC TAM\n 7. NOT MOC TU\n";
            int choose; cin >> choose;
            switch(choose){
                case 1:
                    TruongDo = 4; break;
                case 2:
                    TruongDo = 2; break;
                case 3:
                    TruongDo = 1; break;
                case 4:
                    TruongDo = 0.5; break;
                case 5:
                    TruongDo = 0.25; break;
                case 6:
                    TruongDo = 0.125; break;
                case 7:
                    TruongDo = 0.0625; break;
                default:
                    TruongDo = 1; break; // mac dinh la not den
            }
        };
        virtual int getCaoDo() = 0;
        virtual bool LaDauLangDen() = 0;
        ~KyHieu(){};
};
class NotNhac : public KyHieu {
    private:
        int CaoDo;
    public:
        NotNhac(){};
        ~NotNhac(){};
        void Nhap() override {
            cout << "Nhap not nhac: \n";
            cout << " 1. C\n 2. D\n 3. E\n 4. F\n 5. G\n 6. A\n 7. B\n";
            int choose; cin >> choose;
            CaoDo = choose;
            // nhap truong do
            KyHieu::Nhap();
        }
        bool LaDauLangDen() override {
            return false;
        };
        int getCaoDo() override{
            return CaoDo;
        };
};
class DauLang : public KyHieu{
    public:
        DauLang(){};
        ~DauLang(){};
        bool LaDauLangDen() override{
            if(TruongDo == 1) return true;
            return false;
        }
        void Nhap() override{
            //Nhap truong do
            KyHieu::Nhap();
        }
        int getCaoDo() override{
            return 0;
        }
};
int main()
{
    KyHieu* BanNhac[50];
    int n;
    cout << "Nhap so luong ky hieu cho 1 ban nhac: "; cin >> n;
    for(int i=0;i<n;i++){
        int t;
        cout << "1. Not Nhac" << endl;
        cout << "2. Dau Lang" << endl;
        cin >> t;
        switch (t)
        {
            case 1: BanNhac[i] = new NotNhac();
                break;
            case 2: BanNhac[i] = new DauLang();
                break;
        }
        BanNhac[i]->Nhap();
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(BanNhac[i]->LaDauLangDen()) count++;
    }
    cout << "So dau lang den trong ban nhac la: " << count << "\n";
    int Max =  0;
    for(int i=0;i<n;i++){
        if(BanNhac[i]->getCaoDo() > BanNhac[Max]->getCaoDo()) Max = i;
    }
    cout << "Vi tri co not nhac cao nhat la: " << Max+1;
    for(int i = 0; i < n; i++) {
        delete BanNhac[i];
    }
    return 0;
}
