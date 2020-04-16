#ifndef _SDRAM_H
#define _SDRAM_H

void sdram_init();
void sdram_read( char *val, char *addr);
void sdram_write( char *val, char *addr);
void sdram_write_int(unsigned int *val,unsigned int *addr);
#endif