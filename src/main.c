#include <commonincs.h>
#include <lightsframe.h>
#include <lightsimages.h>

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

    /* Draw hand or running man */
    DrawStopHand(26, 17);

    /* Draw countdown digits. */
    DrawDigit(1, 19, 27);
    DrawDigit(9, 27, 27);

    DrawSignalRefresh();

    while(getchar() != 0x1b);

    endwin();

    return 0;
}
