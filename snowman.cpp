#include "snowman.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <exception>
using namespace std;

const int MAX_NUMS = 8;
const int TEN = 10;

void throwException(unsigned int num)
{	
	throw std::invalid_argument( "Invalid code" );

}

void validateNumber( int num)
{
	 int tempNum = num;
	int counter = 0;
	while (tempNum != 0) {
		counter++;
		int digit = tempNum % TEN;
		if (digit < 1 || digit >4)
		{
			throwException(num);
		}
		tempNum /= TEN;
	}
	if (counter != MAX_NUMS)
	{
			throwException(num);
	}
}

string createHat(int digit)
{
	switch (digit)
	{
		case 1: {
			return " _===_\n";
		}
		case 2: {
			return " ___ \n.....\n";
		}
		case 3: {
			return "   _  \n  /_\\\n";
		}
		case 4: {
			return "  ___ \n (_*_)\n";
		}
		default:{
			return "";
		}
	}
}

string createLeftHand(int digit, int isTop)
{

	switch (digit)
	{
	case 1: {
		if(isTop == 1){
			return " ";
		}
		return "<";
	}
	case 2: {
		if(isTop == 1){
			return "\\";
		}
		return " ";
	}
	case 3: {
		if(isTop == 1){
			return " ";
		}
		return  "/" ;
	}
	case 4: {
		return " ";
	}
	default :{
		return "";
	}
	}
}

string createEye(int digit)
{
	switch (digit)
	{
	case 1: {
		return ".";
	}
	case 2: {
		return "o";
	}
	case 3: {
		return "O";
	}
	case 4: {
		return "-";
	}
	default :{
		return "";
	}
	}
}

string createNose(int digit)
{

	switch (digit)
	{
	case 1: {
		return ",";
	}
	case 2: {
		return ".";
	}
	case 3: {
		return "_";
	}
	case 4: {
		return " ";
	}
	default :{
		return "";
	}
	}

}

string createRightHand(int digit, int isTop)
{

	switch (digit)
	{
	case 1: {
		if(isTop == 1){
			return " \n";
		}
		return ">\n";
	}
	case 2: {
		if(isTop == 1){
			return "/\n";
		}
		return " \n";
	}
	case 3: {
		if(isTop == 1){
			return " \n";
		}
		return "\\\n";
	}
	case 4: {
		return " \n";
	}
	default:{
		return "";
	}
	}
}

string createTorso(int digit)
{

	switch (digit)
	{
	case 1: {
		return " : ";
	}
	case 2: {
		return "] [";
	}
	case 3: {
		return "> <";
	}
	case 4: {
		return "   ";
	}
	default:{
		return "";
	}
	}
}

string createBase(int digit)
{
	switch (digit)
	{
	case 1: {
		return " : ";
	}
	case 2: {
		return "\" \"";
	}
	case 3: {
		return "___";
	}
	case 4: {
		return "   ";
	}
	default:{
		return "";
	}
	}
}



namespace ariel {


string snowman(int num) {
		validateNumber(num);
		int base = num % TEN;
		num /= TEN;
		int torso = num % TEN;
		num /= TEN;
		int rightArm = num % TEN;
		num /= TEN;
		int leftArm = num % TEN;
		num /= TEN;
		int rightEye = num % TEN;
		num /= TEN;
		int leftEye = num % TEN;
		num /= TEN;
		int nose = num % TEN;
		num /= TEN;
		int hat = num;
		return createHat(hat)
			+ createLeftHand(leftArm, 1) + "(" + createEye(leftEye) + createNose(nose) + createEye(rightEye) + ")" + createRightHand(rightArm, 1)
			+ createLeftHand(leftArm, 0) + "(" + createTorso(torso) + ")" + createRightHand(rightArm, 0) +
			+" (" + createBase(base) + ") ";

	}

}