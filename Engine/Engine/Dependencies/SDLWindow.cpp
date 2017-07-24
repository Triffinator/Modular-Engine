#include "SDLWindow.h"

#ifdef _WIN32
#include <Windows.h>
#include <SDL_syswm.h>
#endif

void * ECS::Core::SDLWindow::Handle()
{
    SDL_SysWMinfo info;
    SDL_GetVersion(&info.version);
    SDL_GetWindowWMInfo(window, &info);
    return info.info.win.window;
}

ECS::Core::SDLWindow::SDLWindow() : window(nullptr), glcontext(nullptr), Flags()
{}

ECS::Core::SDLWindow::~SDLWindow()
{
    SDL_GL_DeleteContext(glcontext);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool ECS::Core::SDLWindow::IsAlive() const
{
    return false;
}

bool ECS::Core::SDLWindow::IsMinimized() const
{
    return false;
}

bool ECS::Core::SDLWindow::IsFocused() const
{
    return false;
}

void ECS::Core::SDLWindow::Initialize()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Error: Unable to initialize SDL." << std::endl;
        return;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, ECS_MAJOR_CONTEXT);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, ECS_MINOR_CONTEXT);

    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 0);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

    window = SDL_CreateWindow(
        "SDL2/OpenGL Demo",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        512,
        512,
        SDL_WINDOW_OPENGL | SDL_WINDOW_HIDDEN);

    if (window == NULL)
    {
        std::cerr << "Error: Cannot create window." << std::endl;
        return;
    }

    glcontext = SDL_GL_CreateContext(window);

    if (glcontext == NULL)
    {
        std::cerr << "Error: Cannot create GL context." << std::endl;
        return;
    }

    Window::Initialize();
}

void ECS::Core::SDLWindow::Title(const std::string& title)
{
    SDL_SetWindowTitle(window, title.c_str());
}

bool ECS::Core::SDLWindow::Check(State /*state*/)
{
    return true;
}

bool ECS::Core::SDLWindow::VSync(int interval)
{
    if (interval != SDL_GL_GetSwapInterval())
    {
        SDL_GL_SetSwapInterval(interval);
    }
    return true;
}

void ECS::Core::SDLWindow::Apply(bool center)
{
    SDL_SetWindowSize(window, NewState.Width, NewState.Height);

    if (center)
    {
        SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
    }

    ActiveState = NewState;

    if (OnResizeCallback)
    {
        OnResizeCallback(ActiveState.Width, ActiveState.Height);
    }

    SDL_ShowWindow(window);

    SDL_PumpEvents();
}

void ECS::Core::SDLWindow::Update(float /*dt*/)
{
    SDL_Event Event;
    while (SDL_PollEvent(&Event))
    {
        OnEvent(&Event);
    }
}


void ECS::Core::SDLWindow::OnEvent(SDL_Event* event)
{
    if (event->type == SDL_WINDOWEVENT)
    {
        SDL_WindowEvent* eve = &event->window;
        switch (eve->event)
        {
        case SDL_WINDOWEVENT_CLOSE:
            OnExit(eve);
            break;
        case SDL_WINDOWEVENT_RESIZED:
            OnResize(eve);
            break;
        case SDL_WINDOWEVENT_EXPOSED:
            OnReset(eve);
            break;
        }
    }
    else if (event->type == SDL_QUIT)
    {
        OnExit(nullptr);
    }
}

void ECS::Core::SDLWindow::OnExit(SDL_WindowEvent* /*event*/)
{
    m_running = false;
}

void ECS::Core::SDLWindow::OnResize(SDL_WindowEvent* /*event*/)
{
    SDL_GetWindowSize(window, &ActiveState.Width, &ActiveState.Height);
    if (OnResizeCallback)
    {
        OnResizeCallback(ActiveState.Width, ActiveState.Height);
    }
}

void ECS::Core::SDLWindow::OnReset(SDL_WindowEvent* /*event*/)
{
    //cout << "RESET: " << (uint) event->active.state << " " << (uint) event->active.gain << endl;
}

void ECS::Core::SDLWindow::SwapBuffer()
{
    SDL_GL_SwapWindow(window);
}