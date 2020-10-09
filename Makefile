OBJ=main.o menu.o student.o teacher.o tooler.o
GCC=gcc
main:$(OBJ)
		$(GCC) $^ -o $@
clean:
		rm -rf *.o main



