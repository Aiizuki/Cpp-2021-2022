#include <iostream>
#include <iterator>
using namespace std;

void echanger(int &a, int &b){
  int c = a;
  a = b;
  b = c;
  std::cout << "A : " << a << " " << "|" << " " << "B : " << b << "\n";
}

class Point{
private:
  double x;
  double y;

public:
  Point(){
    this->x = 0;
    this->y=0;
  };

  Point(double x, double y){
    this->x = x;
    this->y = y;
  };

  void PrintPoint(){
    std::cout << "[" << x << "," << y << "]" << "\n";
  };

  ~Point(){
    std::cout << "Destructeur Point." << std::endl;
  }

    Point* droite(Point* p){
    int i =-1 ;
    double abs = x;
    double ord = y;
    int e = p->x - x;
    int dx = e*2;
    int dy = (p->y - y)*2;
    Point* tab = new Point[(int)(p->x-abs)];
    while (abs <= p->x){
      i += 1;
      abs = abs+1;
      e = e-dy;
      if(e <= 0) {
        ord = ord+1;
        e = e+dx;
      }
      tab[i].x = abs;
      tab[i].y = ord;
    }
    return tab;
  }

  void dessiner(Point* p){
    Point* tab = droite(p);
    char** map = new char* [25];
    for(int i =0; i<=25; i++){
      map[i] = new char[25];
      map[i][0] = '#';
      for(int ii=0; ii<=25; ii++){
        map[i][ii]=' ';
      }
      map[i][24] = '#';
    }
    for(int j=0; j<=25; j++){
      map[0][j] = '#';
      map[24][j] = '#';
    }

    for(int k=0; k<=24;k++){
      for(int l=0; l<=24; l++){
        std::cout << map[k][l];
      }
      std::cout << "\n";
    }
  }
};

int main(){
  int x;
  int y;
  std::cin >> x >> y;
  Point* p1 = new Point(x,y);
  Point* p2 = new Point(20,9);
  p1->PrintPoint();
  p1->dessiner(p2);
  delete p1;
  return 0;
}
