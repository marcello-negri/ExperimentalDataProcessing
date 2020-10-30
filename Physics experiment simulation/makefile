LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all: Esercizio9.4
Esercizio9.4: Esercizio9.4.cc random.o funzione.o integrale.o vettore.o esperimento.o
	g++ -Wall -o $@ $^ ${INCS} ${LIBS}
%.o: %.cc %.h
	g++ -Wall -c -o $@ $< ${INCS} 
clean:
	rm *.o Esercizio9.4
