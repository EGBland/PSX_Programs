all:
	mkdir build
	del build\*.obj
	ccpsx -c -O3 -Xo$80010000 src\*.c