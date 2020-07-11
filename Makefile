 LIBS=-lsfml-graphics -lsfml-window -lsfml-system
 EXEC := pong

all: $(EXEC)

run: $(EXEC)
		./$(EXEC)

Plate.o: Plate.cpp
			g++ -c Plate.cpp -o Plate.o

Ball.o: Ball.cpp
			g++ -c Ball.cpp -o Ball.o

main.o: main.cpp
			g++ -c main.cpp -o main.o

pong: main.o Plate.o Ball.o
			g++ -o $(EXEC) main.o Plate.o Ball.o $(LIBS)

clean:
			rm pong
			rm  *.o
