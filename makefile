CPPFLAGS = g++ ./src/main.cpp -I./include/ -o ./bin/wcTest.exe

default:
	$(CPPFLAGS) -O3 -g3 

release:
	$(CPPFLAGS) -O0 -g0

update: clean
	git add -A
	git commit
	git push


clean:
	@$(RM) ./bin/*.exe
	@$(RM) ./src/*.o
