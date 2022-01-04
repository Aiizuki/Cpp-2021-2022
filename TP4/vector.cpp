# include <stdlib.h>
# include <assert.h>
# include "vector.hpp"

using namespace std ;

Vector :: Vector ( ) {
  this->element = new float[0];
  this->size = 0;
}

Vector :: Vector ( unsigned int const _size ) {
  this->element = new float[_size];
  this->size = _size;;
  for(unsigned int i=0; i<this->size; i++){
    this->element[i] = 0;
  }
}

Vector :: Vector ( const Vector & v ) {
  this->size = v.size;
  this->element = new float(this->size);
  for(unsigned int i =0; i<this->size;i++){
    this->element[i] = v.element[i];
  }
}


Vector :: ~Vector () {
}


void Vector :: init_alea () {
  for ( unsigned int i = 0 ; i < size ; i++ ) {
    this->element[ i ] = drand48 () ;
  }
}


float & Vector :: operator [] ( unsigned int const i ) {
  if(i>this->size){
    throw invalid_argument("vector too tiny");
  }
  return (* (float *) &this->element[i]) ;
}


float const & Vector :: operator [] ( unsigned int const i ) const {
  if(i>this->size){
    throw invalid_argument("vector too tiny");
  }
  return (* (float *) &this->element[i]) ;
}


std :: ostream & operator << ( std :: ostream& ost ,Vector const & v ) {
  ost << "( ";
  for(unsigned int i=0; i<v.size; i++){
    ost << v[i] << " | ";
  }
  ost << ")";
  ost << endl;
  return ost ;
}


Vector & Vector :: operator = ( Vector const & v ) {
  return ( * this ) ;
}


Vector Vector :: operator + ( Vector const & v ) const {
  Vector vec(v);
  if(this->size != v.size){
    throw invalid_argument("different lenghts");
  }
  for(unsigned int i=0; i<v.size; i++){
    vec[i] = vec[i]+this->element[i];
  }
  return vec ;
}


Vector Vector :: operator - ( Vector const & v ) const {
  Vector vec(v);
  if(this->size != v.size){
    throw invalid_argument("different lenghts");
  }
  for(unsigned int i=0; i<v.size; i++){
    vec[i] = vec[i]-this->element[i];
  }
  return vec ;
}


Vector Vector :: operator * ( float const a ) const {
  Vector vec(this->size);
  for(unsigned int i=0; i<this->size; i++){
    vec.element[i] = this->element[i]*a;
  }
  return vec;
}


float Vector :: operator | ( Vector const & v ) const {
  float result=0;
  for(unsigned int i=0; i<this->size; i++){
    result += this->element[i]*v.element[i];
  }
  return result ;
}


bool Vector :: operator == ( Vector const & v ) const {
  for(unsigned int i=0; i<this->size; i++){
    if(this->element[i] != v.element[i]){
      return false;
    }
  }
  return true;
}


Vector operator * ( float const a ,Vector const & v ) {
  return v*a ;
}
