#pragma once

#include <stdbool.h>
#include"Window.h"

#include<SDL.h>

#ifdef HAVE_GLAD_H

#include<glad/glad.h>
#else
#undef __gl_h_
#include"gl/glew.h"
#endif
#ifdef HAS_LUA_H
    #include<lua.h>
    #include <lauxlib.h>
    #include <lualib.h>
#endif
//The _GL Indicates that the function is the opengl implementation of it
SDL_Window* SDL_window;
SDL_Renderer* SDL_renderer;
SDL_Event SDL_event;
SDL_GLContext SDL_context;

int SDL_window_width;
int SDL_window_height;

void __declspec(dllexport) SDL2_CreateWindow(int w,int h);
void __declspec(dllexport) SDL2_RenderLoop();





void __declspec(dllexport) SDL2_GL_CreateWindow(int w,int h);
void __declspec(dllexport) SDL2_GL_DrawPixel(float w,float h,float x,float y,float x2,float y2);
void __declspec(dllexport) SDL2_GL_RenderLoop();
void __declspec(dllexport) SDL2_GL_Restart();


