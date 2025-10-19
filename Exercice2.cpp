#include <iostream>
using namespace std;

class Compte {
protected:
    int numero;
    double solde;

public:
    
    Compte(int num, double s = 0.0) {
        numero=num;
		 solde=s; 
		}

    void deposer(double montant) {
        if (montant > 0) {
            solde += montant;
            cout << "Depose : " << montant << " | Nouveau solde : " << solde << endl;
        } else {
            cout << "Montant invalide" << endl;
        }
    }

    void retirer(double montant) {
        if (montant > 0 && montant <= solde) {
            solde -= montant;
            cout << "Retire : " << montant << "| Nouveau solde : " << solde << endl;
        } else {
            cout << "Retrait impossible" << endl;
        }
    }

    void afficher() const {
        cout << "Compte numero" << numero << " | Solde : " << solde  << endl;
    }
};

class CompteEpargne : public Compte {
private:
    double tauxInteret; 

public:
    CompteEpargne(int num, double s, double taux)
        : Compte(num, s), tauxInteret(taux) {}

  
    double calculerInteret() const {
        return solde * tauxInteret / 100;
    }

    void afficherAvecInteret() const {
        afficher();
        cout << "Taux d'interet : " << tauxInteret << "% | Interet : " 
             << calculerInteret()  << endl;
    }
};

int main() {
    
    CompteEpargne ce(300, 700.0, 2.0); 

    ce.afficherAvecInteret();

    ce.deposer(150.0);
    ce.retirer(100.0);

    ce.afficherAvecInteret();

    return 0;
}

