
//configure aqui os parametros desejados
#define CANAL    107 // 1 a 126
#define BUFFER   5  // 1 a 32
#define ENDTX    75  // 1 a 255
#define ENDRX    75  // 1 a 255


#define IRQ  (1<<PORTD2)                      // Habilita o uso do módulo
#define CE  (1<<PORTC1)                       // Habilita o uso do módulo
#define CSN  (1<<PORTC2)                      // LOAD -> Envio TX/RX
#define MISO  (1<<PORTB4)                     // Entrada de dados do Mestre
#define MOSI  (1<<PORTB3)                     // Saída de dados do escravo
#define SCLOCK  (1<<PORTB5)                   // clock de sincronismo do SPI


#define MISO_Direction (1<<DDB4)
#define MOSI_Direction (1<<DDB3)
#define SCLOCK_Direction (1<<DDB5)
#define CSN_Direction  (1<<DDC2)            // Direção (IMPUT/OUTPUT)
#define CE_Direction  (1<<DDC1)          // Direção (IMPUT/OUTPUT)
#define IRQ_Direction  (1<<DDD2)         // Direção (IMPUT/OUTPUT)

//variaveis globais
static unsigned int        espera_ack;
static unsigned char              ACK;
static unsigned char              ACK_R;
static unsigned char   RECEBE[BUFFER];
static unsigned char   ENVIA [BUFFER];
//----------------FUNÇÕES AUXILIARES--------------------------
void SPI1_Write(unsigned char endereco);
char SPI1_Read();

