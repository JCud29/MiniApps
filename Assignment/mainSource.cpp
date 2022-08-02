#include <iostream>//includes the additional libraries
#include <time.h>
#include <vector>
#include <cmath>

using namespace std;

void menu();// function prototyping
void keepCounting();
void numberConversion();
void decimalConversion();
void binaryConversion();
void hexConversion();
void displayBinary(const vector<int> binaryDigits);
void displayHex(vector<int> hexDigits);
void displayDecimal(const int decimalNumber);
void upcCalcultor();
void upcGen(int upc[], const int sixDigitUPC);
void displayUPC(const int upc[], const int upcSize);
void upcChecker();

int main()//entry to the application
{
	cout << "FoP4CS Mini Applications\n--------------------------------";//displays the title of the application
	menu();
	system("pause");
	return 0;//exits the program
}

void menu()
{
	//creates the variables required for the menu
	int menuOption;
	bool validInput(false);

	//do while loop used to loop the menu until the user enters a correct option
	/*to test this I entered a range of correct and incorrect option
	when I entered a correct option the loop stopped and call the correct function
	when an incorrect option was entered the menu continued to loop*/
	do
	{
		//displays the menu options
		cout << "\n\nPlease select an option:\n";
		cout << "1) Keep counting game\n2) Number conversion tool\n3) Universal product code (UPC) calculator\n4) Universal product code (UPC) Checker\n9) Quit\n";
		cout << "Please enter your option from the menu above:";
		cin >> menuOption;//stores the option that the user entered in the menuOption variable

		//cout << menuOption; TEST CODE

		//used a switch function to identify which option the user has entered
		//this has been test by entering a range of correct and incorrect options
		//if the option entered is in the switch it will call that function, if not the user will be told it is not a valid option and is asked to retry
		switch (menuOption)
		{
		case 1://if 1 is entered the loop will end and call the keep counting fucntion
		{
			validInput = true;
			keepCounting();
			break;
		}
		case 2://if 2 is entered the loop will end and call the number conversion fucntion
		{
			validInput = true;
			numberConversion();
			break;
		}
		case 3://if 3 is entered the loop will end and call the UPC calculator fucntion
		{
			validInput = true;
			upcCalcultor();
			break;
		}
		case 4://if 4 is entered the loop will end and call the UPC checker fucntion
		{
			validInput = true;
			upcChecker();
			break;
		}
		case 9://when 9 is entered the loop will stop and the program will exit
		{
			validInput = true;
			break;
		}
		default://if another number is entered which is not an option it will tell the user it is invalid and ask them to try agian
		{
			cout << "\nThat was an invalid input, please try again\n\n";
		}
		}
	} while (validInput != true);//while loop will loop until user has entered a vaild input

}

// -----------------------------------------------------------------keep Counting-------------------------------------------------------------------------------------

void keepCounting()
{
	bool complete(false);
	string enterPressed;
	int totalseconds(0), num1, num2, numberOfQuestions(8), answer, sumNumbers, score(0);
	
	cout << "\n\nKeep Counting\n";
	cout << "-----------------------\n\n";

	cout << "You will be presented with 8 arithmetic questions.\nAfter the first question, the left-hand operand is the result of the prevoius addition.\n";
	//pauses the application so the user as to press any key to start the timmer
	system("pause");
	time_t startTime = time(0);//stores the time when the user starts to answer the questions
	   
	srand((int)time(NULL));//set the start value for generating random numbers
	num1 = rand() % 10;// generates a random number between 0 and 9
	num1 = num1 + 1; // therefore the number range is between 1 and 10

	/*for (int i = 0; i < 20; i++)
		{
			num1 = rand() % 10;
			num1 = num1 + 1;
			cout << num1 << "\n";
		}TEST CODE*/

	int questionNum(0);
	//do while loop displays the question until the max amount of question have been displayed or the user answers a question wrong
	do
	{
		//generates a random number and adds 1 to the number so it is not equal to 0
		num2 = rand() % 10;
		num2 = num2 + 1;

		//if it is not the first question the first number will be the answer to the previous question
		if (questionNum > 0)
			num1 = sumNumbers;

		//generates a random number which is either 0 or 1 to represent a sign operator
		int sign = rand() % 2;
		
		/*for (int i = 0; i < 20; i++)
		{
			int sign = rand() % 2;
			cout << sign;
		}TEST CODE*/

		//if the random number is 0 the question will be a addition question
		if (sign == 0)
		{
			//displays the question and stores the answer
			cout << "\nquestion " << (questionNum + 1) << ": What is " << num1 << "+" << num2 << "?";
			cin >> answer;
			sumNumbers = num1 + num2;
			//if the answer the user has entered is incorrect the user will be notified and shown the correct answer
			//the loop ends if the answer is incorrect

			if (answer != sumNumbers)
			{
				cout << "Wrong - the answer is " << sumNumbers;
				complete = true;
			}
			else//if the answer is correct a point is added to the score and the loop continues
				score++;
		}
		else//if the sign is 1 the question is subtraction
		{
			//displays the question
			cout << "\nquestion " << (questionNum + 1) << ": What is " << num1 << "-" << num2 << "?";
			cin >> answer;
			sumNumbers = num1 - num2;
			//checks the user's answer, and tells them if it is incorrect
			if (answer != sumNumbers)
			{
				cout << "Wrong - the answer is " << sumNumbers;
				complete = true;
			}
			else
				score++;
		}
		questionNum++;
	} while (complete != true && questionNum != numberOfQuestions);
	//loops unitl the user answers a question incorrect or the max number of question have been displayed

	if (score == numberOfQuestions)//if the user answers all the question correct the time taken is displayed
	{
		time_t endTime = time(0);//store when the user finished answering the questions and taken the start time away to get the time taken 
		time_t timeTaken = endTime - startTime;

		cout << "Questions completed in: " << timeTaken << " seconds\n";
	}
	else//if the user fails to answer all of the questions a message will be displayed
	{
		cout << "\nBetter luck next time\n";
	}
	menu();//returns to the menu
}

