#include <stdio.h>

/*
	File: hw2_kaeden_daly
	Author: Kaeden Daly
	Course: CS125
	Assignement: Homework 2
	Date: 1/15/2025
	References: Google
*/

//
int main ()
{
  float ambient_temp;
  float req_engine_temp;
  float cur_fuel;
  
  
  printf("What is the initial ambient temperature: ");
  scanf("%f", &ambient_temp);
  while(1)
  {
    printf("What is the initial fuel amount: ");
    scanf("%f", &cur_fuel);
    if(cur_fuel > 0)
    {
      break;
    }
    printf("\nError: fuel cannot be negative\n\n");
  }
  while(1)
  {
    printf("What is the required engine temperature: ");
    scanf("%f", &req_engine_temp);
    if(req_engine_temp > 0)
    {
      break;
    }
    printf("\nError: required engine temperature cannot be negative\n\n");
  }
  
  printf("\n\n");
  
  float time = 0.0;
  float used_fuel = 0.0;
  float cur_engine_temp = ambient_temp + 3.0;
  
  while(cur_engine_temp < req_engine_temp && cur_fuel > 0)
  {
    cur_fuel -= 2;
    used_fuel += 2;
    cur_engine_temp += 1.25;
    time++;
    sleep(1);
  }
  
  if(cur_fuel > 0)
  {
    printf("Warmup completed after %.1f seconds. Warmup used %.1f gallons of fuel. Remaining fuel left onboard is %.1f gallons.\n", time, used_fuel, cur_fuel);
	}
  else
  {
    printf("The plane ran out of fuel after %.1f seconds.\n", time);
  }
  
  return 0;
}

