/*Bengali, or Bangla, is an Indo-Aryan
language spoken predominantly in Bangladesh and in the Indian
states of West Bengal and Tripura by approximately 200 million
people. The language has a rich literary heritage and underwent
a renaissance in the late 19th century.#
*/
#include<stdio.h>
#include<string.h>
void con(char f[],char s[],int i,int j){
	int c=0;
	while(i<=j){
		f[c]=s[i];
		i++;
		c++;
	}
	f[c]='\0';
}
int checkArticle(char s[],int i,int j){
	if((j-i)>2)
		return 0;
    char *a1="a",*a2="an",*a3="the",*a4="A",*a5="An",*a6="The";
    char temp[4];
    con(temp,s,i,j);
    printf("%s\n",temp);
	if(strcmp(temp,a1)==0||strcmp(temp,a2)==0||strcmp(temp,a3)==0||strcmp(temp,a4)==0||strcmp(temp,a5)==0||strcmp(temp,a6)==0){
		return 1;
	}
    else
        return 0;
}
int checkUpper(char s[],int i){
    if(s[i]>=65 && s[i]<=90)
        return 1;
    else
        return 0;
}
void countArticles(char s[],int len){
    int i=0,j;
    int article=0,upper=0;
    while(s[i]!='#'){
    while(!((s[i]>=65&&s[i]<=90)||(s[i]>=97&&s[i]<=122)||(s[i]>=48&&s[i]<=57)))
        i++;
//	printf("%d\n",i);
    j=i;
    while(s[j]!=' '&&s[j]!=','&&s[j]!='.'&&s[j]!='-')
        j++;
//    printf("%d\n",j);
    if(checkArticle(s,i,j-1))
        article++;
    else if(checkUpper(s,i))
        upper++;
//    else if(checkUpper(s,i))
//        upper++;
    if(j+1>=len)
        break;
    i=j+1;
    }
    printf("Article count %d\n",article);
    printf("Uppercase letters %d\n",upper);
}
int main(){
    char str[500]="The Jadavpur University is the best university in the World And I feel proud of it.";
    puts(str);
    countArticles(str,strlen(str));
    return 0;
}
