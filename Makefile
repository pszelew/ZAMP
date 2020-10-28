__start__: obj interp __plugin__
	export LD_LIBRARY_PATH="./libs"; ./interp plik.txt

obj:
	mkdir obj

__plugin__:
	cd plugin; make

CPPFLAGS=-Wall -pedantic -std=c++11 -Iinc
LDFLAGS=-Wall

interp: obj/main.o obj/LibraryInterface.o obj/Parser.o
	g++ ${LDFLAGS} -o interp  obj/main.o obj/LibraryInterface.o obj/Parser.o -ldl

obj/main.o: src/main.cpp inc/Interp4Command.hh inc/LibraryInterface.hh
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Parser.o: src/Parser.cpp inc/Parser.hh
	g++ -c ${CPPFLAGS} -o obj/Parser.o src/Parser.cpp

obj/Cuboid.o: src/Cuboid.cpp inc/Cuboid.hh inc/MobileObject.hh inc/Vector3D.hh inc/Vector2D.hh
	g++ -c ${CPPFLAGS} -o obj/Cuboid.o src/Cuboid.cpp

obj/LibraryInterface.o: src/LibraryInterface.cpp inc/LibraryInterface.hh inc/Interp4Command.hh
	g++ -c ${CPPFLAGS} -o obj/LibraryInterface.o src/LibraryInterface.cpp


clean:
	rm -f obj/* interp core*


clean_plugin:
	cd plugin; make clean

cleanall: clean
	cd plugin; make cleanall
	cd dox; make cleanall
	rm -f libs/*
	find . -name \*~ -print -exec rm {} \;

help:
	@echo
	@echo "  Lista podcelow dla polecenia make"
	@echo 
	@echo "        - (wywolanie bez specyfikacji celu) wymusza"
	@echo "          kompilacje i uruchomienie programu."
	@echo "  clean    - usuwa produkty kompilacji oraz program"
	@echo "  clean_plugin - usuwa plugin"
	@echo "  cleanall - wykonuje wszystkie operacje dla podcelu clean oraz clean_plugin"
	@echo "             oprocz tego usuwa wszystkie kopie (pliki, ktorych nazwa "
	@echo "             konczy sie znakiem ~)."
	@echo "  help  - wyswietla niniejszy komunikat"
	@echo
	@echo " Przykladowe wywolania dla poszczegolnych wariantow. "
	@echo "  make           # kompilacja i uruchomienie programu."
	@echo "  make clean     # usuwa produkty kompilacji."
	@echo
 
