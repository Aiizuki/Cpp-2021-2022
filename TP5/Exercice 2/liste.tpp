template< typename T >
Liste<T>::Liste() {
    this->tete = NULL;
    this->queue = NULL;
    this->taille = 0;
}

template< typename T >
Liste<T>::Liste(T _valeur) {
    this->tete = new struct Noeud<T>(_valeur);
    this->queue = this->tete;
    this->taille = 1;
}

template< typename T >
Liste<T>::~Liste() {
    while(this->tete->suivant != NULL){
        struct Noeud<T>* u = this->tete->suivant;
        delete(this->tete);
        this->tete = u;
    }
    delete(this->tete);
}

template< typename T >
void Liste<T>::ajouter_fin(T _valeur) {
    /* Si la liste est vide, création de l'élément de tête */
    if(this->taille==0) {
        this->tete = new struct Noeud<T>(_valeur);
        this->queue = this->tete;
    }
    else{
        this->queue->suivant = new struct Noeud<T>(_valeur);
        this->queue = this->queue->suivant;
    }
    ++this->taille;
}

template< typename T >
void Liste<T>::supprimer_fin() {
    assert(this->taille > 0);
    struct Noeud<T>* u = this->tete;
    while(u->suivant != this->queue){
        u = u->suivant;
    }
    u->suivant = NULL;
    delete(this->queue);
    this->queue = u;
    --this->taille;
}

template< typename T >
T& Liste<T>::operator[](size_t i) {
    assert(i>=0 && i < this->taille);
    struct Noeud<T>* u = this->tete;
    for(unsigned int k = 0; k < i;k++){
        u = u->suivant;
    }
    return u;
}

/* Hypothèse : T n'est pas un pointeur */
template< typename T >
std::ostream& operator<<(std::ostream &os, const Liste<T> &l) {
    struct Noeud<T> *parcours = l.tete;
    os << "[ ";
    for(unsigned int i=0; i<l.taille-1; i++){
        os << parcours->valeur <<" | ";
        parcours = parcours->suivant;
    }
    os << parcours->valeur;
    os << " ]" << std::endl;
    return os;
}
