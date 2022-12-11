#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include "Bank_Account_Admin.h"
#include "Bank_Account_Client.h"
#include "STD_Types.h"








void Client_Window(){

    int opt_2;
    printf("\nWhat do you want to do?");
    printf("\n\n1.Make Transaction");
    printf("\n2.Change Account Password");
    printf("\n3.Get Cash");
    printf("\n4.Deposit in Account");
    printf("\n5.Return to main menu");
    printf("\n\nYour choice:\t");
    scanf("%d",&opt_2);
	switch(opt_2){
		case 1:
			Make_Transaction();
        break;

		case 2:
			Change_Account_Password();
        break;

		case 3:
			Get_Cash();
        break;
		case 4:
			Deposit_in_Account();
        break;
		case 5:
			printf("\n*****Thank You For Using Our System*****");
			Exit(1);

		default:
			printf("\nEnter the correct choice!!!");
	
}
}

void Change_Account_Password(){
	
}