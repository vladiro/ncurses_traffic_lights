#include <commonincs.h>
#include <lightsimages.h>

static const char* HORIZONTAL_BAR = "oooooo";
static const char* SIDE_BAR = "o";

int DrawDigit(const unsigned int DIGIT, const unsigned int XDISP, const unsigned int YDISP)
{
    int rtn, idx;

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
            rtn = 4;
            break;
        case 5:
            rtn = 5;
            break;
        case 6:
            rtn = 6;
            break;
        case 7:
            rtn = 7;
            break;
        case 8:
            rtn = 8;
            break;
        case 9:
            rtn = 9;
            break;
        default:
            rtn = -1;
            break;
    }

    attroff(COLOR_PAIR(2));

    return rtn;
}
