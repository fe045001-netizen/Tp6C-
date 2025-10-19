#include <iostream>
#include <string>
using namespace std;

class Personne {
protected:
    string nom;
    int age;
public:
    Personne(string nom, int age) : nom(nom), age(age) {}

    void afficherInfos() const {
        cout << "Nom : " << nom << ", Age : " << age << endl;
    }
};
class Etudiant : public Personne {
private:
    string niveau;
public:
    Etudiant(string nom, int age, string niveau)
        : Personne(nom, age), niveau(niveau) {}

    void afficherEtudiant() const {
        afficherInfos(); 
        cout << "niveau : " << niveau << endl;
    }
};
int main() {
    Etudiant e("Imane", 22, "Informatique");
    e.afficherEtudiant();
    return 0;
}

