#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()

{
	int userin,userscr,computerscr,user_prev,highscore,highscr_txt;
	
	srand(time(NULL));
	int randomnumber;
	int round,comparer,current_round=0;
	int* keyin;
	int restart=2;
	highscore=0;
	user_prev=0;
	userscr=0;
	while(restart==2)
	{
		FILE *fptr;
			if ((fptr = fopen("hscore.txt","r")) == NULL) {
                printf("Scores file was not found\n");
                fptr = fopen("hscore.txt","w");
                fprintf(fptr, "0");
            }
			fscanf(fptr,"%d", &highscr_txt);
			fclose(fptr);
		user_prev=highscr_txt;
		userscr=0;
		computerscr=0;
		/* Debug
		printf("current level = %d\n",round);*/
		printf("\nEnter Number of Rounds:");
		scanf("%d",&round);
		comparer= round*10;
		
		while(round<comparer)	
		{
			//Display Current Round
			if(round>1)
			{
				current_round=current_round+1;
				printf("\n\t\t<<< Round %d >>>\n",current_round);
			}
			
			printf("\n\t");
			printf("Stone[1] Paper[2] Scissor[3] \n");
			
			printf("Enter:");
			scanf("%d",&userin);
			printf("\t------------------\n");
			printf("  >>>\t");

			if (userin==1)
			{
				printf("You: Stone \n");
			}
			else if (userin==2)
			{
				printf("You: Paper \n");
			}
			else if (userin==3)
			{
				printf("You: Scissor \n");
			}
			else
				printf("Invalid, Enter numbers between 1-3");
			
			/* Debug
			printf("randnum = %d \n",randomnumber);*/
			
			/*Computer Output ↓ */
			srand(time(0));
			randomnumber = (rand() % (2 + 1 - 0)) + 0;
			if (randomnumber==0)
			{
				printf("\t");
				printf("Computer: Stone \n");
			}
			
			if (randomnumber==1)
			{
				printf("\t");
				printf("Computer: Paper \n");
			}
			if (randomnumber==2)
			{
				printf("\t");
				printf("Computer: Scissor \n");
			}
			
			printf("\t------------------\n");
			
			//SCORE
			
			/* Computer values = Stone[0] Paper[1] Scissor[2]
			User values = Stone[1] Paper[2] Scissor[3]*/
			
			//Computer
			if (userin==1)
			{
				if (randomnumber==1)
				{
					computerscr=computerscr+1;
				}
			}
			if (userin==2)
			{
				if (randomnumber==2)
				{
					computerscr=computerscr+1;
				}
			}
			if (userin==3)
			{
				if (randomnumber==0)
				{
					computerscr=computerscr+1;
				}
			}
			
			//User
			if (userin==1)
			{
				if (randomnumber==2)
				{
					userscr=userscr+1;
				}
			}
			if (userin==2)
			{
				if (randomnumber==0)
				{
					userscr=userscr+1;
				}
			}
			if (userin==3)
			{
				if (randomnumber==1)
				{
					userscr=userscr+1;
				}
			}
			
			printf("\n");
			
			printf("\t---SCORE---\n");
			printf("\tYour:%d\n",userscr);
			printf("\tComputer:%d\n",computerscr);
			printf("\t   ____\n");
			comparer = comparer-10;
				
		}
		if(userscr>computerscr)
			{
				printf("\n\n");
				printf("\t---Congragulations You Won---\n");
				printf("\n\t\tYour Score: %d \n\t\tComputer's Score: %d",userscr, computerscr);
			}
		if(userscr<computerscr)
			{
				printf("\n\n");
				printf("\t---You Lost Try Again next Time---\n");
				printf("\n\t\tYour Score: %d \n\t\tComputer's Score: %d",userscr, computerscr);
			}
	// Final HighScore [PERMANENT]
		if(userscr>user_prev)
		{
			highscore=userscr;
			
			FILE *fptr;
			fptr = fopen("hscore.txt","w");
		   fprintf(fptr,"%d",highscore);
		   fclose(fptr);
		}
		if(userscr<user_prev)
		{
			highscore=user_prev;
			FILE *fptr;
		   fptr = fopen("hscore.txt","w");
		   fprintf(fptr,"%d",highscore);
		   fclose(fptr);
		}
			// Game Options
		printf("\n\n\t\t---Options--- \n\n| Quit Game [1] | Restart[2] | About & Credits[3] | Title[4] | HighScore[5] |:");
		scanf("%d",&restart);
		
			if(restart==6){
				system("start https://www.youtube.com/watch?v=dQw4w9WgXcQ");
				printf(":)");
			}
			
			if(restart==1)
			{
				return(0);
			}
			
			if(restart==3)
			{
				printf("\n\t\t---ABOUT---\n\n\t---Stone Paper Scissors---");
				printf("\n\tA simple game made by RBN using C programming language.");
				printf("\n\n\t---Credits---\n\tRBN - Creator \n\tStarkshat - Helped to fix an error(Thank You Starkshat!)");
			}
			if(restart==4)
			{
				
				printf("\n\t ######  ########  #######  ##    ## ########    ########     ###    ########  ######## ########      ######   ######  ####  ######   ######   #######  ########   ######  ");
				printf("\n\t##    ##    ##    ##     ## ###   ## ##          ##     ##   ## ##   ##     ## ##       ##     ##    ##    ## ##    ##  ##  ##    ## ##    ## ##     ## ##     ## ##    ## ");
				printf("\n\t##          ##    ##     ## ####  ## ##          ##     ##  ##   ##  ##     ## ##       ##     ##    ##       ##        ##  ##       ##       ##     ## ##     ## ##       ");
				printf("\n\t ######     ##    ##     ## ## ## ## ######      ########  ##     ## ########  ######   ########      ######  ##        ##   ######   ######  ##     ## ########   ######  ");
				printf("\n\t      ##    ##    ##     ## ##  #### ##          ##        ######### ##        ##       ##   ##            ## ##        ##        ##       ## ##     ## ##   ##         ## ");
				printf("\n\t##    ##    ##    ##     ## ##   ### ##          ##        ##     ## ##        ##       ##    ##     ##    ## ##    ##  ##  ##    ## ##    ## ##     ## ##    ##  ##    ## ");
				printf("\n\t ######     ##     #######  ##    ## ########    ##        ##     ## ##        ######## ##     ##     ######   ######  ####  ######   ######   #######  ##     ##  ######  ");
				
			}
			
			if(restart==5)
			{
				FILE *fptr;
				fptr = fopen("hscore.txt","r");
				fscanf(fptr,"%d", &highscr_txt);
				
				printf("\n\t---HighScore---\n");
				printf("\tHighScore: %d\n", highscr_txt);
				fclose(fptr);
			}
			if(restart!=2)
			{
				printf("\n\nPress any key to continue...");
				scanf("%d",&keyin);
				if(keyin!= NULL)
					return(0);
			}
		}
		
	return(0);
}
