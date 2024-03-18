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

 // -------------- Definições de Hardware -------------------
 #define LATCH 10
// pinMode(LATCH,OUTPUT);                      // defino o PIND10  como o "LATCH" DO shift register   
 // -------------- Declaração de variáveis ------------------
volatile unsigned char valor[16] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F, 0x0F};   // Vetor de alocação dos valores dos dígitos
volatile unsigned char mux = 0x00;                // Variável de contagem da escrita dos displays
unsigned int niveis[15] = { 0,3,7,15,31,63,127,255,511,1023,2047,4095,8191,16383,32767};
volatile unsigned int counter = 0 ;
volatile unsigned int counter4 = 0;
volatile unsigned char contagem = 0;
volatile unsigned int variavel = 0x00;
unsigned int shutdown_off = 0x0C01 ;
unsigned int display_test = 0x0F00 ;                   // valor que se refere aos dígitos numéricos
unsigned int refresh = 0x0B07;
unsigned int brilho = 0x0A0F;
unsigned int bcd1 = 0x09FF;                             // valor que se refere aos dígitos numéricos
unsigned int bcd2 = 0x0900 ;                            // valor que se refere aos informativos e o barragráfico

 volatile unsigned char      segment[26] = {    0x00,     // 0               // Todos para cátodo comum
                                                0x01,     // 1
                                                0x02,     // 2
                                                0x03,     // 3
                                                0x04,     // 4
                                                0x05,     // 5
                                                0x06,     // 6
                                                0x07,     // 7
                                                0x08,     // 8
                                                0x09,     // 9
                                                0x77,     // A - 10
                                                0x83,     // B - 11
                                                0x4E,     // C - 12
                                                0x3D,     // d - 13
                                                0x4F,     // E - 14
                                                0x47,     // F - 15
                                                0x05,     // r - 16
                                                0x3E,     // U - 17
                                                0x37,     // H - 18
                                                0x15,     // n - 19
                                                0x0E,     // L - 20
                                                0x83,     // B - 21
                                                0x06,     // I - 22
                                                0x0F,     // t - 23
                                                0x00,     // Espaço - 24
                                                0x1F,     // b. - 25
                                                                            };

 volatile unsigned char frase[68] =  {
                                       0x00,       // Espaço    
                                       0x00,       // Espaço    
                                       0x00,       // Espaço    
                                       0x00,       // Espaço    
                                       0x00,       // Espaço    
                                       0x00,       // Espaço    
                                       0x79,       // E
                                       0x6D,       // S
                                       0x39,       // C
                                       0x3E,       // U
                                       0x5E,       // d
                                       0x79,       // E
                                       0x50,       // r
                                       0x30,       // I
                                       0x77,       // A
                                       0x00,       // ESPAÇO
                                       0x3E,       // U
                                       0x71,       // F
                                       0x6D,       // S
                                       0x77,       // A 
                                       0x79,       // E
                                       0x00,       // ESPAÇO
                                       0x00,       // ESPAÇO
                                       0x6D,       // S
                                       0x3E,       // U
                                       0xFC,       // b.
                                       0x00,       // ESPAÇO
                                       0x79,       // E
                                       0x38,       // L
                                       0x79,       // E
                                       0x78,       // t
                                       0x50,       // r
                                       0x3F,       // O 
                                       0x54,       // n
                                       0x30,       // I
                                       0x39,       // C
                                       0x77,       // A
                                       0x00,       // ESPAÇO
                                       0x00,       // ESPAÇO
                                       0x39,       // C  
                                       0x3E,       // U 
                                       0x30,       // I
                                       0x5E,       // D
                                       0x77,       // A
                                       0x5E,       // D
                                       0x3F,       // O 
                                       0x00,       // ESPAÇO
                                       0x00,       // ESPAÇO
                                       0x77,       // A 
                                       0x3F,       // O
                                       0x00,       // ESPAÇO
                                       0x00,       // ESPAÇO
                                       0x73,       // P
                                       0x30,       // I
                                       0x38,       // L
                                       0x3F,       // O
                                       0x78,       // T
                                       0x77,       // A
                                       0x50,       // r
                                       0x00,       // ESPAÇO
                                       0x00,       // ESPAÇO
                                       0x3E,       // U
                                       0x71,       // F
                                       0x6D,       // S
                                       0x40,       // -
                                       0x7C,       // b
                                       0x50,       // r                                      
                                                       };


