#include <unistd.h>
#include <string.h>

int delayDefault = 40000;
int postDelayDefault = 500000;

int strLen(char string[]){
	int counter;

	for (counter = 0; string[counter] != '\0'; counter++);

	return counter;
}

void escreveBonitinho(char string[], int time, int postDelay, bool jumpLine){
	int len = strLen(string);

	for (int i = 0; i < len; i++){
		printf("%c", string[i]);
		usleep(time);
		fflush(stdout);
		
	}
	usleep(postDelay);
	if (jumpLine) { printf("\n"); }
	

}
