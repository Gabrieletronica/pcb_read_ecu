
_config_nrf24:

;nrf24l01.h,27 :: 		void config_nrf24(){
;nrf24l01.h,28 :: 		GIE_bit = 0;
	BCF        GIE_bit+0, BitPos(GIE_bit+0)
;nrf24l01.h,30 :: 		CSN_Direction = 0;                  // Saída Digital  -> Para habilitar uso do módulo
	BCF        TRISA3_bit+0, BitPos(TRISA3_bit+0)
;nrf24l01.h,31 :: 		CE_Direction = 0;                   // Saída Digital  -> Para utilizar no envio de dados
	BCF        TRISA2_bit+0, BitPos(TRISA2_bit+0)
;nrf24l01.h,32 :: 		IRQ_Direction = 1;                  // Entrada para interrupção
	BSF        TRISB0_bit+0, BitPos(TRISB0_bit+0)
;nrf24l01.h,33 :: 		SPI1_Init();                        // Inicializa o SPI
	CALL       _SPI1_Init+0
;nrf24l01.h,34 :: 		CE = 0;                             //  Desativo o chip enquanto os valores são carregados
	BCF        RA2_bit+0, BitPos(RA2_bit+0)
;nrf24l01.h,36 :: 		CSN = 0;
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,37 :: 		CSN = 1;
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,40 :: 		CSN = 0;                            // Inicio a comunicação SPI
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,41 :: 		SPI1_Write(0x2A);                  //spi_write(0x2A);
	MOVLW      42
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,42 :: 		SPI1_Write(ENDRX);                  //spi_write(ENDRX);
	MOVLW      75
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,43 :: 		SPI1_Write(0xC2);                   //spi_write(0xC2);
	MOVLW      194
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,44 :: 		SPI1_Write(0xC2);                   //spi_write(0xC2);
	MOVLW      194
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,45 :: 		SPI1_Write(0xC2);                   //spi_write(0xC2);
	MOVLW      194
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,46 :: 		SPI1_Write(0xC2);                   //spi_write(0xC2);
	MOVLW      194
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,47 :: 		CSN = 1;                            // Finalizo a comunicação  SPI
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,50 :: 		CSN = 0;                            // Inicio a comunicação  SPI
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,51 :: 		SPI1_Write(0x30);                   //spi_write(0x30);
	MOVLW      48
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,52 :: 		SPI1_Write(ENDTX);                  //spi_write(ENDTX);
	MOVLW      75
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,53 :: 		SPI1_Write(0xC2);                   //spi_write(0xC2);
	MOVLW      194
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,54 :: 		SPI1_Write(0xC2);                   //spi_write(0xC2);
	MOVLW      194
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,55 :: 		SPI1_Write(0xC2);                   //spi_write(0xC2);
	MOVLW      194
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,56 :: 		SPI1_Write(0xC2);                   //spi_write(0xC2);
	MOVLW      194
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,57 :: 		CSN = 1;                            // Finalizo a comunicação  SPI
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,60 :: 		CSN = 0;                           // Inicio a comunicação SPI
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,61 :: 		SPI1_Write(0x21);                  //spi_write(0x21);
	MOVLW      33
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,62 :: 		SPI1_Write(0x01);                  //spi_write(0x01);
	MOVLW      1
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,63 :: 		CSN = 1;                           // Finalizo a comunicação SPI
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,66 :: 		CSN = 0;                           // Inicio a comunicação  SPI
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,67 :: 		SPI1_Write(0x22);                  //spi_write(0x22);
	MOVLW      34
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,68 :: 		SPI1_Write(0x01);                  //spi_write(0x01);
	MOVLW      1
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,69 :: 		CSN = 1;                           // Finalizo a comunicação  SPI
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,72 :: 		CSN = 0;                           // Inicio a comunicação  SPI
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,73 :: 		SPI1_Write(0x23);                  //spi_write(0x23);
	MOVLW      35
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,74 :: 		SPI1_Write(0x03);                  //spi_write(0x03);
	MOVLW      3
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,75 :: 		CSN = 1;                           // Finalizo a comunicação   SPI
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,78 :: 		CSN = 0;                           // Inicio a comunicação  SPI
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,79 :: 		SPI1_Write(0x24);                  //spi_write(0x24);
	MOVLW      36
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,80 :: 		SPI1_Write(0x00);                  //spi_write(0x00);
	CLRF       FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,81 :: 		CSN = 1;                           // Finalizo a comunicação  SPI
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,84 :: 		CSN = 0;                           // Inicio a comunicação   SPI
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,85 :: 		SPI1_Write(0x25);                  //spi_write(0x05);
	MOVLW      37
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,86 :: 		SPI1_Write(CANAL);                 //spi_write(CANAL);
	MOVLW      107
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,87 :: 		CSN = 1;                           // Finalizo a comunicação  SPI
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,90 :: 		CSN = 0;                           // Inicio a comunicação   SPI
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,91 :: 		SPI1_Write(0x26);                  //spi_write(0x26);
	MOVLW      38
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,92 :: 		SPI1_Write(0b00100110);            //spi_write(0b00100110);
	MOVLW      38
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,93 :: 		CSN = 1;                           // Finalizo a comunicação   SPI
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,96 :: 		CSN = 0;                           // Inicio a comunicação  SPI
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,97 :: 		SPI1_Write(0x27);                  //spi_write(0x27);
	MOVLW      39
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,98 :: 		SPI1_Write(0x70);                  //spi_write(0x70);
	MOVLW      112
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,99 :: 		CSN = 1;                           // Finalizo a comunicação  SPI
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,102 :: 		CSN = 0;                           // Inicio a comunicação  SPI
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,103 :: 		SPI1_Write(0x31);                  //spi_write(0x31);
	MOVLW      49
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,104 :: 		SPI1_Write(BUFFER);                //spi_write(BUFFER);
	MOVLW      5
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,105 :: 		CSN = 1;                           // Finalizo a comunicação  SPI
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,108 :: 		CSN = 0;                           // Inicio a comunicação  SPI
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,109 :: 		SPI1_Write(0x20);                  //spi_write(0x20);
	MOVLW      32
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,110 :: 		SPI1_Write(0x0F);                  //spi_write(0x0F);
	MOVLW      15
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,111 :: 		CSN = 1;                           // Finalizo a comunicação  SPI
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,114 :: 		delay_ms(2);
	MOVLW      11
	MOVWF      R12+0
	MOVLW      98
	MOVWF      R13+0
L_config_nrf240:
	DECFSZ     R13+0, 1
	GOTO       L_config_nrf240
	DECFSZ     R12+0, 1
	GOTO       L_config_nrf240
	NOP
;nrf24l01.h,115 :: 		CE = 1;
	BSF        RA2_bit+0, BitPos(RA2_bit+0)
;nrf24l01.h,116 :: 		delay_us(150);
	MOVLW      199
	MOVWF      R13+0
L_config_nrf241:
	DECFSZ     R13+0, 1
	GOTO       L_config_nrf241
	NOP
	NOP
;nrf24l01.h,119 :: 		GIE_bit = 0;
	BCF        GIE_bit+0, BitPos(GIE_bit+0)
;nrf24l01.h,120 :: 		PEIE_bit = 1;
	BSF        PEIE_bit+0, BitPos(PEIE_bit+0)
;nrf24l01.h,121 :: 		INTE_bit = 1;
	BSF        INTE_bit+0, BitPos(INTE_bit+0)
;nrf24l01.h,122 :: 		INTEDG_bit = 0;
	BCF        INTEDG_bit+0, BitPos(INTEDG_bit+0)
;nrf24l01.h,123 :: 		IRQ_Direction = 1;
	BSF        TRISB0_bit+0, BitPos(TRISB0_bit+0)
;nrf24l01.h,124 :: 		GIE_bit = 1;
	BSF        GIE_bit+0, BitPos(GIE_bit+0)
;nrf24l01.h,126 :: 		}
L_end_config_nrf24:
	RETURN
