#ifndef FONCTION_H
#define FONCTION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <vector>
#include <string>
#include <iostream>
#include <assert.h>


template <typename T, typename U>
class Emplacement{
  private:
    U cle;
    T valeur;
    Emplacement<T,U>* suivant;

  public:
    Emplacement();
    Emplacement(const T valeur_, const U cle);
    U getCle();
    void setCle(U cle);
    T getValeur();
    void setValeur(T valeur);
    Emplacement<T,U>* getSuivant();
    void setSuivant(Emplacement<T,U>* emplacement_);
    ~Emplacement();
};

template<typename T, typename U>
class Table_Hachage{
  private:
    U cle;
    T valeur;
    std::vector<Emplacement<T,U>*> table;
    size_t size;
  public:
    Table_Hachage(size_t size);
    bool acces(const U &cle);
    void inserer(const U &cle, const T &valeur);
    void supprimer(const U &cle);
    ~Table_Hachage();
};






























#include "fonctions.tpp"


#endif
