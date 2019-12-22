// Attached: HW_3c
// ===================================================
// Program: HW_3c
// ===================================================
// Programmer: Aaron Geesink
// Class: CS 1B ÅE12 pm class
// ===================================================

#include "Invoice.h";
using namespace std;

void setInvoice(Invoice &inv);
void displayInvoice(Invoice &inv);

int main()
{
	


	Invoice inv_1 = { 0, 0.0, false };
	Invoice inv_2 = { 0, 0.0, false };

	setInvoice(inv_1);
	setInvoice(inv_2);

	system("cls");

	displayInvoice(inv_1);
	displayInvoice(inv_2);

	system("pause");
	return 0;
}

void setInvoice(Invoice &inv)
{
	char answer = '0';

	cout << "Enter the invoice:\n"
		<< "INVOICE #:\t";
	cin >> inv.invoiceNum;

	cout << "AMOUNT:\t";
	cin >> inv.amt;

	cout << "PAID (y/n):\t";
	cin >> answer;
	if (toupper(answer) == 'Y')
		inv.paid = true;
	else
		inv.paid = false;
}

void displayInvoice(Invoice &inv)
{
	cout << "---- Invoice Summary ----\n"
		<< "INVOICE #:\t" << inv.invoiceNum << endl
		<< "AMOUNT:\t" << inv.amt << endl
		<< "PAID (y/n):\t";
	if (inv.paid == true)
		cout << "Paid" << endl;
	if (inv.paid == false)
		cout << "Not Paid" << endl;
}

// ===================================================
/* OUTPUT:
Enter the invoice:
INVOICE #:      100
AMOUNT: 3
PAID (y/n):     n
Enter the invoice:
INVOICE #:      101
AMOUNT: 55.98
PAID (y/n):     y

---- Screen Clear ----

---- Invoice Summary ----
INVOICE #:      100
AMOUNT: 3
PAID (y/n):     Not Paid
---- Invoice Summary ----
INVOICE #:      101
AMOUNT: 55.98
PAID (y/n):     Paid
Press any key to continue . . .
*/
// ===================================================


