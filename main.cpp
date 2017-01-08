#include <iostream>
#include <string>
#include <QApplication>

#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Dialog *dialog = new Dialog();

    for(int i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], "-h") == 0)
        {
            std::cout << "Usage: " << argv[0] << " [OPTIONS]" << std::endl << std::endl;
            std::cout << "Available options:" << std::endl;
            std::cout << "-h       Writes this message and exits." << std::endl;
            std::cout << "-t <n>   Time in seconds for the progress bar. Default is 60." << std::endl;

            return 0;
        }

        else if(strcmp(argv[i], "-t") == 0)
        {
            try
            {
                dialog->setTime(atol(argv[++i]));
            }
            catch(std::string const& e)
            {
                std::cerr << "Error: " << e << std::endl;
                return 1;
            }
        }
    }

    dialog->show();
    dialog->run();

    return a.exec();
}
