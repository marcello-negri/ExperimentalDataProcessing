LIBS:=`root-config --libs`
INCS:=`root-config --cflags`

all: Esercizio8.3
Esercizio8.3: Esercizio8.3.cc random.o vettore.o
	g++ -Wall -o $@ $^ ${INCS} ${LIBS}
%.o: %.cc %.h
	g++ -Wall -c -o $@ $< ${INCS} 
clean:
	rm *.o Esercizio8.3
