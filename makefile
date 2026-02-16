CppF = g++ -Wall -Iinclude/
src = src/main.o src/OutputSystem.o

update: bin/my_wc.exe
	git add bin/my_wc.exe
	rm -f src/*.o
	git commit

bin/my_wc.exe: $(src)
	@$(CppF) src/*.o -o bin/my_wc.exe -g3 -O3 

src/main.o:
	$(CppF) -c src/main.cpp -o src/main.o	

src/OutputSystem.o:
	$(CppF) -c src/OutputSystem.cpp -o src/OutputSystem.o	

vic:
	g++ ./src/vic.cpp -o ./bin/utils/vic.exe

test:
	./bin/my_wc.exe

clean:
	rm -f bin/*.exe
	rm -f src/*.o