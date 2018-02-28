#include "wordParser.h"

wordParser::wordParser(std::string t)
{
	textForFreq = std::stringstream(t);
	textForWords = std::stringstream(t);
	std::string currentWord;

	while (textForFreq >> currentWord) //Creates map for frequency function
	{
		if (wordsInText.find(currentWord) != wordsInText.end())
			++wordsInText[currentWord];
		else
			wordsInText[currentWord] = 1;
	}

	while(textForWords >> currentWord)  //creates map for words function
	{
		uint16_t freq = wordParser::frequency(currentWord);
		if (std::find(repeatedWords[freq].begin(), repeatedWords[freq].end(), currentWord) == repeatedWords[freq].end())
			repeatedWords[freq].push_back(currentWord);
	}
}

uint16_t wordParser::frequency(std::string w)
{
	if (wordsInText.find(w) == wordsInText.end())
		return 0;
	else
		return wordsInText[w];
}

std::pair<std::vector<std::string>::const_iterator, std::vector<std::string>::const_iterator> 
	wordParser::words(const uint16_t frequency)
{
		if (repeatedWords.find(frequency) == repeatedWords.end())
		{
			std::vector<std::string> empty;
			return make_pair(empty.end(), empty.end());
		}
		else 
			return make_pair(repeatedWords[frequency].begin(), repeatedWords[frequency].end());
}
