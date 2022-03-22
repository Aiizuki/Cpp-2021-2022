#include "fonction.hpp"

void InitImage(png::image<png::rgb_pixel> image, auto options){
  int acc_max =  toml::find<int>(options, "acc_max");
  const auto d = toml::find(options, "depart");
  int d1 = toml::find<int>(d,"y");
  int d2 = toml::find<int>(d,"x");
  std::vector<int> couleur_arrivee = toml::find<std::vector<int>>(options,"couleur_arrivee");;

  for (png::uint_32 y = 0; y < image.get_height(); ++y){
    for (png::uint_32 x = 0; x < image.get_width(); ++x){
      if((int) y == d1 && (int) x == d2){
        std::cout<<"Départ en : ["<< x << ";" << y << "]"<<std::endl;
      }

      else if (image[y][x].red == couleur_arrivee.at(0) && image[y][x].green == couleur_arrivee.at(1) && image[y][x].blue == couleur_arrivee.at(2)){
        std::cout<<"Arrivée en : ["<< x << ";" << y << "]"<<std::endl;
      }
    }
  }

  image.write("output.png");

};
