#include <stdio.h>
#include <math.h>

double secForm(double n1, double n2, double k) {
	return ((k * n2 + n1)/(k + 1));
}

double normal(double x1, double y1, double x2, double y2) {
	return ((x2-x1)/(y1-y2));
}

int main() {
    // Parameters for the circle
    double x1 = 3, y1 = 6, x2 = -3, y2 = 4, k = 1;
    double x0 = secForm(x1, x2, k);  // x-coordinate of the center
    double y0 = secForm(y1, y2, k);  // y-coordinate of the center
    double n = normal(x1, y1, x2, y2); // slope of normal
    int num_points = 2;  // Number of points to generate

        // Open the file for writing
    FILE *file = fopen("points.dat", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }
        
    fprintf(file, "%f %f\n", x1, y1);
    fprintf(file, "%f %f\n", x2, y2);
    fprintf(file, "%f %f\n", x0, y0);

    for (double i = -num_points; i <= num_points; i+=0.1) {
        double x = x0 + i;
	double y = y0 + n*i;
	fprintf(file, "%lf %lf\n", x, y);
    }

    // Close the file
    fclose(file);

    printf("y + %.1lfx = %.1lf\n", -n, y0-n*x0);
    return 0;
}
