#ifndef LISTE_HPP
#define LISTE_HPP

#include <assert.h>
#include "noeud.hpp"

template< typename T >
class Liste {

    private:
        struct Noeud<T>* tete; /* Premier élément de la liste */
        struct Noeud<T>* queue; /* Dernier élément de la liste */
        size_t taille; /* Nombre d'éléments dans la liste */

    public:
        Liste();
        Liste(T);
        ~Liste();

        void ajouter_fin(T);
        void supprimer_fin();

        T& operator[](size_t);

        /* Hypothèse : T n'est pas un pointeur */
        template< typename U >
        friend std::ostream& operator<<(std::ostream&, const Liste<U> &);

};

#include "liste.tpp"

#endif
