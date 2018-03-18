//
//  vecNd.cpp
//  inclass
//
//  Created by Derek Hazard on 3/3/14.
//  Copyright (c) 2014 Derek Hazard. All rights reserved.
//

// Implementation of vecNd class

#include "vecNd.h"
#include "matrixMN.h"
#include <iostream>
#include <cmath>

using namespace std;

// Default constructor
vecNd::vecNd() { ndim=0; n=new double[1]; }

// User defined constructor for a 2d vector
vecNd::vecNd(double n0, double n1)
{
    ndim=2;                                     // Set vector size
    n=new double[ndim];                         // Declare array
    n[0] = n0; n[1] = n1;                       // Fill vector
}

// User defined constructor for a 2d vector
vecNd::vecNd(double n0, double n1, double n2)
{
    ndim=3;                                     // Set vector size
    n=new double[ndim];                         // Declare array
    n[0] = n0; n[1] = n1; n[2] = n2;            // Fill vector
}

// User defined constructor for a Nd vector
vecNd::vecNd(int dim)
{
    if (dim > 1) {
        ndim = dim;                             // Set vector size
        n = new double[ndim];                   // Declare array
        for (int i = 0; i < ndim; i++) n[i] = 0;// Fill vector with zeros
    }
    else {
        ndim = 0;                               // Set vector size
        n = new double[1];                      // Declare array
    }
}

// Copy constructor
vecNd::vecNd(vecNd & v)
{
    ndim=(int) v.GetDimension();                // Set vector size
    n=new double[ndim];                         // Declare array
    for (int i=0;i<(int) v.GetDimension();i++)  // Copy elements to new vector
        n[i]=v.GetComponent(i);
}

// Destructor
vecNd::~vecNd()
{
    delete [] n; // Free memory
}

// = operator overload
vecNd vecNd::operator = (vecNd & v)
{
    ndim = v.GetDimension();                    // Set vector size
    n = new double[ndim];                       // Declare array
    for (int i=0;i<(int) v.GetDimension();i++)  // Copy elements to new vector
        n[i]=v.GetComponent(i);
    
    return *this;
}

// + operator overload
vecNd vecNd::operator + (vecNd & v)
{
    vecNd add;                                  // Create new vector
    
    // Check to see if the vectors are of the same dimension.
    if (GetDimension() == v.GetDimension()) {
        add.ndim = GetDimension();              // Set vector size
        add.n = new double[add.ndim];           // Declare array
        
        // Add components and assign to new vector
        for (int i = 0;i < v.GetDimension();i++)
            add.n[i] = GetComponent(i) + v.GetComponent(i);
    }
    
    return add;
}

// += operator overload
vecNd vecNd::operator += (vecNd & v)
{
    // Check to see if the vectors are of the same dimension.
    if (GetDimension() == v.GetDimension()) {
        
        // Add components and assign to first vector
        for (int i = 0;i < v.GetDimension();i++)
            n[i] = GetComponent(i) + v.GetComponent(i);
    }
    else ndim = 0;
    
    return *this;
}

// - operator overload
vecNd vecNd::operator - (vecNd & v)
{
    vecNd diff;                                  // Create new vector
    
    // Check to see if the vectors are of the same dimension.
    if (GetDimension() == v.GetDimension()) {
        diff.ndim = GetDimension();              // Set vector size
        diff.n = new double[diff.ndim];          // Declare array
        
        // Subtract components and assign to new vector
        for (int i = 0;i < v.GetDimension();i++)
            diff.n[i] = GetComponent(i) - v.GetComponent(i);
    }
    
    return diff;
}

// -= operator overload
vecNd vecNd::operator -= (vecNd & v)
{
    // Check to see if the vectors are of the same dimension.
    if (GetDimension() == v.GetDimension()) {
        
        // Subtract components and assign to first vector
        for (int i = 0;i < v.GetDimension();i++)
            n[i] = GetComponent(i) - v.GetComponent(i);
    }
    else ndim = 0;
    
    return *this;
}

// * operator overload
vecNd vecNd::operator * (vecNd & v)
{
    vecNd mult;                                  // Create new vector
    
    // Check to see if the vectors are of the same dimension.
    if (GetDimension() == v.GetDimension()) {
        mult.ndim = GetDimension();              // Set vector size
        mult.n = new double[mult.ndim];          // Declare array
        
        // Multiply components and assign to new vector
        for (int i = 0;i < v.GetDimension();i++)
            mult.n[i] = GetComponent(i) * v.GetComponent(i);
    }
    
    return mult;
}

