#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<malloc.h>
#include<string.h>

float draw, tot_draw = 0.0, dep, tot_dep = 0.0, transfer, tot_transfer = 0.0;
char name[100];
float balance = 0.0;
int acc_no, account1, pin;
int transaction = 1;
int i,j;

typedef struct account 
{
	float amount;
	char transac_name[100];
	struct account *next;
}account;

account *head;
account *acc_ptr;
account *temp;

void current_time()
{
	time_t rawtime;
  	struct tm * timeinfo;
	time ( &rawtime );
  	timeinfo = localtime ( &rawtime );
  	printf ( "Current time and date: %s", asctime (timeinfo) );
}

void fordelay(int p)
{   
	int i,k;
    for(i=0;i<p;i++)
    {
	    k=i;
	}
}

void menu(int ch)
{
	
	switch(ch)
	{
		case 1:
		system("clear");
		printf("\t\t\t*BALANCE ENQUIRY*\n\n");
		for(i = 0; i<=1; i++)
		{
			printf("\t\t\t     LOADING");
			for(j = 0; j<=3; j++)
			{	
				fordelay(100000000);
				printf(".");
			}
			printf("\r");
		}
		printf("Your current bank balance: Rs. %.2f\n", balance);
		break;
		
		case 2:
		system("clear");
		printf("\n\t\t\t*DEPOSIT AMOUNT*\n\n");
		printf("Enter deposit amount: ");
		scanf("%f", &dep);
		printf("\t\t\t     LOADING");
		for(j = 0; j<=3; j++)
		{	
			fordelay(100000000);
			printf(".");
		}
		printf("\r");
		if(dep > 0 && dep<=20000)
		{
			printf("\nRs. %.2f deposited in account number %d.", dep, acc_no);
			balance = balance + dep;
			tot_dep = tot_dep + dep;
			temp->amount = dep;
			strcpy(temp->transac_name, "Deposit:");
			temp->next = NULL;
			acc_ptr->next = temp;
			acc_ptr = temp;
		}
		else if(dep>20000)
		{
			printf("\nYou cannot deposit that amount in one time!!!\n");
		}
		else
		{
			printf("\nInvalid deposit amount!!\n");
		}
		break;
		
		case 3:
		system("clear");
		printf("\n\t\t\t*WITHDRAW AMOUNT*\n\n");
		printf("Enter withdraw amount: ");
		scanf("%f", &draw);
		printf("\t\t\t     LOADING");
		for(j = 0; j<=3; j++)
		{	
			fordelay(100000000);
			printf(".");
		}
		if(draw<balance)
		{
			if(draw > 0 && draw <=20000)
			{
				printf("\nRs. %.2f has been withdrawn in account number %d.\n\n", draw,acc_no);
				balance = balance - draw;
				tot_draw = tot_draw + draw;
				temp->amount = draw;
				strcpy(temp->transac_name, "Withdraw:");
				temp->next = NULL;
				acc_ptr->next = temp;
				acc_ptr = temp;
			}
			else if(draw>20000)
			{
				printf("\nYou cannot withdraw that amount in one time!!!\n");
			}
			else
			{
				printf("\nInvalid withdraw amount!!\n");
			}
		}
		else
		{
			printf("\nInsufficient balance!!!\n");
		}
		break;
		
		case 4:
		system("clear");
		printf("\n\t\t\t*TRANSFER AMOUNT*\n\n");
		printf("Enter account number to which money will be transferred: ");
		scanf("%d", &account1);
		printf("Enter amount to be transferred: ");
		scanf("%f", &transfer);
		printf("\t\t\t     LOADING");
		for(j = 0; j<=3; j++)
		{	
			fordelay(100000000);
			printf(".");
		}
		if(balance >= transfer)
		{
			printf("\nTranfer Successful!!\n");
			printf("\nRs. %.2f has been transferred from your account to account number %d\n\n", transfer, account1);
			balance = balance - transfer;
			tot_transfer = tot_transfer + transfer;
			temp->amount = transfer;
			strcpy(temp->transac_name, "Transfer:");
			temp->next = NULL;
			acc_ptr->next = temp;
			acc_ptr = temp;
		}
		else
		{
			printf("\nYou donot have sufficient balance!!\n");
		}
		break;
		
		case 5:
		system("clear");
		temp = head;
		while(temp != NULL)
		{
			
			puts(temp->transac_name);
			printf("\t%.2f\n", temp->amount);
			temp = temp->next;
		}
		break;
		
		case 6:
		system("clear");
		while(head != NULL)
		{
			temp = head;
			head = head->next;
			free(temp);
		}
		printf("\n\t\t\tACCOUNT DELETED SUCCESSFULLY!!\t\t\t\n");
		printf("\n\t\t\tTHANK YOU FOR USING BANK!!!\t\t\t\n");
		printf("\n\t\t\tHAVE A GOOD DAY\t\t\t\n");
		exit(0);
		break;
		
		default:
		printf("\nInvalid Transaction!!\n");
		break;
	}
	acc_ptr->next = NULL;
}

