#include <time.h>
#include <commonincs.h>
#include <lightsframe.h>
#include <lightsimages.h>
#include <lightslogic.h>

int main()
{
    int lastChar, loopItr = 0, testCycle = 0;
    time_t start, now;
    double secs = 0.0;

    initscr();
    noecho();
    curs_set(FALSE);

    /* Main signal */
    DrawSignalInit();
    DrawLightsFrame();
    LightsCycle(0);
    DrawSignalLights();

    /* Pedestrian signal */
    DrawPedestrianLightsFrame();

    /* Draw hand or running man */
    DrawPedestrianSignal(1, 23, 17);

    /* Draw countdown digits. */
    DrawDigit(1, 19, 27);
    DrawDigit(9, 27, 27);

    DrawSignalRefresh();

    start = now = time(NULL);

    nodelay(stdscr, true);

    while(1)
    {

        if(lastChar == 0x1b)
            break;

        secs = difftime(now, start);

        if(secs > 1.0)
        {
            loopItr++;
            testCycle = loopItr % 3;

            DrawLightsFrame();
            LightsCycle(testCycle);
            DrawSignalLights();

            DrawSignalRefresh();

            start = now;
        }

        lastChar = getch();

        now = time(NULL);
    }

    endwin();

    return 0;
}
