#include <iostream>
#include <pqxx/pqxx>
#include <gtk/gtk.h>
#include <glib/gstdio.h>
#include <limits>
#include <string>
#include "../include/dao.h"
#include "../include/empresa.h"
#include "../include/global.h"
#include "../include/io_functions.h"


#define SCREEN_W 700
#define SCREEN_H SCREEN_W * 3/4



static void
print_hello (GtkWidget *widget,
             gpointer   data)
{
  g_print ("Hello World\n");
}


GtkWidget * create_veicle_row(Veiculo* vl){
  GtkWidget* linha;
  GtkWidget* placa;
  GtkWidget* nome;
  GtkWidget* marca;
  GtkWidget* ano;
  GtkWidget* divisoria1;
  GtkWidget* divisoria2;
  GtkWidget* divisoria3;
  GtkWidget* divisoria4;
  GtkWidget* divisoria5;
  GtkWidget* box;
  GtkWidget* icone;

  linha = gtk_list_box_row_new();

  placa = gtk_label_new(vl->get_placa().c_str());
    gtk_widget_set_hexpand(placa, true);
  nome = gtk_label_new(vl->get_nome().c_str());
    gtk_widget_set_hexpand(nome, true);
  marca = gtk_label_new(vl->get_marca().c_str());
    gtk_widget_set_hexpand(marca, true);
  ano = gtk_label_new(std::to_string(vl->get_ano()).c_str());
    gtk_widget_set_hexpand(ano, true);
  box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

  if(vl->get_valor_venda() == 0){
    icone = gtk_image_new_from_icon_name("software-update-urgent");
  }else{
    icone = gtk_image_new_from_icon_name("emblem-default");
  }
  

  divisoria1 = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
  divisoria2 = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
  divisoria3 = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
  divisoria4 = gtk_separator_new(GTK_ORIENTATION_VERTICAL);
  divisoria5 = gtk_separator_new(GTK_ORIENTATION_VERTICAL);

  gtk_box_append(GTK_BOX(box), nome);
  gtk_box_append(GTK_BOX(box), divisoria1);
  gtk_box_append(GTK_BOX(box), marca);
  gtk_box_append(GTK_BOX(box), divisoria2);
  gtk_box_append(GTK_BOX(box), ano);
  gtk_box_append(GTK_BOX(box), divisoria3);
  gtk_box_append(GTK_BOX(box), placa);
  gtk_box_append(GTK_BOX(box), divisoria4);
  gtk_box_append(GTK_BOX(box), icone);

  gtk_list_box_row_set_child(GTK_LIST_BOX_ROW(linha), box);

  return linha;

}

void instancia_nome(GtkBox* parent_box ){
  //Texto logo
  GtkWidget *logo;

  //instacia imagem do logo
  logo = gtk_label_new("Gerenciador de garagem");
  gtk_widget_set_size_request(GTK_WIDGET(logo), SCREEN_W * 3/8, SCREEN_W * 1.25/6);
  
  //determia tamanho do logo
  gtk_widget_set_halign(logo,  GTK_ALIGN_START);

  gtk_box_append(GTK_BOX (parent_box), logo);
}

void instancia_lista(GtkBox* parent_box ){

  //lista
  GtkWidget *lista_veiculos;
  //coponetes da lista
  GtkWidget *linha;
  //frame lista
  GtkWidget * lista_frame;

  //frame da lista
  lista_frame = gtk_frame_new("Lista de carros");
    //determina margem
    gtk_widget_set_margin_top(GTK_WIDGET(lista_frame), 10 );
    gtk_widget_set_margin_bottom(GTK_WIDGET(lista_frame), 10 );
    gtk_widget_set_margin_start(GTK_WIDGET(lista_frame), 10 );
    gtk_widget_set_margin_end(GTK_WIDGET(lista_frame), 10 );
    //instancia lista 
    lista_veiculos = gtk_list_box_new();
    gtk_widget_set_size_request(GTK_WIDGET(lista_veiculos), SCREEN_W * 5/8, SCREEN_H * 5/6);

  for(int i =0; i<global::dao->veiculo.size(); i++){
    linha = create_veicle_row(global::dao->veiculo[i]);
     gtk_list_box_append(GTK_LIST_BOX(lista_veiculos), linha);
  }
  
  // a linha é adicionada a lista
    gtk_frame_set_child(GTK_FRAME(lista_frame), lista_veiculos);

    gtk_box_append(GTK_BOX (parent_box), lista_frame);
}

