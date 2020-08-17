#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define NUM_REGS 4

typedef struct OBJECT_t{
	uint8_t type;
	
	union{
		uint8_t u8;
		int8_t i8;
		uint32_t u32;
		int32_t i32;
	};
}OBJECT;	
typedef enum {
	PUSH,
	ADD,
	POP,
	SET,
	HALT
	}Instructions;
	
typedef struct STACK_T {
	int top;
	int size;
	OBJECT *stack;
}STACK;
	
STACK stack_new(int size){
	STACK s;
	s.top = 0;
	s.size = size;
	s.stack =(OBJECT*)malloc(sizeof(OBJECT)* size);
	return s;
}

int stack_push(STACK *s, OBJECT o){
	s->stack[s->top++] = o;
	return s->top;
}

OBJECT stack_pop(STACK*s){
	return s->stack[--(s->top)];
}

OBJECT stack_peek(STACK *s){
	return s->stack[s->top-1];
}


int instructionNumber = 0;
int Registernumber = 0;
int secondndbyte_value = 0;
int firstbyte_value = 0;
int total_value = 0;
		
unsigned registers[NUM_REGS];
	//Creates array for registers

int instruction_pointer = 0;
bool check = true;
int sp = -1;
int stack[256];
//Stack that records instructions for program
unsigned program[]={0x1243, 0x11C2, 0x2943, 0x0232};

//list of instructions
int fetch(){
	return program[instruction_pointer];
}

void decode(int instruction)
{
	instructionNumber = (instruction & 0xF000) >>12;
	Registernumber = (instruction & 0xF00 ) >>8;
	secondndbyte_value = (instruction & 0xF0) >> 4;
	firstbyte_value = (instruction & 0xF);
	total_value = (instruction & 0xFF);
}
//decodes instructions to workable parts

void eval(){
	switch(instructionNumber){
	case 0:{
		printf("HALT\n");
		check = false;
		break;
	}
	case 1: {
		printf("load register%d with %d\n",Registernumber,total_value);
		registers[Registernumber] = total_value;
		break;
		}
	case 2: {
		printf("add r1 and r2 into r3\n");
		registers[0]= registers[2]+registers[1];
		break;
	}
	case 3: {
		printf("subtract r1 from r2 and put into r3\n");
		registers[2]= registers[1]-registers[0];
		break;
	}
	
}
}
//determines what to do with each instruction
void printRegisters()
{
	int i;
	printf("Registers = ");
	for(i=0; i<NUM_REGS; i++){
		printf("%04X:",registers[i]);
	}
	printf("\n");
}
//prints values inside registers

int main(){
	while(check){
		printRegisters();
		int x = fetch();
		instruction_pointer++;
		decode(x);
		eval();
		}
}