// -----------------------------------------------------------------numberConversion-------------------------------------------------------------------------------------

void numberConversion()
{
	bool validInput(false);
	int menuOption;
	cout << "\n\nNumber Conversion Tool\n";
	cout << "----------------------------------\n\n";

	//the do while loop will loop the menu until the user enters a vaild option
	//tested with a range of incorrect and correct option, when a incorrect option was entered the menu continued to loop
	do
	{
		//displays the menu option and read the option the user entered
		cout << "Please select the number base you wish to input:";
		cout << "\n1) decimal\n2) Binary\n3) Hexadecimal\n";
		cout << "Please enter your option from the menu above:";
		cin >> menuOption;

		switch (menuOption)
		{
		case 1:
		{
			validInput = true;
			decimalConversion();
			break;
		}
		case 2:
		{
			validInput = true;
			binaryConversion();
			break;
		}
		case 3:
		{
			validInput = true;
			hexConversion();
			break;
		}
		default://display if the user enters a invalid input
		{
			cout << "\nThat was an invalid input, please try again\n\n";
		}
		}
	} while (validInput != true);
}

//to test the decimal conversion I entered a range of decimal numbers kowning the correct output that should of been returned, all of the output that were returned were correct
void decimalConversion()
{
	//defines the variables and vectors
	int decimalNumber, binaryDigit, hexDigit;
	vector<int> binaryDigits;
	vector<int> hexDigits;

	//asks the user to enter a decimal number to convert
	cout << "Please enter a positive decimal number: ";
	cin >> decimalNumber;

	//copies the number enter into other variables for working out
	int hexDecimalNumber = decimalNumber;
	int binaryDecimalNumber = decimalNumber;
	//coverts the decimal number into binary and stores the result into the binary vector
	//works out the binary digits by dividing by 2 and finding remainder
	while (binaryDecimalNumber != 0)
	{
		binaryDigit = binaryDecimalNumber % 2;
		binaryDecimalNumber = binaryDecimalNumber / 2;
		binaryDigits.push_back(binaryDigit);
	}
	//coverts the decimal number to hex and stores the result in the hex vector
	//works out the hex by dividing by 16 and finding remainder
	while (hexDecimalNumber != 0)
	{
		hexDigit = hexDecimalNumber % 16;
		hexDecimalNumber = hexDecimalNumber / 16;
		hexDigits.push_back(hexDigit);
	}
	//displays the results and then returns to the menu
	displayBinary(binaryDigits);
	displayHex(hexDigits);
	menu();
}

