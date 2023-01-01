#include <gtk/gtk.h>

void end_program(GtkWidget *wid, gpointer ptr){
    gtk_main_quit();
}

int main (int argc, char *argv[]){
    gtk_init(&argc, &argv);
    // Creating a GTK window
    GtkWidget *win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    // Creating GTK butten widget with label
    GtkWidget *btn = gtk_button_new_with_label("Close Window");
    // add callback function to button clicked and close app events
    g_signal_connect(btn, "clicked", G_CALLBACK(end_program), NULL);
    g_signal_connect(win, "delete_event", G_CALLBACK(end_program), NULL);
    // Store the button in the window to be displayed
    gtk_container_add(GTK_CONTAINER(win), btn);
    // Show the window widget
    gtk_widget_show_all(win);
    // Run the main loop
    gtk_main();
    return 0;
}
