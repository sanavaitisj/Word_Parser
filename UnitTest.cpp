#include "catch.hpp"
#include "main.cpp"
#include"WordParser.h"

SCENARIO("checking frequency")
{
	GIVEN("one two two three three three")
	{
		std::string const testString = "one two two three three three";
        wordParser check = wordParser(testString);

		WHEN("checking f = 1")
		{
	        uint16_t const result = check.frequency("one");
			REQUIRE(result == 1);
		}

		AND_WHEN("checking f = 2")
		{
			uint16_t const result = check.frequency("two");
			REQUIRE(result == 2);
		}
		AND_WHEN("checking f = 0 Negative test")
		{
			uint16_t const result = check.frequency("ten");
			REQUIRE(result == 0);
		}
	}
}

SCENARIO("checking word")
{

	GIVEN("pizza hotdog pizza nacho hotdog taco burrito taco burrito taco burrito food food")
	{
		std::string const testString = "pizza hotdog pizza nacho hotdog taco burrito taco burrito taco burrito food food";
		wordParser check = wordParser(testString);
		std::vector<std::string> wordHolder;
		WHEN("words with f=1")
		{
			auto const results = check.words(1);
			auto iter = results.first;
			REQUIRE(*iter == "nacho");
		}
		AND_WHEN("words with f=2")
		{
			auto const results = check.words(2);
			auto iter = results.first;
			REQUIRE(*iter == "pizza");
			++iter;
			REQUIRE(*iter == "hotdog");
			++iter;
			REQUIRE(*iter == "food");
			++iter;
			REQUIRE(iter == results.second);
		}
		AND_WHEN("words with f=10  Negative test")
		{
			auto const results = check.words(10);
			REQUIRE(results.first == results.second);

		}
	}
}

SCENARIO("checking functions with an empty string")
{
	GIVEN("AN empty string")
	{
		std::string const testString = "";
		wordParser check = wordParser(testString);


		WHEN("using function frequency")
		{
			uint16_t const result = check.frequency("empty");
			REQUIRE(result == 0);
		}
		AND_WHEN("using function words")
		{
			auto const results = check.words(1);
			REQUIRE(results.first == results.second);
		}
	}
}
