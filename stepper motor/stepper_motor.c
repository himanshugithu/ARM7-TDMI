#include<lpc21xx.h>
void delay(unsigned int ms);
int main ()

{
	
  IO0DIR = 0XFFFFFFFF;
	while(1)
	{
		
		
		IO0SET = 0X09;
		delay(1000);
		IO0CLR = 0X09;
		IO0SET = 0X0C;
		delay(1000);
		IO0CLR = 0X0C;
    IO0SET = 0X06;
		delay(1000);
		IO0CLR = 0X06;
    IO0SET = 0X03;
		delay(1000);
		IO0CLR = 0X03;
		
		
		
		IO0SET = 0X03;
		delay(1000);
		IO0CLR = 0X03;
		IO0SET = 0X06;
		delay(1000);
		IO0CLR = 0X06;
    IO0SET = 0X0C;
		delay(1000);
		IO0CLR = 0X0C;
    IO0SET = 0X09;
		delay(1000);
		IO0CLR = 0X09;
		IO0SET = 0X03;
		delay(1000);
		IO0CLR = 0X03;
  }
   




}

void delay(unsigned int ms)
{
	unsigned int i=0,j=0;
  for(i = 0; i<ms; i++)
    {
			for(j=0; j<3000;j++);
    }	

}