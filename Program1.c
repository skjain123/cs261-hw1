/* CS261- HW1 - Program1.c*/
/* Name: Sunil Jain
 * Date: 1/18/24
 * Solution description: Generates three random numbers, the first will be incremented, second will be decremended, third will be the difference of the the first and second
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /* Increment a */
    *a = *a + 1;
    /* Decrement  b */
    *b = *b - 1;
    /* Assign a-b to c */
    c = *a - *b;
    /* Return c */
    return c;
}

int main(){
	srand(time(NULL));
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
    
	int x = rand() % 10;
	int y = rand() % 10;
	int z = rand() % 10;

	/* Print the values of x, y and z */
    
	printf("%d %d %d \n", x ,y ,z);
			
    /* Call foo() appropriately, passing x,y,z as parameters */
	int fo = foo(&x, &y, z);
    /* Print the values of x, y and z */
    
	printf("%d %d %d \n", x ,y ,z);
	
    /* Print the value returned by foo */
 
	printf("%d \n", fo);

    /* Is the return value different than the value of z?  Why? */
    return 0;
}
    
    
