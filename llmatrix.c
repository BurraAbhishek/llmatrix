/**
 * Copyright 2021 Burra Abhishek
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 * 
 */

/**
 * Source code from:
 * https://github.com/BurraAbhishek/llmatrix/
 * 
 * Using single linked lists, 
 * we make immutable matrices. 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * Data structure which holds the matrix
 */
struct matrix
{
    double data;
    struct matrix *nextRow;
    struct matrix *nextColumn;
} matrix = {.data = 0};

/**
 * Returns the number of rows of the matrix
 * @param matrix(struct)
 * @return rows(int)
 */
int rows(struct matrix **m)
{
    struct matrix *c = (struct matrix *)malloc(sizeof(struct matrix));
    c = *m;
    int rows = 0;
    if (c != NULL)
    {
        while (c != NULL)
        {
            rows++;
            c = c->nextRow;
        }
    }
    return rows;
}

/**
 * Returns the number of columns of the matrix
 * @param matrix(struct)
 * @return columns(int)
 */
int columns(struct matrix **m)
{
    struct matrix *c = (struct matrix *)malloc(sizeof(struct matrix));
    c = *m;
    int columns = 0;
    if (c != NULL)
    {
        while (c != NULL)
        {
            columns++;
            c = c->nextColumn;
        }
    }
    return columns;
}

/**
 * Inserts a number into the matrix
 * @param matrix(struct): The matrix to insert the value into.
 * @param rowPosition(int): The row to insert the value into, starting from 0
 * @param colPosition(int): The column to insert the value into, starting from 0
 * @param value(double): The value to be inserted
 * @return None
 */
void insert(struct matrix **m, int rowPosition, int colPosition, double value)
{
    if ((rowPosition == 0) && (colPosition == 0))
    {
        if ((rows(m) == 0) && (columns(m) == 0))
        {
            struct matrix *d = (struct matrix *)malloc(sizeof(struct matrix));
            d->data = value;
            d->nextRow = NULL;
            d->nextColumn = NULL;
            *m = d;
        }
        else
        {
            struct matrix *d;
            d = *m;
            d->data = value;
            *m = d;
        }
    }
    else if (rowPosition == 0)
    {
        if (colPosition < columns(m))
        {
            struct matrix *d;
            d = *m;
            for (int i = 1; i < colPosition; i++)
            {
                d = d->nextColumn;
            }
            d->data = value;
        }
        else if (colPosition == columns(m))
        {
            struct matrix *d;
            d = *m;
            while (d->nextColumn != NULL)
            {
                d = d->nextColumn;
            }
            struct matrix *n = (struct matrix *)malloc(sizeof(struct matrix));
            n->data = value;
            n->nextRow = NULL;
            n->nextColumn = NULL;
            d->nextColumn = n;
        }
        else
        {
            struct matrix *d;
            d = *m;
            while (d != NULL)
            {
                d = d->nextColumn;
            }
            for (int i = 0; i < colPosition - columns(m); i++)
            {
                insert(&d, rowPosition, i, 0);
                d = d->nextColumn;
            }
            insert(&d, rowPosition, colPosition, value);
        }
    }
    else if (colPosition == 0)
    {
        if (rowPosition < rows(m))
        {
            struct matrix *d;
            d = *m;
            for (int i = 1; i < rowPosition; i++)
            {
                d = d->nextRow;
            }
            d->data = value;
        }
        else if (rowPosition == rows(m))
        {
            struct matrix *d;
            d = *m;
            while (d->nextRow != NULL)
            {
                d = d->nextRow;
            }
            struct matrix *n = (struct matrix *)malloc(sizeof(struct matrix));
            n->data = value;
            n->nextRow = NULL;
            n->nextColumn = NULL;
            d->nextRow = n;
        }
        else
        {
            struct matrix *d;
            d = *m;
            while (d != NULL)
            {
                d = d->nextRow;
            }
            for (int i = 0; i < rowPosition - rows(m); i++)
            {
                insert(&d, i, colPosition, 0);
                d = d->nextRow;
            }
            insert(&d, rowPosition, colPosition, value);
        }
    }
    else
    {
        struct matrix *d;
        d = *m;
        struct matrix *e;
        e = *m;
        // In between matrix
        for (int i = 0; i < rowPosition; i++)
        {
            if (d->nextRow == NULL)
            {
                insert(&d, i, 0, 0);
            }
            d = d->nextRow;
        }
        for (int i = 0; i < colPosition; i++)
        {
            if (e->nextColumn == NULL)
            {
                insert(&e, 0, i, 0);
            }
            e = e->nextColumn;
        }
        for (int i = 0; i < colPosition - 1; i++)
        {
            if (d->nextColumn == NULL)
            {
                struct matrix *n = (struct matrix *)malloc(sizeof(struct matrix));
                n->data = 0;
                n->nextRow = NULL;
                n->nextColumn = NULL;
                d->nextColumn = n;
            }
            d = d->nextColumn;
        }
        for (int i = 0; i < rowPosition - 1; i++)
        {
            if (e->nextRow == NULL)
            {
                struct matrix *n = (struct matrix *)malloc(sizeof(struct matrix));
                n->data = 0;
                n->nextRow = NULL;
                n->nextColumn = NULL;
                e->nextRow = n;
            }
            e = e->nextRow;
        }
        if (d->nextColumn == NULL)
        {
            struct matrix *n = (struct matrix *)malloc(sizeof(struct matrix));
            n->data = value;
            n->nextRow = NULL;
            n->nextColumn = NULL;
            d->nextColumn = n;
            e->nextRow = n;
        }
        else
        {
            d->nextColumn->data = value;
        }
    }
}