void instancia_balanco(GtkBox* parent_box ){
 
  //frame balanço
  GtkWidget *balanco_frame;
  //escritas
  GtkWidget *nome;
  GtkWidget *saldo_veiculos;
  GtkWidget *d_funcionarios;
  GtkWidget *n_veiculos_venda;
  GtkWidget *n_funcionarios;
  GtkWidget *total_vendas;

  stringstream escrita;

  GtkWidget *box;

  Empresa* empresa = new Empresa(global::dao, "Garagem Santos");


  balanco_frame = gtk_frame_new("Balanço");
    gtk_frame_set_label_align(GTK_FRAME(balanco_frame), 0.5);

    gtk_widget_set_size_request(GTK_WIDGET(balanco_frame), SCREEN_W * 3/8, SCREEN_H * 2/6);

    gtk_widget_set_margin_top(GTK_WIDGET(balanco_frame), 10 );
    gtk_widget_set_margin_bottom(GTK_WIDGET(balanco_frame), 10 );
    gtk_widget_set_margin_start(GTK_WIDGET(balanco_frame), 10 );
    gtk_widget_set_margin_end(GTK_WIDGET(balanco_frame), 10 );

  box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);

  std::setprecision(2);
  

  nome = gtk_label_new(empresa->nome.c_str());

  escrita << "Saldo dos veículos: " << empresa->saldo_veiculos;
  saldo_veiculos = gtk_label_new(escrita.str().c_str());

  escrita.str("");
  escrita << "Salario dos funcoinarios: " << empresa->despesas_funcionarios;
  d_funcionarios = gtk_label_new(escrita.str().c_str());

  escrita.str("");
  escrita << "Veiculos a venda: " << empresa->numero_veiculos_venda;
  n_veiculos_venda = gtk_label_new(escrita.str().c_str());

  escrita.str("");
  escrita << "Funcionarios: " << empresa->numero_funcionarios;
  n_funcionarios = gtk_label_new(escrita.str().c_str());

  escrita.str("");
  escrita << "Total de vendas:  " << empresa->total_vendas;
  total_vendas = gtk_label_new(escrita.str().c_str());


  gtk_box_append(GTK_BOX (box), nome);
  gtk_box_append(GTK_BOX (box), saldo_veiculos);
  gtk_box_append(GTK_BOX (box), d_funcionarios);
  gtk_box_append(GTK_BOX (box), n_veiculos_venda);
  gtk_box_append(GTK_BOX (box), n_funcionarios);
  gtk_box_append(GTK_BOX (box), total_vendas);

  gtk_frame_set_child(GTK_FRAME(balanco_frame), box);

  gtk_box_append(GTK_BOX (parent_box), balanco_frame);
  
}

void instancia_funcionario(GtkBox* parent_box ){
  GtkWidget *box_f_mes;
  //frame funcionario
  GtkWidget *f_mes_frame;
  //box
  GtkWidget *box;
  //Imagens
  GtkWidget *perfil;
  //dados
  GtkWidget *nome;
  GtkWidget *vendas;
  GtkWidget *funcao;

  //botao
  

  int melhor = 0;
  std::stringstream escrita1;
  std::stringstream escrita2;

  f_mes_frame = gtk_frame_new("Funcionario do mês");
    gtk_frame_set_label_align(GTK_FRAME(f_mes_frame), 0.5);

    gtk_widget_set_size_request(GTK_WIDGET(f_mes_frame), SCREEN_W * 3/8, SCREEN_H * 3/6);

    gtk_widget_set_margin_top(GTK_WIDGET(f_mes_frame), 10 );
    gtk_widget_set_margin_bottom(GTK_WIDGET(f_mes_frame), 10 );
    gtk_widget_set_margin_start(GTK_WIDGET(f_mes_frame), 10 );
    gtk_widget_set_margin_end(GTK_WIDGET(f_mes_frame), 10 );

    box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 20);
    perfil = gtk_image_new_from_file("./images/foto_perfil.png");
    gtk_image_set_pixel_size(GTK_IMAGE(perfil), SCREEN_H /7 );
    gtk_widget_set_margin_top(perfil, 10);
    gtk_box_append(GTK_BOX(box), perfil);

    for(int i = 0; i<global::dao->funcionario.size(); i++){
      if(global::dao->funcionario[i]->get_vendas() > melhor){
        melhor = i;
      }
    }

    nome = gtk_label_new(global::dao->funcionario[melhor]->get_nome().c_str());
    escrita1 << "Numero de vendas: " << global::dao->funcionario[melhor]->get_vendas();
    vendas = gtk_label_new(escrita1.str().c_str());
    escrita2 << "Cargo: " << global::dao->funcionario[melhor]->get_funcao();
    funcao = gtk_label_new(escrita2.str().c_str());

    

    gtk_box_append(GTK_BOX(box), nome);
    gtk_box_append(GTK_BOX(box), vendas);
    gtk_box_append(GTK_BOX(box), funcao);

    gtk_frame_set_child(GTK_FRAME(f_mes_frame), box);


    gtk_box_append(GTK_BOX (parent_box), f_mes_frame);
    
}
void instancia_b_adiciona_remove(GtkBox* parent_box ){
  //botoes
  GtkWidget *b_adiciona;
  GtkWidget *b_remove;
  GtkWidget *b_edita;
  GtkWidget *b_mostra;
  GtkWidget *box;

  //instancia os botoes
  b_adiciona = gtk_button_new_with_label ("Adicionar veiculo");
    gtk_widget_set_margin_start(GTK_WIDGET(b_adiciona), 10);
    gtk_widget_set_hexpand(GTK_WIDGET(b_adiciona), true);
  

  b_remove = gtk_button_new_with_label ("Remover veiculo");
    gtk_widget_set_margin_end(GTK_WIDGET(b_remove), 10);
    gtk_widget_set_hexpand(GTK_WIDGET(b_remove), true);

  b_mostra = gtk_button_new_with_label ("Mostrar +");
    gtk_widget_set_hexpand(GTK_WIDGET(b_remove), true);
  
  b_edita = gtk_button_new_with_label ("Editar");
    gtk_widget_set_margin_end(GTK_WIDGET(b_edita), 10);
    gtk_widget_set_hexpand(GTK_WIDGET(b_edita), true);

  //determina a ação deles
  g_signal_connect (b_adiciona, "clicked", G_CALLBACK (add_veiculo), NULL);
  g_signal_connect (b_remove, "clicked", G_CALLBACK (rm_veiculo), NULL);
  g_signal_connect (b_edita, "clicked", G_CALLBACK (mod_veiculo), NULL);
  g_signal_connect (b_mostra, "clicked", G_CALLBACK (print_veiculos), NULL);

  box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

  gtk_widget_set_size_request(GTK_WIDGET(box), SCREEN_W * 5/8, SCREEN_H * 0.075/6);

  gtk_box_append(GTK_BOX (box), b_adiciona);
  gtk_box_append(GTK_BOX (box), b_remove);
  gtk_box_append(GTK_BOX (box), b_mostra);
  gtk_box_append(GTK_BOX (box), b_edita);

  gtk_box_append(GTK_BOX (parent_box), box);
}

