clean:
	rm -rf bin lib build

build:
	cmake -H. -Bbuild -GNinja

compile:
	ninja -C build

run:
	./bin/Maze
all:
	make clean
	make build
	make compile
	make run
