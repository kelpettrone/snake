#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"gfx.h"
typedef struct{
        int x;
        int y;
        int direction;
}coord;
typedef struct{
        int x;
        int y;
}fruitCoord;
void firstsnake(coord Arr[]);
void fruit(int height, int wid, fruitCoord apple);
void movefruit(int height, int wid, fruitCoord apple);
void newsnake(coord Arr[], int, int, int);
int main(){
        srand(time(NULL));
        char *text = "you lost";
        coord Arr[50];
        fruitCoord apple;
        int length=5;
        int score = 0;
        int height = 800;
        int wid = 800;
        gfx_open(height, wid, "snake");
        firstsnake(Arr);
        movefruit(height,wid,apple);
        while(1){
        char p = gfx_wait();
        fruit(height,wid,apple);
        if(abs(Arr[0].x - apple.x)<10 && abs(Arr[0].x- apple.y)<10){
                printf("fruit eaten");
                movefruit(height,wid,apple);
                score+=1;
                length +=1;
                int newX = Arr[0].x;
                int newY = Arr[0].y;
                newsnake(Arr,length,newX,newY);
                fruit(height,wid,apple);
        }
        if (p == 'k'){
                gfx_clear();
                fruit(height,wid,apple);
                int i;
                Arr[0].y+=20;
                gfx_circle(Arr[0].x,Arr[0].y,10);
                int prevX = Arr[0].x;
                int prevY = Arr[0].y-20;
                for(i=1;i<length;i++){
                        int curx = Arr[i].x;
                        int cury = Arr[i].y;
                        int temp = cury -20;
                        Arr[i].y = prevY;
                        Arr[i].x = prevX;
                        gfx_circle(Arr[i].x,Arr[i].y,10);
                            printf("%d %d %d %d\n",curx,prevX,cury,prevY);
                        if(curx == prevX&&temp==prevY){
                                gfx_clear();
                                gfx_text(400,400,text);
                                printf("you lost\n");
                               // return 1;
                        }
                        prevX = curx;
                        prevY = cury;
                }

        }

        else if(p=='l'){
                gfx_clear();
                fruit(height,wid,apple);
                int i;
                Arr[0].y -=20;
                gfx_circle(Arr[0].x,Arr[0].y,10);
                int prevX = Arr[0].x;
                int prevY = Arr[0].y+20;
                for(i=1;i<length;i++){
                        int curX = Arr[i].x;
                        int curY = Arr[i].y;
                        int temp = curY+20;
                        Arr[i].y = prevY;
                        Arr[i].x = prevX;
                        gfx_circle(Arr[i].x,Arr[i].y,10);
                           printf("%d %d %d %d\n",curX,prevX,curY,prevY);
                         if(curX == prevX&&temp==prevY){
                                gfx_clear();
                                gfx_text(400,400,text);
                                printf("YOU LOST\n");
                                //return 1;
                        }


                        prevX= curX;
                        prevY = curY;
                }
                 }
          else if(p=='h'){
                gfx_clear();
                 fruit(height,wid,apple);
                int i;
                Arr[0].x -=20;
                gfx_circle(Arr[0].x,Arr[0].y,10);
                int prevX = Arr[0].x+20;
                int prevY = Arr[0].y;

                for(i=1;i<length;i++){
                        int curX = Arr[i].x;
                        int curY = Arr[i].y;
                        int temp = curX + 20;
                        Arr[i].y = prevY;
                        Arr[i].x = prevX;
                        gfx_circle(Arr[i].x,Arr[i].y,10);
                         printf("%d %d %d %d\n",curX,prevX,curY,prevY);
                         if(temp == prevX&&curY==prevY){
                                gfx_clear();
                                gfx_text(400,400,text);
                                printf("you lost\n");
                             // return 1;
                        }

                        prevX= curX;
                        prevY = curY;
                }
        }
         else if(p=='j'){
                gfx_clear();
                fruit(height,wid,apple);
                int i;
                Arr[0].x +=20;
                gfx_circle(Arr[0].x,Arr[0].y,10);
                int prevX = Arr[0].x-20;
                int prevY = Arr[0].y;

                for(i=1;i<length;i++){
                        int curX = Arr[i].x;
                        int curY = Arr[i].y;
                        int temp = curX-20;
                        Arr[i].y = prevY;
                        Arr[i].x = prevX;
                        gfx_circle(Arr[i].x,Arr[i].y,10);
                         printf("%d %d %d %d\n",curX,prevX,curY,prevY);
                         if(temp == prevX&&curY==prevY){
                                gfx_clear();

  gfx_text(400,400,text);
                                printf("you lost");
                               // return 1;
                        }
                        prevX= curX;
                        prevY = curY;
                }
        }




        }
        return 0;


}
void firstsnake(coord Arr[]){
        int i;
        int x = 400;
        int y = 400;
        for(i=0;i<5;i++){
                coord c;
                c.x = 20+x;
                x = c.x;
                c.y = y;
                Arr[i] = c;
                gfx_color(255,255,255);
                gfx_circle(c.x,c.y,10);
        }
}
void movefruit(int height, int wid, fruitCoord apple){
        apple.x = rand() %wid;
        apple.y = rand() %height;
}
void fruit(int height, int wid, fruitCoord apple)
{
        gfx_circle(apple.x,apple.y,10);
}
void newsnake(coord Arr[], int length, int newX, int newY){
        int i;
        int x = newX;
        int y = newY;
        for(i=0;i<length;i++){
                coord c;
                c.x = 20+x;
                x = c.x;
                Arr[i] = c;
                gfx_color(255,255,255);
                gfx_circle(c.x,c.y,10);
        }
}

                              
