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
    systemStatus |= SHIFTLEFT(2);
}

void SetStatusAmber()
{
    systemStatus |= SHIFTLEFT(1);
}

void SetStatusGreen()
{
    systemStatus |= SHIFTLEFT(0);
}

void ClearStatusRed()
{
    systemStatus &= ~SHIFTLEFT(2);
}

void ClearStatusAmber()
{
    systemStatus &= ~SHIFTLEFT(1);
}

void ClearStatusGreen()
{
    systemStatus &= ~SHIFTLEFT(0);
}

int GetStatusRed()
{
    if(systemStatus & SHIFTLEFT(2))
        return 1;

    return 0;
}

int GetStatusAmber()
{
    if(systemStatus & SHIFTLEFT(1))
        return 1;

    return 0;
}

int GetStatusGreen()
{
    if(systemStatus & SHIFTLEFT(0))
        return 1;

    return 0;
}

int LightsCycled()
{
    return 0;
}
