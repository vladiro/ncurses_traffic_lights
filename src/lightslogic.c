#include <lightslogic.h>

#define SHIFTLEFT(n) (1 << n)

static unsigned char systemStatus;
static unsigned char lightsCycled;

int SystemIsReset()
{
    if(!systemStatus)
        return 1;

    return 0;
}

void SetStatusRed()
{

}

void SetStatusAmber()
{

}

void SetStatusGreen()
{

}

void ClearStatusRed()
{

}

void ClearStatusAmber()
{

}

void ClearStatusGreen()
{

}

int GetStatusRed()
{
    return 0;
}

int GetStatusAmber()
{
    return 0;
}

int GetStatusGreen()
{
    return 0;
}

int LightsCycled()
{
    return 0;
}
