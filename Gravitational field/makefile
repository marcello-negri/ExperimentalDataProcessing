all: Esercizio4.2
Esercizio4.2: Esercizio4.2.o particella.o posizione.o
	g++ Esercizio4.2.o particella.o posizione.o -o Esercizio4.2
Esercizio4.2.o: Esercizio4.2.cc particella.h posizione.h
	g++ -c Esercizio4.2.cc -o Esercizio4.2.o
particella.o : particella.cc particella.h
	g++ -c particella.cc -o particella.o
posizione.o : posizione.cc posizione.h
	g++ -c posizione.cc -o posizione.o
clean:
	rm *.o Esercizio4.2
	
