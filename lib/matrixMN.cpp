//
//  matrixMN.cpp
//  inclass
//
//  Created by Derek Hazard on 3/2/14.
//  Copyright (c) 2014 Derek Hazard. All rights reserved.
//

#include "matrixMN.h"
#include "vecNd.h"
#include <iostream>
#include <vector>
#include <cmath>

// Prototypes
void swap(std::vector<double> &, std::vector<double> &);
double round(double val, int precision);

// Default constructor
matrixMN::matrixMN(){
    
    fail_bit = false;                                               // Set fail_bit
    mdim = ndim = 0;                                                // Set dimensions.
}

// User defined 2x2 constructor
matrixMN::matrixMN(double m0n0, double m0n1,
                   double m1n0, double m1n1){
    
    fail_bit = false;                                               // Set fail_bit
    mdim = ndim = 2;                                                // Set dimensions.
    matrix.resize(mdim);                                            // Resize the number of rows.
    for (int i = 0; i < mdim; i++) matrix[i].resize(ndim);          // Resize the number of columns.
    matrix[0][0] = m0n0; matrix[0][1] = m0n1;                       // Fill first row.
    matrix[1][0] = m1n0; matrix[1][1] = m1n1;                       // Fill second row.
    
}

// User defined 3x3 constructor
matrixMN::matrixMN(double m0n0, double m0n1, double m0n2,
                   double m1n0, double m1n1, double m1n2,
                   double m2n0, double m2n1, double m2n2){
    
    fail_bit = false;                                               // Set fail_bit
    mdim = ndim = 3;                                                // Set dimensions
    matrix.resize(mdim);                                            // Resize the number of rows.
    for (int i = 0; i < mdim; i++) matrix[i].resize(ndim);          // Resize the number of columns.
    matrix[0][0] = m0n0; matrix[0][1] = m0n1; matrix[0][2] = m0n2;  // Fill first row.
    matrix[1][0] = m1n0; matrix[1][1] = m1n1; matrix[1][2] = m1n2;  // Fill second row.
    matrix[2][0] = m2n0; matrix[2][1] = m2n1; matrix[2][2] = m2n2;  // Fill third row.
    
}

// User defined 4x4 constructor
matrixMN::matrixMN(double m0n0, double m0n1, double m0n2, double m0n3,
                   double m1n0, double m1n1, double m1n2, double m1n3,
                   double m2n0, double m2n1, double m2n2, double m2n3,
                   double m3n0, double m3n1, double m3n2, double m3n3){
    
    fail_bit = false;                                               // Set fail_bit
    mdim = ndim = 4;                                                // Set dimensions
    matrix.resize(mdim);                                            // Resize the number of rows.
    for (int i = 0; i < mdim; i++) matrix[i].resize(ndim);          // Resize the number of columns.
    matrix[0][0] = m0n0; matrix[0][1] = m0n1;                       // Fill first row.
    matrix[0][2] = m0n2; matrix[0][3] = m0n3;
    matrix[1][0] = m1n0; matrix[1][1] = m1n1;                       // Fill second row.
    matrix[1][2] = m1n2; matrix[1][3] = m1n3;
    matrix[2][0] = m2n0; matrix[2][1] = m2n1;                       // Fill third row.
    matrix[2][2] = m2n2; matrix[2][3] = m2n3;
    matrix[3][0] = m3n0; matrix[3][1] = m3n1;                       // Fill fourth row.
    matrix[3][2] = m3n2; matrix[3][3] = m3n3;
    
}