/**
 * Display the contents of the matrix in the form 'coordinates -> data'
 * For example, if the first cell stores a value 1, it is displayed as '(0, 0) -> 1'
 * @param struct matrix *m
 */
void display(struct matrix *m)
{
    struct matrix *n;
    struct matrix *h = m;
    int r = 0;
    int c;
    while (h != NULL)
    {
        c = 0;
        n = h;
        while (n != NULL)
        {
            printf("(%d, %d) -> %lf\n", r, c, n->data);
            n = n->nextColumn;
            c++;
        }
        h = h->nextRow;
        r++;
    }
}

/**
 * Retrieves data in a matrix from a given position
 * @param matrix(struct): The matrix to retrieve the value from.
 * @param rowPosition(int): The row to retrieve the value from, starting from 0
 * @param colPosition(int): The column to retrieve the value from, starting from 0
 * @return value(double): The required value, 0 if position out of bounds.
 */
double getData(struct matrix *m, int rowPosition, int colPosition)
{
    double value = 0;
    struct matrix *n;
    struct matrix *h = m;
    if ((rowPosition < rows(&m)) && (colPosition < columns(&m)))
    {
        n = h;
        for (int i = 0; i < rowPosition; i++)
        {
            n = n->nextRow;
        }
        for (int j = 0; j < colPosition; j++)
        {
            n = n->nextColumn;
        }
        value = n->data;
    }
    return value;
}

// Format conversions

/**
 * Convert a two-dimensional array into struct matrix
 * @param rows(int): The number of rows of the 2D array
 * @param columns(int): The number of columns of the 2D array
 * @return struct matrix *: The matrix form of the 2D array
 */
struct matrix *arrayToMatrix(int rows, int columns, double array[][columns])
{
    struct matrix *result = NULL;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            insert(&result, i, j, array[i][j]);
        }
    }
    return result;
}

/**
 * Convert a matrix into two-dimensional array
 * @param struct matrix*: The matrix to convert
 * @return array(double[][]): The 2D array form of the matrix
 */
double **MatrixToArray(struct matrix *m)
{
    struct matrix *n;
    struct matrix *h = m;
    int row = rows(&m);
    int column = columns(&m);
    double *a = calloc(row * column, sizeof(double));
    double **array = malloc(column * sizeof(double *));
    int r = 0;
    int c;
    while (h != NULL)
    {
        c = 0;
        n = h;
        while (n != NULL)
        {
            array[r][c] = n->data;
            n = n->nextColumn;
            c++;
        }
        h = h->nextRow;
        r++;
    }
    return array;
}

// Matrix operations

/**
 * Determine if two matrices can be added
 * @param matrix(struct) m1: The first matrix
 * @param matrix(struct) m2: The second matrix
 * @returns bool: True, if the two matrices can be added, false otherwise
 */
bool canAdd(struct matrix *m1, struct matrix *m2)
{
    return ((rows(&m1) == rows(&m2)) && (columns(&m1) == columns(&m2)));
}

/**
 * Determine if two matrices can be multiplied
 * @param matrix(struct) m1: The first matrix
 * @param matrix(struct) m2: The second matrix
 * @returns bool: True, if the two matrices can be multiplied, false otherwise
 */
bool canMultiply(struct matrix *m1, struct matrix *m2)
{
    return (columns(&m1) == rows(&m2));
}

/**
 * Adds two matrices
 * @param matrix(struct) m1: The first matrix
 * @param matrix(struct) m2: The second matrix
 * @returns matrix(struct) sum || null: The sum of the two matrices
 */
struct matrix *add(struct matrix *m1, struct matrix *m2)
{
    struct matrix *result = NULL;
    if (canAdd(m1, m2))
    {
        double m1_value, m2_value, result_value;
        struct matrix *n1;
        struct matrix *h1 = m1;
        struct matrix *n2;
        struct matrix *h2 = m2;
        int r = 0;
        int c;
        while (h1 != NULL)
        {
            c = 0;
            n1 = h1;
            n2 = h2;
            while (n1 != NULL)
            {
                m1_value = n1->data;
                m2_value = n2->data;
                result_value = m1_value + m2_value;
                insert(&result, r, c, result_value);
                n1 = n1->nextColumn;
                n2 = n2->nextColumn;
                c++;
            }
            h1 = h1->nextRow;
            h2 = h2->nextRow;
            r++;
        }
    }
    return result;
}

/**
 * Multiplies two matrices. This function currently does NOT work as intended.
 * @param matrix(struct) m1: The first matrix
 * @param matrix(struct) m2: The second matrix
 * @returns matrix(struct) product || null: The product of the two matrices
 */
struct matrix *multiply(struct matrix *m1, struct matrix *m2)
{
    struct matrix *result = NULL;
    if (canMultiply(m1, m2))
    {
        double m1_value, m2_value, result_value;
        for (int i = 0; i < rows(&m1); i++)
        {
            for (int j = 0; j < columns(&m2); j++)
            {
                result_value = 0;
                for (int k = 0; k < rows(&m2); k++)
                {
                    m1_value = getData(m1, i, k);
                    m2_value = getData(m2, k, j);
                    result_value += m1_value * m2_value;
                }
                insert(&result, i, j, result_value);
            }
        }
    }
    return result;
}
