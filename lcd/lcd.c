#include<lpc214x.h>
#include<string.h>
#include<stdlib.h>

void delay();
void lcdcmd(unsigned char);
void lcddata(unsigned char);
void lcdinit();
void initadc();

void initadc()
{
  PINSEL1 |= 0X010000000;  //select pin fuction
	AD1CR  =  0X00000000;     // clr adc1
	AD1CR |= (0X01<<7);      // select channel
	AD1CR |= (13<<8);        // clkdiv
	AD1CR |= (0X01<<16);     // burst on
	AD1CR |= (0X01<<21);     // pdn = 1
	AD1CR |= (0X01<<24);      //soc
}
void delay()
{
  unsigned int i=0;
  for(i = 0; i<=1000; i++);  
}	

void lcdcmd(unsigned char cmd)
{
	 IO0PIN &= 0X00;
	 IO0PIN |= (cmd<<0) ;
   IO0CLR |= 1<<8;  // RS
   IO0SET |=1<<10;
   delay();
   IO0CLR |= 1<<10;
}


void lcddata(unsigned char data)
{
	 IO0PIN &= 0X00;
	 IO0PIN |= (data<<0) ;
   IO0SET |= 1<<8;  // RS
   IO0SET |=1<<10;
   delay();
   IO0CLR |= 1<<10;
}

void lcdinit()
{
  IO1CLR |=(1<<10);
  lcdcmd(0x30);
  lcdcmd(0x0C);
  lcdcmd(0x01);
  lcdcmd(0x06);
  lcdcmd(0x80);
}

void string(unsigned char *p)
{
  while(*p !='\0')
	{
    lcddata(*p);
		*p++;
  }
}
 //unsigned char arr[5];


int main()
{
  IO0DIR |= 0XFFF;
	lcdinit();
	initadc();
	
	while(1)
	{   unsigned int myadc;
    	myadc = AD1GDR;
      myadc = myadc >> 6;
	    myadc = myadc & 0x3FF;
		  //itoa(myadc,arr,10);
		  //string(arr);
		  delay();
		  lcdcmd(0x01);
  }

}
	






