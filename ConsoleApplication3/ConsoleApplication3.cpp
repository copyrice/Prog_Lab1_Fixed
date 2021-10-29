#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;



char* myStrcpy(char* b, char* str2)
{
    int i;
    for (i = 0; str2[i]; i++) b[i] = str2[i];
    b[i] = '\0';
    return b;
}

/*char* mystrcpy1(char* dest, const char* source)
{
    while (*dest++ = *source++)
        ;
    return dest;
} */


int main()
{
    char s[] = "wow, hello world";
    char c[sizeof(s)];
    char str[] = "www.some_address";
    char z[sizeof(str)];

    strcpy(c, s);
    //cout << c << endl;
    for (int i = 0; i<sizeof(c); i++)
    {
        printf("%c", c[i]);
    }
    printf("%s", "\n");

    myStrcpy(z, str);
    //cout << z;
    for (int i = 0; i < sizeof(c); i++)
    {
        printf("%c", z[i]);
    }
    return 0;
}

