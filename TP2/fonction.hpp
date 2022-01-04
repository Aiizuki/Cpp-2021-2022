#ifndef FONCTION_H
#define FONCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <vector>
#include <iostream>
#include <time.h>
#include <map>
#include <algorithm>
#include <math.h>

class Point{
private:
  double x;
  double y;

public:
  Point();
  Point(double x, double y);
  void PrintPoint();
  bool operator==(const Point);
  int getPointX();
  int getPointY();
};

class kmeans {
  private :
  //attributs//
  std::vector<Point> v1;
  std::map<int,int> m1;
  int nbCluster;
  std::vector<Point> liste_centroides;

  public :
  //méthodes//
  kmeans(int nbP, int nbC);
  void intialiser();
  void calculer(int iter);
  void afficher();
  void setVector(std::vector<Point> vector);
  std::vector<Point> getListe();
};


































#endif