// User defined 5x5 constructor
matrixMN::matrixMN(double m0n0, double m0n1, double m0n2, double m0n3, double m0n4,
                   double m1n0, double m1n1, double m1n2, double m1n3, double m1n4,
                   double m2n0, double m2n1, double m2n2, double m2n3, double m2n4,
                   double m3n0, double m3n1, double m3n2, double m3n3, double m3n4,
                   double m4n0, double m4n1, double m4n2, double m4n3, double m4n4) {
    
    fail_bit = false;                                               // Set fail_bit
    mdim = ndim = 5;                                                // Set dimensions
    matrix.resize(mdim);                                            // Resize the number of rows.
    for (int i = 0; i < mdim; i++) matrix[i].resize(ndim);          // Resize the number of columns.
    matrix[0][0] = m0n0; matrix[0][1] = m0n1;                       // Fill first row.
    matrix[0][2] = m0n2; matrix[0][3] = m0n3; matrix[0][4] = m0n4;
    matrix[1][0] = m1n0; matrix[1][1] = m1n1;                       // Fill second row.
    matrix[1][2] = m1n2; matrix[1][3] = m1n3; matrix[1][4] = m1n4;
    matrix[2][0] = m2n0; matrix[2][1] = m2n1;                       // Fill third row.
    matrix[2][2] = m2n2; matrix[2][3] = m2n3; matrix[2][4] = m2n4;
    matrix[3][0] = m3n0; matrix[3][1] = m3n1;                       // Fill fourth row.
    matrix[3][2] = m3n2; matrix[3][3] = m3n3; matrix[3][4] = m3n4;
    matrix[4][0] = m4n0; matrix[4][1] = m4n1;                       // Fill fifth row.
    matrix[4][2] = m4n2; matrix[4][3] = m4n3; matrix[4][4] = m4n4;
    
}

// User defined 2x3 constructor
matrixMN::matrixMN(double m0n0, double m0n1, double m0n2,
                   double m1n0, double m1n1, double m1n2){
    
    fail_bit = false;                                               // Set fail_bit
    mdim = 2; ndim = 3;                                             // Set dimensions
    matrix.resize(mdim);                                            // Resize the number of rows.
    for (int i = 0; i < mdim; i++) matrix[i].resize(ndim);          // Resize the number of columns.
    matrix[0][0] = m0n0; matrix[0][1] = m0n1; matrix[0][2] = m0n2;  // Fill first row.
    matrix[1][0] = m1n0; matrix[1][1] = m1n1; matrix[1][2] = m1n2;  // Fill second row.
    
}

// User defined 3x4 constructor
matrixMN::matrixMN(double m0n0, double m0n1, double m0n2, double m0n3,
                   double m1n0, double m1n1, double m1n2, double m1n3,
                   double m2n0, double m2n1, double m2n2, double m2n3){
    
    fail_bit = false;                                               // Set fail_bit
    mdim = 3; ndim = 4;                                             // Set dimensions
    matrix.resize(mdim);                                            // Resize the number of rows.
    for (int i = 0; i < mdim; i++) matrix[i].resize(ndim);          // Resize the number of columns.
    matrix[0][0] = m0n0; matrix[0][1] = m0n1;                       // Fill first row.
    matrix[0][2] = m0n2; matrix[0][3] = m0n3;
    matrix[1][0] = m1n0; matrix[1][1] = m1n1;                       // Fill second row.
    matrix[1][2] = m1n2; matrix[1][3] = m1n3;
    matrix[2][0] = m2n0; matrix[2][1] = m2n1;                       // Fill third row.
    matrix[2][2] = m2n2; matrix[2][3] = m2n3;
    
}

// User defined 4x5 constructor
matrixMN::matrixMN(double m0n0, double m0n1, double m0n2, double m0n3, double m0n4,
                   double m1n0, double m1n1, double m1n2, double m1n3, double m1n4,
                   double m2n0, double m2n1, double m2n2, double m2n3, double m2n4,
                   double m3n0, double m3n1, double m3n2, double m3n3, double m3n4) {
    
    fail_bit = false;                                               // Set fail_bit
    mdim = 4; ndim = 5;                                             // Set dimensions
    matrix.resize(mdim);                                            // Resize the number of rows.
    for (int i = 0; i < mdim; i++) matrix[i].resize(ndim);          // Resize the number of columns.
    matrix[0][0] = m0n0; matrix[0][1] = m0n1;                       // Fill first row.
    matrix[0][2] = m0n2; matrix[0][3] = m0n3; matrix[0][4] = m0n4;
    matrix[1][0] = m1n0; matrix[1][1] = m1n1;                       // Fill second row.
    matrix[1][2] = m1n2; matrix[1][3] = m1n3; matrix[1][4] = m1n4;
    matrix[2][0] = m2n0; matrix[2][1] = m2n1;                       // Fill third row.
    matrix[2][2] = m2n2; matrix[2][3] = m2n3; matrix[2][4] = m2n4;
    matrix[3][0] = m3n0; matrix[3][1] = m3n1;                       // Fill fourth row.
    matrix[3][2] = m3n2; matrix[3][3] = m3n3; matrix[3][4] = m3n4;
    
}

