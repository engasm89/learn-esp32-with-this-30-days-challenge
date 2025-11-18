/*
 * Course: Learn Esp32 With This 30 Days Challenge
 * Platform: ESP32
 * Author: Ashraf S A AlMadhoun
 * 
 * Description:
 * This code demonstrates the core concepts taught in the "Learn Esp32 With This 30 Days Challenge" course.
 * It provides a practical implementation that students can study, modify, and
 * use as a foundation for their own projects.
 * 
 * Learning Objectives:
 * - Understand the fundamental principles covered in this course
 * - Practice implementing the concepts with real code
 * - Build a working example that can be extended
 * 
 * Hardware Requirements:
 * - Development board (ESP32)
 * - Components as specified in CIRCUIT.md
 * - USB cable for programming
 * 
 * Pin Connections:
 * Refer to CIRCUIT.md for detailed wiring diagrams and pin assignments.
 * 
 * Usage:
 * 1. Review the code structure and comments
 * 2. Connect hardware according to CIRCUIT.md
 * 3. Upload code to your development board
 * 4. Monitor serial output for debugging
 * 
 * Course Link: https://www.udemy.com/course/learn-esp32-with-this-30-days-challenge/
 * Repository: https://github.com/engasm89/learn-esp32-with-this-30-days-challenge
 * 
 * Copyright (c) 2025 Ashraf S A AlMadhoun
 * Licensed under MIT License
 */

#include "freertos/FreeRTOS.h" // FreeRTOS
#include "freertos/task.h" // Tasks
#include "driver/gpio.h" // GPIO

#define LED GPIO_NUM_2 // LED
static int day = 1; // Simulated day counter

static void task_fast(void *arg) { // Fast blink task
  while (true) { gpio_set_level(LED, 1); vTaskDelay(pdMS_TO_TICKS(100)); gpio_set_level(LED, 0); vTaskDelay(pdMS_TO_TICKS(100)); day++; } // Loop increments day
} // End

static void task_slow(void *arg) { // Slow blink task
  while (true) { gpio_set_level(LED, 1); vTaskDelay(pdMS_TO_TICKS(500)); gpio_set_level(LED, 0); vTaskDelay(pdMS_TO_TICKS(500)); } // Loop
} // End

void app_main(void) { // Program entry point
  gpio_set_direction(LED, GPIO_MODE_OUTPUT); // Output
  xTaskCreate(task_fast, "fast", 2048, NULL, 5, NULL); // Create fast
  xTaskCreate(task_slow, "slow", 2048, NULL, 4, NULL); // Create slow
} // End