//função que configura modulo
void config_nrf24(){

   SREG = 0x00;                                          // Desabilito a interrupção do AVR

   DDRC |= CSN_Direction;                  // Saída Digital  -> Para habilitar uso do módulo
   DDRC |= CE_Direction;                   // Saída Digital  -> Para utilizar no envio de dados
   DDRD &= ~IRQ_Direction;                  // Entrada para interrupção
   
   DDRB = (SCLOCK_Direction) | (MOSI_Direction) | (1<<DDB2);
   SPCR = (1<<SPE)|(1<<MSTR)|(0 << SPR1)|(0 << SPR0)|(0<<CPOL)|(0<<CPHA);          // SPI_Init        com clock de 4MHz
   
   PORTC &= ~CE;                             //  Desativo o chip enquanto os valores são carregados
   
   PORTC &= ~CSN;                            //é necessario fazer isso para a primeira escrita
   PORTC |= CSN;   
   
   //RX_ADDR_P0 - configura endereço de recepção PIPE0
   PORTC &= ~CSN;                       // Inicio a comunicação SPI
   SPI1_Write(0x2A);                  //spi_write(0x2A);
   SPI1_Write(ENDRX);                  //spi_write(ENDRX);
   SPI1_Write(0xC2);                   //spi_write(0xC2);
   SPI1_Write(0xC2);                   //spi_write(0xC2);
   SPI1_Write(0xC2);                   //spi_write(0xC2);
   SPI1_Write(0xC2);                   //spi_write(0xC2);
   PORTC |= CSN;                       // Finalizo a comunicação  SPI

   //TX_ADDR - configura endereço de transmissão
   PORTC &= ~CSN;                            // Inicio a comunicação  SPI
   SPI1_Write(0x30);                   //spi_write(0x30);
   SPI1_Write(ENDTX);                  //spi_write(ENDTX);
   SPI1_Write(0xC2);                   //spi_write(0xC2);
   SPI1_Write(0xC2);                   //spi_write(0xC2);
   SPI1_Write(0xC2);                   //spi_write(0xC2);
   SPI1_Write(0xC2);                   //spi_write(0xC2);
   PORTC |= CSN;                            // Finalizo a comunicação  SPI

   //EN_AA - habilita autoACK no PIPE0
   PORTC &= ~CSN;                           // Inicio a comunicação SPI
   SPI1_Write(0x21);                  //spi_write(0x21);
   SPI1_Write(0x01);                  //spi_write(0x01);
   PORTC |= CSN;                           // Finalizo a comunicação SPI

   //EN_RXADDR - ativa o PIPE0
   PORTC &= ~CSN;                           // Inicio a comunicação  SPI
   SPI1_Write(0x22);                  //spi_write(0x22);
   SPI1_Write(0x01);                  //spi_write(0x01);
   PORTC |= CSN;                           // Finalizo a comunicação  SPI

   //SETUP_AW - define o endereço com tamanho de 5 Bytes
   PORTC &= ~CSN;                           // Inicio a comunicação  SPI
   SPI1_Write(0x23);                  //spi_write(0x23);
   SPI1_Write(0x03);                  //spi_write(0x03);
   PORTC |= CSN;                           // Finalizo a comunicação   SPI

   //SETUP_RETR - configura para nao retransmitir pacotes
   PORTC &= ~CSN;                           // Inicio a comunicação  SPI
   SPI1_Write(0x24);                  //spi_write(0x24);
   SPI1_Write(0x00);                  //spi_write(0x00);
   PORTC |= CSN;                           // Finalizo a comunicação  SPI

   //RF_CH - define o canal do modulo (TX e RX devem ser iguais)
   PORTC &= ~CSN;                           // Inicio a comunicação   SPI
   SPI1_Write(0x25);                  //spi_write(0x05);
   SPI1_Write(CANAL);                 //spi_write(CANAL);
   PORTC |= CSN;                           // Finalizo a comunicação  SPI

   //RF_SETUP - ativa LNA, taxa em 250K, e maxima potencia 0dbm
   PORTC &= ~CSN;                           // Inicio a comunicação   SPI
   SPI1_Write(0x26);                  //spi_write(0x26);
   SPI1_Write(0x26);            //spi_write(0b00100110);
   PORTC |= CSN;                           // Finalizo a comunicação   SPI

   //STATUS - reseta o resgistrador STATUS
   PORTC &= ~CSN;                           // Inicio a comunicação  SPI
   SPI1_Write(0x27);                  //spi_write(0x27);
   SPI1_Write(0x70);                  //spi_write(0x70);
   PORTC |= CSN;                           // Finalizo a comunicação  SPI
   
   //RX_PW_P0 - tamanho do buffer PIPE0
   PORTC &= ~CSN;                           // Inicio a comunicação  SPI
   SPI1_Write(0x31);                  //spi_write(0x31);
   SPI1_Write(BUFFER);                //spi_write(BUFFER);
   PORTC |= CSN;                           // Finalizo a comunicação  SPI

   //CONFIG - coloca em modo de recepção, e define CRC de 2 Bytes
   PORTC &= ~CSN;                           // Inicio a comunicação  SPI
   SPI1_Write(0x20);                  //spi_write(0x20);
   SPI1_Write(0x0F);                  //spi_write(0x0F);
   PORTC |= CSN;                           // Finalizo a comunicação  SPI

   //tempo para sair do modo standby entrar em modo de recepçao
   delay(2);
   PORTC |= CE;
   delayMicroseconds(150);
   
   //configura interrupção no pino PD2 ------------------------
   SREG = 0x00;      //GIE_bit = 0;            //DESABILITA INTERRUPÇÃO GLOBAL
   EIMSK = 0x01;     //INTE_bit = 1;          // HABILITA INTERRUPÇÃO EXTERNA;
   EICRA = 0x02;      //INTEDG_bit = 0;       //INTERRUPÇÃO É ACIONADA POR BORDA DE DESCIDA                
   PORTD |= IRQ;
   SREG = 0x80;                              //HABILITA INTERUUPÇÃO GLOBAL
}

