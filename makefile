objects = get_input.o Read_vector.o Print_vector.o Mat_vect_mult.o vec_sum.o createMatrix.o

%.o:%.c
	mpicc -c $< -o $@
vec_sum:$(objects)
	mpicc -g -lm -Wall -o vec_sum $(objects)
	

clean:
	rm -f *.o

run:
	make
	#make clean
	mpiexec -n 16 ./vec_sum
