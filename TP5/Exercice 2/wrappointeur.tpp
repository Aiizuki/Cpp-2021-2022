template <typename T>
WrapPointeur<T>::WrapPointeur(){
  this->valeur = 0;
}

template <typename T>
WrapPointeur<T>::~WrapPointeur(){
  delete *(this->valeur);
  delete this->valeur;
}
