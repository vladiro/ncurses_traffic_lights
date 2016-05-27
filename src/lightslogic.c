#include <lightslogic.h>

#define SHIFTLEFT(n) (1 << n)

static unsigned char systemStatus;
/*static unsigned char lightsCycled;*/

int SystemIsReset()
{
    if(!systemStatus)
        return 1;

    return 0;
}

static void SetStatusRed()
{
    systemStatus |= SHIFTLEFT(2);
}

static void SetStatusAmber()
{
    systemStatus |= SHIFTLEFT(1);
}

static void SetStatusGreen()
{
    systemStatus |= SHIFTLEFT(0);
}

static void ClearStatusRed()
{
    systemStatus &= ~SHIFTLEFT(2);
}

static void ClearStatusAmber()
{
    systemStatus &= ~SHIFTLEFT(1);
}

static void ClearStatusGreen()
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

int LightsCycle(unsigned int state)
{
    switch(state)
    {
        case 0:
            ClearStatusAmber();
            ClearStatusGreen();

            SetStatusRed();

            break;
        case 1:
            ClearStatusGreen();

            SetStatusAmber();

            break;
        case 2:
            ClearStatusAmber();
            ClearStatusRed();

            SetStatusGreen();

            break;

        default:
            break;
    }

    return 0;
}
