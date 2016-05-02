#include <commonincs.h>
#include <lightsframe.h>
#include <lightsimages.h>
#include <lightslogic.h>

int main()
{
    int lastChar, testCycle = 0;

    initscr();
    noecho();
    curs_set(FALSE);

    /* Main signal */
    DrawSignalInit();
    DrawLightsFrame();
    LightsCycle(1);
    DrawSignalLights();

    /* Pedestrian signal */
    DrawPedestrianLightsFrame();

    /* Draw hand or running man */
    DrawPedestrianSignal(1, 23, 17);

    /* Draw countdown digits. */
    DrawDigit(1, 19, 27);
    DrawDigit(9, 27, 27);

    DrawSignalRefresh();

    while(1)
    {
        switch(lastChar)
        {
            case 0x1b:
                endwin();
                return 0;
            case 0x20:
                testCycle++;

                DrawLightsFrame();
                LightsCycle(testCycle % 3);
                DrawSignalLights();

                DrawSignalRefresh();
            default:
                lastChar = getchar();
        }
    }

    return 1;
}
