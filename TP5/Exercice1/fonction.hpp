#ifndef FONCTION_HPP
#define FONCTION_HPP

#include <iostream>
#include <list>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
template <class T>


T maxT(T val1, T val2){
  if(val1 > val2){
    return val1;
  }
  else{
    return val2;
  }
}
template<class T>
T somme(vector<T> v){
  T res = T();
  for(unsigned int i = 0; i < v.size(); i ++)
  {
    res = res + v.at(i);
  }
  return res;
}

template<class T>
T tri_panier(vector<T> & v){
  map<T,int> map;
  vector<T> res;

  for(typename vector<T>::iterator it = v.begin(); it != v.end(); it++){
    map[*it] ++;
  }
  for(typename map<T, int>::iterator it = map.begin(); it != map.end(); it++){
    for(size_t i = 0; i < it->second; i++){
      res.push_back(it->first);
    }
  }
  return res;

}

class Rectangle{

private:
  int longueur;
  int hauteur;

public:
  Rectangle(int longueur, int largeur){
    this->longueur = longueur;
    this->hauteur = largeur;
  }

  bool operator> (Rectangle const &other) const;
};

class Point{

private:
  double x;
  double y;

public:


  Point(){
    this->x = 0;
    this->y = 0;
  };

  Point(double x, double y){
    this->x = x;
    this->y = y;
  };

  void operator+=(Point const &p);
  Point operator+ (Point const &p);

  void afficher(){
    std::cout << "[" << x << "," << y << "]" << "\n";
  };

  double getX(){
    return this->x;
  }

  double getY(){
    return this->y;
  }

  ~Point(){
    std::cout << "Destructeur Point." << std::endl;
  };
};

#endif
