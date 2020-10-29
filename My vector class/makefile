all: Esercizio6.3
Esercizio6.3: Esercizio6.3.cc vettore.o
	g++ -Wall -o $@ $^
%.o: %.cc %.h
	g++ -Wall -c -o $@ $<
clean:
	rm *.o Esercizio6.3
