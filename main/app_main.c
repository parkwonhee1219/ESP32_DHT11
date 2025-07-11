#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "dht.h"  // esp-idf-lib의 DHT 드라이버

#define DHT_GPIO 4  // DHT11 DATA 핀을 연결한 ESP32 GPIO 번호

static const char *TAG = "DHT11_EXAMPLE";

void app_main(void)
{
    int16_t temperature = 0;
    int16_t humidity = 0;

    while (1)
    {
        esp_err_t result = dht_read_data(DHT_TYPE_DHT11, DHT_GPIO, &humidity, &temperature);
        if (result == ESP_OK)
        {
            ESP_LOGI(TAG, "온도: %.1f°C, 습도: %.1f%%",
                     temperature / 10.0, humidity / 10.0);
        }
        else
        {
            ESP_LOGE(TAG, "센서 읽기 실패: %s", esp_err_to_name(result));
        }

        vTaskDelay(pdMS_TO_TICKS(2000));  // 2초 간격으로 측정
    }
}
