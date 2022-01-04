# compilateur
CPP := g++
# options de compilation
CFLAGS := -std=c++98 -Wall -Wextra -pedantic -ggdb -Wno-unused-variable -Wno-unused-parameter
EXO1 := fonction

# all est la cible choisie par défaut par la commande make
# elle dépend de la règle $(EXEC), qui va être réalisée
# NOTE --- les cibles ne doivent pas avoir le même nom qu'un fichier
all : $(EXO1)

$(EXO1) : fonction.o main.o
	$(CPP) $(CFLAGS) -o $@ $^

# règle générale pour la génération des .o
# $(EXEC) dépend de fonctions.o et main.o, qui seront donc exécutés
# via cette règle en premier lieu
%.o : %.cpp
# la génération des fichiers .o dépend de fichiers .c
# (aucune cible ne correspondant à ces derniers, l'instruction est exécutée)
# $< correspond à chaque dépendance prise les unes à la suite des autres
	clear
	$(CPP) $(CFLAGS) -o $@ -c $<

# règle de nettoyage (supprimant les fichiers .o), ne dépendant d'aucune autre règle
clean :
	rm *.o  $(EXO1)

run : $(EXO1)
	./$(EXO1)
