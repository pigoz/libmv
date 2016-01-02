all: default

.PHONY: configure test default

configure:
	mkdir -p build
	cd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=on ..

test: default
	cd build && ctest -V

default:
	cd build && make
