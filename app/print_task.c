#include "user_task.h"
#include "broker_task.h"

#define POLL_CYCLE (3000)

static event_id_t EVE_POLL = 1 << 0;
static event_id_t EVE_BROKER = 1 << 1;

broker_node_t print_node = 
{
	.release_name = "btn",
	.subscribe_name = "print",	
};

static void print_init(task_id_t task_id)
{
    cd_timer_startre(task_id, EVE_POLL, POLL_CYCLE);
	cd_timer_startre(task_id, EVE_BROKER, 1);
}

static cd_uint16_t print_process(task_id_t task_id, event_asb_t events)
{
    if(events & EVE_POLL)
    {
        static cd_uint16_t print_count = 0;
		cd_msg_bdy_t *msg;

        print_count++;
		msg = (cd_msg_bdy_t*)cd_msg_alloc(sizeof(cd_msg_bdy_t));
		msg->data = (cd_uint8_t *)&print_count;

		if(msg != NULL)
		{
			msg->hdr.event_id = EVE_MSG_PRINTSTAT;
			msg->hdr.status = 0;
			cd_msg_send(TASK_STAT, msg);
		}

        return events ^ EVE_POLL;
    }
	else if(events & EVE_BROKER)
	{
//		static uint16_t times;
//		times++;
//		broker_send((cd_uint8_t *)&times,
//					sizeof(times),
//					print_node.release_name,
//					sizeof(print_node.release_name),
//					0);
		
		return events ^ EVE_BROKER;
	}

    return 0;
}

static cd_task_ops_t print_ops = {print_init, print_process};
static void print_task(void)
{
	cd_task_create(&print_ops, TASK_PRINT);
	LOG_I("TASK INITED");
}
INIT_APP_EXPORT(print_task);
