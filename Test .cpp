/**
* An example of how to write unit tests.
* Use this as a basis to build a more complete Test.cpp file.
*
* IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
*
* AUTHORS: <207229477>
*
* Date: 2021-06-03
*/
#include "doctest.h"
#include "snowman.hpp"
#include <string>
#include <vector>
#include <algorithm>
using namespace ariel;
using namespace std;


string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good snowman code") {
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_ \n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11111111)) == nospaces("_===_\n(.,.)\n<( : )>\n( : )"));
    CHECK(nospaces(snowman(22222222)) == nospaces(" ___\n.....\n\\(o.o)/\n(] [)\n(\" \")"));
    CHECK(nospaces(snowman(33333333)) == nospaces("_\n/_\\\n(O_O)\n/(> <)\\\n(___)"));
    CHECK(nospaces(snowman(44444444)) == nospaces("___\n(_*_)\n(- -)\n(   )\n(   )"));
	CHECK(nospaces(snowman(11223344)) == nospaces("_===_\n(o,o)\n/(   )\\\n(   )"));
    CHECK(nospaces(snowman(44332211)) == nospaces("___\n(_*_)\n\\(O O)/\n( : )\n( : )"));
    CHECK(nospaces(snowman(34231234)) == nospaces("_\n/_\\\n(o O)/\n<(> <)\n(   )"));
}

TEST_CASE("Hats") {
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_ \n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(21114411)) == nospaces("___\n.....\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(31114411)) == nospaces("_\n/_\\\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(41114411)) == nospaces("___\n(_*_)\n(.,.)\n( : )\n( : )"));

}

TEST_CASE("Noses") {
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(12114411)) == nospaces("_===_\n(...)\n( : )\n( : )"));
    CHECK(nospaces(snowman(13114411)) == nospaces("_===_\n(._.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(14114411)) == nospaces("_===_\n(. .)\n( : )\n( : )"));
	
}

TEST_CASE("Left Eyes") {
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11214411)) == nospaces("_===_\n(o,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11314411)) == nospaces("_===_\n(O,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11414411)) == nospaces("_===_\n(-,.)\n( : )\n( : )"));
}

TEST_CASE("Right Eyes") {
	CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11124411)) == nospaces("_===_\n(.,o)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11134411)) == nospaces("_===_\n(.,O)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11144411)) == nospaces("_===_\n(.,-)\n( : )\n( : )"));
}

TEST_CASE("Left Arms") {
	CHECK(nospaces(snowman(11111411)) == nospaces("_===_\n(.,.)\n<( : )\n( : )"));
    CHECK(nospaces(snowman(11112411)) == nospaces("_===_\n\\(.,.)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11113411)) == nospaces("_===_\n(.,.)\n/( : )\n( : )"));
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
}

TEST_CASE("Right Arms") {
	CHECK(nospaces(snowman(11114111)) == nospaces("_===_\n(.,.)\n( : )>\n( : )"));
    CHECK(nospaces(snowman(11114211)) == nospaces("_===_\n(.,.)/\n( : )\n( : )"));
    CHECK(nospaces(snowman(11114311)) == nospaces("_===_\n(.,.)\n( : )\\\n( : )"));
    CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )"));
}

TEST_CASE("Torsos") {
	CHECK(nospaces(snowman(11144411)) == nospaces("_===_\n(.,-)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11144421)) == nospaces("_===_\n(.,-)\n(] [)\n( : )"));
    CHECK(nospaces(snowman(11144431)) == nospaces("_===_\n(.,-)\n(> <)\n( : )"));
    CHECK(nospaces(snowman(11144441)) == nospaces("_===_\n(.,-)\n(   )\n( : )"));
}

TEST_CASE("Bases") {
	CHECK(nospaces(snowman(11144411)) == nospaces("_===_\n(.,-)\n( : )\n( : )"));
    CHECK(nospaces(snowman(11144412)) == nospaces("_===_\n(.,-)\n( : )\n(\" \")"));
    CHECK(nospaces(snowman(11144413)) == nospaces("_===_\n(.,-)\n( : )\n(___)"));
    CHECK(nospaces(snowman(11144414)) == nospaces("_===_\n(.,-)\n( : )\n(   )"));
}

TEST_CASE("Test nagitive") {
    CHECK_THROWS(snowman(-1));
    CHECK_THROWS(snowman(-555));
    CHECK_THROWS(snowman(-654));
    CHECK_THROWS(snowman(-11111111));
}

TEST_CASE("Not legal 8 digit num:") {
    CHECK_THROWS(snowman(91111111));
    CHECK_THROWS(snowman(29224442));
    CHECK_THROWS(snowman(22922222));
    CHECK_THROWS(snowman(21292122));
    CHECK_THROWS(snowman(11119111));
    CHECK_THROWS(snowman(13322912));
    CHECK_THROWS(snowman(11111192));
    CHECK_THROWS(snowman(12331119));
}

TEST_CASE("Less then 8 digit") {
    CHECK_THROWS(snowman(1));
	CHECK_THROWS(snowman(12));
	CHECK_THROWS(snowman(123));
	CHECK_THROWS(snowman(1234));
	CHECK_THROWS(snowman(12344));
	CHECK_THROWS(snowman(123444));
	CHECK_THROWS(snowman(1234444));
}

TEST_CASE("Bad snowman code") {
	CHECK_THROWS(snowman(666));
	CHECK_THROWS(snowman(11111110));
	CHECK_THROWS(snowman(4444444));
	CHECK_THROWS(snowman(0));
	CHECK_THROWS(snowman(999919999));
	CHECK_THROWS(snowman(12341235));
	CHECK_THROWS(snowman(00000001));
}