// User defined MxN constructor
matrixMN::matrixMN(int M, int N){
    
    // Check that dimensions are valid
    if (M > 0 && N > 0) {
        fail_bit = false;                                           // Set fail_bit
        mdim = M; ndim = N;                                         // Set dimensions
        matrix.resize(mdim);                                        // Resize the number of rows.
        for (int i = 0; i < mdim; i++) matrix[i].resize(ndim);      // Resize the number of columns.
        SetZero();                                                  // Fill the matrix with zeros
    }
    else {
        fail_bit = true;                                            // Set fail_bit
        mdim = ndim = 0;                                            // Set dimensions.
    }
}


// Copy constructor
matrixMN::matrixMN(matrixMN & a){
    
    fail_bit = a.fail_bit;                                          // Set fail_bit
    mdim = a.mdim; ndim = a.ndim;                                   // Set dimensions
    matrix.resize(mdim);                                            // Resize the number of rows.
    for (int i = 0; i < mdim; i++) matrix[i].resize(ndim);          // Resize the number of columns.
    
    // Copy each element
    for (int M = 0; M < mdim; M++) {
        for (int N = 0; N < ndim; N++) {
            matrix[M][N] = a.matrix[M][N];
        }
    }
}


// Destructor
matrixMN::~matrixMN(){}


// Overload assignment operator (=)
matrixMN matrixMN::operator = (matrixMN & a){
    
    fail_bit = a.fail_bit;                                          // Set fail_bit
    mdim = a.mdim; ndim = a.ndim;                                   // Set dimensions
    matrix.resize(mdim);                                            // Resize the number of rows.
    for (int i = 0; i < mdim; i++) matrix[i].resize(ndim);          // Resize the number of columns.
    
    // Copy each element
    for (int M = 0; M < mdim; M++) {
        for (int N = 0; N < ndim; N++) {
            matrix[M][N] = a.matrix[M][N];
        }
    }
    
    return *this;
}

// Overload addition operator (+)
matrixMN matrixMN::operator + (matrixMN & a){
    
    matrixMN add;
    
    if (mdim == a.mdim && ndim == a.ndim) {
        
        add.mdim = mdim; add.ndim = ndim;                           // Set dimensions
        add.matrix.resize(add.mdim);                                // Resize the number of rows.
        
        // Loop through each row
        for (int M = 0; M < add.mdim; M++) {
            
            // Dynamically declare an array of doubles.
            add.matrix[M].resize(add.ndim);                         // Resize the number of columns.
            
            //Loop through each column and add element by element
            for (int N = 0; N < add.ndim; N++) {
                add.matrix[M][N] = matrix[M][N] + a.matrix[M][N];
            }
        }
    }
    else {
        add.fail_bit = true;
        std::cout << "\n\nCANNOT ADD MATRICIES WITH DIFFERENT DIMENSIONS!\n\n";
    }
    
    return add;
}

// Overload subtraction operator (-)
matrixMN matrixMN::operator - (matrixMN & a){
    
    matrixMN sub;
    
    if (mdim == a.mdim && ndim == a.ndim) {
        
        sub.mdim = mdim; sub.ndim = ndim;                           // Set dimensions
        sub.matrix.resize(sub.mdim);                                // Resize the number of rows.
        
        // Loop through each row
        for (int M = 0; M < sub.mdim; M++) {
            
            // Dynamically declare an array of doubles.
            sub.matrix[M].resize(sub.ndim);                         // Resize the number of columns.
            
            //Loop through each column and add element by element
            for (int N = 0; N < sub.ndim; N++) {
                sub.matrix[M][N] = matrix[M][N] - a.matrix[M][N];
            }
        }
    }
    else {
        sub.fail_bit = true;
        std::cout << "\n\nCANNOT SUBTRACT MATRICIES WITH DIFFERENT DIMENSIONS!\n\n";
    }
    
    return sub;
}

