#include <iostream>
#include <string>
using namespace std;

class Chef {
    public:
    Chef(string n);
    ~Chef();
    string getName();
    int makeSalad(int s);
    int makeSoup(int s);

    protected:
        string chefName;

};

class ItalianChef : public Chef {
    public:
    ItalianChef(string n);
    ~ItalianChef();
    bool askSecret(string n, int s, int m);

    private:
    string password = "pizza";
    int flour;
    int water;
    int makepizza(int s, int m);

};

Chef::Chef(string n) {
    chefName=n;
    cout<<"Chef "<<chefName<<" konstruktori "<<endl;
}

Chef::~Chef() {
    cout<<"Chef "<<chefName<<" destruktori "<<endl;
}

string Chef::getName() {
    return chefName;
}

int Chef::makeSalad(int s) {
    int portions=s/5;
    cout<<"Chef "<<chefName<<" with "<<s<<" items can make salad "<<portions<<" portions "<<endl;
    return portions;
}

int Chef::makeSoup(int s) {
    int portions=s/3;
    cout<<"Chef "<<chefName<<" with "<<s<<" items can make soup "<<portions<<" portions "<<endl;
    return portions;
}

ItalianChef::ItalianChef(string n):Chef(n) {
    flour=0;
    water=0;
    cout<<"ItalianChef "<<chefName<<" konstruktori "<<endl;
}

ItalianChef::~ItalianChef() {
    cout<<"ItalianChef "<<chefName<<" destruktori "<<endl;
}

bool ItalianChef::askSecret(string n,int s,int m){
    flour=s;
    water=m;

    if(n==password) {
        cout<<"Password ok!"<<endl;
        int pizzas=makepizza(flour,water);
        cout<<"ItalianChef "<< chefName <<" with "<<flour<<" flour and "<<water<<" water can make "<<pizzas<<" pizzas "<<endl;
        return true;
    }
    cout<<"Wrong password!"<<endl;
    return false;
}

int ItalianChef::makepizza(int s,int m) {
    return min(s/5,m/5);
}
int main(){
    Chef c("Gordon");
    c.makeSalad(11);
    c.makeSoup(14);

    ItalianChef i("Mario");
    i.makeSalad(9);
    i.askSecret("pizza",12,12);

    return 0;
}

