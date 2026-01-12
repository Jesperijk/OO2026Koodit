#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int game(int maxnum) {

    int luku = rand() % maxnum + 1;
    int arvaus;
    int arvaukset = 0;

    do {
        cout<<"Luku valilta 1-maxnum: ";
        cin>>arvaus;
        arvaukset++;

        if (arvaus < luku) {
            cout<<"liian pieni"<<endl;
        }
        else if (arvaus > luku) {
            cout<<"liian suuri"<<endl;
        }
    }
    while (arvaus != luku);
    cout<<"oikein"<<endl;

    return arvaukset;
}

int main() {

    int tulos = game(40);
    cout<<"arvaukset: "<<tulos<<endl;

    return 0;
}
