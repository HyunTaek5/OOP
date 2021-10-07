#include <iostream>
#define ROW 3
#define COL 3
using namespace std;

/*
				HW 3 (7pts, Due: 10/13 23:59PM)
Complete a class Matrix2 by inheriting the class Matrix that you made in HW2. 
Your Matrix2 class should support the following functionalities:

1. zeros()
This function is newly added in Matrix2, which makes the given matrix a zero matrix. 
That is, all elements of the given matrix should be zeros.

2. eyes()
Another new function eyes() makes the given matrix the identity matrix.

3. show()
The show() function of the class Matrix is redefined in class Matrix2.
Now, this function only displays the biggest element of the matrix. 

4. You are free to modify the previous class Matrix if necessary, but you need to use inheritance to create class Matrix2.
Make sure all functions (including those of HW2) are working as intended.
Also, any errors in the previous HW2 code should be corrected. Only then can you get a full score. 


Submit this file to the LMS.
*/


//Your code goes here.
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

    virtual void show(){
        for (auto & i : array) {
            for (int j : i)
                cout << "| " << j << " |";
            cout << endl;
        }
    };

private:
    int array[ROW][COL]{};
};

class Matrix2: public Matrix {
public:
    void show() override{
        int max = INT_MIN;
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if( array[i][j] > max) {
                    max = array[i][j];
                }
            }
        }
        cout << max << endl;
    };

    void zeros(){
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                array[i][j] = 0;
            }
        }
    };

    void eyes() {
        for (int i = 0; i < ROW; ++i) {
            for (int j = 0; j < COL; ++j) {
                if (i == j) {
                    array[i][j] = 1;
                }
                else array[i][j] = 0;
            }
        }
    };

private:
    int array[ROW][COL]{};
};


//DO NOT TOUCH THE MAIN FUNCTION.
int main() {

	Matrix A, B, C;		// 3 by 3 matrix created. All values are intialized as non-zero integers.

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


	//added for HW3
	Matrix2 F;
	cout << "Zero Matrix" << endl;
	F.zeros();			// zero all elements.
	F.Matrix::show();	// call the show() of the base.
	F.show();			// diplay the biggest element.

	cout << "Identity Matrix" << endl;
	F.eyes();			// make F the identity matrix.
	F.Matrix::show();
	F.show();

	return 0;
}