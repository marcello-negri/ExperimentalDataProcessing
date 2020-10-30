all: Esercizio5.3

Esercizio5.3: Esercizio5.3.cc funzione.o solutore.o
	g++ -Wall -o $@ $^

%.o: %.cc %.h
	g++ -Wall -c -o $@ $<

clean:
	rm *.o Esercizio5.3
