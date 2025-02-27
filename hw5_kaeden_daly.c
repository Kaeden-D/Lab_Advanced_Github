#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
	File: hw5_Kaeden_daly.c
	Author: Kaeden Daly
	Course: CS125
	Assignement: Homework 5
	Date: 02/09/25
	References:
*/


//Performs the xor (# ^ #) operation on the two given inputs
int xor(int value1, int value2)
{
  int output = value1 ^ value2; //Computes the xor operation
  return output; //Returns the output of the operation/function
}

//Performs the or (# | #) operation on the two given inputs
int or(int value1, int value2)
{
  int output = value1 | value2; //Computes the or operation
  return output; //Returns the output of the operation/function
}

//Performs the and (# & #) operation on the two given inputs
int and(int value1, int value2)
{
  int output = value1 & value2; //Computes the and operation
  return output; //Returns the output of the operation/function
}

//Performs the two's complement (~# + 1) operation on the given input
int complement_twos(int value)
{
  int output = ~value + 1; //Computes the two's complement operation
  return output; //Returns the output of the operation/function
}

//
int main ()
{
  int input1;
  int input2;
  int output;
  
  printf("\nHello User.\n\n");
  
  values:
  
  printf("\nPlease input the first value: ");
  while(scanf("%d", &input1) != 1)
  {
    getchar();
    printf("\nError: Invalid input, please try again.");
    printf("\nPlease input a valid value: ");
  }
  
  printf("\nPlease input the second value: ");
  while(scanf("%d", &input2) != 1)
  {
    getchar();
    printf("\nError: Invalid input, please try again.");
    printf("\nPlease input a valid value: ");
  }
  
  int choice;
  int failed_loop;
  
  operations:
  
  do
  {
    getchar();
    printf("\n\n\n");
    if(failed_loop)
    {
      printf("\nError: Invalid input, please try again.\n");
    }
    failed_loop = 1;
    printf("Type \"1\" to perform XOR operation.\n");
    printf("Type \"2\" to perform OR operation.\n");
    printf("Type \"3\" to perform AND operation.\n");
    printf("Type \"4\" to perform 2's Complement operation.\n");
    printf("...: ");
  }
  while(scanf("%d", &choice) != 1 || (choice < 1 || choice > 4));
  failed_loop = 0;
  
  printf("\n\n");
  
  switch(choice)
  {
  case 1:
    output = xor(input1, input2);
    printf("First Value: %d\n", input1);
    printf("Second Value: %d\n", input2);
    printf("XOR Operation Result Value: %d\n", output);
    break;
  case 2:
    output = or(input1, input2);
    printf("First Value: %d\n", input1);
    printf("Second Value: %d\n", input2);
    printf("OR Operation Result Value: %d\n", output);
    break;
  case 3:
    output = and(input1, input2);
    printf("First Value: %d\n", input1);
    printf("Second Value: %d\n", input2);
    printf("AND Operation Result Value: %d\n", output);
    break;
  case 4:
    output = complement_twos(input1);
    printf("First Value: %d\n", input1);
    printf("First Value 2's Complement: %d\n", output);
    
    output = complement_twos(input2);
    printf("Second Value: %d\n", input2);
    printf("Second Value 2's Complement: %d\n", output);
    break;
  }
  
  do
  {
    getchar();
    printf("\n\n\n");
    if(failed_loop)
    {
      printf("\nError: Invalid input, please try again.\n");
    }
    failed_loop = 1;
    printf("Type \"1\" to perform another operation.\n");
    printf("Type \"2\" to choose new numbers.\n");
    printf("Type \"3\" to quit the program.\n");
    printf("...: ");
  }
  while(scanf("%d", &choice) != 1 || (choice < 1 || choice > 3));
  failed_loop = 0;
  
  switch(choice)
  {
  case 1:
    goto operations;
  case 2:
    goto values;
  case 3:
    printf("Program Shutting Down.\n\n");
  }
  
	return 0;
}
