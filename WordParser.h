#pragma once
#include<string>
#include<vector>
#include <map>
#include<sstream>

class wordParser
{
public:
	explicit wordParser(std::string t);
	uint16_t frequency(std::string w);
	std::pair<std::vector<std::string>::const_iterator, std::vector<std::string>::const_iterator>
		words(const uint16_t frequency);

private:
	std::stringstream textForFreq, textForWords;
	std::map <std::string, uint16_t> wordsInText;
	std::map<uint16_t, std::vector<std::string>> repeatedWords;
};
