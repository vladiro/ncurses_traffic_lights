#include <commonincs.h>
#include <lightsframe.h>
#include <lightsimages.h>
#include <lightslogic.h>

int main()
{
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

    while(getchar() != 0x1b)
    {
        if(getchar() != 0x20)
        {
            /* Change status here. */
        }
    }

    endwin();

    return 0;
}
