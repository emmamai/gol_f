#include <SDL2/SDL.h>

#define WIDTH 80
#define HEIGHT 72

int cells[WIDTH][HEIGHT][2];
int q = 0;
int r = 0;
int sel=0;

int summate( int x, int y ) {
    int i,j,n=0;
    for(j=y-1;j<y+2;j++)
        for(i=x-1;i<x+2;i++)
            n=n+(cells[i][j][sel]>0);
    return n;
}

int main(){
    int i, j, n;
    SDL_Window* w = SDL_CreateWindow( "gol_f", -1,-1, WIDTH*8, HEIGHT*8, 0 );
    SDL_Surface* ws = SDL_GetWindowSurface( w );
    SDL_Surface* rs = SDL_CreateRGBSurface( 0, WIDTH, HEIGHT, 32, 0xFF, 0xFF<<8,  0xFF<<16,  0xFF<<24 );
    SDL_Surface* p = SDL_CreateRGBSurface( 0, 1,1, 32, 0xFF, 0xFF<<8,  0xFF<<16,  0xFF<<24 );
    SDL_Event e;
    SDL_Rect d = { 0, 0, 1, 1 };
    SDL_FillRect( p, NULL, SDL_MapRGB( p->format, 0, 0, 0 ) );

    while( !q ) {
        if (r) {
            for(j=1;j<HEIGHT-1;j++)
                for(i=1;i<WIDTH-1;i++)
                    cells[i][j][!sel] = (n=summate(i,j))==3?1:n==4?cells[i][j][sel]:0;
            sel=!sel;
        }
        SDL_FillRect( rs, NULL, SDL_MapRGB( rs->format, 0xff, 0xff, 0xff ) );
        for(j=0;j<HEIGHT;j++)
                for(i=0;i<WIDTH;i++) 
                    if ( cells[i][j][sel] ) {
                        d.x = i, d.y = j;
                        SDL_BlitSurface( p, NULL, rs, &d );
                    }
        SDL_BlitScaled( rs, NULL, ws, NULL );
        SDL_UpdateWindowSurface( w );
        SDL_Delay(67);
        while ( SDL_PollEvent( &e ) != 0 ) {
            switch( e.type ) {
                case SDL_MOUSEBUTTONDOWN:
                    cells[e.button.x/8][e.button.y/8][sel]=!cells[e.button.x/8][e.button.y/8][sel];
                    break;
                case SDL_KEYDOWN:
                    r=!r;
                    break;
                case SDL_QUIT:
                    q=1;
                default:
                    break;
            }
        }
    }
}