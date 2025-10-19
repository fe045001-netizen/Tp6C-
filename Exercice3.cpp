#include <iostream>
#include <string>
using namespace std;

class Produit {
protected:
    string nom;
    double prix;

public:
    Produit(string n, double p) {
    	nom=n;
	    prix=p;
	}

     void afficherInfos() const {
        cout << "Produit : " << nom << ", Prix : " << prix ;
    }
};
class ProduitAlimentaire : public Produit {
private:
    string dateExpiration;
public:
    ProduitAlimentaire(string n, double p, string date)
        : Produit(n, p), dateExpiration(date) {}

    virtual void afficherInfos() const  {
        Produit::afficherInfos(); 
        cout << " Date d'expiration : " << dateExpiration << endl;
    }
};
class ProduitElectronique : public Produit {
private:
    int garantie;

public:
    ProduitElectronique(string n, double p, int g)
        : Produit(n, p), garantie(g) {}

    void afficherInfos() const  {
    	Produit::afficherInfos(); 
        cout << " Garantie : " << garantie << " mois" << endl;
    }
};
int main() {
    ProduitAlimentaire pa("formmage", 20, "2025-10-20");
    ProduitElectronique pe("iphone", 4000, 3);

    pa.afficherInfos();
    pe.afficherInfos();

    Produit* tab[2];
    tab[0] = &pa;
    tab[1] = &pe;

    cout << "\nAffichage via pointeurs :\n";
    for (int i = 0; i < 2; i++) {
        tab[i]->afficherInfos(); 
    }    
    return 0;
}
