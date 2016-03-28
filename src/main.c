#include <commonincs.h>
#include <lightsframe.h>

int main()
{
    initscr();
    noecho();
    curs_set(FALSE);

    DrawLightsFrame();
    DrawPedestrianLightsFrame();

    while(getchar() != 'q');

    endwin();

    return 0;
}
