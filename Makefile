__start__: obj interp __plugin__
	export LD_LIBRARY_PATH="./libs"; echo;./interp config/commands.cmd config/config.xml

obj:
	mkdir obj

__plugin__:
	cd plugin; make

CPPFLAGS=-Wall -g -pedantic -std=c++17 -Iinc 
LDFLAGS=-Wall

interp: obj/main.o 						 obj/Parser.o obj/Cuboid.o obj/LibraryInterface.o  obj/PluginManager.o  obj/Scene.o obj/Simulation.o  obj/xmlinterp.o obj/ConnectionManager.o
	g++ ${LDFLAGS} -o interp  obj/main.o obj/Parser.o obj/Cuboid.o obj/LibraryInterface.o  obj/PluginManager.o  obj/Scene.o obj/Simulation.o  obj/xmlinterp.o obj/ConnectionManager.o -lxerces-c -lpthread -ldl

obj/main.o: src/main.cpp inc/Simulation.hh inc/Cuboid.hh inc/xmlinterp.hh
	g++ -c ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Parser.o: src/Parser.cpp inc/Parser.hh
	g++ -c ${CPPFLAGS} -o obj/Parser.o src/Parser.cpp

obj/Cuboid.o: src/Cuboid.cpp inc/Cuboid.hh inc/MobileObject.hh inc/Vector3D.hh inc/Vector2D.hh
	g++ -c ${CPPFLAGS} -o obj/Cuboid.o src/Cuboid.cpp

obj/LibraryInterface.o: src/LibraryInterface.cpp inc/LibraryInterface.hh inc/Interp4Command.hh
	g++ -c ${CPPFLAGS} -o obj/LibraryInterface.o src/LibraryInterface.cpp

obj/Scene.o: src/Scene.cpp inc/Scene.hh inc/Scene.hh inc/AccessControl.hh
	g++ -c ${CPPFLAGS} -o obj/Scene.o src/Scene.cpp

obj/PluginManager.o: src/PluginManager.cpp inc/PluginManager.hh inc/LibraryInterface.hh inc/Scene.hh
	g++ -c ${CPPFLAGS} -o obj/PluginManager.o src/PluginManager.cpp

obj/Simulation.o: src/Simulation.cpp inc/Simulation.hh inc/Parser.hh inc/PluginManager.hh inc/Scene.hh
	g++ -c ${CPPFLAGS} -o obj/Simulation.o src/Simulation.cpp

obj/xmlinterp.o: src/xmlinterp.cpp inc/xmlinterp.hh inc/Configuration.hh
	g++ -c ${CPPFLAGS} -o obj/xmlinterp.o src/xmlinterp.cpp

obj/ConnectionManager.o: src/ConnectionManager.cpp inc/ConnectionManager.hh
	g++ -c ${CPPFLAGS} -o obj/ConnectionManager.o src/ConnectionManager.cpp


clean:
	rm -f obj/* interp core*

dox:
	cd dox; make

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
 
