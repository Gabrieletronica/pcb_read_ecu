#line 1 "G:/Meu Drive/ESCUDERIA UFSAE - SUBSISTEMA DE ENGENHARIA ELETRICA/Projetos/[2020]Painel Eletrônico 3.0/Placa de leitura_software/Painel_software_pic16f73.c"
#line 1 "g:/meu drive/escuderia ufsae - subsistema de engenharia eletrica/projetos/[2020]painel eletrônico 3.0/placa de leitura_software/nrf24l01.h"







sbit IRQ at RB0_bit;
sbit CE at RA2_bit;
sbit CSN at RA3_bit;
sbit MISO at RC4_bit;
sbit MOSI at RC5_bit;
sbit SCLOCK at RC3_bit;

sbit CSN_Direction at TRISA3_bit;
sbit CE_Direction at TRISA2_bit;
sbit IRQ_Direction at TRISB0_bit;


 unsigned char ACK;
 unsigned char ACK_R = 5;
 unsigned char RECEBE[ 5 ];
 unsigned char ENVIA [ 5 ];



void config_nrf24(){
 GIE_bit = 0;

 CSN_Direction = 0;
 CE_Direction = 0;
 IRQ_Direction = 1;
 SPI1_Init();
 CE = 0;

 CSN = 0;
 CSN = 1;


 CSN = 0;
 SPI1_Write(0x2A);
 SPI1_Write( 75 );
 SPI1_Write(0xC2);
 SPI1_Write(0xC2);
 SPI1_Write(0xC2);
 SPI1_Write(0xC2);
 CSN = 1;


 CSN = 0;
 SPI1_Write(0x30);
 SPI1_Write( 75 );
 SPI1_Write(0xC2);
 SPI1_Write(0xC2);
 SPI1_Write(0xC2);
 SPI1_Write(0xC2);
 CSN = 1;


 CSN = 0;
 SPI1_Write(0x21);
 SPI1_Write(0x01);
 CSN = 1;


 CSN = 0;
 SPI1_Write(0x22);
 SPI1_Write(0x01);
 CSN = 1;


 CSN = 0;
 SPI1_Write(0x23);
 SPI1_Write(0x03);
 CSN = 1;


 CSN = 0;
 SPI1_Write(0x24);
 SPI1_Write(0x00);
 CSN = 1;


 CSN = 0;
 SPI1_Write(0x25);
 SPI1_Write( 107 );
 CSN = 1;


 CSN = 0;
 SPI1_Write(0x26);
 SPI1_Write(0b00100110);
 CSN = 1;


 CSN = 0;
 SPI1_Write(0x27);
 SPI1_Write(0x70);
 CSN = 1;


 CSN = 0;
 SPI1_Write(0x31);
 SPI1_Write( 5 );
 CSN = 1;


 CSN = 0;
 SPI1_Write(0x20);
 SPI1_Write(0x0F);
 CSN = 1;


 delay_ms(2);
 CE = 1;
 delay_us(150);


 GIE_bit = 0;
 PEIE_bit = 1;
 INTE_bit = 1;
 INTEDG_bit = 0;
 IRQ_Direction = 1;
 GIE_bit = 1;

}


unsigned char envia_dados(){
 unsigned int espera_ack;
 unsigned char i;
 unsigned char status;
 GIE_bit = 0;
 CE = 0;


 CSN = 0;
 SPI1_Write(0x27);
 SPI1_Write(0x70);
 CSN = 1;


 CSN = 0;
 SPI1_Write(0xA0);
 for ( i=0; i <  5 ; i++ )
 {
 SPI1_Write(ENVIA[i]);
 }
 CSN = 1;


 CSN = 0;
 SPI1_Write(0x20);
 SPI1_Write(0x0E);
 CSN = 1;


 CE = 1;
 delay_us(15);
 CE = 0;

 espera_ack=0;

 while( IRQ == 1 )
 {
 espera_ack++;

 if( espera_ack == 500 )
 {
 break;
 }
 }


 CSN = 0;
 SPI1_Write(0x07);
 status = SPI1_Read(0);
 CSN = 1;


 CSN = 0;
 SPI1_Write(0x27);
 SPI1_Write(0x70);
 CSN = 1;


 CSN = 0;
 SPI1_Write(0xE1);
 CSN = 1;


 CSN = 0;
 SPI1_Write(0x20);
 SPI1_Write(0x0F);
 CSN = 1;

 CE = 1;

 delay_us(150);



 if( espera_ack == 500 )
 {
 INTF_bit = 0;
 GIE_bit = 1;
 return(0);
 }

 else
 {
 GIE_bit = 1;
 INTF_bit = 0;
 return(1);
 }
}


