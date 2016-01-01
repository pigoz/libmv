all: default

.PHONY: configure default

configure:
	mkdir -p build
	cd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=on ..

default:
	cd build && make
