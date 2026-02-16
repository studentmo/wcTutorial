CPPFLAGG = g++ -g -Wall

standard: clean OFile
	$(CPPFLAGG) src/*.o -Iinclude/ -o bin/Debug_main.exe

#extra: src/extra.cpp include/extra.hpp
#	$(CPPFLAGG) -c src/extra.cpp -Iinclude/ -o src/extra.o

main: src/main.cpp include/extra.hpp
	$(CPPFLAGG) -c src/main.cpp -Iinclude/ -o src/main.o

argcProc: src/argcProc.cpp include/extra.hpp
	$(CPPFLAGG) -c src/argcProc.cpp -Iinclude/ -o src/argcProc.o

fileCount: src/fileCount.cpp include/extra.hpp
	$(CPPFLAGG) -c src/fileCount.cpp -Iinclude/ -o src/fileCount.o

resultOutput: src/resultOutput.cpp include/extra.hpp
	$(CPPFLAGG) -c src/resultOutput.cpp -Iinclude/ -o src/resultOutput.o

vic:
	g++ ./src/vic.cpp -o ./bin/utils/vic.exe

OFile: main argcProc fileCount resultOutput
	

test: standard 
	./bin/Debug_main.exe

gdb_test: standard 
	gdb ./bin/Debug_main.exe

clean:
	rm -f bin/*.exe
	rm -f src/*.o

realease: OFile
	$(CPPFLAGG) src/*.o -Iinclude/ -o bin/Main.exe

update: clean realease
	git add -A
	git commit