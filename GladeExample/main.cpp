#include <gtk/gtk.h>
#include <iostream>
GtkWidget *button_Widget;
	GtkWidget *label1, *textView;
void destroy(GtkWidget *widget, gpointer data){
    gtk_main_quit();
}
static void on_applyButton_clicked(GtkWidget *button, gpointer data){

    std::cout<<"Button1 clicked"<<std::endl;
    gtk_label_set_text((GtkLabel*)label1,(char*)gtk_entry_get_text ((GtkEntry*)textView));

	}
int main (int argc, char *argv[])
{
  GtkBuilder      *builder;
  GtkWidget       *window;

  gtk_init (&argc, &argv);
  builder = gtk_builder_new ();
  GError *err = NULL;
  if(0 == gtk_builder_add_from_file (builder, "win.glade", &err)){
  fprintf(stderr, "Error adding build from file. Error: %s\n", err->message);
  return 0;
}

  window = GTK_WIDGET (gtk_builder_get_object (builder, "dialog1"));
  button_Widget =  GTK_WIDGET (gtk_builder_get_object (builder, "button1"));
    label1 =  GTK_WIDGET (gtk_builder_get_object (builder, "label1"));
		  textView =  GTK_WIDGET (gtk_builder_get_object (builder, "entry1"));
    //  gtk_builder_connect_signals (builder, NULL);
    //add destory function callback
    g_signal_connect((gpointer) window, "destroy", G_CALLBACK(destroy), NULL);
    g_signal_connect((gpointer) button_Widget, "clicked",
   	                     G_CALLBACK(on_applyButton_clicked), NULL);
    g_object_unref (G_OBJECT (builder));

    gtk_widget_show (window);
    gtk_main ();

    return 0;
}