; end of _config_nrf24

_envia_dados:

;nrf24l01.h,129 :: 		unsigned char envia_dados(){
;nrf24l01.h,133 :: 		GIE_bit = 0;  //Desabilita interrupção global(eu coloquei)
	BCF        GIE_bit+0, BitPos(GIE_bit+0)
;nrf24l01.h,134 :: 		CE = 0;
	BCF        RA2_bit+0, BitPos(RA2_bit+0)
;nrf24l01.h,137 :: 		CSN = 0;
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,138 :: 		SPI1_Write(0x27);                  //spi_write(0x27);
	MOVLW      39
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,139 :: 		SPI1_Write(0x70);                  //spi_write(0x70);
	MOVLW      112
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,140 :: 		CSN = 1;
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,143 :: 		CSN = 0;
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,144 :: 		SPI1_Write(0xA0);                  //spi_write(0xA0);
	MOVLW      160
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,145 :: 		for ( i=0; i < BUFFER; i++ )
	CLRF       envia_dados_i_L0+0
L_envia_dados2:
	MOVLW      5
	SUBWF      envia_dados_i_L0+0, 0
	BTFSC      STATUS+0, 0
	GOTO       L_envia_dados3
;nrf24l01.h,147 :: 		SPI1_Write(ENVIA[i]);                  //spi_write(ENVIA[i]);
	MOVF       envia_dados_i_L0+0, 0
	ADDLW      _ENVIA+0
	MOVWF      FSR
	MOVF       INDF+0, 0
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,145 :: 		for ( i=0; i < BUFFER; i++ )
	INCF       envia_dados_i_L0+0, 1
;nrf24l01.h,148 :: 		}
	GOTO       L_envia_dados2
L_envia_dados3:
;nrf24l01.h,149 :: 		CSN = 1;
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,152 :: 		CSN = 0;
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,153 :: 		SPI1_Write(0x20);                  //spi_write(0x20);
	MOVLW      32
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,154 :: 		SPI1_Write(0x0E);                  //spi_write(0x0E);
	MOVLW      14
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,155 :: 		CSN = 1;
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,158 :: 		CE = 1;
	BSF        RA2_bit+0, BitPos(RA2_bit+0)
;nrf24l01.h,159 :: 		delay_us(15);
	MOVLW      19
	MOVWF      R13+0
L_envia_dados5:
	DECFSZ     R13+0, 1
	GOTO       L_envia_dados5
	NOP
	NOP
;nrf24l01.h,160 :: 		CE = 0;
	BCF        RA2_bit+0, BitPos(RA2_bit+0)
;nrf24l01.h,162 :: 		espera_ack=0;
	CLRF       envia_dados_espera_ack_L0+0
	CLRF       envia_dados_espera_ack_L0+1
;nrf24l01.h,164 :: 		while( IRQ == 1 )
L_envia_dados6:
	BTFSS      RB0_bit+0, BitPos(RB0_bit+0)
	GOTO       L_envia_dados7
;nrf24l01.h,166 :: 		espera_ack++;
	INCF       envia_dados_espera_ack_L0+0, 1
	BTFSC      STATUS+0, 2
	INCF       envia_dados_espera_ack_L0+1, 1
;nrf24l01.h,168 :: 		if( espera_ack == 500 )
	MOVF       envia_dados_espera_ack_L0+1, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L__envia_dados75
	MOVLW      244
	XORWF      envia_dados_espera_ack_L0+0, 0
L__envia_dados75:
	BTFSS      STATUS+0, 2
	GOTO       L_envia_dados8
;nrf24l01.h,170 :: 		break;
	GOTO       L_envia_dados7
;nrf24l01.h,171 :: 		}
L_envia_dados8:
;nrf24l01.h,172 :: 		}
	GOTO       L_envia_dados6
L_envia_dados7:
;nrf24l01.h,175 :: 		CSN = 0;
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,176 :: 		SPI1_Write(0x07);                  //spi_write(0x07);
	MOVLW      7
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,177 :: 		status = SPI1_Read(0);             //spi_read(0);
	CLRF       FARG_SPI1_Read_buffer+0
	CALL       _SPI1_Read+0
;nrf24l01.h,178 :: 		CSN = 1;
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,181 :: 		CSN = 0;
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,182 :: 		SPI1_Write(0x27);                  //spi_write(0x27);
	MOVLW      39
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,183 :: 		SPI1_Write(0x70);                  //spi_write(0x70);
	MOVLW      112
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,184 :: 		CSN = 1;
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,187 :: 		CSN = 0;
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,188 :: 		SPI1_Write(0xE1);                  //spi_write(0xE1);
	MOVLW      225
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,189 :: 		CSN = 1;
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,192 :: 		CSN = 0;
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,193 :: 		SPI1_Write(0x20);                  //spi_write(0x20);
	MOVLW      32
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,194 :: 		SPI1_Write(0x0F);                  //spi_write(0x0F);
	MOVLW      15
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;nrf24l01.h,195 :: 		CSN = 1;
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,197 :: 		CE = 1;
	BSF        RA2_bit+0, BitPos(RA2_bit+0)
;nrf24l01.h,199 :: 		delay_us(150);
	MOVLW      199
	MOVWF      R13+0
L_envia_dados9:
	DECFSZ     R13+0, 1
	GOTO       L_envia_dados9
	NOP
	NOP
;nrf24l01.h,203 :: 		if( espera_ack == 500 )
	MOVF       envia_dados_espera_ack_L0+1, 0
	XORLW      1
	BTFSS      STATUS+0, 2
	GOTO       L__envia_dados76
	MOVLW      244
	XORWF      envia_dados_espera_ack_L0+0, 0
L__envia_dados76:
	BTFSS      STATUS+0, 2
	GOTO       L_envia_dados10
;nrf24l01.h,205 :: 		INTF_bit = 0;
	BCF        INTF_bit+0, BitPos(INTF_bit+0)
