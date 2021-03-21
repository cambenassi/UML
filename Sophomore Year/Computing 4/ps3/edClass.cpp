#include <iostream>
#include <iomanip>
#include "edClass.h"

//constructors & destructor
ED::ED(std::string a, std::string b){
    dnaA = a;
    dnaB = b;

    int m = a.length() + 1, n = b.length() + 1;
    
    matrix = new int *[m];
    for(int i = 0; i < m; i++)
        matrix[i] = new int [n];

    optDistance();
    
}

ED::ED(){
    dnaA = "blank";
    dnaB = "blank";
}

//ED::~ED() {delete[] matrix;};
//overloaded operators
std::istream& operator>>(std::istream& os, ED& dest){
    std::string tempA, tempB;
    std::cin >> tempA >> tempB;
    ED tempED(tempA, tempB);
    
    dest = tempED;
    
    return os;
}
//member functions
int ED::penalty(char a, char b){
    if(a == b)
        return 0;
    else   
        return 1;
}

int ED::min(int a, int b, int c){
    return std::min({a, b, c});
}

int ED::optDistance(){
    int m = dnaA.length() + 1;  //m - 1 = go up 1
    int n = dnaB.length() + 1;  //n - 1 = go left 1
    
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            matrix[i][j] = 0;
        }
    }

    //populating y axis
    for(int i = m - 1; i >= 0; i--){
        if(i != m - 1)
            matrix[i][n - 1] = matrix[i + 1][n - 1] + 2;
        else   
            matrix[i][n - 1] = 0;
    }
    //populating x axis
    for(int i = n - 1; i >= 0; i--){
        if(i != n - 1)
            matrix[m - 1][i] = matrix[m - 1][i + 1] + 2;
        else   
            matrix[m - 1][i] = 0;
    }
    //populating middleß
    for(int i = m - 2; i >= 0; i--){
        for(int j = n - 2; j >= 0; j--){
            matrix[i][j] = min(matrix[i + 1][j] + 2, matrix[i][j + 1] + 2, penalty(dnaA.at(i), dnaB.at(j)) + matrix[i + 1][j + 1] );
        }
    }
    //printing

    std::cout << stringAllignment();

    return 1;
}

std::string ED::stringAllignment(){
    int m = dnaA.length(), i = 0;  //m - 1 = go up 1
    int n = dnaB.length(), j = 0, temp, offset = 0, totalCost = 0;  //n - 1 = go left 1
    std::string costs, final;

    while(i != m && j != n){
        if(penalty(dnaA.at(i), dnaB.at(j + offset)) == 0){
            i++;
            j++;
            costs += '0';
        }
        else{
            temp = min(matrix[i + 1][j], matrix[i][j + 1], matrix[i + 1][j + 1]);
            if(temp == matrix[i + 1][j] && (matrix[i][j] - temp == 2)){
                dnaB.insert(j + offset, "-");
                costs += "2";
                totalCost += 2;
                offset++;
                i++;
            }
            else{
                i++;
                j++;
                costs += '1';
                totalCost += 1;
            }

        }
    }
    final += "\nEdit distance = ";
    final += std::to_string(totalCost);
    final += "\nx  y  cost\n----------\n";
    for(i = 0; i < dnaA.length(); i++){
        final += dnaA.at(i);
        final += "  ";
        final += dnaB.at(i);
        final += "    ";
        final += costs.at(i);
        final += '\n';
    }

    return final;
}

/*
for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            std::cout.width(4);
            std::cout << std::right << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
*/