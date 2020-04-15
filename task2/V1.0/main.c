
#include "s3c2440_soc.h"
#include "led.h"
#include "key.h"
#include "uart.h"
#include "sdram.h"
const char p1[100] = "hello world";//if put this defination in main(),there will be mistake in compile 


int main(void)
{
	int key=0,i;
	volatile unsigned char *p2 = (volatile unsigned char *)0x30000000;
	char val[100];
	led_init();
	uart0_init();
	sdram_init();
	key_init();
	GPFDAT &=~(7<<4);
//	tacc_set(7);
	
	puts("sdram test start!\n\rthis is which words we will write in sdram: ");
	puts(p1);		
	sdram_write(p1,p2);

	puts("\n\rthis is what we read from sdram: ");
	sdram_read(val,p2);
	for(i=0;i<100;i++)
	{
		putchar(val[i]);
	}	
	puts("\n\r");
	while(1)
	{
	}
	return 0;
}



