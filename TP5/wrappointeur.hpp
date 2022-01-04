/*#ifndef WRAPPOINTEUR_HPP
#define WRAPPOINTEUR_HPP

#include <assert.h>
#include "noeud.hpp"

template <typename T>
class WrapPointeur{
  private :
    T* valeur;

  public :
    WrapPointeur(T);
    ~WrapPointeur();
    Noeud<T>* Unwrap();
};




#include "wrappointeur.tpp"


#endif*/
