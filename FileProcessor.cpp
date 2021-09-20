// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 1

/* FileProcessor.cpp contains the implementation of the FileProcessor class. It implements a constructor, a destructor, and one function:
processFile takes an English text file (one parameter) as input and translates the text to Tutnese and writes it to a designated output (another parameter).
It also uses functions from the Translator class to facilitate functionality. */

#include "FileProcessor.h"
#include "Translator.h"

FileProcessor::FileProcessor(){
}
FileProcessor::~FileProcessor(){
}

// takes an English text file (one parameter) as input and translates the text to Tutnese and writes it to a designated output (another parameter).
void FileProcessor::processFile(string englishFileName, string tutneseFileName){
  ifstream inFS;// input file stream
  ofstream outFS;// output file stream

  inFS.open(englishFileName);// open input file
  outFS.open(tutneseFileName);// open output file

  // if input file cannot be opened print error to user and do nothing else
  if (!inFS.is_open()) {
     cout << "Could not open the input file: " << englishFileName << "." << endl << "Please provide a valid input file." << endl;
  }
  // if output file cannot be opened print error to user and do nothing else
  else if (!outFS.is_open()) {
     cout << "Could not open the output file: " << englishFileName << "." << endl << "Please provide a valid input file." << endl;
  }
  // if both files are successfully opened run translation code
  else{
    // create instance of Translator for function use
    Translator *translator = new Translator();
    string englishSentence = "";// stores sentence/line of file data
    string tutneseSentence = "";

    getline(inFS, englishSentence);// store first line in file data

    // loop until the filestream is empty
    while (!inFS.fail()) {
      // translate the English sentence into a Tutnese sentence
      tutneseSentence = translator->translateEnglishSentence(englishSentence);
      // write Tutnese sentence to file
      outFS << tutneseSentence << endl;

      getline(inFS, englishSentence);// store next line in file data
    }

    // if there is an input failure before reaching end of file, notify user
    if (!inFS.eof()) {
       cout << "Input failure before reaching end of file." << endl;
    }
    //delete translator from memory
    delete translator;
  }
  inFS.close();// close input file stream
  outFS.close();// close output file stream
}
