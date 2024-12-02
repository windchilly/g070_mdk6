#include <string.h>
#include "broker_task.h"

#include "cdos.h"

#define BROKER_AMOUNT		3
#define RELEASE_BUFF_MAX	20

typedef struct
{
	broker_data_t release[RELEASE_BUFF_MAX + 1];
	uint32_t delay[RELEASE_BUFF_MAX + 1];
}broker_buff_t;
static broker_buff_t broker_buff;
static broker_node_t broker_core;

static broker_node_t* broker_information[BROKER_AMOUNT] =
{
	&broker_core,
	&test_node,
	&btn_node,
};

static void broker_proc(void)
{
	for(uint8_t i = 0; i < RELEASE_BUFF_MAX; i++)
	{
		if(broker_buff.release[i].serial != 0)
		{
			if(broker_buff.delay[i] > 0 )
			{
				broker_buff.delay[i]--;
			}
			else
			{
				if(broker_core.release_data.serial == 0) 
				{
					memcpy(broker_core.release_name, &broker_buff.release[i].name, sizeof(broker_core.release_data.name));
					memcpy(broker_core.release_data.name, &broker_buff.release[i].name, sizeof(broker_core.release_data.name));
					memcpy(broker_core.release_data.buff, &broker_buff.release[i].buff, sizeof(broker_core.release_data.buff));
					broker_core.release_data.length = broker_buff.release[i].length;
					broker_core.release_data.serial = broker_buff.release[i].serial;
					memset(&broker_buff.release[i], 0, sizeof(broker_data_t));
					break;
				}
			}
		}
	}
}

static void broker_push(uint8_t release)
{
	for(uint8_t i = 0; i < BROKER_AMOUNT; i++)
	{
		if(i != release)
		{
			if((strstr((char*)broker_information[i]->subscribe_name ,(char*)broker_information[release]->release_name)) != NULL)
			{
				for(uint8_t k = 0; k < (SUBSCRIBE_AMOUNT - 1); k++)
				{
					if(broker_information[i]->subscribe_data[k].serial == 0)
					{
						memcpy(broker_information[i]->subscribe_data[k].buff, broker_information[release]->release_data.buff ,CONTAINER_AMOUNT);						
						memcpy(broker_information[i]->subscribe_data[k].name, broker_information[release]->release_name , sizeof(broker_information[0]->subscribe_data[0].name));						
						broker_information[i]->subscribe_data[k].serial = broker_information[release]->release_data.serial;
						broker_information[i]->subscribe_data[k].length = broker_information[release]->release_data.length;
						break;
					}
				}
			}
		}
	}
}

static void broker_clean(broker_data_t* release)
{
	memset(release->buff, 0, sizeof(release->buff));
	memset(release->name, 0, sizeof(release->name));	
	release->serial = 0;
	release->length = 0;
}

void broker_handle(void *pvParameters)
{
	broker_proc();

	for(uint8_t i = 0; i < BROKER_AMOUNT; i++)
	{
		if(broker_information[i]->release_data.serial != 0)
		{
			broker_push(i);
			broker_clean(&broker_information[i]->release_data);
		}
	}
}

static uint32_t broker_check(broker_node_t* node)
{
	for(uint8_t i = 0 ; i < (SUBSCRIBE_AMOUNT - 1); i++)
	{
		if(node->subscribe_data[i].serial != 0)
		{
			return i;
		}
	}

	return 0xFFFFFFFF;
}

void broker_poll(broker_node_t* node, node_fn node_func)
{
	uint32_t subscribe;

	subscribe = broker_check(node);

	if(subscribe != 0xFFFFFFFF)
	{
		(*node_func)(&node->subscribe_data[subscribe]);
		broker_clean(&node->subscribe_data[subscribe]);
	}
}

void broker_send(uint8_t* release_data,
				 uint8_t release_length, 
				 uint8_t* release_name, 
				 uint8_t release_name_length,
				 uint32_t delay)
{
	broker_data_t data;

	memcpy(data.name, release_name, release_name_length);	
	memcpy(data.buff, release_data, release_length);
	data.length = release_length;
	data.serial = 1;

	uint8_t j;
	for(uint8_t i = 0; i < RELEASE_BUFF_MAX; i++)
	{
		if(broker_buff.release[i].serial == 0)
		{
			memcpy(&broker_buff.release[i], &data, sizeof(data));
			broker_buff.delay[i] = delay;
			
			j = i;
			break;
		}
	}

	LOG_I("buffer used %d", j);
}
