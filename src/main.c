#include <time.h>
#include <commonincs.h>
#include <lightsframe.h>
#include <lightsimages.h>
#include <mainsignallogic.h>
#include <pedestriansignallogic.h>

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
    PedestrianLightsCycle(0);
    DrawSignalLights();

    /* Pedestrian signal */
    DrawPedestrianLightsFrame();

    /* Draw hand or running man */
    DrawPedestrianSignal(23, 17);

    /* Draw countdown digits. */
    DrawSignalDigits(2, 19, 27, 0, 27, 27);

    DrawSignalRefresh();

    start = now = time(NULL);

    nodelay(stdscr, true);

    while(1)
    {
        if(lastChar == 0x1b)
            break;

        secs = difftime(now, start);

        if(secs > 0.5)
        {
            if(!GetStatusGreen())
            {
                loopItr++;
                testCycle = loopItr % 3;

                DrawLightsFrame();
                LightsCycle(testCycle);
                PedestrianLightsCycle(testCycle);
                DrawSignalLights();
                DrawPedestrianSignal(23, 17);
                DrawSignalDigits(1, 19, 27, 9, 27, 27);
                BlankSignalDigits(19, 27, 27, 27);
            }
            else
            {
                loopItr++;
                testCycle = loopItr % 3;

                DrawLightsFrame();
                LightsCycle(testCycle);
                PedestrianLightsCycle(testCycle);
                DrawSignalLights();
                DrawPedestrianSignal(23, 17);
                DrawSignalDigits(2, 19, 27, 0, 27, 27);
            }

            DrawSignalRefresh();

            start = now;
        }

        lastChar = getch();

        now = time(NULL);
    }

    endwin();

    return 0;
}
