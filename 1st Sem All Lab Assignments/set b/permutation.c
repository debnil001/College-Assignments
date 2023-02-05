#include<stdio.h>
void swap(char *ch,int l,int r){
    char temp=*(ch+l);
    *(ch+l)=*(ch+r);
    *(ch+r)=temp;
}
void permute(char *p,int start,int end){
    if(start==end){
        printf("%s ",p);
        return;
    }
    for(int i=start;i<=end;i++){
        swap(p,start,i);
        permute(p,start+1,end);
        swap(p,start,i);
    }
}
void main(){
    char p[]="abc";
    // swap(p,0,2);
    // printf("%s",p);
    permute(p,0,2);
}