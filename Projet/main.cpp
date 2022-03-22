#include "fonction.hpp"
#include "fonctions.cpp"

int main() {
  using namespace std;
  png::image<png::rgb_pixel> image("Circuit/input.png");
  auto options = toml::parse("Circuit/basique.toml");

  vector<int> Depart = CheckDepart(image, options);
  if(Depart.at(0) == -1 && Depart.at(1) == -1){
    cout<<"Erreur : Départ non trouvé. Assurez-vous de l'avoir défini sur l'image et dans le fichier toml (nom de paramètre : 'depart')"<<endl;
    return EXIT_SUCCESS;
  }

  vector<int>  Arrivee = CheckArrivee(image,options);
  if(Arrivee.at(0) == -1 && Arrivee.at(1) == -1){
    cout<<"Erreur : Arrivée non trouvée. Assurez-vous de l'avoir définie sur l'image et dans le fichier toml (nom de paramètre : 'couleur_arrivee')"<<endl;
    return EXIT_SUCCESS;
  }


  return EXIT_SUCCESS;
}
