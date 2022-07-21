CPP := g++
CFLAGS := -std=c++17 -fconcepts -Wsign-compare -Wparentheses -Wreturn-type -Wall -Wvla -Wextra -pedantic -ggdb -Wno-unused-variable -Wno-unused-parameter -I /home/etud/o2185673/Documents/Mario_Karthage -I /home/etud/o2185673/include `libpng-config --cflags`
FICHIER := main
COMPOSANTS_1 := fonction
COMPOSANTS_2 :=
LDFLAGS := -L/usr/lib/x86_64-linux-gnu/ `libpng-config --ldflags`

all : $(FICHIER)

$(FICHIER) : $(FICHIER).o # $(COMPOSANTS_1).o
	$(CPP) -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CPP) $(CFLAGS) -o $@ -c $<  $(LDFLAGS)

clean :
	rm *.o  $(FICHIER)

run : $(FICHIER)
	./$(FICHIER)

VFLAGS := --leak-check=full

memoire : $(FICHIER)
	valgrind $(VFLAGS) ./$(FICHIER)