;nrf24l01.h,206 :: 		GIE_bit = 1;
	BSF        GIE_bit+0, BitPos(GIE_bit+0)
;nrf24l01.h,207 :: 		return(0);
	CLRF       R0+0
	GOTO       L_end_envia_dados
;nrf24l01.h,208 :: 		}
L_envia_dados10:
;nrf24l01.h,212 :: 		GIE_bit = 1;
	BSF        GIE_bit+0, BitPos(GIE_bit+0)
;nrf24l01.h,213 :: 		INTF_bit = 0;
	BCF        INTF_bit+0, BitPos(INTF_bit+0)
;nrf24l01.h,214 :: 		return(1);
	MOVLW      1
	MOVWF      R0+0
;nrf24l01.h,216 :: 		}
L_end_envia_dados:
	RETURN
; end of _envia_dados

_recebe_dados:

;nrf24l01.h,219 :: 		void recebe_dados(){
;nrf24l01.h,225 :: 		GIE_bit = 0;
	BCF        GIE_bit+0, BitPos(GIE_bit+0)
;nrf24l01.h,227 :: 		CSN = 0;
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,228 :: 		SSPIF_bit = 0;
	BCF        SSPIF_bit+0, BitPos(SSPIF_bit+0)
;nrf24l01.h,229 :: 		SSPBUF = 0x07;                                   //SPI1_Write(0x07);
	MOVLW      7
	MOVWF      SSPBUF+0
;nrf24l01.h,230 :: 		while(!SSPIF_bit);                               /// Aguardo o envio do byte alocado anteriormente
L_recebe_dados12:
	BTFSC      SSPIF_bit+0, BitPos(SSPIF_bit+0)
	GOTO       L_recebe_dados13
	GOTO       L_recebe_dados12
L_recebe_dados13:
;nrf24l01.h,232 :: 		SSPIF_bit = 0;
	BCF        SSPIF_bit+0, BitPos(SSPIF_bit+0)
;nrf24l01.h,233 :: 		SSPBUF = 0x00;                                   //SPI1_Read(0);
	CLRF       SSPBUF+0
;nrf24l01.h,234 :: 		while(!SSPIF_bit);                               // Aguardo o envio do byte alocado anteriormente
L_recebe_dados14:
	BTFSC      SSPIF_bit+0, BitPos(SSPIF_bit+0)
	GOTO       L_recebe_dados15
	GOTO       L_recebe_dados14
L_recebe_dados15:
;nrf24l01.h,235 :: 		status = SSPBUF;
	MOVF       SSPBUF+0, 0
	MOVWF      R2+0
;nrf24l01.h,236 :: 		CSN = 1;
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,239 :: 		CSN = 0;
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,240 :: 		SSPIF_bit = 0;
	BCF        SSPIF_bit+0, BitPos(SSPIF_bit+0)
;nrf24l01.h,241 :: 		SSPBUF = 0x27;                                   //SPI1_Write(0x27);
	MOVLW      39
	MOVWF      SSPBUF+0
;nrf24l01.h,242 :: 		while(!SSPIF_bit);                               /// Aguardo o envio do byte alocado anteriormente
L_recebe_dados16:
	BTFSC      SSPIF_bit+0, BitPos(SSPIF_bit+0)
	GOTO       L_recebe_dados17
	GOTO       L_recebe_dados16
L_recebe_dados17:
;nrf24l01.h,244 :: 		SSPIF_bit = 0;
	BCF        SSPIF_bit+0, BitPos(SSPIF_bit+0)
;nrf24l01.h,245 :: 		SSPBUF = 0x70;                                   //SPI1_Write(0x70);
	MOVLW      112
	MOVWF      SSPBUF+0
;nrf24l01.h,246 :: 		while(!SSPIF_bit);                               // Aguardo o envio do byte alocado anteriormente
L_recebe_dados18:
	BTFSC      SSPIF_bit+0, BitPos(SSPIF_bit+0)
	GOTO       L_recebe_dados19
	GOTO       L_recebe_dados18
L_recebe_dados19:
;nrf24l01.h,247 :: 		CSN = 1;
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,250 :: 		if( status & 0x40 == 0 )
	MOVLW      0
	ANDWF      R2+0, 0
	MOVWF      R0+0
	BTFSC      STATUS+0, 2
	GOTO       L_recebe_dados20
;nrf24l01.h,255 :: 		}
L_recebe_dados20:
;nrf24l01.h,258 :: 		CSN = 0;
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,259 :: 		SSPIF_bit = 0;
	BCF        SSPIF_bit+0, BitPos(SSPIF_bit+0)
;nrf24l01.h,260 :: 		SSPBUF = 0x61;                                   //SPI1_Write(0x61);
	MOVLW      97
	MOVWF      SSPBUF+0
;nrf24l01.h,261 :: 		while(!SSPIF_bit);                               // Aguardo o envio do byte alocado anteriormente
L_recebe_dados21:
	BTFSC      SSPIF_bit+0, BitPos(SSPIF_bit+0)
	GOTO       L_recebe_dados22
	GOTO       L_recebe_dados21
L_recebe_dados22:
;nrf24l01.h,262 :: 		for( i=0; i < BUFFER; i++)
	CLRF       R1+0
L_recebe_dados23:
	MOVLW      5
	SUBWF      R1+0, 0
	BTFSC      STATUS+0, 0
	GOTO       L_recebe_dados24
;nrf24l01.h,264 :: 		SSPIF_bit = 0;
	BCF        SSPIF_bit+0, BitPos(SSPIF_bit+0)
;nrf24l01.h,265 :: 		SSPBUF = 0x00;                                   //SPI1_Read(0);
	CLRF       SSPBUF+0
;nrf24l01.h,266 :: 		while(!SSPIF_bit);                               // Aguardo o envio do byte alocado anteriormente
L_recebe_dados26:
	BTFSC      SSPIF_bit+0, BitPos(SSPIF_bit+0)
	GOTO       L_recebe_dados27
	GOTO       L_recebe_dados26
L_recebe_dados27:
;nrf24l01.h,267 :: 		RECEBE[i] = SSPBUF;
	MOVF       R1+0, 0
	ADDLW      _RECEBE+0
	MOVWF      FSR
	MOVF       SSPBUF+0, 0
	MOVWF      INDF+0
;nrf24l01.h,262 :: 		for( i=0; i < BUFFER; i++)
	INCF       R1+0, 1
;nrf24l01.h,269 :: 		}
	GOTO       L_recebe_dados23
L_recebe_dados24:
;nrf24l01.h,270 :: 		CSN = 1;
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;nrf24l01.h,273 :: 		INTF_bit = 0;
	BCF        INTF_bit+0, BitPos(INTF_bit+0)
;nrf24l01.h,275 :: 		GIE_bit = 1;
	BSF        GIE_bit+0, BitPos(GIE_bit+0)
