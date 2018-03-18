//
//  vecNd.h
//  inclass
//
//  Created by Derek Hazard on 3/3/14.
//  Copyright (c) 2014 Derek Hazard. All rights reserved.
//

#ifndef __inclass__vecNd__
#define __inclass__vecNd__

class matrixMN;

// Vector class
class vecNd{
    
private:
    
    bool fail_bit;
    int ndim;
    double *n;
    
public:
    
    // constructor
    vecNd();                                //default
    vecNd(double n1, double n2);            // user defined 2d constructor
    vecNd(double n1, double n2, double n3); // User defined 3d constructor
    vecNd(int dim);                         // User defined Nd constructor
    
    // Copy constructor
    vecNd(vecNd & v);
    
    // Destructor
    virtual ~vecNd();
    
    //operators
    vecNd operator = (vecNd & v);           // Vector assignment
    vecNd operator + (vecNd & v);           // Vector addition
    vecNd operator - (vecNd & v);           // Vector subtraction
    vecNd operator * (vecNd & v);           // Vector multiplication
    vecNd operator * (double k);            // Scalar multiplication
    vecNd operator * (matrixMN & a);        // Vector matrix multiplication
    vecNd operator += (vecNd & v);          // Vector addition assignment
    vecNd operator -= (vecNd & v);          // Vector subtraction assignment
    vecNd operator *= (vecNd & v);          // Vector multiplication assignment
    vecNd operator *= (double k);           // Scalar multiplication assignment
    vecNd operator *= (matrixMN & a);       // Vector matrix multiplication assignment
    
    // Setter functions
    void SetComponent(double val, int i);
    
    // Getter functions
    int GetDimension() {return ndim;}
    double GetComponent(int i);
    
    // Member functions
    vecNd Clear() {fail_bit = false; return * this;}
    void Print();
    double Magnitude();
};

#endif /* defined(__inclass__vecNd__) */
