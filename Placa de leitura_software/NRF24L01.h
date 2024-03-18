
//configure aqui os parametros desejados
#define CANAL    107 // 1 a 126
#define BUFFER   5  // 1 a 32
#define ENDTX    75  // 1 a 255
#define ENDRX    75  // 1 a 255

sbit IRQ at RB0_bit;                      // Habilita o uso do módulo
sbit CE at RA2_bit;                       // Habilita o uso do módulo
sbit CSN at RA3_bit;                      // LOAD -> Envio TX/RX
sbit MISO at RC4_bit;                     // Entrada de dados do Mestre
sbit MOSI at RC5_bit;                     // Saída de dados do escravo
sbit SCLOCK at RC3_bit;                   // clock de sincronismo do SPI

sbit CSN_Direction at TRISA3_bit;         // Direção (IMPUT/OUTPUT)
sbit CE_Direction at TRISA2_bit;          // Direção (IMPUT/OUTPUT)
sbit IRQ_Direction at TRISB0_bit;         // Direção (IMPUT/OUTPUT)

//variaveis globais
 unsigned char              ACK;
 unsigned char              ACK_R = 5;
 unsigned char   RECEBE[BUFFER];
 unsigned char   ENVIA [BUFFER];
 

//função que configura modulo
void config_nrf24(){
   GIE_bit = 0;
   
   CSN_Direction = 0;                  // Saída Digital  -> Para habilitar uso do módulo
   CE_Direction = 0;                   // Saída Digital  -> Para utilizar no envio de dados
   IRQ_Direction = 1;                  // Entrada para interrupção
   SPI1_Init();                        // Inicializa o SPI
   CE = 0;                             //  Desativo o chip enquanto os valores são carregados
   
   CSN = 0;
   CSN = 1;

   //RX_ADDR_P0 - configura endereço de recepção PIPE0
   CSN = 0;                            // Inicio a comunicação SPI
   SPI1_Write(0x2A);                  //spi_write(0x2A);
   SPI1_Write(ENDRX);                  //spi_write(ENDRX);
   SPI1_Write(0xC2);                   //spi_write(0xC2);
   SPI1_Write(0xC2);                   //spi_write(0xC2);
   SPI1_Write(0xC2);                   //spi_write(0xC2);
   SPI1_Write(0xC2);                   //spi_write(0xC2);
   CSN = 1;                            // Finalizo a comunicação  SPI

   //TX_ADDR - configura endereço de transmissão
   CSN = 0;                            // Inicio a comunicação  SPI
   SPI1_Write(0x30);                   //spi_write(0x30);
   SPI1_Write(ENDTX);                  //spi_write(ENDTX);
   SPI1_Write(0xC2);                   //spi_write(0xC2);
   SPI1_Write(0xC2);                   //spi_write(0xC2);
   SPI1_Write(0xC2);                   //spi_write(0xC2);
   SPI1_Write(0xC2);                   //spi_write(0xC2);
   CSN = 1;                            // Finalizo a comunicação  SPI

   //EN_AA - habilita autoACK no PIPE0
   CSN = 0;                           // Inicio a comunicação SPI
   SPI1_Write(0x21);                  //spi_write(0x21);
   SPI1_Write(0x01);                  //spi_write(0x01);
   CSN = 1;                           // Finalizo a comunicação SPI

   //EN_RXADDR - ativa o PIPE0
   CSN = 0;                           // Inicio a comunicação  SPI
   SPI1_Write(0x22);                  //spi_write(0x22);
   SPI1_Write(0x01);                  //spi_write(0x01);
   CSN = 1;                           // Finalizo a comunicação  SPI

   //SETUP_AW - define o endereço com tamanho de 5 Bytes
   CSN = 0;                           // Inicio a comunicação  SPI
   SPI1_Write(0x23);                  //spi_write(0x23);
   SPI1_Write(0x03);                  //spi_write(0x03);
   CSN = 1;                           // Finalizo a comunicação   SPI

   //SETUP_RETR - configura para nao retransmitir pacotes
   CSN = 0;                           // Inicio a comunicação  SPI
   SPI1_Write(0x24);                  //spi_write(0x24);
   SPI1_Write(0x00);                  //spi_write(0x00);
   CSN = 1;                           // Finalizo a comunicação  SPI

   //RF_CH - define o canal do modulo (TX e RX devem ser iguais)
   CSN = 0;                           // Inicio a comunicação   SPI
   SPI1_Write(0x25);                  //spi_write(0x05);
   SPI1_Write(CANAL);                 //spi_write(CANAL);
   CSN = 1;                           // Finalizo a comunicação  SPI

   //RF_SETUP - ativa LNA, taxa em 250K, e maxima potencia 0dbm
   CSN = 0;                           // Inicio a comunicação   SPI
   SPI1_Write(0x26);                  //spi_write(0x26);
   SPI1_Write(0b00100110);            //spi_write(0b00100110);
   CSN = 1;                           // Finalizo a comunicação   SPI

   //STATUS - reseta o resgistrador STATUS
   CSN = 0;                           // Inicio a comunicação  SPI
   SPI1_Write(0x27);                  //spi_write(0x27);
   SPI1_Write(0x70);                  //spi_write(0x70);
   CSN = 1;                           // Finalizo a comunicação  SPI

   //RX_PW_P0 - tamanho do buffer PIPE0
   CSN = 0;                           // Inicio a comunicação  SPI
   SPI1_Write(0x31);                  //spi_write(0x31);
   SPI1_Write(BUFFER);                //spi_write(BUFFER);
   CSN = 1;                           // Finalizo a comunicação  SPI

   //CONFIG - coloca em modo de recepção, e define CRC de 2 Bytes
   CSN = 0;                           // Inicio a comunicação  SPI
   SPI1_Write(0x20);                  //spi_write(0x20);
   SPI1_Write(0x0F);                  //spi_write(0x0F);
   CSN = 1;                           // Finalizo a comunicação  SPI

   //tempo para sair do modo standby entrar em modo de recepçao
   delay_ms(2);
   CE = 1;
   delay_us(150);
   
   //configura interrupção no pino RB0 ------------------------
   GIE_bit = 0;
   PEIE_bit = 1;
   INTE_bit = 1;
   INTEDG_bit = 0;
   IRQ_Direction = 1;
   GIE_bit = 1;

}