//to test the binary conversion I enter a range of binary number that I knew the outputs of, to check that my application converts the binary numbers correctly
void binaryConversion()
{
	//defines the variables and vectors
	int binaryNumber, binarySize(0), decimalNumber(0), digit, hexDigit;
	vector<int> binaryDigits;
	vector<int> hexDigits;
	//asks the user to enter a binary number to convert
	cout << "Please enter a binary number: ";
	cin >> binaryNumber;

	//copyies the binary number to check the size of the number entered
	//the size of the number is calculated by divide by 10 until the number equals 0
	int checkBinaryNumber = binaryNumber;
	while (checkBinaryNumber != 0)
	{
		checkBinaryNumber = checkBinaryNumber / 10;
		binarySize++;
	}
	//seperates the binary digits and stores them in the binary vector
	for (int i = 0; i < binarySize; i++)
	{
		digit = binaryNumber % 10;
		binaryNumber = binaryNumber / 10;
		binaryDigits.push_back(digit);
		//cout << digit; TEST CODE
	}
	//cout << binarySize; TEST CODE

	//converts the binary digits to a decimal by working out 2 to the power of the index number of the binary digits
	for (int i = binarySize - 1; i >= 0; i--)
	{
		digit= binaryDigits.at(i);
		//cout << digit; TEST CODE
		if (digit == 1)
		{
			decimalNumber = decimalNumber + pow(2, i);
		}
	}
	//copies the decimalNumber calculated and works out the Hex of the number by finding the remainder when dividing by 16
	int hexDecimalNumber = decimalNumber;
	while (hexDecimalNumber != 0)
	{
		hexDigit = hexDecimalNumber % 16;
		hexDecimalNumber = hexDecimalNumber / 16;
		hexDigits.push_back(hexDigit);
	}
	//calls the function which displays the results and returns to the menu
	displayDecimal(decimalNumber);
	displayHex(hexDigits);
	menu();
}

//to test the hex conversion I enter a Variety of which i knew what the outputs should be to check if my method correctly converts a hex number to decimal and binary
void hexConversion()
{
	string hexInput;
	vector<char>hexDigits;
	vector<int>binaryDigits;
	char hexDigit, hexChar;
	int hexNumber(0), hexLength, decimalNumber(0), binaryDecimalNumber, binaryDigit;

	//asks the user to enter a hexadecimal number to convert
	cout << "Please enter a hexadecimal number: ";
	cin >> hexInput;
	hexLength = hexInput.length();//get the lenght of the user input

	//splits the input into seperate characters and store in the hexDigits vector
	for (int i = hexLength-1; i >=0; i--)
	{
		hexDigit = hexInput[i];
		hexDigits.push_back(hexDigit);
	}

	//converts all of the character to a corresponding int value
	for (int i = hexLength - 1; i >=0; i--)
	{
		hexChar = hexDigits.at(i);
		hexNumber = ((int)hexChar - 48);//subtract 48 the values start at 0, because of the ASCII table
		if (hexNumber < 10);
		{
			if (hexChar == 'a' || hexChar == 'A')
			{
				hexNumber = 10;
			}
			else if (hexChar == 'b' || hexChar == 'B')
			{
				hexNumber = 11;
			}
			else if (hexChar == 'c' || hexChar == 'C')
			{
				hexNumber = 12;
			}
			else if (hexChar == 'd' || hexChar == 'D')
			{
				hexNumber = 13;
			}
			else if (hexChar == 'e' || hexChar == 'E')
			{
				hexNumber = 14;
			}
			else if (hexChar == 'f' || hexChar == 'F')
			{
				hexNumber = 15;
			}
		}
		//calculates the decimal conversion of the hex number
		decimalNumber = decimalNumber + (hexNumber * pow(16, i));
	}

	//copies the decimal value and generates the binary number for the hex entered by the user
	binaryDecimalNumber = decimalNumber;
	while (binaryDecimalNumber != 0)
	{
		binaryDigit = binaryDecimalNumber % 2;
		binaryDecimalNumber = binaryDecimalNumber / 2;
		binaryDigits.push_back(binaryDigit);
	}
	//displays the results and then returns to the user
	displayDecimal(decimalNumber);
	displayBinary(binaryDigits);
	menu();
}

void displayBinary(const vector<int> binaryDigits)
{
	//get the size of the vector to display the correct amount of digits
	const int binarySize = binaryDigits.size();
	//cout << binarySize; Test Code
	cout << "\nBinary: ";
	for (int i = binarySize - 1; i >= 0; i--)
	{
		cout << binaryDigits.at(i);
	}
}

void displayHex(vector<int> hexDigits)
{
	//generates the size of the vector to display the correct amount of digits
	const int hexSize = hexDigits.size();
	int hexDigit;
	char hexChar('A');
	//cout << hexSize; TEST CODE
	//displays the hexadecimal result
	cout << "\nHexadecimal: ";
	for (int i = hexSize - 1; i >= 0; i--)
	{
		//convert the number into the characters in the hex range
		hexDigit = hexDigits.at(i);
		if (hexDigit > 9)
		{
			if (hexDigit == 10)
				hexChar = 'A';
			else if (hexDigit == 11)
				hexChar = 'B';
			else if (hexDigit == 12)
				hexChar = 'C';
			else if (hexDigit == 13)
				hexChar = 'D';
			else if (hexDigit == 14)
				hexChar = 'E';
			else if (hexDigit == 15)
				hexChar = 'F';
			cout << hexChar;
		}
		else
		{
			cout << hexDigit;
		}
	}
}

