/*
The following Program is meant to work as a lexical analyzer.
It will scan a code file and generate token.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*  checking for a keyword
    0: not a keyword
    1: keyword
*/
int isKeyword(char token[])
{

    char keywords[44][20] = {
        "_Alignas", "_Alignof", "_Atomic", "_Bool", "_Complex", "_Generic",
        "_Imaginary", "_Noreturn", "_Static_assert", "_Thread_local",
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "inline", "int", "long", "register", "restrict", "return",
        "short", "signed", "sizeof", "static", "struct", "switch", "typedef",
        "union", "unsigned", "void", "volatile", "while"};

    int iIterate, flag = 0;
    //Checking the word with 44 keywords; one by one
    for (iIterate = 0; iIterate < 44; iIterate++){
        if (strcmp(keywords[iIterate], token)==0){
            
            flag = 1;
            break;
        }
    }

    return flag;
}
/*
    checking for Constant or Identifier
    Invalid Symbols : 0
    Valid Constant : 1
    Valid Identifier : 2
*/

int isConstantOrIdentifier(char token[])
{

    int length=0;

    /*
    Logic:  If the token is 90.12 : length(6) = digitCount(5) + decimalCount(1)
            else maybe it is an Identifier like A9012 (must not contain '.')
                                                    (must start from alphabet or '_')

            if the token is 90.12.12 : decimalCount>=1 ; invalidToken
            
    */
    int iIterate=0;
    int decimalCount = 0;
    int digitCount = 0;
    
    while(token[iIterate]!= '\0'){
        length++;
        iIterate++;
    }
    if(length==0){
        return -1;
    }
    iIterate=0;
    if (isdigit(token[0]) || token[0] == '.')
    {

        while(token[iIterate]!= '\0')
        {

            if (isdigit(token[iIterate]))
            {
                digitCount++;
            }
            else if (token[iIterate] == '.')
            {
                decimalCount++;
            }
            iIterate++;
        }

        if ((length == decimalCount + digitCount) && (decimalCount <= 1))
        {
            return 1; //Valid Constant
        }
        else
        {
            return 0; //Invalid Constant
        }
    }
    else if (isalpha(token[0]) || token[0] == '_')
    {
        iIterate++;

        while(token[iIterate]!= '\0'){

            // if the identier contains other than alphabet, number or '_' it is invalid
            if(!isalpha(token[iIterate]) && !isdigit(token[iIterate]) && token[iIterate]!='_'){

                return 0; //Invalid Identifier
            }
            iIterate++;
        }

        //if while loop runs with returning any value, the identifier is valid
        return 2; //Valid Identifier

    }

    return 0;
}

void main()
{

    FILE *filePointer;
    char ch, char1, char2;
    char token[20];
    int tokenIndex=0;
    int iIterate;
    char fileName[30];
    
    printf("Enter your file name\n");
    scanf("%s",fileName);

    filePointer = fopen(fileName, "r");

    //Remove Comments // or /*
    while ((ch = fgetc(filePointer)) != EOF){
        
        start:
        
        /* For Ignoring Comments */
        if (ch == '/')
        {
            fseek(filePointer, 0, SEEK_CUR);
            ch = fgetc(filePointer);

            if (ch == '/')
            { // presence of '//'
                while ((ch = fgetc(filePointer)) != '\n'){
                }
            }
            else if (ch == '*')
            { // presence of '/*'

            star:
                while (((ch = fgetc(filePointer)) != '*') && (ch != EOF)){
                
                }
                if (ch = fgetc(filePointer) != '/')
                {
                    goto star;
                }
            }
            else
            {
                fseek(filePointer, -1, SEEK_CUR);
                if (ch = fgetc(filePointer) == '=')
                {
                    printf("/= is an operator\n");
                }
                else
                {
                    fseek(filePointer, -1, SEEK_CUR);
                    printf("/ is an operator\n");
                }
            }
        }

        /* For Operators*/
        if (ch == '!' || ch == '%' || ch == '+' || ch == '-' || ch == '*' || ch == '>' || ch == '=' || ch == '<')
        {
            if (ch = fgetc(filePointer) == '=')
            {
                fseek(filePointer, -2, SEEK_CUR);
                char1 = fgetc(filePointer);
                char2 = fgetc(filePointer);
                printf("%c%c is an operator\n", char1, char2);
            }
            else
            {
                fseek(filePointer, -2, SEEK_CUR);
                char1 = fgetc(filePointer);
                printf("%c is an operator\n", char1);
            }
        }

        /*  For String 
            String : 'a' or "hello"
        */
        if ((ch == '\"'))
        {
            printf("%c", ch);
            while ((ch = fgetc(filePointer)) != '\"')
            {
                printf("%c", ch);
            }
            printf("%c is a String\n", ch);
        }

        /*
            Special Symbols
            ';' '[' ',' ')'  etc
        */
        if (ch == ';' || ch == ',' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}' || ch=='!'|| ch=='#' || ch=='&')
        {
            printf("%c is a Special Symbol\n", ch);
        }

       /*
        Removing Space and new line
       */
        while(ch == ' ' || ch == '\n' || ch =='\t'){
            ch = fgetc(filePointer);
            goto start;
        }

        iIterate =0;
        
        while((ch!= ' ') && (ch!= '\n') && (ch!= '\t') && (ch!=';') && (ch!='(') && (ch!='\"') && ch!=','){
            
            token[iIterate] = ch;
            printf("%c",ch);
            ch = fgetc(filePointer);
            iIterate++;
        }
        token[iIterate]='\0';

        
        if(isKeyword(token)==1){
            
            while(token[iIterate]!='\0'){
                printf("%c",token[iIterate]);
                iIterate++;
            }
            printf(" is a keyword\n");
            memset(token,0,sizeof(token));
            goto start;
        }
        
        if(isConstantOrIdentifier(token)==1){
            
            while(token[iIterate]!='\0'){
                printf("%c",token[iIterate]);
                iIterate++;
            }
            printf(" is a constant\n");
            memset(token,0,sizeof(token));
            goto start;
        }
        else if(isConstantOrIdentifier(token)==2){
            
            while(token[iIterate]!='\0'){
                printf("%c",token[iIterate]);
                iIterate++;
            }
            printf(" is a identifier\n");
            memset(token,0,sizeof(token));
            goto start;
        }
        else if(isConstantOrIdentifier(token)==0){
            
            while(token[iIterate]!='\0'){
                printf("%c",token[iIterate]);
                iIterate++;
            }
            printf(" is a invalid symbol\n");
            memset(token,0,sizeof(token));
            goto start;
        }
    
 
    
    }
}