all: foo.c
	gcc foo.c
run: all
	./a.out
clean:
	rm *~
