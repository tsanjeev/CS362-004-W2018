#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this 
    //ascii number for space
    int min = 32;
    //ascii number for ~
    int max = 126;
    //random ascii char between space and ~
    int charNum = (rand()% (max - min + 1) + min);
    return charNum;
}

char *inputString()
{
    // TODO: rewrite this function
    // lowercase a
    int min = 97;
    // lowercase z
    int max = 122;
    //random charbetween a - z
    int charNum;
    // string length is reset + '\0 = 6'
    int strLen = 6;
    char *ranString = malloc(strLen);
    
    //create random string of 5 chars
    int i;
    for(i = 0; i < strLen-1; i++)
    {
      charNum =(rand()% (max - min + 1) + min);
      ranString[i] = charNum;
    }
    ranString[i] = '\0';
    return ranString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error\n");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
