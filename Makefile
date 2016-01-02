all: default

.PHONY: configure test default

configure:
	mkdir -p build
	cd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=on ..

test:
	cd build && ctest

default:
	cd build && make
