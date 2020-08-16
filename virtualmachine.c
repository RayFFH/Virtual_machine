#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define NUM_REGS 4

typedef struct {
	int *nem;
	int *max_num;
	
	//registers
	int *pc;
	int sp;
	int a[];
	int b[];
	
	int inst;
	int dest;
	int src;
	
	int busa;
	int busb;
}cpu;	
	
	
typedef enum {
	PUSH,
	ADD,
	POP,
	SET,
	HALT
	}Instructions;
	
unsigned registers[NUM_REGS]
	//Creates array for registers
const int executables[] = {
	PUSH,5,
	PUSH,6,
	ADD,
	POP,
	HALT
};
//List of functions that will be used
int instruction_pointer = 0;
bool check = true;
int ip = 0;
int sp = -1;
int stack[256];
//Stack that records instructions for program
unsigned program[]=[0x1243, 0x11C2, 0x2943, 0x0232};
//list of instructions
int fetch(){
	return program[ip];
}


void decode(int instruction)
{
	instuctionNUmber = (instruction & 0xF000) >>12;
	Registernumber = (instruction & 0xF00 ) >>8;
	secondndbyte_value = (instruction & 0xF0) >> 4;
	firstbyte_value = (instruction & 0xF);
	total_value = (instruction & 0xFF).
}
//decodes instructions to workable parts

void eval(int instruction){
	switch(instruction){
	case 0:{
		printf("HALT\n");
		running = false;
		break;
	}
	case 1: {
		printf("load register%d with %d\n",register1,imm);
		registers[RegisterNumber] = total_value;
		break;
		}
	case 2: {
		printf("add r1 and r2 into r3");
		register[2]= register[0]+register[1]
		break;
	}
	case 3: {
		int a = stack[sp--];
		int b = stack[sp--};
		int result = a + b
		sp++;
		stack[sp] = result
		break;
	}
	
}
//determines what to do with each instruction
void printRegister()
{
	int i;
	printf("Registers = ");
	for(i=0; i<NUM_REGS; i++){
		printf("%04X":,registers[i]);
	}
	printf("\n");
}
//prints values inside registers
void run()
{
	while(check)
	{
		printRegister();
		int instruction = fetch()

int main(){
	while(check){
		int x = fetch();
		if(x == HLT) check = false;
		instruction_pointer++;
		}
}
//fetches instructions and moves pointer to next instruction
