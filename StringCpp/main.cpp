#include <iostream>
#include <string.h>

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

    while (*curr != '\0')
    {
        j++;
        curr++;
    }
    j = j - 1;

    int i = 0;

    while (i != j)
    {

        char temp = x[i];
        x[i] = x[j];
        x[j] = temp;
        i++;
        j--;
    }
}
void DuplicateBitWise(char *x)
{
    long int H = 0;
    long int X = 0;

    char *curr = &x[0];

    while (*curr != '\0')
    {
        X = 1;
        int temp = *curr - 97;
        X = X << temp;
        if ((X & H) > 0)
        {
            std::cout << *curr << std::endl;
        }
        else
        {
            H = X | H;
        }
        curr++;
    }
}
void Compare(char *p, char *q)
{
    char *i = p;
    char *j = q;

    while (*i != '\0' && *j != '\0')
    {
        if (*i != *j)
        {
            break;
        }
        i++;
        j++;
    }
    if (*i == *j)
    {
        std::cout << "Equal" << std::endl;
    }
    else if (*i < *j)
    {
        std::cout << "1st string is less than second" << std::endl;
    }
    else
    {
        std::cout << "2nd string is less than first" << std::endl;
    }
}
bool isPalin(char *p)
{
    char *curr = &p[0];
    char *back = &p[0];

    while (*back != '\0')
    {

        back++;
    }
    back--;
    while (curr != back)
    {
        if (*curr != *back)
        {
            return false;
        }
        curr++;
        back--;
    }
    return true;
}
void Duplicates(char *p)
{
    int A[26];
    int i = 0;
    for (; i < 26; i++)
    {
        A[i] = 0;
    }
    char *curr = p;

    while (*curr != '\0')
    {
        int diff = *curr - 97;
        A[diff]++;
        curr++;
    }
    for (i = 0; i < 26; i++)
    {
        if (A[i] > 1)
        {
            char out = i + 97;
            std::cout << out << std::endl;
        }
    }
}
bool isAnagram(char *s, char *t)
{
    int SLength = strlen(s);
    int TLength = strlen(t);
    if (SLength != TLength)
    {
        return false;
    }
    int A[26] = {0};
    char *curr = &s[0];
    while (*curr != '\0')
    {
        SLength++;
        curr++;
    }
    curr = &t[0];
    while (*curr != '\0')
    {
        TLength++;
        curr++;
    }

    curr = &s[0];
    while (*curr != '\0')
    {
        int diff = *curr - 97;

        A[diff]++;

        curr++;
    }

    curr = &t[0];

    while (*curr != '\0')
    {
        int diff = *curr - 97;
        A[diff]--;
        curr++;
    }
    int i;
    for (i = 0; i < 26; i++)
    {
        if (A[i] != 0)
        {
            return false;
        }
    }
    return true;
}
void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}
void Permute(char *c, int i, int n)
{

    if (i == n - 1)
    {
        printf("%s\n", c);
        return;
    }
    for (int j = i; j < n; j++)
    {
        swap(&c[i], &c[j]);
        Permute(c, i + 1, n);
        swap(&c[i], &c[j]);
    }
}

int main()
{
    char x[] = "abc";
    Permute(&x[0], 0, 3);
    return 0;
}