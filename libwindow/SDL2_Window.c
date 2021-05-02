#include "SDL2_Window.h"
#ifdef __CLIENT_BUILD
#define NK_IMPLEMENTATION
#include"nuklear.h"
#include "CommandInt.h"
#endif
bool RenderingDisabled = false;
SDL_bool SDL_RenderLoop = SDL_FALSE;
SDL_bool SDL_ONLY_DEBUG_DRAW = SDL_FALSE;

void __declspec(dllexport) SDL2_CreateWindow(int w, int h)
{

	int window_renderer_combo = SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_RESIZABLE, &SDL_window, &SDL_renderer);


	//if (SDL_window == NULL) {
   //SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Project", "Failed to create SDL 2 Window", NULL);
//	SDL_Quit();
//}
//if (SDL_renderer == NULL) {
	//SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Project", "Failed to create SDL 2 Renderer", NULL);
//SDL_Quit();
//}
	if (window_renderer_combo == -1) {

		//SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Project", "Failed to create SDL 2 Window and Renderer", NULL);

		//SDL_Quit();
        #ifdef __CLIENT_BUILD
        GetCommandInput();
        #endif
  #ifndef __CLIENT_BUILD

  #endif
	}
	else {
		Current_window = SDL;
#ifdef __CLIENT_BUILD
Player_Special_init();
#endif
if (init_func != NULL) {
    init_func();
}

		SDL_RenderLoop = SDL_TRUE;
if(SDL_ONLY_DEBUG_DRAW == SDL_TRUE){

}else{
    render_func();
#ifdef __CLIENT_BUILD
    RenderALLEntities();
#endif
}
		//SDL_GL_GetProcAddress(gladloadgl)


	}


}

