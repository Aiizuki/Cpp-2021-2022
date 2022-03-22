#include "fonction.hpp"

std::vector<int> CheckArrivee(png::image<png::rgb_pixel> image, auto options){
  int acc_max =  toml::find<int>(options, "acc_max");
  std::vector<int> couleur_arrivee = toml::find<std::vector<int>>(options,"couleur_arrivee");;

  std::vector<std::vector<int>*> Zone_Arrivee;

  for (png::uint_32 y = 0; y < image.get_height(); ++y){
    for (png::uint_32 x = 0; x < image.get_width(); ++x){
      if (image[y][x].red == couleur_arrivee.at(0) && image[y][x].green == couleur_arrivee.at(1) && image[y][x].blue == couleur_arrivee.at(2)){
        // std::cout<<"Arrivée en : ["<< x << ";" << y << "]"<<std::endl;
        Zone_Arrivee.push_back(new std::vector<int> {(int) y,(int) x});
      }
    }
  }

  if(Zone_Arrivee.size()%2 == 0){
    return *(Zone_Arrivee.at(Zone_Arrivee.size()/2));
  }

  else if (Zone_Arrivee.size() == 0){
    return *(new  vector<int>{-1,-1});
  }

  return *(Zone_Arrivee.at((Zone_Arrivee.size()/2)+1));

}

std::vector<int> CheckDepart(png::image<png::rgb_pixel> image, auto options){
  const auto d = toml::find(options, "depart");
  int d1 = toml::find<int>(d,"y");
  int d2 = toml::find<int>(d,"x");

  for (png::uint_32 y = 0; y < image.get_height(); ++y){
    for (png::uint_32 x = 0; x < image.get_width(); ++x){
      if((int) y == d1 && (int) x == d2){
        std::vector<int>* v = new std::vector<int> {(int) y, (int) x};
        // std::cout<<"Départ en : ["<< x << ";" << y << "]"<<std::endl;
        return *v;
      }
    }
  }
  std::vector<int>* e = new std::vector<int>{-1,1};
  return *e;
}