void instancia_extra_direita(GtkBox* parent_box ){
  //botoes
  GtkWidget *b_adiciona_f;
  GtkWidget *b_remove_f;
  GtkWidget *b_mostra_f;
  GtkWidget *b_edita_f;
  GtkWidget *box0;
  GtkWidget *box1;

  GtkWidget *b_adiciona_c;
  GtkWidget *b_remove_c;
  GtkWidget *b_mostra_c;
  GtkWidget *b_edita_c;
  GtkWidget *box2;
  GtkWidget *box3;

    //instancia os botoes
  b_adiciona_f = gtk_button_new_with_label("Adicionar");
  gtk_widget_set_hexpand(GTK_WIDGET(b_adiciona_f), true);
  gtk_widget_set_margin_start(GTK_WIDGET(b_adiciona_f), 10);
  gtk_widget_set_margin_top(GTK_WIDGET(b_adiciona_f), 2);

  b_remove_f = gtk_button_new_with_label("Remover");
  gtk_widget_set_hexpand(GTK_WIDGET(b_remove_f), true);
  gtk_widget_set_margin_end(GTK_WIDGET(b_remove_f), 10);
  gtk_widget_set_margin_top(GTK_WIDGET(b_remove_f), 2);

  b_mostra_f = gtk_button_new_with_label("Mostrar funcionarios");
  gtk_widget_set_hexpand(b_mostra_f, true);
  gtk_widget_set_margin_start(GTK_WIDGET(b_mostra_f), 10);
  gtk_widget_set_margin_end(GTK_WIDGET(b_mostra_f), 10);

  b_edita_f = gtk_button_new_with_label("Editar");
  gtk_widget_set_hexpand(GTK_WIDGET(b_edita_f), true);
  gtk_widget_set_margin_start(GTK_WIDGET(b_edita_f), 5);
  gtk_widget_set_margin_end(GTK_WIDGET(b_edita_f), 5);
  gtk_widget_set_margin_top(GTK_WIDGET(b_edita_f), 2);

  box0 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  //gtk_widget_set_margin_top(box1, -16);

  box1 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  //gtk_widget_set_margin_top(box1, -16);
  

  b_adiciona_c = gtk_button_new_with_label("Adicionar");
  gtk_widget_set_hexpand(GTK_WIDGET(b_adiciona_c), true);
  gtk_widget_set_margin_start(GTK_WIDGET(b_adiciona_c), 10);
  gtk_widget_set_margin_top(GTK_WIDGET(b_adiciona_c), 2);

  b_remove_c = gtk_button_new_with_label("Remover");
  gtk_widget_set_hexpand(GTK_WIDGET(b_remove_c), true);
  gtk_widget_set_margin_top(GTK_WIDGET(b_remove_c), 2);
  gtk_widget_set_margin_end(GTK_WIDGET(b_remove_c), 10);

  b_mostra_c = gtk_button_new_with_label("Mostrar clientes");
  gtk_widget_set_hexpand(GTK_WIDGET(b_mostra_c), true);
  gtk_widget_set_margin_start(GTK_WIDGET(b_mostra_c), 10);
  gtk_widget_set_margin_end(GTK_WIDGET(b_mostra_c), 10);

  b_edita_c = gtk_button_new_with_label("Editar");
  gtk_widget_set_hexpand(GTK_WIDGET(b_edita_c), true);
  gtk_widget_set_margin_start(GTK_WIDGET(b_edita_c), 5);
  gtk_widget_set_margin_top(GTK_WIDGET(b_edita_c), 2);
  gtk_widget_set_margin_end(GTK_WIDGET(b_edita_c), 5);


  box2 = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_widget_set_margin_top(box2, 20);

  box3 = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
  //gtk_widget_set_margin_top(box2, -15);

 
  g_signal_connect (b_adiciona_f, "clicked", G_CALLBACK (add_funcionario), NULL);
  g_signal_connect (b_adiciona_c, "clicked", G_CALLBACK (add_cliente), NULL);
  g_signal_connect (b_remove_f, "clicked", G_CALLBACK (rm_funcionario), NULL);
  g_signal_connect (b_remove_c, "clicked", G_CALLBACK (rm_cliente), NULL);
  g_signal_connect (b_edita_f, "clicked", G_CALLBACK (mod_funcionario), NULL);
  g_signal_connect (b_edita_c, "clicked", G_CALLBACK (mod_cliente), NULL);
  g_signal_connect (b_mostra_f, "clicked", G_CALLBACK (print_funcionarios), NULL);
  g_signal_connect (b_mostra_c, "clicked", G_CALLBACK (print_clientes), NULL);
  

  gtk_box_append(GTK_BOX (box1), b_adiciona_f);
  gtk_box_append(GTK_BOX (box1), b_edita_f);
  gtk_box_append(GTK_BOX (box1), b_remove_f);
  gtk_box_append(GTK_BOX (box0), b_mostra_f);
  gtk_box_append(GTK_BOX (box0), box1);
  

  gtk_box_append(GTK_BOX (box3), b_adiciona_c);
  gtk_box_append(GTK_BOX (box3), b_edita_c);
  gtk_box_append(GTK_BOX (box3), b_remove_c);
  gtk_box_append(GTK_BOX (box2), b_mostra_c);
  gtk_box_append(GTK_BOX (box2), box3);
  


  gtk_box_append(GTK_BOX (parent_box), box0);
  gtk_box_append(GTK_BOX (parent_box), box2);
}

