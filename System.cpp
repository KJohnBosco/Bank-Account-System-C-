#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <limits>

using namespace std;

class Account{
	int AC_PIN,  Current_Balance = 0;
	string AC_Number;
	fstream Acct, Temp;
	
	public:
	
	void Main_Menu(){
	Account A1;
		int action;
	
	// Menu
	Start:
	cout << "\n"
	"\t\t\t===========================\n"
	"\t\t\t\tBANK ACCOUNT\n"
	"\t\t\t===========================\n"
	"\t\t\t1. Create account\n"
	"\t\t\t2. Check balance\n"
	"\t\t\t3. Deposit\n"
	"\t\t\t4. Withdraw\n"
	"\t\t\t0. Exit\n"
	"\t\t\tSelect action:[1,2,3,4,0]:\n\t\t\t";
	
	// Fetching user input
	cin >> action;
	
	// Clear screen
	system("cls");
	
	// Handling invalid input
	if(cin.fail()){	
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\t\t\tInvalid input" << endl;
		goto Start;
	}
	
	// Selecting action based on the user input
	if(action == 0){
		cout << "\t\t\tExiting..." << endl;
		return;
	}
	else if(action == 1){
		A1.Create_account();
	}
	else if(action == 2){
		A1.Check_balance();
	}
	else if(action == 3){
		A1.Deposit();
	}
	else if(action == 4){	
		A1.Withdraw();
	}
	else{
		system("cls");
		cout << "\t\t\tInvalid input!" << endl;
		goto Start;
	}
	

}
	
	void Return(){
	Start:
	int choice;
	cout << "\n"
	"\t\t\t1. Return to main menu\n"
	"\t\t\t0. Exit\n\t\t\t";
	cin >> choice;
	
	if(cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "\n\t\t\tInvalid choice!"<< endl;
		goto Start;
	}
	
	if(choice == 0){
		cout << "\t\t\tExiting..." << endl;
		exit(0);
	}
	else if(choice == 1){
		system("cls");
		Main_Menu();
	}
	
}
	
	void Create_account(){
	Start: // Create Account scope
	
	// Variable declarations
	string First_Name, Last_Name, Password;
	int Initial_Deposit;
	char Account_Number[11] = "AC1952D65O";
	
	// Printing the title
	cout << "\n"
	"\t\t\t===========================\n"
	"\t\t\t\t CREATE ACCOUNT\n"
	"\t\t\t===========================\n"
	"\t\t\t*Recommended to use Upper case!*\n\n"
	"\t\t\tFirst name:";
	cin >> First_Name; // Get first name
	
	// Error handlimg for first name
	if(cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("cls");
		cout << "\n\t\t\tInvalid Input!"<< endl;
		goto Start;
	}
	
	cout << "\n\t\t\tSecond name:";
	cin >> Last_Name; // Getting last name
	
	// Error handlimg for Last name
	if(cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("cls");
		cout << "\n\t\t\tInvalid Input!"<< endl;
		goto Start;
	}
	
	cout << "\n\t\t\tInitial deposit:[>UGX.10,000]";
	cin >> Initial_Deposit; // Getting the Initial Deposit
	
	// Error handlimg for Initial Deposit
	if(cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("cls");
		cout << "\n\t\t\tInvalid Input!"<< endl;
		goto Start;
	}
	else if(Initial_Deposit < 10000){
		system("cls");
		cout << "\t\t\tThe Initial amount should be greater than UGX.10,000!" << endl;
		goto Start;
	}

	cout << "\n\t\t\tSet PIN:[4 digits]";
	cin >> AC_PIN; // Getting the User PIN set
	
	// Error handlimg for Setting PIN
	if(cin.fail()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		system("cls");
		cout << "\n\t\t\tInvalid PIN!"<< endl;
		goto Start;
	}
	
		
	
	// Generating account Number//////////
	
	Account_Number[0] = First_Name[0];
	Account_Number[1] = Last_Name[0];
	Account_Number[2] = '1';
	Account_Number[3] = '9';
	Account_Number[4] = '5';
	Account_Number[5] = '2';
	Account_Number[6] = First_Name[2];
	Account_Number[7] = '6';
	Account_Number[8] = '5';
	Account_Number[9] = Last_Name[2];
	
	// Assign Function values to class variables
	Current_Balance = Initial_Deposit;
	AC_Number = Account_Number;
	
	// Prompt Account created successfully
	system("cls");
	cout << "\t\t\t===========================================\n"
	"\t\t\tAccount created successfully...!\n"
	"\t\t\t===========================================\n\n"
	"\t\t\tAccount Name: " << First_Name << " " << Last_Name << "\n"
	"\t\t\tAccount Number: " << AC_Number << "\n"
	"\t\t\tCurrent Balance: UGX." << Current_Balance << "\n";
	
	// Saving Account in the database
	Acct.open("Accounts.txt", ios::app);
	if(Acct.is_open()){
		Acct << "=============================================" << endl;
		Acct << Account_Number << endl;
		Acct << First_Name << " " << Last_Name << endl;
		Acct << Current_Balance << endl;
		Acct << AC_PIN << endl;
		Acct << "\n\n";
	}
	else{
		cout << "\t\t\tSorry, we could not access the database at a moment!\n"
		"\t\t\tPlease contact the service support team for help!\n";
	}
	Acct.close();
	
	
	// Returning func
	Return();
	
		
	}

