#include<stdio.h>


int getValue(char c){
  if (c =='I') return 1;
  else if (c =='V') return 5;
  else if (c =='X') return 10;
  else if (c =='L') return 50;
  else if (c =='C') return 100;
  else if (c =='D') return 500;
  else if (c =='M') return 1000;
  return 0;
  
}

int romanToInt(char *s){
  int sum = 0;
  int p=0;
  for (int i=0;s[i]!='\0';i++) {
   if(i>0){
    p=i-1;
   }
   
  }
  printf("%d\n",sum);
  return sum;

}

int main()
{
  char *s;
  fgets(s, sizeof(s), stdin);

  romanToInt(s);
  return 0;
}
