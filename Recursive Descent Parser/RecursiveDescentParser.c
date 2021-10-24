/*
Building a Recursive Descent Parser for the following code
E dash would be written as Ed
T dash would be written as Td
ignore spaces

E -> T Ed
Ed -> + T Ed | ^
T -> F Td
Td -> * F Td | ^
F -> ( E ) | id

Lets write a C Program for the same

*/

#include<stdio.h>
#include<string.h>

// Global Variables
int i,f;

// A variable that will store 1 grammer rule at each row
char input[50];

//Declaration of all functions
void E(void);
void Ed(void);
void T(void);
void Td(void);
void F(void);


int main(){
    i=0;
    f=0;
    // Name of txt file
    char inputFile[30];

    //variable that holds the character while traversing
    char ch;
    //get input txt file name
    printf("Enter File Name with Grammer ");
    gets(inputFile);
    
    // Traversing Pointer
    FILE *filePointer;
    filePointer = fopen(inputFile,"r");

    //reading character one by one
    while((ch = fgetc(filePointer)) != EOF){
        //Storing character in input variable
        input[i] = ch;
        i++;
    }
    
    i=0;
    // Travering through Grammer Rules
    // Starting with E as 
    E();

    if((strlen(input)==i) && (f==0)){
        printf("The String parsed Successfully");
    }
    else{
        printf("The String is Rejected");
    }
    return 0;
}

//All Functions

//E -> T Ed
void E(){
    T();
    Ed();
}

//Ed -> + T Ed | ^
void Ed(){
    if(input[i]=='+'){
        i++;
        T();
        Ed();
    }
    else{
        //signifying existing of NULL
    }
}

// T -> F Td
void T(){
    F();
    Td();
}

//Td -> * F Td | ^
void Td(){
    if(input[i]== '*'){
        i++;
        F();
        Td();
    }
    else{
        //signifying existing of NULL
    }
}

//F -> ( E ) | id
void F(){
    if(input[i]=='('){
        i++;
        E();
        if(input[i]==')'){
            i++;
        }
        else
            f=1;
    }
    else if((input[i]>='a' && input[i]<='z') || (input[i]>='A' && input[i]<='Z')){
        i++;
    }
    else
        f=1;
    
}