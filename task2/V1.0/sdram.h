#ifndef _SDRAM_H
#define _SDRAM_H

void sdram_init();
void sdram_read(int *val,char* addr);
void sdram_write(char *val,char* addr);

#endif