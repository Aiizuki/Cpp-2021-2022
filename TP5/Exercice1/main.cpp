#include "fonction.hpp"


int main() {

  int valInt = 2;
  int valInt2 = 5;

  std::cout << "max entre " << valInt <<" et " << valInt2 << " : "<< maxT(valInt,valInt2) << std::endl;

  Rectangle* rec1 = new Rectangle(2,5);

  Rectangle* rec2 = new Rectangle(5,5);
  maxT(*rec1,*rec2);

  vector<int> v(3, 3);

  std::cout << "Somme des points de v :" << somme(v) << "\n";

  free(rec1);
  free(rec2);

  vector<Point>v2(2,Point(2.2, 1.3));

  somme(v2).afficher();


}
