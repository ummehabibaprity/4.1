#include<stdio.h>
#include<stdbool.h>
#include<string.h>
int global=0;
int i,j;
bool isDel(char c)
{
if(c==';'||c==','||c=='\"' || c=='{' || c=='}' || c=='[' || c==']' || c=='('
|| c==')'){
return true;
}
return false;
}
bool isOp(char c)
{
if(c=='+' || c=='-' || c=='*' || c=='/' || c=='=' ||
c=='>' || c=='<' || c=='!' || c=='%' || c=='&' || c=='|')
return true;
return false;
}
int isKeyWord(char lexemes[])
{
if(strcmp(lexemes,"int")==0){
return 1;
}
else if(strcmp(lexemes,"char")==0){
return 2;
}
else if(strcmp(lexemes,"float")==0){
return 3;
}
else if(strcmp(lexemes,"double")==0){
return 4;
}
else if(strcmp(lexemes,"void")==0){
return 5;
}
else if(strcmp(lexemes,"main")==0){
return 6;
}
else if(strcmp(lexemes,"for")==0){
return 7;
}
else if(strcmp(lexemes,"while")==0){
return 8;
}
else if(strcmp(lexemes,"if")==0){
return 9;
}
else if(strcmp(lexemes,"else")==0){
return 10;
}
else if(strcmp(lexemes,"return")==0){
return 11;
}
else{
return 0;
}
}
bool isId(char lexemes[])
{
if(lexemes[0]=='_' || (lexemes[0]>='a' && lexemes[0]<='z') ||
(lexemes[0]>='A' && lexemes[0]<='Z')){
int i=1;
for(;i<strlen(lexemes); i++){
if(!(lexemes[i]=='_' || (lexemes[i]>='a' && lexemes[i]<='z')
|| (lexemes[i]>='A' && lexemes[i]<='Z') || (lexemes[i]>='0' &&
lexemes[i]<='9'))){
return false;
}
}
return true;
}
else
return false;
}
bool lap(char lexemes[], int i)
{
while(i<strlen(lexemes)){
if(!(lexemes[i]>='0' && lexemes[i]<='9'))
return false;
i++;
}
global=2;
return true;
}
bool lbp(char lexemes[])
{
int i=1;
while(i<strlen(lexemes)){
if(lexemes[i]=='.'){
return lap(lexemes,i+1);
}
else if(!(lexemes[i]>='0' && lexemes[i]<='9')){
return false;
}
else
i++;
}
global=1;
return true;
}
bool isNum(char lexemes[])
{
if(lexemes[0]>='0' && lexemes[0]<='9'){
return lbp(lexemes);
}
else if(lexemes[0]=='.'){
return lap(lexemes,1);
}
else
return false;
}
bool isChar(char lexemes[])
{
if(lexemes[0]=='\''){
if(lexemes[2]=='\'' || lexemes[1]=='\'')
return true;
else
return false;
}
return false;
}
int main()
{
FILE *fp_read1, *fp_read2, *fp_write;
char c, sep, op;
char lexemes[100];
int i=0, s=0, d=0, err=0, k=0;
char errors[100][100];
fp_read1=fopen("symbolTable.txt","r");
fp_read2=fopen("tokens.txt","r");
fp_write=fopen("output.txt","w");
printf("Input: \n");
while((c=fgetc(fp_read2))!=EOF){
printf("%c",c);
}
printf("\n");
printf("\nOutput: \n");
while((c=fgetc(fp_read1))!=EOF){
i=d=0;
sep=op=' ';
while(c!=' '){
if(isDel(c)){
d=1;
sep=c;
break;
}
else if(isOp(c)){
d=1;
op=c;
break;
}
lexemes[i]=c;
i++;
c=fgetc(fp_read1);
}
lexemes[i]='\0';
s=0;
if((s=isKeyWord(lexemes))>0){
switch(s){
case 1:{
printf("[kw %s]", lexemes);
//fputc()
break;
}
case 2:{
printf("[kw %s]", lexemes);
break;
}
case 3:{
printf("[kw %s]", lexemes);
break;
}
case 4:{
printf("[kw %s]", lexemes);
break;
}
case 5:{
printf("[kw %s]", lexemes);
break;
}
case 6:{
printf("[kw %s]", lexemes);
break;
}
case 7:{
printf("[kw %s]", lexemes);
break;
}
case 8:{
printf("[kw %s]", lexemes);
break;
}
case 9:{
printf("[kw %s]", lexemes);
break;
}
case 10:{
printf("[kw %s]", lexemes);
break;
}
case 11:{
printf("[kw %s]", lexemes);
break;
}
}
}
else if(isId(lexemes)){
printf("[id %s]", lexemes);
}
else if(isNum(lexemes)){
if(global==1)
printf("[in %s]", lexemes);
else
printf("[fn %s]", lexemes);
global=0;
}
else if(isChar(lexemes)){
printf("[char %s]", lexemes);
}
else{
if(i>0){
printf("[unkn %s]", lexemes);
err=1;
int j=0;
for(; j<strlen(lexemes); j++)
errors[k][j]=lexemes[j];
errors[k][j]='\0';
k++;
}
}
if(d){
if(sep!=' ')
printf("[sep %c]",sep);
else{
printf("[op %c]",op);
}
}
}
if(err){
printf("\n\nErrors:\n");
for( i=0; i<k; i++){
for( j=0; errors[i][j]!='\0'; j++){
printf("%c",errors[i][j]);
}
printf(" unrecognized token\n");
}
}
return 0;
}
