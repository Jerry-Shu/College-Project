#include "GUI.h"
#include "SemanticDictionary.h"
#include"std_lib_facilities.h"
#include "SemanticDescriptor.h"


using namespace Graph_lib;

struct Lines_window : Graph_lib::Window  // Lines_window inherits from Window
{

  Lines_window(Point xy, int w, int h, const string& title); // declare constructor
private:
  Open_polyline lines;


  Button choice1_button;
  Button choice2_button;
  Button choice3_button;
  Button choice4_button;
  Button choice5_button;
  //Button ok_button;


  //In_box next_x;        //declare some i/o box
  In_box question_button;
  In_box inFile_button;  
  In_box yes_no_button;
  Out_box out_button;
  Out_box significantly_button;
 



  //----------------------------------------------------------------------
  void choice1();
  void choice2();
  void choice3();
  void choice4();
  void choice5();
  //string ok();
  void check();

  static void cb_choice1(Address, Address window); // calback for next_button
  static void cb_choice2(Address, Address window); // calback for next_button
  static void cb_choice3(Address, Address window); // calback for next_button
  static void cb_choice4(Address, Address window); // calback for next_button
  static void cb_choice5(Address, Address window); // calback for next_button
          

  //static void cb_ok(Address, Address window); // calback for next_button


  //-------------------------------------------------------------------


};