//função que transmite os dados
unsigned char envia_dados(){
   unsigned  int        espera_ack;
   unsigned char i;
   unsigned char status;
   GIE_bit = 0;  //Desabilita interrupção global(eu coloquei)
   CE = 0;

   //STATUS - reseta registrador STATUS
   CSN = 0;
   SPI1_Write(0x27);                  //spi_write(0x27);
   SPI1_Write(0x70);                  //spi_write(0x70);
   CSN = 1;

   // W_TX_PAYLOAD - envia os dados para o buffer FIFO TX
   CSN = 0;
   SPI1_Write(0xA0);                  //spi_write(0xA0);
   for ( i=0; i < BUFFER; i++ )
   {
     SPI1_Write(ENVIA[i]);                  //spi_write(ENVIA[i]);
   }
   CSN = 1;

   //CONFIG - ativa modo de transmissão
   CSN = 0;
   SPI1_Write(0x20);                  //spi_write(0x20);
   SPI1_Write(0x0E);                  //spi_write(0x0E);
   CSN = 1;

   //pulso para transmitir os dados
   CE = 1;
   delay_us(15);
   CE = 0;

   espera_ack=0;

   while( IRQ == 1 )
   {
      espera_ack++;
      //espera 5ms, pela recepçao do pacote ACK
      if( espera_ack == 500 )
      {
        break;
      }
   }

   //STATUS - leitura do registrador
   CSN = 0;
   SPI1_Write(0x07);                  //spi_write(0x07);
   status = SPI1_Read(0);             //spi_read(0);
   CSN = 1;

   //STATUS - limpa registrador
   CSN = 0;
   SPI1_Write(0x27);                  //spi_write(0x27);
   SPI1_Write(0x70);                  //spi_write(0x70);
   CSN = 1;

   //TX_FLUSH - limpa o buffer FIFO TX
   CSN = 0;
   SPI1_Write(0xE1);                  //spi_write(0xE1);
   CSN = 1;

   //CONFIG - configura para modo de recepção
   CSN = 0;
   SPI1_Write(0x20);                  //spi_write(0x20);
   SPI1_Write(0x0F);                  //spi_write(0x0F);
   CSN = 1;

   CE = 1;

   delay_us(150);

   //se não recebeu ACK em 5ms retorna 0
   
   if( espera_ack == 500 )
   {
     INTF_bit = 0;
     GIE_bit = 1;
     return(0);
   }
   //se recebeu ACK retorna 1
   else
   {
     GIE_bit = 1;
     INTF_bit = 0;
     return(1);
   }
}

//função que recebe os dados e joga num vetor
void recebe_dados(){

   unsigned char i;
   unsigned char status;

   //desabilita interrupção
   GIE_bit = 0;
   //STATUS - leitura do registrador
   CSN = 0;
   SSPIF_bit = 0;
   SSPBUF = 0x07;                                   //SPI1_Write(0x07);
   while(!SSPIF_bit);                               /// Aguardo o envio do byte alocado anteriormente
   
   SSPIF_bit = 0;
   SSPBUF = 0x00;                                   //SPI1_Read(0);
   while(!SSPIF_bit);                               // Aguardo o envio do byte alocado anteriormente
   status = SSPBUF;
   CSN = 1;

   //STATUS - limpa registrador
   CSN = 0;
   SSPIF_bit = 0;
   SSPBUF = 0x27;                                   //SPI1_Write(0x27);
   while(!SSPIF_bit);                               /// Aguardo o envio do byte alocado anteriormente
   
   SSPIF_bit = 0;
   SSPBUF = 0x70;                                   //SPI1_Write(0x70);
   while(!SSPIF_bit);                               // Aguardo o envio do byte alocado anteriormente
   CSN = 1;

   //verifica o bit de recepção de dados
   if( status & 0x40 == 0 )
   {
   
    //ACK_R = 0;//return(0);

   }

   //R_RX_PAYLOAD - recebe os dados do buffer FIFO RX
   CSN = 0;
   SSPIF_bit = 0;
   SSPBUF = 0x61;                                   //SPI1_Write(0x61);
   while(!SSPIF_bit);                               // Aguardo o envio do byte alocado anteriormente
   for( i=0; i < BUFFER; i++)
   {
     SSPIF_bit = 0;
     SSPBUF = 0x00;                                   //SPI1_Read(0);
     while(!SSPIF_bit);                               // Aguardo o envio do byte alocado anteriormente
     RECEBE[i] = SSPBUF;
                                                       //RECEBE[i] = SPI1_Read(0);
   }
   CSN = 1;

   //habilita interrupção
   INTF_bit = 0;
   //INTE_bit = 1;
   GIE_bit = 1;

    //return(1);
}