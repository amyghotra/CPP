#include "KeywordsInFile.h"

/*
    Constructor method
    Takes in textfile and keyword files
    Reads both files
    Creates map with keywords
    Parses through the text and keeps track of how many keywords there are
    in total and how many keywords there are per line
*/
KeywordsInFile::KeywordsInFile(const std::string& wordFile, const std::string& textFile)
{
    std::ifstream given_text;
    std::fstream given_words;

    std::string word = "";
    std::string text_body = "";

    // open keyword file and save ghe words in an unordered map
    given_words.open(wordFile, std::ios::in);
    if(given_words.is_open())
    {
        while(getline(given_words, word))
        {
            std::string temp = "";
            std::stringstream ls(word);

            while(ls >> temp)
            {
                std::string temp2 = "";
                for(const auto& x: temp)
                {
                    if((x >= 'A'))
                    {
                        temp2 += x;
                    }
                }
                if(word_map.count(temp2))
                {
                    word_map.at(temp2) = 0;
                }
                else
                {
                    word_map.insert({temp2, 0});
                }
            }

        }
        given_words.close();
    }
    

    int lineCounter = 0; // keep track of what line youre on

    // read through the file with the text
    given_text.open(textFile, std::ios::in);
    if(given_text.is_open())
    {
        char myChar;
        string tempStr = "";
        string temp2 = "";
        std::unordered_map<std::string, int> words_current_line;
        while(!given_text.eof())
        {
            given_text.get(myChar);
            // if(myChar == '\n')
            // {
            //     words_by_line.insert({lineCounter,words_current_line});
            //     lineCounter++;
            // }
            if(myChar == ' ')
            {
                tempStr = "";
            }
            else
            {
                tempStr+= myChar;
            }

            if (word_map.count(tempStr)) 
            {
                word_map.at(tempStr)++;
                if(words_current_line.count(tempStr))
                {
                    words_current_line.at(tempStr)++;
                }
                else
                {
                    words_current_line.insert({tempStr, 1});
                }
            }
            
        }
        // get the lines
        // while(getline(given_text, text_body))
        // {
            // std::string temp = "";
            // std::unordered_map<std::string, int> words_current_line;
            // text.push_back(text_body);
            // std::stringstream ls(text_body);

            // get the words in the current line and save them
            // while(ls >> temp)
            // {
            //     std::string temp2 = "";
                // for(int i = 0; i < temp.length(); i++)
                // {
                //     if((temp[i]>= 'A'))
                //     {
                //         temp2 += temp[i];
                //     }
                // }
                
                /* unordered map to keep track of how many times a keyword
                   appears in a line 
                */
                // if (word_map.count(temp2)) {
                //     word_map.at(temp2)++;
                //     if(words_current_line.count(temp2))
                //     {
                //         words_current_line.at(temp2)++;
                //     }
                //     else
                //     {
                //         words_current_line.insert({temp2, 1});
                //     }
                // }
            // }
            // words_by_line.insert({lineCounter,words_current_line});
            // lineCounter++;
        // }


        given_text.close();
    }

}

/*
    Returns F if word does not exist in map
    Returns T if word does exist
*/
bool KeywordsInFile::KeywordFound(const std::string& givenWord) const
{
    if(word_map.count(givenWord))
    {
        return true;
    }
    else
    {
        return false;
    }
    
    // return word_map.count(givenWord);
}

/*
    Given line number and word, will return the number
    of instacnes of a given word in given line
    Else will return a -1
*/
int KeywordsInFile::KeywordInLine(const std::string& givenWord,const int& lineNumber) const
{
    if(words_by_line.count(lineNumber - 1))
    {
        int line_to_index = lineNumber - 1;
        std::unordered_map<std::string, int> getInt = words_by_line.at(line_to_index);
        return getInt.at(givenWord);
    }
    else
    {
        return -1;
    }

}

/*
    Returns the total number of times a keyword appeared in the text
*/
int KeywordsInFile::TotalOcccurrences(const std::string& givenWord) const
{
    if(word_map.count(givenWord))
    {
        return word_map.at(givenWord);
    }
    else
    {
        return 0;
    }
}

/*
    Helper method that returns the map holding all of the keyword:instances
    pairs
*/
std::unordered_map<std::string, int> KeywordsInFile::get_map() const
{
    return word_map;
}

/*
    operator<< overloading
*/
std::ostream& operator<<(std::ostream& os,const KeywordsInFile& itemName)
{
    std::unordered_map<std::string, int> map_associated = itemName.get_map();
    for(const auto& i: map_associated)
    {
        os << i.first << ": " << i.second << std::endl;
    }
    
    return os;
}