;nrf24l01.h,278 :: 		}
L_end_recebe_dados:
	RETURN
; end of _recebe_dados

_interrupt:
	MOVWF      R15+0
	SWAPF      STATUS+0, 0
	CLRF       STATUS+0
	MOVWF      ___saveSTATUS+0
	MOVF       PCLATH+0, 0
	MOVWF      ___savePCLATH+0
	CLRF       PCLATH+0

;Painel_software_pic16f73.c,57 :: 		void interrupt()
;Painel_software_pic16f73.c,59 :: 		if(CCP1IF_bit && CCP1CON.B0)             //Interrupção do módulo CCP e modo de captura configurado para borda de subida?
	BTFSS      CCP1IF_bit+0, BitPos(CCP1IF_bit+0)
	GOTO       L_interrupt30
	BTFSS      CCP1CON+0, 0
	GOTO       L_interrupt30
L__interrupt67:
;Painel_software_pic16f73.c,61 :: 		CCP1IF_bit  = 0x00;                    //Limpa a flag para nova captura
	BCF        CCP1IF_bit+0, BitPos(CCP1IF_bit+0)
;Painel_software_pic16f73.c,62 :: 		CCP1IE_bit  = 0x00;                    //Desabilita interrupção do periférico CCP
	BCF        CCP1IE_bit+0, BitPos(CCP1IE_bit+0)
;Painel_software_pic16f73.c,63 :: 		CCP1CON     = 0x04;                    //Configura captura por borda de descida
	MOVLW      4
	MOVWF      CCP1CON+0
;Painel_software_pic16f73.c,64 :: 		CCP1IE_bit  = 0x01;                    //Habilita interrupção do periférico CCP
	BSF        CCP1IE_bit+0, BitPos(CCP1IE_bit+0)
;Painel_software_pic16f73.c,65 :: 		TMR1H       = 0x00;                    //Zera registrador high do TMR1
	CLRF       TMR1H+0
;Painel_software_pic16f73.c,66 :: 		TMR1L       = 0x00;                    //Zera registrador low do TMR1
	CLRF       TMR1L+0
;Painel_software_pic16f73.c,67 :: 		TMR1ON_bit  = 0x01;                    //Habilita contagem de tempo
	BSF        TMR1ON_bit+0, BitPos(TMR1ON_bit+0)
;Painel_software_pic16f73.c,68 :: 		} //end if
	GOTO       L_interrupt31
L_interrupt30:
;Painel_software_pic16f73.c,70 :: 		else if(CCP1IF_bit)                      //Interrupção do módulo CCP?
	BTFSS      CCP1IF_bit+0, BitPos(CCP1IF_bit+0)
	GOTO       L_interrupt32
;Painel_software_pic16f73.c,72 :: 		CCP1IF_bit  = 0x00;                    //Limpa a flag para nova captura
	BCF        CCP1IF_bit+0, BitPos(CCP1IF_bit+0)
;Painel_software_pic16f73.c,73 :: 		TMR1ON_bit  = 0x00;                    //Desabilita contagem de tempo
	BCF        TMR1ON_bit+0, BitPos(TMR1ON_bit+0)
;Painel_software_pic16f73.c,74 :: 		CCP1IE_bit  = 0x00;                    //Desabilita interrupção do periférico CCP
	BCF        CCP1IE_bit+0, BitPos(CCP1IE_bit+0)
;Painel_software_pic16f73.c,75 :: 		CCP1CON     = 0x00;                    //Desabilita captura por borda de subida
	CLRF       CCP1CON+0
;Painel_software_pic16f73.c,76 :: 		CCP1IE_bit  = 0x01;                    //Habilita interrupção do periférico CCP    //comentei
	BSF        CCP1IE_bit+0, BitPos(CCP1IE_bit+0)
;Painel_software_pic16f73.c,77 :: 		Tempo_H_rpm  = CCPR1H;                  //Valor do tempo em ns é armazenado na variável Tempo_H (registrador CCPR1H)
	MOVF       CCPR1H+0, 0
	MOVWF      _Tempo_H_rpm+0
;Painel_software_pic16f73.c,78 :: 		Tempo_L_rpm  = CCPR1L;                  //Valor do tempo em ns é armazenado na variável Tempo_L (registrador CCPR1L)
	MOVF       CCPR1L+0, 0
	MOVWF      _Tempo_L_rpm+0
;Painel_software_pic16f73.c,80 :: 		CCP2CON  = 0x05;                    //Habilita interrupção do periférico CCP           //coloquei
	MOVLW      5
	MOVWF      CCP2CON+0
;Painel_software_pic16f73.c,81 :: 		} //end else*/
L_interrupt32:
L_interrupt31:
;Painel_software_pic16f73.c,84 :: 		if(CCP2IF_bit && CCP2CON.B0)             //Interrupção do módulo CCP e modo de captura configurado para borda de subida?
	BTFSS      CCP2IF_bit+0, BitPos(CCP2IF_bit+0)
	GOTO       L_interrupt35
	BTFSS      CCP2CON+0, 0
	GOTO       L_interrupt35
L__interrupt66:
;Painel_software_pic16f73.c,86 :: 		CCP2IF_bit  = 0x00;                    //Limpa a flag para nova captura
	BCF        CCP2IF_bit+0, BitPos(CCP2IF_bit+0)
;Painel_software_pic16f73.c,87 :: 		CCP2IE_bit  = 0x00;                    //Desabilita interrupção do periférico CCP
	BCF        CCP2IE_bit+0, BitPos(CCP2IE_bit+0)
;Painel_software_pic16f73.c,88 :: 		CCP2CON     = 0x04;                    //Configura captura por borda de descida
	MOVLW      4
	MOVWF      CCP2CON+0
;Painel_software_pic16f73.c,89 :: 		CCP2IE_bit  = 0x01;                    //Habilita interrupção do periférico CCP
	BSF        CCP2IE_bit+0, BitPos(CCP2IE_bit+0)
;Painel_software_pic16f73.c,90 :: 		TMR1H       = 0x00;                    //Zera registrador low do TMR1
	CLRF       TMR1H+0
;Painel_software_pic16f73.c,91 :: 		TMR1L       = 0x00;                    //Zera registrador high do TMR1
	CLRF       TMR1L+0
;Painel_software_pic16f73.c,92 :: 		TMR1ON_bit  = 0x01;                    //Habilita contagem de tempo
	BSF        TMR1ON_bit+0, BitPos(TMR1ON_bit+0)
;Painel_software_pic16f73.c,93 :: 		} //end if
	GOTO       L_interrupt36
L_interrupt35:
;Painel_software_pic16f73.c,94 :: 		else if(CCP2IF_bit)                      //Interrupção do módulo CCP?
	BTFSS      CCP2IF_bit+0, BitPos(CCP2IF_bit+0)
	GOTO       L_interrupt37
