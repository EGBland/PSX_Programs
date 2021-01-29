all:
	mkdir build
	del build\main.exe
	
	ccpsx -Iinclude -O3 -Xo$80010000 src\*.c lib\*.obj -obuild\main.cpe,build\main.sym,build\mem.map
	cpe2x /ce build\main.cpe
	del build\mem.map
	del build\main.sym
	del build\main.cpe