// * operator overload
vecNd vecNd::operator * (double k)
{
    vecNd mult;                                 // Create new vector
    mult.ndim = GetDimension();                 // Set vector size
    mult.n = new double[mult.ndim];             // Declare array
    
    // Multiply components and assign to new vector
    for (int i = 0;i < GetDimension();i++)
        mult.n[i] = GetComponent(i) * k;
    
    return mult;
}

// Overload multiplication operator (*)
vecNd vecNd::operator * (matrixMN & a){
    
    vecNd mult;                                 // Declare a new vector.
    
    // Check to make sure the vector and matrix can be multiplied
    if (ndim == a.GetM()) {
        mult.ndim = a.GetN();                   // Set vector size
        mult.n = new double[mult.ndim];         // Declare array
            
            // Loop through each column of the second matrix
            for (int i = 0; i < a.GetN(); i++) {
                
                // Loop through each element of the vector and current column in the second matrix
                for (int j = 0; j < ndim; j++) {
                    
                    // Multiple the jth element's in the vector and current column and sum them together
                    mult.n[i] += n[j] * a.GetElement(j, i);
                }
            }
    }
    else {
        mult.fail_bit = true;
        std::cout << "\n\nCANNOT MULTIPLY A " << ndim << "D VECTOR WITH A "
                  << a.GetM() << "x" << a.GetN() << "MATRIX!\n\n";
    }
    
    return mult;
}

// *= operator overload
vecNd vecNd::operator *= (vecNd & v)
{
    // Check to see if the vectors are of the same dimension.
    if (GetDimension() == v.GetDimension()) {
        
        // Multiply components and assign to first vector
        for (int i = 0;i < v.GetDimension();i++)
            n[i] = GetComponent(i) * v.GetComponent(i);
    }
    else ndim = 0;
    
    return *this;
}

// *= operator overload
vecNd vecNd::operator *= (double k)
{
    // Multiply each component by k and assign to first vector
    for (int i = 0;i < GetDimension();i++)
        n[i] = GetComponent(i) * k;
    
    return *this;
}


// *= operator overload
vecNd vecNd::operator *= (matrixMN & a)
{
    vecNd mult;                                 // Declare a new vector.
    
    // Check to make sure the vector and matrix can be multiplied
    if (ndim == a.GetM()) {
        mult.ndim = a.GetN();                   // Set vector size
        mult.n = new double[mult.ndim];         // Declare array
        
        // Loop through each column of the second matrix
        for (int i = 0; i < a.GetN(); i++) {
            
            // Loop through each element of the vector and current column in the second matrix
            for (int j = 0; j < ndim; j++) {
                
                // Multiple the jth element's in the vector and current column and sum them together
                mult.n[i] += n[j] * a.GetElement(j, i);
            }
        }
    }
    else {
        mult.fail_bit = true;
        std::cout << "\n\nCANNOT MULTIPLY A " << ndim << "D VECTOR WITH A "
        << a.GetM() << "x" << a.GetN() << "MATRIX!\n\n";
    }
    
    delete [] n;    // Free memory
    
    // Reconsruct first vector and fill it with the results.
    fail_bit = mult.fail_bit;
    ndim = mult.ndim;
    n = new double[ndim];
    for (int i = 0; i < ndim; i++) n[i] = mult.n[i];
    
    return *this;
}


// Setter function for components
void vecNd::SetComponent(double val, int i) {
    if (i > -1 && i < ndim) n[i] = val;            // If valid index, set value
}

// Getter function for components
double vecNd::GetComponent(int i) {
    if (i > -1 && i < ndim) return n[i];            // If valid index, return value
    else return 0;                                  // If invalid index, return zero
}

// Print the numbers in the vector.
void vecNd::Print()
{
    for (int i = 0;i < ndim;i++) {
        if (i < (ndim - 1)) cout << n[i] << ", ";
        else cout << n[i];
    }
}

// Find the magnitude of the vector
double vecNd::Magnitude()
{
    double magSqr = 0;
    for (int i = 0;i < ndim;i++) magSqr += n[i] * n[i];
    return sqrt(magSqr);
}
