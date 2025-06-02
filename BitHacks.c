#include <stdio.h>

// identity
// x + ~x = -1 => ~x = x + 1

// operators
// & and
// | or
// ^ xor
// ~ not (two's complement)
// << left shift
// >> right shit
void print_binary(int ptr);
int main(){
	printf("hello, world\n");
	
	//set kth bit in x to 1
	int x=0b101001011;
	//set 7th bit to 1
	int x_result=x | (1<<7);
	printf("flip 7th bit of 0b101001011: ");
	print_binary(x_result);
	printf("\n");
	//set 7th bit to 0
	int x_result_rollback=x_result & ~(1<<7);
	print_binary(x_result_rollback);
	printf("\n");

	//toggle kth bit
	int to_togggle=0b100101100001;
	//toggle 4th bit
	printf("toggle 4th bit of 0b100101100001: ");

	int toggled=to_togggle ^ (1<<4);
	print_binary(toggled);
	printf("\n");
	print_binary(toggled ^ (1<<4));
	
	//extract bit field
	return 0;
}

void print_binary(int ptr){
	int size=sizeof(int)*8;
	for(int j=size-1;j>=0;j--){
		int mask=1<<j;
		printf("%d",mask&ptr?1:0);
	}
}