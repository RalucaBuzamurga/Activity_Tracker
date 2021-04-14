
#include <iterator>
#include "View/MainWindowView.h"


int main(int argc, char *argv[])
{
    MainWindowView* window = new MainWindowView;
    window->showActivity(argc, argv);
}
