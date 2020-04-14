

/*
* task1
* 1，设置定时器，FCLK=200M Operating Frequency ? Fclk Up to 400MHz ? Hclk Up to 136MHz ? Pclk Up to 68MHz
* 2，GPIO按键控制变量，控制点灯函数闪烁不同的灯（非中断）
*/

.text
.global _start

_start:

/*
*   close Watchdog ,WTCON 0x53000000 [5]=0;
*/

	ldr r1, =0x53000000
	ldr r0, =0x8000
	str r0, [r1]

/*
 *   reset CLK,we need PLCK=200M
 	first,active LOCKTIME 0x4C000000, set Dividing Ratio between FCLK, HLCK and PCLK=1:4:8,so HDIVN=2,PDIVN=1,HCLK3_HALF/
HCLK4_HALF=0/0. CLKDIVN 0x4C000014  H[2:1]=10  P[0]=1
 	second,HDIVN!=0,CPU bus need  to be change to asynchronous 
 bus mode
 	last, set MPLL,Mpll = (2 * m * Fin) / (p * 2S) 
	m = (MDIV + 8), p = (PDIV + 2), s = SDIV
	MPLLCON 0x4C000004 MDIV[19:12] PDIV[9:4] SDIV[1:0]
	96.00 MHz ----------56(0x38)-----2--------1
 */
	ldr r1, =0x4C000000
	ldr r0, =0xFFFFFFFF
	str r0, [r1]

	ldr r1, =0x4C000014
	ldr r0, =0x05
	str r0, [r1]

	mrc p15,0,r0,c1,c0,0 
	orr r0,r0,#0xc0000000 //#R1_nF:OR:R1_iA 
	mcr p15,0,r0,c1,c0,0

	ldr r1, =0x4C000004
	ldr r0, =0x00038021
	str r0, [r1]

/*
 * judge which mode does board run in(nor or nand )
 */

	mov r1, #0
	ldr r0, [r1] /* 读出原来的值备份 */
	str r1, [r1] /* 0->[0] */ 
	ldr r2, [r1] /* r2=[0] */
	cmp r1, r2   /* r1==r2? 如果相等表示是NAND启动 */
	ldr sp, =0x40000000+4096 /* 先假设是nor启动 */
	moveq sp, #4096  /* nand启动 */
	streq r0, [r1]   /* 恢复原来的值 */
	

	bl main




	/* 死循环 */
halt:
	b halt
