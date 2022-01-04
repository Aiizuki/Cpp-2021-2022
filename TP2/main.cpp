#include "fonction.hpp"

int main() {
  srand(time(NULL));

  std::vector<Point> test;
  for(int i=0; i<50; i++){
    test.push_back(Point(rand()%30, rand()%30));
  }

  kmeans* SujetTest = new kmeans(50, 5);
  SujetTest->setVector(test);
  SujetTest->intialiser();
  SujetTest->calculer(5);
  SujetTest->afficher();
  std::vector<Point> liste = SujetTest->getListe();
  for(int k=0; k<=liste.size();k++){
    std::cout<<(liste[k].getPointX(),liste[k].getPointY());
  }


  return EXIT_SUCCESS;
}
