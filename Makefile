.PHONY: build run test clean

build:
	cmake --preset unix-debug
	cmake --build --preset unix-debug

run: build
	./build/unix-debug/raytracer

test: build
	ctest --preset unix-debug

clean:
	cmake -E rm -rf build
