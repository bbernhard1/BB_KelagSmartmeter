// Using UART2 for reading the data from the smart meter, if you use the UART0 you can not upload new code to the board cause its blocked while reading from the meter!
int uart2_rx_gpio = 16;
int uart2_tx_gpio = 17;
int data_request_gpio = 26;
int led_builtin = 2;

// Wifi Settings
String hostname = "ESP_Smartmeter";

// MQTT Settings
const char* MQTTBroker = "10.0.0.1"; //IPS Server
const int MQTTPort = 1883;  // IPS MQTT Port


// Smartmeter Protocoll
const byte start_byte = 0x7E; 
const byte stop_byte = 0x7E;

const int max_wait_time_for_reading_data = 1100;
int delay_before_reading_data = 1000;

const int message_length = 123;
byte message[message_length];
byte buffer[90];

bool use_test_data = false;
byte testData[123] = {0x7e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
                      0x00, 0x00, 0x7e};