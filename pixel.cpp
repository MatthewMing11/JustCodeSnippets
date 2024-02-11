#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main(int argc,char* argv[]){
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = nullptr;
    SDL_Renderer *renderer = nullptr;
    SDL_Event e;
    window =SDL_CreateWindow("SDL2 Window",
                                            SDL_WINDOWPOS_CENTERED,
                                            SDL_WINDOWPOS_CENTERED,
                                            680,480,
                                            0);
    renderer=SDL_CreateRenderer(window,-1,0);

    SDL_SetRenderDrawColor(renderer,0,0,0,0);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer,255,0,0,0);
    SDL_RenderDrawPoint(renderer,30,30);

    SDL_SetRenderDrawColor(renderer,0,255,0,0);
    SDL_RenderDrawLine(renderer,50,50,250,250);
    

    SDL_SetRenderDrawColor(renderer,0,0,255,0);
    SDL_Rect rect = {100,120,200,50};
    SDL_RenderDrawRect(renderer,&rect);
    SDL_RenderFillRect(renderer,&rect);
    SDL_RenderPresent(renderer);
    
    for(;;){
        SDL_PollEvent(&e);
            if (e.type==SDL_QUIT){
                break;
            }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    renderer=NULL;
    window=NULL;
    SDL_Quit();

}