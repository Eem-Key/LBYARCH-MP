#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

extern void x64Acceleration(long long int y, float* array, int* output);

void computeAcceleration(long long int y, int cols, float* array, int* output) {

	for (int i = 0; i < y * cols; i += 3) {
		float initial_velocity = array[i];
		float final_velocity = array[i + 1];
		float time = array[i + 2];

		float acceleration = (((final_velocity - initial_velocity) * 1000) / 3600) / time;
		output[i / 3] = (int)round(acceleration);
	}
}

int main() {
	long long int y;
	int cols = 3;
	printf("Enter an integer: ");
	scanf_s("%lld", &y);

	long long int total_elements = y * cols;

	// -------------------------------------------------------------- Initialize the array
	float* array = malloc(total_elements * sizeof(float*));

	int* output = malloc(y * sizeof(int));

	// -------------------------------------------------------------- Fill the array with values
	printf("Enter the elements of the array:\n");
	for (int i = 0; i < y * cols; i += 3) {
		scanf_s("%f,%f,%f", &array[i], &array[i + 1], &array[i + 2]);
	}

	// -------------------------------------------------------------- Initialize Clock
	clock_t start, end;
	double time_taken;

	// -------------------------------------------------------------- C Programming
	start = clock();
	computeAcceleration(y, cols, array, output);
	end = clock();
	time_taken = ((double)(end - start) * 1000 / CLOCKS_PER_SEC);
	printf("Time (in C, ms) = %lf ms\n", time_taken);
	
	
	for (int i = 0; i < y; i++)
		printf("Row %d: %d\n", i + 1, output[i]);

	// -------------------------------------------------------------- END of C Programming

	// -------------------------------------------------------------- Reset the output
	free(output);
	output = malloc(y * sizeof(int));
	// -------------------------------------------------------------- END of Reset of output

	// -------------------------------------------------------------- Assembly
	start = clock();
	x64Acceleration(y, array, output);
	end = clock();
	time_taken = ((double)(end - start) * 1000 / CLOCKS_PER_SEC);
	printf("Time (in x86-64, ms) = %lf ms\n", time_taken);

	for (int i = 0; i < y; i++)
		printf("x86-64 Row %d: %d\n", i + 1, output[i]);

	// -------------------------------------------------------------- END of Assembly
	printf("\n");

	// ----------------------------------------------------------------------------------------------------------- TESTINGGGG
	printf("----------------- Start of Testing -----------------\n\n");

	int input_y[4] = { 10, 100, 1000, 10000 };

	for (int j = 0; j < 4; j++) {
		printf("Input row size = %d \n\n", input_y[j]);
		y = input_y[j];
		long long int total_elements = y * cols;

		// -------------------------------------------------------------- Initialize the array
		float* array = malloc(total_elements * sizeof(float*));

		int* output = malloc(y * sizeof(int));

		// -------------------------------------------------------------- Fill the array with values
		for (int i = 0; i < total_elements; i += 3) {
			float randomFloat = ((float)rand() / RAND_MAX) * 100;
			float randomFloat2 = ((float)rand() / RAND_MAX) * 100;
			float randomTime = (float)(0.5 + ((float)rand() / RAND_MAX) * (20.0 - 0.5));
			array[i] = randomFloat;
			array[i + 1] = randomFloat2;
			array[i + 2] = randomTime;
		}
		//tihiuiuhiuh
		// -------------------------------------------------------------- Initialize Clock
		clock_t start, end;
		double time_taken;

		// -------------------------------------------------------------- C Programming
		double average_time_c = 0.0;
		for (int i = 0; i < 30; i++) {
			start = clock();
			computeAcceleration(y, cols, array, output);
			end = clock();
			time_taken = ((double)(end - start) * 1000 / CLOCKS_PER_SEC);
			average_time_c += time_taken;
		}
		average_time_c /= 30;
		printf("Average Time (in C, ms) = %lf ms\n", average_time_c);
		


		for (int i = 0; i < 10; i++)
			printf("Row %d: %d\n", i + 1, output[i]);

		// -------------------------------------------------------------- END of C Programming

		// -------------------------------------------------------------- Reset the output
		free(output);
		output = malloc(y * sizeof(int));
		// -------------------------------------------------------------- END of Reset of output

		// -------------------------------------------------------------- Assembly
		double average_time_asm = 0.0;
		for (int i = 0; i < 30; i++) {
			start = clock();
			x64Acceleration(y, array, output);
			end = clock();
			time_taken = ((double)(end - start) * 1000 / CLOCKS_PER_SEC);
			average_time_asm += time_taken;
		}
		average_time_asm /= 30;
		printf("Average Time (in x86-64, ms) = %lf ms\n", average_time_asm);

		for (int i = 0; i < 10; i++)
			printf("x86-64 Row %d: %d\n", i + 1, output[i]);

		// -------------------------------------------------------------- END of Assembly
		printf("\n");
	}
	return 0;
}