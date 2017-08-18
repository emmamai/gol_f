#include <SDL2/SDL.h>
#define B(a)e.button.a
#define V(a)SDL_##a
#define W 80
#define H 72
#define C case

                    int z[W][H][2],q=0,r
                    =0,s=0;int m( int x,
                    int y){int i,j, n=0;
                    for(j=y-1;j<y+2;j++)
                    for(i=x-1;i<x+2;i++)
                    n=n+(z[i][j][s] >0);
                    return n;}int main()
                    {int i,j,n, Z=255;V(
                    Window * ) w = V ( \
                    CreateWindow)("gol",
                                        -1,-1,W*8,H*8,0); V(
                                        Surface * ) ws = V (
                                        GetWindowSurface)(w)
                                        ;V(Surface*) rs = V(
                                        CreateRGBSurface)(0,
                                        W,H,32,Z,Z<<8,Z<<16,
                                        Z<<24);V(Surface*)p=
                                        V(CreateRGBSurface)(
                                        0,1,1,32,Z,Z<<8, Z<<
                                        16,Z<<24);V(Event)e;
V(Rect)d={0,0,1,1};V(FillRect)(p,0,V(MapRGB)(p->format,0,0,0
));while(!q){if(r){for(j=1;j<H-1;j++)for(i=1;i<W-1;i++)z[i][
j][!s]=(n=m(i,j))==3?1:n==4?z[i][j][s]:0;s=!s;} V(FillRect)(
rs,0,V(MapRGB)(rs->format,Z,Z,Z));for(j=0;j<H;j++)for(i=0;i<
W;i++)if(z[i][j][s]){d.x=i,d.y=j;V(BlitSurface)(p,0,rs,&d);}
V(BlitScaled)(rs,0,ws,0);V(UpdateWindowSurface)(w); V(Delay(
67));while(V(PollEvent)(&e)!=0){switch(e.type){C V(MOUSEBUT\
TONDOWN): z[B(x)/8][B(y)/8][s] = !z[B(x)/8][B(y)/8][s];break
;C V(KEYDOWN):r=!r; break; C V(QUIT): q=1;default:break;}}}}
