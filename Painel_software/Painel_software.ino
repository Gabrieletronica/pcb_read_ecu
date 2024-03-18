/*
  - Universidade Federal de Sergipe
  - Departamento de Engenharia Elétrica
  - Escuderia UFSAE
  - Subsistema de Eletrônica
  - Projeto Painel Eletrônico
  - Microcontrolador Utilizado: Atmega328p
  - Discente: Gabriel Santana Alves de Barros
  - Frequência Utilizada: 16MHz

*/
// variáveis globais //
 
unsigned char k =0;

//--------------------//
#include "NRF24L01.h"
#include "Painel_Def.h"
#include "Processamento_sinais.h"

void setup() {
  config_nrf24();
  Painel_begin();
  Inicia_barragraph();
   
}

void loop() {
      
    Tempo_H_RPM = RECEBE[1]; 
    Tempo_L_RPM = RECEBE[2];
    Tempo_H_VEL = RECEBE[3];
    Tempo_L_VEL = RECEBE[4];  

    RPM = rotacao(Tempo_H_RPM,Tempo_L_RPM);
    VEL = velocidade(Tempo_H_VEL,Tempo_L_VEL);
    rpm_bargraph = bargraph(rpm_medido) ;

    Write_frames( );
    marcha_Digit( RECEBE[0] );
    RPM_Digit( RPM );
    Vel_Digit( VEL );
    RPM_Bargraph( rpm_bargraph );
    delay(1);
}
