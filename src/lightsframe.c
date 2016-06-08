#include <commonincs.h>
#include <lightsframe.h>

static const char* TOP_BOTTOM = "XXXXXXXXXXXXXXXXXXX";
static const char* SIDES = "XX";

static const char* PEDESTRIAN_TOP_BOTTOM = "XXXXXXXXXXXXXXXXXXXX";
static const char* PEDESTRIAN_SIDE = "XX";

void DrawSignalInit()
{
    mvprintw(1, 14, "Traffic Signals Using NCurses");
    mvprintw(3, 14, "Esc to quit.");

    start_color();

    init_pair(1, COLOR_BLACK, COLOR_YELLOW);
    init_pair(2, COLOR_BLACK, COLOR_RED);
    init_pair(3, COLOR_BLACK, COLOR_GREEN);
}

void DrawLightsFrame()
{
    unsigned int idx;

    attron(COLOR_PAIR(1));

    mvprintw(5, LEFT_MARGIN, TOP_BOTTOM);

    for(idx = MAIN_SIGNAL_FRAME_LOWER_BOUND_ITERATOR; idx < MAIN_SIGNAL_FRAME_UPPER_BOUND_ITERATOR; idx++)
    {
        mvprintw(idx, LEFT_MARGIN, SIDES);
        mvprintw(idx, RIGHT_MARGIN, SIDES);
    }

    mvprintw(MAIN_SIGNAL_FRAME_UPPER_BOUND_ITERATOR, LEFT_MARGIN, TOP_BOTTOM);

    for(idx = MAIN_SIGNAL_FRAME_LOWER_BOUND_ITERATOR + MAIN_SIGNAL_FRAME_ITERATOR_DISPLACEMENT; idx < MAIN_SIGNAL_FRAME_UPPER_BOUND_ITERATOR + MAIN_SIGNAL_FRAME_ITERATOR_DISPLACEMENT; idx++)
    {
        mvprintw(idx, LEFT_MARGIN, SIDES);
        mvprintw(idx, RIGHT_MARGIN, SIDES);
    }

    mvprintw(MAIN_SIGNAL_FRAME_UPPER_BOUND_ITERATOR + MAIN_SIGNAL_FRAME_ITERATOR_DISPLACEMENT, LEFT_MARGIN, TOP_BOTTOM);

    for(idx = MAIN_SIGNAL_FRAME_LOWER_BOUND_ITERATOR + 2 * MAIN_SIGNAL_FRAME_ITERATOR_DISPLACEMENT; idx < MAIN_SIGNAL_FRAME_UPPER_BOUND_ITERATOR + 2 * MAIN_SIGNAL_FRAME_ITERATOR_DISPLACEMENT; idx++)
    {
        mvprintw(idx, LEFT_MARGIN, SIDES);
        mvprintw(idx, RIGHT_MARGIN, SIDES);
    }

    mvprintw(MAIN_SIGNAL_FRAME_UPPER_BOUND_ITERATOR + 2 * MAIN_SIGNAL_FRAME_ITERATOR_DISPLACEMENT, LEFT_MARGIN, TOP_BOTTOM);

    attroff(COLOR_PAIR(1));
}

void DrawPedestrianLightsFrame()
{
    unsigned int idx;

    attron(COLOR_PAIR(1));

    mvprintw(15, PED_LEFT_MARGIN, PEDESTRIAN_TOP_BOTTOM);

    for(idx = PED_SIGNAL_FRAME_LOWER_BOUND_ITERATOR; idx < PED_SIGNAL_FRAME_UPPER_BOUND_ITERATOR; idx++)
    {
        mvprintw(idx, PED_LEFT_MARGIN, PEDESTRIAN_SIDE);
    }

    mvprintw(25, PED_LEFT_MARGIN, PEDESTRIAN_TOP_BOTTOM);

    for(idx = PED_SIGNAL_FRAME_LOWER_BOUND_ITERATOR + PED_SIGNAL_FRAME_ITERATOR_DISPLACEMENT; idx < PED_SIGNAL_FRAME_UPPER_BOUND_ITERATOR + PED_SIGNAL_FRAME_ITERATOR_DISPLACEMENT; idx++)
    {
        mvprintw(idx, PED_LEFT_MARGIN, PEDESTRIAN_SIDE);
    }

    mvprintw(35, PED_LEFT_MARGIN, PEDESTRIAN_TOP_BOTTOM);

    attroff(COLOR_PAIR(1));
}

void DrawSignalRefresh()
{
    refresh();
}
