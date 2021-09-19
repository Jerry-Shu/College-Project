#ifndef TOKEN_STREAM_H_INCLUDED
#define TOKEN_STREAM_H_INCLUDED

#include "../std_lib_facilities.h"

///This file does not need to be changed at all
///Note the new constants below

struct Token  	// user-defined type called Token
{
    char kind;	// what kind of token
    double value;	// used for numbers (only): a value
};

class Token_stream
{
public:
    // user interface:
    Token get();		// get a Token
    void putback(Token); // put a Token back into the Token_stream
    void ignore(char c);	// discard tokens up to and including a c

private:
    // representation: not directly accessible to users:
    bool full {false};	// is there a Token in the buffer?
    Token buffer;       // here is where we keep a Token put back using putback()

};

// Token 搆ind?values:
const char number = '8';		// a floating-point number
const char quit = 'q';		// an exit command
const char print = ';';		// a print command

///constant for factorial operator
const char fact = '!';		// a print command

///constants for "sin" and "sqrt" inputs
const char sine = 21;  ///arbitrary number
const char root = 22;

// User interaction strings:
const string prompt = "> ";
const string result = "= ";	// indicate that a result follows

#endif // TOKEN_STREAM_H_INCLUDED
