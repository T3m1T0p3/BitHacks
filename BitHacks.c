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
	
	//set k bit in x to 1
	int x=0b101001011;
	//set 7bit to 1
	int x_res=x | (1<<7);
	print_binary(x_res);
	return 0;
}

void print_binary(int ptr){
	int size=sizeof(int)*8;
	for(int j=size-1;j>=0;j--){
		int mask=1<<j;
		printf("%d",mask&ptr?1:0);
	}
}