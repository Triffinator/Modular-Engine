#include "Dependencies/Engine.h"

//inline float operator-(std::chrono::system_clock::time_point a, std::chrono::system_clock::time_point b)
//{
//    float val1 = (float)a;
//
//}

int main(int argc, char ** argv)
{
    ECS::Engine * e = new ECS::Engine();
    
    e->Awake();
    e->Start();
   
    e->UpdateLoop();

    e->End();
    e->Sleep();

    return 0;
}