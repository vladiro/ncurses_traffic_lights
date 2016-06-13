#include <commonincs.h>
#include <mainsignallogic.h>

static unsigned char systemStatus = (char)0;

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

int LightsCycle(UINT state)
{
    switch(state)
    {
        case 0:
            SetStatusRed();
            ClearStatusAmber();
            ClearStatusGreen();
            break;
        case 1:
            ClearStatusRed();
            ClearStatusAmber();
            SetStatusGreen();
            break;
        case 2:
            ClearStatusRed();
            SetStatusAmber();
            ClearStatusGreen();
            break;
        default:
            break;
    }

    return 0;
}
