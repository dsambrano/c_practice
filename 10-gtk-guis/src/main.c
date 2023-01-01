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

    // Adding a label
    GtkWidget *lbl = gtk_label_new("My Label");

    // Adding Box to store all widgets
    // Creates a Vertical box with 5 pixels of spacing
    GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    // Add all widgets to box
    // Adds to lbl to box with expand and fill set to true and 0 padding
    gtk_box_pack_start(GTK_BOX(box), lbl, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(box), btn, TRUE, TRUE, 0);
    // Add Box widget to window
    gtk_container_add(GTK_CONTAINER(win), box);

    // Show the window widget
    gtk_widget_show_all(win);
    // Run the main loop
    gtk_main();
    return 0;
}
