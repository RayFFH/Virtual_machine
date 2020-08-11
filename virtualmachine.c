#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef enum {

	PUSH,
	ADD,
	POP,
	SET,
	HALT
	}Instructions;
	
typedef enum {
	A,B,C,D,E,F
	NUM_REGISTERS
	}Registers;
	
const int executables[] = {
	PUSH,5,
	PUSH,6,
	ADD,
	POP,
	HALT
};

int instruction_pointer = 0;
bool check = true;
int ip = 0;
int sp = -1;
int stack[256];

int fetch(){
	return program[ip];
}


void eval(int instruction){
	switch(instruction){
	case HALT:{
		running = false;
		break;
	}
	case PUSH: {
		sp++;
		stack[sp] = executables[++instruction_pointer];
		break;
		}
	case POP: {
		int value_popped = stack[sp--];
		printf("popped %d\n", value_popped);
		break;
	}
	case ADD: {
		int a = stack[sp--];
		int b = stack[sp--};
		int result = a + b
		sp++;
		stack[sp] = result
		break;
	}
	
}

int main(){
	while(check){
		int x = fetch();
		if(x == HLT) check = false;
		instruction_pointer++;
		}
}

