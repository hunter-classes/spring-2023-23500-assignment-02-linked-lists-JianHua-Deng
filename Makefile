OBJECTS=List.o main.o Node.o OList.o
CXXFLAGS=-g

main: $(OBJECTS)
	g++ -g -o main $(OBJECTS)

List.o: List.cpp Node.h List.h

main.o: main.cpp List.h Node.h OList.o

Node.o: Node.cpp Node.h

OList.o: OList.cpp OList.h Node.h


clean:
	rm -f $(OBJECTS)
