#ifndef TERRAIN_HPP
#define TERRAIN_HPP

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <iostream>
#include <vector>
#include <string>

class Terrain{
protected:
  char pelouse;
  int longeur;
  int largeur;
  std::vector<std::string> builded_terrain;

public:
  Terrain();
  Terrain(char pelouse, int longueur, int largeur);
  virtual void build_pelouse();
  virtual void afficher_pelouse();

};

class Terrain_Rugby : public Terrain {
  public:
    Terrain_Rugby(char pelouse, int longeur, int largeur);
    void dessiner_logo();
    void build_pelouse_rugby();
};



































#endif
