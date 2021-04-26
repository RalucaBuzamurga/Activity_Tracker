#include "View/MainWindowView.h"
#include "Model/Date.h"
#include <iostream>
int main(int argc, char *argv[])
{
    MainWindowView::showActivity(argc, argv);
    Date date = Date(2020, 123, 12);
    if(date.isAcceptable())
        std::cout << "data valida";
    else
        std::cout << "Data non valida\n";
    std::cout << date.getYear() << " " << date.getMonth() << " " << date.getDay();

    return 0;
}

