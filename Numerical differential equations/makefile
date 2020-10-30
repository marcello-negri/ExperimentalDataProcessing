LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all: Esercizio10.4
Esercizio10.4: Esercizio10.4.cc vettore.o funzionevettoriale.o eqDifferenziale.o
	g++ -Wall -o $@ $^ ${INCS} ${LIBS}
%.o: %.cc %.h
	g++ -Wall -c -o $@ $< ${INCS} 
clean:
	rm *.o Esercizio10.4
