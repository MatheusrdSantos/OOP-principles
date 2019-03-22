PROG = exec
CC = g++
CPPFLAGS = -O0 -Wall -std=c++11
OBJS = main.o Player.o Dice.o GameController.o

$(PROG):$(OBJS)
	$(CC) -o $(PROG) $(OBJS)
	make clean
main.o:
	$(CC) $(CPPFLAGS) -c main.cpp
Player.o: Player.h
	$(CC) $(CPPFLAGS) -c Player.cpp
GameController.o: GameController.h
	$(CC) $(CPPFLAGS) -c GameController.cpp
Dice.o: Dice.h
	$(CC) $(CPPFLAGS) -c Dice.cpp
clean:
	#rm -f core $(PROG) $(OBJS)
	rm -f core $(OBJS)