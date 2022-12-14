#ifndef   Bank_Acc_Admin_H_
#define   Bank_Acc_Admin_H_

#include "STD_Types.h"

typedef struct Account
{
    u8 Full_Name[100];
    u8 Full_Address[200];
    u8 status[100];
	u8 Age ;
	f32 Balance;
	u8 Guardian_National_ID[15];
	int Bank_Account_ID;
	u8 National_ID[15];
	u8 state [100];
	u64 pass[50];
} user_t ;


void Create_Account();

void Open_Existing_Account();

void Make_Transaction(int source_id ,int destination_id,double money);

void Get_Cash(int user_id, double money);

void Deposit_in_Account(int user_id, double money);

void Admin_Window();

void Change_Account_Status(int user_id);



u64 generatePassword();
#endif