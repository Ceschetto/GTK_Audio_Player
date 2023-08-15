#include "../inc/gtk_interface.h"

int main(int argc, char **argv)
{
    
    return g_application_run( G_APPLICATION(app_init()), argc, argv);

}