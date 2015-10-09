#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <error.h>

/** Given an integer x, find square root of it. If x is not a perfect
 * square, then return floor(√x).
 *
 * Examples:
 *
 * Input: x = 4
 * Output: 2
 *
 * Input: x = 11
 * Output: 3
 * */


int _get_squareroot(int x) {

    int cnt = 0;

    if (x <= 0) {
        printf("\n Invalid number for square root");
        return cnt;
    }

    while (x && x!= 1) {
        x = x>>1;
        cnt++;
    }

    return cnt;
}

/** Belwo progrm prints square root of integers from 1 - 10 */
void main() {

    int i = 0;

    for (i=0; i < 100; i++) {

        printf("\nsquare root of %d:=%d", i, _get_squareroot(i));
    }
} 
