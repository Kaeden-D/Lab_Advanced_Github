#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	File: hw4_kaeden_daly.c
	Author: Kaeden Daly
	Course: CS125
	Assignement: Homework 4
	Date: 02/01/25
	References: Google
*/

//
int main ()
{
  int distance = rand() % 21 + 50; //Distance from flight path
  int margin = 5; //Needed distance from flight path
  int autopilot = 0; //0 (disabled) 1 (enabled)
  int elevation = 38000; //Current elevation
  int time_left = 10; //Seconds to destination
  
  int choice;
  
  srand(time(NULL));
  
  play_again:
  
  while(time_left > 0 && autopilot == 0)
  {
    printf("\n\n");
    printf("Current elevation: %d feet\n", elevation);
    printf("Current distance from flight path: %d\n", distance);
    printf("Needed distance from flight path: %d\n", margin);
    printf("Time left till destination: %d\n", time_left);
    (autopilot == 0) ? printf("Autopilot disabled\n")
                     : printf("Autopilot enabled\n");
    
    do
    {
      printf("\n\n\nType \"1\" to correct flight path.\n");
      printf("Type \"2\" to stay flight path.\n");
      printf("...: ");
    }
    while(scanf("%d", &choice) != 1 || (choice < 1 || choice > 2));
    
    if (distance < 0) 
    {
    ++choice;
    }
    
    switch(choice % 2)
    {
    case 0:
      distance += rand() % 25 + 1;
      break;
    case 1:
      distance -= rand() % 25 + 1;
      break;
    }
    
    if(distance > -margin && distance < margin)
    {
      autopilot = 1;
      printf("\n\nAutopilot has been re-enabled\n\n");
    }
    
    time_left--;
    sleep(1);
  }
  
  printf("\n\n\n");
  
  if(autopilot == 1)
  {
    printf("Congratulations!\n");
    printf("You have beat the game with %d seconds left\n\n", time_left);
  }
  else if(time == 0)
  {
    printf("Sorry.");
    printf("You have lost the game with %d distance away\n\n", distance);
  }
  
  do
  {
    printf("\n\n\nType \"1\" to play again.\n");
    printf("Type \"2\" to quit the game.\n");
    printf("...: ");
  }
  while(scanf("%d", &choice) != 1 || (choice < 1 || choice > 2));
  
  distance = rand() % 21 + 50;
  autopilot = 0;
  time_left = 10;
    
  switch(choice)
  {
  case 1:
    printf("\n\nReinitializing Simulator.\n");
    goto play_again;
  case 2:
    printf("\n\nShutting Down Simulator.\n");
    return 0;
  }
  
}