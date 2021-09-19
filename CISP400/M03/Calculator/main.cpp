#include "../std_lib_facilities.h"
#include "calculator.h"
#include "Token_stream.h"

Token_stream ts;

///This file does not need to be changed at all
int main()
{
    try
    {
        calculate();
        keep_window_open("~~");	// cope with Windows console mode
        return 0;
    }
    catch (...)  			// other errors (don�t try to recover)
    {
        cerr << "exception \n";
        keep_window_open("~~");
        return 2;
    }

    keep_window_open("~~");
}
