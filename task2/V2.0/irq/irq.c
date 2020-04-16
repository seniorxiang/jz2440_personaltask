#include"../include/s3c2440_soc.h"
#include"../include/uart.h"


void key_eint_init()
{
		GPFCON &=~((3<<0) | (3<<4) );
		GPGCON &=~(3<<6 );
	
		GPFCON |=((2<<0) | (2<<4) );//EINT0,EINT2
		GPGCON |=(2<<6 );			//EINT11

		EXTINT0 |= ((2<<0) | (2<<8));
		EXTINT1 |= (2<<12);

		EINTMASK &= ~(1<<11);//EINT0~3 is enable defaultly
		puts("\n\r this is key_eint_init ");
}

void irq_init()
{
/*
1 set key to EINT mode ,enable GPIO EINT
2 open INTMSK
3 act
*/
	INTMSK &=~((1<<0) | (1<<2) | (1<<5));
	key_eint_init();
	puts("\n\r this is irq_init ");
}




void key_irq(int bit)
{
	volatile unsigned char *p2 = (volatile unsigned char *)0x3000b000;
	unsigned char val[100];
	int i;
	puts("\n\r this is key_irq ");
	GPFDAT &=~(1<<5);
	sdram_read(val,p2);
	for(i=0;i<100;i++)
	{
		putchar(val[i]);
	}	
	EINTPEND=EINTPEND;
}

void irq_act()
{
/*
1 find which irq request,by reading INTOFFSET
2 do what it want to do
3 clear SRCPND and INTPND
*/
	int bit = INTOFFSET;


	if(bit == 0 || bit == 2 || bit == 5)
	{puts("\n\r this is irq_act ");
		key_irq(bit);
	}
	SRCPND = (1<<bit);
	INTPND = (1<<bit);	
}


