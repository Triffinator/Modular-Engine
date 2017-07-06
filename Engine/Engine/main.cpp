#include "Dependencies/Engine.h"

int main(int argc, char ** argv)
{
    ECS::Engine * e = new ECS::Engine();

    e->Start();

    return 0;
}