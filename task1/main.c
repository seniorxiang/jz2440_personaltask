
#include "s3c2440_soc.h"
#include "led.h"
#include "key.h"


int main(void)
{
	int key=0;
	led_init();
	key_init();
	while(1)
	{
	if(!(GPFDAT&(1<<0)))
		key=1;
	if(!(GPFDAT&(1<<2)))
		key=2;
	if(!(GPGDAT&(1<<3)))
		key=3;
	led_test(key);
	}
	return 0;
}



