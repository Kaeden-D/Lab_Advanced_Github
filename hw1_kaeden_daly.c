#include <stdio.h>

/*
	File: hw1_kaeden_daly.c
	Author: Kaeden Daly
	Course: CS125
	Assignement: Homework 1
	Date: 1/13/2025
	Rrferences: Used Google.
*/

//
int main()
{
float numerator = 0;
float denominator = 0;

float answer = 0;

printf("Please type the numerator value: ");
scanf("%f", &numerator);

printf("Please type the denominator value: ");
scanf("%f", &denominator);

if (denominator == 0)
{
printf("Error: The denominator cannot be 0 \n");
}
else
{
answer = numerator / denominator;

printf("The answer is %.2f \n", answer);
}

}
