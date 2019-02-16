CFALGS = -I ./lib
LIB_OBJS = test.o sort.o

test: test.o sort.o
	${CC} -o $@ ${LIB_OBJS}

test.o: test.c
	${CC} -c test.c ${CFALGS}

clean:
	-rm *.o test
