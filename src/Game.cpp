
#include "Game.h"

#include "Constants.h"
#include "glm/glm.hpp"
#include <iostream>

SDL_Renderer* Game::renderer{};

void Game::Initialize(int width, int height) {
   if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
      std::cerr << "Error initializing SDL." << std::endl;
      return;
   }
   window = SDL_CreateWindow(
      NULL,
      SDL_WINDOWPOS_CENTERED,
      SDL_WINDOWPOS_CENTERED,
      width,
      height,
      SDL_WINDOW_BORDERLESS
   );
   if (!window) {
      std::cerr << "Error creating SDL window." << std::endl;
      return;
   }
   renderer = SDL_CreateRenderer(window, -1, 0);
   if (!renderer) {
      std::cerr << "Error creating SDL renderer." << std::endl;
      return;
   }
   isRunning = true;
   return;
}

void Game::ProcessInput() {
   SDL_Event event;
   SDL_PollEvent(&event);
   switch (event.type) {
      case SDL_QUIT:
         isRunning = false;
         break;
      case SDL_KEYDOWN:
         if (event.key.keysym.sym == SDLK_ESCAPE) {
            isRunning = false;
         }
         break;
      default:
         break;
   }

}

void Game::Update() {
   // wait until 16ms has ellapsed since the last frame
   while (!SDL_TICKS_PASSED(SDL_GetTicks(), ticksLastFrame + FRAME_TARGET_TIME)) ;

   // delta time is the difference in ticks from last frame converted to seconds
   float deltaTime = (SDL_GetTicks() - ticksLastFrame) / 1000.0f;

   // clamp delta time to a maximum vale
   deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

   // sets the new ticks for the current frame to be used in the next pass
   ticksLastFrame = SDL_GetTicks();

   // update my game objects
}

void Game::Render() {
   // set the background color
   SDL_SetRenderDrawColor(renderer, 21, 21, 21, 255);
   // clear the back buffer
   SDL_RenderClear(renderer);

   // draw all game objects in the scene

   // swap front and back buffers
   SDL_RenderPresent(renderer);
}

void Game::Destroy() {
   SDL_DestroyRenderer(renderer);
   SDL_DestroyWindow(window);
   SDL_Quit();
}

void Game::LoadLevel(int levelNumer) {
}

