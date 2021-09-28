make:
	g++ -c main.cpp
	g++ main.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
	rm main.o

run:
	./sfml-app

clean:
	rm sfml-app
