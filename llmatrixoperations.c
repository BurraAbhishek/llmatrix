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
 * Matrix operations,
 * compatible with llmatrix.h
 */
#include "llmatrix.h"
#include <stdio.h>
#include <stdbool.h>

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
    double m1_value, m2_value, result_value;
    if (canAdd(m1, m2))
    {
        for(int i=0; i<rows(&m1); i++)
        {
            for(int j=0; j<columns(&m1); j++)
            {
                m1_value = getData(m1, i, j);
                m2_value = getData(m2, i, j);
                result_value = m1_value + m2_value;
                insert(&result, i, j, result_value);
            }
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
    double m1_value, m2_value, result_value;
    if (canMultiply(m1, m2))
    {
        // INCOMPLETE. This is only addition.
        // TODO: Coming up, an extremely slow multiplication algorithm, 
        // going to o(n3). In later versions, replace with 
        // an implementation of the currently fastest algorithm.
        for(int i=0; i<rows(&m1); i++)
        {
            for(int j=0; j<columns(&m1); j++)
            {
                m1_value = getData(m1, i, j);
                m2_value = getData(m2, i, j);
                result_value = m1_value + m2_value;
                insert(&result, i, j, result_value);
            }
        }
    }
    return result;
}
