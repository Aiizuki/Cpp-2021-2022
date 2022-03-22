#include "fonction.hpp"

bool Rectangle::operator> (Rectangle const &other) const{
  if(this->longueur*this->hauteur > other.longueur * other.hauteur){
    std::cout << "Rectangle1 plus grand" << std::endl;
    return true;
  }
  else{
    std::cout << "Rectangle2 plus grand" << std::endl;
    return false;
  }
}

  Point Point::operator+ (Point const &p){
    Point* res = new Point(this->x + p.x, this->y + p.y);
    return *res;
  }
