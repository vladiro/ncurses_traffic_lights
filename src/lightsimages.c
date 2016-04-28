#include <commonincs.h>
#include <lightsimages.h>
#include <lightslogic.h>

static const char* HORIZONTAL_BAR = "oooooo";
static const char* SIDE_BAR = "o";

void DrawSignalLights()
{
    const char* LIGHTS_SPECULAR = "***************";
    unsigned int idx;

    if(GetStatusRed())
    {
        attron(COLOR_PAIR(2));

        for(idx = 6; idx < 15; idx++)
        {
            mvprintw(idx, LIGHTS_FRAME, LIGHTS_SPECULAR);
        }

        attroff(COLOR_PAIR(2));
    }

    if(GetStatusAmber())
    {
        attron(COLOR_PAIR(1));

        for(idx = 16; idx < 25; idx++)
        {
            mvprintw(idx, LIGHTS_FRAME, LIGHTS_SPECULAR);
        }

        attroff(COLOR_PAIR(1));
    }

    if(GetStatusGreen())
    {
        attron(COLOR_PAIR(3));

        for(idx = 26; idx < 35; idx++)
        {
            mvprintw(idx, LIGHTS_FRAME, LIGHTS_SPECULAR);
        }

        attroff(COLOR_PAIR(3));
    }
}

