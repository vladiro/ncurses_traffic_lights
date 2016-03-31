#include <commonincs.h>
#include <lightsframe.h>

int main()
{
    initscr();
    noecho();
    curs_set(FALSE);

    /* Main signal */
    DrawSignalInit();
    DrawLightsFrame();
    DrawSignalLights();

    /* Pedestrian signal */
    DrawPedestrianLightsFrame();

    DrawSignalRefresh();

    while(getchar() != 0x1b);

    endwin();

    return 0;
}
