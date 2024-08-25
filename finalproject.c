#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
int calc(int wal, int bnmbr, int chsB, int *out_wal, int *out_pamount, int *out_sht){
    int i = 1;
        srand(time(NULL));
    int raam[3] = {0};
    for (int i = 0; i < 3; ++i) {
        raam[i] = rand() % 9 + 1;
    }
     
    int bwall = 0;
    if ( chsB == 1)
    {
        bwall = wal * 1;
    }else if (chsB == 2)
    {
        bwall = wal * 0.5;
    }else if (chsB == 3)
    {
        bwall = wal * 0.3;
    }
    
    
    int tmpwin = 0, sht = 0;
    for (i = 0; i < 3; i++)
    {
        if ( bnmbr == raam[i])
        {
            if ( i == 0)
            {
                tmpwin = bwall * 1;
                sht = i;
            }else if (i == 1)
            {
                tmpwin = bwall * 0.5;
                sht = i;
            }else if (i == 2)
            {
                tmpwin = bwall * 0.3;
                sht = i;
            }
            
            
            
        }
        
    }
    int pamount = bwall - tmpwin;
    *out_wal = wal + pamount;
    *out_pamount = pamount;
    *out_sht = sht;
    
}

int main()
{
    printf("\t\t Bet & Shoot Simulator");
    printf("\n\t 'Shoot For The Jackpot And Bet On Your Aim'");
    printf("\n\t __________________________________________");
    printf("\nINSTRUCTION:\n");
    printf("> You have been provided $100 in your wallet to bet for profit.\n");
    printf("> You can bet 100%%, 75%%, 50%% or 25%% from your wallet to progress\n");
    printf("> There are total nine(9) holes out of which three(3) contains targets to be shoot.\n");
    printf("> For Each Bet You Have One Bullet To Shoot\n");
    printf("> There are three(3) targets to shoot\n");
    printf("\n1. Hamster(for 100%% profit)\n2. Rabbit(for 50%% profit)\n3. Snake(for 30%% profit)\n");
    printf("Press 'P' to Start The Game\n");
    printf("Press 'E' to Exit The Game\n");
    char chs;
    scanf("%c", &chs);
    if( chs == 'E' || chs == 'e'){
        return 0;
    }else if (chs == 'P' || chs == 'p')
    {
       
        /*Prograam manwana haiii */
        int i = 0, j = 0;
        int holes[3][3]={1,2,3,4,5,6,7,8,9};
        printf("\n");
        
        for( i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                printf("\t_\t\t");
            }
            printf("\n");
            printf("\n");
            for ( j = 0; j < 3; j++)
            {
                printf("|\t");
                printf("%d\t", holes[i][j]);
                printf("|\t");
            }
            printf("\n");
                        
        }
        printf("\n");
        for (j = 0; j < 3; j++)
        {
            printf("\t_\t\t");
        }
        printf("\n");
        printf("\n");
        printf("\n");
        int wall = 100;
        printf("\nCurrent Balance: %d $\n", wall);
        printf("*******************************\n");
        printf("Make a Choise amoung 1 to 9 : ");
        int betNbr, prsnt;
        scanf("%d", &betNbr);
        
        printf("Select Your Bet Amount");
        printf("\n1. 100%% \n2. 50%% \n3. 30%%\n: ");
        scanf("%d", &prsnt);
        while (prsnt > 3)
        {


          if ( prsnt > 3) 
            {
                printf("** Invalid Input **");
                printf("\n1. 100%% \n2. 50%% \n3. 30%%\n: ");
                scanf("%d", &prsnt);

            }else{
        
                break;
            }


        }
        int out_wal, out_pamount, out_sht;
        int wal = wall, bnmbr = betNbr, chsB = prsnt;
        calc(wal, bnmbr, chsB, &out_wal, &out_pamount, &out_sht);
        char name[100];
        if (out_sht == 0) {
            strcpy(name, "Hamster");
        } else if (out_sht == 1) {
            strcpy(name, "Rabbit");
        } else if (out_sht == 2) {
            strcpy(name, "Snake");
        }
        
        
        printf("----------------------------------------------------\n");
        printf("Current Balance: %d, Profit: %d, You shoot: %s\n", out_wal, out_pamount, name);
        printf("----------------------------------------------------\n");
    }else{
        printf("Read the Instruction properly");
    }
    
    return 0;
}