	void Check_balance(){
		int ITER;
		Start:
		string Ac_No;
		int PIN;
		bool Wrong_Credentials = false;
		
		cout << "\n"
		"\t\t\t===========================\n"
		"\t\t\t\t ACCOUNT BALANCE\n"
		"\t\t\t===========================\n\n"
		"\t\t\tEnter Account Number: ";
		cin >> Ac_No;
		
		// Error handling for Ac_No
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
			cout << "\t\t\tInvalid input..!!" << endl;
			goto Start;
		}
		Re_PIN:
		
		// Check for the wrong PIN prompts
		if(ITER == 3){
			cout << "\n\n\t\t\tWe couldn't complete this action because of too many wrong PIN attempts!\n"
			"\t\t\tPlease retry again later after recovering your password...!" << endl;
			exit(0);
		}
		
		// Getting PIN from user
		cout << "\t\t\tEnter PIN: ";
		cin >> PIN;
		
		// Error handling for PIN
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
			cout << "\t\t\tInvalid input..!!" << endl;
			goto Start;
		}
		// Checking the Account PIN in the database
		string Pin_Ln;
		bool Fd = false;
		int Account_PIN = 0;
		int Iter = 0;
		ifstream Acct("Accounts.txt");
		if(Acct.is_open()){
			while(getline(Acct, Pin_Ln)){
				// Touggle Fd to true when the target account is found.
				if(Pin_Ln == Ac_No){
					Fd = true;
				}
				
				//	Continue if target account is not found
				else if(Pin_Ln != Ac_No && Fd != true){
					continue;
				}
				
				//	Continue if target account is found but not the account PIN
				if(Fd == true && Iter != 3){
					Iter += 1;
					continue;
				}
				
				// Add the new deposits to your current balance
				else if(Fd == true && Iter == 3){
					
					Account_PIN = stoi(Pin_Ln);
					break;
				}
			}
			if(Fd != true){
				system("cls");
				cout << "\t\t\tSorry, we could not access the account with such credentials!\n"
				"\t\t\tPlease confirm your Account number and PIN, then try again.\n\n\n";
				Wrong_Credentials = true;
				Return();
			}
			
		}else{
			cout << "\t\t\tSorry, we could not access the database at a moment!\n"
			"\t\t\tPlease contact the service support team for help!\n";	
		}
		
		Acct.close();// Close file
		
		// Taking Action basing on the user provied PIN
		if(PIN == Account_PIN){
		
		cout << endl;
		// Search for account info in the database and display them to the screen
		bool Print = false;
		string line;
		int iter = 0;
		Acct.open("Accounts.txt", ios::in);
		if(Acct.is_open()){
			while(getline(Acct, line)){
				
				if(line == Ac_No){
					Print = true;
				}
				else if(line != Ac_No && Print != true){
					continue;
				}
				
				if(line == Ac_No && Print == true){
					cout << "\t\t\tAccount Number: " << line << endl;
					iter+=1;
				}
				else if(line != Ac_No && iter <= 2){
					if(iter == 1){
						cout << "\t\t\tAccount Name: " << line << endl;
					}
					else if(iter == 2){
						cout << "\t\t\tAccount balance: " << line << endl;
					}
					iter+=1;
				}
				else{
					continue;
				}
			}
			
			// Account is not found in the database
			if(Print != true){
				cout << "\t\t\tAccount not found!\n"
				"\t\t\tPlease check your account number and try again!" << endl;
			}
		}
		
		// Filed to access the database
		else{
			cout << "\t\t\tSorry, we could not access the database at a moment!\n"
			"\t\t\tPlease contact the service support team for help!\n";
		}
		Acct.close();
		
		// PIN provieded by the User isn't correct
		}else if(Wrong_Credentials != true){
			if(ITER != 2){
			cout << "\t\t\tIncorrect PIN! Please re-enter PIN!" << endl;
			}
			ITER += 1;
			goto Re_PIN;
		}
		
		if(Wrong_Credentials != true){
			Return();
		}
	}
	
	void Deposit(){
		system("cls");
		Start:
		string Ac_No;
		int Dep_Amount;
		// Session Title
		cout << "\n"
		"\t\t\t===========================\n"
		"\t\t\t\t MAKING A DEPOSIT\n"
		"\t\t\t===========================\n\n"
		"\t\t\tEnter Account Number: "; // Fetch User Account Number
		cin >> Ac_No;
		
		// Error handling for Account Number
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
			cout << "\t\t\tInvalid Account Number...!" << endl;
			goto Start;
		}
		
		// Fetch User amount to Deposit
		cout << "\t\t\tEnter Amount: UGX.";
		cin >> Dep_Amount;
		
		// Error handling for Amount to deposit
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
			cout << "\t\t\tInvalid Account Number...!" << endl;
			goto Start;
		}
		
		// Search for account info in the database. Open the existing File "Accounts.txt" in the "ios::in" mode
		// to read all the accounts and search for the target account using its account number. Open a new temporary
		// File "Temp.txt" in the "ios::app" to hold the new changes made to the accounts.
		string line, Account_Holder;
		bool Found = false;
		bool Action_Successful = false;
		int iter = 0;
		Acct.open("Accounts.txt", ios::in);
		Temp.open("Temp.txt", ios::app);
		if(Acct.is_open()){
			Action_Successful = true;
			if(Temp.is_open()){
				while(getline(Acct, line)){
				
				// Touggle Found to true when the target account is found.
				if(line == Ac_No){
					Found = true;
				}
				
				// Save other accounts Hosted by the bank. This only works to the accounts
				//	that come first before the target account or before (bool) Foound is set to "true".
				else if(line != Ac_No && Found != true){
					Temp << line << endl;
				}
				
				// Save the host account data. Leaving it unchanged and saving all the other accounts
				//	that come after the target account if there is any.
				if(Found == true && iter != 2){
					if(iter == 1){
						Account_Holder = line;
					}
					Temp << line << endl;
					iter += 1;
				}
				
				// Add the new deposits to your current balance
				else if(Found == true && iter == 2){
					
					int DA = stoi(line);
					Temp << DA + Dep_Amount<< endl;
					iter += 1;
					cout << "\n\t\t\tDeposit transaction of " << Dep_Amount
					<< " to " << Account_Holder << "'s account is successful!\n"
					"\t\t\tThank you for using our banking services.\n";
				}
			}
		}
		
		// Define the action when the File "Temp.txt" failed to be created.
		else{
			cout << "\t\t\tFailed to create a temporary file\n"
			"\t\t\tPlease contact the support team for assistance!" << endl;			
		}
		}
		
		// Define the action if the File "Accounts.txt" failed to be accessed.
		else{
			cout << "\t\t\tFailed to access the database\n"
			"\t\t\tPlease contact the support team for assistance!" << endl;
		}
		Acct.close();
		Temp.close();
		// Replace the "Accounts.txt" with "Temp.txt".
		if(Action_Successful != false){
		remove("Accounts.txt");
		rename("Temp.txt", "Accounts.txt");
	}
		// Return statement
		Return();
	}

	void Withdraw(){
		system("cls");
		Start:
		string Ac_No;
		int Withdraw_Amount;
		int ITER;
		int PIN = 0;
		bool Wrong_Credentials = false;
		// Session Title
		cout << "\n"
		"\t\t\t===========================\n"
		"\t\t\tWITHDRAWING FROM ACCOUNT\n"
		"\t\t\t===========================\n\n"
		"\t\t\tEnter Account Number: "; // Fetch User Account Number
		cin >> Ac_No;
		
		// Error handling for Account Number
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
			cout << "\t\t\tInvalid Account Number...!" << endl;
			goto Start;
		}
		
		// Fetch User amount to Withdraw
		cout << "\t\t\tEnter Amount: UGX.";
		cin >> Withdraw_Amount;

		// Error handling for withdraw amount
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
			cout << "\t\t\tInvalid Account Number...!" << endl;
			goto Start;
		}

		Re_PIN:
		
		// Check for the wrong PIN prompts
		if(ITER == 3){
			cout << "\n\n\t\t\tThis transaction couldn't be completed because of too many\n"
			"\t\t\twrong PIN attempts!\n"
			"\t\t\tPlease retry again later after recovering your password...!" << endl;
			exit(0);
		}
		
		// Getting User PIN
		cout << "\t\t\tConfirm PIN: ";
		cin >> PIN;
		
		// cin failure for PIN
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			system("cls");
			cout << "\t\t\tInvalid input..!!" << endl;
			goto Start;
		}
		// Checking the Account PIN in the database
		string Pin_Ln;
		bool Fd = false;
		int Account_PIN = 0;
		int Iter = 0;
		ifstream Acct("Accounts.txt");
		if(Acct.is_open()){
			while(getline(Acct, Pin_Ln)){
				// Touggle Fd to true when the target account is found.
				if(Pin_Ln == Ac_No){
					Fd = true;
				}
				
				//	Continue if target account is not found
				else if(Pin_Ln != Ac_No && Fd != true){
					continue;
				}
				
				//	Continue if target account is found but not the account PIN
				if(Fd == true && Iter != 3){
					Iter += 1;
					continue;
				}
				
				// Add the new deposits to your current balance
				else if(Fd == true && Iter == 3){
					
					Account_PIN = stoi(Pin_Ln);
					break;
				}
			}
			if(Fd != true){
				system("cls");
				cout << "\t\t\tSorry, we could not access the account with such credentials!\n"
				"\t\t\tPlease confirm your Account number and PIN, then try again.\n\n\n";
				Wrong_Credentials = true;
				Return();	
			}
			
		}else{
			cout << "\t\t\tSorry, we could not access the database at a moment!\n"
			"\t\t\tPlease contact the service support team for help!\n";	
		}
		
		Acct.close();// Close file				
		
		// Take Action basing on wheather PIN is correct or not
		if(Account_PIN == PIN){
			
		// Search for account info in the database. Open the existing File "Accounts.txt" in the "ios::in" mode
		// to read all the accounts and search for the target account using its account number. Open a new temporary
		// File "Temp.txt" in the "ios::app" to hold the new changes made to the accounts.
		string line, Account_Holder;
		bool Found = false;
		bool Action_Successful = false;
		int iter = 0;
		Acct.open("Accounts.txt", ios::in);
		Temp.open("Temp.txt", ios::app);
		if(Acct.is_open()){
			Action_Successful = true;
			if(Temp.is_open()){
				while(getline(Acct, line)){
				
				// Touggle Found to true when the target account is found.
				if(line == Ac_No){
					Found = true;
				}
				
				// Save other accounts Hosted by the bank. This only works to the accounts
				//	that come first before the target account or before (bool) Found is set to "true".
				else if(line != Ac_No && Found != true){
					Temp << line << endl;
				}
				
				// Save the host account data. Leaving it unchanged and saving all the other accounts
				//	that come after the target account if there is any.
				if(Found == true && iter != 2){
					if(iter == 1){
						Account_Holder = line;
					}
					Temp << line << endl;
					iter += 1;
				}
				
				// Deduct the withdraw amounts from your current balance
				else if(Found == true && iter == 2){
					
					int Av_Amount = stoi(line);
					Temp << Av_Amount - Withdraw_Amount<< endl;
					iter += 1;
				}
			}
		}
		
		// Define the action when the File "Temp.txt" failed to be created.
		else{
			cout << "\t\t\tFailed to create a temporary file\n"
			"\t\t\tPlease contact the support team for assistance!" << endl;			
		}
		}
		
		// Define the action if the File "Accounts.txt" failed to be accessed.
		else{
			cout << "\t\t\tFailed to access the database\n"
			"\t\t\tPlease contact the support team for assistance!" << endl;
		}
		Acct.close();
		Temp.close();
		// Replace the "Accounts.txt" with "Temp.txt".
		if(Action_Successful != false){
		remove("Accounts.txt");
		rename("Temp.txt", "Accounts.txt");
	
		cout << "\n\t\t\tWithdraw transaction of " << Withdraw_Amount
		<< " from " << Account_Holder << "'s account successful!\n"
		"\t\t\tThank you for using our banking services.\n";
		
		}
		
		// Incorrect PIN form the user
		}else if(Wrong_Credentials != true){
			if(ITER != 2){
			cout << "\t\t\tIncorrect PIN! Re-enter PIN!" << endl;
			}
			ITER +=1;
			goto Re_PIN;
		}
		
		// Return statement
		if(Wrong_Credentials != true){
		Return();
		}
	}
	
};


int main(){
	Account A1;
	A1.Main_Menu();	
	
	
	return 0;
}