#ifndef NOEUD_HPP
#define NOEUD_HPP

#include <iostream>

template< typename T >
struct Noeud {
    T valeur;
    struct Noeud* suivant;
    Noeud(T _valeur); 
    ~Noeud();
};

#include "noeud.tpp"

#endif
