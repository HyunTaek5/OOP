#include <iostream>
#define ROW 3
#define COL 3
using namespace std;

/*
				HW 2 (5pts, Due: 10/4 23:59PM)
Provide a class Matrix to complete this code.
This class should support the following functionalities:

1. Matrix Creation
A 3 by 3 matrix is created. All values are initialized as non-zero integers.
You may want to use rand for this.

2. Matrix Addition and Multiplication
You may want to use operator overloading.

3. Display
The values of a matrix are "well" displayed.

Submit this file to the LMS.
*/

//Your code goes here.

//
// Updated by 32202733 오현택 on 2021/09/29.
//

class Matrix {
public:
     explicit Matrix(int x0 = rand(), int x1 = rand(), int x2 = rand(),
                     int y0 = rand(), int y1 = rand(),  int y2 = rand(),
                     int z0 = rand(), int z1 = rand(), int z2 = rand()){
         array[0][0] = x0;
         array[0][1] = x1;
         array[0][2] = x2;
         array[1][0] = y0;
         array[1][1] = y1;
         array[1][2] = y2;
         array[2][0] = z0;
         array[2][1] = z1;
         array[2][2] = z2;
     };

    Matrix operator+(const Matrix &array0){
        Matrix array1;
        for (int i = 0; i < 3; i++)
            for(int j = 0; j < 3; j++)
                array1.array[i][j] = array[i][j] + array0.array[i][j];
        return array1;
    };

    Matrix operator*(const Matrix &array0){
        Matrix array1;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                    array1.array[i][k] += (array[i][j] * array1.array[j][i]);
        return array1;
    };

    void show(){
        for (auto & i : array)
        {
            for (int j : i)
                cout << "| " << j << " |";
            cout << endl;
        }
    };

private:
    int array[ROW][COL]{};
};

//DO NOT TOUCH THE MAIN FUNCTION.
int main() {

	Matrix A, B, C;		// 3 by 3 matrix created. All values are initialized as non-zero integers.

	Matrix D = A + B;	// Matrix Addition
	Matrix E = A * C;	// Matrix Multiplication

	cout << "A" << endl;
	A.show();		// display the values
	cout << "B" << endl;
	B.show();
	cout << "C" << endl;
	C.show();


	cout << "A + B" << endl;
	D.show();

	cout << "A * C" << endl;
	E.show();

	return 0;
}