;Painel_software_pic16f73.c,96 :: 		CCP2IF_bit  = 0x00;                    //Limpa a flag para nova captura
	BCF        CCP2IF_bit+0, BitPos(CCP2IF_bit+0)
;Painel_software_pic16f73.c,97 :: 		TMR1ON_bit  = 0x00;                    //Desabilita contagem de tempo
	BCF        TMR1ON_bit+0, BitPos(TMR1ON_bit+0)
;Painel_software_pic16f73.c,98 :: 		CCP2IE_bit  = 0x00;                    //Desabilita interrupção do periférico CCP
	BCF        CCP2IE_bit+0, BitPos(CCP2IE_bit+0)
;Painel_software_pic16f73.c,99 :: 		CCP2CON     = 0x00;                    //Desabilita captura
	CLRF       CCP2CON+0
;Painel_software_pic16f73.c,100 :: 		CCP2IE_bit  = 0x01;                    //Habilita interrupção do periférico CCP
	BSF        CCP2IE_bit+0, BitPos(CCP2IE_bit+0)
;Painel_software_pic16f73.c,101 :: 		Tempo_H_vel   = CCPR2H;                  //Valor do tempo em ns é armazenado na variável Tempo_H (registrador CCPR2H)
	MOVF       CCPR2H+0, 0
	MOVWF      _Tempo_H_vel+0
;Painel_software_pic16f73.c,102 :: 		Tempo_L_vel   = CCPR2L;                  //Valor do tempo em ns é armazenado na variável Tempo_L (registrador CCPR2L)
	MOVF       CCPR2L+0, 0
	MOVWF      _Tempo_L_vel+0
;Painel_software_pic16f73.c,104 :: 		CCP1CON  = 0x05;                       //Habilita interrupção do periférico CCP  // coloquei
	MOVLW      5
	MOVWF      CCP1CON+0
;Painel_software_pic16f73.c,105 :: 		}
L_interrupt37:
L_interrupt36:
;Painel_software_pic16f73.c,108 :: 		if(INTF_bit){
	BTFSS      INTF_bit+0, BitPos(INTF_bit+0)
	GOTO       L_interrupt38
;Painel_software_pic16f73.c,110 :: 		recebe_dados();
	CALL       _recebe_dados+0
;Painel_software_pic16f73.c,111 :: 		}
L_interrupt38:
;Painel_software_pic16f73.c,113 :: 		} //end interrupt
L_end_interrupt:
L__interrupt79:
	MOVF       ___savePCLATH+0, 0
	MOVWF      PCLATH+0
	SWAPF      ___saveSTATUS+0, 0
	MOVWF      STATUS+0
	SWAPF      R15+0, 1
	SWAPF      R15+0, 0
	RETFIE
; end of _interrupt

_medicao_marcha:

;Painel_software_pic16f73.c,116 :: 		void medicao_marcha(){
;Painel_software_pic16f73.c,120 :: 		if(MARCHA_1 && MARCHA_2){
	BTFSS      RB1_bit+0, BitPos(RB1_bit+0)
	GOTO       L_medicao_marcha41
	BTFSS      RA4_bit+0, BitPos(RA4_bit+0)
	GOTO       L_medicao_marcha41
L__medicao_marcha72:
;Painel_software_pic16f73.c,121 :: 		marcha = 0;
	CLRF       _marcha+0
;Painel_software_pic16f73.c,122 :: 		}
	GOTO       L_medicao_marcha42
L_medicao_marcha41:
;Painel_software_pic16f73.c,124 :: 		else if(!marcha){
	MOVF       _marcha+0, 0
	BTFSS      STATUS+0, 2
	GOTO       L_medicao_marcha43
;Painel_software_pic16f73.c,125 :: 		if(MARCHA_1 ){//&& !control){
	BTFSS      RB1_bit+0, BitPos(RB1_bit+0)
	GOTO       L_medicao_marcha44
;Painel_software_pic16f73.c,127 :: 		marcha = 2;
	MOVLW      2
	MOVWF      _marcha+0
;Painel_software_pic16f73.c,128 :: 		}
L_medicao_marcha44:
;Painel_software_pic16f73.c,133 :: 		if(MARCHA_2){// && !control2){
	BTFSS      RA4_bit+0, BitPos(RA4_bit+0)
	GOTO       L_medicao_marcha45
;Painel_software_pic16f73.c,135 :: 		marcha = 1;
	MOVLW      1
	MOVWF      _marcha+0
;Painel_software_pic16f73.c,136 :: 		}
L_medicao_marcha45:
;Painel_software_pic16f73.c,140 :: 		}
L_medicao_marcha43:
L_medicao_marcha42:
;Painel_software_pic16f73.c,141 :: 		if (marcha != 0){
	MOVF       _marcha+0, 0
	XORLW      0
	BTFSC      STATUS+0, 2
	GOTO       L_medicao_marcha46
;Painel_software_pic16f73.c,142 :: 		if(MARCHA_1 && !control){
	BTFSS      RB1_bit+0, BitPos(RB1_bit+0)
	GOTO       L_medicao_marcha49
	BTFSC      medicao_marcha_control_L0+0, BitPos(medicao_marcha_control_L0+0)
	GOTO       L_medicao_marcha49
L__medicao_marcha71:
;Painel_software_pic16f73.c,143 :: 		control = 1;
	BSF        medicao_marcha_control_L0+0, BitPos(medicao_marcha_control_L0+0)
;Painel_software_pic16f73.c,144 :: 		marcha++;
	INCF       _marcha+0, 1
;Painel_software_pic16f73.c,145 :: 		}
L_medicao_marcha49:
;Painel_software_pic16f73.c,146 :: 		if(!MARCHA_1 && control){
	BTFSC      RB1_bit+0, BitPos(RB1_bit+0)
	GOTO       L_medicao_marcha52
	BTFSS      medicao_marcha_control_L0+0, BitPos(medicao_marcha_control_L0+0)
	GOTO       L_medicao_marcha52
L__medicao_marcha70:
;Painel_software_pic16f73.c,147 :: 		control = 0;
	BCF        medicao_marcha_control_L0+0, BitPos(medicao_marcha_control_L0+0)
;Painel_software_pic16f73.c,148 :: 		}
L_medicao_marcha52:
;Painel_software_pic16f73.c,150 :: 		if(MARCHA_2 && !control2){
	BTFSS      RA4_bit+0, BitPos(RA4_bit+0)
	GOTO       L_medicao_marcha55
	BTFSC      medicao_marcha_control2_L0+0, BitPos(medicao_marcha_control2_L0+0)
	GOTO       L_medicao_marcha55
L__medicao_marcha69:
;Painel_software_pic16f73.c,151 :: 		control2 = 1;
	BSF        medicao_marcha_control2_L0+0, BitPos(medicao_marcha_control2_L0+0)
;Painel_software_pic16f73.c,152 :: 		marcha --;
	DECF       _marcha+0, 1
;Painel_software_pic16f73.c,153 :: 		}
L_medicao_marcha55:
;Painel_software_pic16f73.c,154 :: 		if(!MARCHA_2 && control2){
	BTFSC      RA4_bit+0, BitPos(RA4_bit+0)
	GOTO       L_medicao_marcha58
	BTFSS      medicao_marcha_control2_L0+0, BitPos(medicao_marcha_control2_L0+0)
	GOTO       L_medicao_marcha58
L__medicao_marcha68:
;Painel_software_pic16f73.c,155 :: 		control2 = 0;
	BCF        medicao_marcha_control2_L0+0, BitPos(medicao_marcha_control2_L0+0)
;Painel_software_pic16f73.c,156 :: 		}
L_medicao_marcha58:
;Painel_software_pic16f73.c,157 :: 		}
L_medicao_marcha46:
;Painel_software_pic16f73.c,158 :: 		if(marcha < 0){
	MOVLW      128
	XORWF      _marcha+0, 0
	MOVWF      R0+0
	MOVLW      128
	XORLW      0
	SUBWF      R0+0, 0
	BTFSC      STATUS+0, 0
	GOTO       L_medicao_marcha59
;Painel_software_pic16f73.c,159 :: 		marcha = 0;
	CLRF       _marcha+0
;Painel_software_pic16f73.c,160 :: 		}
	GOTO       L_medicao_marcha60
L_medicao_marcha59:
;Painel_software_pic16f73.c,161 :: 		else if(marcha > 6){
	MOVLW      128
	XORLW      6
	MOVWF      R0+0
	MOVLW      128
	XORWF      _marcha+0, 0
	SUBWF      R0+0, 0
	BTFSC      STATUS+0, 0
	GOTO       L_medicao_marcha61
;Painel_software_pic16f73.c,162 :: 		marcha = 6;
	MOVLW      6
	MOVWF      _marcha+0
;Painel_software_pic16f73.c,163 :: 		}
L_medicao_marcha61:
L_medicao_marcha60:
;Painel_software_pic16f73.c,164 :: 		}     // fim da função marcha
L_end_medicao_marcha:
	RETURN
