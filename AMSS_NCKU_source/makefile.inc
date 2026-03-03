filein  = -I/usr/include/ -I/usr/lib/x86_64-linux-gnu/openmpi/include/ -I/usr/lib/x86_64-linux-gnu/openmpi/lib/ -I/usr/lib/gcc/x86_64-linux-gnu/11/ -I/usr/include/c++/11/
LDLIBS  = -L/usr/lib/x86_64-linux-gnu -L/usr/lib64 -L/usr/lib/gcc/x86_64-linux-gnu/11 -lgfortran -lmpi

# 🌟 PGO 冲刺模式：使用 -fprofile-use 激活基于真实运行数据的编译器极限优化
OPT_FLAGS = -O3 -march=znver4 -flto -fprefetch-loop-arrays -funroll-loops -fprofile-use

CXXAPPFLAGS  = $(OPT_FLAGS) -Wno-deprecated -Dfortran3 -Dnewc -std=c++14
f90appflags  = $(OPT_FLAGS) -x f95-cpp-input
f90          = mpif90
f77          = mpif90
CXX          = mpicxx
CC           = mpicc
CLINKER      = mpicxx
Cu = nvcc
CUDA_LIB_PATH = 
CUDA_APP_FLAGS = -c -g -O3 --ptxas-options=-v -Dfortran3 -Dnewc
