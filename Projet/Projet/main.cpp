#include "fonction.hpp"
#include "fonctions.cpp"


int main(int argc, char *argv[]) {
  using namespace std;
  if (argc < 3) {
    cerr << "pas assez de parametres !" << endl;
    exit(EXIT_FAILURE);
  }

  string fichier_entree = argv[1];
  string image_entree = argv[2];

  png::image<png::rgb_pixel> image(image_entree);
  auto options = toml::parse(fichier_entree);

      try
    {
        vector<Pair> traj_opti = findTraj(image, options);
        vector<vector<int>> vect_opti = pointToVector(traj_opti);
        string fichier_sortie = "path";
        ofstream fichier(fichier_sortie.c_str(), ios::out | ios::trunc);
        if(fichier){
          for(int x = 0 ; x < vect_opti.size() ; x++){
            fichier << convert((vect_opti.at(x)).at(0)) << convert((vect_opti.at(x)).at(1));
          }
          fichier.close();
        }
        else{
          cerr << "Impossible d'ouvrir le fichier !" << endl;
        }
    }

    catch (std::invalid_argument& e)
    {
        cerr << e.what() << endl;
        return -1;
    }


  return EXIT_SUCCESS;
}
