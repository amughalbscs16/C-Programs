/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*\
|*                    Author : Ali Hassaan Mughal                *|
|*                       Program: Black Jack                     *|
|*                    Assignment Number 2.CS 110.                *|
\*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <stdio.h>
#include "time.h"
enum choices {hit,stay};  //List of Choices for The Player.

void main()
{
	start:
	system("cls");
    srand(time(NULL)); //New Random Number Generator Every time .
    char choice[5]; //Choice Hit or Stay
    char again; //Want to play again.
	int random_card_player,random_card_dealer;
    int player_card1 = (rand()%10) + 2;
    int player_card2 = (rand()%10) + 2;
    int dealer_card1 = (rand()%10) + 2;
    int dealer_card2 = (rand()%10) + 2;
    int total_player = player_card1+player_card2;
    int total_dealer = dealer_card1+dealer_card2;
    printf("Welcome to simple blackjack program!\n");
    printf("You get a %d and a %d.\n", player_card1, player_card2);
    printf("Your Total is %d.\n\n", total_player);
    printf("The Dealer has a %d showing, and a hidden card.\n", dealer_card1);
    printf("His total is hidden, too.\n\n");
    printf("Would you like to \"hit\" or \"stay\"? ");  //Takes input Hit or Stay
    scanf("%s", &choice);

    while (strcmp(choice, "hit")==0) //If player choses to hit
    {
        random_card_player=rand()%6+2;
        printf("You drew a %d\n", random_card_player);
        total_player += random_card_player;  //New Total after use hits.
        printf("Your total is %d\n\n", total_player);
        if (total_player>21)   //total of player is greater than 21 then print busted.
        {  
		 printf("Busted, Player Lost\n");
            goto end;   }
        printf("Would you like to \"hit\" or \"stay\"? ");  			//Takes input Hit or Stay
        scanf("%s", &choice);
    }
		
    if (strcmp(choice, "stay")==0)										//If player choses to stay
	{
        printf("Okay, dealer's turn.\n");
        printf("His hidden card was a %d\n",dealer_card2);
        printf("His total was %d\n\n",total_dealer);
        
    	while (total_dealer<=16)
   		{
        	random_card_dealer=rand()%6+2;    							 //Random card generator for Dealer
        	printf("\nDealer chooses to hit.\n");
        	printf("He draws a %d\n",random_card_dealer);
        	total_dealer += random_card_dealer; 						 //New total of dealer
		} 
		
        if (total_dealer>21)     										 //total of Dealer is greater than 21 then print busted.
        
        {
        	printf("Busted, Player Won\n");
        	goto end;
        }

        printf("Dealer stays\n");
        printf("Dealer total is %d\n", total_dealer);
        printf("Your total is %d\n\n",total_player);
        
		if (total_dealer > total_player)  									//Deciding Winner of Loser(Conclusion).
        {
			printf("YOU LOSE!\n");
    	}
		if (total_dealer == total_player)
        {
        	printf("You Lose!!\n");
    	}	
		if (total_dealer < total_player)
        {
			printf("YOU WIN!\n");
		}
		
		}
        end:	
        system("pause");
        printf("Want to play again - Press Y to play again: ");
		scanf(" %c", &again);        
		
		while (again == 'y' || again == 'Y')    				// Condition for Playing Again.
        {
        	goto start;
		}
		if (again != 'y' && again != 'Y')    					  // Condition For Exiting the Game.
		{
			printf("Thank you for Playing.\nBye\n");
		}

}																	//End Brace for Main.

