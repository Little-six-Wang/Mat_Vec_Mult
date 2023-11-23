FILENAME = mpi
COMPARE = test
SUB = subtest
export OBJ = test
Res = vec_sum
INCLUDE = -I./subtest/include
thread_count = 1

objects = get_input.o Read_vector.o Print_vector.o Mat_vect_mult.o vec_sum.o createMatrix.o

%.o:%.c
	mpicc $(INCLUDE) -c $< -o $@
$(Res):$(objects) 
	mpicc -g -lm -Wall -o $@ $(objects)	

clean:
	rm -f *.o $(Res) $(SUB)/*.o $(SUB)/$(OBJ)

run:
	make
	make -C $(SUB)
	echo "version = '$(FILENAME)';" > output_$(FILENAME).m
	echo "version = '$(COMPARE)';" > output_$(COMPARE).m
	mpiexec -n $(thread_count) ./vec_sum >> output_$(FILENAME).m
	./$(SUB)/$(OBJ) >> output_$(COMPARE).m
	make clean
