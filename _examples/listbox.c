#include <gtk/gtk.h>

static void destroy(GtkWidget *widget, gpointer data)
{
    gtk_main_quit();
}
static gboolean ShowRow(GtkListbox *box, gpointer data )
{
    GtkListBoxRow *selected_row;
    selected_row = gtk_list_box_get_selected_row(box);
    printf("%d ",gtk_list_box_row_get_index(selected_row));
}

int main(int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *listbox;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "ListBox");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(destroy), NULL);

    listbox = gtk_list_box_new();
    gtk_container_add(GTK_CONTAINER(window), listbox);

    for (int i=1; i<10; i++)
    {
        gchar *name = g_strdup_printf("Label %i", i);
        GtkWidget *label = gtk_label_new(name);
        gtk_container_add(GTK_CONTAINER(listbox), label);
    }
    g_signal_connect(listbox,"row-selected",G_CALLBACK(ShowRow),NULL);
    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
