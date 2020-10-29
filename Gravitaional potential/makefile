all: Esercizio3.3
Esercizio3.3: Esercizio3.3.o particella.o posizione.o 
	g++ Esercizio3.3.o particella.o posizione.o -o Esercizio3.3
Esercizio3.3.o: Esercizio3.3.cc particella.h posizione.h
	g++ -c Esercizio3.3.cc -o Esercizio3.3.o
particella.o : particella.cc particella.h
	g++ -c particella.cc -o particella.o
posizione.o : posizione.cc posizione.h
	g++ -c posizione.cc -o posizione.o
clean:
	rm *.o Esercizio3.3
	
