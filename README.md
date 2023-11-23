# Mat_Vec_Mult
利用MPI来实现矩阵和向量的乘法
# 修改运行时线程的数量
通过修改makefile文件中的`thread_count = 1`这条语句中的来修改
# 输出说明
`output_mpi.m`中存放的是通过mpi计算的结果；`output_test.m`中存放的是通过一般串行程序计算的结果；

`result.txt`中存放的是mpi计算结果与一般串行程序计算结果的误差的绝对值的最大值以及mpi程序运行时间和串行程序运行时间，具体如下：
```
# Created by Octave 8.3.0, Thu Nov 23 17:05:31 2023 CST <taoer@taoer-None>
# name: result
# type: matrix
# rows: 1
# columns: 3
 0 0.30176700000000001 0.28113500000000002
```
0表示最大误差的绝对值为0，第二列表示串行程序运行的时间，第三列表示mpi程序运行时间
# 运行说明
在`vec_sum.c`所在目录下执行：
```
make run
```
在`Octave`中执行：
```
diff
```
