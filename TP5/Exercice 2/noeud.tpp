template< typename T >
Noeud<T>::Noeud(T _valeur) {
    this->valeur = _valeur; 
    suivant = NULL; 
}

template< typename T >
Noeud<T>::~Noeud() {
}
