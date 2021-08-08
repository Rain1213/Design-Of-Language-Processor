/*
This is a prototype program that works on a DFA with atmost 9 states and 9 inputs.
*/

#include <stdio.h>
#include <stdlib.h>

//array will form the transition table
int array[10][10];
//aStates are the accepting states
int aStates[10];

//Function that simulates the transition after taking current state and input as arguments
 int transition( int inputState, int transitionInput){
 	
 	inputState = array[inputState][transitionInput];
 	return inputState;
 }

int main(){
	
	int inputRow, inputCol,iIterate,jIterate,aNum, numFromChar,inputSt,startState, check=0;
	char charFromString;
	FILE *fp;
	
	//Input string stored in txt file
	fp = fopen("test.txt","r");
	
	//Ask use for number of states
	printf("Enter the number of states\n");
	scanf("%d", &inputRow);
	printf("Enter the number of inputs\n");
	scanf("%d", &inputCol);
	
	for(iIterate=1 ;iIterate<=inputRow ; iIterate++){
		
		for(jIterate=1; jIterate<=inputCol ; jIterate++){
			
			printf("input %d would change state %d to: ",jIterate,iIterate);
			scanf("%d", &array[iIterate][jIterate]);
		}
	}
	printf("\n");
	
	// Printing Transition Table
	for(iIterate=0 ;iIterate<=inputRow ; iIterate++){
		
		for(jIterate=0; jIterate<=inputCol ; jIterate++){
			
			if(iIterate==0 && jIterate==0){
				printf("TABLE\t");
				
			}
			else if(iIterate==0){
				printf("Input%d\t",jIterate);
			}
			else if(jIterate==0){
				printf("State%d\t",iIterate);
			}
			else{
				printf(" %d\t",array[iIterate][jIterate]);
			}
			
		}
		printf("\n");
	}
	//Starting state
	printf("which state would u like to start with: ");
	scanf("%d",&startState);
	
	//Accepting States
	printf("Enter the number of accepting states: ");
	scanf("%d",&aNum);
	printf("Enter the index for accepting states [1: 1st State]\nin ascending order \n");
	for(iIterate=1;iIterate<=aNum; iIterate++){
		scanf("%d", &aStates[iIterate]);
	}
	
	//DFA Starts from starting state
	inputSt = startState;
		
	// Reading all characters from input String one by one until End of File
	while((charFromString =fgetc(fp)) != EOF){
		
		numFromChar = charFromString - '0';
		if(numFromChar >=0){
			inputSt = transition(inputSt, numFromChar);
		}
		
	}
	
	//Check if the current state we stopped at is an accepting state
	for(iIterate=0; iIterate<=10; iIterate++){
		if(aStates[iIterate] == inputSt){
			check = 1;
		}
	}
	if(check == 1){
		printf("String Accepted\n");
	}
	else{
		printf("String Rejected\n");
	}
	return 0;
}

