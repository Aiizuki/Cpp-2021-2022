# compilateur
CC := g++
# options de compilation
CFLAGS := -std=c++98 -Wall -Wextra -pedantic -ggdb -Wno-unused-variable -Wno-unused-parameter
EX1 := exercice1
LL := liste

# all est la cible choisie par défaut par la commande make
# elle dépend de la règle $(EXEC), qui va être réalisée
# NOTE --- les cibles ne doivent pas avoir le même nom qu'un fichier
all : $(EX1) $(LL)

$(LL) : point.o main.o
	$(CC) $(CFLAGS) -o $@ $^

$(EX1) : point.o exercice1.o
	$(CC) $(CFLAGS) -o $@ $^

# règle générale pour la génération des .o
# $(EXEC) dépend de fonctions.o et main.o, qui seront donc exécutés 
# via cette règle en premier lieu
%.o : %.cpp
# la génération des fichiers .o dépend de fichiers .c 
# (aucune cible ne correspondant à ces derniers, l'instruction est exécutée)
# $< correspond à chaque dépendance prise les unes à la suite des autres 
	clear
	$(CC) $(CFLAGS) -o $@ -c $<

# règle de nettoyage (supprimant les fichiers .o), ne dépendant d'aucune autre règle
clean : 
	rm *.o  $(EX1) $(LL) 

run_exercice1 : $(EX1)
	./$(EX1)

run_liste : $(LL)
	./$(LL)

VFLAGS := --leak-check=full

memoire_exercice1 : $(EX1)
	valgrind $(VFLAGS) ./$(EX1)

memoire_liste : $(LL)
	valgrind $(VFLAGS) ./$(LL)
