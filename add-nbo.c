#include <stdint.h>
#include <stdio.h>
#include "add-nbo.h"

uint32_t my_ntohl(uint32_t n){
	uint32_t n1 = n & 0xff000000;
	n1 = n1 >> 24;
	uint32_t n2 = n & 0x00ff0000;
	n2 = n2 >> 8;
	uint32_t n3 = n & 0x0000ff00;
	n3 = n3 << 8;
	uint32_t n4 = n & 0x000000ff;
	n4 = n4 << 24;

	return n1 | n2 | n3 | n4;
}

void add_nbo(uint32_t a, uint32_t b){
	uint32_t conv_a = my_ntohl(a);
	uint32_t conv_b = my_ntohl(b);
	uint32_t sum = conv_a + conv_b;
	printf("%d(%#x) + %d(%#x) = %d(%#x)\n", conv_a, conv_a, conv_b, conv_b, sum, sum);

	return;
}
