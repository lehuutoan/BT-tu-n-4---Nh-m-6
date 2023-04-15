//This program prints the first 512-bit keystream
//then measure the average encryption speed
#include "hc256.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
int main()
{
	int key[8], iv[8];
	char DATA; // the DATA is encrypted
	clock_t start, finish;
	double duration, speed;
	int i;
	//initializes the key and IV
	for (i = 0; i < 8; i++) key[i] = 0;
	for (i = 0; i < 8; i++) iv[i] = 0;
	//iv[0] = 1;
	key[0] = 0x55;
	//key and iv setup
	initialization(key, iv);
	//generate and print the first 512-bit keystream
	//for (i = 0; i < 16; i++) DATA[i] = 0;
	DATA = "Hello";
	int DATA_BIN[CHAR_BIT];
	for (i = 0; i < CHAR_BIT; ++i) {
		DATA_BIN[i] = (DATA >> i) & 1;	
	}
	encrypt(DATA_BIN);
	for (i = 0; i < strlen(DATA); i++) printf(" %8x ", DATA[i]);
	//measure the encryption speed by encrypting
	//DATA repeatedly for 0x4000000 times
	/*
	start = clock();
	for (i = 0; i < 0x4000000; i++) encrypt(DATA);
	finish = clock();
	duration = ((double)(finish - start)) / CLOCKS_PER_SEC;
	speed = ((double)i) * 32 * 16 / duration;
	printf("\n The encryption takes %4.4f seconds.\n\ The encryption speed is %13.2f bit/second \n" ,duration, speed);
	*/
	return (0);
}