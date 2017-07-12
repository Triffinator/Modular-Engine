#pragma once

#include <SDL.h>
#include <GL/glew.h>  // Include before gl.h, which is in SDL_opengl.h.
#include <SDL_opengl.h>

#include "Definitions.h"
#include "Window.h"

#define ECS_MAJOR_CONTEXT  3
#define ECS_MINOR_CONTEXT  3

namespace ECS 
{
    namespace Core
    {
        /**
        * @class GLWindow
        * @brief An implementation of Window using OpenGL.
        * @author Aiden Triffitt
        * @date 11/07/2017
        */
        class SDLWindow : public Window
        {
            private:

                SDL_Window* window;
                SDL_GLContext glcontext;
                int Flags;

            public:

                /**
                * @brief
                * @return	void*
                * @author	Aiden Triffitt
                */
                virtual void* Handle();


                SDLWindow();
                virtual ~SDLWindow();

                /**
                * @brief
                * @return	bool
                * @author	Aiden Triffitt
                */
                bool IsAlive() const;
                /**
                * @brief
                * @return	bool
                * @author	Aiden Triffitt
                */
                bool IsMinimized() const;
                /**
                * @brief
                * @return	bool
                * @author	Aiden Triffitt
                */
                bool IsFocused() const;

                /**
                * @brief
                * @param	const string & title
                * @return	void
                * @author	Aiden Triffitt
                */
                virtual void Title(const std::string& title);

                /**
                * @brief
                * @param	bool center
                * @return	void
                * @author	Aiden Triffitt
                */
                virtual void Apply(bool center = false);

                /**
                * @brief
                * @param	State state
                * @return	bool
                * @author	Aiden Triffitt
                */
                virtual bool Check(State state);

                virtual bool VSync(int interval = 0);


                /*
                *  Creates a window with SDL ready for OpenGL output, and creates the
                *  SDL context the renderer will use.
                *  @return True if there were no errors, else false.
                */
                virtual void Initialize();

                /**
                * @brief
                * @param	float dt
                * @return	bool
                * @author	Aiden Triffitt
                */
                virtual void Update(float dt);

                /**
                * @brief
                * @param	SDL_Event * Event
                * @return	void
                * @author	Aiden Triffitt
                */
                virtual void OnEvent(SDL_Event* Event);
                /**
                * @brief
                * @param	SDL_WindowEvent * Event
                * @return	void
                * @author	Aiden Triffitt
                */
                virtual void OnExit(SDL_WindowEvent* Event);
                /**
                * @brief
                * @param	SDL_WindowEvent * Event
                * @return	void
                * @author	Aiden Triffitt
                */
                virtual void OnResize(SDL_WindowEvent* Event);
                /**
                * @brief
                * @param	SDL_WindowEvent * Event
                * @return	void
                * @author	Aiden Triffitt
                */
                virtual void OnReset(SDL_WindowEvent* Event);

                /**
                * @brief
                * @return	void
                * @author	Aiden Triffitt
                */
                virtual void SwapBuffer();
        };
    } 
}