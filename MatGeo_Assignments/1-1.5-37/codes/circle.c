#include <stdio.h>
#include <math.h>

double secForm(double n1, double n2, double k) {
	return ((k * n2 + n1)/(k + 1));
}

int main() {
    // Parameters for the circle
    double x1 = -6, y1 = 3, x2 = 6, y2 = 4, k = 1;
    double centerX = secForm(x1, x2, k);  // x-coordinate of the center
    double centerY = secForm(y1, y2, k);  // y-coordinate of the center
    int num_points = 100;  // Number of points to generate

    double radius = sqrt(pow(x2-x1, 2)+pow(y2-y1, 2)) / 2.0;
    double angle_step = 2 * M_PI / num_points;

    printf("%f %f\n", centerX, centerY);

    // Open the file for writing
    FILE *file = fopen("points.dat", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }
        
    fprintf(file, "%f %f\n", x1, y1);
    fprintf(file, "%f %f\n", x2, y2);
    fprintf(file, "%f %f\n", centerX, centerY);

    // Generate the points
    for (int i = 0; i <= num_points; ++i) {
        double angle = i * angle_step;
        double x = centerX + radius * cos(angle);
        double y = centerY + radius * sin(angle);

        fprintf(file, "%f %f\n", x, y);
    }

    // Close the file
    fclose(file);

    return 0;
}
