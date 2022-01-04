CPP := g++
CFLAGS := -std=c++98 -Wall -Wextra -pedantic -ggdb -Wno-unused-variable -Wno-unused-parameter
FICHIER := main
COMPOSANTS_1 :=
COMPOSANTS_2 :=

all : $(FICHIER)

$(FICHIER) : $(FICHIER).o # $(COMPOSANTS_2).o
	$(CPP) $(CFLAGS) -o $@ $^


%.o : %.cpp
	$(CPP) $(CFLAGS) -o $@ -c $<

clean :
	rm *.o  $(FICHIER)

run : $(FICHIER)
	./$(FICHIER)

VFLAGS := --leak-check=full

memoire_exercice1 : $(FICHIER)
	valgrind $(VFLAGS) ./$(FICHIER)
