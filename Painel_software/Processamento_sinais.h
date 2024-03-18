
//configure aqui os ajustes desejados dos valores para rotação, velocidade e bargraph
const float aju_rpm_max = 12000.0;
const float aju_vel_max = 122.0;
const float aju_rpmbargraph_max = 10000.0;
const float f_PWM = 100.0;

//---------------------------------------//

unsigned char Tempo_H_RPM,Tempo_L_RPM = 0;
unsigned char Tempo_H_VEL,Tempo_L_VEL = 0;
float rpm_medido = 0; 
float vel_medida = 0;
unsigned int rpm_bargraph = 0;
unsigned int RPM = 0;
unsigned int VEL = 0;

//--------------------------------------//

// Função para fazer a leitura do PWM  da rotação do motor
unsigned int rotacao(unsigned char t1, unsigned char t2){
  // declaração de variáveis
      unsigned int Periodo = 0;                          //Armazena o período
      float duty = 0;
      k = 0;
      Periodo = (t1 << 8)+ t2;                         //Cálculo do período: Periodo = (Tempo_H x 256) + Tempo_L
      duty = Periodo*250.0*f_PWM/1000000000.0;                       // Fclock = 16Mhz/4 ; Tciclo = 1/4Mhz = 250ns
      rpm_medido = aju_rpm_max*duty;                                 //ajuste de rotação máxima
      if (rpm_medido < 200){                                        // rotação é menor que 200 rpm?
        rpm_medido = 0;        
      }

      if (rpm_medido >= 10000){                       // rotação é maior que 10000 rpm
        rpm_medido = rpm_medido/10;                   // divido rotação por 10
        k = 1;
      }
      return rpm_medido;                             // retorna o valor da rotação
}
// Função para fazer a leitura do PWM da velocidade
unsigned int velocidade(unsigned char t1, unsigned char t2){
  // declaração de variáveis
      unsigned int Periodo = 0;                          //Armazena o período
      float duty = 0;                                    //Armazena o duty
      
      Periodo = (t1 << 8)+ t2;                         //Cálculo do período: Periodo = (Tempo_H x 256) + Tempo_L
      duty = Periodo*250.0*f_PWM/1000000000.0;                       // Fclock = 16Mhz/4 ; Tciclo = 1/4Mhz = 250ns
      vel_medida = aju_vel_max*duty-1;                               //Ajuste de velocidade
      
      return vel_medida;                                 //retorna o valor da velocidade
}

// Função para ajustar o bargraph com a rotação do motor
unsigned int bargraph(unsigned int rot){
   if (!k){
    rpm_bargraph = 14.0*rot/aju_rpmbargraph_max;        // ajuste do bargraph
    }
    else{
    rpm_bargraph = 10*14.0*rot/aju_rpmbargraph_max;    // ajuste do bargraph para rotação acima de 10000 rpm
    }
    return rpm_bargraph;                               // retorna o valor ajustado do bargraph
}
