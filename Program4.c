/* CS261- HW1 - Program4.c*/
/* Name: Sunil Jain
 * Date: 1/18/24
 * Solution description: generates 10 students with randomized initials and scores (1-100). it prints the 10 students, sorts them by thier initials (A-Z), then prints the 10 students in order.
 */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

struct student{
	char initials[2];
	int score;
};

void output(struct student* students){
        int i;
        for (i = 0; i < 10; i = i + 1) {
                printf("%d. %c%c %d\n", i + 1, students[i].initials[0], students[i].initials[1], students[i].score);
        }
        printf("\n");
}

void swap(struct student* a, struct student* b) {	
	struct student temp = *a;
	*a = *b;
	*b = temp;
}

void sort(struct student* students, int n){
     /*Sort n students based on their initials*/
        int i;
        int j;
        for (i = 0; i < n; i = i + 1) {
                for (j = 0; j < n; j = j + 1) {
                        if (j+1 < n && students[j+1].initials[0] <= 'Z' && students[j+1].initials[0] >= 'A') {
				if (students[j].initials[0] > students[j+1].initials[0]) {
                                        swap(&students[j], &students[j+1]);
				} else if (students[j].initials[0] == students[j+1].initials[0]) {
					if (students[j].initials[1] > students[j+1].initials[1]) {
                                        	swap(&students[j], &students[j+1]);
                                	}
				}
                        }
                }
        }
}

void generate(struct student* students){
     /*Generate random initials and scores for ten students.
        The two initial letters must be capital and must be between A and Z.
        The scores must be between 0 and 100*/

        int i;
        for (i = 0; i < 10; i = i + 1) {
                students[i].initials[0] = 'A' + rand() % 26;
                students[i].initials[1] = 'A' + rand() % 26;
                students[i].score = rand() % 100;
        }
}

int main(){
	srand(time(NULL));
    /*Declare an integer n and assign it a value.*/
	int n = 20;
    /*Allocate memory for n students using malloc.*/
	if (n > 0) {
		printf("\n");
		struct student* array = (struct student*)malloc(n * sizeof(struct student*));
		/*Generate random initials and scores for the n students, using rand().*/
		generate(array);
		/*Print the contents of the array of n students.*/
        	output(array);
    		/*Pass this array along with n to the sort() function*/
        	sort(array, n);
    		/*Print the contents of the array of n students.*/
        	output(array);
        	free(array);
	} else {
		printf("You must have at least one student in the list!\n");
	}
    return 0;
}
