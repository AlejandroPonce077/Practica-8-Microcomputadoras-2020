#include <16F877A.h>
#fuses HS, NOWDT, NOPROTECT
#use delay(clock = 20000000)
#use rs232(baud=56000, xmit=PIN_C6, rcv=PIN_C7)
#org 0x1F00, 0x1FFF void loader16F877A(void){}

void main(){
   while(1){
      output_b(0xFF);
     printf("Todos los bits encendidos\n\r");
     delay_ms(2000);
     output_b(0x00);
     printf("Todos los leds apagados\n\r");
     delay_ms(2000);
   }//while
}//main
