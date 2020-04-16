
#include "include/s3c2440_soc.h"
#include "include/led.h"
#include "include/key.h"
#include "include/uart.h"
#include "include/sdram.h"
#include "include/irq.h"

const char p1[100] = "hello world1111111222222233333334444444555555566666667777777888888899999990000000";//if put this defination in main(),there will be mistake in compile 
int flag=0;



int main(void)
{
	volatile unsigned char *p2 = (volatile unsigned char *)0x3000b000;
	unsigned char val[100];
	int key=0,i;
	
	
	led_init();

//	uart0_init();
//	sdram_init();
//	key_init();
	irq_init();
	GPFDAT |=(7<<4);
//	tacc_set(7);
	puts("\n\rsdram test start!\n\rthis is which words we write in sdram before write: ");
	
	puts(p1);	
	sdram_write(p1,p2);	
	puts("\n\rthis is which words we will read in sdram: ");
	sdram_read(val,p2);
	for(i=0;i<100;i++)
	{
		putchar(val[i]);
	}	

	
		


			puts("\n\rthis is what we read from sdram after written: ");
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



