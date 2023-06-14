# GPIO_LED
En applikation som kontrollerar hårdvaran av STM32F411xC i syfte att kontrollera IOn via utvecklingskortets pins

Projektet kommer att består utav följande struktur:
- main.c - Huvudansvarig för applikationens användning
- my_stm32f4_gpio_driver.h - Definitioner av beteckningar och funktioner som kommer kallas på utav drivrutinen i sig
- my_stm32f4_gpio_lib.h - Definitioner av hårdvaran vi behöver kommunicera med
- my_stm32f4_gpio_lib.c - Tillämpar vi funktionalitet