void displayDecimal(const int decimalNumber)
{
	//displays the decimal number
	cout << "Decimal number: " << decimalNumber;
}

// -------------------------------------------------------------------UPC--------------------------------------------------------------------------------------------
void upcCalcultor()
{
	int sixDigitUPC, sixDigitCheck;
	const int upcSize(7);
	int upc[upcSize];
	cout << "\n\nUniversal Product Code (UPC) calculator\n";
	cout << "---------------------------------------------\n";

	cout << "\nThis calculator will take a 6-digit product code\nand generate a trailing 7th check digit to product the\nfinal 7-digit UPC.\n\n";
	//the do while loop loops until the user enters a 6 digit code
	do
	{
		//ask the user to enter a 6 digit code to calculate the UPC
		cout << "Please enter a 6-digit code to generate a final UPC code: ";
		cin >> sixDigitUPC;
		//check that the code entered is not more than 6 digits long, if it is a message will be displayed to the user
		sixDigitCheck = sixDigitUPC / 1000000;
		if (sixDigitCheck != 0)
			cout << "That was an Invaild code, please try again\n\n";
	} while (sixDigitCheck != 0);

	upcGen(upc, sixDigitUPC);//calls the function to generate the UPC code
	//displays the 7 digit UPC and then returns to the main menu
	cout << "The final 7-Digit UPC is: ";
	displayUPC(upc, upcSize);
	menu();
}

//to test that the UPC generated is correct I enter a number of six digits code of which I calculated the seventh digit, to check the output the the function
void upcGen(int upc[], const int sixDigitUPC)
{
	int oddPositions, evenPositions, addedPositions, remainder, upcDigit;
	//splits the 6 digit code into single digits and stores them in the upc array
	upc[0] = sixDigitUPC / 100000;
	upc[1] = (sixDigitUPC / 10000) - (upc[0] * 10);
	upc[2] = (sixDigitUPC / 1000) - (upc[0] * 100) - (upc[1] * 10);
	upc[3] = (sixDigitUPC / 100) - (upc[0] * 1000) - (upc[1] * 100) - (upc[2] * 10);
	upc[4] = (sixDigitUPC / 10) - (upc[0] * 10000) - (upc[1] * 1000) - (upc[2] * 100) - (upc[3] * 10);
	upc[5] = sixDigitUPC - (upc[0] * 100000) - (upc[1] * 10000) - (upc[2] * 1000) - (upc[3] * 100) - (upc[4] * 10);
	//calculates the seventh digit of the UPC code
	oddPositions = (upc[0] + upc[2] + upc[4]);
	evenPositions = (upc[1] + upc[3] + upc[5]);
	addedPositions = (3 * oddPositions) + evenPositions;
	remainder = addedPositions % 10;
	//cout << remainder << "\n\n"; TEST CODE
	if (remainder == 0)
		upcDigit = remainder;
	else
	{
		upcDigit = 10 - remainder;
	}
	//stores the seventh digit in the array
	upc[6] = upcDigit;
}

void displayUPC(const int upc[], const int upcSize)
{
	//displays all of the digits stored in the upc array
	for (int i = 0; i < upcSize; i++)
		cout << upc[i];
}

//i have tested this by entering a number of correct and incorrect UPCs check if the application notifies the user correctly
void upcChecker()
{
	int upcToCheck, lastDigit, UPC;
	const int upcSize(7);
	int upc[upcSize];
	cout << "\n\nUniversal Product Code (UPC) checker\n";
	cout << "---------------------------------------------\n";
	cout << "This checker will check that the UPC is correct\n\n";

	//asks the user enter a UPC to check
	cout << "Please enter the UPC you wish to check: ";
	cin >> UPC;
	//divides the seven digit UPC to covert it to a digit code to generate the seventh digit to check
	upcToCheck = UPC / 10;
	upcGen(upc, upcToCheck);//call the generate function to calculate the last digit of the UPC

	//calculate the last digit of the 7 digit code the user entered
	lastDigit = UPC % 10;
	//cout << lastDigit; TEST CODE

	//checks if the UPC entered is valid and displays a message to the user to tell them if the UPC entered is valid or not
	if (upc[6] == lastDigit)
	{
		cout << "\nThe UPC entered was correct\n";
	}
	else
	{
		cout << "\nThe UPC entered was incorrect\n";
	}
	menu();//returns to the main menu
}