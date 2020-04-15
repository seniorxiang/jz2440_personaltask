#include"s3c2440_soc.h"

void sdram_init()
{
	BWSCON &=~(15<<24);
	BWSCON |=((2<<24) | (2<<28));	
	
	BANKCON6 &=~((3<<15) | (3<<0) | (3<<2));
	BANKCON6 |=((3<<15) | (1<<0) );

	BANKCON7 &=~((3<<15) | (3<<0) | (3<<2));
	BANKCON7 |=((3<<15) | (1<<0) );
	
	REFRESH &=0;
	REFRESH |=((1<<23) | (1<<18) | (1269<<0));
	
	BANKSIZE &=0;
	BANKSIZE |=((1<<7) | (1<<5) | (1<<4) | (1<<0));
	
	MRSRB6 &=0;
	MRSRB6 |=((2<<4));

	MRSRB7 &=0;
	MRSRB7 |=((2<<4));
}
void sdram_read(int *val,char* addr)
{
	int i;
	for (i=0;i<100;i++)
	{
		val[i]=addr[i];
	}
}
void sdram_write(char *val,char* addr)
{
	int i;
	for (i=0;i<100;i++)
	{
		addr[i]=val[i];
	}

}

