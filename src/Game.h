#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

class Game {
public:
   Game() = default;
   ~Game() = default;
   bool IsRunning() const   { return isRunning; }
   void Initialize(int width, int height);
   void ProcessInput();
   void Update();
   void Render();
   void Destroy();
   static SDL_Renderer* renderer;
   void LoadLevel(int levelNumber);

private:
   bool isRunning{};

   SDL_Window* window{};
   int ticksLastFrame{};
};


#endif
