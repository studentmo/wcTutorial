CPPFLAGG = g++ -g -Wall
ARGS:=""

standard: cleanExe OFile
	$(CPPFLAGG) src/*.o -Iinclude/ -o bin/Debug_main.exe

main: src/main.cpp include/extra.hpp
	$(CPPFLAGG) -c src/main.cpp -Iinclude/ -o src/main.o

argcProc: src/argcProc.cpp include/extra.hpp
	$(CPPFLAGG) -c src/argcProc.cpp -Iinclude/ -o src/argcProc.o

fileCount: src/fileCount.cpp include/extra.hpp
	$(CPPFLAGG) -c src/fileCount.cpp -Iinclude/ -o src/fileCount.o

resultOutput: src/resultOutput.cpp include/extra.hpp
	$(CPPFLAGG) -c src/resultOutput.cpp -Iinclude/ -o src/resultOutput.o

vic:
	$(CPPFLAGG) ./src/vic.cpp -o ./bin/utils/vic.exe

OFile: main argcProc fileCount resultOutput

test: standard
	./bin/Debug_main.exe $(ARGS)

gdb_test: standard 
	gdb ./bin/Debug_main.exe $(ARGS)

vicExe:
	./bin/utils/vic.exe $(ARGS)

cleanAll:
	rm -f bin/*.exe
	rm -f src/*.o

cleanExe:
	rm -f bin/*.exe

realease: OFile
	$(CPPFLAGG) src/*.o -Iinclude/ -o bin/Main.exe

update: cleanAll vicExe realease
	git add -A
	git commit