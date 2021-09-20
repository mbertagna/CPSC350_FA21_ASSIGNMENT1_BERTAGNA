// a. Michael Bertagna
// b. 2353491
// c. bertagna@chapman.edu
// d. CPSC 350-01
// e. Assignment 1

/* Translator.cpp contains the implementation of the Translator class. It implements a constructor, a destructor, and two functions:
translateEnglishWord translates a English word string into a tutenese word string; translateEnglishSentence translates an
English sentence string into a tutenese sentence string. It also uses functions from the Model class to facilitate functionality. */

#include "Translator.h"
#include "Model.h"

Translator::Translator(){
}
Translator::~Translator(){
}

// translates a single English word string into a tutenese word string
string Translator::translateEnglishWord(string wordInput){
  string tutneseWord = "";
  //create a model instance on the heap for use of its functions
  Model *model = new Model();

  //loop through each character of word
  for(int i = 0 ; i < wordInput.size() ; ++i){
    //if not double character (i.e. single character)
    if(wordInput[i] != wordInput[i+1]){
      tutneseWord += model->translateSingleCharacter(wordInput[i]);
    }
    // if single character
    else{
      tutneseWord += model->translateDoubleCharacter(wordInput[i]);
      ++i;
    }
  }
  //delete instance from memory
  delete model;
  return tutneseWord;
}

// translates an English sentence string into a tutenese sentence string
string Translator::translateEnglishSentence(string sentenceInput){
    string tutneseSentence = "";

    // track the start and end index of the current word in the sentence
    int wordStartIndex = 0;
    int wordEndIndex = 0;

    // loop through the words (tracked by spaces) in the sentence until the sentence string contains no more spaces
    while(sentenceInput.find(" ", wordStartIndex) != string::npos/* represents end of string (value of -1) */){

      // find space after index of word start to get the index of the end of the word
      wordEndIndex = sentenceInput.find(" ", wordStartIndex);

      // extract the substring representing the word
      string englishWord = sentenceInput.substr(wordStartIndex, wordEndIndex - wordStartIndex);

      // translate english word to tutnese and add a space for separation with next word
      tutneseSentence += (translateEnglishWord(englishWord) + " ");

      // move to next word (search for next space in sentence string)
      wordStartIndex = wordEndIndex + 1;
    }

    // get the last word in the sentence that does not have space after it (its end index will be the size of the string)
    wordEndIndex = sentenceInput.size();
    string englishWord = sentenceInput.substr(wordStartIndex, wordEndIndex - wordStartIndex);
    // add it to the tutnese translation string without a space
    tutneseSentence += translateEnglishWord(englishWord);

    return tutneseSentence;
}