// Overload multiplication operator (*)
matrixMN matrixMN::operator * (matrixMN & a){
    
    // Declare a new matrix.
    matrixMN mult;
    
    // Check to make sure the matricies can be multiplied
    if (ndim == a.mdim) {
        
        mult.mdim = mdim; mult.ndim = a.ndim;                         // Set dimensions
        mult.matrix.resize(mult.mdim);                                // Resize the number of rows.
        
        // Loop through each row of the first matrix
        for (int i = 0; i < mdim; i++) {
            
            mult.matrix[i].resize(mult.ndim);                         // Resize the number of columns.
            
            //Loop through each column of the second matrix
            for (int j = 0; j < a.ndim; j++) {
                
                // Loop through each element of the current row in the first and column in the second matrix
                for (int k = 0; k < ndim; k++) {
                    
                    // Multiple the kth element's in the current row and column and sum them together
                    mult.matrix[i][j] += matrix[i][k] * a.matrix[k][j];
                }
            }
        }
    }
    else {
        mult.fail_bit = true;
        std::cout << "\n\nCANNOT MULTIPLY A " << mdim << "x" << ndim << " MATRIX WITH A "
                  << a.mdim << "x" << a.ndim << " MATRIX!\n\n";
    }
    
    return mult;
}

// Overload multiplication operator (*)
matrixMN matrixMN::operator * (double k){
    
    matrixMN mult;
    
    if (mdim > 0 && ndim > 0) {
        
        mult.mdim = mdim; mult.ndim = ndim;                         // Set dimensions
        mult.matrix.resize(mult.mdim);                              // Resize the number of rows.
        
        // Loop through each row
        for (int M = 0; M < mult.mdim; M++) {
            
            // Dynamically declare an array of doubles.
            mult.matrix[M].resize(mult.ndim);                         // Resize the number of columns.
            
            //Loop through each column and multiply element by element
            for (int N = 0; N < mult.ndim; N++) {
                mult.matrix[M][N] = matrix[M][N] * k;
            }
        }
    }
    else mult.fail_bit = true;
    
    return mult;
}


// Overload addition operator (+=)
matrixMN matrixMN::operator += (matrixMN & a){

    if (mdim == a.mdim && ndim == a.ndim) {
        
        // Loop through each row
        for (int M = 0; M < mdim; M++) {
            
            //Loop through each column and add element by element
            for (int N = 0; N < ndim; N++) {
                matrix[M][N] += a.matrix[M][N];
            }
        }
    }
    else {
        fail_bit = true;
        std::cout << "\n\nCANNOT ADD MATRICIES WITH DIFFERENT DIMENSIONS!\n\n";
    }
    
    return *this;
}

// Overload addition operator (-=)
matrixMN matrixMN::operator -= (matrixMN & a){
    
    if (mdim == a.mdim && ndim == a.ndim) {
        
        // Loop through each row
        for (int M = 0; M < mdim; M++) {
            
            //Loop through each column and add element by element
            for (int N = 0; N < ndim; N++) {
                matrix[M][N] -= a.matrix[M][N];
            }
        }
    }
    else {
        fail_bit = true;
        std::cout << "\n\nCANNOT SUBTRACT MATRICIES WITH DIFFERENT DIMENSIONS!\n\n";
    }
    return *this;
}


// Overload multiplication operator (*=)
matrixMN matrixMN::operator *= (matrixMN & a){
    
    // Declare a new matrix.
    matrixMN mult;
    
    // Check to make sure the matricies can be multiplied
    if (ndim == a.mdim) {
        
        mult.mdim = mdim; mult.ndim = a.ndim;                         // Set dimensions
        mult.matrix.resize(mult.mdim);                                // Resize the number of rows.
        
        // Loop through each row of the first matrix
        for (int i = 0; i < mdim; i++) {
            
            mult.matrix[i].resize(mult.ndim);                         // Resize the number of columns.
            
            //Loop through each column of the second matrix
            for (int j = 0; j < a.ndim; j++) {
                
                // Loop through each element of the current row in the first and column in the second matrix
                for (int k = 0; k < ndim; k++) {
                    
                    // Multiple the kth element's in the current row and column and sum them together
                    mult.matrix[i][j] += matrix[i][k] * a.matrix[k][j];
                }
            }
        }
    }
    else {
        mult.fail_bit = true;
        std::cout << "\n\nCANNOT MULTIPLY A " << mdim << "x" << ndim << "MATRIX WITH A "
        << a.mdim << "x" << a.ndim << "MATRIX!\n\n";
    }
    
    // Reconsruct first vector and fill it with the results.
    fail_bit = mult.fail_bit;
    mdim = mult.mdim;
    ndim = mult.ndim;
    matrix.resize(mdim);                                            // Resize the number of rows.
    for (int i = 0; i < mdim; i++) matrix[i].resize(ndim);          // Resize the number of columns.
    
    // Copy each element
    for (int M = 0; M < mdim; M++) for (int N = 0; N < ndim; N++) matrix[M][N] = mult.matrix[M][N];
    
    return * this;
}


