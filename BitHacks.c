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
	int mask, field,x,y;
	//set kth bit in x to 1
	x=0b101001011;
	//set 7th bit to 1
	int x_result=x | (1<<7);
	printf("flip 7th bit of 0b101001011:\n");
	print_binary(x_result);
	printf("\n");
	//set 7th bit to 0
	int x_result_rollback=x_result & ~(1<<7);
	print_binary(x_result_rollback);
	printf("\n");

	//toggle kth bit
	int to_togggle=0b100101100001;
	//toggle 4th bit
	printf("toggle 4th bit of 0b100101100001:\n");

	int toggled=to_togggle ^ (1<<4);
	printf("Toggled bit:\n");
	print_binary(toggled);
	printf("\nToggled bit:\n");
	print_binary(toggled ^ (1<<4));
	printf("\n");

	//extract bit field
     field=0b1011110101101101;
	 mask =0b0000011110000000;
	int extracted_field=(field & mask) >>7;
	printf("field extracted\n");
	print_binary(extracted_field);
	printf("\n");
	//set 8-12th bit filed to 0
	mask=0b0000111100000000;
	extracted_field=(field & ~mask) | (0);
	printf("8-12 bit of 0b1011110101101101 set to 0:\n");
	print_binary(extracted_field);
	//swap two integers without a temporary variable
	// x ^ x = 0 ==> (x ^ y) ^ y = x
	x=25;
	y=21;
	x=x^y;
	y=x^y;
	x=x^y;
	printf("x:25,y:21 swapped by XOR to %d %d\n",x,y);
	
	//no branch minimum of two numbers
	int min=y ^ ((x ^ y) & -(x<y));
	printf("no branch minimum of 25 & 21:%d\n",min);
	
	return 0;
}

void print_binary(int ptr){
	int size=sizeof(int)*8;
	for(int j=size-1;j>=0;j--){
		int mask=1<<j;
		printf("%d",mask&ptr?1:0);
	}
}