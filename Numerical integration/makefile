all: Esercizio7.2
Esercizio7.2: Esercizio7.2.cc funzione.o integrale.o
	g++ -Wall -o $@ $^
%.o: %.cc %.h
	g++ -Wall -c -o $@ $<
clean:
	rm *.o Esercizio7.2
