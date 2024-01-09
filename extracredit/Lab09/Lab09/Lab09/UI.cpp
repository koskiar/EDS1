#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "BST.h"
#include "BST.cpp"

struct Book {
    std::string title;
    std::string authorFName;
    std::string authorLName;
    std::string authorName; //Author full name

    int wordCount = 0; //hyphenated words are considered 1 word, but words separated by two hyphens (--) are separate words

    int totalLetters = 0;
    double letterFrequency[26] = { 0 }; //all entries set to 0
    int lineCount = 0;
};



int main()
{
    std::string inputFileName;
    BinaryTree<std::string> BST;
    std::ifstream inputFile;
    std::string* pain = nullptr;


    std::cout << "Please input the name of the file you want to open: ";
    getline(std::cin, inputFileName);
    inputFile.open(inputFileName);

    // Needs to be a while loop because an incorrect filename could attempt to be opened many times in a row.
    while (inputFile.fail())
    {
        std::cout << "The file does not exist, please enter a different name: ";
        getline(std::cin, inputFileName);
        inputFile.open(inputFileName);
    }

    Book myBook;

    getline(inputFile, myBook.title);
    getline(inputFile, myBook.authorName);

    int spaceIndex = myBook.authorName.find(" ");
    myBook.authorFName = myBook.authorName.substr(0, spaceIndex);
    myBook.authorLName = myBook.authorName.substr(spaceIndex + 1);

    bool checkContent = false; //to check if the string "Content:" has been encountered
    std::string line; //to store a line from the file's content text
    std::string Word;

    while (!inputFile.eof()) {

        getline(inputFile, line);

        if (line == "") { //check for blank lines
            continue;
        }

        if (line.substr(0, 9) == "Contents:") { //check for "Content:" string
            continue;
        }

        myBook.lineCount++;

        /*For loop to parse through each character in the line*/
        for (int i = 0; i < line.length(); i++) {

            /*Counts the number of words*/
            if (i < line.length() - 1) { //if statement to ensure code only excutes when: i < last index of the string

                Word += line[i];

                if (line[i] == ' ' || (line[i] == '-' && line[i + 1] == '-')) {
                    
                    pain = new std::string(Word);

                    BST.Insert(pain);
                    
                    delete pain;
                    myBook.wordCount++; //counts the number of spaces " " and em dashes "--"
                    Word = "";
                }
            }


        }
        myBook.wordCount++; //number of words is always one more than the number of spaces and em dashes per line
    }

    inputFile.close(); //close input file
    int input = 0;
    std::cout << "The Tree has Been implimented" << std::endl;
    while (input != 4) {
        std::cout << "What would you like to do?" << std::endl
            << "[1] Search for a word?" << std::endl
            << "[2] Words in Alphabetical order (Ascending) " << std::endl
            << "[3] Words in Alphabetical order (descending)" << std::endl
            << "[4] quit" << std::endl;
        std::cin >> input;
            while (input < 1 || input > 4)
            {
                std::cout << "invalid input" << std::endl;
                std::cout << "What would you like to do?" << std::endl
                    << "[1] Search for a word?" << std::endl
                    << "[2] Words in Alphabetical order (Ascending) " << std::endl
                    << "[3] Words in Alphabetical order (descending)" << std::endl
                    << "[4] quit" << std::endl;
            };
            if (input == 1) 
            {
                std::string Sinput;
                std::string output;
                std::cout << "what word would you like to search for? " << std::endl;
                std::cin >> Sinput;
                if (BST.Find(Sinput) == nullptr) 
                {
                    std::cout << " The Word Was not used in the tree" << std::endl;
                }
                else
                {
                    std::cout << "The word was used: " << std::endl;
                    std::cout << BST.Find(Sinput) << std::endl;
                }            
            }
            else if (input == 2) 
            {
                std::cout << BST.GetAllAscending() << std::endl;
                
            }
            else if (input == 3) 
            {
            
                std::cout << BST.GetAllDescending() << std::endl;

            }
    }

    return 0;
}
