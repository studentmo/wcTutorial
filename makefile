CppF = g++ -g -Wall
src = src/main.o

update: bin/my_wc.exe
	git add bin/my_wc.exe
	rm -f src/*.o
	git commit

bin/my_wc.exe: $(src)
	@$(CppF) src/*.o -Iinclude/ $(SDL3) -o bin/my_wc.exe

src/main.o:
	$(CppF) -c src/main.cpp -Iinclude/ $(SDL3) -o src/main.o	

test:
	./bin/my_wc.exe

clean:
	rm -f bin/*.exe
	rm -f src/*.o