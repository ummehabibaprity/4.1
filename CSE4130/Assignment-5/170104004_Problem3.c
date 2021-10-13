#include<stdio.h>
#include<string.h>
#include<stdbool.h>
bool stat(char *input);
bool loop_stat(char *input);
bool dcsn_stat(char *input);
bool asgn_stat(char *input);
bool expn(char *input);
bool smpl_expn(char *input);
bool extn(char *input);
bool term(char *input);
bool factor(char *input);
bool id(char *input);
bool num(char *input);
bool extn1(char *input);
int i;
int main()
{
   char input[100];
   printf("Enter a string to Parse: ");
   scanf("%s",&input);

   if(stat(input)){ printf("\nValid String\n"); }
   else{ printf("\nInvalid String\n");}

   return 0;
}

bool asgn_stat(char *input)
{
   char newx[100]; int c = 0;
   char x[5];
   x[0] = input[0];//first char
   if(id(x)){//id check
      if(input[1] == '='){
         for( i=2; i<strlen(input); i++){
            newx[c++] = input[i];//copy full length
         }
         newx[c] = '\0';
         if(expn(newx)){
            return true;
         }
      }
   }
   return false;
}

bool dcsn_stat(char *input)
{

   char x[100], y[100], z[100]; int c1 = 0, c2 =0, c3 = 0;
   if(input[0] == 'i' && input[1] == 'f' && input[2] == '('){
      int i = 3;
      while(1){
         x[c1++] = input[i];
         i++;
         if(input[i] == ')'){break;}
      }
      x[c1] = '\0';
      i++;
      if(expn(x)){
         while(1){
            y[c2++] = input[i];

            i++;
            if(input[i] == 'e' && input[i+1] == 'l' && input[i+2] == 's' && input[i+3] == 'e'){break;}
         }
         y[c2] = '\0';
         if(stat(y)){
            while(1){
               z[c3++] = input[i];

               i++;
               if(i >= strlen(input)){break;}
            }
            z[c3] = '\0';
            if(extn1(z)){
               return true;
            }
         }
      }
   }

   return false;
}

bool loop_stat(char *input)
{
   char x[100], y[100], z[100], p[100]; int c1 = 0, c2 = 0, c3 =0, c4 = 0;
   if(input[0] == 'w' && input[1] == 'h' && input[2] == 'i' && input[3] == 'l' && input[4] == 'e' && input[5] == '('){
      int i = 6;
      while(1){
         x[c1++] = input[i];
         i++;
         if(input[i] == ')'){break;}
      }
      x[c1] = '\0';
      i++;
      if(expn(x)){
         while(1){
            y[c2++] = input[i];
            i++;
            if(i >= strlen(input)){break;}
         }
         y[c2] = '\0';
         if(stat(y)){return true;}
      }
   }
   else if(input[0] == 'f' && input[1] == 'o' && input[2] == 'r' && input[3] == '('){
      int i = 4;
      while(1){
         x[c1++] = input[i];
         i++;
         if(input[i] == ';'){break;}
      }
      x[c1] = '\0';
      i++;
      if(asgn_stat(x)){
         while(1){
            y[c2++] = input[i];
            i++;
            if(input[i] == ';'){break;}
         }
         i++;
         y[c2] = '\0';
         if(expn(y)){
            while(1){
               z[c3++] = input[i];
               i++;
               if(input[i] == ')'){break;}
            }
            i++;
            z[c3] = '\0';
            if(asgn_stat(z)){
               while(1){
                  p[c4++] = input[i];
                  i++;
                  if(i>=strlen(input)){break;}
               }
               p[c4] = '\0';
               if(stat(p)){return true;}
            }
         }
      }
   }
   else{
      return false;
   }
}

bool expn(char *input)
{
   char x[100], y[100]; int c1 = 0, c2 = 0, turn = 1;
   for( i=0; i<strlen(input); i++){
      if( (input[i] == '=' && input[i+1] == '=') || (input[i] == '!' && input[i+1] == '=') || (input[i] == '>' && input[i+1] == '=') || (input[i] == '<' && input[i+1] == '=') ){
         turn = 2;
      }
      else if(input[i] == '>' || input[i] == '<'){
         turn = 2;
      }
      if(turn == 1){
         x[c1++] = input[i];
      }
      else if(turn == 2){
         y[c2++] = input[i];
      }

   }
   x[c1] = '\0';
   y[c2] = '\0';
   if(smpl_expn(x) && extn(y)){ return true;}
   else{ return false;}
}

bool smpl_expn(char *input)
{
   char x[100], y[100]; int c1 = 0, c2 = 0, turn = 1;
   for( i=0; i<strlen(input); i++){
      if( input[i] == '+' || input[i] == '-' ){
         turn = 2;
         i++;
      }
      if(turn == 1){
         x[c1++] = input[i];
      }
      if(turn == 2){
         y[c2++] = input[i];
      }
      else if(input[i] == '*' || input[i] == '/'){break;}
   }
   x[c1] = '\0';
   y[c2] = '\0';

   if(strlen(y) > 0){
      if(term(x) && term(y)){ return true;}
      else{ return false;}
   }
   else{
      if(term(x)){ return true;}
      else{ return false;}
   }
}

bool extn(char *input)
{
   char x[100]; int c1 = 0;
   if(strlen(input) == 0){return true;}
   if( (input[0] == '=' && input[1] == '=') || (input[0] == '!' && input[1] == '=') || (input[0] == '>' && input[1] == '=') || (input[0] == '<' && input[1] == '=')){
      for( i=2; i<strlen(input); i++){
         x[c1++] = input[i];
      }
   }
   else if(input[0] == '>' || input[0] == '<'){
      for( i=1; i<strlen(input); i++){
         x[c1++] = input[i];
      }
   }
   x[c1] = '\0';
   if(smpl_expn(x)){ return true;}
   return false;
}

bool term(char *input)
{
   char x[100], y[100]; int c1 = 0, c2 = 0, turn = 1;
   for( i=0; i<strlen(input); i++){
      if( input[i] == '*' || input[i] == '/' ){
         turn = 2;
         i++;
      }
      if(turn == 1){
         x[c1++] = input[i];
      }
      if(turn == 2){
         y[c2++] = input[i];
      }
      else if(input[i] == '+' || input[i] == '-'){break;}
   }
   x[c1] = '\0';
   y[c2] = '\0';
   if(strlen(y) > 0){
      if(factor(x) && factor(y)){ return true;}
      else{ return false;}
   }
   else{
      if(factor(x)){ return true;}
      else{ return false;}
   }

}

bool factor(char *input)
{
   if(strlen(input) > 1){
      if(smpl_expn(input)){return true;}
   }
   if(id(input) || num(input)){return true;}
   else{return false;}
}

bool id(char *input)
{
   if(input[0] == 'a' || input[0] == 'b' || input[0] == 'c' || input[0] == 'd' || input[0] == 'e'){ return true;}
   else{ return false;}
}

bool num(char *input)
{
   if(input[0] >= '0' && input[0] <='9'){return true;}
   else{ return false;}
}

bool stat(char *input)
{
   if(asgn_stat(input) || dcsn_stat(input) || loop_stat(input)){ return true; }
   else{ return false;}
}

bool extn1(char *input)
{
   char x[100], y[100]; int c1 = 0, c2 = 0;
   if(strlen(input) == 0){ return true;}
   for( i=4; i<strlen(input); i++){
      x[c1++] = input[i];
   }
   x[c1] = '\0';
   if(stat(x)){ return true;}

   return false;
}
/*
a=b*2+c/3
if(a>=b)
    d=d+1
else
    c=c+1
*/