// Overload addition operator (*=)
matrixMN matrixMN::operator *= (double k){
    
    if (mdim > 0 && ndim > 0) {
        
        // Loop through each row
        for (int M = 0; M < mdim; M++) {
            
            // Loop through each column and multiply element by element
            for (int N = 0; N < ndim; N++) {
                matrix[M][N] *= k;
            }
        }
    }
    else fail_bit = true;
    
    return *this;
}

// Setter functions
matrixMN matrixMN::SetElement(int M, int N, double val){
    
    //Check to make sure the position is valid
    if (M >=0 && N >=0 && M < mdim && N < ndim){
        
        // Set the matrix element.
        matrix[M][N] = val;
    }
    else {
        fail_bit = true;
        std::cout << "\n\nINDEX OUT OF BOUNDS! ELEMENT NOT SET!\n\n";
    }
    
    return *this;
}

matrixMN matrixMN::SetIdentity(){
    
    // Check to make sure it is a square matrix and set its elements to zero.
    if (mdim == ndim){
        
        //Set the matrix equal to zero.
        SetZero();
        
        //Loop through the trace elements
        for (int i = 0; i < ndim; i++) {
            matrix[i][i] = 1;
        }
    }
    else {
        fail_bit = true;
        std::cout << "\n\nTHIS METHOD IS ONLY FOR SQUARE MATRICIES.\n\n";
    }
    // Return false if the function isn't sucessful
    return *this;
    
}

matrixMN matrixMN::SetZero(){
    
    if (mdim > 0 && ndim > 0) {
    
        // Loop through each row
        for (int M = 0; M < mdim; M++) {
        
            //Loop through each column
            for (int N = 0; N < ndim; N++) {
                matrix[M][N] = 0;
            }
        }
    }
    else fail_bit = true;
    
    return *this;
}


// Getter functions
double matrixMN::GetElement(int M, int N){
    
    //Check to make sure the position is valid and return the element
    if (M >=0 && N >=0 && M < mdim && N < ndim){
        return matrix[M][N];
    }
    
    // If the indices are invalid, print a message and return zero.
    fail_bit = true;
    std::cout << "\n\nINDEX OUT OF BOUNDS! REQUESTED VALUE CANNOT BE RETURNED.\n\n";
    return 0;
}


// Member functions
matrixMN matrixMN::Print(int precision){
    
    int oldPrec = std::cout.precision();
    if (precision > 6) precision = 6;
    else if (precision < 0) precision = 0;
    std::cout.precision(precision);
    std::cout << std::fixed;
    
    // First find the appropriate width for each column.
    int strLeng = 0;    // Length of the numbers
    int widths[ndim];   // Length of the widest numbers in each row
        
    // Loop through each column to find the widest element
    for (int N = 0; N < ndim; N++) {
            
        widths[N] = 0;  // Set the inital width of each column to zero.
            
        // Loop through each element in the cloumn
        for (int M = 0; M < mdim; M++) {
                
            // Find the width of the element and if it is larger than
            // any of the previous elements, update the widths array.
            strLeng = (int) std::to_string(matrix[M][N]).length();
            if (matrix[M][N] < 0.) strLeng -= 1;
            if (strLeng > widths[N]) widths[N] = strLeng;
        }
            
        // Add two spaces to the largest widths to ensure proper on screen spacing.
        widths[N] += (precision - 4)  ;
    }
        
    // Print the elements to the screen using the column widths
    // Loop through the rows
    for (int M = 0; M < mdim; M++) {
            
        // Print the line on the left side of the matrix.
        std::cout << " |";
            
        // Loop through the columns
        for (int N = 0; N < ndim; N++) {
            std::cout.width(widths[N]);
            std::cout << std::right << round(matrix[M][N], precision);
        }
            
        // Print the line on the right side of the matrix.
        std::cout << "  | \n";
    }
    
    // Return to defaults
    std::cout.precision(oldPrec);
    std::cout.unsetf(std::ios_base:: floatfield);
    
    return *this;
}

double round(double val, int precision) {
    val = round(val * pow(10, precision))/pow(10, precision);
    if (val == 0.) val = abs(val);
    return val;
}

