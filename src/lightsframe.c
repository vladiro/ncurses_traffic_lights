#include <commonincs.h>
#include <lightsframe.h>

#define LIGHTS_FRAME 37
#define LEFT_MARGIN 35
#define RIGHT_MARGIN 52
#define PED_LEFT_MARGIN 21

static const char* TOP_BOTTOM = "XXXXXXXXXXXXXXXXXXX";
static const char* SIDES = "XX";

static const char* PEDESTRIAN_TOP_BOTTOM = "XXXXXXXXXXXXXX";
static const char* PEDESTRIAN_SIDE = "XX";

void DrawSignalInit()
{
    mvprintw(1, 20, "Traffic Lights Using NCurses");
    mvprintw(3, 20, "Esc to quit.");

    start_color();

    init_pair(1, COLOR_BLACK, COLOR_YELLOW);
    init_pair(2, COLOR_BLACK, COLOR_RED);
    init_pair(4, COLOR_BLACK, COLOR_GREEN);
}

void DrawLightsFrame()
{
    unsigned int idx;

    attron(COLOR_PAIR(1));

    mvprintw(5, LEFT_MARGIN, TOP_BOTTOM);

    for(idx = 6; idx < 15; idx++)
    {
        mvprintw(idx, LEFT_MARGIN, SIDES);
        mvprintw(idx, RIGHT_MARGIN, SIDES);
    }

    mvprintw(15, LEFT_MARGIN, TOP_BOTTOM);

    for(idx = 16; idx < 25; idx++)
    {
        mvprintw(idx, LEFT_MARGIN, SIDES);
        mvprintw(idx, RIGHT_MARGIN, SIDES);
    }

    mvprintw(25, LEFT_MARGIN, TOP_BOTTOM);

    for(idx = 26; idx < 35; idx++)
    {
        mvprintw(idx, LEFT_MARGIN, SIDES);
        mvprintw(idx, RIGHT_MARGIN, SIDES);
    }

    mvprintw(35, LEFT_MARGIN, TOP_BOTTOM);

    attroff(COLOR_PAIR(1));
}

void DrawSignalLights()
{
    const char* LIGHTS_SPECULAR = "***************";
    unsigned int idx;

    attron(COLOR_PAIR(2));

    for(idx = 6; idx < 15; idx++)
    {
        mvprintw(idx, LIGHTS_FRAME, LIGHTS_SPECULAR);
    }

    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(1));

    for(idx = 16; idx < 25; idx++)
    {
        mvprintw(idx, LIGHTS_FRAME, LIGHTS_SPECULAR);
    }

    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(4));

    for(idx = 26; idx < 35; idx++)
    {
        mvprintw(idx, LIGHTS_FRAME, LIGHTS_SPECULAR);
    }

    attroff(COLOR_PAIR(4));

}

void DrawPedestrianLightsFrame()
{
    unsigned int idx;

    attron(COLOR_PAIR(1));

    mvprintw(10, PED_LEFT_MARGIN, PEDESTRIAN_TOP_BOTTOM);

    for(idx = 11; idx < 17; idx++)
    {
        mvprintw(idx, PED_LEFT_MARGIN, PEDESTRIAN_SIDE);
    }

    mvprintw(17, PED_LEFT_MARGIN, PEDESTRIAN_TOP_BOTTOM);

    attroff(COLOR_PAIR(1));
}

void DrawSignalRefresh()
{
    refresh();
}
