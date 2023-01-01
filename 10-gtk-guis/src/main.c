#include <gtk/gtk.h>

int count = 0;

void end_program(GtkWidget *wid, gpointer ptr){
    gtk_main_quit();
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
    GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    
    // Creating GTK butten widget with label
    GtkWidget *btn = gtk_button_new_with_label("Close Window");
    GtkWidget *btn2 = gtk_button_new_with_label("Add Count");

    // Adding a label
    GtkWidget *lbl = gtk_label_new("My Label");
    
    // add callback function to button clicked and close app events
    g_signal_connect(btn, "clicked", G_CALLBACK(end_program), NULL);
    g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);
    // added lbl as ptr for callback function. This can be any pointer that the
    // callback function might used/need
    g_signal_connect(btn2, "clicked", G_CALLBACK(button_counter), lbl);

    // Switching to Tables instead of Box
    // Table was deprecated in place of GtkGrid so switched to that instead
    GtkWidget *grid = gtk_grid_new();
    gtk_grid_attach(GTK_GRID(grid), lbl, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), btn2, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), btn, 0, 1, 2, 1);

    // Add Box widget to window
    gtk_container_add(GTK_CONTAINER(win), grid);

    // Show the window widget
    gtk_widget_show_all(win);

    // Run the main loop
    gtk_main();

    return 0;
}