; end of _medicao_marcha

_main:

;Painel_software_pic16f73.c,166 :: 		void main()
;Painel_software_pic16f73.c,170 :: 		unsigned char a,b,cc,dd = 0;
	CLRF       main_dd_L0+0
	MOVLW      42
	MOVWF      main_txt1_L0+0
	MOVLW      42
	MOVWF      main_txt1_L0+1
	MOVLW      32
	MOVWF      main_txt1_L0+2
	MOVLW      69
	MOVWF      main_txt1_L0+3
	MOVLW      83
	MOVWF      main_txt1_L0+4
	MOVLW      67
	MOVWF      main_txt1_L0+5
	MOVLW      85
	MOVWF      main_txt1_L0+6
	MOVLW      68
	MOVWF      main_txt1_L0+7
	MOVLW      69
	MOVWF      main_txt1_L0+8
	MOVLW      82
	MOVWF      main_txt1_L0+9
	MOVLW      73
	MOVWF      main_txt1_L0+10
	MOVLW      65
	MOVWF      main_txt1_L0+11
	MOVLW      32
	MOVWF      main_txt1_L0+12
	MOVLW      42
	MOVWF      main_txt1_L0+13
	MOVLW      42
	MOVWF      main_txt1_L0+14
	CLRF       main_txt1_L0+15
	MOVLW      42
	MOVWF      main_txt2_L0+0
	MOVLW      42
	MOVWF      main_txt2_L0+1
	MOVLW      42
	MOVWF      main_txt2_L0+2
	MOVLW      42
	MOVWF      main_txt2_L0+3
	MOVLW      32
	MOVWF      main_txt2_L0+4
	MOVLW      85
	MOVWF      main_txt2_L0+5
	MOVLW      70
	MOVWF      main_txt2_L0+6
	MOVLW      83
	MOVWF      main_txt2_L0+7
	MOVLW      65
	MOVWF      main_txt2_L0+8
	MOVLW      69
	MOVWF      main_txt2_L0+9
	MOVLW      32
	MOVWF      main_txt2_L0+10
	MOVLW      42
	MOVWF      main_txt2_L0+11
	MOVLW      42
	MOVWF      main_txt2_L0+12
	MOVLW      42
	MOVWF      main_txt2_L0+13
	MOVLW      42
	MOVWF      main_txt2_L0+14
	CLRF       main_txt2_L0+15
	MOVLW      32
	MOVWF      main_txt3_L0+0
	MOVLW      32
	MOVWF      main_txt3_L0+1
	MOVLW      32
	MOVWF      main_txt3_L0+2
	MOVLW      32
	MOVWF      main_txt3_L0+3
	MOVLW      67
	MOVWF      main_txt3_L0+4
	MOVLW      69
	MOVWF      main_txt3_L0+5
	MOVLW      78
	MOVWF      main_txt3_L0+6
	MOVLW      84
	MOVWF      main_txt3_L0+7
	MOVLW      82
	MOVWF      main_txt3_L0+8
	MOVLW      65
	MOVWF      main_txt3_L0+9
	MOVLW      76
	MOVWF      main_txt3_L0+10
	MOVLW      32
	MOVWF      main_txt3_L0+11
	MOVLW      32
	MOVWF      main_txt3_L0+12
	MOVLW      32
	MOVWF      main_txt3_L0+13
	MOVLW      32
	MOVWF      main_txt3_L0+14
	CLRF       main_txt3_L0+15
	MOVLW      32
	MOVWF      main_txt4_L0+0
	MOVLW      32
	MOVWF      main_txt4_L0+1
	MOVLW      68
	MOVWF      main_txt4_L0+2
	MOVLW      69
	MOVWF      main_txt4_L0+3
	MOVLW      32
	MOVWF      main_txt4_L0+4
	MOVLW      67
	MOVWF      main_txt4_L0+5
	MOVLW      79
	MOVWF      main_txt4_L0+6
	MOVLW      78
	MOVWF      main_txt4_L0+7
	MOVLW      84
	MOVWF      main_txt4_L0+8
	MOVLW      82
	MOVWF      main_txt4_L0+9
	MOVLW      79
	MOVWF      main_txt4_L0+10
	MOVLW      76
	MOVWF      main_txt4_L0+11
	MOVLW      69
	MOVWF      main_txt4_L0+12
	MOVLW      32
	MOVWF      main_txt4_L0+13
	MOVLW      32
	MOVWF      main_txt4_L0+14
	CLRF       main_txt4_L0+15
;Painel_software_pic16f73.c,177 :: 		TRISA = 0x10;
	MOVLW      16
	MOVWF      TRISA+0
;Painel_software_pic16f73.c,178 :: 		TRISB = 0x03;
	MOVLW      3
	MOVWF      TRISB+0
;Painel_software_pic16f73.c,179 :: 		TRISC = 0x16;
	MOVLW      22
	MOVWF      TRISC+0
