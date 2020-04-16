objs = start.o main.o
objs += led/led.o
objs += norflash/norflash.o
objs += sdram/sdram.o
objs += key/key.o
objs += uart/uart.o
objs += irq/irq.o

all:$(objs)
	#arm-linux-ld -Ttext 0 -Tdata 0x30000000  start.o led.o uart.o init.o main.o -o sdram.elf
	arm-linux-ld -T sdram.lds $^ -o task.elf
	arm-linux-objcopy -O binary -S task.elf task.bin
	arm-linux-objdump -D task.elf > task.dis
clean:
	rm *.bin $(objs) *.elf *.dis
	
%.o : %.c
	arm-linux-gcc -march=armv4 -c -o $@ $<
	
%.o : %.S
	arm-linux-gcc -march=armv4 -c -o $@ $<