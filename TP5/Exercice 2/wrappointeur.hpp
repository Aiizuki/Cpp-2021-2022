#ifndef WRAPPOINTEUR_HPP
#define WRAPPOINTEUR_HPP

#include <assert.h>
#include "noeud.hpp"

template <typename T>
class WrapPointeur{
  private :
    T* valeur;

  public :
    WrapPointeur();
    ~WrapPointeur();
};




#include "wrappointeur.tpp"


#endif