//------------------------ Funções Auxiliares --------------------------
void writeDigito( unsigned char dado, unsigned int digito );           // Função de escrita em cada dígito do display
void writeMsg( unsigned char dado, unsigned int digito );                // Função de escrita da mensagem em cada dígito do display 
void RPM_Digit( unsigned int rpm );                                    // Função de escrita do RPM
void marcha_Digit( unsigned char marcha );                             // Função de escrita da marcha
void Vel_Digit( unsigned int vel );                                  // Função de escrita da velocidade
void writeBargraph( volatile unsigned char nivel );
void RPM_Bargraph( unsigned int rotacao );
void Write_frames(  );
void setup_max(unsigned int endereco_1, unsigned int endereco_2);
void Painel_begin();
void Inicia_barragraph();
//--------------------Setup do max 7219 -------------------------------
   void setup_max(unsigned int endereco_1,unsigned int endereco_2){
   digitalWrite(LATCH,LOW);
   SPDR = ( unsigned char )( endereco_1 >> 8);                // Carrego o valor da posição do display no registrador de SPI e inicio o envio
   while(!(SPSR & (1<<SPIF)) );                    // Aguardo o envio do byte alocado anteriormente
   SPDR = ( unsigned char )( endereco_1 );           // Carrego o valor da posição do display no registrador de SPI e inicio o envio
   while(!(SPSR & (1<<SPIF)) ) ;                    // Aguardo o envio do byte alocado anteriormente
   SPDR = ( unsigned char )( endereco_2 >> 8);           // Carrego o valor da posição do display no registrador de SPI e inicio o envio
   while(!(SPSR & (1<<SPIF)) );                    // Aguardo o envio do byte alocado anteriormente
   SPDR = ( unsigned char )( endereco_2 );          // Carrego o valor da posição do display no registrador de SPI e inicio o envio
   while(!(SPSR & (1<<SPIF)) );                    // Aguardo o envio do byte alocado anteriormente
   digitalWrite(LATCH,HIGH);
   }

// ----------------------- Início do Programa --------------------------
void Painel_begin()
{
  
    SREG = 0x00;
   // ---------------- SPI Init ----------------------------------
   SPCR = (1<<SPE)|(1<<MSTR)|(0 <<SPR1)|(0 <<SPR0)|(0<<CPOL)|(0<<CPHA);           // SPI_Init        com clock de 4MHz
   
    //Configuro o max7219 para operar como conversor binário
    // O PRIMEIRO QUE ELE LE é O ULTIMO QUE ENVIA
    
       digitalWrite(LATCH,LOW);                                      // Coloco inicialmente LATCH em 0
       digitalWrite(LATCH,HIGH);
       setup_max(brilho,brilho);
       setup_max(refresh,refresh);
       setup_max(display_test,display_test);
       setup_max(bcd2,bcd1);
       setup_max(shutdown_off,shutdown_off);
       
       

   // ------- Inicialização do Timer 1 --------------       // Tempo de estouro de aproximadamente 8,64 ms
   TCCR1B = (1<<CS12)|(0<<CS11)|(1<<CS10);                  // Fclock = Fmáquina / 256;                 com prescale de 256
   TIMSK1 = 0x01;                                           // Habilito a rotina de interrupção do Timer 1
   TCNT1 = 0xFDF6;                                         // Valor inicial para ajuste do tempo de Overflow 

   //--------- Inicialização do Timer 2-------------       // Tempo de estouro de aproximadamente 2,11 ms
   TCCR2B = (1<<CS22)|(1<<CS21)|(0<<CS20);                 // com prescale de 256
   TIMSK2 = 0x01;                                          // Habilito a rotina de intererupção do Timer 2
   TCNT2 = 124;                                            // Valor inicial para ajuste do tempo de Overflow
   

   //------------------------------------------------
   digitalWrite(LATCH,LOW);                                               // LATCH do shift register iniciado em 0


   //-------------- Loop Inifinito -------------------                                         
    SREG = 0x80;                                          // Habilito a interrupção do AVR
}

// ------------------ Função de escrita de Frames (PAinel Informativo) ------------
void Write_frames( )
{
    valor[0] = frase[contagem];             // símbolo do primeiro dígito(LSD)
    valor[1] = frase[contagem +1];          // símbolo do segundo dígito
    valor[2] = frase[contagem +2];          // Símbolo do terceiro dígito
    valor[3] = frase[contagem +3];          // Símbolo do quarto dígito
    valor[4] = frase[contagem +4];          // Símbolo do quinto dígito
    valor[5] = frase[contagem +5];          // Símbolo do sexto dígito(MSD)
}

