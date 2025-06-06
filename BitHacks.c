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
void merge(long* __restrict C,long* __restrict A,long* __restrict B,size_t szA,size_t szB);
int main(){
	printf("hello, world\n");
	int mask, field,x,y,n, sum;
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
	
	//merge two sorted array
	long arr1[]={3,12,19,46};
	long arr2[]={4,14,21,23};
	long sorted_arr[8];
	printf("merge two sorted arrays with no branch minimum\n");
	merge(sorted_arr,arr1,arr2,4,4);
	for(int t=0;t<8;t++){
		printf(" %d ",sorted_arr[t]);
	}
	
	//modular addition: compute (x+y)%n for x,y<n
	x=46;
	y=37;
	n=75;
	sum=x+y;
	int rem= sum-(n& -(sum>=n));//sum<n?n:sum-n;
	printf("\n%d + %d mod %d:%d\n",x,y,n,rem);
	
	//compute the mask of the LSB in word x
	x=0b0110100101100;
	int neg_x=-x ;//0b1001011010100
	printf("mask of the lsb in 0b0110100101100:%d\n",x&neg_x);
	
	return 0;
}

void print_binary(int ptr){
	int size=sizeof(int)*8;
	for(int j=size-1;j>=0;j--){
		int mask=1<<j;
		printf("%d",mask&ptr?1:0);
	}
}
void merge(long* __restrict C,long* __restrict A,long* __restrict B,size_t szA,size_t szB){
	while(szA>0 && szB>0){
		//replace with no branch minimum
		/*if(*A>*B){
			*C=*B;
			B++;
			szB--;
		}
		else{
			*C=*A;
			A++;
			szA--;
		}*/
		long min= *B ^ ((*A ^ *B) & -(*A <= *B));
		int inc=*A <= *B;
		*C=min;
		A+=inc; 
		B+=!inc;
		szA-=inc;
		szB-=!inc;
		C++;
	}
	while(szA>0){
		*C=*A;
		C++;
		szA--;
	}
	while(szB>0){
		*C=*B;
		szB--;
		C++;
	}
	
}