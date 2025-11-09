#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


size_t strtosize_t(char const *str)
{
  int len = strlen(str);
  size_t x = 0;
  int i;
  for (i = 0; i < len; i++)
    if (isdigit(str[i]))
    {
      x += str[i] - '0';
    }
  return x;
}


int strtodouble(char const * str, double *d)
{
  size_t whereispoint = 0;
  char * beforepoint = 0;
  char * afterpoint = 0;
  double result = 0;
  size_t len = strlen(str);


  // Finding the size of whole number and making the array for it

  for (int i = 0; ; i++)
  {
    if (str[i] == '.')
    {
      whereispoint = i;
      break;
    }
  }


  // if there is no point, working like with usual int

  if (whereispoint == 0)
  {
    int x = 0;
    for (int i = 0; i < len; i++)
      if (isdigit(str[i]))
      {
        x += str[i] - '0';
      }
  }


  // if point exist, starting to allocate memory for before and after point nums

  else
  {
    beforepoint = (char *)malloc(whereispoint * sizeof(char));
    if (beforepoint == NULL)
    {
      return -1;
    }
    afterpoint = (char *)malloc((len - whereispoint) * sizeof(char));
    if (afterpoint == NULL)
    {
      free(beforepoint);
      return -2;
    }


    // adding data to before and after point nums vars
    for (int i = 0; i < whereispoint; i++)
    {
      beforepoint[i] = str[i];
    }
    for (size_t i = whereispoint; i < len; i++)
    {
      afterpoint[i] = str[i];
    }


    // making the final result by using the powers of number digits
    double firstnumpart = 0;
    double secondnumpart = 0;
    for (int i = 0; i < whereispoint; i++)
      if (isdigit(beforepoint[i]))
      {
        firstnumpart = firstnumpart * 10 + (str[i] - '0');
      }
    for (int j = len; j > whereispoint; j--)
      if (isdigit(afterpoint[j]))
      {
        secondnumpart = (secondnumpart + (str[j] - '0')) / 10;
      }

    result = firstnumpart + secondnumpart;
    *d = result;
    free(beforepoint);
    free(afterpoint);
    return 1;
  }
}




int main(int argc, char * argv[])
{
  size_t n;
  double dot;
  double y;
  double total;
  int i;

  if (argc < 4)
  {
    printf("Error! To little arguments.\n");
    return -1;
  }

  n = strtosize_t(argv[2]);
  strtodouble(argv[1], &dot);
  strtodouble(argv[3], &total);

  // 3.4 = 2.5x**2 + 5.7
  for (i = 4; i < argc; i++)
  {
    strtodouble(argv[i], &y);
    total = total * dot + y;
  }

  printf("The answer is: %lf\n", total);
  return 0;
}
