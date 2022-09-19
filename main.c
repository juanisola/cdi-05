#include <stdio.h>
#include "pico/stdlib.h"

int main() {
    for(int pin=0;pin<7;pin++){
      gpio_init(pin);
      gpio_set_dir(pin, true);
    }
    uint8_t digitos[]={~0x01, ~0x4f, ~0x12, ~0x06, ~0x4c, ~0x24, ~0x20, ~0x0f, ~0x00, ~0x0c};
    int contador=0;
    gpio_init(16);
    gpio_init(17);
    gpio_init(18);
    gpio_set_dir(16, false);
    gpio_set_dir(17, false);
    gpio_set_dir(18, false);
    stdio_init_all();
    

    while (true) {
      for(int i=0;i<7;i++){
        bool val=digitos[contador] & (1<<i);
        gpio_put(i, val);       
      }  
      if(gpio_get(18)==true){
        contador=0;
      }
       else if(gpio_get(17)==true){
        contador--;
      }
       else if(gpio_get(16)==true){
        contador++;
      }
      sleep_ms(500);
        
    }
    return 0;
}
