main: main.o Node.o BSTree.o
	g++ -o main main.o BSTree.o Node.o

tests: tests.o Node.o BSTree.o
	g++ -o tests tests.o BSTree.o Node.o

main.o: main.cpp BSTree.h Node.h

BSTree.o: BSTree.cpp BSTree.h Node.h

Node.o: Node.cpp Node.h

tests.o: tests.cpp BSTree.h Node.h doctest.h

clean:
	rm -f main main.o BSTree.o Node.o tests.o
