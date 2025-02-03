#include "pico/stdlib.h"
#include <stdio.h>

// Definição dos pinos dos LEDs
#define LED_RED 11
#define LED_YELLOW 12
#define LED_GREEN 13

// Estados do semáforo
typedef enum {
    ESTADO_VERMELHO,
    ESTADO_AMARELO,
    ESTADO_VERDE
} EstadoDoLed;

// Variável global para armazenar o estado atual do semáforo
volatile EstadoDoLed estadoDoLed = ESTADO_VERMELHO;

// Função de callback do temporizador
bool repeating_timer_callback(struct repeating_timer *t) {
    // Alterna o estado do semáforo
    switch (estadoDoLed) {
        case ESTADO_VERMELHO:
            gpio_put(LED_RED, 0);    // Apaga LED vermelho
            gpio_put(LED_YELLOW, 1); // Acende LED amarelo
            estadoDoLed = ESTADO_AMARELO;
            break;
        case ESTADO_AMARELO:
            gpio_put(LED_YELLOW, 0); // Apaga LED amarelo
            gpio_put(LED_GREEN, 1);  // Acende LED verde
            estadoDoLed = ESTADO_VERDE;
            break;
        case ESTADO_VERDE:
            gpio_put(LED_GREEN, 0);  // Apaga LED verde
            gpio_put(LED_RED, 1);    // Acende LED vermelho
            estadoDoLed = ESTADO_VERMELHO;
            break;
    }
    return true; // Mantém o temporizador ativo
}

int main() {
    // Inicializa a comunicação serial (para debug)
    stdio_init_all();

    // Configura os pinos dos LEDs como saída
    gpio_init(LED_RED);
    gpio_init(LED_YELLOW);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_set_dir(LED_GREEN, GPIO_OUT);

    // Inicia o semáforo com o LED vermelho aceso
    gpio_put(LED_RED, 1);
    gpio_put(LED_YELLOW, 0);
    gpio_put(LED_GREEN, 0);

    // Configura o temporizador para chamar a função de callback a cada 3 segundos
    struct repeating_timer timer;
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Loop principal
    while (true) {
        // Envia uma mensagem pela porta serial a cada segundo
        printf("Estado atual do semáforo: %d\n", estadoDoLed);
        sleep_ms(1000);
    }

    return 0;
}