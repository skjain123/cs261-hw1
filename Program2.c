/* CS261- HW1 - Program2.c*/
/* Name: Sunil Jain
 * Date: 1/18/24
 * Solution description: allocates 10 students in an array, assigns initials and scores to each, then prints and summarizes the list of students and thier information
 */

#include <time.h>
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct student{
	char initials[2];
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
     struct student* array = (struct student*) malloc(10 * sizeof(struct student));
     /*return the pointer*/
     return array;
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

void output(struct student* students){
	int i;
	for (i = 0; i < 10; i = i + 1) {
		printf("%d. %c%c %d\n", i + 1, students[i].initials[0], students[i].initials[1], students[i].score);
	}
	printf("\n");
     /*Output information about the ten students in the format:
              1. Initials  Score
              2. Initials  Score
              ...
              10. Initials Score*/
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
     int min = 101;
     int max = 0;
     int total = 0;
     int i;
     for (i = 0; i < 10; i = i + 1) {
     	if (students[i].score < min) {
		min = students[i].score;
	}
	if (students[i].score > max) {
		max = students[i].score;
	}
	total = total + students[i].score;
     }
     printf("Min Score: %d\n", min);
     printf("Max Score: %d\n", max); 
     printf("Average Score: %d\n", total / i);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
	if (stud != NULL) {
		free(stud);
	}
}

int main(){
	srand(time(NULL));
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);
    return 0;
}
