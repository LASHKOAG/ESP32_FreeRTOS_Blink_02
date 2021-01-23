//Toggles LED at different rates using separate tasks

//Use only core 1 for demo purposes

#if CONFIG_FREERTOS_UNICORE
  static const BaseType_t app_cpu = 0;
#else
  static const BaseType_t app_cpu = 1;
#endif

//LED rates
//ms
static const int rate_1 = 500;
static const int rate_2 = 323;

//Pins
//static const int led_pin = LED_BUILTIN;
static const int led_pin = 2;

//task_1: blink an LED at rate_1
void toggle_led_1(void* parameter){
  while(1){
    digitalWrite(led_pin, HIGH);
    vTaskDelay(rate_1/portTICK_PERIOD_MS);
    digitalWrite(led_pin, LOW);
    vTaskDelay(rate_1/portTICK_PERIOD_MS);
  }
}


//task_2: blink an LED at rate_2
void toggle_led_2(void* parameter){
  while(1){
    digitalWrite(led_pin, HIGH);
    vTaskDelay(rate_2/portTICK_PERIOD_MS);
    digitalWrite(led_pin, LOW);
    vTaskDelay(rate_2/portTICK_PERIOD_MS);
  }
}


void setup() {
  pinMode(led_pin, OUTPUT);

  //run task_1
  xTaskCreatePinnedToCore(
                          toggle_led_1, //function to be called
                          "Toggle_1",   //name of task
                          1024,         //stack size (bytes in ESP32, word in FreeRTOS)
                          NULL,         //parameter to pass to fuction
                          1,            //task priority (0 to configMAX_PRIORITIES-1)
                          NULL,         //task handle
                          0);     //run on one core ESP32  app_cpu

  //run task_2
//  xTaskCreatePinnedToCore(
//                          toggle_led_2, //function to be called
//                          "Toggle_2",   //name of task
//                          1024,         //stack size (bytes in ESP32, word in FreeRTOS)
//                          NULL,         //parameter to pass to fuction
//                          1,            //task priority (0 to configMAX_PRIORITIES-1)
//                          NULL,         //task handle
//                          1);     //run on one core ESP32  app_cpu

//xTaskCreate(toggle_led_1, "Toggle_1", 1024, NULL, 0, NULL);
//  vTaskStartScheduler();
}



void loop() {
  
//fot test pin
//  digitalWrite(led_pin, HIGH);
//  delay(rate_2);
//  digitalWrite(led_pin, LOW);
//  delay(rate_2);

}
