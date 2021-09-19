#include <stdio.h>
#include "_string.h"  ///this must be included

size_t strlen(const char* str);
int strcmp(const char* str1, const char* str2);
char* strcpy(char* dest, const char* src);
char* strncpy(char* dest, const char* src, size_t n);
char* strcat(char* dest, const char* src);
char* strncat(char* dest, const char* src, size_t n);
const char* strchr(const char* str, int c);
const char* strrchr(const char* str, int c);


const char* strstr(const char* str1, const char* str2);
int isalnum(int c );

int main(void)
{
    char h[10] = "Jerry";
    char g[10] = "729";
    strcat(h,g);
    printf("%s", h);







}  ///Add your own unit tests here.  When uploading, you can leave it blank.

///Server unit testers will only tell you if it failed or not
///Unit test your own code and study the specifications provided in the description
size_t strlen(const char* str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] != '\0')
        {

            i++;

        }

    }


    return i;


}


int strcmp(const char* str1, const char* str2)
{
    int i = 0;
    int R = 0;  //return value;
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    if(len_str1 < len_str2)
    {
        while(i < len_str1)
        {
            if(str1[i] > str2[i])
            {
                R = 1;
                return R;

            }
            else if(str1[i] < str2[i])
            {
                R = -1;
                return R;

            }
            else
            {
                if(i == len_str1 - 1)
                {
                    R = -1;
                    return R;

                }
                i++;

            }


        }


    }
    else if(len_str1 > len_str2)
    {
        while(i < len_str2)
        {
            if(str1[i] > str2[i])
            {
                R = 1;
                return R;

            }
            else if(str1[i] < str2[i])
            {
                R = -1;
                return R;

            }
            else
            {
                if(i == len_str2 - 1)
                {
                    R = 1;
                    return R;

                }
                i++;

            }


        }
    }
    else if(len_str1 == len_str2)
    {
        while(i < len_str2)
        {
            if(str1[i] > str2[i])
            {
                R = 1;
                return R;

            }
            else if(str1[i] < str2[i])
            {
                R = -1;
                return R;

            }
            else
            {
                if(i == len_str1 - 1)
                {
                    R = 0;
                    return R;

                }
                i++;

            }


        }




    }
}




char* strcpy(char* dest, const char* src)
{
    if ((dest != NULL) && (src != NULL))
    {



        while(*src != '\0')
        {
            *dest = *src;
            dest++;
            src++;


        }

        *dest = *src;
        return dest;
    }


}


char* strncpy(char* dest, const char* src, size_t n)
{
    int i = 0;


    if((dest != NULL )&&(src != NULL))
    {

        for(i = 0; (i < n) && (src != '\0'); i++)
        {
            *dest = *src;
            dest++;
            src++;

        }

        return dest;
    }







}


char* strcat(char* dest, const char* src)
{

    if((dest != NULL) && (src != NULL))
    {


        while(*dest != '\0')
        {
            dest++;

        }
        while(*src != '\0')
        {
            *dest = *src;
            dest++;
            src++;

        }
        *dest = '\0';
        return dest;






    }



}
char* strncat(char* dest, const char* src, size_t n)
{
   int i = 0;
   if((dest != NULL) && (src != NULL))
    {


        while(*dest != '\0')
        {
            dest++;

        }

        for(i = 0; i < n; i++)
        {
            *dest = *src;
            dest++;
            src++;
        }

        *dest = '\0';
        return dest;



    }



}



const char* strchr(const char* str, int c)
{


    while(*str != '\0')
    {
       if(*str == c)
       {
           return str;

       }
       else
       {
           str++;
       }



    }

    return NULL;




}
const char* strrchr(const char* str, int c)
{
     char *p = NULL;


    while(*str != '\0')
    {

        if(*str == c)
        {

            p = str;

        }
        str++;
    }

    return p;



}

///ststr is the hardest function.  It uses a tricky nested loop and must return an address.
///Here are some hints:
/// Loop thru str1, looking for the first char of str2
/// if(str1[i] == str2[0]) Then start inner loop, j=0
/// loop while str1[i+j] is not null and str2[j] is not null
/// inside loop, if(str1[i+j] != str2[j]) Then break out of inner loop
/// when inner loop completes, if(str2[j] == '\0') Then return &str1[i]
/// if outer loop completes, then return NULL
const char* strstr(const char* str1, const char* str2)
{
    int i;
    int j = 0;
    for(i = 0; i < strlen(str1);i++)
    {
        if(str1[i] == str2[0])
        {

                while((str1[i + j] != NULL) && (str2[j] != NULL))
                {

                      if( str1[i + j] != str2[j] )
                        {
                            break;

                        }
                    j++;



                }
                if(str2[j] == '\0')
                {

                    return &str1[i];
                }




        }



    }


    return NULL;




}
int isalnum(int c )
{

    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
        return 1;
    }
    else
    {

        return 0;
    }




}
