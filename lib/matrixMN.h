//
//  matrixMN.h
//  inclass
//
//  Created by Derek Hazard on 3/2/14.
//  Copyright (c) 2014 Derek Hazard. All rights reserved.
//

#ifndef __inclass__matrixMN__
#define __inclass__matrixMN__

#include <vector>
class vecNd;

// Matrix class
class matrixMN {
    
private:
    
    bool fail_bit;
    int mdim;
    int ndim;
    std::vector<std::vector<double> > matrix;
    
public:
    
    // constructor
    matrixMN();                                                                 //default
    
    matrixMN(double m0n0, double m0n1,                                          // user defined 2x2 constructor
             double m1n0, double m1n1);
    
    matrixMN(double m0n0, double m0n1, double m0n2,                             // User defined 3x3 constructor
             double m1n0, double m1n1, double m1n2,
             double m2n0, double m2n1, double m2n2);
    
    matrixMN(double m0n0, double m0n1, double m0n2, double m0n3,                // User defined 4x4 constructor
             double m1n0, double m1n1, double m1n2, double m1n3,
             double m2n0, double m2n1, double m2n2, double m2n3,
             double m3n0, double m3n1, double m3n2, double m3n3);
    
    matrixMN(double m0n0, double m0n1, double m0n2, double m0n3, double m0n4,   // User defined 5x5 constructor
             double m1n0, double m1n1, double m1n2, double m1n3, double m1n4,
             double m2n0, double m2n1, double m2n2, double m2n3, double m2n4,
             double m3n0, double m3n1, double m3n2, double m3n3, double m3n4,
             double m4n0, double m4n1, double m4n2, double m4n3, double m4n4);
    
    matrixMN(double m0n0, double m0n1, double m0n2,                             // User defined 2x3 constructor
             double m1n0, double m1n1, double m1n2);
    
    matrixMN(double m0n0, double m0n1, double m0n2, double m0n3,                // User defined 3x4 constructor
             double m1n0, double m1n1, double m1n2, double m1n3,
             double m2n0, double m2n1, double m2n2, double m2n3);
    
    matrixMN(double m0n0, double m0n1, double m0n2, double m0n3, double m0n4,   // User defined 4x5 constructor
             double m1n0, double m1n1, double m1n2, double m1n3, double m1n4,
             double m2n0, double m2n1, double m2n2, double m2n3, double m2n4,
             double m3n0, double m3n1, double m3n2, double m3n3, double m3n4);
             
    matrixMN(int M, int N);                                                     // User defined MxN constructor
    
    
    // Copy constructor
    matrixMN(matrixMN & a);
    
    
    // Destructor
    virtual ~matrixMN();
    
    
    //operators
    matrixMN operator = (matrixMN & a);                                         // Matrix assignment
    matrixMN operator + (matrixMN & a);                                         // Matrix addition
    matrixMN operator - (matrixMN & a);                                         // Matrix subtraction
    matrixMN operator * (matrixMN & a);                                         // Matrix multiplication
    matrixMN operator * (double k);                                             // Scalar multiplication
    matrixMN operator += (matrixMN & a);                                        // Matrix addition assignment
    matrixMN operator -= (matrixMN & a);                                        // Matrix subtraction assignment
    matrixMN operator *= (matrixMN & a);                                        // Matrix multiplication assignment
    matrixMN operator *= (double k);                                            // Scalar multiplication assignment
    
    
    // Setter functions
    matrixMN SetElement(int M, int N, double val = 0);                          // Set value of individual elements
    matrixMN SetIdentity();                                                     // Set a square matrix to identity
    matrixMN SetZero();                                                         // Set all matrix elements to zero
    
    
    // Getter functions
    int GetM() {return mdim;}
    int GetN() {return ndim;}
    double GetElement(int M, int N);
    
    
    // Member functions
    double Determinant();
    double Trace();
    matrixMN Clear() {fail_bit = false; return * this;}
    matrixMN Print(int precision = 2);
    matrixMN Transpose();
    matrixMN Inverse();
    matrixMN GaussElimination();
    matrixMN GaussJordanElimination();
};

#endif /* defined(__inclass__matrixMN__) */
