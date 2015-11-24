#include <stdio.h>

int fatal(int * r) {
	printf("[FATAL ERROR] %r",r);
	for(;;);
}

void fwbug(void * fwdesc) {
	printf("[FIRMWARE BUG] %r",fwdesc);
}

void hwbug(void * hwdesc) {
	printf("[HARDWARE BUG] %r",hwdesc);
}

void swbug(void * swdesc) {
	printf("[SOFTWARE BUG] %s",swdesc);
}

int asmint(void * asmint)
{
	__asm__("int %a1"
		:
		:"a"(asmint)); // fu = the descriptor, where we add the descriptor re
	return 0;
}

int add(int * fu,int * re) {
	__asm__("add %a1,%b1"
		:
		:"a"(fu),"b"(re)); // fu = the descriptor, where we add the descriptor re
	return 0;
}

int mov(int * cf,int * gd) {
	asm volatile("mov %b1,%a1"
		:
		:"a"(cf),"b"(gd));
	return 0;
}