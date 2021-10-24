# **Design-Of-Language-Processor**

- [Generic DFA](#generic-dfa)
- [Lexical Analyzer](#lexical-analyzer)
- [Recursive Descent Parser](#recursive-descent-parser)

## **GENERIC DFA**
DFA refers to deterministic finite automata. A DFA is a collection of 5-tuples:

Q: finite set of states  
∑: finite set of the input symbol  
q0: initial state   
F: final state  
δ: Transition function

</br>

- In the particular program, the user is can build a generic DFA by inputing the transition table for it.

- Create a `test.txt` in the same directory where you will extract the `genericDFA.c` program.

- Input any String in the .txt file.

**Note**: The Program accepts inputs from 1 to 9. So if you would want to try out a DFA with inputs as {a,b,c}, they will first have to be converted to {1,2,3}.
Similarly a string as "aabccb" will have to be converted into "112332".


### **EXAMPLE**

<img align="center" alt="Example DFA" width="50%" src="https://raw.githubusercontent.com/Rain1213/Design-Of-Language-Processor/main/images/exampleDFA.jpg" />

This DFA has 
 - Q: {A,B,C}
 - ∑: {a,b,c}
 - q0: {A}
 - F: {C}

For the purposes of using this DFA on the code written above,
Let’s convert the following:

A State will now become State 1.</br>
B State will now become State 2.</br>
C State will now become State 3.</br>

a input will now become input 1.</br>
b input will now become input 2.</br>
c input will now become input 3.</br>

Therefore the DFA will now look more like:

<img align="center" alt="New Example DFA" width="50%" src="https://raw.githubusercontent.com/Rain1213/Design-Of-Language-Processor/main/images/newExampleDFA.jpg" />


</br>
</br>

Let us take input as "aab" or "112".

<img align="center" alt="txt Input DFA" width="50%" src="https://raw.githubusercontent.com/Rain1213/Design-Of-Language-Processor/main/images/txtInputDFA.jpg" />


</br>
</br>

### **OUTPUT**

<img align="center" alt="output DFA" width="50%" src="https://raw.githubusercontent.com/Rain1213/Design-Of-Language-Processor/main/images/outputDFA.jpg" />

</br>
</br>
<hr>
</br>

## **LEXICAL ANALYZER**

Lexical analysis is the first phase of a compiler. It takes the modified source code from language preprocessors that are written in the form of sentences. The lexical analyser breaks these syntaxes into a series of tokens, by removing any whitespace or comments in the source code. If the lexical analyser finds a token invalid, it generates an error. The lexical analyzer works closely with the syntax analyser. It reads character streams from the source code, checks for legal tokens, and passes the data to the syntax analyser when it demands.

- The following program takes in the name of a `.c program` in the same directory as the `lexicalAnalyzer.c` or `lexicalAnalyzer.l`
- The program will convert the c program into tokens and will output them along with their type.
- There are 6 types of different tokens:</br>
    i. identifiers</br>
    ii. reserved keywords</br>
    iii. constants</br>
    iv. strings</br>
    v. operators</br>
    vi. special symbols</br>

- The program will also ignore all comments.
- Token errors genereted will also be displaced as "invalid symbols".

### **EXAMPLE**

<mark>Lexical Analyzer/Test.c</mark> contains the following code.

```
/* compiler
Practical-4*/
void main()
{
int a; //variable declaration
float 1b;
printf ("hi");
a = a + 20;
}
```
</br>

### **OUTPUT: `lexicalAnalyzer.c`**

<img align="center" alt="output DFA for c program" width="60%" src="https://raw.githubusercontent.com/Rain1213/Design-Of-Language-Processor/main/images/outputLA.jpg" />
</br>

### **OUTPUT: `lexicalAnalyzer.l`**

<img align="center" alt="output DFA for lex program" width="60%" src="https://raw.githubusercontent.com/Rain1213/Design-Of-Language-Processor/main/images/outputLA2.JPG" />

</br>
</br>
<hr>
</br>

## **Recursive Descent Parser**

There are two types of Parsers:
- **Top Down Parser** :
    Parser where a start symbol is expanded into a whole program. Recursive Descent and LL Parser are Top-Down in nature.

- **Bottom Up Parser** :
    Parser where the whole program is reduces to a start symbol. LR(0) is a Bottom Up Parser

RDP uses a set of recursive procedures to scan the input. Recursive Parsing method includes backtracking. Backtracking repeatedly scans its inputs.
Grammer must first eliminate left recursion. The result can be passed to RDP Parser. 

<img align="center" alt="RDP Flow" width="50%" src="https://raw.githubusercontent.com/Rain1213/Design-Of-Language-Processor/main/images/RDP.PNG" />

In this code, for every variable, we would be writing a function. The prime player in this code will be a global variable known as lookahead operator, which will be tasked with scanning the next character from the input.

<mark>Recursive Descent Parser/RecursiveDescentParser.c</mark> takes in the name of a txt file as an input. You would write the grammer in this input file.

<img align="center" alt="RDP Input Text File" width="40%" src="https://raw.githubusercontent.com/Rain1213/Design-Of-Language-Processor/main/images/inputGrammerRDP.PNG" />

<img align="center" alt="RDP Program Output" width="70%" src="https://raw.githubusercontent.com/Rain1213/Design-Of-Language-Processor/main/images/outputGrammerRDP.PNG" />

</br>
</br>
<hr>
</br>