static void
activate (GtkApplication *app,
          gpointer        user_data)
{
  //Dao* global::dao = new Dao("postgres", "aaos0706", "localhost", "5432", "Garagem");

  //janela
  GtkWidget *window;

  //Caixas
  GtkWidget *main_box;
  GtkWidget *box_e;
  GtkWidget *box_d;


  //instancia janela
  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Aplicação");
  gtk_window_set_default_size (GTK_WINDOW (window), SCREEN_W, SCREEN_H);

  //instancia box principal
  main_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);


  //instancia boxs esquerda e direitas
  box_e = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  gtk_widget_set_size_request(GTK_WIDGET(box_e), SCREEN_W * 5/8, SCREEN_H);
  box_d = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
  gtk_widget_set_size_request(GTK_WIDGET(box_d), SCREEN_W * 3/8, SCREEN_H);

  instancia_nome(GTK_BOX(box_e));
  instancia_b_adiciona_remove(GTK_BOX(box_e));
  instancia_lista(GTK_BOX(box_e));
  instancia_balanco(GTK_BOX(box_d));
  instancia_funcionario(GTK_BOX(box_d));
  instancia_extra_direita(GTK_BOX(box_d));

  


  //adiciona as boxs esquerdas e direitas a box principal
  gtk_box_append(GTK_BOX (main_box), box_e);
  gtk_box_append(GTK_BOX (main_box), box_d);
  
  //adiciona a box principal a janela
  gtk_window_set_child (GTK_WINDOW (window), main_box);
  gtk_window_set_resizable(GTK_WINDOW (window), false);
  
  //mostra a janela
  gtk_window_present (GTK_WINDOW (window));

  
}

int
main (int    argc,
      char **argv)
{
  GtkApplication *app;
  int status;

  
  app = gtk_application_new ("com.gemail.alvinn.alvaro", G_APPLICATION_FLAGS_NONE);
  g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
  status = g_application_run (G_APPLICATION (app), argc, argv);
  g_object_unref (app);

  return status;
}