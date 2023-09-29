/*
# dynamic memory allocation - in buyAnimal() function
# file handling - in draw(),importData(),exportData(),login(),signup(),mainmenu(),gamemenu(),helpmenu(),displayLogo() function
# inheritance - from "animal" class
# polymorphism - in draw(),feed() function
# abstract class,pure virtual function,virtual function - "animal" class
# pointer to base class - displayAnimal() , feedTemplate() function
# template - displayAnimal(), feedTemplate(), sellAnimal() function
# stl vector -in class "farm" and many other functions
# friend function - exportData() function
# friend class - friend class "farm" in animal class
# operator overloading - << operator in inherited classes
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class farm;
void exportData(farm &f1,ofstream &out);
int cnt;

class animal{
protected:
    int serialNo;
    int price;
    int happiness;
    int feedrate;

public:
    animal(){
        serialNo = ++cnt;
        happiness = 0;
    }
    animal(int sl,int hp){
        serialNo = sl;
        happiness = hp;
    }
    virtual void draw() = 0;
    virtual void feed() = 0;
    friend class farm;
    friend void exportData(farm &f1,ofstream &out);
};

class cow:public animal{
    int milkrate;

public:
    cow(){
        milkrate = 5;
        price = 20000;
        feedrate = 5;
    }
    cow(int sl,int price,int hp,int fr,int mr):animal(sl,hp){
        milkrate = mr;
        this->price = price;
        feedrate = fr;
    }
    void draw(){
        ifstream in;
        in.open("cow.txt");
        string line;
        while(in.eof()==0){
            getline(in, line);
            cout << line << endl;
        }
        in.close();
    }
    void feed(){
        happiness += 20;
        if(happiness>=100){
            happiness -= 100;
            milkrate++;
            price += 500;
            cout << "Sl no " << serialNo << " cow milkrate increased!" << endl;
        }
        cout << "Sl No " << serialNo << " cow has been fed!" << endl;
    }
    friend ostream& operator<<(ostream& out, cow& c1){
        out << "Sl: " << c1.serialNo << endl;
        out << "Milkrate: " << c1.milkrate << " Liter per day" << endl;
        out << "Happiness: " << c1.happiness << " %" << endl;
        out << "Price: " << c1.price << endl;
        return out;
    }
    friend class farm;
    friend void exportData(farm &f1,ofstream &out);
};

class chicken:public animal{
    int eggrate;

public:
    chicken(){
        eggrate = 1;
        price = 300;
        feedrate = 1;
    }
    chicken(int sl,int price,int hp,int fr,int er):animal(sl,hp){
        eggrate = er;
        this->price = price;
        feedrate = fr;
    }
    void draw(){
        ifstream in;
        in.open("chicken.txt");
        string line;
        while(in.eof()==0){
            getline(in, line);
            cout << line << endl;
        }
        in.close();
    }
    void feed(){
        happiness += 20;
        if(happiness>=100){
            happiness -= 100;
            eggrate++;
            price += 100;
            cout << "Sl no " << serialNo << " chicken eggrate increased!" << endl;
        }
        cout << "Sl No " << serialNo << " chicken has been fed!" << endl;
    }
    friend ostream& operator<<(ostream& out, chicken& c1){
        out << "Sl: " << c1.serialNo << endl;
        out << "Eggrate: " << c1.eggrate << " piece per day" << endl;
        out << "Happiness: " << c1.happiness << " %" << endl;
        out << "Price: " << c1.price << endl;
        return out;
    }
    friend class farm;
    friend void exportData(farm &f1,ofstream &out);
};

class horse:public animal{
    int speed;

public:
    horse(){
        speed = 20;
        price = 50000;
        feedrate = 8;
    }
    horse(int sl,int price,int hp,int fr,int sp):animal(sl,hp){
        speed = sp;
        this->price = price;
        feedrate = fr;
    }
    void draw(){
        ifstream in;
        in.open("horse.txt");
        string line;
        while(in.eof()==0){
            getline(in, line);
            cout << line << endl;
        }
        in.close();
    }
    void feed(){
        happiness += 20;
        if(happiness>=100){
            happiness -= 100;
            speed++;
            price += 2000;
            cout << "Sl no " << serialNo << " horse speed increased!" << endl;
        }
        cout << "Sl No " << serialNo << " horse has been fed!" << endl;
    }
    friend ostream& operator<<(ostream& out, horse& c1){
        out << "Sl: " << c1.serialNo << endl;
        out << "Speed: " << c1.speed << " miles per hour" << endl;
        out << "Happiness: " << c1.happiness << " %" << endl;
        out << "Price: " << c1.price << endl;
        return out;
    }
    friend class farm;
    friend void exportData(farm &f1,ofstream &out);
};

class sheep:public animal{
    int woolrate;
public:
    sheep(){
        woolrate = 1;
        price = 8000;
        feedrate = 3;
    }
    sheep(int sl,int price,int hp,int fr,int wr):animal(sl,hp){
        woolrate = wr;
        this->price = price;
        feedrate = fr;
    }
    void draw(){
        ifstream in;
        in.open("sheep.txt");
        string line;
        while(in.eof()==0){
            getline(in, line);
            cout << line << endl;
        }
        in.close();
    }
    void feed(){
        happiness += 20;
        if(happiness>=100){
            happiness -= 100;
            woolrate++;
            price += 1000;
            cout << "Sl no " << serialNo << " sheep woolrate increased!" << endl;
        }
        cout << "Sl No " << serialNo << " sheep has been fed!" << endl;
    }
    friend ostream& operator<<(ostream& out, sheep& c1){
        out << "Sl: " << c1.serialNo << endl;
        out << "Woolrate: " << c1.woolrate << " kg per day" << endl;
        out << "Happiness: " << c1.happiness << " %" << endl;
        out << "Price: " << c1.price << endl;
        return out;
    }
    friend class farm;
    friend void exportData(farm &f1,ofstream &out);
};

class farm{
    int balance;
    int feed;
    vector<cow> cowBarn;
    vector<chicken> chickenHouse;
    vector<horse> horseStable;
    vector<sheep> sheepPen;
    int cowCapacity;
    int chickenCapacity;
    int horseCapacity;
    int sheepCapacity;

public:
    farm(){
        balance = 25000;
        feed = 0;
        cowCapacity = 2;
        chickenCapacity = 5;
        horseCapacity = 1;
        sheepCapacity = 3;
    }
    farm(int bal,int fd,int cowC,int chickenC,int horseC,int sheepC,vector<cow>cowB,vector<chicken>chickenH,vector<horse>horseS,vector<sheep>sheepP){
        balance = bal;
        feed = fd;
        cowBarn = cowB;
        chickenHouse = chickenH;
        horseStable = horseS;
        sheepPen = sheepP;
        cowCapacity = cowC;
        chickenCapacity = chickenC;
        horseCapacity = horseC;
        sheepCapacity = sheepC;
    }

    template <typename t>
    void displayanimal(vector<t>&v){
        if(v.size()==0){
            cout << "You don't have any animal!" << endl;
            return;
        }
        for(auto it:v){
            animal *ptr = &it;
            ptr->draw();
            cout << it;
        }
    }

    template <typename t>
    void sellanimal(vector<t>&v){
        if(v.size()==0){
            cout << "You don't have any animal!" << endl;
            return;
        }
        cout << '\n';
        for(auto it:v){
            cout << it << endl;
        }
        cout << "1.sell individual" << endl;
        cout << "2.sell all" << endl;
        cout << "3.back" << endl;
        int x;
        cin >> x;
        if(x==1){
            cout << "Enter SL No: " << endl;
            int sl;
            cin >> sl;
            for (auto it = v.begin(); it != v.end();++it)
            {
                if((*it).serialNo==sl){
                    balance += (*it).price;
                    cout << "SL no " << sl << " Animal sold!" << endl;
                    v.erase(it);
                    return;
                }
            }
            cout << "Invalid SL " << endl;
        }
        else if(x==2){
            for (auto it:v)
            {
                cout << "SL no " << it.serialNo << " Animal sold!" << endl;
                balance += it.price;
            }
            v.clear();
        }
        else if(x==3){
            return;
        }
        else{
            cout << "Invalid choice!" << endl;
        }
    }

    void buyanimal(){
        cout << '\n';
        cout << "1.Cow    :  20000 BDT " << endl;
        cout << "2.Chiken :    300 BDT " << endl;
        cout << "3.Horse  :  50000 BDT " << endl;
        cout << "4.Sheep  :   8000 BDT " << endl;
        cout << "Enter your choice : " << endl;
        int x;
        cin >> x;
        switch(x){
            case 1:
            {
            cow *c1 = new cow;
            if (balance < c1->price)
            {
                cout << "You don't have enough balance!" << endl;
                break;
                }
                if(cowBarn.size()==cowCapacity){
                    cout << "Not enough space! Upgrade your farm!" << endl;
                    break;
                }
                balance -= c1->price;
                cowBarn.push_back(*c1);
                cout<<"Cow bought"<<endl;
                c1->draw();
                cout << *c1;
                delete c1;
                break;
            }
            case 2:
            {
                chicken *c2 = new chicken;
                if(balance<c2->price){
                    cout << "You don't have enough balance!" << endl;
                    break;
                }
                if(chickenHouse.size()==chickenCapacity){
                    cout << "Not enough space! Upgrade your farm!" << endl;
                    break;
                }
                balance -= c2->price;
                chickenHouse.push_back(*c2);
                cout<<"Chicken bought"<<endl;
                c2->draw();
                cout << *c2;
                delete c2;
                break;
            }
            case 3:
            {
                horse *h1 = new horse;
                if(balance<h1->price){
                    cout << "You don't have enough balance!" << endl;
                    break;
                }
                if(horseStable.size()==horseCapacity){
                    cout << "Not enough space! Upgrade your farm!" << endl;
                    break;
                }
                balance -= h1->price;
                horseStable.push_back(*h1);
                cout<<"Horse bought"<<endl;
                h1->draw();
                cout << *h1;
                delete h1;
                break;
            }
            case 4:
            {
                sheep *s1 = new sheep;
                if(balance<s1->price){
                    cout << "You don't have enough balance!" << endl;
                    break;
                }
                if(sheepPen.size()==sheepCapacity){
                    cout << "Not enough space! Upgrade your farm!" << endl;
                    break;
                }
                balance -= s1->price;
                sheepPen.push_back(*s1);
                cout<<"Sheep bought"<<endl;
                s1->draw();
                cout << *s1;
                delete s1;
                break;
            }
        }
    }

    void buyfeed(){

        cout << "Balance: " << balance << " BDT" << endl;
        cout << "Price: 20 BDT per kg" << endl;
        cout << "Enter amount: " << endl;
        int amnt;
        cin >> amnt;
        if(amnt*20>balance){
            cout << "You don't have enough balance!" << endl;
            return;
        }
        balance -= (amnt * 20);
        feed += amnt;
        cout << amnt << " kg feed bought" << endl;
    }

    void shop(){
        while(true){
            cout << '\n';
            cout << "1.Buy Animal" << endl;
            cout << "2.Sell Animal" << endl;
            cout << "3.Buy Feed" << endl;
            cout << "4.Increase Capacity" << endl;
            cout << "5.Back" << endl;
            int choice;
            cin >> choice;
            if(choice==1){
                buyanimal();
            }
            else if(choice==2){
                cout << '\n';
                cout << "1.Cow" << endl;
                cout << "2.Chiken" << endl;
                cout << "3.Horse" << endl;
                cout << "4.Sheep" << endl;
                cout << "Enter your choice : " << endl;
                int x;
                cin >> x;
                switch(x){
                    case 1:
                        sellanimal(cowBarn);
                        break;
                    case 2:
                        sellanimal(chickenHouse);
                        break;
                    case 3:
                        sellanimal(horseStable);
                        break;
                    case 4:
                        sellanimal(sheepPen);
                        break;
                    default:
                        cout << "Invalid Choice!" << endl;
                }
            }
            else if(choice==3){
                buyfeed();
            }
            else if(choice==4){
                cout << '\n';
                cout << "1.Upgrade Cow barn -     2000 BDT" << endl;
                cout << "2.Upgrade Chicken House- 300 " << endl;
                cout << "3.Horse Stable-          2000" << endl;
                cout << "4.Sheep Pen-             1000" << endl;
                int x;
                cin >> x;
                switch(x){
                    case 1:
                    if(balance<2000){
                        cout << "You don't have enough balance" << endl;
                        break;
                    }
                    balance -= 2000;
                    cowCapacity++;
                    cout << "Cow capacity: " << cowCapacity << endl;
                    break;
                    case 2:
                    if(balance<300){
                        cout << "You don't have enough balance" << endl;
                        break;
                    }
                    balance -= 300;
                    chickenCapacity++;
                    cout << "Chicken capacity: " << chickenCapacity << endl;
                    break;
                    case 3:
                    if(balance<2000){
                        cout << "You don't have enough balance" << endl;
                        break;
                    }
                    balance -= 2000;
                    horseCapacity++;
                    cout << "Horse capacity: " << horseCapacity << endl;
                    break;
                    case 4:
                    if(balance<1000){
                        cout << "You don't have enough balance" << endl;
                        break;
                    }
                    balance -= 2000;
                    sheepCapacity++;
                    cout << "Sheep capacity: " << sheepCapacity << endl;
                    break;
                    default:
                    cout << "Invalid choice!" << endl;
                }
            }
            else if(choice==5){
                break;
            }
            else{
                cout << "Invalid Choice!" << endl;
            }
        }
    }

    void simulate(){
        cout << '\n';
        for(auto it:cowBarn){
            balance += (80 * it.milkrate);
            cout << 80 * it.milkrate << " BDT earned from Cow milk" << endl;
        }
        for(auto it:chickenHouse){
            balance += (12 * it.eggrate);
            cout << 12 * it.eggrate << " BDT earned from Chicken egg" << endl;
        }
        for(auto it:sheepPen){
            balance += (200 * it.woolrate);
            cout << 200 * it.woolrate << " BDT earned from Sheep wool" << endl;
        }
        for(auto it:horseStable){
            balance += (400 * it.speed);
            cout << 400 * it.speed << " BDT earned from Horse Show ticket" << endl;
        }
    }

    template<typename t>
    void feedtemplate(vector<t>&v){
        for(auto &it:v){
            if(it.feedrate>feed){
                cout << "You don't have enough feed!" << endl;
                return;
            }
            animal *ptr = &it;
            ptr->feed();
            feed -= it.feedrate;
        }
    }

    void feedAnimal(){
        cout << '\n';
        cout << "1.Cow    - 5 kg / cow" << endl;
        cout << "2.Chiken - 1 kg / chicken" << endl;
        cout << "3.Horse  - 8 kg / horse" << endl;
        cout << "4.Sheep  - 3 kg / sheep" << endl;
        cout << "Enter your choice : " << endl;
        int x;
        cin >> x;
        switch(x){
            case 1:
            feedtemplate(cowBarn);
            break;
            case 2:
            feedtemplate(chickenHouse);
            break;
            case 3:
            feedtemplate(horseStable);
            break;
            case 4:
            feedtemplate(sheepPen);
            break;
            default:
            cout << "Invalid Choice!" << endl;
        }
    }

    void showStatus(){
        cout << '\n';
        cout << "Balance: " << balance << " BDT" << "\t\tFeed: " << feed << endl;
        cout << "Cow: " << cowBarn.size() << '/' << cowCapacity << endl;
        cout << "Chicken: " << chickenHouse.size() << '/' << chickenCapacity << endl;
        cout << "Horse: " << horseStable.size() << '/' << horseCapacity << endl;
        cout << "Sheep: " << sheepPen.size() << '/' << sheepCapacity << endl;
    }

    void showFarm(){
        cout << '\n';
        cout << "1.Cow Barn" << endl;
        cout << "2.Chiken House" << endl;
        cout << "3.Horse Stable" << endl;
        cout << "4.Sheep Pen" << endl;
        cout << "Enter your choice : " << endl;
        int x;
        cin >> x;
        switch(x){
            case 1:
            displayanimal(cowBarn);
            break;
            case 2:
            displayanimal(chickenHouse);
            break;
            case 3:
            displayanimal(horseStable);
            break;
            case 4:
            displayanimal(sheepPen);
            break;
            default:
            cout << "Invalid choice!" << endl;
        }
    }

    friend void exportData(farm &f1,ofstream &out);
    friend void gamemenu(farm &f, string username);
};

void importData(farm &f,ifstream &in){
    int bal, feed, cowc, chickc, horsec, sheepc, cown, chickn, horsen, sheepn;
    in >> bal >> feed >> cowc >> chickc >> horsec >> sheepc >> cown >> chickn >> horsen >> sheepn;
    vector<cow> cowb(cown);
    vector<chicken> chickh(chickn);
    vector<horse> horseS(horsen);
    vector<sheep> sheepP(sheepn);
    for(auto &it:cowb){
        int sl, price, hp, fr, mr;
        in >> sl >> price >> hp >> fr >> mr;
        cow c1(sl, price, hp, fr, mr);
        it = c1;
    }
    for(auto &it:chickh){
        int sl, price, hp, fr, er;
        in >> sl >> price >> hp >> fr >> er;
        chicken c1(sl, price, hp, fr, er);
        it = c1;
    }
    for(auto &it:horseS){
        int sl, price, hp, fr, sp;
        in >> sl >> price >> hp >> fr >> sp;
        horse c1(sl, price, hp, fr, sp);
        it = c1;
    }
    for(auto &it:sheepP){
        int sl, price, hp, fr, wr;
        in >> sl >> price >> hp >> fr >> wr;
        sheep c1(sl, price, hp, fr, wr);
        it = c1;
    }
    farm f1(bal, feed, cowc, chickc, horsec, sheepc, cowb, chickh, horseS, sheepP);
    f = f1;
}

void exportData(farm &f1,ofstream &out){
    out << f1.balance << ' ' << f1.feed << ' ' << f1.cowCapacity << ' ' << f1.chickenCapacity << ' ' << f1.horseCapacity << ' ' << f1.sheepCapacity << ' ' << f1.cowBarn.size() << ' ' << f1.chickenHouse.size() << ' ' << f1.horseStable.size() << ' ' << f1.sheepPen.size() << endl;
    for(auto it:f1.cowBarn){
        out << it.serialNo << ' ' << it.price << ' ' << it.happiness << ' ' << it.feedrate << ' ' << it.milkrate << endl;
    }
    for(auto it:f1.chickenHouse){
        out << it.serialNo << ' ' << it.price << ' ' << it.happiness << ' ' << it.feedrate << ' ' << it.eggrate << endl;
    }
    for(auto it:f1.horseStable){
        out << it.serialNo << ' ' << it.price << ' ' << it.happiness << ' ' << it.feedrate << ' ' << it.speed << endl;
    }
    for(auto it:f1.sheepPen){
        out << it.serialNo << ' ' << it.price << ' ' << it.happiness << ' ' << it.feedrate << ' ' << it.woolrate << endl;
    }
}

bool login(string &userName,ifstream &in){
    cout << '\n';
    cout << "Login..." << endl;
    cout << "Enter username: " << endl;
    cin >> userName;
    in.open("gamesave-" + userName + ".txt");
    if(!in){
        cout << "username not found!" << endl;
        return false;
    }
    else
        return true;
}
bool signup(string &userName){
    cout << '\n';
    cout << "Account creation..." << endl;
    cout << "Choose username: " << endl;
    cin >> userName;
    cout << "This is your username: " << userName << endl;
    cout << "Confirm?(y/n)" << endl;
    char c;
    cin >> c;
    switch(c){
        case 'y':
        return true;
        case 'n':
        cout << "Account creation failed!" << endl;
        return false;
        default:
        cout << "Invalid choice! Account creation failed!" << endl;
        return false;
    }
}

void displayLogo(){
    ifstream in;
    in.open("logo.txt");
    string line;
    while(in.eof()==0){
        getline(in, line);
        cout << line << endl;
    }
    cout << "\n\n";
    in.close();
}

void mainmenu(int &choice){
    cout << '\n';
    displayLogo();
    cout << "1.Create new Farm" << endl;
    cout << "2.Play in existing Farm" << endl;
    cout << "3.How to play" << endl;
    cout << "0.Exit" << endl;
    cin >> choice;
}

void gamemenu(farm &f,string username){
    cout << '\n';
    displayLogo();
    cout << "1.Show farm status" << endl;
    cout << "2.Display farm animals" << endl;
    cout << "3.Enter shop" << endl;
    cout << "4.Feed animal" << endl;
    cout << "5.Simulate one day" << endl;
    cout << "6.Save and exit" << endl;
    int choice;
    cin >> choice;
    switch(choice){
        case 1:
        f.showStatus();
        gamemenu(f,username);
        break;
        case 2:
        f.showFarm();
        gamemenu(f,username);
        break;
        case 3:
        cout << "Balance: \t" << f.balance << " BDT" << endl;
        f.shop();
        gamemenu(f,username);
        break;
        case 4:
        f.feedAnimal();
        gamemenu(f,username);
        break;
        case 5:
        f.simulate();
        gamemenu(f,username);
        break;
        case 6:
        {ofstream out;
        out.open("gamesave-" + username + ".txt");
        exportData(f, out);
        out.close();}
        return;
        default:
        cout << "Invalid choice!" << endl;
        gamemenu(f, username);
    }
}

void helpmenu(){
    cout << '\n';
    displayLogo();
    ifstream in;
    in.open("help.txt");
    string line;
    while(in.eof()==0){
        getline(in, line);
        cout << line << endl;
    }
    cout << "\n\n";
    in.close();
}

int main(){

    while(true){
        int choice;
        mainmenu(choice);
        string userName;
        bool flag = false;
        ifstream in;
        farm f;
        switch(choice){
            case 1:
            flag = signup(userName);
            break;
            case 2:
            flag = login(userName, in);
            if(flag){
                importData(f, in);
            }
            break;
            case 3:
            helpmenu();
            break;
            case 0:
            return 0;
            default:
            cout << "Invalid choice!" << endl;
        }
        if(!flag)
            continue;
        gamemenu(f, userName);
        in.close();
    }

    return 0;
}