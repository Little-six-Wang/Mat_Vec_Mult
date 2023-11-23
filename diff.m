output_mpi
version_mpi = version
Result_Mpi = Result
secMpi = sec

output_test
version_test = version
Result_Test = Result
secTest = sec

diff = max(max(abs(Result_Mpi - Result_Test)))
result = [diff, secTest, secMpi]
save result.txt result

clear all
close all
