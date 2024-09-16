#include <stdio.h>
#include <math.h>

FILE *file = NULL;

typedef struct {
    double x;
    double y;
} Vector2;

void soln(double a, double b, double c, double *root1, double *root2);

double dist(Vector2 A, Vector2 B);

void lineGen(Vector2 A, Vector2 B, int numPoints);

int main() {
	double a1, a2, y1 = 2, x2 = 9, y2 = 8;
	double a = 1, b = -18, c = 17;

	soln(a, b, c, &a1, &a2);

	Vector2 A1 = {a1, y1};
	Vector2 A2 = {a2, y1};
	Vector2 B = {x2, y2};

    	// Open the file for writing
	file = fopen("points.dat", "w");
    	if (file == NULL) {
        	fprintf(stderr, "Error opening file.\n");
        	return 1;
    	}
    	    
    	fprintf(file, "%lf %lf\n", A1.x, A1.y);
	fprintf(file, "%lf %lf\n", A2.x, A2.y);
	fprintf(file, "%lf %lf\n", B.x, B.y);
    	fclose(file);

	lineGen(A1, B, 20);
	lineGen(A2, B, 20);

    	printf("Distance between A1 and B : %lf\n", dist(A1, B));
	printf("Distance between A2 and B : %lf\n", dist(A2, B));
    	return 0;
}

void soln(double a, double b, double c, double *root1, double *root2) {
	double d = b*b - 4*a*c;
	*root1 = (-b + sqrt(d)) / (2*a);
        *root2 = (-b - sqrt(d)) / (2*a);
}

double dist(Vector2 A, Vector2 B) {
	return sqrt(pow(A.x-B.x,2)+pow(A.y-B.y,2));
}

void lineGen(Vector2 A, Vector2 B, int numPoints) {
	file = fopen("points.dat", "a");
    	if (file == NULL) {
        	perror("Error opening file");
        	return;
    	}

    	for (int i = 0; i <= numPoints; ++i) {
        	double t = (double)i / (double)numPoints;
        	double x = A.x + t * (B.x - A.x);
        	double y = A.y + t * (B.y - A.y);
        	fprintf(file, "%lf %lf\n", x, y);
    	}
    	fclose(file);
}
