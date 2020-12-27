#ifndef KeywordsInFile_h
#define KeywordsInFile_h

// libraries
#include <sstream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <utility>

class KeywordsInFile
{
public:
    // disable the default constructor
    KeywordsInFile() = delete;

    // constructor that takes in and reads the text and keyword files
    KeywordsInFile(const std::string& wordFile, const std::string& textFile);

    // return if a given word is in the text or not
    bool KeywordFound(const std::string& givenWord) const;

    // return the total number of times a word occurs in a given line
    int KeywordInLine(const std::string& givenWord,const int& lineNumber) const;

    // return the total number of times a keyword appears in the entire text
    int TotalOcccurrences(const std::string& givenWord) const;
    
    // helpter method used in tandem with operator<< ; returns the word_map
    std::unordered_map<std::string, int> get_map() const;

private:
    // vector to store the lines of text
    std::vector<std::string> text;

    // keep track of word frequency in entire text
    std::unordered_map<std::string, int> word_map;

    // keep track of word frequency by line
    std::unordered_map<int, std::unordered_map<std::string, int>> words_by_line;
};

#include "KeywordsInFile.cpp"
#endif