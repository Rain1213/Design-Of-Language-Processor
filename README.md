# **Design-Of-Language-Processor**

- [Generic DFA](#generic-dfa)
- [Lexical Analyzer](#lexical-analyzer)

## **Generic DFA**
DFA refers to deterministic finite automata. A DFA is a collection of 5-tuples:

Q: finite set of states  
∑: finite set of the input symbol  
q0: initial state   
F: final state  
δ: Transition function

</br>

- In the particular program, the user is can build a generic DFA by inputing the transition table for it.

- Create a <mark>test.txt</mark> in the same directory where you will extract the <mark>genericDFA.c</mark> program.

- Input any String in the .txt file.

**Note**: The Program accepts inputs from 1 to 9. So if you would want to try out a DFA with inputs as {a,b,c}, they will first have to be converted to {1,2,3}.
Similarly a string as "aabccb" will have to be converted into "112332".


### **Example**

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

### **Output**

<img align="center" alt="output DFA" width="50%" src="https://raw.githubusercontent.com/Rain1213/Design-Of-Language-Processor/main/images/outputDFA.jpg" />

</br>
</br>
</br>
</br>

## **Lexical Analyzer**

