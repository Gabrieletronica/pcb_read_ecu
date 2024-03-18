
/*
* Universidade Federal de Sergipe
* Departamento de Engenharia Elétrica
* Sérgio Silvaneres Pereira Silva
* EMULADOR E.C.U
* Escuderia UFSAE
* Projeto Painel
* Microcontrolador Utilizado: PIC16F73
* Frequência Clock: 16.00000 MHz
*/

#include "NRF24L01.h"

// ------------------------ Pinos de comunicação com o LCD ----------------------

sbit LCD_RS at RB5_bit;
sbit LCD_EN at RB4_bit;
sbit LCD_D4 at RB3_bit;
sbit LCD_D5 at RB2_bit;
sbit LCD_D6 at RC7_bit;
sbit LCD_D7 at RC6_bit;

sbit LCD_RS_Direction at TRISB5_bit;
sbit LCD_EN_Direction at TRISB4_bit;
sbit LCD_D4_Direction at TRISB3_bit;
sbit LCD_D5_Direction at TRISB2_bit;
sbit LCD_D6_Direction at TRISC7_bit;
sbit LCD_D7_Direction at TRISC6_bit;

// --------------- Pinos de entrada da frequência ( CCP1 e CCP2 ) ---------------

//sbit FREQ_1 at RC2_bit;  // Entrada 1 de frequência ( CCP1 )
//sbit FREQ_2 at RC1_bit;  // Entrada 2 de frequência ( CCP2 )

// --------------- Pinos de entrada da marcha -----------------------------------

sbit MARCHA_1 at RB1_bit; // Entrada 1 da marcha
sbit MARCHA_2 at RA4_bit; // Entrada 2 da marcha

// --------------- Variáveis Globais --------------------------------------------

short int marcha = 0;
unsigned char Tempo_H_rpm, Tempo_L_rpm = 0;                //Armazena valores do tempo de captura 1
unsigned char Tempo_H_vel, Tempo_L_vel = 0;                //Armazena valores do tempo de captura 2
char x1[4];
char x2[4];
char x3[4];
char x4[4];
char x5[4];
char x6[4];
char x7[4];
char x8[4];


// --- Rotina de Interrupção ---
void interrupt()
{      //interrupção por captura1  (ECU)
      if(CCP1IF_bit && CCP1CON.B0)             //Interrupção do módulo CCP e modo de captura configurado para borda de subida?
      {                                        //Sim...
        CCP1IF_bit  = 0x00;                    //Limpa a flag para nova captura
        CCP1IE_bit  = 0x00;                    //Desabilita interrupção do periférico CCP
        CCP1CON     = 0x04;                    //Configura captura por borda de descida
        CCP1IE_bit  = 0x01;                    //Habilita interrupção do periférico CCP
        TMR1H       = 0x00;                    //Zera registrador high do TMR1
        TMR1L       = 0x00;                    //Zera registrador low do TMR1
        TMR1ON_bit  = 0x01;                    //Habilita contagem de tempo
      } //end if
      
      else if(CCP1IF_bit)                      //Interrupção do módulo CCP?
      {                                        //Sim...
        CCP1IF_bit  = 0x00;                    //Limpa a flag para nova captura
        TMR1ON_bit  = 0x00;                    //Desabilita contagem de tempo
        CCP1IE_bit  = 0x00;                    //Desabilita interrupção do periférico CCP
        CCP1CON     = 0x00;                    //Desabilita captura por borda de subida
        CCP1IE_bit  = 0x01;                    //Habilita interrupção do periférico CCP    //comentei
        Tempo_H_rpm  = CCPR1H;                  //Valor do tempo em ns é armazenado na variável Tempo_H (registrador CCPR1H)
        Tempo_L_rpm  = CCPR1L;                  //Valor do tempo em ns é armazenado na variável Tempo_L (registrador CCPR1L)
        
        CCP2CON  = 0x05;                    //Habilita interrupção do periférico CCP           //coloquei
      } //end else*/
      
      // Interrupção por captura2 (ECU)
      if(CCP2IF_bit && CCP2CON.B0)             //Interrupção do módulo CCP e modo de captura configurado para borda de subida?
      {                                        //Sim...
        CCP2IF_bit  = 0x00;                    //Limpa a flag para nova captura
        CCP2IE_bit  = 0x00;                    //Desabilita interrupção do periférico CCP
        CCP2CON     = 0x04;                    //Configura captura por borda de descida
        CCP2IE_bit  = 0x01;                    //Habilita interrupção do periférico CCP
        TMR1H       = 0x00;                    //Zera registrador low do TMR1
        TMR1L       = 0x00;                    //Zera registrador high do TMR1
        TMR1ON_bit  = 0x01;                    //Habilita contagem de tempo
      } //end if
      else if(CCP2IF_bit)                      //Interrupção do módulo CCP?
      {                                        //Sim...
        CCP2IF_bit  = 0x00;                    //Limpa a flag para nova captura
        TMR1ON_bit  = 0x00;                    //Desabilita contagem de tempo
        CCP2IE_bit  = 0x00;                    //Desabilita interrupção do periférico CCP
        CCP2CON     = 0x00;                    //Desabilita captura
        CCP2IE_bit  = 0x01;                    //Habilita interrupção do periférico CCP
        Tempo_H_vel   = CCPR2H;                  //Valor do tempo em ns é armazenado na variável Tempo_H (registrador CCPR2H)
        Tempo_L_vel   = CCPR2L;                  //Valor do tempo em ns é armazenado na variável Tempo_L (registrador CCPR2L)

        CCP1CON  = 0x05;                       //Habilita interrupção do periférico CCP  // coloquei
      }

      //Interrupção por pino RB0 (NRF24L01)
      if(INTF_bit){
         //função RECEBE dados
         recebe_dados();
         }
   
} //end interrupt

 //indica qual a marcha do carro
