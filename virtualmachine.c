#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define NUM_REGS 4

		
typedef struct STACK_T {
	int* data;
	int top;
	int size;
}Stack;

char instructions *[] ={
	"PSH",
	"ADD",
	"POP",
	"HLT"
};

char* registers[]={ 
	"REGA",
	"REGB",
	"REGC"};

void push(Stack *sp, int value);
int pop(Stack *sp);
int peep(Stack *sp);

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
	
Stack* init(int size){
	Stack *sp = (Stack*)malloc(sizeof(Stack));
	if(sp=='\0'){
		printf("Error -- Unable to allocate memory");
		exit(1);
	}
	
	sp->data = (int*) malloc(sizeof(int)*size);
	if(sp->data == '\0'){
		printf("Error unable to allocate memory");
		exit(1);
	}
	sp->top = -1;
	sp->size = size;
  return sp;
}

void push(Stack *sp, int value){
	if(sp->top == sp->size - 1){
		int *temp = (int*)malloc(sizeof(int) * sp->size *2);
		if(temp == '\0'){
			printf("Error-- Unable to allocate memory...");
			return;
		}
		int i =0;
		for(i = 0; i<=sp->top; ++i){
			temp[i]=sp->data[i];
		}
		free(sp->data);
		sp->data = temp;
		sp->size *=2;
	}
	sp->data[++sp->top] = value;
	
}

int pop(Stack* sp){
	if(sp->top == -1){
		return -1001;
	}
	else{
		return sp->data[sp->top--];
	}	
}

int peep(Stack* sp){
	if(sp->top == -1){
		return -1001;
	}
	else{
		return sp->data[sp->top];
	}	
}

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

int arraySize(){
	int length = sizeof(program)/sizeof(unsigned);
	return length;
}

int concat(int a, int b, int c)
{
	char s1[20];
	char s2[20];
	char s3[20];
	sprintf(s1, "%d", a); 
    sprintf(s2, "%d", b);
    sprintf(s3, "%d", c);  
    strcat(s1, s2); 
    strcat(s1,s3);
    int c = atoi(s1); 
    return c; 
} 

int main(){
	char instruction[16], char registername[16], char number[16]
	int a,b,c,d;
	char str[3];
	int length = arraySize();
	Stack *s1 = init(length);
	while(check){
		printf("Type instruction");
		scanf("%s",str);
		strcpy(instruction, strok(str ," "));
		strcpy(registername, strok(str ," "));
		strcpy(number, strok(str ," "));
		int i;
		for(i=0; i<3; i++){
        if(!strcmp(instruction,instructions[i]))
        {
            printf("Your instruction is: %d\n", instruction[i]);
            a = i;
            }
        }
        for(i=0; i<3; i++){
        if(!strcmp(registername,register[i]))
        {
            printf("Your instruction is: %d\n", instruction[i]);
            b = i;
            }
		}
		c = number - '0';
		d = concat(a,b,c);
		printRegisters();
		//int x = fetch();
		//option to input instructions or to preset them in code.
		push(s1,d);
		instruction_pointer++;
		decode(d);
		eval();
		}
}