double matrixMN::Determinant(){
    
    // Return value
    double determinant = 0;
    
    // Check to see if the matrix is at least 1x1 and if matrix is square.
    if (mdim != ndim || mdim < 1 || ndim < 1) {
        fail_bit = true;
        std::cout << "\n\nTHE DETERMINANT IS ONLY DEFINED FOR SQUARE MATRICIES.\n\n";
        return determinant;
    }
    
    // Base case 1x1.
    else if (mdim == 1) return matrix[0][0];
    
    // Base case 2x2.
    else if (mdim == 2) return matrix[0][0]*matrix[1][1] - matrix[1][0]*matrix[0][1];
    
    // Case of NxN, where N > 2.
    else if (mdim > 2) {
        
        // Loop through the elements in the first row of the matrix.
        for (int i = 0; i < ndim; i++) {
            
            // Create a submatrix
            matrixMN b(mdim - 1, ndim - 1);
            
            // Loop through the rows of the matrix, except the first row.
            for (int j = 1; j < mdim; j++) {
                
                
                // Loop through the columns of the matrix.
                for (int k = 0; k < ndim; k++){
                    
                    // If the column number matchs the column number of the current element "i"
                    // in the first row, skip it.
                    if (i == k) continue;
                
                    // Otherwise set the submatrix elements
                    if (k < i) b.matrix[j - 1][k] = matrix[j][k];
                    else b.matrix[j - 1][k - 1] = matrix[j][k];
                }
            }
            
            // Calculate the determinate.
            determinant += pow(-1.0, i) * matrix[0][i] * b.Determinant();
        }
    }
    
    return determinant;
}

double matrixMN::Trace(){
    
    double trace = 0;   // Return value
    
    // Make sure the matrix is square
    if (mdim == ndim) {
        
        // Loop through the diagonal elements and add them together
        for (int i = 0; i < mdim; i++) {
            trace += matrix[i][i];
        }
    }
    else {
        fail_bit = true;
        std::cout << "\n\nTHE TRACE IS ONLY DEFINED FOR SQUARE MATRICIES.\n\n";
    }
    
    return trace;
}

matrixMN matrixMN::Transpose(){
    
    matrixMN transpose(ndim, mdim);
    
    if (mdim > 0 && ndim > 0) {
    
        // Loop through the rows
        for (int M = 0; M < mdim; M++) {
        
            // Loop through the columns
            for (int N = 0; N < ndim; N++) {
                transpose.matrix[N][M] = matrix[M][N];
            }
        }
    }
    else transpose.fail_bit = true;
    
    *this = transpose;
    
    return *this;
}

