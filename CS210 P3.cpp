#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>


using namespace std;

void DisplayTable() {	//Display menu with header
	cout << setfill('*') << setw(33) << "*" << endl;
	cout << "Please select a task: \n";
	cout << "1: Display items purchased\n";
	cout << "2: Check specific item\n";
	cout << "3: Display histogram of sales\n";
	cout << "4: Exit Program\n";
};


int UserMenuSelection() {	// user menu selection function with displaying menu options
	int userChoice;
	DisplayTable();
	while (!(cin >> userChoice))	//check for inputting integer
	{
		// Explain error
		cout << "**Error Detected**\n Must enter 1, 2, 3, or 4: ";
		// Clear input stream
		cin.clear();
		// Discard previous input
		cin.ignore(100, '\n');
	}
	while (userChoice != 1 && userChoice != 2 && userChoice != 3 && userChoice != 4) {	//output if incorrect integer is entered
		cin.ignore();
		cout << "Incorrect Entry, Please enter 1, 2, 3, or 4 to make a selection\n";
		while (!(cin >> userChoice))	//check for inputting integer
		{
			// Explain error
			cout << "**Error Detected**\n Must enter 1, 2, 3, or 4: ";
			// Clear input stream
			cin.clear();
			// Discard previous input
			cin.ignore(100, '\n');
		}
	}
	system("cls");	//clear screen for clean console
	return userChoice;	//return user selection to main
};



/*
Description:
	To call this function, simply pass the function name in Python that you wish to call.
Example:
	callProcedure("printsomething");
Output:
	Python will print on the screen: Hello from python!
Return:
	None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("PythonCode");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);
	Py_Finalize();

	delete[] procname;
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("PrintMe","Test");
Output:
	Python will print on the screen:
		You sent me: Test
Return:
	100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());


	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;
	delete[] paramval;


	return _PyLong_AsInt(presult);
}

/*
Description:
	To call this function, pass the name of the Python functino you wish to call and the string parameter you want to send
Example:
	int x = callIntFunc("doublevalue",5);
Return:
	25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"PythonCode");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference 
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference 
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}


void main()
{


	int menuSelection;		//call menu selection function to have user choose option
	int userInt;
	string userString;
	menuSelection = UserMenuSelection();
	while (menuSelection != 4) {	//check for integer entry
		switch (menuSelection) {
		case 1: {
			cout << "Displaying total sales:\n";	//Displaying total sales for items in file
			CallProcedure("printSales");
			cout << endl;
			break;
		};
		case 2: {
			cout << "Please enter a the item you'd like to check on:\n";	//user entry for item to check
			cin >> userString;
			callIntFunc("checkSingleItem", userString);	//call checkSingleItem python function with string parameter
			cout << endl;
			break;
		};
		case 3: {
			cout << "Displaying Histogram\n";	// menu option 3, displaying histogram
			string tempString;
			int tempInt;
			CallProcedure("createDatFile");
			ifstream fileIn("frequency.dat");
			while (!fileIn.eof()) {
				fileIn >> tempString;
				fileIn >> tempInt;
				cout << tempString + " ";
				for (int i = 0; i < tempInt; i++) {
					cout << "*";
				}
				cout << endl;
			}
			cout << endl;
			break;
		};
		}
		menuSelection = UserMenuSelection();	//call menu function again for loop
		system("cls");
	}
	CallProcedure("printsomething");

}