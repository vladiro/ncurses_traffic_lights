#include <commonincs.h>
#include <lightsframe.h>

int main()
{
    initscr();
    noecho();
    curs_set(FALSE);

    DrawSignalInit();
    DrawLightsFrame();
    DrawSignalLights();
    DrawSignalRefresh();

    while(getchar() != 'q');

    endwin();

    return 0;
}
