CC=g++
FLAG=-c

all:	main.o Room.o Creature.o NPC.o PC.o Animal.o
	$(CC) main.o Room.o Creature.o NPC.o PC.o Animal.o -o mud
main.o:
	$(CC) $(FLAG) main.cpp
Room.o:
	$(CC) $(FLAG) Room.cpp Room.h
Creature.o:
	$(CC) $(FLAG) Creature.cpp Creature.h
NPC.o:
	$(CC) $(FLAG) NPC.cpp NPC.h
PC.o:
	$(CC) $(FLAG) PC.cpp PC.h
Animal.o:
	$(CC) $(FLAG) Animal.cpp Animal.h

clean:
	rm *.o mud *.gch	
	
