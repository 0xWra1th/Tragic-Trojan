make:
	g++ -c TragicTrojan.cpp
	g++ TragicTrojan.o -o TragicTrojan -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
	rm TragicTrojan.o

run: make
	./TragicTrojan

clean:
	rm TragicTrojan
