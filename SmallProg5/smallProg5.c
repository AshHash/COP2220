/*  Atta Saleh
 *  COP2220
 *  smallProg5.c
 *	
 *	A program that reads from a file into an array
 *	then manipulating the data in the array and 
 * 	prints it into a new file
 *
 *  3/27/2017
 */


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//reads double values from file to an array of size arraySize
void fileToArray(int arraySize, FILE *pointerToFile, double *array); 
//prints values stored in an array of size arraySize
void printFromArray(int arraySize, double *array); 
//writes double values from an array of size arraySize to a blank output file
void writeToFile(int arraySize, FILE *pointerToFile, double *array); 

int main()
{
	FILE *input, *output;
	input = fopen("doubleInput.txt", "r");
	output = fopen("doubleOutput.txt", "w");

	int i, amount;
	double doubleArray[25];

	printf("How many doubles do you want from the file? ");
	scanf("%d", &amount);

	fileToArray(amount, input, doubleArray);

	printFromArray(amount, doubleArray);

	for(i=0; i<amount; i++){
		doubleArray[i] += 2.64;
	}

	writeToFile(amount, output, doubleArray);

	fclose(input);
	fclose(output);
	return 0;
}

//reads double values from file to an array of size arraySize
void fileToArray(int arraySize, FILE *pointerToFile, double *array){
		
		int i;
		
		for(i=0; i<arraySize; i++){
		fscanf(pointerToFile, "%lf", &array[i]);
	}
}
//prints values stored in an array of size arraySize
void printFromArray(int arraySize, double *array){
		
		int i;
		
		for(i=0; i<arraySize; i++){
		printf("%f ", array[i]);
	}

}
//writes double values from an array of size arraySize to a blank output file
void writeToFile(int arraySize, FILE *pointerToFile, double *array){
	
	int i;

	for(i=0; i<arraySize; i++){
		fprintf(pointerToFile, "%f ", array[i]);
	}

} 


