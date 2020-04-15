#include"s3c2440_soc.h"
void key_init()
{
	GPFCON &=~((3<<0) | (3<<4) );
	GPGCON &=~(3<<6 );
}

