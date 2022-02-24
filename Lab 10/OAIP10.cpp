#include <fstream>
#include <stdio.h>
#include <cwchar> 
#include <string.h>


char* InputString(char* string, int size)
{
    printf("Input the text (below 256 symbols): \n");
    while (getchar() != '\n');
    return fgets(string, size, stdin);
}

void s1()
{
    char input[256];

    InputString(input, 256);

    int beg = 0;
    int end = strlen(input)-2;

    while (beg < end) {
        

        if (input[beg] != input[end]) {
            printf("The following line is not a palindrom.\n");
            break;
        }
        else
        {
            beg++;
            end--;
            if (input[beg] == ' ')
                beg++;
            if (input[end] == ' ')
                end--;
        }
    }

    if (beg >= end)
        printf("The following line is a palindrom.\n");
}

void s2() {

    int count=0;
    char input[256];

    InputString(input, 256);
    char* text = new char[strlen(input) + 2];
    strcpy_s(text, strlen(input) + 2, input);
    text[strlen(input) - 1] = ' ';
    text[strlen(input)] = '\n';
    text[strlen(input) + 1] = '\0';


    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            if (text[i - 1] == 'a')
                count++;
        }
    }

    printf("The number of words ending with 'a' is: %d",count);
    printf("\n");

    delete[] text;
}

void s3() {
    char input[256];

    InputString(input, 256);

   char* middle_name = strrchr(input, ' ');
   char* first_name = strchr(input, ' ');
    if (middle_name != NULL && middle_name != first_name)
    {
        printf( "Hi, %.*s %.*s\n", (int)(middle_name - first_name) - 1, first_name + 1,(int)(first_name - input),input);

    }
    else
    {
        printf("The input line is incorrect.\n");
    }
        
            
}

void s4() {
    char input[256];

    InputString(input, 256);

    for (int i = 0; i < strlen(input)-2; i += 2)
    {
        int t = input[i];
        input[i] = input[i + 1];
        input[i + 1] = t;
    }
    printf("The edited line is: %s", input);
    

}

void s5() {
    
    char input[256];

    InputString(input, 256);
    printf("Hi, %s",input);
}




int main()
{
    int s;
    for (;;)
    {
        printf("\t Choose the action: \n");
        printf("\t 1 - Check if the input line is a palindrom; \n");
        printf("\t 2 - Find the number of words in the line ending with 'a'.\n");
        printf("\t 3 - Input the name, surname and patronim. Output the greeting with name and surname.\n ");
        printf("\t 4 - Switch the symbols standing next to each other.\n");
        printf("\t 5 - Input the name. The program outputs the greeting with the name. \n");
        printf("\t 0 - Exit \n");

        scanf_s("%d", &s);
        switch (s) {

        case 1:
            s1();
            break;
        case 2:
            s2();
            break;
        case 3:
            s3();
            break;
        case 4:
            s4();
            break;
        case 5:
            s5();
            break;
        case 0:
            exit(1);
        }
    }
}

