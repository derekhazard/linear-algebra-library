This is a sample of how to compile and run calculations with the linear algebra library.

1. Open terminal
2. Change the directory to match the one that contains this document by typing “cd ../Project_2”
3. Change to c-shell by typing "csh" and hitting return on the command line.
4. Type “source setup.csh” and return on the command line.
5. Then make the library by changing to the library directory by typing	"cd lib/" and hitting return.
6. Change to the same directory as this "readme.txt" file.  Type "cd .." and return on the command line.
7. Make the test run program by typing "make" and hitting return on the command line.
8. Run the test program by typing "./bin/linearAlgebraLibTest" and return on the command line.


Last login: Wed Mar 14 16:40:24 on ttys000
Dereks-MBP:~ derekhazard$ cd Desktop/Project_2/
Dereks-MBP:Project_2 derekhazard$ csh
[Dereks-MBP:~/Desktop/Project_2] derekhazard% source setup.csh 

Setup our new LinearAlgebra Library
===========================

<I>---------------Info--------------------<I>
Setting up the following environments: 
LinearAlgebra:  /Users/derekhazard/Desktop/Project_2/lib
<I>---------------Info--------------------<I>

[Dereks-MBP:~/Desktop/Project_2] derekhazard% cd lib/
[Dereks-MBP:~/Desktop/Project_2/lib] derekhazard% make
g++ -O -fPIC -pipe -Wall   -c -o vecNd.o vecNd.cpp
g++ -O -fPIC -pipe -Wall   -c -o matrixMN.o matrixMN.cpp
Linking libLinearAlgebra.so for Darwin
g++ -dynamiclib -flat_namespace -undefined suppress vecNd.o matrixMN.o -o libLinearAlgebra.so
done
[Dereks-MBP:~/Desktop/Project_2/lib] derekhazard% cd ..
[Dereks-MBP:~/Desktop/Project_2] derekhazard% make
g++ -O -fPIC -pipe -Wall -dynamiclib -I./lib -c src/linearAlgebraLibTest.cpp
clang: warning: argument unused during compilation: '-dynamiclib' [-Wunused-command-line-argument]
g++ -O -Xlinker -bind_at_load -flat_namespace linearAlgebraLibTest.o -L./lib -lLinearAlgebra -o bin/linearAlgebraLibTest
rm linearAlgebraLibTest.o
[Dereks-MBP:~/Desktop/Project_2] derekhazard% ./bin/linearAlgebraLibTest 

Welcome to the linear algebra library testing program.

The magnitude of <2, 4, 5> is 6.7082

The magnitude of <6, 8, 6> is 11.6619

<2, 4, 5> + <6, 8, 6> = <8, 12, 11>

<2, 4, 5> - <6, 8, 6> = <-4, -4, -1>

<2, 4, 5> * <6, 8, 6> = <12, 32, 30>

<2, 4, 5> * 2 = <4, 8, 10>

<2, 4, 5> += <6, 8, 6>
First Vector: <8, 12, 11>
Second Vector: <6, 8, 6>

<8, 12, 11> -= <6, 8, 6>
First Vector: <2, 4, 5>
Second Vector: <6, 8, 6>

<2, 4, 5> *= <6, 8, 6>
First Vector: <12, 32, 30>
Second Vector: <6, 8, 6>

<12, 32, 30> *= 1/3
Vector: <4, 10.6667, 10>

<4, 10.6667, 10> = <6, 8, 6>
First Vector: <6, 8, 6>
Second Vector: <6, 8, 6>


Here are a few matricies

a:
 |   1   3   3  | 
 |   1   4   3  | 
 |   1   3   4  | 


b:
 |   0   0   0  | 
 |   0   0   0  | 
 |   0   0   0  | 


c:
 |   0   2   0   1   0  | 
 |   2   2   3   2  -2  | 
 |   4  -3   0   1  -7  | 
 |   6   1  -6  -5   6  | 


Let's fill b with some random numbers:

b:
 |   0   2   9  | 
 |   0   9   7  | 
 |   9   9   8  | 

Trace of a = 9
Trace of b = 17
Trace of a + b = 26

Determinant of a = 1
Determinant of b = -603
Determinant of a + b = -940

The inverse of a:
 |   7  -3  -3  | 
 |  -1   1   0  | 
 |  -1   0   1  | 

a * a^-1:
 |   1   0   0  | 
 |   0   1   0  | 
 |   0   0   1  | 

The transpose of a:
 |   1   1   1  | 
 |   3   4   3  | 
 |   3   3   4  | 

Let's demonstrate the +, -, and * operators:

a + b = 
 |    1    5   12  | 
 |    1   13   10  | 
 |   10   12   12  | 

a - b = 
 |   1   1  -6  | 
 |   1  -5  -4  | 
 |  -8  -6  -4  | 

a * 2 = 
 |   2   6   6  | 
 |   2   8   6  | 
 |   2   6   8  | 

a * b = 
 |   27   56   54  | 
 |   27   65   61  | 
 |   36   65   62  | 


Let's demonstrate the +=, -=, and *= operators:

a:
 |   1   3   3  | 
 |   1   4   3  | 
 |   1   3   4  | 

b:
 |   0   2   9  | 
 |   0   9   7  | 
 |   9   9   8  | 

a += b

a:
 |    1    5   12  | 
 |    1   13   10  | 
 |   10   12   12  | 


b:
 |   0   2   9  | 
 |   0   9   7  | 
 |   9   9   8  | 

a -= b

a:
 |   1   3   3  | 
 |   1   4   3  | 
 |   1   3   4  | 


b:
 |   0   2   9  | 
 |   0   9   7  | 
 |   9   9   8  | 

a *= b

a:
 |   27   56   54  | 
 |   27   65   61  | 
 |   36   65   62  | 


b:
 |   0   2   9  | 
 |   0   9   7  | 
 |   9   9   8  | 

a *= 2

a:
 |   54   112   108  | 
 |   54   130   122  | 
 |   72   130   124  | 

Performing Gauss Elimination on c yields:
 |  6.000  1.000 -6.000 -5.000   6.000  | 
 |  0.000 -3.667  4.000  4.333 -11.000  | 
 |  0.000  0.000  6.818  5.636  -9.000  | 
 |  0.000  0.000  0.000  1.560  -3.120  | 


Performing Gauss Jordan Elimination on c yields:
 |  1.000  0.000  0.000  0.000 -0.500  | 
 |  0.000  1.000  0.000  0.000  1.000  | 
 |  0.000  0.000  1.000  0.000  0.333  | 
 |  0.000  0.000  0.000  1.000 -2.000  | 

[Dereks-MBP:~/Desktop/Project_2] derekhazard% 
