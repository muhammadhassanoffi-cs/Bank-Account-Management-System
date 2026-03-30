//#define _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<string>
//#include<fstream>
//using namespace std;
//enum account_type{
//	Current=1, Saving 
//};
//class Bank_account {
//	char name[50]; // safe size
//	char account_number[50];
//	const account_type Type; 
//	double amount;
//	char bank_name[50];
//	char branch_code[50];
//	char city[50];
//	static unsigned int count;
//public:
//
//	Bank_account() :Type (Current) // default constructer 
//	{
//		strcpy(name, "");
//		strcpy(account_number, "");
//		amount = 0.0;
//		strcpy(bank_name, "");
//		strcpy(branch_code, "");
//		strcpy(city, "");
//		count++;
//	
//	}
//	
//	Bank_account(char name[], char account_number[], const account_type t, double amount, char bank_name[], char branch_code[], char city[]) :Type(t) // parametrized constructer 
//	{
//		strcpy(this->name, name);
//		strcpy(this->account_number, account_number);
//		this->amount = amount;
//		strcpy(this->bank_name, bank_name);
//		strcpy(this->branch_code, branch_code);
//		strcpy(this->city, city);
//		count++;
//	}
//	static void getAccCounts() // static funcion
//	{
//		cout << " =============================" << endl;
//		cout << " Number of accounts are :" << count << endl;
//		
//	}
//	void depositamount(double d)// deposit function
//	{
//		if (d > 0)
//		{
//			amount += d;
//		}
//		else
//		{
//			cout << " Invalid amount " << endl;
//		}
//		cout << "================================" << endl;
//		cout << " Amount deposited successfully " << endl;
//		cout << "================================" << endl;
//	}
//	void withdraw(double w) // withdraw function
//	{
//		if (w <= amount)
//		{
//			amount -= w;
//		}
//		else
//		{
//			cout << " Insuficent balance " << endl;
//		}
//		cout << "======================" << endl;
//		cout << " Withdraw successfuly " << endl;
//		cout << "======================" << endl;
//	}
//	void display()
//	{
//		cout << "===============================" << endl;
//		cout << " Depositers name :" << name << endl;
//		cout << " Bank  :" << bank_name << endl;
//		cout << " City : " << city << endl;
//		cout << " Balance :" << amount << endl;
//		cout << " Type :";
//		if (Type == Current)
//		{
//			cout << " Current " << endl;
//		}
//		else
//		{
//			cout << " Saving " << endl;
//		}
//	}
//	void filewriting(ofstream& fout) // function to write data in file 
//	{
//
//		fout << name << endl;
//		fout << account_number << endl;
//		fout << Type << endl;
//		fout << amount << endl;
//		fout << bank_name << endl;
//		fout << branch_code << endl;
//		fout << city << endl;
//		fout << "============================" << endl;
//	}
//	~Bank_account()
//	{
//		count--;
//	}
//	
//};
//unsigned int Bank_account :: count = 0;
//int main()
//{
//	char name[50];
//	char accnum[50];
//	double am;
//	char bankname[50];
//	char branchcode[50];
//	char city[50];
//	int type;
//
//	int choice = 0;
//	const int Size = 100;
//	Bank_account* account[Size] = { nullptr };
//	ifstream fin("accounts.txt");
//	// reading data from file 
//	for (int i = 0; i < Size; i++)
//	{
//		fin.getline(name, 50);
//		if (fin.fail())
//		{
//			break;
//		}
//		fin.getline(accnum, 50);
//		fin >> type;
//		fin >> am;
//
//		fin.ignore();
//		fin.getline(bankname, 50);
//		fin.getline(branchcode, 50);
//		fin.getline(city, 50);
//		fin.ignore(1000, '\n');
//		account[i] = new Bank_account(name, accnum, (type == 1 ? Current : Saving), am, bankname, branchcode, city);
//	}
//
//	while (choice!=7)
//	{
//		cout << "================================" << endl;
//		cout << "1 Create Account" << endl;
//		cout << "2 Display All Accounts" << endl;
//		cout << "3 Deposit" << endl;
//		cout << "4 Withdraw" << endl;
//		cout << "5 Delete Account" << endl;
//		cout << "6 Show Count" << endl;
//		cout << "7 Exit" << endl;
//		cout << "Enter choice: ";
//		cin >> choice;
//		if (choice == 1)
//		{
//			int index = -1;
//			for (int i = 0; i < Size; i++)
//			{
//				if (account[i] == nullptr)
//				{
//					index = i;
//					break;
//				}
//
//			}
//			cin.ignore(); 
//			cout << " Enter your name :";
//			cin.getline(name, 50);
//			cout << " Enter account number :";
//			cin.getline(accnum, 50);
//			cout << " Enter amount :";
//			cin >> am;
//			cin.ignore();
//			cout << " Enter bank name :";
//			cin.getline(bankname, 50);
//			cout << " Enter branch code :";
//			cin.getline(branchcode, 50);
//			cout << " Enter you city :";
//			cin.getline(city, 50);
//			cout << " Account type ( 1. current / 2 .Saving ) :";
//			cin >> type;
//			account[index] = new Bank_account(name, accnum, (type == 1 ? Current : Saving), am, bankname, branchcode, city);
//			cout << "=======================" << endl;
//			cout << " Account Created " << endl;
//			cout << "=======================" << endl;
//		}
//		else if (choice == 2)
//		{
//			for (int i = 0; i < Size; i++)
//			{
//				if (account[i] != nullptr)
//				{
//					account[i]->display();
//				}
//			}
//		}
//		else if (choice == 3)
//		{
//			int t;
//			cout << " Enter index who want to deposit amount  :";
//			cin >> t;
//			double amount;
//			if (t >= 0 && t < Size && account[t] != nullptr)
//			{
//				cout << " Enter amount :";
//				cin >> amount;
//				account[t]->depositamount(amount);
//			}
//		}
//		else if (choice == 4)
//		{
//			int t;
//			cout << " Enter index who want to withdraw   :";
//			cin >> t;
//			double amount;
//			if (t >= 0 && t < Size && account[t] != nullptr)
//			{
//				cout << " Enter amount :";
//				cin >> amount;
//				account[t]->withdraw(amount);
//			}
//		}
//		else if (choice == 5)
//		{
//			int inde;
//			cout << " Enter index whos account you want to delete :";
//			cin >> inde;
//			if (account[inde] != nullptr)
//			{
//				delete account[inde];
//
//				for (int i = inde; i < Size - 1; i++)
//				{
//					account[i] = account[i + 1];
//				}
//				
//				account[Size - 1] = nullptr;
//				cout << "=======================" << endl;
//				cout << " Deleted Successfullty " << endl;
//				cout << "=======================" << endl;
//			}
//		}
//		else if (choice == 6)
//		{
//		    Bank_account::getAccCounts();
//		}
//	
//	}
//		cout << "==============================" << endl;
//		cout << "Thanks " << endl;
//		cout << "==============================" << endl;
//		ofstream fout("accounts.txt");
//		if (!fout)
//		{
//			cout << " File not Found " << endl;
//		}
//		for (int i = 0; i < Size; i++) // caling function to save dyta of every index in file 
//		{
//			if (account[i] != nullptr)
//			{
//				account[i]->filewriting(fout);
//			}
//		}
//		fout.close();
//
//		for (int i = 0; i < Size; i++) // deleting memory 
//		{
//			delete account[i];
//		}
//
//
//	system("pause");
//	return 0;
//}
