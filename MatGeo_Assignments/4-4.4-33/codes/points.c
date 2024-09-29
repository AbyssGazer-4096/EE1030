#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include "libs/matfun.h"
#include "libs/geofun.h"

// Function to generate points on the plane given normal vector N and constant c
void generate_plane_points(FILE *fptr, double **N, double c, int num_points) {
    for (int i = 0; i < num_points; i++) {
        // Create random x and y offsets
        double x_offset = (rand() % 100) / 10.0; // Random value for x
        double y_offset = (rand() % 100) / 10.0; // Random value for y
        
        // Calculate z using the plane equation
        double z = (c - (N[0][0] * x_offset + N[1][0] * y_offset)) / N[2][0];

        // Write the point to the file
        fprintf(fptr, "%lf,%lf,%lf\n", x_offset, y_offset, z);
    }
}

int main() {
    // Define the normal vector N (3D example)
    int m = 3, n = 1;
    
    // Create matrix N for the normal vector
    double **N = createMat(m, n);
    N[0][0] = 1; // n1
    N[1][0] = 2; // n2
    N[2][0] = 3; // n3
    double c = 10; // Example constant

    // Open the file
    FILE *fptr = fopen("points.txt", "w");
    if (fptr == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Define four points A, B, C, D
    double A[3] = {3, 2, 1}; // Point A coordinates
    double B[3] = {4, 5, 5}; // Point B coordinates
    double C[3] = {4, 2, -2}; // Point C coordinates
    double D[3] = {6, 5, -1}; // Point D coordinates

    // Write custom points A, B, C, D to the file
    fprintf(fptr, "%lf,%lf,%lf\n", A[0], A[1], A[2]);
    fprintf(fptr, "%lf,%lf,%lf\n", B[0], B[1], B[2]);
    fprintf(fptr, "%lf,%lf,%lf\n", C[0], C[1], C[2]);
    fprintf(fptr, "%lf,%lf,%lf\n", D[0], D[1], D[2]);

    // Generate additional points on the plane
    generate_plane_points(fptr, N, c, 100); // Generate 100 random points

    // Free the matrix
    freeMat(N, m);

    // Close the file
    fclose(fptr);
    return 0;
}
