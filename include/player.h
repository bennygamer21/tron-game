#indef PLAYER_H
#define PLAYER_H

typedef struct  
{
    int x, y;
    int dx, dy;
}   Player;

void initPlayer(Player *p, int x, int y);
void updatePlayer(Player *p);

#endif
