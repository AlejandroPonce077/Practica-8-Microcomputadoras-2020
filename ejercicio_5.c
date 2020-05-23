#include <16F877A.h>
#fuses HS, NOWDT, NOPROTECT
#use delay(clock = 20000000)
#use rs232(baud=56000, xmit=PIN_C6, rcv=PIN_C7)
#org 0x1F00, 0x1FFF void loader16F877A(void){}

#define retardo 250

void apagados(){
   output_b(0x00);
   delay_ms(retardo);
}

void encendidos(){
   output_b(255);
   delay_ms(retardo);
   
}

void corrDer(){
   int data=128,i;
   for(i=0;i<=7;i++){
      output_b(data);
      delay_ms(retardo);
      data=data/2;
   }
   output_b(0);
}

void corrIzq(){
   int data=2,i;
   output_b(1);
   delay_ms(retardo);
   for(i=1;i<=7;i++){
      output_b(data);
      data=data*2;
      delay_ms(retardo);
   }
   output_b(0);
}

void corrDerIzq(){
   corrDer();
   corrIzq();
}

void apagEnc(){
   output_b(255);
   delay_ms(retardo);
   output_b(0);
   delay_ms(retardo);
}

void main(){
   while(TRUE){
      switch(getch()){
         case '0': apagados(); 
            break;
         case '1': encendidos(); 
            break;
         case '2': corrDer(); 
            break;
         case '3': corrIzq(); 
            break;
         case '4': corrDerIzq(); 
            break;
         case '5': apagEnc(); 
            break;
         default: apagados(); 
            break;
      }//switch
   }//while
}//main
