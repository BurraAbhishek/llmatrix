/**
 * Using single linked lists, 
 * we make immutable matrices 
 */
#include "llmatrix.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * A test case. Change these values as needed
 */
void TestCase(struct matrix **c)
{
    struct matrix *m;
    m = *c;
    insert(&m, 0, 0, 1);
    insert(&m, 0, 1, 2);
    insert(&m, 0, 2, 3);
    insert(&m, 0, 3, 4);
    insert(&m, 0, 4, 5);
    insert(&m, 1, 0, 2);
    insert(&m, 1, 1, 4);
    insert(&m, 1, 2, 6);
    insert(&m, 1, 3, 8);
    insert(&m, 1, 4, 10);
    insert(&m, 2, 0, 3);
    insert(&m, 2, 1, 6);
    insert(&m, 2, 2, 9);
    insert(&m, 2, 3, 12);
    insert(&m, 2, 4, 15);
    insert(&m, 3, 0, 4);
    insert(&m, 3, 1, 8);
    insert(&m, 3, 2, 12);
    insert(&m, 3, 3, 16);
    insert(&m, 3, 4, 20);
    insert(&m, 4, 0, 5);
    insert(&m, 4, 1, 10);
    insert(&m, 4, 2, 15);
    insert(&m, 4, 3, 20);
    insert(&m, 4, 4, 25);
    *c = m;
}

// Test case. Replace if necessary
int main()
{
    struct matrix *m = NULL;
    struct matrix *n = NULL;
    struct matrix *s = NULL;
    struct matrix *p = NULL;
    TestCase(&m);
    TestCase(&n);
    s = add(m, n);
    p = multiply(m, n);
    display(s);
    display(p);
}