;Painel_software_pic16f73.c,181 :: 		Lcd_Init();                        // Inicialize LCD
	CALL       _Lcd_Init+0
;Painel_software_pic16f73.c,182 :: 		config_nrf24();                   //  Configure NRF24
	CALL       _config_nrf24+0
;Painel_software_pic16f73.c,184 :: 		Lcd_Cmd(_LCD_CLEAR);               // Clear display
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Painel_software_pic16f73.c,185 :: 		Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
	MOVLW      12
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Painel_software_pic16f73.c,186 :: 		Lcd_Out(1,1,txt1);                 // Write text in first row
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      main_txt1_L0+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Painel_software_pic16f73.c,187 :: 		Lcd_Out(2,1,txt2);                 // Write text in second row
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      main_txt2_L0+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Painel_software_pic16f73.c,188 :: 		Delay_ms( 2000 );
	MOVLW      41
	MOVWF      R11+0
	MOVLW      150
	MOVWF      R12+0
	MOVLW      127
	MOVWF      R13+0
L_main62:
	DECFSZ     R13+0, 1
	GOTO       L_main62
	DECFSZ     R12+0, 1
	GOTO       L_main62
	DECFSZ     R11+0, 1
	GOTO       L_main62
;Painel_software_pic16f73.c,189 :: 		Lcd_Cmd(_LCD_CLEAR);               // Clear display
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Painel_software_pic16f73.c,190 :: 		Lcd_Out(1,1,txt3);                 // Write text in first row
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      main_txt3_L0+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Painel_software_pic16f73.c,191 :: 		Lcd_Out(2,1,txt4);                 // Write text in second row
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      main_txt4_L0+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Painel_software_pic16f73.c,192 :: 		Delay_ms( 2000 );
	MOVLW      41
	MOVWF      R11+0
	MOVLW      150
	MOVWF      R12+0
	MOVLW      127
	MOVWF      R13+0
L_main63:
	DECFSZ     R13+0, 1
	GOTO       L_main63
	DECFSZ     R12+0, 1
	GOTO       L_main63
	DECFSZ     R11+0, 1
	GOTO       L_main63
;Painel_software_pic16f73.c,193 :: 		Lcd_Cmd(_LCD_CLEAR);               // Clear display
	MOVLW      1
	MOVWF      FARG_Lcd_Cmd_out_char+0
	CALL       _Lcd_Cmd+0
;Painel_software_pic16f73.c,196 :: 		INTCON      = 0x00;                        //Desabilita interrupção global , interrupção por periféricos  e interrupção externa
	CLRF       INTCON+0
;Painel_software_pic16f73.c,197 :: 		TMR1IE_bit  = 0x00;                        //Desabilita interrupções de TMR1
	BCF        TMR1IE_bit+0, BitPos(TMR1IE_bit+0)
;Painel_software_pic16f73.c,198 :: 		CCP1IE_bit  = 0x00;                        //Habilita interrupções do módulo CCP1
	BCF        CCP1IE_bit+0, BitPos(CCP1IE_bit+0)
;Painel_software_pic16f73.c,199 :: 		CCP1CON     = 0x05;                        //Configura captura por borda de subida
	MOVLW      5
	MOVWF      CCP1CON+0
;Painel_software_pic16f73.c,200 :: 		T1CON       = 0x00;                        // conf preescale de 1:1 e FOSC/4
	CLRF       T1CON+0
;Painel_software_pic16f73.c,202 :: 		CCP2IE_bit  = 0x00;                        //Habilita interrupções do módulo CCP2
	BCF        CCP2IE_bit+0, BitPos(CCP2IE_bit+0)
;Painel_software_pic16f73.c,205 :: 		INTCON      = 0xD0;                        //Habilita interrupção global , interrupção por periféricos  e interrupção externa
	MOVLW      208
	MOVWF      INTCON+0
;Painel_software_pic16f73.c,207 :: 		while(1)
L_main64:
;Painel_software_pic16f73.c,209 :: 		medicao_marcha();
	CALL       _medicao_marcha+0
;Painel_software_pic16f73.c,211 :: 		ENVIA[0]= marcha;
	MOVF       _marcha+0, 0
	MOVWF      _ENVIA+0
;Painel_software_pic16f73.c,212 :: 		ENVIA[1]= Tempo_H_rpm;
	MOVF       _Tempo_H_rpm+0, 0
	MOVWF      _ENVIA+1
;Painel_software_pic16f73.c,213 :: 		ENVIA[2]= Tempo_L_rpm;
	MOVF       _Tempo_L_rpm+0, 0
	MOVWF      _ENVIA+2
;Painel_software_pic16f73.c,214 :: 		ENVIA[3]= Tempo_H_vel;
	MOVF       _Tempo_H_vel+0, 0
	MOVWF      _ENVIA+3
;Painel_software_pic16f73.c,215 :: 		ENVIA[4]= Tempo_L_vel;
	MOVF       _Tempo_L_vel+0, 0
	MOVWF      _ENVIA+4
;Painel_software_pic16f73.c,218 :: 		CSN = 0;
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;Painel_software_pic16f73.c,219 :: 		SPI1_Write(0x07);
	MOVLW      7
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;Painel_software_pic16f73.c,220 :: 		a = SPI1_Read(0);
	CLRF       FARG_SPI1_Read_buffer+0
	CALL       _SPI1_Read+0
	MOVF       R0+0, 0
	MOVWF      main_a_L0+0
;Painel_software_pic16f73.c,221 :: 		CSN = 1;
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;Painel_software_pic16f73.c,224 :: 		CSN = 0;
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;Painel_software_pic16f73.c,225 :: 		SPI1_Write(0x00);
	CLRF       FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;Painel_software_pic16f73.c,226 :: 		b = SPI1_Read(0);
	CLRF       FARG_SPI1_Read_buffer+0
	CALL       _SPI1_Read+0
	MOVF       R0+0, 0
	MOVWF      main_b_L0+0
;Painel_software_pic16f73.c,227 :: 		CSN = 1;
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;Painel_software_pic16f73.c,230 :: 		CSN = 0;
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;Painel_software_pic16f73.c,231 :: 		SPI1_Write(0x02);
	MOVLW      2
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;Painel_software_pic16f73.c,232 :: 		cc = SPI1_Read(0);
	CLRF       FARG_SPI1_Read_buffer+0
	CALL       _SPI1_Read+0
	MOVF       R0+0, 0
	MOVWF      main_cc_L0+0
;Painel_software_pic16f73.c,233 :: 		CSN = 1;
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;Painel_software_pic16f73.c,236 :: 		CSN = 0;
	BCF        RA3_bit+0, BitPos(RA3_bit+0)
;Painel_software_pic16f73.c,237 :: 		SPI1_Write(0x0A);
	MOVLW      10
	MOVWF      FARG_SPI1_Write_data_+0
	CALL       _SPI1_Write+0
