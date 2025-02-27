#include <stdio.h>

/*
	File: hw3_kaeden_daly
	Author: Kaeden Daly
	Course: CS125
	Assignement: Homework 3
	Date: 01/22/25
	References: 
*/

//
int main ()
{
  float hours_worked = 0.0;
  int employee_id = 0;
  float hourly_rate = 0.0;
  int employee_type = 0;
  int manager_flag;
  
  do
  {
    printf("\nType your hours worked: ");
    scanf("%f", &hours_worked);
  }
  while(hours_worked < 0.0);
  
  while(employee_id < 1000 || employee_id > 1000000)
  {
    printf("\nType your employee ID: ");
    scanf("%d", &employee_id);
  }

  while(hourly_rate <= 0.0 || hourly_rate > 100.0)
  {
    printf("\nType your hourly rate: ");
    scanf("%f", &hourly_rate);
  }
  
  while(employee_type != 1 && employee_type != 2)
  {
    printf("\nType \"1\" if you are Hourly and \"2\" if you are Salary: ");
    scanf("%d", &employee_type);
  }
  
  
  summary:
  printf("\nHello employee %d.\n", employee_id);
  printf("Your hourly rate is %f.\n", hourly_rate);
  
  if(employee_type - 1)
  {
    printf("You are a Salary employee and worked %f hours.\n", hours_worked);
  }
  else
  {
    printf("You are a Hourly employee and worked %f hours.\n", hours_worked);
  }
  
  
  manager:
  (hours_worked >= 60.0) ? printf("\n\nYou need to see a manager.\n\n\n\n")
                        : printf("\n\nYou do not need to see a manager.\n\n\n\n");
  
  int loop = 1;
  int choice;
  float pay;
  
  while(loop)
  {
    printf("Type \"0\" to exit.\n");
    printf("Type \"1\" to see pay.\n");
    printf("Type \"2\" to see summary again.\n");
    printf("Type \"3\" to change hours worked.\n");
    printf("Type \"4\" to change hourly rate.\n");
    printf("Type \"5\" to change employee type.\n");
    printf("Type \"6\" to see if you need to see a manager.\n");
    printf("...: ");
    scanf("%d", &choice);
    
    switch(choice)
    {
    case 0:
      loop = 0;
      break;
    case 1:
      pay = hours_worked * hourly_rate;
      if(employee_type - 1)
      {
        if(hours_worked > 40)
        {
          pay = 40 * hourly_rate;
        }
      }
      else
      {
        if(hours_worked > 60)
        {
          pay = 60 * hourly_rate;
          hours_worked = 60;
        }
      }
      
      int exact;
      
      printf("\nType \"1\" for whole dollars and \"2\" for exact: ");
      scanf("%d", &exact);
      
      if(exact - 1)
      {
        printf("\nYour pay is %f dollars\n\n", pay);
      }
      else
      {
        printf("\nYour pay is %d dollars\n\n", (int)pay);
      }
      if(hours_worked >= 60 && employee_type == 1)
      {
        goto manager;
      }
      break;
    case 2:
      goto summary;
      break;
    case 3:
      change_hours:
      printf("New hours worked: ");
      scanf("%f", &hours_worked);
      if(hours_worked < 0.0)
      {
        goto change_hours;
      }
      if(hours_worked >= 60.0 && employee_type == 1)
      {
        goto manager;
      }
      break;
    case 4:
      change_rate:
      printf("New hourly rate: ");
      scanf("%f", &hourly_rate);
      if(hourly_rate <= 0.0 || hourly_rate > 100.0)
      {
        goto change_rate;
      }
      if(hours_worked >= 60.0 && employee_type == 1)
      {
        goto manager;
      }
      break;
    case 5:
      change_type:
      printf("\nType \"1\" if you are Hourly and \"2\" if you are Salary: ");
      scanf("%d", &employee_type);
      if(employee_type != 1 && employee_type != 2)
      {
        goto change_type;
      }
      if(hours_worked >= 60.0 && employee_type == 1)
      {
        goto manager;
      }
      break;
    case 6:
      goto manager;
      break;
    } //switch
    
    printf("\n\n");
    
  } //while loop
  
	return 0;
}