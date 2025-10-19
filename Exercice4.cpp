#include <iostream>
#include <string>
using namespace std;

class Employe {
protected:
    string nom;
    int id;
    float salaireDeBase;

public:
    Employe(string n, int i, float s)
        : nom(n), id(i), salaireDeBase(s) {}

    virtual void afficherInfos() const {
        cout << "Nom : " << nom
             << ", ID : " << id
             << ", Salaire de base : " << salaireDeBase ;
    }
    virtual ~Employe() {}

};

class Permanent : public Employe {
private:
    float primeAnnuelle;

public:
    Permanent(string n, int i, float s, float prime)
        : Employe(n, i, s), primeAnnuelle(prime) {}

    void afficherInfos() const  {
        Employe::afficherInfos();
        cout << ", Prime annuelle : " << primeAnnuelle  << endl;
    }
};

class Contractuel : public Employe {
private:
    int dureeContrat; 
    float tauxHoraire;

public:
    Contractuel(string n, int i, float s, int duree, float taux)
        : Employe(n, i, s), dureeContrat(duree), tauxHoraire(taux) {}

    void afficherInfos() const  {
        Employe::afficherInfos();
        cout << ", Duree contrat : " << dureeContrat 
             << " mois, Taux horaire : " << tauxHoraire  << endl;
    }

    float calculerSalaireMensuel(int heures) const {
        return tauxHoraire * heures;
    }
};

int main() {

    Employe* equipe[3];

    equipe[0] = new Permanent("Ariana", 100, 1500.0, 2000.0);
     equipe[1] = new Contractuel("Martin", 103, 700.0, 12, 20.0);
    equipe[2] = new Permanent("Taylor", 102, 2000.0, 1200.0);

    cout << "Informations des employes :\n";
    for (int i = 0; i < 3; i++) {
        equipe[i]->afficherInfos();
    }
    Contractuel* c = dynamic_cast<Contractuel*>(equipe[1]);
    if (c) {
        cout << "Salaire mensuel de " << c->calculerSalaireMensuel(160) << " pour 160 heures" << endl;
    }


    return 0;
}
