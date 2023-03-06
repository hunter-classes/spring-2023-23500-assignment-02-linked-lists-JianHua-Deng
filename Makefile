OBJECTS=List.o Node.o OList.o
CXXFLAGS=-g

main: main.o $(OBJECTS)
	g++ -g -o main main.o $(OBJECTS)

tests: tests.o $(OBJECTS)
	g++ -g -o tests tests.o $(OBJECTS)

List.o: List.cpp Node.h List.h

tests.o: tests.cpp Node.h OList.o

main.o: main.cpp List.h Node.h OList.o

Node.o: Node.cpp Node.h

OList.o: OList.cpp OList.h Node.h


clean:
	rm -f tests.o main.o $(OBJECTS)