void __declspec(dllexport) SDL2_RenderLoop(){
	float prev_ypos;
	int delay;
	while (SDL_RenderLoop == SDL_TRUE) {
		SDL_PollEvent(&SDL_event);

		SDL_RenderClear(SDL_renderer);
		if(SDL_ONLY_DEBUG_DRAW == SDL_TRUE){
            debug_render_func();
            debug_update_func();
        }else{
            render_func();
            update_func();
#ifdef __CLIENT_BUILD
            RenderALLEntities();
            //glClear(GL_COLOR_BUFFER_BIT);


            //SDL_GL_SetSwapInterval(1);
            UpdateALLEntities();
#endif

        }

		//SDL_GL_SwapWindow(SDL_window);
		SDL_RenderPresent(SDL_renderer);


		if (SDL_event.type == SDL_QUIT) {
			SDL_RenderLoop = SDL_FALSE;
			SDL_Quit();
		}
        
		if(SDL_ONLY_DEBUG_DRAW == SDL_TRUE ){

		}else{
            input_func();
#ifdef __CLIENT_BUILD
            if(SDL_event.type == SDL_KEYDOWN){
                if(SDL_event.key.keysym.sym == SDLK_RIGHT){
                    Player_data->posX += 0.222225f;
                }
                if(SDL_event.key.keysym.sym == SDLK_LEFT){
                    Player_data->posX -= 0.222225f;
                }
                if(SDL_event.key.keysym.sym == SDLK_UP){
                    prev_ypos = Player_data->posY;
                    Player_data->posY += 0.222225f;
                }
                if(SDL_event.key.keysym.sym == SDLK_DOWN){
                    prev_ypos = Player_data->posY;
                    Player_data->posY -= 0.222225f;
                }
                if(SDL_event.key.keysym.sym == SDLK_SPACE){

                   /* Player_data->posY += 0.222225f;
                    delay++;
                    if(delay >= 60){
                        Player_data->posY += prev_ypos;
                    }*/


                }
#endif
		}




	   }

	   if(SDL_event.type == SDL_WINDOWEVENT){
		   if(SDL_event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED){

			 // glViewport(0,0,SDL_event.window.data1,SDL_event.window.data2);

		   }
	   }



}

void __declspec(dllexport) SDL2_GL_CreateWindow(int w,int h){
	int window_renderer_combo = SDL_CreateWindowAndRenderer(w, h, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE, &SDL_window, &SDL_renderer);
	if (window_renderer_combo == -1) {

			SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Project", "Failed to create SDL 2 Window and Renderer", NULL);
            #ifdef __CLIENT_BUILD
        GetCommandInput();
        #endif
			//SDL_Quit();
		}
		else {

		SDL_context = SDL_GL_CreateContext(SDL_window);

			if(SDL_context == NULL){

				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Project","Failed to create a SDL 2 OpenGL Context!",NULL);

			}
			if(SDL_GL_MakeCurrent(SDL_window,SDL_context) != 0){
				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Project","Failed to make OpenGL Current!",NULL);
				SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR,"Project",SDL_GetError(),NULL);
#ifdef __CLIENT_BUILD
                GetCommandInput();
#endif
			}
			#ifdef HAVE_GLAD_H
			gladLoadGLLoader(SDL_GL_GetProcAddress);
			#else

			#endif
            Current_window = GL;
            if (init_func != NULL) {
                init_func();
            }
     
        
            
			SDL_RenderLoop = SDL_TRUE;

			//SDL_GL_GetProcAddress(gladloadgl)

       // if(SDL_ONLY_DEBUG_DRAW == SDL_TRUE ){
         //   RenderALLDebugObjects();
        //}else{
#ifdef __CLIENT_BUILD
            RenderALLEntities();
#endif
            render_func();
        //}

		}
}
void __declspec(dllexport) SDL2_GL_RenderLoop() {
    float prev_ypos;
    int delay;
    while (SDL_RenderLoop == SDL_TRUE) {
        SDL_PollEvent(&SDL_event);

        //SDL_RenderClear(SDL_renderer);
  //  if(SDL_ONLY_DEBUG_DRAW == SDL_TRUE ){
        //RenderALLDebugObjects();
        //UpdateALLDebugObjects();
  //  }else{
        if (RenderingDisabled == true) {
            SDL_RenderLoop = false;
            //SDL_RenderPresent(SDL_renderer);
        }
        else {

#ifdef __CLIENT_BUILD
            RenderALLEntities();
#endif
            render_func();
            // }

            //

            glClear(GL_COLOR_BUFFER_BIT | GL_STENCIL_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
#ifdef __CLIENT_BUILD
            UpdateALLEntities();
#endif
            update_func();
            //SDL_GL_SetSwapInterval(1);



            SDL_GL_SwapWindow(SDL_window);


            if (SDL_event.type == SDL_QUIT) {

                SDL_RenderLoop = SDL_FALSE;
                SDL_Quit();
            }
            //if(SDL_ONLY_DEBUG_DRAW == SDL_TRUE ){

            //}else{
#ifdef __CLIENT_BUILD
            if (SDL_event.type == SDL_KEYDOWN) {
                if (SDL_event.key.keysym.sym == SDLK_RIGHT) {
                    SDL2_OnPlayerMove(1);
                    Player_data->posX += 0.222225f;
                }
                if (SDL_event.key.keysym.sym == SDLK_LEFT) {
                    SDL2_OnPlayerMove(1);
                    Player_data->posX -= 0.222225f;
                }
                if (SDL_event.key.keysym.sym == SDLK_UP) {
                    SDL2_OnPlayerMove(0);
                    prev_ypos = Player_data->posY;
                    Player_data->posY += 0.222225f;
                }
                if (SDL_event.key.keysym.sym == SDLK_DOWN) {
                    SDL2_OnPlayerMove(0);
                    prev_ypos = Player_data->posY;
                    Player_data->posY -= 0.222225f;
                }
                if (SDL_event.key.keysym.sym == SDLK_SPACE) {
                    RenderingDisabled = true;
                    SDL_HideWindow(SDL_window);

                    GetCommandInput();

                    /*Player_data->posY -= 0.06f;
                    delay++;
                    if(delay >= 60){
                       Player_data->posY = prev_ypos;
                    }*/

                }
#endif
                input_func();

                if (SDL_event.type == SDL_WINDOWEVENT) {
                    if (SDL_event.window.event == SDL_WINDOWEVENT_SIZE_CHANGED) {

                        glViewport(0, 0, SDL_event.window.data1, SDL_event.window.data2);

                    }
                }
        }
    }
}

        void __declspec(dllexport) SDL2_GL_Restart() {
            RenderingDisabled = false; //Clear rendering disabled
            SDL_ShowWindow(SDL_window);

            // SDL2_GL_CreateWindow(640,480);
            SDL2_GL_RenderLoop();
        }

        void __declspec(dllexport) SDL2_GL_DrawPixel(float w, float h, float x, float y, float x2, float y2) {
            glScalef(w, h, 0);
            glRectf(x, y, x2, y2);
        }
