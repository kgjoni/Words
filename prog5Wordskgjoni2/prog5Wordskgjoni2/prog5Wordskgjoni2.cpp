/* -------------------------------------------------------------------------------------------------------------------------
* prog5Wordskgjoni2.c
*
* Class: Program #5 for CS 141, Spring 2017.  Tues 11am lab.
* System: Windows 7
* Author: Kristi Gjoni
*
. . .
* --------------------------------------------------------------------------------------------------------------------------
*/


#include <stdio.h>
#include <ctype.h>     
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <iostream>
using namespace std;


//--------------------------------------------------------------------------------------------------------------------------
// Display ID info
void displayIdInfo()
{
	printf("\n");
	printf("Author: Kristi Gjoni               \n");
	printf("Program #5: Across Words           \n");
	printf("TA: Moumita Samanta, Tuesday 11 AM \n");
	printf("April 15, 2017                     \n");
	printf("\n");
}// end displayIDInfo()


//--------------------------------------------------------------------------------------------------------------------------
// Display game instructionos
void displayInstructions() 
{
	printf("Welcome to AcrossWord puzzle, where you rotate rows or columns		\n"); 
	printf("to restore the board back to containing four words.Each move is		\n");
	printf("a row or column letter followed by the rotation distance 1, 2 or 3. \n");
	printf("When prompted to provide input you may enter:			\n");
	printf("	Enter 'r' to reset the board to user-defined values.\n");
	printf("	Enter 'u' to unveil the underlying words.			\n");
	printf("	Enter 's' to auto solve the board (Extra Credit)	\n");
	printf("	Enter 'x' to exit the program.						\n");
}// end displayInstructions()


//--------------------------------------------------------------------------------------------------------------------------
// Count number of words in dictionaries 
int countNumberOfWords(int userChoice) 
{
	FILE *pInputFile;
	int countWords = 0;
	char currentWord[81];

	// user inputs 1
	if (userChoice == 1)
	{
		pInputFile = fopen("smallDictionary.txt", "r");
		if (pInputFile == NULL)
		{
			printf("File not found.  Exiting...\n\n");		// check for errors
			exit(0);	// exit if cannot open the file
		}

		// Read in the words
		
		while (fscanf(pInputFile, "%s", currentWord) != EOF)
		{
			countWords++;	// increment the count of words
		}

		printf("There are %d 4-letter words. \n", countWords);	// display how many words are found

		// Close the file
		fclose(pInputFile);

	}

	// user inputs 2
	else if (userChoice == 2)
	{
		pInputFile = fopen("mediumDictionary.txt", "r");
		if (pInputFile == NULL)
		{
			printf("File not found.  Exiting...\n\n");		// check for errors
			exit(0);	// exit if cannot open the file
		}

		while (fscanf(pInputFile, "%s", currentWord) != EOF)
		{
			countWords++;	// increment the count of words
		}

		printf("There are %d 4-letter words. \n", countWords);	// display how many words are found

		// Close the file
		fclose(pInputFile);
	}

	// user inputs 3
	else if (userChoice == 3)
	{
		pInputFile = fopen("largeDictionary.txt", "r");
		if (pInputFile == NULL)
		{
			printf("File not found.  Exiting...\n\n");		// check for errors
			exit(0);	// exit if cannot open the file
		}

		while (fscanf(pInputFile, "%s", currentWord) != EOF)
		{
			countWords++;	// increment the count of words
		}

		printf("There are %d 4-letter words. \n", countWords);	// display how many words are found

		// Close the file
		fclose(pInputFile);
	}

	return countWords;
	
}// end countNumberOfWords


//--------------------------------------------------------------------------------------------------------------------------
// Display the board 
void displayBoard(char *board, char **dictionaryWords, int numberOfWords)
{
	int randomNumber;
	srand((int)time);

	// store first word from dictionary to game board
	randomNumber = rand() % numberOfWords;
	for (int j = 0; j < 4; j++)
	{
		board[j] = dictionaryWords[randomNumber][j];
	}

	// store second word from dictionary to game board
	randomNumber = rand() % numberOfWords;
	for (int j = 0; j < 4; j++)
	{
		board[j + 4] = dictionaryWords[randomNumber][j];
	}

	// store third word from dictionary to game board
	randomNumber = rand() % numberOfWords;
	for (int j = 0; j < 4; j++)
	{
		board[j + 8] = dictionaryWords[randomNumber][j];
	}

	// store fourth word from dictionary to game board
	randomNumber = rand() % numberOfWords;
	for (int j = 0; j < 4; j++)
	{
		board[j + 12] = dictionaryWords[randomNumber][j];
	}

	// print the board
	printf("   E F G H\n");
	printf("   -------\n");
	printf("A| %c %c %c %c\n", board[0], board[1], board[2], board[3]);
	printf("B| %c %c %c %c\n", board[4], board[5], board[6], board[7]);
	printf("C| %c %c %c %c\n", board[8], board[9], board[10], board[11]);
	printf("D| %c %c %c %c\n", board[12], board[13], board[14], board[15]);
}// end diplayBoard()


