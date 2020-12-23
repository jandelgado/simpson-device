# use this makefile to build with platformio 
#
.PHONY: all clean upload monitor lint ci

all:
	pio run

ci:
	platformio ci -c platformio.ini src/simpson.ino 

lint:
	cpplint --extensions=cpp,h,ino $(shell find src -name "*\.cpp" -o -name "*\.h" -o -name "*\.ino")

clean:
	pio run --target clean

upload:
	pio run --target upload 

monitor:
	pio device monitor

