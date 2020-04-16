#include"../include/s3c2440_soc.h"

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
void sdram_read( char *val, char *addr)
{
	int i;
	for (i=0;i<100;i++)
	{
		val[i]=addr[i];
	}
}
void sdram_write( char *val, char *addr)
{
	int i;
	for (i=0;i<100;i++)
	{
		addr[i]=val[i];
	}
}

void sdram_write_int(unsigned int *val,unsigned int *addr)
{
	int i;
	for (i=0;i<1;i++)
	{
		addr[i]=val[i];
	}
}

void copy2sdram(void)
{
	/* 要从lds文件中获得 __code_start, __bss_start
	 * 然后从0地址把数据复制到__code_start
	 */

	extern int __code_start, __bss_start;

	volatile unsigned int *dest = (volatile unsigned int *)&__code_start;
	volatile unsigned int *end = (volatile unsigned int *)&__bss_start;
	volatile unsigned int *src = (volatile unsigned int *)0;

	while (dest < end)
	{
		*dest++ = *src++;
	}
}


void clean_bss(void)
{
	/* 要从lds文件中获得 __bss_start, _end
	 */
	extern int _end, __bss_start;

	volatile unsigned int *start = (volatile unsigned int *)&__bss_start;
	volatile unsigned int *end = (volatile unsigned int *)&_end;


	while (start <= end)
	{
		*start++ = 0;
	}
}