;Painel_software_pic16f73.c,238 :: 		dd = SPI1_Read(0);
	CLRF       FARG_SPI1_Read_buffer+0
	CALL       _SPI1_Read+0
	MOVF       R0+0, 0
	MOVWF      main_dd_L0+0
;Painel_software_pic16f73.c,239 :: 		CSN = 1;
	BSF        RA3_bit+0, BitPos(RA3_bit+0)
;Painel_software_pic16f73.c,243 :: 		ByteToStr( a, x1 );
	MOVF       main_a_L0+0, 0
	MOVWF      FARG_ByteToStr_input+0
	MOVLW      _x1+0
	MOVWF      FARG_ByteToStr_output+0
	CALL       _ByteToStr+0
;Painel_software_pic16f73.c,244 :: 		ByteToStr( b, x2 );
	MOVF       main_b_L0+0, 0
	MOVWF      FARG_ByteToStr_input+0
	MOVLW      _x2+0
	MOVWF      FARG_ByteToStr_output+0
	CALL       _ByteToStr+0
;Painel_software_pic16f73.c,245 :: 		ByteToStr( cc, x3 );
	MOVF       main_cc_L0+0, 0
	MOVWF      FARG_ByteToStr_input+0
	MOVLW      _x3+0
	MOVWF      FARG_ByteToStr_output+0
	CALL       _ByteToStr+0
;Painel_software_pic16f73.c,246 :: 		ByteToStr( dd, x4 );
	MOVF       main_dd_L0+0, 0
	MOVWF      FARG_ByteToStr_input+0
	MOVLW      _x4+0
	MOVWF      FARG_ByteToStr_output+0
	CALL       _ByteToStr+0
;Painel_software_pic16f73.c,248 :: 		Lcd_Out( 1,1, x1 );
	MOVLW      1
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _x1+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Painel_software_pic16f73.c,249 :: 		Lcd_Out_Cp(",");
	MOVLW      ?lstr1_Painel_software_pic16f73+0
	MOVWF      FARG_Lcd_Out_CP_text+0
	CALL       _Lcd_Out_CP+0
;Painel_software_pic16f73.c,250 :: 		Lcd_Out_Cp( x2 );
	MOVLW      _x2+0
	MOVWF      FARG_Lcd_Out_CP_text+0
	CALL       _Lcd_Out_CP+0
;Painel_software_pic16f73.c,251 :: 		Lcd_Out_Cp(",");
	MOVLW      ?lstr2_Painel_software_pic16f73+0
	MOVWF      FARG_Lcd_Out_CP_text+0
	CALL       _Lcd_Out_CP+0
;Painel_software_pic16f73.c,252 :: 		Lcd_Out_Cp( x3 );
	MOVLW      _x3+0
	MOVWF      FARG_Lcd_Out_CP_text+0
	CALL       _Lcd_Out_CP+0
;Painel_software_pic16f73.c,253 :: 		Lcd_Out_Cp(",");
	MOVLW      ?lstr3_Painel_software_pic16f73+0
	MOVWF      FARG_Lcd_Out_CP_text+0
	CALL       _Lcd_Out_CP+0
;Painel_software_pic16f73.c,254 :: 		Lcd_Out_Cp( x4 );
	MOVLW      _x4+0
	MOVWF      FARG_Lcd_Out_CP_text+0
	CALL       _Lcd_Out_CP+0
;Painel_software_pic16f73.c,256 :: 		ByteToStr( TEMPO_H_vel , x5 );
	MOVF       _Tempo_H_vel+0, 0
	MOVWF      FARG_ByteToStr_input+0
	MOVLW      _x5+0
	MOVWF      FARG_ByteToStr_output+0
	CALL       _ByteToStr+0
;Painel_software_pic16f73.c,257 :: 		ByteToStr( TEMPO_L_vel, x6 );
	MOVF       _Tempo_L_vel+0, 0
	MOVWF      FARG_ByteToStr_input+0
	MOVLW      _x6+0
	MOVWF      FARG_ByteToStr_output+0
	CALL       _ByteToStr+0
;Painel_software_pic16f73.c,258 :: 		ByteToStr( TEMPO_H_rpm, x7 );
	MOVF       _Tempo_H_rpm+0, 0
	MOVWF      FARG_ByteToStr_input+0
	MOVLW      _x7+0
	MOVWF      FARG_ByteToStr_output+0
	CALL       _ByteToStr+0
;Painel_software_pic16f73.c,259 :: 		BytetoStr( TEMPO_L_rpm, x8);
	MOVF       _Tempo_L_rpm+0, 0
	MOVWF      FARG_ByteToStr_input+0
	MOVLW      _x8+0
	MOVWF      FARG_ByteToStr_output+0
	CALL       _ByteToStr+0
;Painel_software_pic16f73.c,261 :: 		Lcd_Out( 2,1, x5 );
	MOVLW      2
	MOVWF      FARG_Lcd_Out_row+0
	MOVLW      1
	MOVWF      FARG_Lcd_Out_column+0
	MOVLW      _x5+0
	MOVWF      FARG_Lcd_Out_text+0
	CALL       _Lcd_Out+0
;Painel_software_pic16f73.c,262 :: 		Lcd_Out_Cp(",");
	MOVLW      ?lstr4_Painel_software_pic16f73+0
	MOVWF      FARG_Lcd_Out_CP_text+0
	CALL       _Lcd_Out_CP+0
;Painel_software_pic16f73.c,263 :: 		Lcd_Out_Cp( x6 );
	MOVLW      _x6+0
	MOVWF      FARG_Lcd_Out_CP_text+0
	CALL       _Lcd_Out_CP+0
;Painel_software_pic16f73.c,264 :: 		Lcd_Out_Cp(",");
	MOVLW      ?lstr5_Painel_software_pic16f73+0
	MOVWF      FARG_Lcd_Out_CP_text+0
	CALL       _Lcd_Out_CP+0
;Painel_software_pic16f73.c,265 :: 		Lcd_Out_Cp( x7 );
	MOVLW      _x7+0
	MOVWF      FARG_Lcd_Out_CP_text+0
	CALL       _Lcd_Out_CP+0
;Painel_software_pic16f73.c,266 :: 		Lcd_Out_Cp(",");
	MOVLW      ?lstr6_Painel_software_pic16f73+0
	MOVWF      FARG_Lcd_Out_CP_text+0
	CALL       _Lcd_Out_CP+0
;Painel_software_pic16f73.c,267 :: 		Lcd_Out_Cp( x8 );
	MOVLW      _x8+0
	MOVWF      FARG_Lcd_Out_CP_text+0
	CALL       _Lcd_Out_CP+0
;Painel_software_pic16f73.c,270 :: 		ACK = envia_dados();
	CALL       _envia_dados+0
	MOVF       R0+0, 0
	MOVWF      _ACK+0
;Painel_software_pic16f73.c,271 :: 		}
	GOTO       L_main64
;Painel_software_pic16f73.c,273 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
