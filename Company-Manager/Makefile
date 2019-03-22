PROG = exec
CC = g++
CPPFLAGS = -O0 -Wall -std=c++11
OBJS = main.o Company.o Controller.o Employee.o Date.o

$(PROG):$(OBJS)
	$(CC) -o $(PROG) $(OBJS)
	make clean
main.o:
	$(CC) $(CPPFLAGS) -c main.cpp
Company.o: Company.h
	$(CC) $(CPPFLAGS) -c Company.cpp
Controller.o: Controller.h
	$(CC) $(CPPFLAGS) -c Controller.cpp
Employee.o: Employee.h
	$(CC) $(CPPFLAGS) -c Employee.cpp
Date.o: Date.h
	$(CC) $(CPPFLAGS) -c Date.cpp
clean:
	#rm -f core $(PROG) $(OBJS)
	rm -f core $(OBJS)