matrixMN matrixMN::Inverse(){
    
    // Check to see if the matrix is square.
    if (mdim != ndim || mdim == 0 || mdim == 1) {
        fail_bit = true;
        std::cout << "\n\nINVERSE IS UNDEFINED FOR A " << mdim << "x" << ndim << " MATRIX!\n\n";
    }
    // Check to see if the matrix has an inverse.
    else if (abs(Determinant()) > 0) {
        
        // Case of 2x2 matrix
        if (mdim == 2) {
            
            // Create the inverse matrix.
            matrixMN inverse(mdim, ndim);
            
            // Fill it
            inverse.matrix[0][0] = (1.0/Determinant())*matrix[1][1];
            inverse.matrix[0][1] = (-1.0/Determinant())*matrix[0][1];
            inverse.matrix[1][0] = (-1.0/Determinant())*matrix[1][0];
            inverse.matrix[1][1] = (1.0/Determinant())*matrix[0][0];
            
            // Copy the elements back to the original matrix
            matrix = inverse.matrix;
        }
            
        // Case of 3x3 matrix
        if (mdim == 3) {
            
            // Create the inverse matrix.
            matrixMN inverse(mdim, ndim);
            
            // Fill it
            inverse.matrix[0][0] = (1.0/Determinant()) * ( matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]);
            inverse.matrix[1][0] = (1.0/Determinant()) * (-matrix[1][0] * matrix[2][2] + matrix[1][2] * matrix[2][0]);
            inverse.matrix[2][0] = (1.0/Determinant()) * ( matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);
            inverse.matrix[0][1] = (1.0/Determinant()) * (-matrix[0][1] * matrix[2][2] + matrix[0][2] * matrix[2][1]);
            inverse.matrix[1][1] = (1.0/Determinant()) * ( matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0]);
            inverse.matrix[2][1] = (1.0/Determinant()) * (-matrix[0][0] * matrix[2][1] + matrix[0][1] * matrix[2][0]);
            inverse.matrix[0][2] = (1.0/Determinant()) * ( matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1]);
            inverse.matrix[1][2] = (1.0/Determinant()) * (-matrix[0][0] * matrix[1][2] + matrix[0][2] * matrix[1][0]);
            inverse.matrix[2][2] = (1.0/Determinant()) * ( matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]);
            
            // Copy the elements back to the original matrix
            matrix = inverse.matrix;
        }
            
        // Case of NxN, N > 3
        else {
            matrixMN inverse(mdim, 2 * ndim); // Declare a new matrix with twice the columns of the original matrix.
        
            // Using two loops, copy the elements from the original matrix to the left side of the new matrix.
            for (int i = 0; i < mdim; i++) for (int j = 0; j < ndim; j++) inverse.matrix[i][j] = matrix[i][j];
        
            // Using one loop fill the diagonal elements of the right side of the new matrix with ones.
            for (int i = 0; i < mdim; i++) inverse.matrix[i][i + ndim] = 1;
        
            // Use Gauss Jordan Elimination to calculate the inverse
            inverse.GaussJordanElimination();
        
            // Copy inverse matrix back to original matrix
            for (int i = 0; i < mdim; i++) for (int j = 0; j < ndim; j++) matrix[i][j] = inverse.matrix[i][j + ndim];
        }
    }
    else {
        fail_bit = true;
        std::cout << "\n\nTHE MATRIX HAS NO INVERSE.\n\n";
    }
    
    return *this;
}

matrixMN matrixMN::GaussElimination() {
    
    // Loop through the columns while they are less than the number of rows
    int steps = 0;
    if (mdim > ndim) steps = ndim;
    else steps = mdim;
    for (int j = 0; j < steps; j++) {
        
        // Loop through the jth column values at and below the diagonal.
        int max = abs(matrix[j][j]);    // The assumed largest magnitude element in the current row.
        int swapIndex = j;              // Index of the current row.
        for (int i = j; i < mdim; i++) {
            
            // Check to see if the current element magnitude is larger than the assumed max and if it
            // is, save the value and the index.
            if (abs(matrix[i][j]) > max) {
                max = abs(matrix[i][j]);
                swapIndex = i;
            }
        }
        
        // Swap rows if necessary
        if (swapIndex != j) swap(matrix[j], matrix[swapIndex]);
        
        // Check to see if the largest magnitude element is greater than zero
        if (abs(matrix[j][j]) > 0) {
            
            // Loop through all the rows below the diagonal
            for (int i = j + 1; i < mdim; i++) {
                
                // Loop through all the columns.
                double temp = matrix[i][j];
                for (int k = 0; k < ndim; k++) {
                    
                    // Calculate the value of each Guassian Elimination matrix element.
                    matrix[i][k] = matrix[i][k] - temp * (matrix[j][k] / matrix[j][j]);
                }
            }
        }
    }
    
    return * this;
}

// Function that swaps the values of two vectors of doubles
void swap(std::vector<double> &v1, std::vector<double> &v2){
    
    std::vector<double> temp = v1;
    v1 = v2;
    v2 = temp;
    
}

matrixMN matrixMN::GaussJordanElimination() {
    
    // First perform Gauss Elimination
    GaussElimination();
    
    // Loop through rows
    for (int i = 0; i < mdim; i++) {
        
        // Loop through the columns
        double temp = matrix[i][i];
        for (int j = i; j < ndim; j++) {
            
            // Make sure you don't divide by zero and divide each row by the value of its first nonzero element.
            if (abs(temp) > 0) matrix[i][j] = matrix[i][j] / temp;
        }
    }
    
    // Loop through rows backwards
    int step = mdim - 1;
    if (ndim < mdim) step = ndim - 1;
    for (int i = step; i >= 0; i--) {
        
        // Loop through the rows backwards
        for (int j = i; j > 0; j--) {
            
            double temp = matrix[j-1][i];
            
            // Loop through the columns forwards
            for (int k = i; k < ndim; k++) matrix[j-1][k] -= temp * matrix[i][k];
        }
    }
    
    return * this;
}