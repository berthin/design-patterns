clean:
	rm -rf bin lib build

build:
	cmake -H. -Bbuild -GNinja

compile:
	ninja -C build

all:
	make clean
	make build
	make compile
