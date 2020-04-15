#include"s3c2440_soc.h"
void led_init()
{
	GPFCON &=~((3<<8) | (3<<10) | (3<<12));
	GPFCON |= ((1<<8) | (1<<10) | (1<<12));
	
}
void led_test(int val)
{
	switch(val)
	{
		case 1 : GPFDAT =(GPFDAT|(1<<5)|(1<<6))&(~(1<<4));break;
		case 2 : GPFDAT =(GPFDAT|(1<<4)|(1<<6))&(~(1<<5));break;
		case 3 : GPFDAT =(GPFDAT|(1<<5)|(1<<4))&(~(1<<6));break;
		default : GPFDAT |=(7<<4);break;
	}

}

