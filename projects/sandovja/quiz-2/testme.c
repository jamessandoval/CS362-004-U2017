#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

// Randomization function
char randChar(int min, int max) {

  int i; 
  
  i = min + rand() % (max - min);

  char c = i;

  //printf("the random value is: %c\n", c);
  return c;

}

char inputChar()
{

    // Using Ascii char table: 
    // values are 0 thru 127: total 128.
    int min = 1;
    int max = 128;
    char c;

    c = randChar(min, max);

    //printf("the random char is: %d\n", c);
    
    return c;
}

char *inputString()
{
    // make an array of strings 
    // 6 chars
    int size = 6;
    char string[size];
    int i;
    int min = 100;
    int max = 120;

    for(i = 0; i < 5;i++){  

        string[i] = randChar(min, max);
    }

        string[5] = '\0';

    printf("%s", string);

    return string;
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
      printf("error ");
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