// ----------------- Efeito de subida e descida dos leds e dígitos -----------------------
void Inicia_barragraph(){
  byte led = 0;                               // variável para acender os leds em ordem crescente e decresente
  TIMSK1 = 0;                                 // desabilita interrupção do timer1 
  for (  led = 0; led <= 14; led++){          // laço para efeito de subida 

        if(led < 8){
          valor[led+8] = segment[8];
        }
        else{
          valor[led-8] = 0x7F;
        }
        
        valor[6] = ( unsigned char )( niveis[ led ] );             // escrevo nos 8 LEds LSB os 8 bits LSB
        valor[7] = ( unsigned char )(  niveis[ led ] >> 8 );       // escrevo nos 8 LEds MSB os 8 bits MSB
        delay(100);                         
      }
      while(led > 0){                         //laço para efeito de descida
        led--;

         if(led < 8){
          valor[led+8] = 0x0F;
        }
        else{
          valor[led-8] = 0x00;
        }
        
        valor[6] = ( unsigned char )( niveis[ led ] );             // escrevo nos 8 LEds LSB os 8 bits LSB
        valor[7] = ( unsigned char )(  niveis[ led ] >> 8 );       // escrevo nos 8 LEds MSB os 8 bits MSB
        
        delay(100);  
      }
   TIMSK1 = 1;                       //habilita interrupção do timer1
}//Fim da função

// Função de escrita dos Frames(Por interrupção do Timer1) ------------------------
// Cada led pisca a uma frequencia de 6400 Hz (frequencia fixa do max7219)
//Nessa função ele passa a mensagem pelos displays informativos em um período de 15*8,64/1000 = 0,1296 s aprox. 8Hz
ISR(TIMER1_OVF_vect)                                      //void Timer0Overflow_ISR()                    //org IVT_ADDR_TIMER0_OVF
{
   SREG = 0x00;                              // Desabilito a interrupção Global
   counter4 ++;                              // Incremento o contador de delay
   if( counter4 == 2000 )                    // Já foram 2 mil contagens? ( 2 mil x T_estouro do Timer 1 )
   {                                         // Sim...
     if( contagem >= 61 )                    // Contagem maior que 61?(Todas as mensagens foram enviadas e parou?)
     {                                       // Sim...
       contagem = 0x00;                      // Limpo a contagem para reiniciar a rolagem das mensagens
     }
     counter4 = 0x00;                        // Limpo a variável de Delay
   }
   counter ++;                               // Incremento counter para delay do efeito da rolagem
   if( counter == 15)                       // Já ouve o delay de 15 vezes o estouro do Timer?
   {                                         // Sim...
     if( contagem < 61 )                     // A rolagem das mensagens não foram concluídas? ( São 67 vetores de símbolos )
     {                                       // Sim...
        contagem ++;                         // incremento contagem para continuar a rolagem dos frames
     }
     else                                    // Se não...
     {
       contagem = 61;                        // Fixo contagem em 61
     }
     counter = 0x00;                         // Limpo counter para recomeçar o delay para o efeito da rolagem
   }
   TCNT1 = 0xFDF6; 
   SREG = 0x80;                              // Habilito as interrupções globais
}
// --------------- Função da rotina de Interrupção do Timer 2 -----------------
//Nessa função ele passa os valores pelos displays e leds em um período de 2,11ms = 473Hz.
ISR(TIMER2_OVF_vect)                                     // Ocorreu overflow do timer, inicio a função
{
   SREG = 0x00;                                          // Desabilito as interrupções globais
    if( mux < 8 )                                          // Coloco Mux até 8 para fazer a varredura dos valores
    { 
      writeMsg( valor[ mux ] , ( mux+1 ));                   
      writeDigito( valor[ mux+8 ] , ( mux+1 ));            // coloco vetor dígito e posição dígito na função de escrita dos displays
      
      mux ++;                                               //acrescento mux em uma unidade                                            
    }
    else
    {                                                       // mux é menor que 8? Sim...
      mux = 0x00;                                           // limpo mux
                                              // reseto a variável de multiplexação dos displays em 0x01
    }
  TCNT2 = 124;                                        // o Timer 2 é pré carregado para o correto tempo de estouro do Timer

  SREG = 0x80;
}
//--------------- Função de escrita dos displays -----------------------------
void writeMsg( unsigned char dado, unsigned int digito )
{
         
       digitalWrite(LATCH,LOW);                                      // Coloco inicialmente LATCH em 0
       SPDR = ( unsigned char )( digito );             // Carrego o valor da posição do display no registrador de SPI e inicio o envio
       while(!(SPSR & (1<<SPIF)) );                    // Aguardo o envio do byte alocado anteriormente
       SPDR = dado;
       while(!(SPSR & (1<<SPIF)) );                    // Aguardo o envio do byte alocado anteriormente
}

