#include "fonction.hpp"

/*
#include "lion.hpp"
#include "zebre.hpp"
#include "girafe.hpp"
#include "zoo.hpp"*/

int main() {
  /*
    string nom("Zootopia");
    Zoo zootopia(nom);

    zootopia.ajouter_animal(new Lion(20, "Alex", 200, "marron"));
    zootopia.ajouter_animal(new Zebre(10, "Marty", 350, 50));
    zootopia.ajouter_animal(new Girafe(15, "Melman", 800, 1.8));

    zootopia.appel();

    /* Le gardien, un brin paranoïaque, refait l'appel à sa manière
    vector<Animal*> animaux = zootopia.get_animaux();
    for(vector<Animal*>::iterator it = animaux.begin() ;
            it != animaux.end() ; ++it) {
        (*it)->crier();
    }*/

    Terrain_Rugby* Test = new Terrain_Rugby('/',60,20);
    Test->build_pelouse_rugby();
    Test->afficher_pelouse();

    return 0;
}
