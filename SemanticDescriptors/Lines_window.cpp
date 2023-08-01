#include "Lines_window.h"
#include "SemanticDictionary.h"
#include "SemanticDescriptor.h"
#include"std_lib_facilities.h"

SemanticDictionary d;
int TOTAL_TIME = 0;
int CORRECT = 0;



Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	:Window(xy,w,h,title),
		// construct/initialize the parts of the window:
   // location	        size          name            action
	choice1_button(Point(x_max()-500,20), 400, 20, "  1.  Read the semantic dictionary from storage", cb_choice1),
  choice2_button(Point(x_max()-500,50), 400, 20, "2.  Write the semantic dictionary to storage", cb_choice2),  
  choice3_button(Point(x_max()-500,80), 400, 20, "  3.  Read and process a text file (get smarter!)", cb_choice3),  
  choice4_button(Point(x_max()-500,110), 400, 20, "4.  Solve a TOEFL question", cb_choice4),  
  choice5_button(Point(x_max()-500,140), 400, 20, "5.  Quit", cb_choice5),    
  //ok_button(Point(x_max()-1150,200), 40, 20, "OK", cb_ok),    
  question_button(Point(x_max()- 420,200), 320, 20, "Input a TOEFL question: "),
  inFile_button(Point(x_max()- 420,170), 150, 20, "Input the file name"),    	          // io boxes
  //
  yes_no_button(Point(x_max()- 190,170), 89, 20, "(y/n)?"), 
  out_button(Point(x_max()-500,250), 220, 100, "Result: "),// result of computer
   significantly_button(Point(x_max()-135,250), 35, 30, "significantly: %")
{

  attach(choice1_button);
  attach(choice2_button);
  attach(choice3_button);
  attach(choice4_button);
  attach(choice5_button);
  //attach(ok_button);
  attach(question_button);
  attach(inFile_button);
 
  attach(out_button);
  attach(yes_no_button);
  attach(significantly_button);
 


 out_button.put("Please fill out the \ninformation in advance\nThen press the button...");
//--------------------------------------------------------------




//--------------------------------------------------------------

}


void Lines_window::choice1()
{
         //output that you are reading the dictionary file
           string p0 = "Reading dictionary from file...\n";
           string p1 = "Done reading!\n";
           string p2 = p0 + p1;
          string dictionaryFileName = "SemanticDictionary.txt";
            //construct ifstream object and open the file
            ifstream ifs(dictionaryFileName);
            if(!ifs)
            {
                //error message
             out_button.put("Dictionary file is not open!" );
            }
            else
            {
                 ifs >> d;
                //extract from ifstream object into your dictionary object
                //output that you are done reading
                out_button.put(p2);
            }



}

void Lines_window::choice2()
{
  //warn the user that this will overwrite the previous file, ask if they want to proceed
            //if proceed
            
            string p0 = "Overwrite the pervious file of the dictionary? (y/n): \n";
            
            
            string p1 = "Writing dictionary to a file...\n";
            string p2 =  "Done writing!\n" ;
            string p3 = p0 + p1 + p2;
            string proceedChoice = yes_no_button.get_string();
            string dictionaryFileName = "SemanticDictionary.txt";
            if(proceedChoice == "y" || proceedChoice == "Y")
            {
                //output that you are writing the dictionary to a file
                
                //declare and open ofstream object
                ofstream ofs(dictionaryFileName);
                //insert from the dictionary object into the ofstream object
                ofs << d;
                //output that you are done writing
               
            }
            out_button.put(p3);
            

}

void Lines_window::choice3()
{
   
    //declare string for menu choice

    //declare and assign a string for the dictionary file name
      string filename;
      filename = inFile_button.get_string();
      
            //construct ifstream object and open the file
            ifstream ifs(filename);
            if(!ifs)
            {
                //error message
                out_button.put(" Dictionary file is not open!");
            }
            else
            {
                //output that you are processing the file
                
                
                auto start = high_resolution_clock::now(); //code to record time elapsed
                //declare a variable to hold all of the text
                string giantText;
                //loop to read every word in the file.  Concatenate each word onto text, separated by " "
                string s;
               while(ifs >> s)
               {
                   giantText += s + " ";
               }
                //pass text into getSentenceLists.  (This is a copy paste from the last project)
                vector<vector<string>> sentenceLists = getSentenceLists(giantText);
                //Create a double for loop to loop through each word of each sentenceList in sentenceLists and 
                
                //    process the target word.  (This is also a copy paste from the last project)

                
                 for(vector<string> sentenceList : sentenceLists)
                     for(string targetWord : sentenceList) d.processTargetWord(targetWord, sentenceList);

                auto stop = high_resolution_clock::now();  //code to record time elapsed
                auto duration = duration_cast<milliseconds>(stop - start);
                string p0 = "File opened, reading...\n";
                string p1 = "Done.  Time elapsed: \n";
                string p2= to_string(duration.count());
                string p3 = " milliseconds";

                string p4 = p0 + p1 + p2 + p3;

                out_button.put(p4);
                
                
            }
}

void Lines_window::choice4()
{
            string p0 =  "Enter a TOEFL question as \n <word> <answer> <choice1> <choice2> <choice3>: \n";
            string word, answer, choice1, choice2, choice3;
            istringstream question(question_button.get_string());
            question >> word >> answer >> choice1 >> choice2 >> choice3;

            try
            {
                string s = d.mostSimilarWord(word, vector<string>{choice1, choice2, choice3});
                cout << "Most similar: " << s << endl;
                string p1 = "Most similar: ";
                string p2 = s + "\n";
                string p3 = "Index: ";
                string p4 = to_string(d.getSimilarity(word, s)) + "\n";
                string p5 = "Correct answer.\n";
                string p6 = "Incorrect answer.";
                if(s == answer) 
                {
                     CORRECT += 1;
                     TOTAL_TIME += 1;
                  out_button.put(p1 + p2 + p3 + p4 + p5);
                 
                }
                else 
                {
                   out_button.put(p1 + p2 + p3 + p4 + p6);
                   TOTAL_TIME += 1;

                }

                check();

                
            }
            catch(runtime_error& e)
            {
                cout << e.what() << endl;
            }



}

void Lines_window::choice5()
{
  //cout << "5.  Quit" << endl;
  	

}


void Lines_window::check()
{

   int s  = (CORRECT * 1.0 / TOTAL_TIME * 1.0) * 100;
    string str_s = to_string(s);
    significantly_button.put(str_s);
    


}

/*
string Lines_window::ok()
{
  string s = inFile_button.get_string();
  string p0 = "Reading the file ";
  string p1 = "...\n";
  string p2 = p0 + s + p1;
  out_button.put(p2);
  return s;

}
*/


void Lines_window::cb_choice1(Address, Address pw) // calback for next_button
{
        reference_to<Lines_window>(pw).choice1();	// now call our
}

void Lines_window::cb_choice2(Address, Address pw) // calback for next_button
{
        reference_to<Lines_window>(pw).choice2();	// now call our
}

void Lines_window::cb_choice3(Address, Address pw) // calback for next_button
{
        reference_to<Lines_window>(pw).choice3();	// now call our
}

void Lines_window::cb_choice4(Address, Address pw) // calback for next_button
{
        reference_to<Lines_window>(pw).choice4();	// now call our
}

void Lines_window::cb_choice5(Address, Address pw) // calback for next_button
{
        reference_to<Lines_window>(pw).choice5();	// now call our
}

/*
void Lines_window::cb_ok(Address, Address pw) // calback for next_button
{
        reference_to<Lines_window>(pw).ok();	// now call our
}
*/






































//---------------------------------------------------------------------
