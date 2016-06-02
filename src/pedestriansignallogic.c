#include <commonincs.h>
#include <pedestriansignallogic.h>

static unsigned char pedestrianStatus = (char)0;

static void SetPedestrianStatusRed()
{
    pedestrianStatus |= SHIFTLEFT(2);
}

static void SetPedestrianStatusRedBlinking()
{
    pedestrianStatus |= SHIFTLEFT(1);
}

static void SetPedestrianStatusGreen()
{
    pedestrianStatus |= SHIFTLEFT(0);
}

static void ClearPedestrianStatusRed()
{
    pedestrianStatus &= ~SHIFTLEFT(2);
}

static void ClearPedestrianStatusRedBlinking()
{
    pedestrianStatus &= ~SHIFTLEFT(1);
}

static void ClearPedestrianStatusGreen()
{
    pedestrianStatus &= ~SHIFTLEFT(0);
}

int GetPedestrianStatusRed()
{
    if(pedestrianStatus & SHIFTLEFT(2))
        return 1;

    return 0;
}

int GetPedestrianStatusRedBlinking()
{
    if(pedestrianStatus & SHIFTLEFT(1))
        return 1;

    return 0;
}

int GetPedestrianStatusGreen()
{
    if(pedestrianStatus & SHIFTLEFT(0))
        return 1;

    return 0;
}

void PedestrianLightsCycle(unsigned int state)
{
    switch(state)
    {
        case 0:
            SetPedestrianStatusRed();
            ClearPedestrianStatusRedBlinking();
            ClearPedestrianStatusGreen();
            break;
        case 1:
            ClearPedestrianStatusRed();
            SetPedestrianStatusRedBlinking();
            ClearPedestrianStatusGreen();
            break;
        case 2:
            ClearPedestrianStatusRed();
            ClearPedestrianStatusRedBlinking();
            SetPedestrianStatusGreen();
            break;
        default:
            break;
    }
}
