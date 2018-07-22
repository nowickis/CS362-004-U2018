#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char inputChar()
{
    // TODO: rewrite this function
	char c;
	int lower = 32;
	int upper = 127;
	c = (rand() % (upper - lower + 1)) + lower;

   	 return c;
}

char *inputString()
{
    // TODO: rewrite this function
		int r = rand() % 10;
		if(r == 0){
			return "dog\0";
		}
		if(r == 1){
			return "cat\0";
		}
		if(r == 2){ 
			return "return\0";
		}
		if(r == 3){
			return "random\0";
		}
		if(r == 4){
			return "future\0";
		}
		if(r == 5){ 
			return "pizza\0";
		}
		if(r == 6) { 
			return "taco\0";
		}
		if( r == 7){ 
			return "prize\0";
		}
		if(r == 8){ 
			return "no\0";
		}


    return "reset\0";
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