int main()
{
	system("clear");
	
	printf("\n\t\t\t    * * * BANKING SYSTEM * * *\n\n");
	printf("\t\t");
	for(i=0;i<=25;i++)
		printf("* ");
	printf("\n");
	printf("\t\t*\t\t\t\t\t\t  *\n");
	printf("\t\t*\t\t\t\t\t\t  *\n");
	printf("\t\t*\tWELCOME TO  BANK PRIVATE LIMITED\t  *\n");
	printf("\t\t*\t\t\t\t\t\t  *\n");
	printf("\t\t*\t\t\t\t\t\t  *\n");
	printf("\t\t");
	for(i = 0; i<=25 ; i++)
		printf("* ");
	printf("\n\n");
	
	for(i = 0; i<=1; i++)
	{
		printf("\t\t\t\tLOADING");
		for(j = 0; j<=6; j++)
		{
			
			fordelay(100000000);
			printf(".");
		}
		printf("\r");
	}
	system("clear");
	system("color 9");
	printf("Enter your name: ");
	gets(name);
	printf("Hello %s. Please enter your account number: ", name);
	scanf("%d", &acc_no);
	head = (account*)malloc(sizeof(account));
	head->amount = balance;
	head->next = NULL;
	acc_ptr = (account*)malloc(sizeof(account));
	acc_ptr = head;
	temp = (account*)malloc(sizeof(account));
	while (transaction == 1)
	{
		int choice;
		fordelay(100000000);
		system("clear");
		printf("\n\nChoose what you want to do\n");
		printf("1 - Balance Enquiry\n");
		printf("2 - Deposit\n");
		printf("3 - Withdraw\n");
		printf("4 - Transfer\n");
		printf("5 - Display all transactions\n");
		printf("6 - Delete account\n\n");
		scanf("%d", &choice);
		menu(choice);
		transaction = 0;
		while(transaction != 1 && transaction != 2)
		{
			printf("\nDo you want to do another transaction?\n");
			printf("1. YES 2. NO\n");
			scanf("%d", &transaction);
			if(transaction != 1 && transaction != 2)
			{
				printf("Invalid number. \nChoose between 1 and 2 only\n");
			}
		}
	}
	system("clear");
	printf("\n\t\t\tYou have balance Rs.%.2f", balance);
	printf("\n\t\t\tYou have deposited Rs.%.2f", tot_dep);
	printf("\n\t\t\tYou have withdrawn Rs.%.2f", tot_draw);
	printf("\n\t\t\tYou have transferred Rs.%.2f", tot_transfer);
	printf("\n\t\t\t    --------------------------------");
	printf("\n\t\t\t\t BANK PRIVATE LIMITED\n");
	printf("\t\t\t      --------------------------------\n");
	current_time();
	return 0;
}
