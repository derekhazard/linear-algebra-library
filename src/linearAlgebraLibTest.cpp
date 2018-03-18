//
//  vectorClassTest.cpp
//  
//
//  Created by Derek Hazard on 2/19/14.
//  Copyright (c) 2014 Derek Hazard. All rights reserved.
//


#include "vecNd.h"
#include "matrixMN.h"
#include <iostream>
#include <cmath>

void fillVector(vecNd & v, int lowerBound, int upperBound, double seed);
void fillMatrix(matrixMN & a, int lowerBound, int upperBound, double seed);

using namespace std;

int main( )
{
    // Dynamically declare two vectors
    int dim = 3;
    vecNd *myFirstVecNd=new vecNd(dim);
    vecNd *mySecondVecNd=new vecNd(dim);
    
    // Fill vectors with random numbers
    fillVector(*myFirstVecNd, 0, 9, 3.4);
    fillVector(*mySecondVecNd, 0, 9, 4.3);
    
    // Welcome user
    cout << "\nWelcome to the linear algebra library testing program.\n\n";
    
    
    // Display vector magnitudes
    cout << "The magnitude of <";
    myFirstVecNd->Print();
    cout << "> is " << myFirstVecNd->Magnitude() << "\n\n";
    
    // Display vector magnitudes
    cout << "The magnitude of <";
    mySecondVecNd->Print();
    cout << "> is " << mySecondVecNd->Magnitude() << "\n\n";
    
    // Demonstrate +
    cout << "<";
    myFirstVecNd->Print();
    cout << "> + <";
    mySecondVecNd->Print();
    cout << "> = <";
    (*myFirstVecNd + *mySecondVecNd).Print();
    cout << ">\n\n";
    
    // Demonstrate -
    cout << "<";
    myFirstVecNd->Print();
    cout << "> - <";
    mySecondVecNd->Print();
    cout << "> = <";
    (*myFirstVecNd - *mySecondVecNd).Print();
    cout << ">\n\n";
    
    // Demonstrate *
    cout << "<";
    myFirstVecNd->Print();
    cout << "> * <";
    mySecondVecNd->Print();
    cout << "> = <";
    (*myFirstVecNd * *mySecondVecNd).Print();
    cout << ">\n\n";
    
    cout << "<";
    myFirstVecNd->Print();
    cout << "> * 2 = <";
    (*myFirstVecNd * 2).Print();
    cout << ">\n\n";
    
    // Demonstrate +=
    cout << "<";
    myFirstVecNd->Print();
    cout << "> += <";
    mySecondVecNd->Print();
    cout << ">\n";
    *myFirstVecNd += *mySecondVecNd;
    cout << "First Vector: <";
    myFirstVecNd->Print();
    cout << ">\nSecond Vector: <";
    mySecondVecNd->Print();
    cout << ">\n\n";
    
    // Demonstrate -=
    cout << "<";
    myFirstVecNd->Print();
    cout << "> -= <";
    mySecondVecNd->Print();
    cout << ">\n";
    *myFirstVecNd -= *mySecondVecNd;
    cout << "First Vector: <";
    myFirstVecNd->Print();
    cout << ">\nSecond Vector: <";
    mySecondVecNd->Print();
    cout << ">\n\n";
    
    // Demonstrate *=
    cout << "<";
    myFirstVecNd->Print();
    cout << "> *= <";
    mySecondVecNd->Print();
    cout << ">\n";
    *myFirstVecNd *= *mySecondVecNd;
    cout << "First Vector: <";
    myFirstVecNd->Print();
    cout << ">\nSecond Vector: <";
    mySecondVecNd->Print();
    cout << ">\n\n";
    
    cout << "<";
    myFirstVecNd->Print();
    cout << "> *= 1/3\n";
    *myFirstVecNd *= (1/3.);
    cout << "Vector: <";
    myFirstVecNd->Print();
    cout << ">\n\n";
    
    // Demonstrate =
    cout << "<";
    myFirstVecNd->Print();
    cout << "> = <";
    mySecondVecNd->Print();
    cout << ">\n";
    *myFirstVecNd = *mySecondVecNd;
    cout << "First Vector: <";
    myFirstVecNd->Print();
    cout << ">\nSecond Vector: <";
    mySecondVecNd->Print();
    cout << ">\n\n";
    
    delete myFirstVecNd;
    delete mySecondVecNd;
    
    // Declare a few test matricies
    matrixMN a(1,3,3,
               1,4,3,
               1,3,4);
    
    matrixMN b(3,3);
    
    matrixMN c(0,  2,  0,  1,  0,
               2,  2,  3,  2, -2,
               4, -3,  0,  1, -7,
               6,  1, -6, -5,  6);
    
    // Display the matricies
    cout << "\nHere are a few matricies\n";
    cout << "\na:\n";
    a.Print(0);
    cout << "\n\nb:\n";
    b.Print(0);
    cout << "\n\nc:\n";
    c.Print(0);
    
    // Fill b with random numbers
    cout << "\n\nLet's fill b with some random numbers:\n";
    cout << "\nb:\n";
    fillMatrix(b, 0, 10, 2.5);
    b.Print(0);
    
    // Demonstrate the trace and determinant
    cout << "\nTrace of a = " << a.Trace() << "\n";
    cout << "Trace of b = " << b.Trace() << "\n";
    cout << "Trace of a + b = " << (a+b).Trace() << "\n";
    
    cout << "\nDeterminant of a = " << a.Determinant() << "\n";
    cout << "Determinant of b = " << b.Determinant() << "\n";
    cout << "Determinant of a + b = " << (a+b).Determinant() << "\n";
    
    // Demonstrate the inverse
    matrixMN aInverse = a;
    cout << "\nThe inverse of a:\n";
    aInverse.Inverse().Print(0);
    cout << "\na * a^-1:\n";
    (a * aInverse).Print(0);
    
    // Display the transpose.
    matrixMN aTrans = a;
    cout << "\nThe transpose of a:\n";
    aTrans.Transpose().Print(0);
    
    // Demonstrate +, -, and *
    cout << "\nLet's demonstrate the +, -, and * operators:\n";
    cout << "\na + b = \n";
    (a+b).Print(0);
    
    cout << "\na - b = \n";
    (a-b).Print(0);
    
    cout << "\na * 2 = \n";
    (a * 2).Print(0);
    
    cout << "\na * b = \n";
    (a * b).Print(0);
    
    // Demonstrate +=, -=, and *=
    cout << "\n\nLet's demonstrate the +=, -=, and *= operators:\n";
    cout << "\na:\n";
    a.Print(0);
    cout << "\nb:\n";
    b.Print(0);
    cout << "\na += b\n";
    a += b;
    cout << "\na:\n";
    a.Print(0);
    cout << "\n\nb:\n";
    b.Print(0);
    
    cout << "\na -= b\n";
    a -= b;
    cout << "\na:\n";
    a.Print(0);
    cout << "\n\nb:\n";
    b.Print(0);
    
    cout << "\na *= b\n";
    a *= b;
    cout << "\na:\n";
    a.Print(0);
    cout << "\n\nb:\n";
    b.Print(0);

    cout << "\na *= 2\n";
    a *= 2;
    cout << "\na:\n";
    a.Print(0);
    
    // Demonstrate gauss elimination
    cout << "\nPerforming Gauss Elimination on c yields:\n";
    c.GaussElimination().Print(3);
    std::cout << "\n";
    
    // Demonstrate gauss jordan elimination
    cout << "\nPerforming Gauss Jordan Elimination on c yields:\n";
    c.GaussJordanElimination().Print(3);
    std::cout << "\n";
    
    return 0;
}

// Function that fills a vector with random integers.
void fillVector(vecNd & v, int lowerBound, int upperBound, double seed) {
    
    // Check if the vector size is nonzero.
    if (v.GetDimension() > 0){
        
        // Seed the random number generator.
        srand(time(NULL)*seed);
        
        // Loop through the vector.
        for (int i = 0 ; i < v.GetDimension(); i++) {
            // Put a random number between and including the upper and lower
            // boundaries in the array's last element.
            v.SetComponent(lowerBound + rand() % upperBound, i);
        }
    }
    
    return;
    
}

// Function that fills a matrix with random integers.
void fillMatrix(matrixMN & a, int lowerBound, int upperBound, double seed) {
    
    // Check if the vector size is nonzero.
    if (a.GetM() > 0 && a.GetN()){
        
        // Seed the random number generator.
        srand(time(NULL)*seed);
        
        // Loop through the rows and columns. Put a random number between and
        // including the upper and lower boundaries in the array's last element.
        for (int i = 0 ; i < a.GetM(); i++) for (int j = 0; j < a.GetN(); j++)
            a.SetElement(i, j, lowerBound + rand() % upperBound);
        
    }
    
    return;
    
}