void recebe_dados(){

 unsigned char i;
 unsigned char status;


 GIE_bit = 0;

 CSN = 0;
 SSPIF_bit = 0;
 SSPBUF = 0x07;
 while(!SSPIF_bit);

 SSPIF_bit = 0;
 SSPBUF = 0x00;
 while(!SSPIF_bit);
 status = SSPBUF;
 CSN = 1;


 CSN = 0;
 SSPIF_bit = 0;
 SSPBUF = 0x27;
 while(!SSPIF_bit);

 SSPIF_bit = 0;
 SSPBUF = 0x70;
 while(!SSPIF_bit);
 CSN = 1;


 if( status & 0x40 == 0 )
 {



 }


 CSN = 0;
 SSPIF_bit = 0;
 SSPBUF = 0x61;
 while(!SSPIF_bit);
 for( i=0; i <  5 ; i++)
 {
 SSPIF_bit = 0;
 SSPBUF = 0x00;
 while(!SSPIF_bit);
 RECEBE[i] = SSPBUF;

 }
 CSN = 1;


 INTF_bit = 0;

 GIE_bit = 1;


}
#line 17 "G:/Meu Drive/ESCUDERIA UFSAE - SUBSISTEMA DE ENGENHARIA ELETRICA/Projetos/[2020]Painel Eletrônico 3.0/Placa de leitura_software/Painel_software_pic16f73.c"
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








sbit MARCHA_1 at RB1_bit;
sbit MARCHA_2 at RA4_bit;



short int marcha = 0;
unsigned char Tempo_H_rpm, Tempo_L_rpm = 0;
unsigned char Tempo_H_vel, Tempo_L_vel = 0;
char x1[4];
char x2[4];
char x3[4];
char x4[4];
char x5[4];
char x6[4];
char x7[4];
char x8[4];



void interrupt()
{
 if(CCP1IF_bit && CCP1CON.B0)
 {
 CCP1IF_bit = 0x00;
 CCP1IE_bit = 0x00;
 CCP1CON = 0x04;
 CCP1IE_bit = 0x01;
 TMR1H = 0x00;
 TMR1L = 0x00;
 TMR1ON_bit = 0x01;
 }

 else if(CCP1IF_bit)
 {
 CCP1IF_bit = 0x00;
 TMR1ON_bit = 0x00;
 CCP1IE_bit = 0x00;
 CCP1CON = 0x00;
 CCP1IE_bit = 0x01;
 Tempo_H_rpm = CCPR1H;
 Tempo_L_rpm = CCPR1L;

 CCP2CON = 0x05;
 }


 if(CCP2IF_bit && CCP2CON.B0)
 {
 CCP2IF_bit = 0x00;
 CCP2IE_bit = 0x00;
 CCP2CON = 0x04;
 CCP2IE_bit = 0x01;
 TMR1H = 0x00;
 TMR1L = 0x00;
 TMR1ON_bit = 0x01;
 }
 else if(CCP2IF_bit)
 {
 CCP2IF_bit = 0x00;
 TMR1ON_bit = 0x00;
 CCP2IE_bit = 0x00;
 CCP2CON = 0x00;
 CCP2IE_bit = 0x01;
 Tempo_H_vel = CCPR2H;
 Tempo_L_vel = CCPR2L;

 CCP1CON = 0x05;
 }


 if(INTF_bit){

 recebe_dados();
 }

}


void medicao_marcha(){
 bit control;
 bit control2;

 if(MARCHA_1 && MARCHA_2){
 marcha = 0;
 }

 else if(!marcha){
 if(MARCHA_1 ){

 marcha = 2;
 }
#line 133 "G:/Meu Drive/ESCUDERIA UFSAE - SUBSISTEMA DE ENGENHARIA ELETRICA/Projetos/[2020]Painel Eletrônico 3.0/Placa de leitura_software/Painel_software_pic16f73.c"
 if(MARCHA_2){

 marcha = 1;
 }
#line 140 "G:/Meu Drive/ESCUDERIA UFSAE - SUBSISTEMA DE ENGENHARIA ELETRICA/Projetos/[2020]Painel Eletrônico 3.0/Placa de leitura_software/Painel_software_pic16f73.c"
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
}

void main()
{


unsigned char a,b,cc,dd = 0;
char txt1[] = "** ESCUDERIA **";
char txt2[] = "**** UFSAE ****";
char txt3[] = "    CENTRAL    ";
char txt4[] = "  DE CONTROLE  ";


 TRISA = 0x10;
 TRISB = 0x03;
 TRISC = 0x16;

 Lcd_Init();
 config_nrf24();

 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 Lcd_Out(1,1,txt1);
 Lcd_Out(2,1,txt2);
 Delay_ms( 2000 );
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Out(1,1,txt3);
 Lcd_Out(2,1,txt4);
 Delay_ms( 2000 );
 Lcd_Cmd(_LCD_CLEAR);


 INTCON = 0x00;
 TMR1IE_bit = 0x00;
 CCP1IE_bit = 0x00;
 CCP1CON = 0x05;
 T1CON = 0x00;

 CCP2IE_bit = 0x00;


 INTCON = 0xD0;

 while(1)
 {
 medicao_marcha();

 ENVIA[0]= marcha;
 ENVIA[1]= Tempo_H_rpm;
 ENVIA[2]= Tempo_L_rpm;
 ENVIA[3]= Tempo_H_vel;
 ENVIA[4]= Tempo_L_vel;


 CSN = 0;
 SPI1_Write(0x07);
 a = SPI1_Read(0);
 CSN = 1;


 CSN = 0;
 SPI1_Write(0x00);
 b = SPI1_Read(0);
 CSN = 1;


 CSN = 0;
 SPI1_Write(0x02);
 cc = SPI1_Read(0);
 CSN = 1;


 CSN = 0;
 SPI1_Write(0x0A);
 dd = SPI1_Read(0);
 CSN = 1;



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


 ACK = envia_dados();
 }

}