int DrawDigit(const unsigned int DIGIT, const unsigned int XDISP, const unsigned int YDISP)
{
    int rtn;
    unsigned int idx;

    attron(COLOR_PAIR(2));

    switch(DIGIT)
    {
        case 0:
            mvprintw(YDISP, XDISP, HORIZONTAL_BAR);

            for(idx = 0; idx < 6; idx++)
            {
                mvprintw(YDISP + idx, XDISP, SIDE_BAR);
                mvprintw(YDISP + idx, XDISP + 5, SIDE_BAR);
            }

            mvprintw(YDISP + idx, XDISP, HORIZONTAL_BAR);

            rtn = 0;

            break;
        case 1:
            for(idx = 0; idx < 7; idx++)
            {
                mvprintw(YDISP + idx, XDISP + 5, SIDE_BAR);
            }

            rtn = 1;

            break;
        case 2:
            mvprintw(YDISP, XDISP, HORIZONTAL_BAR);

            for(idx = 0; idx < 3; idx++)
            {
                mvprintw(YDISP + idx, XDISP + 5, SIDE_BAR);
            }

            mvprintw(YDISP + idx, XDISP, HORIZONTAL_BAR);

            for(; idx < 6; idx++)
            {
                mvprintw(YDISP + idx, XDISP, SIDE_BAR);
            }

            mvprintw(YDISP + idx, XDISP, HORIZONTAL_BAR);

            rtn = 2;

            break;
        case 3:
            mvprintw(YDISP, XDISP, HORIZONTAL_BAR);

            for(idx = 0; idx < 3; idx++)
            {
                mvprintw(YDISP + idx, XDISP + 5, SIDE_BAR);
            }

            mvprintw(YDISP + idx, XDISP, HORIZONTAL_BAR);

            for(; idx < 6; idx++)
            {
                mvprintw(YDISP + idx, XDISP + 5, SIDE_BAR);
            }

            mvprintw(YDISP + idx, XDISP, HORIZONTAL_BAR);

            rtn = 3;

            break;
        case 4:
            mvprintw(YDISP, XDISP, SIDE_BAR);
            mvprintw(YDISP, XDISP + 5, SIDE_BAR);

            for(idx = 0; idx < 3; idx++)
            {
                mvprintw(YDISP + idx, XDISP, SIDE_BAR);
                mvprintw(YDISP + idx, XDISP + 5, SIDE_BAR);
            }

            mvprintw(YDISP + idx, XDISP, HORIZONTAL_BAR);

            for(; idx < 6; idx++)
            {
                mvprintw(YDISP + idx, XDISP + 5, SIDE_BAR);
            }

            mvprintw(YDISP + idx, XDISP + 5, SIDE_BAR);

            rtn = 4;

            break;
        case 5:
            mvprintw(YDISP, XDISP, HORIZONTAL_BAR);

            for(idx = 0; idx < 3; idx++)
            {
                mvprintw(YDISP + idx, XDISP, SIDE_BAR);
            }

            mvprintw(YDISP + idx, XDISP, HORIZONTAL_BAR);

            for(; idx < 6; idx++)
            {
                mvprintw(YDISP + idx, XDISP + 5, SIDE_BAR);
            }

            mvprintw(YDISP + idx, XDISP, HORIZONTAL_BAR);

            rtn = 5;

            break;
        case 6:
            mvprintw(YDISP, XDISP, HORIZONTAL_BAR);

            for(idx = 0; idx < 3; idx++)
            {
                mvprintw(YDISP + idx, XDISP, SIDE_BAR);
            }

            mvprintw(YDISP + idx, XDISP, HORIZONTAL_BAR);

            for(; idx < 6; idx++)
            {
                mvprintw(YDISP + idx, XDISP, SIDE_BAR);
                mvprintw(YDISP + idx, XDISP + 5, SIDE_BAR);
            }

            mvprintw(YDISP + idx, XDISP, HORIZONTAL_BAR);

            rtn = 6;

            break;
        case 7:
            mvprintw(YDISP, XDISP, HORIZONTAL_BAR);

            for(idx = 0; idx < 7; idx++)
            {
                mvprintw(YDISP + idx, XDISP + 5, SIDE_BAR);
            }

            rtn = 7;

            break;
        case 8:
            mvprintw(YDISP, XDISP, HORIZONTAL_BAR);

            for(idx = 0; idx < 3; idx++)
            {
                mvprintw(YDISP + idx, XDISP, SIDE_BAR);
                mvprintw(YDISP + idx, XDISP + 5, SIDE_BAR);
            }

            mvprintw(YDISP + idx, XDISP, HORIZONTAL_BAR);

            for(; idx < 6; idx++)
            {
                mvprintw(YDISP + idx, XDISP, SIDE_BAR);
                mvprintw(YDISP + idx, XDISP + 5, SIDE_BAR);
            }

            mvprintw(YDISP + idx, XDISP, HORIZONTAL_BAR);

            rtn = 8;

            break;
        case 9:
            mvprintw(YDISP, XDISP, HORIZONTAL_BAR);

            for(idx = 0; idx < 3; idx++)
            {
                mvprintw(YDISP + idx, XDISP, SIDE_BAR);
                mvprintw(YDISP + idx, XDISP + 5, SIDE_BAR);
            }

            mvprintw(YDISP + idx, XDISP, HORIZONTAL_BAR);

            for(; idx < 6; idx++)
            {
                mvprintw(YDISP + idx, XDISP + 5, SIDE_BAR);
            }

            mvprintw(YDISP + idx, XDISP, HORIZONTAL_BAR);

            rtn = 9;

            break;
        default:
            rtn = -1;
            break;
    }

    attroff(COLOR_PAIR(2));

    return rtn;
}

void DrawPedestrianSignal(unsigned int SIGNAL, const unsigned int XDISP, const unsigned int YDISP)
{
    unsigned int idx;
    const unsigned int UPPER_BOUND = 7;

    if(SIGNAL == 0)
        attron(COLOR_PAIR(2)); /* Red. */
    else if(SIGNAL == 1)
        attron(COLOR_PAIR(3)); /* Green */

    /* If green should be a walking man, and if red should be a hand. My art skill has made them blocks! :D */
    for(idx = 0; idx < UPPER_BOUND; idx++)
    {
        mvprintw(YDISP + idx, XDISP, HORIZONTAL_BAR);
    }

    if(SIGNAL == 0)
        attroff(COLOR_PAIR(2));
    else if(SIGNAL == 1)
        attroff(COLOR_PAIR(3));
}
