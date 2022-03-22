#include "fonction.hpp"

using namespace std;
int main() {

  Table_Hachage<char,int> Table(10);
  Table.inserer(1,'a');
  Table.inserer(11,'B');
  Table.inserer(21,'C');
  Table.acces(1);
  Table.acces(11);
  Table.supprimer(21);
  Table.supprimer(1);
}
