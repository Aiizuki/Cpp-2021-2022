CPP := g++
CFLAGS := -std=c++14 -Wall -Wextra -pedantic -ggdb -Wno-unused-variable -Wno-unused-parameter -I /home/etud/o2185673/Documents/Mario_Karthage -I /home/etud/o2185673/include `libpng-config --cflags`
FICHIER := main
COMPOSANTS_1 :=
COMPOSANTS_2 :=
LDFLAGS := -L/usr/lib/x86_64-linux-gnu/ `libpng-config --ldflags`

all : $(FICHIER)

$(FICHIER) : $(FICHIER).o # $(COMPOSANTS_2).o
	$(CPP) -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CPP) $(CFLAGS) -o $@ -c $<  $(LDFLAGS)

clean :
	rm *.o  $(FICHIER)

run : $(FICHIER)
	./$(FICHIER)

VFLAGS := --leak-check=full

memoire_exercice1 : $(FICHIER)
	valgrind $(VFLAGS) ./$(FICHIER)
