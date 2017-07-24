#pragma once

#include "Definitions.h"

namespace ECS
{
    namespace Core
    {
        class Window
        {
            public:

                struct State
                {
                    int Width, Height, Bits;
                    bool Fullscreen;

                    State(int x = 800, int y = 600, int b = 32, bool f = false): 
                        Width(x), 
                        Height(y), 
                        Bits(b == 0 ? 32 : b), 
                        Fullscreen(f)
                    {

                    }

                    State& operator= (const State& state)
                    {
                        Width = state.Width;
                        Height = state.Height;
                        Bits = state.Bits;
                        Fullscreen = state.Fullscreen;
                        return *this;
                    }
                };

                std::function<void(const int, const int)> OnResizeCallback;

                static void* GetHandle;

                /**
                * @brief
                * @return	void*
                * @author	Aiden Triffitt
                */
                virtual void* Handle() = 0;

                State ActiveState, NewState;
                bool m_running;


                Window();
                virtual ~Window();

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
                * @param	const char * title
                * @param	int x
                * @param	int y
                * @param	int bits
                * @param	bool fullscreen
                * @return	void
                * @author	Aiden Triffitt
                */
                void Set(const char* title, int x, int y, int bits, bool fullscreen = false, int vsync = 0);

                /**
                * @brief
                * @param	const string & title
                * @return	void
                * @author	Aiden Triffitt
                */
                virtual void Title(const std::string& title) = 0;

                /**
                * @brief
                * @param	bool center
                * @return	void
                * @author	Aiden Triffitt
                */
                virtual void Apply(bool center = false) = 0;

                /**
                * @brief
                * @param	int x
                * @param	int y
                * @param	int bits
                * @param	bool fullscreen
                * @return	void
                * @author	Aiden Triffitt
                */
                virtual void Resolution(int x, int y, int bits = 0, bool fullscreen = false);
                
                /**
                * @brief
                * @param	State state
                * @return	bool
                * @author	Aiden Triffitt
                */
                virtual bool Check(State state) = 0;

                virtual bool VSync(int interval = 0) = 0;

                /**
                * @brief
                * @return	void
                * @author	Aiden Triffitt
                */
                virtual void Initialize();

                /**
                * @brief
                * @param	float dt
                * @return	bool
                * @author	Aiden Triffitt
                */
                virtual void Update(float dt) = 0;
                
                /**
                * @brief
                * @return	void
                * @author	Aiden Triffitt
                */
                virtual void SwapBuffer() = 0;

                //bool operator= (bool val) { return Running = val; }
                /**
                * @brief
                * @return
                * @author	Aiden Triffitt
                */
                operator bool();

                virtual uint BaseType() { return TYPEID(Window); }
        };
    }  
}

