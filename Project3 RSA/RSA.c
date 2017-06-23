/*
Program : RSA.
Authors : Ali Hassaan Mughal , Furqan Sadiq.
Class : BS CS 6-B.
Encrypts and Decrypts a message with the help of prime numbers and applying different operations such as modulo etc.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
unsigned long long findd( unsigned long long e, unsigned long long phi);  //Prototype of find (value of d);
unsigned long long p,q,n,e,phi,d;  char message[50]="Rome is not built in one day"; int intmessage[50],keymessage[50],encryptednumber[50],decryptednumber[50],decryptedindividual[50];
int prime[10]={2,3,5,7,11,13,17,19,23,29}, prime2[10]={31,37,41,43,47,53,59,61,67,71};
int key=2,keycount,i,j;
char capital[29]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',' ','.','\0'};  
char lower[29]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' ','.','\0'};



int main()
{

	primes();           //Calling Values of Prime Numbers.
	welcomemessage();   //Printing welcome Message
	welcomemessage2();  //Printing Welcome Message 2
	capitalize();   //Convert the letters into Capital Letters.
	printing();     //Printing The Messages with its number value in the list.
	applykey();		//Applying key to make messages divided in parts of 2 or more characters. In this case set to 2.
	encryption();   //Encrypts the messages number into another numbers by parts.
	decryption();   //Decrypts the message parts.
	decryptionprinter();    //Prints the Decrypted of Message 
	output();			// Prints the Last Output alphabet by alphabet.
}
int welcomemessage()
{
	printf("\n\n");

	printf("+--------------------+\n");
	printf("|  I. Key Generation |\n");
	printf("+--------------------+\n");	printf("\n\n");
	printf("Public  key. (e,n) = (  %d,%d)\n", e,n);
	printf("Private key. (d,n) = (%d,%d)", d,n);
	printf("\n\n");
}
int welcomemessage2()
{
	printf("\n\n");	
	printf("+--------------------------+\n");
	printf("|  II. Cipher and Decipher |\n");
	printf("+--------------------------+\n");
	printf("\n\n");
}

unsigned long long power_mod(unsigned long long power,unsigned long long variable,unsigned long long modnum)
{
	int i;
	unsigned long long modulus=1;
	for (i=1;i<=power;i++)
	{
	modulus=(modulus*variable)%modnum;
	}
	return modulus;	
}
int capitalize()          //Capitalize and Converting into Numbers;
{

	for (i=0;message[i]!='\0';i++)
	{
		
		for (j=0;j<29;j++)
		{
			
		
			if (capital[j]==message[i])
			{
				intmessage[i]=j;
			}
			else if (lower[j]==message[i])
			{
				message[i]=capital[j];
				intmessage[i]=j;
			}
			
			
		}
	}
}
	//End Capitalize
int printing()
{
		
	printf("\n");
	printf("Input. |");
	for (i=0;message[i]!='\0';i++)
	{
			
	printf(" %c |", message[i]);
	}
	printf("\n");
	printf("       |");
	for (i=0;message[i]!='\0';i++)
	{
			if (intmessage[i]<9)
			printf(" %d |",intmessage[i]);
			else
	printf("%d |", intmessage[i]);
	}

    printf("\n");printf("\n");
    printf("\n");
    for (i=0;message[i]!='\0';i+=key)
    {
  	printf(" %c %c  |", message[i],message[i+1]);
  	}
    printf("\n");
}
    
    
    //Applying Key Conversion of Characters into Number(2 Numbers)
int applykey()
{
   	keycount=0;
   // Converting into Integer with Key and storing into KeyMessage
  	for (i=0;message[i]!='\0';i+=key)
  	{
  	keymessage[i-keycount]=(intmessage[i]*100)+(intmessage[i+1]);
  	keycount++;
  	}
  	for (i=0;i<keycount;i++)
  	{
  		if (keymessage[i]<1000)
  		printf(" %d  |",keymessage[i]);
  		else
  		printf(" %d |", keymessage[i]);
  	}
  	printf("\n");
}
   
  //Encryption work.
int encryption()
{
  
  for (i=0;i<keycount;i++)
  {
  encryptednumber[i]=power_mod(e,keymessage[i],n);
  if (encryptednumber[i]<1000)
  		printf(" %d  |",encryptednumber[i]);
  		else
  printf(" %d |", encryptednumber[i]);
  }

}
  
int decryption()
{
  //Decription Work;
  printf("\n");
   for (i=0;i<keycount;i++)
  {
  decryptednumber[i]=power_mod(d,encryptednumber[i],n);
  if (decryptednumber[i]<1000)
  		printf(" %d  |",decryptednumber[i]);
  		else
  printf(" %d |", decryptednumber[i]);
  }
  printf("\n");
}

int decryptionprinter()
{ 
	keycount=0;
	for (i=0;message[i]!='\0';i+=2)
	{
	decryptedindividual[i]=decryptednumber[i-keycount]/100;
	decryptedindividual[i+1]=decryptednumber[i-keycount]-(decryptedindividual[i]*100);
	printf(" %c %c  |", capital[decryptedindividual[i]],capital[decryptedindividual[i+1]]);
    keycount++;
	}
}
int output()
{	
printf("\n\nOutput. |");
	for (i=0;message[i]!='\0';i++)
	{
		if (decryptedindividual[i]<10)
		printf(" %d |", decryptedindividual[i]);
		else
		printf("%d |", decryptedindividual[i]);
	}
	printf("\n\n");
	printf("        |");
	for (i=0;message[i]!='\0';i++)
	{
		printf(" %c |", capital[decryptedindividual[i]]);
	}
}
int primes()
{	
	srand(time(0));
	p=61;
	q=53;
	n=p*q;
	phi=(p-1)*(q-1);
	e=17;
	d=findd(e,phi);
}


unsigned long long findd( unsigned long long e, unsigned long long phi)
{
	unsigned long long x, y, u, v, m, n, a, b, q, r;
	/* phi = e(0) + phi(1) */
	x = 0; y = 1;

	/* e = e(1) + phi(0) */
	u = 1; v = 0;
	for (a = e, b = phi; 0 != a; b = a, a = r, x = u, y = v, u = m, v = n)
	{
		/* b = aq + r and 0 <= r < a */
		q = b / a;
		r = b % a;

		/* r = Ax + By - aq = Ax + By - (Au + Bv)q = pe(x - uq) + pphi(y - vq) */
		m = x - (u * q);
		n = y - (v * q);
	}

	/* Ax + By = gcd(e, phi) */
	// b contains the gcd and had better be 1
	// d is the sum of x and m.
	return m + x;
}
















