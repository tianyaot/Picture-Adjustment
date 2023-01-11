// Project UID af1f95f547e44c8ea88730dfb185559d

#include "Matrix.h"
#include "Matrix_test_helpers.h"
#include "unit_test_framework.h"

using namespace std;


// Here's a free test for you! Model yours after this one.
// Test functions have no interface and thus no RMEs, but
// add a comment like the one here to say what it is testing.
// -----
// Fills a 3x5 Matrix with a value and checks
// that Matrix_at returns that value for each element.
TEST(test_fill_basic) {
  Matrix *mat = new Matrix; // create a Matrix in dynamic memory

  const int width = 3;
  const int height = 5;
  const int value = 42;
  Matrix_init(mat, 3, 5);
  Matrix_fill(mat, value);

  for(int r = 0; r < height; ++r){
    for(int c = 0; c < width; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), value);
    }
  }

  delete mat; // delete the Matrix
}

// ADD YOUR TESTS HERE
// You are encouraged to use any functions from Matrix_test_helpers.h as needed.

// Initialize a 3x5 Matrix with a value and check that
// Matrix_at returns that value for each element.
TEST(test_Matrix_init) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 5);
  for(int r = 0; r < 5; ++r){
    for(int c = 0; c < 3; ++c){
      ASSERT_EQUAL(*Matrix_at(mat, r, c), 0);
    }
  }

  delete mat;
}
// Initialize a 1x1 Matrix with a value and check that
// Matrix_print prints the width and height for the Matrix to os
// and prints the rows of the Matrix to os with one row per line.
TEST(test_matrix_print) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 1, 1);
  *Matrix_at(mat, 0, 0) = 42;
  ostringstream expected;
  expected << "1 1\n"
           << "42 \n";
  ostringstream actual;
  Matrix_print(mat, actual);
  ASSERT_EQUAL(expected.str(), actual.str());
  delete mat;
}

// Initialize a 3x5 Matrix with a value and check that
// Matrix_width returns the width of the matrix.
TEST(test_Matrix_width) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 5);
  ASSERT_EQUAL(Matrix_width(mat), 3);
  delete mat;
}
// Initialize a 3x5 Matrix with a value and check that
// Matrix_height returns the height of the matrix.
TEST(test_Matrix_height) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 3, 5);
  ASSERT_EQUAL(Matrix_height(mat), 5);
  delete mat;
}
// Initialize a 4x7 Matrix with a value and check that
// Matrix_row returns the row of the element 
// pointed to by ptr
TEST(test_Matrix_row) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 4, 7);
  int *ptr = Matrix_at(mat, 2, 3);
  ASSERT_EQUAL(Matrix_row(mat,ptr), 2);
  delete mat;
}
// Initialize a 5x3 Matrix with a value and check that
// Matrix_column returns the column of 
// the element pointed to by ptr
TEST(test_Matrix_column) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 5, 3);
  int *ptr = Matrix_at(mat, 2, 3);
  ASSERT_EQUAL(Matrix_column(mat,ptr), 3);
  delete mat;
}
// Initialize a 5x3 Matrix with a value and check that
// Matrix_column returns a pointer to the element in the Matrix
// at the given row and column.
TEST(test_Matrix_at) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 5, 3);
  int *ptr = Matrix_at(mat, 2, 2);
    *ptr=7;
  const int *cptr = Matrix_at(mat, 2, 2);
  ASSERT_EQUAL(*cptr, 7);
  delete mat;
}
// Initialize a 5x3 Matrix and check that
// Matrix_fill sets each element of 
// the Matrix to the given value. 
TEST(test_Matrix_fill) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 5, 3);
    int value=7;
  Matrix_fill(mat,value);
  ASSERT_EQUAL(*Matrix_at(mat,2,3), 7);
  delete mat;
}
// Initialize a 5x3 Matrix and check that
// Matrix_fill_border sets each element on the
// border of the Matrix to the given value. 
TEST(test_Matrix_fill_border) {
  Matrix *mat = new Matrix;
  Matrix_init(mat,5, 3);
  Matrix_fill_border(mat,7);
  ASSERT_EQUAL(*Matrix_at(mat, 2, 0), 7);
  delete mat;
}
// Initialize a 4x7 Matrix and check that
// Matrix_max returns the value of the 
// maximum element in the Matrix
TEST(test_Matrix_max) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 4, 7);
  Matrix_fill(mat,7);
  Matrix_fill_border(mat,8);
  ASSERT_EQUAL(Matrix_max(mat), 8);
  int *ptr = Matrix_at(mat, 2, 3);
      *ptr=9;
  ASSERT_EQUAL(Matrix_max(mat), 9);
  delete mat;
}
// Initialize a 5x3 Matrix and check that
// Matrix_Matrix_column_of_min_value_in_row 
// returns the value of the column of the element 
// with the minimal value in a particular region
TEST(test_Matrix_column_of_min_value_in_row) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 5, 3);
  Matrix_fill(mat,4);
  int *ptr1 = Matrix_at(mat, 2, 2);
    *ptr1=3;
  int *ptr2= Matrix_at(mat,2, 1);
    *ptr2=9;
  int *ptr3 = Matrix_at(mat, 2, 3);
    *ptr3=3;
  ASSERT_EQUAL(Matrix_column_of_min_value_in_row(mat, 2, 0, 5),2);
  delete mat;
}
// Initialize a 5x3 Matrix and check that
// Matrix_Matrix_min_value_in_row 
// returns the value of the element 
// with the minimal value in a particular region
TEST(test_Matrix_min_value_in_row) {
  Matrix *mat = new Matrix;
  Matrix_init(mat, 5, 3);
  Matrix_fill(mat,5);
  int *ptr1 = Matrix_at(mat, 2, 3);
    *ptr1=3;
  int *ptr2= Matrix_at(mat, 2, 4);
    *ptr2=9;
  int *ptr3 = Matrix_at(mat, 2, 2);
    *ptr3=3;
  ASSERT_EQUAL(Matrix_min_value_in_row(mat, 2, 0, 5 ),3);
  delete mat;
}


// NOTE: The unit test framework tutorial in Lab 2 originally
// had a semicolon after TEST_MAIN(). Although including and
// excluding the semicolon are both correct according to the c++
// standard, the version of g++ we are using reports a warning
// when there is a semicolon. Therefore do NOT add a semicolon
// after TEST_MAIN()
TEST_MAIN() // Do NOT put a semicolon here
