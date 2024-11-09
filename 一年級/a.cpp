#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define N 80
#define up 72
#define left 75
#define right 77
#define down 80

void run();
void yn();
void print(int [][N]);
void menu();

int scr[22][N]={0},pl=9,shit,width=70,score=0,death=0,jump_time=0,game_time=0,day=0,jump_height=0,shift_time=0;

int main(){
    menu();
    run();
    return 0;
}

void drawplayer(int a[][N],int xlu,int ylu){
    int i; 
	for( i=1;i<=3;i++)
        a[xlu][ylu+i]=1;
    for( i=0;i<=4;i++)
        a[xlu+1][ylu+i]=1;
    a[xlu+2][ylu+1]=1;
    a[xlu+2][ylu+3]=1;
}

bool search_player(int a[][N],int xlu,int ylu){
    int i;
	for( i=1;i<=3;i++)
        if(a[xlu][ylu+i]==2 || a[xlu][ylu+i]==3)
            return false;
    for( i=0;i<=4;i++)
        if(a[xlu+1][ylu+i]==2 || a[xlu+1][ylu+i]==3)
            return false;
    if(a[xlu+2][ylu+1]==2 || a[xlu+2][ylu+1]==3)
        return false;
    if(a[xlu+2][ylu+3]==2 || a[xlu+2][ylu+3]==3)
        return false;
    return true;
}

void days(int q,int a[][N]){
    int i,j;
	for( i=3;i<=7;i++){
        for( j=51;j<=55;j++){
            a[i][j]=0;
        }
    }
    if(q==1){
        a[4][52]=4;
        a[7][52]=4;
        int i;
		for( i=53;i<=54;i++){
            a[4][i]=4;
            a[5][i]=4;
            a[6][i]=4;
            a[7][i]=4;
        }
        a[4][54]=0;
        a[7][54]=0;
        a[5][55]=4;
        a[6][55]=4;
    }
    else{
        int i,j;
		for( i=3;i<=7;i++){
            for( j=51;j<=56;j++){
                a[i][j]=4;
            }
        }
        a[4][51]=0;
        a[4][56]=0;
        a[7][51]=0;
        a[7][56]=0;
    }
}

void print(int a[][N]){
    COORD c={0,0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
    int i,j;
    for(i=4;i<22;i++){
        a[i][width-1]=4;
        for(j=0;j<width;j++){
            if(a[i][j]==0){
                printf(" ");
            }
            if(a[i][j]==1)
                printf("@");
            if(a[i][j]==2)
                printf("#");
            if(a[i][j]==3)
                printf("<");
            if(a[i][j]==4){
                printf("*");
            }
            if(i==4&&j==width-1)
                printf("score:%d",score); // 修正此處的分數顯示
            if(i==5&&j==width-1)
                printf("Press Esc to exit");
        }
        printf("\n");
    }
    for(j=0;j<width;j++)
        printf("~");
}

void yn(){
    system("cls");
    system("color 07");
    printf("\n");
    printf("\n");
    printf("\t\t\t\t   *****GAME OVER*****\n\a");
    printf("\t\t\t\t   *****YOU DIED!***** \n");
    printf("\t\t\t\t*****YOUR SCORE:%4d*****\n\n",score); // 修正此處的分數顯示
    printf("\t\t\t press y to continue，n to close(y/n)?\n");
    printf("\t\t\t");
end:;
    switch(getch()){
        case 'y':
        case 'Y':death=0,score=0;memset(scr,0,sizeof(scr));run();break;
        case 'n':
        case 'N':break;
        default :goto end;break;
    }
}

void generate_block(int a[][N],int lala){
    if(lala==5){
        int i;
		for( i=0;i<=19;i++){
            a[i][69]=2;
        }
    }
    else if(lala==6){
        int hehe=rand()%5+1;
        if(hehe<=1){
            a[19][69]=3;
        }
        else if(hehe<=4){
            a[14][69]=3;
        }
        else if(hehe==5){
            a[21][69]=3;
        }
    }
    else{
        int i;
		for( i=0;i<=lala;i++)
            a[21-i][69]=2;
    }
}

void run() {
    shit=0;
    day=0;
    system("cls");
    srand(time(NULL));
    while(1){
        score++; // 每次循環增加分數
        game_time++;
        if(game_time%60==0)
            generate_block(scr,rand()%6+1);
        if(game_time%80==0)
            generate_block(scr,6);
        days(day,scr);
        if(kbhit())
            switch(getch()){
                case down:
                case 's':
                case 'S':if(jump_time<=15)shift_time=20,jump_time=0;break;
                case up:
                case 'W':
                case 'w':if(jump_time<=0)jump_time=25,jump_height=-1,shift_time=0;break;
                case 13 :system("pause");break;
            }
        if(jump_time<=0 && shift_time<=0){
            if(search_player(scr,19,pl))
                drawplayer(scr,19,pl);
            else
                goto end;
        }
        else if(jump_time>0){
            jump_time--;
            if(jump_time<10){
                jump_height--;
            }
            else if(jump_time>15){
                jump_height++;
            }
            if(search_player(scr,19-jump_height,pl)){
                drawplayer(scr,19-jump_height,pl);
            }
            else
                goto end;
        }
        else if(shift_time>0){
            shift_time--;
            if(search_player(scr,20,pl))
                drawplayer(scr,20,pl);
            else
                goto end;
        }
        int i,j;
		for( i=4;i<22;i++)
            for( j=0;j<=80;j++){
                if(scr[i][j]==2){
                    scr[i][j]=0;
                    if(j-1>=0)
                        scr[i][j-1]=2;
                }
            }
        for( i=4;i<22;i++)
            for( j=0;j<=80;j++){
                if(scr[i][j]==3){
                    scr[i][j]=0;
                    if(scr[i][j-1]==1)
                        goto end;
                    else if(scr[i][j-2]==1)
                        goto end;
                    else if(j-2>=0)
                        scr[i][j-2]=3;
                }
            }
        print(scr);
        for( i=4;i<22;i++)
            for( j=0;j<=80;j++){
                if(scr[i][j]==1)
                    scr[i][j]=0;
            }
    }
    end:;
    yn();
}

void menu(){
    system("color 07");
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hOut,&cci);
    cci.bVisible=false;
    SetConsoleCursorInfo(hOut,&cci);
}
