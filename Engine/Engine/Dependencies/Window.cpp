#include "Window.h"

ECS::Core::Window::Window()
    : m_running(true)
{

}

ECS::Core::Window::~Window()
{

}

bool ECS::Core::Window::IsAlive() const
{
    return false;
}

bool ECS::Core::Window::IsMinimized() const
{
    return false;
}

bool ECS::Core::Window::IsFocused() const
{
    return false;
}

void ECS::Core::Window::Set(const char* title, int x, int y, int bits, bool fullscreen, int vsync)
{
    Title(title);
    VSync(vsync);
    Resolution(x, y, bits, fullscreen);
}

void ECS::Core::Window::Initialize()
{

}

void ECS::Core::Window::Resolution(int x, int y, int bits, bool fullscreen)
{
    State temp(x, y, bits, fullscreen);

    if (Check(temp))
    {
        NewState = temp;
    }
}

ECS::Core::Window::operator bool()
{
    return m_running;
}