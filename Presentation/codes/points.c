#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "libs/matfun.h"
#include "libs/geofun.h"

void line_gen(FILE *fptr, double **A, double **dir_vector, int no_rows, int no_cols, int num_points_1, int num_points_2) {
    double **output;
    for (int i = -num_points_1; i <= num_points_2; i++) {
        output = Matadd(A, Matscale(dir_vector,no_rows,no_cols,(double)i/(num_points_1 + num_points_2)), no_rows, no_cols);
        fprintf(fptr, "%lf %lf\n", output[0][0], output[1][0]);
        freeMat(output, no_rows);
    }
}

int main(){
    double x1 = 3.0, y1 = 6.0, x2 = -3.0, y2 = 4.0;
    int m = 2, n = 1;
    int k1 = 10, k2 = 10;
    double **A, **B, **mid_point, **s_ab, **bisectorABMidpoint;

    A = createMat(m, n);
    B = createMat(m, n);
    mid_point = createMat(m, n);

    A[0][0] = x1;
    A[1][0] = y1;
    B[0][0] = x2;
    B[1][0] = y2;

    // Calculate the midpoint of AB
    mid_point = Matscale(Matadd(A, B, m, n), m, n, 0.5);

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
    fprintf(fptr, "%lf %lf\n", mid_point[0][0], mid_point[1][0]);

    // Generate points on the perpendicular bisector
    line_gen(fptr, mid_point, bisectorABMidpoint, m, n, 10, 10);
	
    // Close the file
    fclose(fptr);

    // Free all allocated memory
    freeMat(A,m);
    freeMat(B,m);
    freeMat(mid_point,m);
    freeMat(s_ab,m);
    freeMat(bisectorABMidpoint,m);
    return 0;
}
