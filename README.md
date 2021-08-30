# llmatrix
Generate immutable matrices using the C language and linked lists.

llmatrix is simply 'linked list matrix'. These matrices are generated only using linked lists, no arrays used in active code. These matrices are currently immutable, and any attempt to change the values will result in segmentation faults.

## Getting started:
Copy and paste the file `llmatrix.c` into your working directory.

To use the file, add the following in the beginning of your source code:
```
#include "llmatrix.c"
```

## Usage:

### Initialize a matrix
```
struct matrx *m = NULL;
```
Initializes a matrix `m`.

### Insert values into a matrix
```
insert(&m, r, c, value);
```
Inserts a value `value` into a matrix `m` at position `(r, c)`. The first element is at position (0, 0). It is considered as the top left position.
#### &#9888; WARNING! Insertions must be either row-wise or column-wise. Random insertions may result in segmentation faults!
For example, insert elements into the first row from the first column to the last column in the same order. Repeat for each row, going from first row to last row.

If you are able to perform random insertions successfully, consider a pull request so that everyone can benefit from the bug fix.

### Get the number of rows in a matrix
```
int row = rows(m);
```
if m is of type struct \*, and

```
int row = rows(&m);
```
if m is of type struct \*\*

Result: `row`

### Get the number of columns in a matrix
```
int column = columns(m);
```
if m is of type struct \*, and

```
int column = columns(&m);
```
if m is of type struct \*\*

Result: `column`

### Display the matrix
```
display(m);
```
if m is of type struct \*

#### NOTE: 
Due to the unpredictable number of digits, the output is of the form `(row, column): value`

### Search for an element
```
double element = getData(m, r, c);
```
where m is of type struct \*, r is the row position, c is the column position. Returns the element in that position.

## Type conversions

### Linked list form to two-dimensional array
```
double **array;
array = MatrixToArray(m)
```
The first element of the array is `array[0][0]`
#### &#9888; WARNING! If your matrix is incomplete, using this function will cause a segmentation fault. Ensure that each row has the same number of columns and each column has the same number of rows before using this function.

### Two-dimensional array to linked list form
```
struct matrix *m = NULL;
m = arrayToMatrix(r, c, array)
```
where:
- r is the number of rows of the array
- c is the number of columns of the array

## Operations involving two matrices

### Addition
```
struct matrix *sum = NULL;
sum = add(matrix1, matrix2);
```
NOTE: The function automatically checks if the matrices can be added and returns NULL if they cannot be added.

### Multiplication
```
struct matrix *product = NULL;
product = multiply(matrix1, matrix2);
```
NOTE: The function automatically checks if the matrices can be multiplied and returns NULL if they cannot be multiplied.
