#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    int randChar=(rand() % 94) + 32;//ASCII code from 32 to 125, 32 is space, 125 is }
    return randChar;
}

char *inputString()
{
    char static randString[6];   //string will store a string with 6 characters
    int i;
    for (i =0; i <6; i++)//fill the string with r,s,t,e and null
    {
      int d=(rand()%6);
      if(d==1)
        randString[i]='r';
      else if(d==2)
        randString[i]='s';
      else if(d==3)
        randString[i]='t';
      else if(d==4)
        randString[i]='e';
      else if(d==5)
        randString[i]=0;      
    }
    return randString;
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
