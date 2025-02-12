#include "Plotter.h"
#include "strlib.h"
#include <string>
using namespace std;

void runPlotterScript(istream& input) {
    /* TODO: Delete this line and the one after it, then implement this function. */

    string command;
    PenStyle style = {1,"black"};
    int flag = 0;
    double x_starting = 0;
    double y_starting = 0;
    double x_end;
    double y_end;

    while(!input.eof()){
        input >> command;
        if(toLowerCase(command) == "pendown")
            flag = 1;

        if(toLowerCase(command) == "penup")
            flag = 0;

        if(toLowerCase(command) == "moveabs"){
            input >> x_starting >> y_starting;
            if(flag)
                drawLine(x_starting,y_starting,x_end,y_end,style);
            x_end = x_starting;
            y_end = y_starting;

        }
        if(toLowerCase(command) == "moverel"){
            double parameter1;
            double parameter2;
            input >> parameter1 >> parameter2;
            x_starting += parameter1;
            y_starting += parameter2;
            if(flag)
                drawLine(x_starting,y_starting,x_end,y_end,style);
            x_end = x_starting;
            y_end = y_starting;
        }


        if(toLowerCase(command) == "pencolor"){
            input >> style.color;
        }
        if(toLowerCase(command) == "penwidth"){
            input >> style.width;
        }
    }
}
