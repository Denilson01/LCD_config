/*
 * File:   main.c
 * Author: 20185087
 *
 * Created on 14 de Maio de 2021, 16:23
 */

#include "config.h"
#include <xc.h>
#include "delay.h"
#include "dispLCD4vias.h"
#include "teclado.h"

void main(void) 
{
    char estado;
    char tecla;
    dispLCD_init();
    teclado_init();
    
    tecla = teclado_scan();
    
    while(1)
    {
        switch( estado )
        {
            case 0:
                estado = 1;
                break;
            
            case 1:
                dispLCD(0,0,"    Boa Tarde!  ");
                //dispLCD(0,0,"  Este trem tem ");
                //delay(3000);
                //dispLCD(1,0,"  como destino  ");
                //delay(3000);
                //dispLCD(0,0,"  a estação     ");
                //delay(3000);
                //dispLCD(1,0,"   JANDIRA      ");
                //delay(3000);
                delay( 3000 );
                estado = 10;
                break;
            
            case 10:
                dispLCD(0,0,"escolha a opcao:");
                dispLCD(1,0,"1:Operacao 2:Cfg");
                if(tecla == '1')
                    estado = 20;
                if(tecla == '2')
                    estado = 100;
                    
                
               break;
            
            case 20:
                dispLCD(0,0,"Operando...     ");
                if(tecla == '*')
                    estado = 1;
                break;
            
            case 100:
                dispLCD(0,0,"Configurando    ");
                if(tecla == '*')
                    estado = 1;
            
                break;

        }
    } 
    
    return;
}
