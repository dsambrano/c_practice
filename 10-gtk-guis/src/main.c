#include <gtk/gtk.h>
#include <stdio.h>

int count = 0;
GtkWidget *text_box;

void end_program(GtkWidget *wid, gpointer ptr){
    gtk_main_quit();
}

void copy_text(GtkWidget *wid, gpointer ptr){
    const char *input = gtk_entry_get_text(GTK_ENTRY(text_box));
    printf("%s\n", "yes");
    char output[20] = "test";
    gtk_label_set_text(GTK_LABEL(ptr), output);
}

void button_counter(GtkWidget *wid, gpointer ptr){
    char updated_label_with_count[30];
    count ++;
    sprintf(updated_label_with_count, "Button Pressed %d Times", count);
    gtk_label_set_text(GTK_LABEL(ptr), updated_label_with_count);
}

int main (int argc, char *argv[]){

    // Initialize GTK
    gtk_init(&argc, &argv);
    
    // Creating a GTK window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    
    // Creating GTK butten widget with label
    GtkWidget *close_button = gtk_button_new_with_label("Close Window");
    GtkWidget *count_button = gtk_button_new_with_label("Add Count");
    GtkWidget *copy_button = gtk_button_new_with_label("Copy Text");
    // Adding Text box for Typing
    GtkWidget *text_box = gtk_entry_new_with_buffer(gtk_entry_buffer_new("Test Text", 10));

    // Adding a label
    GtkWidget *lbl = gtk_label_new("My Label");
    
    // add callback function to button clicked and close app events
    g_signal_connect(close_button, "clicked", G_CALLBACK(end_program), NULL);
    g_signal_connect(window, "delete_event", G_CALLBACK(end_program), NULL);
    // added lbl as ptr for callback function. This can be any pointer that the
    // callback function might used/need
    struct data {
        GtkWidget *label;
        GtkWidget *box;
    };

    g_signal_connect(count_button, "clicked", G_CALLBACK(button_counter), lbl);
    struct data pointers;
    pointers.box = text_box;
    pointers.label = lbl;
    // callback function might used/need
    g_signal_connect(copy_button, "clicked", G_CALLBACK(copy_text), lbl);

    // Switching to Tables instead of Box
    // Table was deprecated in place of GtkGrid so switched to that instead
    GtkWidget *grid = gtk_grid_new();
    // Row, Column, Width, Height
    gtk_grid_attach(GTK_GRID(grid), lbl, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), count_button, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), close_button, 0, 1, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), copy_button, 0, 2, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), text_box, 0, 3, 2, 1);

    // Add Box widget to window
    gtk_container_add(GTK_CONTAINER(window), grid);

    // Show the window widget
    gtk_widget_show_all(window);

    // Run the main loop
    gtk_main();

    return 0;
}
