/*
Lexical Analyzer using Lex
Generates: 'identifiers','keywords','constants','string','operators' and 'special symbols'
*/
%{
	#include<stdio.h>
	#include<string.h>
%}

%%

(\/\*)(.|\n)*(\*\/) {//Multiline Comments
/*
	A multiline comment is represented with / * and * / (without space)
	/ should be written as \/
	* should be written as \*
	
	Anything in between the symbols / * and * / must also be a part of comments
	. is used for any character but new line
	\n is used for new line
	multiline comments can contain zero or more characters as well as newlines
	therefore:
	(.|\n)*
	
	Multiline comments are to be ignored
*/
}

(\/\/)(.)* {
/*
	// is written as \/\/
	// can contain any characters but in the same line
	single line comment is disrupted by a new line
	. is used for any character but new line
	
	Singleline comments are to be ignored
*/
}

(\n)|(\t)|([ ]) {
/*
	Spaces and new lines outside comments have to be ignored.
*/
}

auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while {
/*
	All are Keywords
*/
	printf("%s is a Keyword\n",yytext);
}

\+|\-|\*|\/|%|\<|\>|\+=|\-=|\*=|\/=|\%=|==|\>=|\<=|= {
/*
	All are Operators
	+	-	*	/	%
	<	>	<=	>=	==
	+=	*=	/=	-=	%=
	=
	
*/
	printf("%s is an Operator\n",yytext);
}

\[|\]|\{|\}|\(|\)|\$|;|:|!|@|#|& {
/*
	All are Special Symbols
	
	[	]	(	)	!
	{	}	$	@	&
	#	;	:
*/
	printf("%s is a Special Symbol\n",yytext);
}

(\")(.)*(\") {
/*
	Any token that has " and " surrounding it
	is definitely as string
*/
	printf("%s is a String\n",yytext);
}

[0-9]+(\.)*[0-9]* {
/*
	All are constants
	
	Constants are numbers
	numbers can have decimal point but its not mandatory
	but its mandatory that it has atleast one digit between 0 to 9
*/
	printf("%s is a Constant\n",yytext);
}

[a-zA-Z_]+[a-zA-Z_0-9]* {
/*
	All are identifiers
	
	Identifiers start from alphabets or '_' symbol
	they can have numbers in them but not at the start
*/
	printf("%s is an Identifier\n",yytext);
}

[0-9]+[a-zA-Z_0-9]+ {
/*
	Any token that starts with a digit and has a alphabets after it
	will definitely be a lexical error
*/
	printf("%s is a Lexical Error\n",yytext);
}
%%

int main(){

	char fileName[30];

	//taking input
	extern FILE *yyin, *yyout;
	
	printf("Enter your file name\n");
	scanf("%s",fileName);
	
	//reading input
	yyin = fopen(fileName,"r");
	
	yylex();
}
