Semáforo com Raspberry Pi Pico no Wokwi
Este repositório contém o código e o diagrama para simular um semáforo utilizando um Raspberry Pi Pico no simulador Wokwi. O projeto foi desenvolvido como parte de uma atividade prática para entender o funcionamento de temporizadores, GPIOs e comunicação serial.

Descrição do Projeto
O projeto simula um semáforo com três LEDs (vermelho, amarelo e verde), que alternam seus estados a cada 3 segundos. O código foi desenvolvido em C e utiliza a placa Raspberry Pi Pico. O simulador Wokwi permite testar o circuito e o código de forma interativa.

Diagrama do Circuito
O circuito foi montado no Wokwi e consiste nos seguintes componentes:

Raspberry Pi Pico: Placa controladora.

LEDs: Três LEDs (vermelho, amarelo e verde) conectados aos GPIOs 11, 12 e 13, respectivamente.

Resistores: Resistores de 1kΩ para limitar a corrente dos LEDs.

O diagrama do circuito pode ser visualizado no arquivo diagram.json.

Funcionalidades
Estados do Semáforo:

Vermelho: LED vermelho aceso.

Amarelo: LED amarelo aceso.

Verde: LED verde aceso.

Temporizador:

O estado do semáforo muda a cada 3 segundos.

Comunicação Serial:

A cada segundo, o estado atual do semáforo é enviado para a porta serial.

Como Executar o Projeto
Pré-requisitos
Visual Studio Code (VSCode) com a extensão Wokwi instalada.

Arquivo diagram.json para o circuito.

Arquivo firmware.c para o código.
