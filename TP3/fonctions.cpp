#include "fonction.hpp"


Terrain::Terrain(char pelouse, int longueur, int largeur){
  this->pelouse = pelouse;
  this->longeur = longueur;
  this->largeur = largeur;
}

Terrain::Terrain(){
  this->longeur = 0;
  this->largeur = 0;
}

Terrain_Rugby::Terrain_Rugby(char pelouse, int longeur, int largeur):Terrain(pelouse, longeur, largeur){
}


void Terrain::build_pelouse(){
  for(int j=1; j<=this->largeur;j++){
    std::string ligne = "";
    ligne += "*";
    for(int i=1; i<=this->longeur; i++){
      if(j==1 || j==this->largeur){
        ligne += "*";
      }


      else{
        ligne += this->pelouse;
      }
    }
    ligne +="*";
    builded_terrain.push_back(ligne);
  }
}

void Terrain::afficher_pelouse(){
  for (int i=0; i<=this->builded_terrain.size();i++){
    std::cout<<builded_terrain[i]<<"\n";
  }
}

void  Terrain_Rugby::dessiner_logo(){
  std::cout<<"rugby";
}

void Terrain_Rugby::build_pelouse_rugby(){
  Terrain::build_pelouse();
  int j =0;
  int mid;
  int milieu = this->builded_terrain[0].size() /2-1;
  for(int i=0; i<this->builded_terrain.size();i++){
    this->builded_terrain[i].replace(milieu,1,"*");
    if(i>this->builded_terrain.size()/4 && i<this->builded_terrain.size()-this->builded_terrain.size()/4){
      if(i<this->builded_terrain.size()/2){
        this->builded_terrain[i].replace(milieu-(i-this->builded_terrain.size()/4),1,"0");
        this->builded_terrain[i].replace(milieu+(i-this->builded_terrain.size()/4),1,"0");
      }

      else if(i==this->builded_terrain.size()/2){
        mid = i;
        this->builded_terrain[i].replace(milieu-(i-this->builded_terrain.size()/4),1,"0");
        this->builded_terrain[i].replace(milieu+(i-this->builded_terrain.size()/4),1,"0");
      }
      else{
        this->builded_terrain[i].replace(milieu-(mid-(this->builded_terrain.size()/4+j)),1,"0");
        this->builded_terrain[i].replace(milieu+(mid-(this->builded_terrain.size()/4+j)),1,"0");
        j += 1;
      }
    }
  }

}
