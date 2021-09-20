// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 1

/* main.cpp contains the main method and creates an instance of the FileProcessor class in order to test its functionality.
It takes two command line arguements: the name of an input text file (English) and the name of an output text file. The text in the
input text file (English) is converted to Tutnese and written to the output text file. */

#include <iostream>
#include "FileProcessor.h"
using namespace std;

int main(int argc/*number of arguments*/, char** argv/*array*/){
  string inputFile = "";
  string outputFile = "";

  // if user does not provide two command line aruguements, notify user
  if(argc < 3){
    cout << "ERROR: Please provide both an input and an output file name (in that order) as command line arguements." << endl;
    return -1;
  }
  // else, collect names of input and output files from command line arguements
  else{
    inputFile = argv[1];
    outputFile = argv[2];

    // create instance of FileProcessor for function use
    FileProcessor *fp = new FileProcessor();

    // convert text in input file to Tutnese
    fp->processFile(inputFile, outputFile);

    // delete instance of FileProcessor
    delete fp;
  }
  return 0;
}
