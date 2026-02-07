#include <iostream>
#include <string>
using namespace std;

class Seuraaja {
public:
    Seuraaja *next = nullptr;
    Seuraaja(string nimi) : nimi(nimi) {
        cout << "Luodaan seuraaja " << nimi << endl;
    }
    string getNimi() {
        return nimi;
    }
    void paivitys(string viesti) {
        cout << "Seuraaja " << nimi << " sai viestin " << viesti << endl;
    }
private:
    string nimi;
};

class Notifikaattori {
private:
    Seuraaja *seuraajat = nullptr;
public:
    Notifikaattori() {
        cout << "Luodaan notifikaattori" << endl;
}

    void lisaa(Seuraaja *uusi) {
        cout << "Notifikaattori lisaa seuraajan " << uusi->getNimi() << endl;
        uusi->next = seuraajat;
        seuraajat = uusi;
}


    void poista(Seuraaja *poistettava) {
        cout << "Notifikaattori poistaa seuraajan " << poistettava->getNimi() << endl;
        if (seuraajat == nullptr)
            return;

        if (seuraajat == poistettava) {
            seuraajat = seuraajat->next;
            return;
}

        Seuraaja *nykyinen = seuraajat;
        while (nykyinen->next != nullptr) {
            if (nykyinen->next == poistettava) {
                nykyinen->next = poistettava->next;
                return;
            }
            nykyinen = nykyinen->next;
}
}

    void tulosta() {
        cout << "Notifikaattorin seuraajat:" << endl;
        Seuraaja *nykyinen = seuraajat;
        while (nykyinen != nullptr) {
            cout << "Seuraaja " << nykyinen->getNimi() << endl;
            nykyinen = nykyinen->next;
        }
    }

    void postita(string viesti) {
        cout << "Notifikaattori postaa viestin " << viesti << endl;
        Seuraaja *nykyinen = seuraajat;
        while (nykyinen != nullptr) {
            nykyinen->paivitys(viesti);
            nykyinen = nykyinen->next;
        }
    }

};

int main()
{
    Notifikaattori n;
    Seuraaja a("A");
    Seuraaja b("B");
    Seuraaja c("C");

    n.lisaa(&a);
    n.lisaa(&b);
    n.lisaa(&c);
    n.tulosta();
    n.postita("Tama on viesti 1");
    n.poista(&b);
    n.postita("Tama on viesti 2");

    return 0;
}
