#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "libs/matfun.h"
#include "libs/geofun.h"

void point_gen(FILE *fptr, double **A, double **direction_vector, int no_rows, int no_col, int num_points) {
    double **output;
    for (double i = -num_points/2; i <= num_points/2; i++) {
        output = Matadd(A, Matscale(direction_vector,no_rows,no_col,(double) i/num_points), no_rows, no_col);
        fprintf(fptr, "%lf %lf\n", output[0][0], output[1][0]);
        freeMat(output, no_rows);
    }
}

int main(){
    double x1 = 3, y1 = 6, x2 = -3, y2 = 4;
    int m = 2, n = 1;
    double **A, **B, **midpoint, **s_ab, **bisectorABMidpoint;

    A = createMat(m, n);
    B = createMat(m, n);
    midpoint = createMat(m, n);

    A[0][0] = x1;
    A[1][0] = y1;
    B[0][0] = x2;
    B[1][0] = y2;

    // Calculate the midpoint of AB
    midpoint = Matadd(A, B, m, n);
    midpoint = Matscale(midpoint, m, n, 1.0/2);

    // Calculate the vector AB and then the perpendicular bisector vector
    s_ab = Matsub(B, A, m, n);
    bisectorABMidpoint = normVec(s_ab);

    // Open file to write points
    FILE *fptr;
    fptr = fopen("points.dat", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    fprintf(fptr, "%lf %lf\n", x1, y1);
    fprintf(fptr, "%lf %lf\n", x2, y2);
    fprintf(fptr, "%lf %lf\n", midpoint[0][0], midpoint[1][0]);

    // Generate points on the perpendicular bisector
    point_gen(fptr, midpoint, bisectorABMidpoint, m, n, 20);
	
    // Close the file
    fclose(fptr);

    // Free all allocated memory
    freeMat(A,m);
    freeMat(B,m);
    freeMat(midpoint,m);
    freeMat(s_ab,m);
    freeMat(bisectorABMidpoint,m);
    return 0;
}
