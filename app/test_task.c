#include "broker_task.h"

#include "user_task.h"

#define POLL_INTERVAL (1)

const event_id_t EVE_MSG_TEST = 0xF002;

static event_id_t EVE_TEST = 1 << 0;
static event_id_t EVE_BROKER = 1 << 1;

static void test_broker_cb(broker_data_t* param);

broker_node_t test_node = 
{
	.release_name = "btn",
	.subscribe_name = "test",
};

static void task_test_init(task_id_t task_id)
{
	cd_timer_startre(task_id, EVE_BROKER, POLL_INTERVAL);
	cd_timer_startre(task_id, EVE_TEST, 50);

	return;
}

static cd_uint16_t task_test_event_process(task_id_t task_id, event_asb_t events)
{
	if(events & EVE_TEST)
	{
		static cd_uint16_t times = 0;
		times++;

		broker_poll(&test_node, test_broker_cb);
		broker_send((cd_uint8_t *)&times,
					sizeof(times),
					test_node.release_name,
					sizeof(test_node.release_name),
					0);
		LOG_D("TASK_TEST: %d", times);

		return events ^ EVE_TEST;
	}
	else if(events & EVE_BROKER)
	{
		broker_handle(CD_NULL);
		LOG_D("broker task triggered");

		return events ^ EVE_BROKER;
	}

    return 0;
}

static cd_task_ops_t test_ops = {task_test_init, task_test_event_process};
static void test_task(void)
{
	cd_task_create(&test_ops, TASK_TEST);
	LOG_I("TASK INITED");
}
INIT_APP_EXPORT(test_task);

static void test_broker_cb(broker_data_t* param)
{
	LOG_I("btn data recevd");
}
