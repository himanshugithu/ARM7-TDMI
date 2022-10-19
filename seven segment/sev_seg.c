
#include<lpc214x.h>            
void delay(unsigned int ms);            

int i;                         
unsigned int a[]={0x06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F,0X3F};
//unsigned int b[]={0x2000,0x7C80,};//  for cammon cathod
int main()

{ 

    IO0DIR=IO0DIR|0x000000ff;              
    IO0CLR=0xffffffff;
    while(1)
      {    
        for(i=0;i<=9;i++)
        {
            IO0PIN= a[i];           
            delay(2000);  
					//	IO0PIN= b[i];           
            //delay(2000);
            
        }
      }
    return 0;
}

void delay( unsigned int ms)              
{
    int i,j;
    for(i=0;i<ms;i++)
    for(j=0;j<=1000;j++);
}