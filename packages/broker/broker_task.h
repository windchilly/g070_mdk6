#ifndef __BROKER_H__
#define __BROKER_H__

#include <stdint.h>

#define CONTAINER_AMOUNT	50
#define SUBSCRIBE_AMOUNT	10
#define RELEASE_NAME_NUM	30
#define SUBSCRIBE_NAME_NUM	20

typedef struct
{
	uint8_t buff[CONTAINER_AMOUNT + 1];
	uint8_t serial;	
	uint8_t name[RELEASE_NAME_NUM + 1];
	uint8_t length;
}broker_data_t;

typedef struct
{
	uint8_t release_name[RELEASE_NAME_NUM + 1];
	uint8_t subscribe_name[SUBSCRIBE_NAME_NUM +1];	
	broker_data_t release_data;
	broker_data_t subscribe_data[SUBSCRIBE_AMOUNT + 1];	
}broker_node_t;

typedef void(*node_fn)(broker_data_t* data);

extern broker_node_t test_node;
extern broker_node_t btn_node;

void broker_handle(void *pvParameters);

void broker_send(uint8_t* release_data,
				 uint8_t release_length, 
				 uint8_t* release_name, 
				 uint8_t release_name_length,
				 uint32_t delay);
void broker_poll(broker_node_t* node, node_fn node_func);
#endif
