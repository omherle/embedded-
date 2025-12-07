#include <LPC214x.h>

unsigned char seg[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

int main()
{
	unsigned int val,d;
	PINSEL1|=(1<<24);
	IODIR0|=0x7F;
	AD1CR=0x00200104;
	while(1)
	{
		AD1CR|=(1<<24);
		while(!(AD1GDR&0x80000000));
		val=(AD1GDR>>6)&0x3FF;
		d=(val*10)/1024;
		IOCLR0=0x7F;
		IOSET0=seg[d];
	}
}
