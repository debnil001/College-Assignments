#include<string.h>
#include<stdio.h>
void two(int num,char[]);
void three(int num,char[]);
char* ten(int);
char* one(int);  
char* lessThan20(int);
char* convertToIndian(int);
char* convertToInternational(int);
char resultIndian[500];
char iRes[500];
void main() {
        int number;
        printf("enter number::");
        scanf("%d",&number);
		
        printf("%s ",convertToIndian(number));

        printf("\n%s",convertToInternational(number));
}
char* convertToIndian(int num) {
        if(num==0)
            return "Zero";

        int crore=num/10000000;
        num=num%10000000;

        int lakh=num/100000;
        num=num%100000;
        
        int thousand=num/1000;
        num=num%1000;        
        
        if(crore!=0){
            strcat(resultIndian,one(crore));
            strcat(resultIndian," Crore ");
        }
        char lakhres[200];
        if(lakh!=0){
            two(lakh,lakhres);
            strcat(resultIndian,lakhres);
            strcat(resultIndian," Lakh ");
        }
        char thou[200];
        if(thousand!=0){
        	two(thousand,thou);
        	strcat(resultIndian,thou);
            strcat(resultIndian," Thousand ");
        }
        char hun[200];
        if(num!=0){
        	three(num,hun);
//            three(num,resultIndian);
			strcat(resultIndian,hun);
        }
        return resultIndian;
}
char* convertToInternational(int num) {
       
       if(num==0)
           return "Zero";
       
       int million=num/1000000;
       num=num%1000000;
       
       int thousand=num/1000;
       num=num%1000;
       
       char mill[200];
       if(million!=0)
       {
           two(million,mill);
           strcat(iRes,mill);
           strcat(iRes," Million ");
       }
       char thou[200];
       if(thousand!=0)
       {
           three(thousand,thou);
           strcat(iRes,thou);
           strcat(iRes," Thousand ");
       }
       
       if(num!=0)
       {
           three(num,iRes);
       }
       
       return iRes;
   }
   

void three(int num,char r[]){
        if(num==0)
            strcat(r,"");
        
        int hundred=num/100;
        int result=num%100;
        
        if(result!=0 && hundred!=0){
            strcat(r,one(hundred));
            strcat(r," Hundred ");
            two(result,r);
        }
        else if(result==0 && hundred!=0){
        	strcat(r,one(hundred));
            strcat(r," Hundred ");
        }
        else{
            two(result,r);
        }
}

void two(int num,char r[]){
        if(num<10)
        {
        	strcat(r,one(num));

        }
        else if(num<20)
        {
        	strcat(r,lessThan20(num));
        }
        else{
        int tenner=num/10;  //digit at ten's place
        int result=num%10;
        
        if(tenner!=0 && result!=0){
            strcat(r,ten(tenner));
            strcat(r," ");
            strcat(r,one(result));
        }
        else if(tenner!=0 && result==0)
        {
        	strcat(r,ten(tenner));
        }
		else
		strcat(r,one(result));
		}
}   
char* one(int num){
        switch(num)
        {
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";            
        }
        return "";
}
char* ten(int num){
        switch(num){
            case 2: return "Twenty";
            case 3: return "Thirty";
            case 4: return "Forty";
            case 5: return "Fifty";
            case 6: return "Sixty";
            case 7: return "Seventy";
            case 8: return "Eighty";
            case 9: return "Ninety";            
        }
        return "";
}    
char* lessThan20(int num){
        switch(num)
        {
            case 10: return "Ten";
            case 11: return "Eleven";
            case 12: return "Twelve";
            case 13: return "Thirteen";
            case 14: return "Fourteen";
            case 15: return "Fifteen";
            case 16: return "Sixteen";
            case 17: return "Seventeen";
            case 18: return "Eighteen";
            case 19: return "Nineteen";            
        }
        return "";
}
