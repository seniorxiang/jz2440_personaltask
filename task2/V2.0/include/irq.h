#ifndef _IRQ_H
#define _IRQ_H

void irq_init();
void irq_act();
void key_eint_init();
void key_irq(int bit);
#endif