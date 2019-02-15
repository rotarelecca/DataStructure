CC = gcc
LIB_OBJS = test.o sort.o

test: ${LIB_OBJS}
	${CC} -o $@ ${LIB_OBJS}

sort.o: sort.c algorithm.h
	${CC} -c sort.c algorithm.h

test.o: test.c algorithm.h
	${CC} -c test.c algorithm.h

clean:
	-rm -f *.o *.gch test
