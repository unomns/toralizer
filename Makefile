all:
	gcc -Wall -g main.c ./lib/toralizer.c -o toralize

clean:
	rm -rf ./toralize ./*.dSYM
