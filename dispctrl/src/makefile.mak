all:
	del mem.map
	del main.sym
	del main.exe
	del main.cpe
	#cls
	
	ccpsx -O3 -Xo$80010000 *.c -omain.cpe,main.sym,mem.map
	cpe2x /ce main.cpe