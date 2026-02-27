CPPFLAGS = g++ ./src/main.cpp -I./include/ -o ./bin/wcTest.exe
ARGS := "nothing"

default:
	@echo "you passed $(ARGS)"
	@./bin/utils/vic.exe
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

vic:
	g++ ./src/vic.cpp -o ./bin/utils/vic.exe