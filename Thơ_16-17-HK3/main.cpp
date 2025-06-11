#include <bits/stdc++.h>
using namespace std;
class Tho{
    protected:
        int soCau;
        string dsCau[100][15];
    public:
        Tho(){};
        virtual ~Tho(){};
        void soanBaiTho(){
            cout << "Nhap tung cau tho (nhap 'x' de ket thuc):\n";
            string line;
            soCau = 0;
            cin.ignore();
            while(soCau<100){
                cout << "Cau " << soCau + 1 << ":";
                getline(cin,line);
                if(line == "x"){
                    break;
                }
                stringstream ss(line);
                string word;
                int wordCount = 0;
                while(ss>>word && wordCount < 15){
                    dsCau[soCau][wordCount] = word;
                    wordCount++;
                }
                soCau++;
            }
        }
        void inBaiTho(){
            cout << "\n=== Bai tho vua soan ===\n" << endl;
            for(int i=0;i<soCau;i++){
                for(int j=0;j<15;j++){
                    if(dsCau[i][j].empty()) break;
                    cout << dsCau[i][j] << " ";
                }
                cout << endl;
            }
        }
        int ktgieovan(string a, string b){
            int check = 0;
            return check;
        }
        int demTuTheoDong (int dong){
            int Count = 0;
            for(int i = 0; i<15 ;i++){
                if(dsCau[dong][i].empty()) break;
                Count++;
            }
            return Count;
        }
        int getSoCau(){return soCau;}
        virtual bool isValid(){return true;}
};
class ThoLucBat : public Tho{
    public:
        bool isValid() override{
            if(soCau % 2 !=0) return false;
            for(int i=0;i<soCau;i++){
                int soTu=Tho::demTuTheoDong(i);
                if((soCau %2==0 && soTu!=6) || (soCau%2!=0 && soTu!=8)) return false;
                if(i%2==0){
                    if(Tho::ktgieovan(dsCau[i][5],dsCau[i+1][5])) return false;
                }
                if(i%2!=0 && i != soCau-1){
                    if(Tho::ktgieovan(dsCau[i][7],dsCau[i+1][5])) return false;
                }
            }
            return true;
        }
};
class ThoSong768 : public Tho{
    public:
        bool isValid() override{
            if(soCau % 4 !=0) return false;
            for(int i=0;i<soCau;i++){
                int soTu=Tho::demTuTheoDong(i);
                if(((i == 0 || i == 1 ) && soTu != 7) || (i == 2 && soTu != 6) || (i == 3 && soTu != 8)) return false;
                if(i==0){
                    if(Tho::ktgieovan(dsCau[i][6],dsCau[i+1][4])) return false;
                }
                if(i==1){
                    if(Tho::ktgieovan(dsCau[i][6],dsCau[i+1][5])) return false;
                }
                if(i==2){
                    if(Tho::ktgieovan(dsCau[i][5],dsCau[i+1][5])) return false;
                }
            }
            return true;
        }
};
class ThoDL78 : public Tho{
    public:
        bool isValid() override{
            if(soCau % 8 != 0 ) return false;
            for(int i=0;i<soCau;i++){
                int soTu = Tho::demTuTheoDong(i);
                if(soTu != 7) return false;
                if (i == 0) {
                    if (Tho::ktgieovan(dsCau[i][6],dsCau[i+1][6]) &&
                        Tho::ktgieovan(dsCau[i][6],dsCau[i+3][6]) &&
                        Tho::ktgieovan(dsCau[i][6],dsCau[i+5][6]) &&
                        Tho::ktgieovan(dsCau[i][6],dsCau[i+1][7])) {
                        return false;
                    }
                }
            }
            return true;
        }
};
using namespace std;

int main()
{
    Tho* DS[100];
    int dem = 0;
    int choose;
    do{
        cout << "1. Tho 68\n2. Tho 768\n3. Tho DL78\n0. Ket thuc\n"; cin >> choose;
        switch(choose){
            case 1:
                DS[dem] = new ThoLucBat();
                DS[dem]->soanBaiTho();
                dem++;
                break;
            case 2:
                DS[dem] = new ThoSong768();
                DS[dem]->soanBaiTho();
                dem++;
                break;
            case 3:
                DS[dem] = new ThoDL78();
                DS[dem]->soanBaiTho();
                dem++;
                break;
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default: cout << "Lua chon k hop le\n";
        }
    }while(choose !=0);
    int Max = 0;
    for(int i=1;i<dem;i++){
        if(DS[i]->getSoCau() > DS[Max]->getSoCau()) Max = i;
    }
    cout << "Bai tho nhieu cau nhat la: "; DS[Max]->inBaiTho();
    cout << "voi so cau la: " << DS[Max]->getSoCau();
    for (int i = 0; i < dem; i++) {
        cout << "\nBai tho thu: " << i+1 << endl;
        // Câu 3. Các bài thơ trong danh sách có phù hợp luật thơ không
        if (DS[i]->isValid()) {
            cout << " phu hop!" << endl;
        } else {
            cout << " Khong phu hop" << endl;
        }
    }
     //Giải phóng bộ nhớ
    for (int i = 0; i < dem; i++) {
        delete DSnj[i];
    }

    return 0;
}
