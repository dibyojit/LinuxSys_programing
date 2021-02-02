#include<stdio.h>
#define STRUCT_ELMT	\
	X(char_a) \
	X(memory_leak) \
	X(short_b) \
	X(int_c) \
	X(long_long_d)
	
enum elmt {
	char_a,
	memory_leak,
	short_b,
	int_c = 4,
	long_long_d = 8,
};
struct st {
	char a;
	short b;
	int c;
	long long d;
};	//according to me size should be 8 bytes if till c is there but inlusion of d makes it 16 bytes long and int and short element can fit into 
//spaces allocated for others if the address is even.

main() {
	printf("size of structure is : %d\n", sizeof(struct st));
	struct st h = { 'A', 43690, 0x99999999, 0xffffffffffffffff};
	char *p = &h,i;
	for(;p<((char *)&h +sizeof(struct st));p++){
		
		#define X(element) \
				if((p-(char *)&h) == element) \
					printf("\nthe " #element" binary :\n");
					STRUCT_ELMT
		#undef X
// ^ Here the preprocessor gets confused if more than one # is use post a #define so #element# can't be used here as it creates problems 
// which is why two printfs are used !!!

//	the macro expands like this 		
//		if(p==(char *)&h)
//			printf("\n the char a binary :\n");
//		else if((p-(char *)&h)==1)
//			printf("\n the memory leak byte :\n");
//		else if((p-(char *)&h)==2)
//			printf("\n the short b binary :\n");
//		else if((p-(char *)&h)==4)
//			printf("\n the int c binary :\n");
//		else if((p-(char *)&h)==8)
//			printf("\n the long long d binary :\n");
			
		for(i=7;i>=0;printf("%d",*p>>i--&1));
		putchar(32);		
	}
	putchar(10);
}
