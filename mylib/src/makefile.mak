all:
	del *.obj
	ccpsx -c -O3 -Xo$80010000 *.c