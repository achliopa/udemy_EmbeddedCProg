/*
 * main.c
 *
 *  Created on: 7 Απρ 2020
 *      Author: achliopa
 */
#include <stdio.h>

int main(void) {
	float num1, num2, num3;
	printf("Enter num1: ");
	fflush(stdout);
	scanf("%f",&num1);
	printf("Enter num2: ");
	scanf("%f",&num2);
	printf("Enter num3: ");
	scanf("%f",&num3);
	printf("Average is: %f\n",(num1+num2+num3)/3);
	printf("Press ENTER key to exit");
	getchar();
	getchar();
	return 0;
}
