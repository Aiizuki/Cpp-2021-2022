#ifndef FONCTION_HPP
#define FONCTION_HPP

#include <iostream>
#include <png++/png.hpp>
#include "tomlPack/toml.hpp"
#include <bits/stdc++.h>
#include <bitset>
#include <iostream>
#include <stdexcept>
#include <math.h>
 
// Definition d'une structure qui permettra de stocker les parametres d'une cellule
struct cell {
    // i et j stockent la ligne et la colonne du parent
    int parent_i;
    int parent_j;
    // f = g + h
    double f;
    double g;
    double h;
};

// Creation d'une structure permettant de stocker une paire d'entiers
typedef std::pair<int, int> Pair;
 
// Creation d'une structure permettant de stocker une paire d'entiers identifiee par un double
typedef std::pair<double, std::pair<int, int> > pPair;


std::vector<int> CheckArrivee(png::image<png::rgb_pixel> image, auto options); // recherche tous les pixels qui sont de la couleur de l'arrivée et retourne un seul de ces pixels (plus ou moins centré)
std::vector<int> CheckDepart(png::image<png::rgb_pixel> image, auto options); // recherche le pixel de départ en fonction des coordonnées données dans le fichier option

std::vector<Pair> findTraj(png::image<png::rgb_pixel> image, auto options); // permet de calculer une première trajectoire grâce à A*
int** MakeGrid(png::image<png::rgb_pixel> image); // permet de transformer une image en une matrice de collisions

std::string toBinary (int n); // permet de convertir un int en binaire
std::string convert(int x); // permet de convertir un int en binaire signé sur 32bits

std::vector<std::vector<int>> pointToVector(std::vector<Pair> liste_point); //
int distance(int Xa, int Ya, int Xb, int Yb); // permet de calculer la distance entre deux points

bool isValid(int row, int col, int ROW, int COL); // vérifie si le points est accessible
bool isPathable(int** grid, int x0, int y0, int x1, int y1); //verifie si la trajectoire entre deux points ne coupe pas de pixels noirs

bool is_notBlack(Pair point, png::image<png::rgb_pixel> image); // verifie si un pixel est ou est entouré de pixel noirs

bool isUnBlocked(int** grid, int row, int col); // vérifie si un point n'est pas un pixel noir

bool isDestination(int row, int col, Pair dest); // vérifie si le point correspond à l'arrivée
double calculateHValue(int row, int col, Pair dest); 

std::stack<Pair> tracePath(cell** cellDetails, Pair dest); //permet de stocker tous les points du chemin

std::stack<Pair> aStarSearch(int** grid, Pair src, Pair dest, int ROW, int COL, png::image<png::rgb_pixel> image); // algorithme de calcul de trajectoire

std::vector<Pair> Optimizatron(png::image<png::rgb_pixel> image, int** map, std::stack<Pair> trajectoire, auto options); // algorithme qui optimise la trajectoire calculée par A*































#endif
