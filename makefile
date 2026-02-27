CppF = g++ -Wall -Iinclude/
src = src/main.o src/OutputSystem.o

MinorUpdate: bin/my_wc.exe
	git add bin/my_wc.exe
	rm -f src/*.o
	git commit 
	#Вызвать vic.exe VERSION_MINOR += 1

MajorUpdate: bin/my_wc.exe
	git add bin/my_wc.exe
	rm -f src/*.o
	git commit
	#Вызвать vic.exe VERSION_MAJOR += 1, VERSION_MINOR = 0

bin/my_wc.exe: $(src)
	@$(CppF) src/*.o -o bin/my_wc.exe -g3 -O3 

src/main.o:
	@$(CppF) -c src/main.cpp -o src/main.o	

src/OutputSystem.o:
	@$(CppF) -c src/OutputSystem.cpp -o src/OutputSystem.o	

vic:
	@g++ -Wall ./src/vic.cpp -o ./bin/utils/vic.exe -g3 -O3

test:
	./test.bat

clean:
	rm -f bin/*.exe
	rm -f src/*.o