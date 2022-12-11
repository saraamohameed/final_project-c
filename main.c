#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Bank_Account_Admin.h"
#include "Bank_Account_Client.h"
#include "STD_Types.h"
#include<windows.h>

void Create_Account();
void Open_Existing_Account();
void Get_Cash();
void Deposit_in_Account();
void Change_Account_Status();
void Change_Account_Password();
void Admin_Window();
void Client_Window();
void Make_Transaction(int source_id ,int destination_id,double money);

int counter ;
user_t arr[200] ;
int Bank_Account_ID;

int main()
{ 
int choice;

	while(1){
	printf("Welcome to Bank System \n");
	printf("\nWhat do you want ?");
	printf("\n\n1. Admin Window");
	printf("\n2. Client Window");
	printf("\n3. Exit");
	printf("\n\nYour choice:\t");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			Admin_Window();
			break;

		case 2:
			Client_Window();
			break;

		case 3:
			printf("\n*****Thank You For Using Our System*****");
			exit(1);

		default:
			printf("\nEnter the correct choice!!!");
	}
	}

}