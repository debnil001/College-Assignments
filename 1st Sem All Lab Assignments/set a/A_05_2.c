#include <stdio.h>

void notesRequired(int *, int *, int ,int );

int main()
{
    int notes[] = {100, 50, 20, 10};
    int notesNeeded[4] = {0};
    int notesCount = 4;
    int amount = 0;
    int *res;
    printf("Enter the amount: ");
    scanf("%d", &amount);

    notesRequired(notes, notesNeeded, amount, notesCount);
    
    for(int i=0;i<notesCount;i++) {
        printf("\n Notes required of %d is %d", notes[i], notesNeeded[i]);
    }
    return 0;
}

void notesRequired(int *notes, int *notesNeeded, int amount, int notesCount)
{
    int rem = 0;
    for(int i=0;i<notesCount;i++) {
        rem = amount / notes[i];
        if(rem == 0)
            continue;
        notesNeeded[i] = rem;
        amount = amount % notes[i];
    }
    if(amount > 0)
        notesNeeded[notesCount-1]++;
}