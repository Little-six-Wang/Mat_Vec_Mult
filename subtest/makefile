DEP = createMatrix_Test.o test.o dclock.o
INCLUDE = -I./include
%.o:%.c
	gcc $(INCLUDE) -c $< -o $@
$(OBJ):$(DEP)
	gcc -o $@ $(DEP)
