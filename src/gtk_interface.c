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

    //grande box che conterrà tutti ciò che servirà
    GtkWidget *bigBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    gtk_window_set_child(GTK_WINDOW(window), bigBox);
    //conterra l'enty per poter inserire la cartella e sotto comparirà lista con i nomi dei file
    GtkWidget *rightBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    //griglia che conterrà il nostro player audio con i bottoni e se dio vuole anche una specie di visualizzatore
    GtkWidget *leftGrid = gtk_grid_new();

    gtk_box_append(GTK_BOX(bigBox), rightBox);
    gtk_box_append(GTK_BOX(bigBox), leftGrid);


    GtkEntryBuffer *EntryTextBuffer = gtk_entry_buffer_new("Inserire percorso cartella audio", 34);
    GtkWidget *textEntry = gtk_entry_new_with_buffer( EntryTextBuffer );

    gtk_box_append(GTK_BOX(rightBox), textEntry);






    g_print("\n The number of file found is: %d\n", count_number_of_file("."));
    print_FNList(enlist_files_name("."));



    

    gtk_widget_set_visible(window, true);
}