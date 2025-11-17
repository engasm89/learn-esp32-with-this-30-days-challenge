#include "freertos/FreeRTOS.h" // FreeRTOS
#include "freertos/task.h" // Tasks
#include "driver/gpio.h" // GPIO

#define LED GPIO_NUM_2 // LED

static void task_fast(void *arg) { // Fast blink task
  while (true) { gpio_set_level(LED, 1); vTaskDelay(pdMS_TO_TICKS(100)); gpio_set_level(LED, 0); vTaskDelay(pdMS_TO_TICKS(100)); } // Loop
} // End

static void task_slow(void *arg) { // Slow blink task
  while (true) { gpio_set_level(LED, 1); vTaskDelay(pdMS_TO_TICKS(500)); gpio_set_level(LED, 0); vTaskDelay(pdMS_TO_TICKS(500)); } // Loop
} // End

void app_main(void) { // Entry
  gpio_set_direction(LED, GPIO_MODE_OUTPUT); // Output
  xTaskCreate(task_fast, "fast", 2048, NULL, 5, NULL); // Create fast
  xTaskCreate(task_slow, "slow", 2048, NULL, 4, NULL); // Create slow
} // End

