#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(void){
  char phrase[80];
  char newphrase[80];
  int size = 0, d = 0;
  int lowervocal[5] = {97, 101, 105, 111, 117};
  bool outputsms = true;

  //printf("\n----Vocales---");
  //printf("\n Ingrese una frase corta\n\t: ");
  scanf("%s", phrase);

  size = strlen(phrase);

  for(int i = 0; i < size; i++)
  {
    char temp;
    int ascii;
    bool verify = false;
    if(isalpha(phrase[i]))
    {  // Check if it is a letter

      for(int j = 0; j < 5; j++)
      {
        temp = tolower(phrase[i]);  //_Transform the letter to uppercase_
        ascii = (int)temp;

        if(ascii == lowervocal[j]){
          verify = true;
          break;
        }
        else{
          verify = false;
        }
          //printf("%c", newphrase[i]);
      }
      if(!verify){
        newphrase[d] = phrase[i]; // remove all vocals into string
        d++;
      }

    }
    else
    {
      printf("El texto no debe contener numeros.");
      outputsms = false;
      break;
      //exit(-1);
    }
  }
  if(outputsms){
    printf("Output: %s\n", newphrase);
  }

  return 0;
}