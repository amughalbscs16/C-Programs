#include <stdio.h>
#include <stdlib.h>
/*Authors Information
Author #1
Name : Ali Hassaan Mughal
Class: BS CS 6-B.
Reg No Leader: 173627
Author #2
Name : Muhammad Asim Noor
Class: BS CS 6-B.

About Program.
Program is known as simplified solitaire encryption.
It encodes and decodes the message under different card numbers.
Uses keystreams and conversion of letters into numbers to encrypt
and then decrypt the message. Learnt a lot from it.

Difficulties.
Difficulty was the management of time for this project, It took a lot of time as well as effort.
Different steps, with different procedures and varying in difficulty.
Made me learn a lot.*/
int main()
{
	int num[28]={1,4,7,10,13,16,19,22,25,28,3,6,9,12,15,18,21,24,27,2,5,8,11,14,17,20,23,26},new1[28],num4[28];   //Number Arrays to be Used for different Steps.
	int i,j,locationofjoker1,locationofjoker2,locationofclosejoker,locationoffarjoker,tmp1,tmp2;       
	int keystream[40];
	char message[40];
	char refinedmessage[40]; 
	int countmessage=0,othercharacters=0,times=0;
	for (i=0;i<28;i++)           //Makes the given numbers Random and doesn't let them repeat.
	{
		num[i]=((num[i]+rand())%28)+1;
	}
	start:                                           //Book Mark to Starting of the Program.
	system("cls");                                   //Clear Screen
	printf("Enter a message : ");                    
	
   	gets(message);									//Get a Message from user to encrypt.
	for (i=0;message[i]!='\0';i++)                  // Refining the Message by removing Commas and Spaces.
	{
		
	if (message[i]==',' || message[i]==' ' || message[i]=='\'')
	{
		othercharacters++;
		i++;
	}
	
	refinedmessage[i-othercharacters]=message[i];
	countmessage++;
	
	}
	
	refinedmessage[i-othercharacters]='\0';
	
	for (i=1;refinedmessage[i]!='\0';i++)          //Capitalizing the Elements of the Refined String.
	{
		
		if (refinedmessage[i] >= 97)
		{
			refinedmessage[i]-=32;
		}
			
	}
	do {
	
	   
	for (i=0;i<28;i++)                           //Swapping The 1st Joker by one position beneath,
        {
       if (num[i]==27)
        {
		tmp1=num[i];
		num[i]=num[(i+1)%28];
		num[(i+1)%28]=tmp1;
		break;
		
        }
       
    	}
    	
    	
    	
    	
for (i=0;i<28;i++)						////Swapping The 2st Joker by two position beneath,
    {
	  
       if (num[i]==28)
		{
		num[i]=num[i]+num[(i+2)%28];
		num[(i+2)%28]=num[i]-num[(i+2)%28];
		num[i]=num[i]-num[(i+2)%28];
		num[i]=num[i]+num[(i+1)%28];
		num[(i+1)%28]=num[i]-num[(i+1)%28];
		num[i]=num[i]-num[(i+1)%28];
	
		break;
		}
	}
	
	
	
   		
for (i=0;i<28;i++)      //Triple Cut 3rd Swap the cards above the first joker (the one closest to the top of the deck)
						//with the cards below the second joker.
   	{
   	if (num[i]==28)
   		{
   		locationofjoker2=i;
		}
	}
for (i=0;i<28;i++)
   	{
   	if (num[i]==27)
   		{
   		locationofjoker1=i;
	    }
	}
	if (locationofjoker1>locationofjoker2)    //Calculating Closer and Far Joker from the Top of the Deck.
	{
	locationofclosejoker=locationofjoker2;
	locationoffarjoker=locationofjoker1;
	}
	else if(locationofjoker1<locationofjoker2)
	{
	locationofclosejoker=locationofjoker1;
	locationoffarjoker=locationofjoker2;
	}
	int newele=27;
	for (i=locationofclosejoker-1;i>-1;i--)
	{	
		new1[newele]=num[i];
		newele--;
		if (i==0)
		{
			new1[newele]=num[locationoffarjoker];
		}
	}
	int newele1=0;
	for (i=locationoffarjoker+1;i<28;i++)
	{
		new1[newele1]=num[i];
		newele1++;
		if (i==27)
		{
			new1[newele1]=num[locationofclosejoker];
		}
	}
	for (i=locationofclosejoker+1;i<locationoffarjoker;i++)
	{	newele1++;
	if (newele1!=newele){
	
		new1[newele1]=num[i];
	}
	}										//3rd Step Finish




int cometopelement=26;    //4th step. Taking the Number of Elements equal to the last number after the last number.
for (i=0;i<new1[27];i++)
{
	num4[cometopelement]=new1[new1[27]-i-1];
	cometopelement--;
	
}
for (i=0;i<28-new1[27]-1;i++)
{
num4[i]=new1[i+new1[27]];
}

int newelementdown=0;
num4[27]=new1[27];
for (i=0;i<28;i++)
{
	num[i]=num4[i];
}

keystream[times]=num4[num4[0]];              			//Saving the Key Stream values generated in each string.
if (keystream[times]==27 || keystream[times]==28)
{times--;
}
times++;
} while (times<countmessage);          //Loop To Generate Key Streams for Each Element in the String.

//Final Printing Out Work
//Output of the Whole program


printf("\n\nENCRYPTION PASS...\n\n");


printf("\n\nRefined Message\t\t");

for (i=0;i<countmessage;i++)
{
	printf("%c  ", refinedmessage[i]);
}

printf("\n\nLetters to Numbers.\t");

for (i=0;i<countmessage;i++)
{
	printf("%d ", refinedmessage[i]-64 );
}

printf("\n\nKey Streams\t\t");

for (i=0;i<countmessage;i++)
{
	printf("%d ", keystream[i]);
}

int encoded[28];                                         //Array of Encoded Numbers.

printf("\n\nEncoded Numbers.\t");

for (i=0;i<countmessage;i++)
{
	encoded[i]=((keystream[i]+refinedmessage[i]-64)%26);
	if (encoded[i]==0)
	{
	encoded[i]+=26;
	}
	printf("%d ", encoded[i] );
}

char encodedmessage[28];                                    //String of Encoded Message

printf("\n\nEncoded Message.\t");

for (i=0;i<countmessage;i++)
{
	encodedmessage[i]=encoded[i]+64;
	printf("%c  ", encodedmessage[i]);
}




printf("\n\nDECRYPTION PASS...\n\n");

printf("\n\nEncoded Message.\t");

for (i=0;i<countmessage;i++)
{
	encodedmessage[i]=encoded[i]+64;
	printf("%c  ", encodedmessage[i]);
}
printf("\n\nLetters to Numbers.\t");

for (i=0;i<countmessage;i++)
{
	encoded[i]=((keystream[i]+refinedmessage[i]-64)%26);
	if (encoded[i]==0)
	{
	encoded[i]+=26;
	}
	printf("%d ", encoded[i] );
}

printf("\n\nKey Streams\t\t");

for (i=0;i<countmessage;i++)
{
	printf("%d ", keystream[i]);
}

printf("\n\nDecoded Numbers\t\t");

for (i=0;i<countmessage;i++)
{
	printf("%d ", refinedmessage[i]-64 );
}

printf("\n\nDecoded Message.\t");
for (i=0;i<countmessage;i++)
{
	printf("%c  ", refinedmessage[i]);
}
return 0;
}



