#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#include "libs/matfun.h"
#include "libs/geofun.h"

void line_gen(FILE *fptr, double **A, double **dir_vector, int no_rows, int no_cols, double num_units_1, double num_units_2, int num_points) {
    double **output;
    double **unit_dir_vector = Matscale(dir_vector, no_rows, no_cols, 1/Matnorm(dir_vector, no_rows));
    for (double i = -num_units_1; i <= num_units_2; i += (num_units_1 + num_units_2)/num_points) {
        output = Matadd(A, Matscale(unit_dir_vector,no_rows,no_cols, i), no_rows, no_cols);
        fprintf(fptr, "%lf %lf\n", output[0][0], output[1][0]);
        freeMat(output, no_rows);
    }
}

int main(){
    double x1 = 3.0, y1 = 6.0, x2 = -3.0, y2 = 4.0;
    int m = 2, n = 1;
    int k1 = 4, k2 = 4, res = 20;
    double **A, **B, **mid_point, **m_ab, **n_ab;

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
    m_ab = Matsub(B, A, m, n);
    n_ab = normVec(m_ab);

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
    line_gen(fptr, mid_point, n_ab, m, n, k1, k2, res);
	
    // Close the file
    fclose(fptr);

    // Free all allocated memory
    freeMat(A,m);
    freeMat(B,m);
    freeMat(mid_point,m);
    freeMat(m_ab,m);
    freeMat(n_ab,m);
    return 0;
}
