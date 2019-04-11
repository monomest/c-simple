#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 


int randNum(int max, int min);
void inputOutput(int num1, int num2, int * input);

int main() {

	// random seed
	srand(time(0));

	int max = 12;
	int min = 1;
	int num1, num2, input, answer;
	int stop = 0;
	int correct = 0;
	int incorrect = 0;
	int totalq = 0;
	float percent = 0;
	clock_t t;
	double time_taken;
	double tav = 0;
	double time_total = 0;
	char yn;

	printf("This is a fun maths game! All you need to do is answer the questions as quickly and correctly as possible. \nPress '0' to stop the program. ");
	printf("Press any key to start. ");
	if (getchar() == '0') {
		return 0;
	}
	printf("=============================================\n");
	while(stop != 1){
		num1 = randNum(max, min);
		num2 = randNum(max, min);
		answer = num1*num2;
    	t = clock(); 
		inputOutput(num1, num2, &input);
		t = clock() - t; 
		if(input == 0){
			stop = 1;
		} else if (input == answer) {
			correct = correct + 1;
			totalq = totalq + 1;
			time_taken = ((double)t)/CLOCKS_PER_SEC;
    		time_total = time_total + time_taken;
    		tav = time_total/totalq;
    		printf("Correct! Time taken: %.2lf seconds\n", time_taken);
				if(correct%10 == 0){
				printf("\n\n\n");
				printf(" (\\_/)\n");
				printf("(='.'=)   Yay! You have answered %d correct questions! Average time taken: %.2lf seconds\n", correct, tav);
				printf("(\")_(\")\n");
	 	
	 			printf("\n\n");
	 			printf("Would you like to play more? y/n ");
	 			yn = getchar();
	 			getchar();
	 			if(yn == 'n'){
	 				stop = 1;
	 			}
			}
		}
		else {
			printf("Incorrect! You entered %d, but the real answer is %d.\n", input, answer);
			incorrect = incorrect + 1;
			totalq = totalq + 1;
			time_taken = ((double)t)/CLOCKS_PER_SEC;
    		time_total = time_total + time_taken;
    		tav = time_total/totalq;
		}
		if (totalq != 0){
		percent = ((float)correct/(float)totalq)*100;
		printf("Correct: %d    Incorrect: %d    Score: %.2f\n", correct, incorrect, percent);
	    } else {
	    	percent = 0;
	    }
	    printf("=============================================\n");

	}
	printf("Thanks for playing! Your overall score is:\n\n");
			printf("\n");
			printf(" (\\_/)\n");
			printf("(='.'=)   Total questions: %d   Total Correct: %d   Total Incorrect: %d   Score: %.2f     Average Time Taken: %.2lf seconds\n", totalq, correct, incorrect, percent, tav);
			printf("(\")_(\")\n\n");
	
   return(0);
}

int randNum(int max, int min) {
	return min + rand() / (RAND_MAX / (max - min + 1) + 1);
}

void inputOutput(int num1, int num2, int * input) {
	printf("%d x %d = ", num1, num2);
	scanf("%d%*c", input);
}