.DEFAULT_GOAL := run

config:
	mkdir -p build
	cd build && cmake -G "Unix Makefiles" -D CMAKE_C_COMPILER=C:/cygwin64/bin/gcc.exe -D CMAKE_CXX_COMPILER=C:/cygwin64/bin/g++.exe ..

build: config
	cmake --build build

run: build
	cd build && ./*.exe

clean:
	rm -rf build

