/*
Name : Ali Hassaan Mughal
Submission Date: 5th January 2017
Class : BS CS 6-B  Registration No: 173627
Program : Caeser Cipher (Encrypt or Decrypt the string) (How many times you want it prompts) (can be made more functional but was not required)
*/

#include <stdio.h>
#include <stdlib.h>
char upper[27]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
char lower[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
unsigned char string[100];
int encrypt(int key,char string[])                                              //Encryption Function Started
{
	int i,j;
	printf("Enter the String: ");
	getchar();
	gets(string);
	printf("Enter the Key:");
	scanf("%d", &key);
	for (i=0;string[i]!='\0';i++)
	{
		for (j=0;j<26;j++)
		{
			if (upper[j]==string[i])                                            //Comparing with the UpperCase letters
			{
				string[i]=upper[(j+key)%26];
				break;
			}
		}
			for (j=0;j<26;j++)
		{
			if (lower[j]==string[i] )											 //Comparing with the Lowercase letters
			{
				string[i]=lower[(j+key)%26];
				break;
			}
		}
	
	}
	printf("%s is the string\n", string);
}

int decrypt(int key,char string[])
{
	int i,j;
		printf("Enter the String: ");
	getchar();
	gets(string);
	printf("Enter the Key:");
	scanf("%d", &key);
	for (i=0;string[i]!='\0';i++)
	{
		for (j=0;j<26;j++)
		{
			if (upper[j]==string[i])                              //Comparing with Capital letters/alphabets.
			{
				if (j-key<0)
				{
					j+=26;
				}
				string[i]=upper[(j-key)%26];
				break;
			}
		}
			for (j=0;j<26;j++)
		{
			if (lower[j]==string[i] )                            //Comparing with Small letters/alphabets.
			{
				if (j-key<0)
				{
					j+=26;
				}
				string[i]=lower[(j-key)%26];
				break;
			}
		}
	
	}
	printf("%s is the string\n", string);
}

int main()
{
	int key; char option,again;
	do {
	start:                                                              //Start of Program Bookmarked
	system("cls");
	printf("Enter E or e for Encryption and D or d for decryption:");   //Asking for What the user want to do.
	scanf(" %c", &option);
	if (option=='E'||option=='e')
	{
	encrypt(key,string);
	}
	else if (option=='d'||option=='D')
	{
	decrypt(key,string);
	}
	else
	{
	goto start;
	}
	printf("Try again? Enter Y or y");                                //Use it again Feature.
	scanf(" %c", &again);
} while(again=='Y' || again=='y');

}
