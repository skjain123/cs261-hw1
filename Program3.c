/* CS261- HW1 - Program3.c*/
/* Name: Sunil Jain
 * Date: 1/18/24
 * Solution description: generates an array of random ints, sorts that array (min->max) and prints both unsorted and sorted
 */
 
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {

	int temp = *a;
	*a = *b;
	*b = temp;

}

void sort(int* number, int n){
     /*Sort the array of integeres of length n*/
 	int i;
	int j;
	for (i = 0; i < n; i = i + 1) {
		for (j = 0; j < n; j = j + 1) {
			if (j+1 < n) {
				if (number[j] > number[j+1]) {
					swap(&number[j], &number[j+1]);
				}
			}
		}
	
	}
		
}

int main(){
	srand(time(NULL));
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    /*Allocate memory for an array of n integers using malloc.*/
    int* array = (int*) malloc(n * sizeof(int));
    /*Fill this array with random numbers, using rand().*/
    int i;
    for (i = 0; i < n; i = i + 1) {
    	array[i] = rand();
    }
    /*Print the contents of the array.*/
	for (i = 0; i < n; i = i + 1) {
        	printf("%d ", array[i]);
    	}
	printf("\n\n");
    /*Pass this array along with n to the sort() function of part a.*/
    sort(array, n);
    /*Print the contents of the array.*/    
    for (i = 0; i < n; i = i + 1) {
        printf("%d ", array[i]);
    }
    
    printf("\n");

    return 0;
}
