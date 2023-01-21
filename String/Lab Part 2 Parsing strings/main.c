#include<stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void)
{
    int i;
    char *first = NULL;
    char *second = NULL;

    char *p1 = NULL;
    char Input[50];
    char *start = NULL;
    start = p1;




    /* Type your code here. */
do{
    first = (char *)malloc(sizeof(char) * 50);
    second= (char *)malloc(sizeof(char) * 50);

    printf("Enter input string:\n");
    fgets(Input, 100, stdin);

    if(strcmp(Input, "q\n") == 0)
    {
        break;
    }
    if(strchr(Input, ',') == NULL)
    {
        printf("Error: No comma in string.\n");
        printf("\n");
        continue;

    }
    else
    {
        p1 = Input;


        while((*p1 != ',') && (*p1 != NULL))
        {
            if(*p1 != ' ')
            {
                first[i] = *p1;
                i++;
            }



            p1++;


        }



        printf("First word: ");
        printf("%s\n", first);

        p1++;
        i = 0;
        while((*p1 != ',') && (*p1 != NULL))
        {
            if(*p1 != ' ')
            {
                second[i] = *p1;
                i++;
            }

            p1++;


        }


        i = 0;
        printf("Second word: ");
        printf("%s\n",second);

        p1 = start;

        free(first);
        free(second);


        fflush(stdin);

    }
}while(1);










    return 0;
}
