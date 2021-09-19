#include <stdio.h>
#include <ctype.h>
#include <string.h>




//don't forgot to add symbol'&' in the scanf("%d",&num);
//if it's a string , dont need to add '&'  scanf("%s", str);

 // char str1[10];  '\0'
 // C++ ： string str1;

//strcmp(str1,str2) > 0

void shiftStr(char str[], int shift);
void encipher(FILE* inFile, FILE* outFile, int key);
int validFileSuffix(char str[]);

const int BUFFER_SIZE = 2048;

int main()
{
    char inName[BUFFER_SIZE];

    ///TODO(0):  Declare strings for outName and outPrefix

    char outName[BUFFER_SIZE];
    char outRrefix[BUFFER_SIZE];
    int search;


    int key;


    ///TODO(1):  Prompt and read file name
    do
    {
        printf("Read file name (*.txt):");
        scanf("%s", inName);
        search = validFileSuffix(inName);
        if(search == 0)
        {

            printf("Error.  *.txt required.\n");
        }



    }
    while(search == 0);



    ///TODO(3):  Open read file
    fopen(inName, "r");
    ///TODO(4):  If the input file is NULL, error and exit program
    if(fopen(inName, "r") == NULL)
    {

        printf("Error:  Failed to open %s\n",inName);
        return -1;
    }


    ///TODO(5):  Prompt and read output file prefix


    printf("Output file prefix: ");
    scanf("%s", outRrefix);

    ///TODO(6):  Copy prefix to output file string, concatenate input file name


    strcpy(outName, outRrefix);
    strcat(outName, inName);



    ///TODO(7):  Open output file.  If it fails, exit the program.

    fopen(outName, "w");
    if(fopen(outName, "w") == NULL)
    {

        printf("Could not open file %s\n", outName);
        return -1;
    }


    ///TODO(8):  Prompt and read the key.  Don't forget the & for the int on scanf!!
    printf("Key: ");
    scanf("%d", &key);
    printf("Encrypting...\n");
    encipher(fopen(inName, "r"), fopen(outName, "w"), key);

    printf("Complete.\n");
}

///TODO(9):  validFileSuffix
int validFileSuffix(char str[])
{

    char *s;
    s = strstr(str, ".txt");
    if(s == NULL)
    {
        return 0;
    }
    else
    {

        return 1;
    }



}

///TODO(10):  encipher
///declare a string of size BUFFER_SIZE
///using fgets, read while it does not return NULL
///call shiftStr to shift the buffer
///use fprintf to output the string to the output file
void encipher(FILE* inFile, FILE* outFile, int key)
{
    char line[BUFFER_SIZE];

    while(fgets(line,BUFFER_SIZE,inFile)!= NULL)
    {
        shiftStr(line, key);

        fprintf(outFile, "%s",line);


    }


}

///TODO(11):  shiftStr
///Mod the shift with 26
///loop through each char
///only process if isalpha is nonzero
///if lowercase and char + shift > 'z' OR uppercase and char + shift > 'Z', subtract 26 from shift
///else if lowercase and char + shift < 'a' OR uppercase and char + shift < 'A', add 26 to shift
///add shift to the char, continue loop
void shiftStr(char str[], int shift)
{
    int i;
    shift = shift % 26;

    for(i = 0; i < strlen(str); i++)
    {
        if(isalpha(str[i]))
        {


            if(islower(str[i]))
            {
                if(str[i] + shift > 'z')
                {
                    shift -= 26;

                }
                else if(str[i] + shift < 'a')
                {

                    shift += 26;
                }
            }
            if(isupper(str[i]))
            {
                if(str[i] + shift > 'Z')
                {
                    shift -= 26;
                }
                else if(str[i] + shift < 'A')
                {

                    shift += 26;
                }
            }

            str[i] += shift;


        }



    }




}


