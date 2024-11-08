#include <iostream>
#include <conio.h>
#include <cstdlib>
using namespace std;

const int mapx = 10;
const int mapy = 10;
char map[mapy][mapx];
void resetmap() {
    char tempMap[mapy][mapx] = {
        {'#','#','#','#','#','#','#','#','#','#'},
        {'#','A',' ',' ','#',' ',' ',' ',' ','#'},
        {'#',' ','#',' ','#',' ','#','#',' ','#'},
        {'#',' ','#',' ','#',' ','#',' ',' ','#'},
        {'#',' ','#',' ',' ',' ','#',' ','#','#'},
        {'#',' ','#','#','#','#','#',' ',' ','#'},
        {'#',' ',' ','#',' ',' ',' ',' ','#','#'},
        {'#',' ','#','#','#','#',' ','#',' ','#'},
        {'#',' ','#',' ',' ',' ',' ',' ','B','#'},
        {'#','#','#','#','#','#','#','#','#','#'},
    };
    for (int i = 0; i < mapy; i++) {
        for (int j = 0; j < mapx; j++) {
            map[i][j] = tempMap[i][j];
        }
    }
}
struct player
{
    int x;
    int y;
    char name;
};

void printmap() {
    system("cls");
    for (int i = 0; i < mapy; i++) {
        for (int j = 0; j < mapx; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

player player1 = {1,1,'A'};
player player2 = {8,8,'B'};

bool move1(player &player1, char in) {
    int x = player1.x;
    int y = player1.y;
    
    switch (in) {
        case 'w':
            y--;
            break;
        case 's':
            y++;
            break;
        case 'a':
            x--;
            break;
        case 'd':
            x++;
            break;
    }
    if (map[y][x] == ' ') {
        if (map[player1.y][player1.x] =='S')
        {
            map[player1.y][player1.x] = player2.name;
        }
        else {
            map[player1.y][player1.x] = ' ';
        }
        player1.x = x;
        player1.y = y;
        map[y][x] = player1.name;
        return true;
    }
    else if (map[y][x] == player2.name) {
        map[player1.y][player1.x] = ' ';
        player1.x = x; 
        player1.y = y;
        map[y][x] = 'S';
        return true;
    }
    else
        return false;
    }

bool move2(player &player2, char in) {
    int x = player2.x;
    int y = player2.y;

    switch (in) {
    case 'i':
        y--;
        break;
    case 'k':
        y++;
        break;
    case 'j':
        x--;
        break;
    case 'l':
        x++;
        break;
    }
    if (map[y][x] == ' ') {
        if (map[player2.y][player2.x] == 'S')
        {
            map[player2.y][player2.x] = player1.name;
        }
        else {
            map[player2.y][player2.x] = ' ';
        }
        player2.x = x;
        player2.y = y;
        map[y][x] = player2.name;
        return true;
    }
    else if (map[y][x] == player1.name) {
        map[player2.y][player2.x] = ' ';
        player2.x = x;
        player2.y = y;
        map[y][x] = 'S';
        return true;
    }
    else
        return false;
}



int main() {
    while (1)
    {
        
        resetmap();
        player1.x = 1;
        player1.y = 1;

        player2.x = 8;
        player2.y = 8;
        printmap();
        while (1)
        {

            if (_kbhit()) {
                char in = _getch();
                if (in == 'w' || in == 'a' || in == 's' || in == 'd') {
                    if (move1(player1, in)) {
                        printmap();
                    }
                }
                if (in == 'i' || in == 'j' || in == 'k' || in == 'l') {
                    if (move2(player2, in)) {
                        printmap();
                    }
                }

            }
            if (player1.x == 8 && player1.y == 8){
                cout << "player 1 wins" << endl;
                break;
            }
            if (player2.x == 1 && player2.y == 1){
                cout << "player 2 wins" << endl;
                break;

            }
        }
        system("cls");
        cout << "PLAY AGAIN ?(y/n)";
        char answer;
        cin >> answer;
        if (answer == 'n') {
            break;
        }
     
    }
    return 0;
}