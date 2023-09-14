/*** Program to Draw a Circle using Bresenham's Algorithm ***/

#include <stdio.h>
#include <graphics.h>

void circleBres(int, int, int);
void drawCircle(int, int, int, int);

int main()
{
int xc, yc, r;

int gd = DETECT, gm;
initgraph(&gd, &gm, "");

printf("Enter center coordinates of circle: ");
scanf("%d %d", &xc, &yc);
printf("Enter radius of circle: ");
scanf("%d", &r);

circleBres(xc, yc, r);

getch();
return 0;
}

void circleBres(int xc, int yc, int r)
{
int x = 0, y = r;
int d = 3 - 2 * r;

while (x < y)
{
drawCircle(xc, yc, x, y);
x++;

if (d < 0)
d = d + 4 * x + 6;
else
{
y--;
d = d + 4 * (x - y) + 10;
}

drawCircle(xc, yc, x, y);
delay(50);
}
}

void drawCircle(int xc, int yc, int x, int y)
{
putpixel(xc+x, yc+y, RED);
putpixel(xc-x, yc+y, RED);
putpixel(xc+x, yc-y, RED);
putpixel(xc-x, yc-y, RED);
putpixel(xc+y, yc+x, RED);
putpixel(xc-y, yc+x, RED);
putpixel(xc+y, yc-x, RED);
putpixel(xc-y, yc-x, RED);
}
