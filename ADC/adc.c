#include<lpc214x.h>
void getadc();
void main(void)
{
	IO0DIR |= (1<<0);
  getadc();  // CALL GETADC FUCTION
}

void getadc()
{
	unsigned int myadc;

  PINSEL1 |= 0X010000000;  //select pin fuction
	AD1CR  =  0X00000000;     // clr adc1
	AD1CR |= (0X01<<7);      // select channel
	AD1CR |= (13<<8);        // clkdiv
	AD1CR |= (0X01<<16);     // burst on
	AD1CR |= (0X01<<21);     // pdn = 1
	AD1CR |= (0X01<<24);     // soc
	
	//while(!(AD1GDR & (0x01<<31)) == 0); // check for eoc
	while(1)
   {
      myadc = AD1GDR;
      myadc = myadc >> 6;
	    myadc = myadc & 0x3FF;
		 
	    if(myadc >=500)
	     {
         IO0SET |= (1<<0);
       }
	    else
	     {
         IO0CLR |=(1<<0);
       }
		 
   }
}