#include <bits/stdc++.h>
using namespace std;
class PersonalityTraits{
    protected:
        int score;
    public:
        PersonalityTraits(int s){
            score = s;
        }
        virtual string getDescription() = 0;
        int getScore(){return score;}
        virtual ~PersonalityTraits(){};
};
class Openness: public PersonalityTraits{ // Cởi mở
    public:
        Openness(int s) : PersonalityTraits(s){}
        string getDescription() override{
            if(score >=70) return "thich nhung y tuong moi, thich hieu biet nhieu linh vuc nhung dong thoi cung thich tu do, khong thich bi rang buoc...\n";
            if(score <= 30) return "kha bao thu, kho tiep nhan nhung y tuong moi, la. Ho thich su on dinh quen thuoc va thuc te.\n";
            return "Khong xac dinh\n";
        }
};
class Conscientiousness: public PersonalityTraits{ // Tận tâm
    public:
        Conscientiousness(int s): PersonalityTraits(s){}
        string getDescription() override{
            if(score >=70) return "cham chi, co kha nang chiu ap luc tot. Ho thuong la nguoi gan bo, trung thanh voi to chuc.\n";
            if(score <=30) return "de bo cuoc, kha nang chiu ap luc, tuan thu ky luat to chuc kem.\n";
            return "Khong xac dinh\n";
        }
};
class Extraversion: public PersonalityTraits{ // Hướng ngoại
    public:
        Extraversion(int s): PersonalityTraits(s){}
        string getDescription() override{
            if(score >=70) return "nhiet tinh, nang dong, giao tiep to, thich the hien ban than.\n";
            if(score <=30) return "ngai giao tiep, khong thich su noi bat, thich duoc lam viec doc lap\n";
            return "Khong xac dinh\n";
        }
};
class Agreeableness : public PersonalityTraits{ // Dễ chiu
    public:
        Agreeableness (int s): PersonalityTraits(s){}
        string getDescription() override{
            if(score >=70) return "than thien, coi mo, dong cam voi moi nguoi nhung nhieu khi 'thieu chinh kien'.\n";
            if(score <=30) return "dat loi ich cua ban than len tren, it dong cam, chia se voi dong nghiep, co tinh canh tranh cao\n";
            return "Khong xac dinh\n";
        }
};
class Neuroticism : public PersonalityTraits{ // Âu lo
    public:
        Neuroticism (int s): PersonalityTraits(s){}
        string getDescription() override{
            if(score >=70) return "co cam xuc tieu cuc nhu: lo lang, buc boi, tu ti, yeu duoi va kha nang chiu ap luc kem.\n";
            if(score <=30) return "kiem soat duoc cam xuc, ung pho voi cang thang tot, it bi ben ngoai anh huong den tam trang cua ban than.\n";
            return "Khong xac dinh\n";
        }
};
//==========================================================LỚP NGƯỜI===================================================================
class Person{
    private:
        string id;
        PersonalityTraits* traits[5]; // O,C,E,A,N
    public:
        void Input(){
            int o,c,e,a,n;
            cout << "Nhap ma~ nguoi: "; cin >> id;
            cout << "Nhap score cua o,c,e,a,n: ";
            do{
                cin >> o >> c >> e >> a >> n;
                if(o > 100 || o < 0 || c > 100 || c < 0 || e > 100 || e < 0 || a > 100 || a < 0 || n > 100 || n < 0){cout << "score khong hop le! Nhap lai!\n";}
            }while(o > 100 || o < 0 || c > 100 || c < 0 || e > 100 || e < 0 || a > 100 || a < 0 || n > 100 || n < 0);
            traits[0] = new Openness(o);
            traits[1] = new Conscientiousness(c);
            traits[2] = new Extraversion(e);
            traits[3] = new Agreeableness(a);
            traits[4] = new Neuroticism(n);
        }
        void Display(){
            string Labels[5] = {"Openness","Conscientiousness","Extraversion","Agreeableness","Neuroticism"};
            cout << "Ma: " << id << "\n";
            for(int i=0;i<5;i++){
                cout << Labels[i]  << "(" << traits[i]->getScore() << "): ";
                cout << traits[i]->getDescription() << "\n";
            }
        }
        string getID(){return id;}
        bool RiskyCandidate(){
            return traits[1]->getScore() <=30 || traits[4]->getScore() >=70 || (traits[2]->getScore()<=30 && traits[4]->getScore() >=70);
        }
        ~Person(){
            for(int i=0;i<5;i++){
                delete traits[i];
            }
        }
};
//==================================MAIN========================================
int main(){
    const int MAX = 50;
    Person people[MAX];
    int count=0,choice;
    do{
        cout << "\n=== MENU ===\n";
        cout << "1. Them nguoi moi\n";
        cout << "2. Xem thong tin mot nguoi\n";
        cout << "3. Liet ke nguoi co nguy co cao\n";
        cout << "0. Thoat\n";
        cout << "Chon: ";
        cin >> choice;
        switch(choice){
            case 1:
                if(count>= MAX) cout << "Danh sach da day.\n";
                else{
                    people[count++].Input();
                    cout << "Da them vao danh sach!\n";
                } break;
            case 2:{
                string id;
                cout << "Nhap id nguoi can xem: "; cin >> id;
                bool found = false;
                for(int i=0;i<count;i++){
                    if(people[i].getID()==id){
                        people[i].Display();
                        found = true;
                    }
                    if(!found) cout << "Chua co du lieu.\n";
                }
                break;
            }
            case 3:
                cout << "Danh sach nguoi co nguy co cao: \n";
                for(int i=0;i<count;i++){
                    if(people[i].RiskyCandidate()){
                        cout << i+1 << ". " << people[i].getID() << "\n";
                    }
                }
                break;
            case 0:
                cout << "Ket thuc!\n";
            default: cout << "Lua chon khong hop le.\n";
        }
    }while(choice != 0);
    return 0;
}