//função que transmite os dados
unsigned char envia_dados(){

   unsigned char i;
   unsigned char stat;
   PORTC &= ~CE;

   //STATUS - reseta registrador STATUS
   PORTC &= ~CSN;
   SPI1_Write(0x27);                  //spi_write(0x27);
   SPI1_Write(0x70);                  //spi_write(0x70);
   PORTC |= CSN;

   // W_TX_PAYLOAD - envia os dados para o buffer FIFO TX
   PORTC &= ~CSN;
   SPI1_Write(0xA0);                  //spi_write(0xA0);
   for ( i=0; i < BUFFER; i++ )
   {
     SPI1_Write(ENVIA[i]);                  //spi_write(ENVIA[i]);
   }
   PORTC |= CSN;

   //CONFIG - ativa modo de transmissao
   PORTC &= ~CSN;
   SPI1_Write(0x20);                  //spi_write(0x20);
   SPI1_Write(0x0E);                  //spi_write(0x0E);
   PORTC |= CSN;

   //pulso para transmitir os dados
   PORTC |= CE;
   delayMicroseconds(15);
   PORTC &= ~CE;

   espera_ack=0;

   while((PIND&IRQ) == 4 )
   {
      espera_ack++;
      //espera 5ms, pela recepçao do pacote ACK
      if( espera_ack == 800 )
      {
        break;
      }
   }

   //STATUS - leitura do registrador
   PORTC &= ~CSN;
   SPI1_Write(0x07);                  //spi_write(0x07);
   stat = SPI1_Read();             //spi_read(0);
   PORTC |= CSN;

   //STATUS - limpa registrador
   PORTC &= ~CSN;
   SPI1_Write(0x27);                  //spi_write(0x27);
   SPI1_Write(0x70);                  //spi_write(0x70);
   PORTC |= CSN;

   //TX_FLUSH - limpa o buffer FIFO TX
   PORTC &= ~CSN;
   SPI1_Write(0xE1);                  //spi_write(0xE1);
   PORTC |= CSN;

   //CONFIG - configura para modo de recepção
   PORTC &= ~CSN;
   SPI1_Write(0x20);                  //spi_write(0x20);
   SPI1_Write(0x0F);                  //spi_write(0x0F);
   PORTC |= CSN;

   PORTC |= CE;

   delayMicroseconds(150);

   //se não recebeu ACK em 5ms retorna 0
   
   if( espera_ack == 800 ) 
   {
     EIFR = 0x00;            //INTF_bit = 0;
     SREG = 0x80;            //GIE_bit = 1;
     return(0);
   }
   //se recebeu ACK retorna 1
   else
   {
     SREG = 0x80;    //GIE_bit = 1;
     EIFR = 0x00;     //INTF_bit = 0;
     return(1);
   }
}

//função que recebe os dados e joga num vetor
unsigned char recebe_dados(){

   unsigned char i;
   unsigned char stat;

   //desabilita interrupção
   SREG = 0x00; 

   //STATUS - leitura do registrador
   PORTC &= ~CSN;
   SPI1_Write(0x07);
   stat = SPI1_Read();
   PORTC |= CSN;

   //STATUS - limpa registrador
   PORTC &= ~CSN;
   SPI1_Write(0x27);
   SPI1_Write(0x70);
   PORTC |= CSN;
   
   //verifica o bit de recepção de dados
   if( stat & 0x40 == 0 )
   {
     return(0);
   }

   //R_RX_PAYLOAD - recebe os dados do buffer FIFO RX
   PORTC &= ~CSN;
   SPI1_Write(0x61);
   for( i=0; i < BUFFER; i++)
   {
     RECEBE[i] = SPI1_Read();
   }
   PORTC |= CSN;

   //habilita interrupção
   EIFR = 0x00;    //INTF_bit = 0;
   SREG = 0x80;     //GIE_bit = 1;

   return(1);
}

//Interrupção pino PD2
ISR(INT0_vect)
{
   //funçãoo recebe dados
   ACK_R = recebe_dados();
}

//--------------------Envio Spi-------------------------------
   void SPI1_Write(unsigned char endereco){
   SPDR = endereco;           // Carrego o valor da posição do display no registrador de SPI e inicio o envio
   while(!(SPSR & (1<<SPIF)) );                    // Aguardo o envio do byte alocado anteriormente
   }
//--------------------Recebe Spi-------------------------------
    char SPI1_Read(){
    SPDR = 0x00;  
    while(!(SPSR & (1<<SPIF))); /* Wait for reception complete */
    return SPDR;  /* Return Data Register */
    }
