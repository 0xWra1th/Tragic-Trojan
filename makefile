make:
	g++ -o TragicTrojan.exe TragicTrojan.cpp -DSFML_STATIC -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system -lgdi32 -lwinmm -lopengl32 -lfreetype -lws2_32
	del TragicTrojan.o

run: make
	./TragicTrojan.exe

clean:
	del TragicTrojan.o
	del TragicTrojan.exe
