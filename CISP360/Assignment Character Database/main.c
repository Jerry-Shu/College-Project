// -----------------------------------------------------------------------
// monsterdb.c
// -----------------------------------------------------------------------
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// -----------------------------------------------------------------------
// Some defines
#define NAME_MAX 64
#define BUFFER_MAX 256




// -----------------------------------------------------------------------
// Structs

typedef struct
{
    char name[NAME_MAX];
    int hp;
    int attackPower;
    int armor;
} Character;

typedef struct
{
    int size;
    Character *list;
} CharacterContainer;

// -----------------------------------------------------------------------
// Function prototypes

void printCharacters(CharacterContainer *characters);
void sortCharacters(CharacterContainer *characters);
Character inputCharacter();
void inputCharacters(CharacterContainer *characters);
void readDb(CharacterContainer *characters, char *fileName);
void writeDb(CharacterContainer *characters, char *fileName);

// -----------------------------------------------------------------------
// Main Program

int main()
{
    CharacterContainer characters = {0, NULL};
    char fileName[BUFFER_MAX];
    char userIn[BUFFER_MAX];

    printf("Menu:\n(i)nput Characters\n(w)rite Character file\n(r)ead Character file\n");
    printf("(s)ort current list of Characters\n(p)rint current list of Characters\n(q)uit\n");
    scanf("%s", userIn);

    while(userIn[0] != 'q')
    {
        switch(userIn[0])
        {
        case 'i':
            inputCharacters(&characters);
            break;

            case 'w':
            printf("Name of output file: ");
            scanf("%s", fileName);
            writeDb(&characters, fileName);
            break;


            case 'r':
            printf("Name of input file: ");
            scanf("%s", fileName);
            readDb(&characters, fileName);
            break;


            case 's':
            sortCharacters(&characters);
            break;
            case 'p':
            printCharacters(&characters);
            break;
            default:
            printf("Error.  Invalid menu choice.\n");
            break;

         }
            printf("Menu:\n(i)nput Characters\n(w)rite Character file\n(r)ead Character file\n");
            printf("(s)ort current list of Characters\n(p)rint current list of Characters\n(q)uit\n");
            scanf("%s", userIn);
    }



        return 0;
}



// -----------------------------------------------------------------------
// Function implementations

    void printCharacters(CharacterContainer *characters)
    {
        for (int i = 0; i < characters->size; i++)
        {
            printf("%s [hp:%d, attack power:%d, armor:%d]\n",
                   characters->list[i].name,
                   characters->list[i].hp,
                   characters->list[i].attackPower,
                   characters->list[i].armor);
        }
    }

    void sortCharacters(CharacterContainer *characters)
    {
        Character temp;
        Character* arr = characters->list;

        // Insertion Sort Algorithm...
        for (int i = 1; i < characters->size; i++)
        {
            int j = i;
            while (j >= 1 && (strcmp(arr[j].name, arr[j - 1].name) < 0)) ///compare adjacent names with strcmp
            {
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
                j--;
            }
        }
    }


    Character inputCharacter()
    {
        Character ch;
        printf("Name: ");
        scanf("%s", &ch.name);
        printf("HP: ");
        scanf("%d", &ch.hp);
        printf("Attack power: ");
        scanf("%d", &ch.attackPower);
        printf("Armor: ");
        scanf("%d", &ch.armor);
        return ch;
    }

    void inputCharacters(CharacterContainer *characters)
    {
        int  i;
        printf("Enter number of Characters: ");

        ///input integer into the struct
        scanf("%d",&characters->size);

        ///if the list is not NULL, free it to prevent memory leaks
        if(characters->list != NULL)
        {
            free(characters->list);
        }

        printf("Allocating heap for %d Characters...", characters->size);
        ///allocate the list
        characters->list = (Character *)malloc(sizeof(Character) * characters->size);
        printf("\n");
        for(i = 0; i < characters->size; i++)
        {

            characters->list[i] = inputCharacter();

        }



        ///loop through each Character in the list, assign the return value from inputCharacter to the ith element

    }

    void readDb(CharacterContainer *characters, char *fileName)
    {

        FILE* f = NULL;

        ///Open the file in read binary mode
         f = fopen(fileName,"rb");
        ///make sure it successfully opened
        if(f == NULL)
        {
             printf("Could not open file %s.bin.\n", fileName);
                return -1;
        }

        int nItems = fread(&characters->size, sizeof(int), 1, f);
        printf("%d items read from '%s' (size header)\n", nItems, fileName);

        ///if the list is not NULL, free it to prevent memory leaks
        if(characters->list != NULL)
        {
            free(characters->list);
        }

        printf("Allocating heap for %d Characters...", characters->size);

        ///allocate the list

        characters->list = (Character *)malloc(sizeof(Character) * characters->size);

        nItems = fread(characters->list, sizeof(Character), characters->size, f);
        printf("%d Characters read from '%s' (Character array)\n", nItems, fileName);
        fclose(f);
    }





    void writeDb(CharacterContainer *characters, char *fileName)
    {
        FILE* f = NULL;

        ///Open the file in write binary mode
        f = fopen(fileName,"wb");
        ///make sure it successfully opened
        if(f == NULL)
        {
             printf("Could not open file %s.bin.\n", fileName);
                return -1;
        }

        int nItems = fwrite(&characters->size, sizeof(int), 1, f);
        printf("%d items written to '%s' (size header)\n", nItems, fileName);
        nItems = fwrite(characters->list, sizeof(Character), characters->size, f);
        printf("%d items written to '%s' (Character array)\n", nItems, fileName);
        fclose(f); //make sure to close here or writes may not finish!
    }



// -----------------------------------------------------------------------

