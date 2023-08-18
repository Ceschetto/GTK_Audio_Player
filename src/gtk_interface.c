#include "../inc/gtk_interface.h"
#include "../inc/file_manager.h"


struct gen_list_box_data
{
    GtkWidget *ListB;
    GtkEntryBuffer *EntryBuffer;

};


void gen_list_box(void * data);
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

    // grande box che conterrà tutti ciò che servirà
    GtkWidget *bigBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    gtk_window_set_child(GTK_WINDOW(window), bigBox);
    // conterra l'enty per poter inserire la cartella e sotto comparirà lista con i nomi dei file
    GtkWidget *rightBox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);
    // griglia che conterrà il nostro player audio con i bottoni e se dio vuole anche una specie di visualizzatore
    GtkWidget *leftGrid = gtk_grid_new();



    gtk_box_append(GTK_BOX(bigBox), rightBox);
    gtk_box_append(GTK_BOX(bigBox), leftGrid);

    GtkWidget *rightUpperBox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 2);
    gtk_box_append(GTK_BOX(rightBox), rightUpperBox);



    GtkEntryBuffer *EntryTextBuffer = gtk_entry_buffer_new("Inserire percorso", 256);
    GtkWidget *textEntry = gtk_entry_new_with_buffer(EntryTextBuffer);
    gtk_box_append(GTK_BOX(rightUpperBox), textEntry);


    GtkWidget * button = gtk_button_new_with_label(">");
    gtk_box_append(GTK_BOX(rightUpperBox), button);

//A list box that will hold the labels
    GtkWidget *listBox = gtk_list_box_new(); 
    gtk_box_append(GTK_BOX(rightBox), listBox);


    struct gen_list_box_data *buttonData = ( struct gen_list_box_data *) calloc(1, sizeof( struct gen_list_box_data));
    buttonData->EntryBuffer = EntryTextBuffer;
    buttonData->ListB = listBox;

    g_signal_connect_swapped(button, "clicked", G_CALLBACK(gen_list_box), buttonData);


    gtk_widget_set_visible(window, true);
}


void gen_list_box(void * data)
{
    //calcallare la precedente ricerca prima di generare un'altra lista
    struct gen_list_box_data *dataPtr = (struct gen_list_box_data *) data;

    GtkWidget *label = NULL;

    FileNameNodePtr currentFileNode;
    currentFileNode = enlist_files_name(gtk_entry_buffer_get_text(dataPtr->EntryBuffer));

    while (currentFileNode != NULL)
    {
        label = gtk_label_new(currentFileNode->FileName);
        gtk_list_box_append(GTK_LIST_BOX(dataPtr->ListB), label);
        currentFileNode = get_next_file_node(currentFileNode);
    }    

}

