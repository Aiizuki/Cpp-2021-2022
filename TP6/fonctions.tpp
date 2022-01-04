template <typename T, typename U>
Emplacement<T,U>::Emplacement(){
  this->cle = NULL;
  this->valeur = NULL;
  this->suivant = NULL;
}

template <typename T, typename U>
Emplacement<T,U>::Emplacement(T _valeur, U _cle){
  this->cle= _cle;
  this->valeur= _valeur;
  this->suivant = NULL;
}

template <typename T, typename U>
Emplacement<T,U>::~Emplacement(){
}

template <typename T, typename U>
U Emplacement<T,U>::getCle(){
  return this->cle;
}

template <typename T, typename U>
T Emplacement<T,U>::getValeur(){
  return this->valeur;
}

template <typename T, typename U>
Emplacement<T,U>* Emplacement<T,U>::getSuivant(){
  return this->suivant;
}

template <typename T, typename U>
void Emplacement<T,U>::setCle(U cle_){
  this->cle = cle_;
}

template <typename T, typename U>
void Emplacement<T,U>::setValeur(T valeur_){
  this->valeur = valeur_;
}

template <typename T, typename U>
void Emplacement<T,U>::setSuivant(Emplacement<T,U>* emplacement_){
  this->suivant = emplacement_;
}




template <typename T, typename U>
Table_Hachage<T,U>::Table_Hachage(size_t size){
  for(unsigned int i=0;i<size;i++){
    table.push_back(new Emplacement<T,U>());
  }
}

template <typename T, typename U>
Table_Hachage<T,U>::~Table_Hachage(){
  for(unsigned int i=0; i<table.size();i++){
    delete this->table.at(i);
  }
}

template <typename T, typename U>
bool Table_Hachage<T,U>::acces(const U &cle){
  assert(this->table.size() > 0);
  int index = cle%this->table.size();
  Emplacement<T,U>* zone = this->table.at(index);
  while (zone->getCle() != cle) {
    if(zone->getSuivant() == NULL){
      std::cout<<"La clé indiquée n'existe pas !"<<"\n";
      return true;
    }
    zone = zone->getSuivant();
  }
  std::cout<<"Clé: "<<cle<<" | "<<"Valeur: "<<zone->getValeur()<<"\n";
  return true;
}


template <typename T, typename U>
void Table_Hachage<T,U>::supprimer(const U &cle){
  assert(this->table.size() > 0);
  int index = cle%this->table.size();
  Emplacement<T,U>* zone = this->table.at(index);
  while(zone->getCle() != cle){
    if(zone->getSuivant() == NULL){
      std::cout<<"La clé indiquée n'existe pas !"<<"\n";
    }
    zone = zone->getSuivant();
  }
}


template <typename T, typename U>
void Table_Hachage<T,U>::inserer(const U &cle, const T &valeur){
  int index = cle%this->table.size();
  if(this->table.at(index)->getCle() == NULL){
    this->table.at(index)->setCle(cle);
    this->table.at(index)->setValeur(valeur);
    this->table.at(index)->setSuivant(NULL);
  }
  Emplacement<T,U>* zone = this->table.at(index);
  while (zone->getCle() != cle){
    if(zone->getSuivant() == NULL){
      Emplacement<T,U>* newE = new Emplacement<T,U>(valeur,cle);
      zone->setSuivant(newE);
    }
    zone = zone->getSuivant();
  }
}