//---------------Função de escrito da mensagem------------------------------
void writeDigito( unsigned char dado, unsigned int digito )
{
       SPDR = ( unsigned char )( digito );             // Carrego o valor da posição do display no registrador de SPI e inicio o envio
       while(!(SPSR & (1<<SPIF)) );                    // Aguardo o envio do byte alocado anteriormente
       SPDR = dado;
       while(!(SPSR & (1<<SPIF)) );                    // Aguardo o envio do byte alocado anteriormente
       digitalWrite(LATCH,HIGH);                                      // Carrego os dados para os displays setando o pino de LATCH
}
//--------------- Função de escrita do RPM ----------------------------------
void RPM_Digit( unsigned int rpm )
 {
      volatile unsigned char mil, cent, dz;           // Declaração de variáveis Locais
      mil = rpm / 1000;                               // armazeno a unidade do milhar
      cent = ( rpm % 1000 ) / 100;                    // armazeno a unidade das centenas
      dz = ( rpm % 100 ) / 10;                        // armazeno a unidade do milhar
    
      if( mil == 0 )                                  // Dígito mais significativo igual a zero?
      {                                               // Sim...
        valor[8] = 0x0F;                              // Apago ele
      }
      else                                            // Se não...
      {
        valor[8] = segment[mil];                      // coloco no vetor alocado a unidade de milhar do rpm
      }
      if( cent == 0 && mil == 0 )                     // Digito do milhar e das centenas iguais a zero?
      {                                               // Sim...
         valor[9] = 0x0F;                             // Apago o dígito das centenas
      }
      else                                            // Se não...
      {
       if (!k){
         valor[9] = segment[cent];                    // coloco no vetor alocado a unidade das centenas do rpm
         }
         else {
          valor[9] = segment[cent] | (1<<7);         // coloco no vetor alocado a unidade das centenas do rpm com ponto
         }
      }
      if( dz == 0 && cent == 0 && mil == 0 )          // Digito do milhar, das centenas e das dezenas iguais a zero?
      {                                               // Sim...
         valor[10] = 0x0F;                            // Apago o dígito das dezenas
      }
      else                                            // Se não...
      {
         valor[10] = segment[dz];                     // coloco no vetor alocado a unidade das dezenas do rpm
      }
      valor[11] = segment[(rpm % 10)];                // Por fim, coloco no vetor alocado as unidades do rpm
 }

 //-------------- Função de escrita da velocidade ---------------------------
void Vel_Digit( unsigned int vel )
 {
      unsigned int cent, dz;               // Declaração das variáveis locais
      cent = vel / 100;                               // Armazeno o dígito das centenas
      dz = ( vel % 100 ) / 10;                        // Armazeno o dígito das dezenas
      if( cent == 0 )                                 // O dígito das centenas igual a zero?
      {                                               // Sim...
         valor[13] = 0x0F;                            // Apago o dígito das centenas
      }
      else                                            // Se não...
      {
         valor[13] = segment[ cent ];                 // Coloco no vetor alocado a unidade das centenas
      }
      if( dz == 0 && cent == 0 )                      // O dígito das centenas e das dezenas iguais a zero?
      {                                               // Sim...
          valor[14] = 0x0F;                           // Apago o dígito das dezenas
      }
      else                                            // Se não...
      {
          valor[14] = segment[ dz ];                  // coloco no vetor alocado as unidades das dezenas  da vel.
      }
      valor[15] = segment[(vel % 10)];                // coloco no vetor alocado as unidades da vel.
 }

 //-------------- Função de escrita da marcha -------------------------------
void marcha_Digit( unsigned char marcha )
 {
      valor[12] = segment[marcha];                          // coloco no vetor alocado a unidade da marcha
 }

 //-------------- Função de escrita do RPM no Bargraph -----------------------
void RPM_Bargraph( volatile unsigned int rotacao )
 {
    if( rotacao < 14 )                                  // Rotação menor que 12000(Máxima)?
    {                                                      // Sim...
       writeBargraph( ( unsigned char )( rotacao ) );   // Escrevo na segunda função a variável rotacao
    }
    else                                                // Se não...
    {
       writeBargraph( 14 );                             //  Envio 14 para a segunda função
    }
 }
 // ------------ Segunda função de escrita no Bargraph( Um nível mais baixo ) ----------------
void writeBargraph( volatile unsigned char nivel ){
     if( nivel < 15 )                                                // Nível menor que 15?
     {                                                               // Sim...
        valor[6] = ( unsigned char )( niveis[ nivel ] );             // escrevo nos 8 LEds LSB os 8 bits LSB
        valor[7] = ( unsigned char )(  niveis[ nivel ] >> 8 );       // escrevo nos 8 LEds MSB os 8 bits MSB
      }
      else                                                           // Se não...
      {
        valor[6] = 0x00;                                                  // Apago os LEds MSB
        valor[7] = 0x00;                                                   // Apago os LEds LSB
      }
 }
