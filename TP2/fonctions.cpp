#include "fonction.hpp"


Point::Point(){
  this->x = 0;
  this->y=0;
}

Point::Point(double x, double y){
  this->x = x;
  this->y = y;
}

void Point::PrintPoint(){
    std::cout << "[" << x << "," << y << "]" << "\n";
}

int Point::getPointX(){
  return this->x;
}

int Point::getPointY(){
  return this->y;
}

bool Point::operator==(Point p){
  if(p.getPointX() == this->x && p.getPointY() == this->y){
    return true;
  }

  else{
    return false;
  }
}

///////////////////////////////////////////////////////////////////////////////

kmeans::kmeans(int nbP, int nbC){
  for(int i=0; i<=nbP; i++){
    double abscisse  = rand();
    double ordonnee = rand();
    this->v1.push_back(Point(abscisse,ordonnee));
  }
  this->nbCluster = nbC;
}

void kmeans::setVector(std::vector<Point> vector){
  this->v1=vector;
}

std::vector<Point> kmeans::getListe(){
  return this->liste_centroides;
}

void kmeans::intialiser(){
  int nbC = this->nbCluster;
  std::vector<Point> dejavu;
  std::vector<Point>::iterator it;
  bool PasDeNvCentre = true;
  for(int i=0; i<=nbC;i++){
    while(PasDeNvCentre){
      Point nvCentre = this->v1.at(rand()%v1.size());
      it = find(dejavu.begin(), dejavu.end(), nvCentre);
      if(it != dejavu.end() || dejavu.size()==0){
        this->liste_centroides.push_back(nvCentre);
        dejavu.push_back(nvCentre);
        PasDeNvCentre = false;
      }
    }
    PasDeNvCentre = true;
  }
}

void kmeans::calculer(int iter){
  int dist_min = 99999;
  std::vector<float> abscisses_moy(nbCluster,0);
  std::vector<float> ordonnee_moy(nbCluster,0);
  std::vector<int> nbPts(nbCluster,0);
  for(int i=0; i<iter; i++){
    for(unsigned int j=0; j<this->v1.size(); j++){

      for(int k=0; k<=this->nbCluster; k++){
        if(sqrt((liste_centroides[k].getPointX() - v1.at(j).getPointX()) + (liste_centroides[k].getPointY() - v1.at(j).getPointY())) < dist_min){
          this->m1[j] = k;
          dist_min = sqrt((liste_centroides[k].getPointX() - v1.at(j).getPointX()) + (liste_centroides[k].getPointY() - v1.at(j).getPointY()));
        }
      }
    }
    for(int n=0; n<=this->nbCluster; n++){
      for (unsigned int m=0; m<this->m1.size(); m++){
        if(this->m1[m] == n){
          abscisses_moy[n] += (float) this->v1.at(m).getPointX();
          ordonnee_moy[n] +=(float) this->v1.at(m).getPointY();
          nbPts[n] += 1;
        }
      }
      liste_centroides[n] = Point(abscisses_moy[n]/nbPts[n], ordonnee_moy[n]/nbPts[n]);
    }
  }
}

void kmeans::afficher(){
  int abscisse_max = 0;
  int ordonnee_max = 0;
  for(unsigned int i=0; i< this->v1.size(); i++){
    if(this->v1.at(i).getPointX() > abscisse_max){
      abscisse_max = this->v1.at(i).getPointX();
    }

    else if(this->v1.at(i).getPointY() > ordonnee_max){
      ordonnee_max = this->v1.at(i).getPointY();
    }
  }

  for(int y=0; y<=ordonnee_max+1;y++){
    if(y==0 || y==ordonnee_max+1){
      for(int p=0; p<=abscisse_max; p++){
        std::cout << " = ";
      }
    }

    else{
      for(int x=1; x<abscisse_max;x++){
        for(unsigned int k=0; k<this->v1.size();k++){
          if(this->v1.at(k).getPointX() == x && this->v1.at(k).getPointY() == y){
            std::cout << "x";
          }

          else{
            std::cout<<" ";
          }
        }

        for(int v=0; v<this->nbCluster; v++){
          if(liste_centroides[v].getPointX()==x && liste_centroides[v].getPointY()==y){
            std::cout << "&";
          }
          else{
            std::cout<<" ";
          }
        }
      }
    }
    std::cout<<std::endl;
  }
}