//--------------------------------------------------------------------------------------------------------------------------
// Make board rotations
void makeRotation(char userLetter, int userNumber, char *board) 
{
	userLetter = toupper(userLetter);	// convert letters to upper case
	char temp;							// declare temporary variable used for rotation
	char temp2;							// declare temporary variable used for rotation

	// Rotate row 'A' by 1 position
	if ((userLetter == 'A') && (userNumber == 1)) {
		temp = board[3];
		board[3] = board[2];
		board[2] = board[1];
		board[1] = board[0];
		board[0] = temp;
	}
	// Rotate row 'A' by 2 positions
	else if ((userLetter == 'A') && (userNumber == 2)) {
		temp = board[3];
		temp2 = board[2];
		board[3] = board[1];
		board[2] = board[0];
		board[1] = temp;
		board[0] = temp2;
	}
	// Rotate row 'A' by 3 positions
	else if ((userLetter == 'A') && (userNumber == 3)) {
		temp = board[0];
		board[0] = board[1];
		board[1] = board[2];
		board[2] = board[3];
		board[3] = temp;
	}

	// Rotate row 'B' by 1 position
	if ((userLetter == 'B') && (userNumber == 1)) {
		temp = board[7];
		board[7] = board[6];
		board[6] = board[5];
		board[5] = board[4];
		board[4] = temp;
	}
	// Rotate row 'B' by 2 positions
	else if ((userLetter == 'B') && (userNumber == 2)) {
		temp = board[7];
		temp2 = board[6];
		board[7] = board[5];
		board[6] = board[4];
		board[5] = temp;
		board[4] = temp2;
	}
	// Rotate row 'B' by 3 positions
	else if ((userLetter == 'B') && (userNumber == 3)) {
		temp = board[4];
		board[4] = board[5];
		board[5] = board[6];
		board[6] = board[7];
		board[7] = temp;
	}

	// Rotate row 'C' by 1 position
	if ((userLetter == 'C') && (userNumber == 1)) {
		temp = board[11];
		board[11] = board[10];
		board[10] = board[9];
		board[9] = board[8];
		board[8] = temp;
	}
	// Rotate row 'C' by 2 positions
	else if ((userLetter == 'C') && (userNumber == 2)) {
		temp = board[11];
		temp2 = board[10];
		board[11] = board[9];
		board[10] = board[8];
		board[9] = temp;
		board[8] = temp2;
	}
	// Rotate row 'C' by 3 positions
	else if ((userLetter == 'C') && (userNumber == 3)) {
		temp = board[8];
		board[8] = board[9];
		board[9] = board[10];
		board[10] = board[11];
		board[11] = temp;
	}

	// Rotate row 'D' by 1 position
	if ((userLetter == 'D') && (userNumber == 1)) {
		temp = board[15];
		board[15] = board[14];
		board[14] = board[13];
		board[13] = board[12];
		board[12] = temp;
	}
	// Rotate row 'D' by 2 positions
	else if ((userLetter == 'D') && (userNumber == 2)) {
		temp = board[15];
		temp2 = board[14];
		board[15] = board[13];
		board[14] = board[12];
		board[13] = temp;
		board[12] = temp2;
	}
	// Rotate row 'D' by 3 positions
	else if ((userLetter == 'D') && (userNumber == 3)) {
		temp = board[12];
		board[12] = board[13];
		board[13] = board[14];
		board[14] = board[15];
		board[15] = temp;
	}

	// Rotate column 'E' by 1 position
	if ((userLetter == 'E') && (userNumber == 1)) {
		temp = board[12];
		board[12] = board[8];
		board[8] = board[4];
		board[4] = board[0];
		board[0] = temp;
	}
	// Rotate column 'E' by 2 positions
	else if ((userLetter == 'E') && (userNumber == 2)) {
		temp = board[0];
		temp2 = board[4];
		board[0] = board[8];
		board[4] = board[12];
		board[8] = temp;
		board[12] = temp2;
	}
	// Rotate column 'E' by 3 positions
	else if ((userLetter == 'E') && (userNumber == 3)) {
		temp = board[0];
		board[0] = board[4];
		board[4] = board[8];
		board[8] = board[12];
		board[12] = temp;
	}

	// Rotate column 'F' by 1 position
	if ((userLetter == 'F') && (userNumber == 1)) {
		temp = board[13];
		board[13] = board[9];
		board[9] = board[5];
		board[5] = board[1];
		board[1] = temp;
	}
	// Rotate column 'F' by 2 positions
	else if ((userLetter == 'F') && (userNumber == 2)) {
		temp = board[1];
		temp2 = board[5];
		board[1] = board[9];
		board[5] = board[13];
		board[9] = temp;
		board[13] = temp2;
	}
	// Rotate column 'F' by 3 positions
	else if ((userLetter == 'F') && (userNumber == 3)) {
		temp = board[1];
		board[1] = board[5];
		board[5] = board[9];
		board[9] = board[13];
		board[13] = temp;
	}

	// Rotate column 'G' by 1 position
	if ((userLetter == 'G') && (userNumber == 1)) {
		temp = board[14];
		board[14] = board[10];
		board[10] = board[6];
		board[6] = board[2];
		board[2] = temp;
	}
	// Rotate column 'G' by 2 positions
	else if ((userLetter == 'G') && (userNumber == 2)) {
		temp = board[2];
		temp2 = board[6];
		board[2] = board[10];
		board[6] = board[14];
		board[10] = temp;
		board[14] = temp2;
	}
	// Rotate column 'G' by 3 positions
	else if ((userLetter == 'G') && (userNumber == 3)) {
		temp = board[2];
		board[2] = board[6];
		board[6] = board[10];
		board[10] = board[14];
		board[14] = temp;
	}

	// Rotate column 'H' by 1 position
	if ((userLetter == 'H') && (userNumber == 1)) {
		temp = board[15];
		board[15] = board[11];
		board[11] = board[7];
		board[7] = board[3];
		board[3] = temp;
	}
	// Rotate column 'H' by 2 positions
	else if ((userLetter == 'H') && (userNumber == 2)) {
		temp = board[3];
		temp2 = board[7];
		board[3] = board[11];
		board[7] = board[15];
		board[11] = temp;
		board[15] = temp2;
	}
	// Rotate column 'H' by 3 positions
	else if ((userLetter == 'H') && (userNumber == 3)) {
		temp = board[3];
		board[3] = board[7];
		board[7] = board[11];
		board[11] = board[15];
		board[15] = temp;
	}

	// print the board
	printf("   E F G H\n");
	printf("   -------\n");
	printf("A| %c %c %c %c\n", board[0], board[1], board[2], board[3]);
	printf("B| %c %c %c %c\n", board[4], board[5], board[6], board[7]);
	printf("C| %c %c %c %c\n", board[8], board[9], board[10], board[11]);
	printf("D| %c %c %c %c\n", board[12], board[13], board[14], board[15]);
}// end makeRotation()


