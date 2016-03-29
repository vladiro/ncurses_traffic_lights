#include <commonincs.h>
#include <lightsframe.h>

#define LEFT_MARGIN 35
#define RIGHT_MARGIN 42

static const char* TOP_BOTTOM = "XXXXXXXXX";
static const char* SIDES = "XX";

#define LIGHTS_FRAME 37

void DrawSignalInit()
{
    mvprintw(1, 24, "Traffic Lights Using NCurses");
    mvprintw(3, 24, "'q' to quit.");

    start_color();
}

void DrawLightsFrame()
{
    init_pair(1, COLOR_BLACK, COLOR_YELLOW);

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

    init_pair(2, COLOR_BLACK, COLOR_RED);
    init_pair(3, COLOR_BLACK, COLOR_YELLOW);
    init_pair(4, COLOR_BLACK, COLOR_GREEN);

    attron(COLOR_PAIR(2));

    mvprintw(6, LIGHTS_FRAME, LIGHTS_SPECULAR);
    mvprintw(7, LIGHTS_FRAME, LIGHTS_SPECULAR);
    mvprintw(8, LIGHTS_FRAME, LIGHTS_SPECULAR);

    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(3));

    mvprintw(10, LIGHTS_FRAME, LIGHTS_SPECULAR);
    mvprintw(11, LIGHTS_FRAME, LIGHTS_SPECULAR);
    mvprintw(12, LIGHTS_FRAME, LIGHTS_SPECULAR);

    attroff(COLOR_PAIR(3));

    attron(COLOR_PAIR(4));

    mvprintw(14, LIGHTS_FRAME, LIGHTS_SPECULAR);
    mvprintw(15, LIGHTS_FRAME, LIGHTS_SPECULAR);
    mvprintw(16, LIGHTS_FRAME, LIGHTS_SPECULAR);

    attroff(COLOR_PAIR(4));
}

void DrawSignalRefresh()
{
    refresh();
}
