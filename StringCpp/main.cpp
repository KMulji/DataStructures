#include <iostream>

int Length(char *p)
{
    int i = 0;
    while (*p != '\0')
    {
        p++;
        i++;
    }
    return i;
}
void ToUpper(char *p)
{
    while (*p != '\0')
    {
        if (*p >= 97 && *p <= 122)
        {
            *p -= 32;
        }
        p++;
    }
}
void ToLower(char *p)
{
    while (*p != '\0')
    {
        if (*p >= 65 && *p <= 90)
        {
            *p += 32;
        }

        p++;
    }
}
int VowelCount(char *p)
{
    int vowel = 0;
    while (*p != '\0')
    {
        if (*p == 'a' || *p == 'e' || *p == 'i' || *p == 'o' || *p == 'u' || *p == 'A' || *p == 'E' || *p == 'O' || *p == 'U')
        {
            vowel++;
        }
        p++;
    }
    return vowel;
}
int WordCount(char *p)
{
    int space = 1;
    while (*p != '\0')
    {
        if (*p == ' ')
        {
            space++;
        }
        p++;
    }
    return space;
}
void Reverse(char *x)
{
    int j = 0;
    char *curr = &x[0];

    while (*curr!='\0'){
        j++;
        curr++;
    }
    j=j-1;

    int i=0;

    while(i!=j){

        char temp = x[i];
        x[i]=x[j];
        x[j]=temp;
        i++;
        j--;
    }
}
int main()
{

    char x[] = "Hello";
    Reverse(&x[0]);
    char* curr = &x[0];

    while(*curr!='\0'){
        std::cout<<*curr<<std::endl;
        curr++;
    }
    return 0;
}