//--------------------------------------------------------------------------------------------------------------------------
// begin main()
int main() 
{
	int userChoice;			// declare int variable userChoice
	int countWords = 0;		// declare int countWords and initialize to 0
	FILE *pInputFile;		// pointer to file
	char storeWord[81];		// declare array for storing dictionary words
	char board[16];			// declare array for board elements
	int counter = 1;		// initialize int counter to 1
	char userLetter;		// store user choice for letter
	int userNumber;			// store user choice for number

	displayIdInfo();		// call function to display information

	displayInstructions();	// call function to display game instructions

	printf("Which dictionary size do you want? (1=small, 2=medium, 3=large): ");
	scanf("%d", &userChoice);

	int numberOfWords = countNumberOfWords(userChoice);		// store number of words into int numberOfWords

	// Allocate memory
	char ** dictionaryWords = new char*[numberOfWords];
	for (int i = 0; i < numberOfWords; i++)
	{
		dictionaryWords[i] = new char[5];
	}

	// user chooses 1 for SMALL dictionary
	if (userChoice == 1)
	{
		// open SMALL dictionary file and store the words
		pInputFile = fopen("smallDictionary.txt", "r");
		int i = 0;
		while (fscanf(pInputFile, "%s", storeWord) != EOF) {
			strcpy(dictionaryWords[i], storeWord);
			i++;
		}
	}

	// user chooses 2 for MEDIUM dictionary
	else if (userChoice == 2)
	{
		// open MEDIUM dictionary file and store the words
		pInputFile = fopen("mediumDictionary.txt", "r");
		int i = 0;
		while (fscanf(pInputFile, "%s", storeWord) != EOF) {
			strcpy(dictionaryWords[i], storeWord);
			i++;
		}
	}

	// user chooses 3 for LARGE dictionary
	else if (userChoice == 3)
	{
		// open LARGE dictionary file and store the words
		pInputFile = fopen("largeDictionary.txt", "r");
		int i = 0;
		while (fscanf(pInputFile, "%s", storeWord) != EOF) {
			strcpy(dictionaryWords[i], storeWord);
			i++;
		}
	}

	displayBoard(board, dictionaryWords, numberOfWords);		// call function to display board

	// begin while() loop
	while (counter < 4)		// repeat loop 3 times
	{
		printf("%d. Enter the row or column to be rotated, and a number 1..3: ", counter);
		scanf(" %c", &userLetter);
		scanf("%d", &userNumber);

		printf("Rotating row/col %c by %d \n", toupper(userLetter), userNumber);

		makeRotation(userLetter, userNumber, board);		// make rotatations on board according to user choice

		counter++;		// increment counter
	}// end while() loop

	printf("End of program.  Exiting...\n");		// exit the program

	return 0;
}// end main()