all: geom

geom: geom.c
	gcc -Wall -o geom geom.c
run:
	./geom
delete:
	rm geom

