#subdir.mk
#============================================
test.o : test.c test.h
    @echo Building test.c ...
    gcc -Werror -Wall -c test.c -o test.o

main.o : main.c main.h test.h
    @echo Building main.c ...
    gcc -Werror -Wall -c main.c -o main.o
#============================================