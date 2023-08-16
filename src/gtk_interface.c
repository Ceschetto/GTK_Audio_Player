#include "../inc/gtk_interface.h"
#include "../inc/file_manager.h"

void draw_app(GtkApplication *app);

GtkApplication *app_init(void)
{

    GtkApplication *app = gtk_application_new("audio.player.tt", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(draw_app), app);
    return app;
}

void draw_app(GtkApplication *app)
{
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Ciao Bellezza");
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);

    g_print("\n The number of file found is: %d\n", count_number_of_file("."));
    print_FNList(enlist_files_name("."));



    

    gtk_widget_set_visible(window, true);
}