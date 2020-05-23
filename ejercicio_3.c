#include <16F877A.h>
#fuses HS, NOWDT, NOPROTECT
#use delay(clock = 20000000)
#org 0x1F00, 0x1FFF void loader16F877A(void){}

int var1;
void main(){
	while(1){
		var1=input_a();
		output_b(var1);
	}//while
}//main