void medicao_marcha(){
    bit control;
    bit control2;

    if(MARCHA_1 && MARCHA_2){
    marcha = 0;
    }
    // caso em qual a marcha é neutro
    else if(!marcha){
      if(MARCHA_1 ){//&& !control){
       //control = 1;
       marcha = 2;
       }
     /* if(!MARCHA_1 && control){
       control = 0;
       }*/
      
      if(MARCHA_2){// && !control2){
       //control2 = 1;
       marcha = 1;
       }
     /* if(!MARCHA_2 && control2){
       control2 = 0;
       }*/
    }
    if (marcha != 0){
     if(MARCHA_1 && !control){
      control = 1;
      marcha++;
      }
     if(!MARCHA_1 && control){
      control = 0;
      }

     if(MARCHA_2 && !control2){
       control2 = 1;
       marcha --;
       }
     if(!MARCHA_2 && control2){
       control2 = 0;
      }
      }
      if(marcha < 0){
         marcha = 0;
      } 
      else if(marcha > 6){
        marcha = 6;
      }
}     // fim da função marcha

void main()
{

//declaração de variáveis
unsigned char a,b,cc,dd = 0;
char txt1[] = "** ESCUDERIA **";
char txt2[] = "**** UFSAE ****";
char txt3[] = "    CENTRAL    ";
char txt4[] = "  DE CONTROLE  ";
//---------------------------------------------------------
// configuração de portas
  TRISA = 0x10;
  TRISB = 0x03;
  TRISC = 0x16;

  Lcd_Init();                        // Inicialize LCD
  config_nrf24();                   //  Configure NRF24

  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
  Lcd_Out(1,1,txt1);                 // Write text in first row
  Lcd_Out(2,1,txt2);                 // Write text in second row
  Delay_ms( 2000 );
  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Out(1,1,txt3);                 // Write text in first row
  Lcd_Out(2,1,txt4);                 // Write text in second row
  Delay_ms( 2000 );
  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  
   // Configura captura1(RPM)
    INTCON      = 0x00;                        //Desabilita interrupção global , interrupção por periféricos  e interrupção externa
    TMR1IE_bit  = 0x00;                        //Desabilita interrupções de TMR1
    CCP1IE_bit  = 0x00;                        //Habilita interrupções do módulo CCP1
    CCP1CON     = 0x05;                        //Configura captura por borda de subida
    T1CON       = 0x00;                        // conf preescale de 1:1 e FOSC/4
   // Configura captura2(Velocidade/temperatura)           // ambas capturas possuem o mesmo timer
    CCP2IE_bit  = 0x00;                        //Habilita interrupções do módulo CCP2
    //CCP2CON     = 0x05;                        //Configura captura por borda de subida
    //
    INTCON      = 0xD0;                        //Habilita interrupção global , interrupção por periféricos  e interrupção externa

  while(1)
  {
      medicao_marcha();

      ENVIA[0]= marcha;
      ENVIA[1]= Tempo_H_rpm;
      ENVIA[2]= Tempo_L_rpm;
      ENVIA[3]= Tempo_H_vel;
      ENVIA[4]= Tempo_L_vel;

      // le status
      CSN = 0;
      SPI1_Write(0x07);
      a = SPI1_Read(0);
      CSN = 1;

      //le config
      CSN = 0;
      SPI1_Write(0x00);
      b = SPI1_Read(0);
      CSN = 1;

      // EN_RXADDR
      CSN = 0;
      SPI1_Write(0x02);
      cc = SPI1_Read(0);
      CSN = 1;

      //RX_PW0
      CSN = 0;
      SPI1_Write(0x0A);
      dd = SPI1_Read(0);
      CSN = 1;

      //GIE_bit = 0x00;        //Desabilita interrupção para converter e mostrar valores

      ByteToStr( a, x1 );
      ByteToStr( b, x2 );
      ByteToStr( cc, x3 );
      ByteToStr( dd, x4 );

      Lcd_Out( 1,1, x1 );
      Lcd_Out_Cp(",");
      Lcd_Out_Cp( x2 );
      Lcd_Out_Cp(",");
      Lcd_Out_Cp( x3 );
      Lcd_Out_Cp(",");
      Lcd_Out_Cp( x4 );

      ByteToStr( TEMPO_H_vel , x5 );
      ByteToStr( TEMPO_L_vel, x6 );
      ByteToStr( TEMPO_H_rpm, x7 );
      BytetoStr( TEMPO_L_rpm, x8);

      Lcd_Out( 2,1, x5 );
      Lcd_Out_Cp(",");
      Lcd_Out_Cp( x6 );
      Lcd_Out_Cp(",");
      Lcd_Out_Cp( x7 );
      Lcd_Out_Cp(",");
      Lcd_Out_Cp( x8 );
      
      //GIE_bit = 0x01;                        //Habilita interrupção
      ACK = envia_dados();
  }

}