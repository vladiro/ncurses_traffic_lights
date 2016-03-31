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
    attron(COLOR_PAIR(1));

    mvprintw(5, LEFT_MARGIN, TOP_BOTTOM);
    mvprintw(6, LEFT_MARGIN, SIDES);
    mvprintw(6, RIGHT_MARGIN, SIDES);
    mvprintw(7, LEFT_MARGIN, SIDES);
    mvprintw(7, RIGHT_MARGIN, SIDES);
    mvprintw(8, LEFT_MARGIN, SIDES);
    mvprintw(8, RIGHT_MARGIN, SIDES);
    mvprintw(9, LEFT_MARGIN, TOP_BOTTOM);

    mvprintw(10, LEFT_MARGIN, SIDES);
    mvprintw(10, RIGHT_MARGIN, SIDES);
    mvprintw(11, LEFT_MARGIN, SIDES);
    mvprintw(11, RIGHT_MARGIN, SIDES);
    mvprintw(12, LEFT_MARGIN, SIDES);
    mvprintw(12, RIGHT_MARGIN, SIDES);
    mvprintw(13, LEFT_MARGIN, TOP_BOTTOM);

    mvprintw(14, LEFT_MARGIN, SIDES);
    mvprintw(14, RIGHT_MARGIN, SIDES);
    mvprintw(15, LEFT_MARGIN, SIDES);
    mvprintw(15, RIGHT_MARGIN, SIDES);
    mvprintw(16, LEFT_MARGIN, SIDES);
    mvprintw(16, RIGHT_MARGIN, SIDES);
    mvprintw(17, LEFT_MARGIN, TOP_BOTTOM);

    attroff(COLOR_PAIR(1));
}

void DrawSignalLights()
{
    const char* LIGHTS_SPECULAR = "*****";

    attron(COLOR_PAIR(2));

    mvprintw(6, LIGHTS_FRAME, LIGHTS_SPECULAR);
    mvprintw(7, LIGHTS_FRAME, LIGHTS_SPECULAR);
    mvprintw(8, LIGHTS_FRAME, LIGHTS_SPECULAR);

    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(1));

    mvprintw(10, LIGHTS_FRAME, LIGHTS_SPECULAR);
    mvprintw(11, LIGHTS_FRAME, LIGHTS_SPECULAR);
    mvprintw(12, LIGHTS_FRAME, LIGHTS_SPECULAR);

    attroff(COLOR_PAIR(1));

    attron(COLOR_PAIR(4));

    mvprintw(14, LIGHTS_FRAME, LIGHTS_SPECULAR);
    mvprintw(15, LIGHTS_FRAME, LIGHTS_SPECULAR);
    mvprintw(16, LIGHTS_FRAME, LIGHTS_SPECULAR);

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
