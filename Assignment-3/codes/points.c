#include <stdio.h>

void sectionFormula(float x1, float y1, float x2, float y2, float k, float *x, float *y) {
	*x = (k * x2 + x1)/(k + 1);
	*y = (k * y2 + y1)/(k + 1);
}

int main() {
	float x, y;
	float x1 = -6, y1 = 3, x2 = 6, y2 = 4;
	float k = 1;
	sectionFormula(x1, y1, x2, y2, k, &x, &y);

	FILE *file = fopen("points.txt", "w");
	if(file == NULL) {
		printf("Error opening file!\n");
		return 1;
	}

	fprintf(file, "%.2f %.2f\n", x1, y1);
	fprintf(file, "%.2f %.2f\n", x2, y2);
	fprintf(file, "%.2f %.2f\n", x, y);

	fclose(file);
	return 0;
}
