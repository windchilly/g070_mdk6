#include "stm32g030xx.h"

#include "board.h"

#include "shell_port.h"
#include "cm_backtrace.h"
#include "cdos.h"

#define HARDWARE_VERSION	"V1.0.0"
#define SOFTWARE_VERSION	"V0.1.0"
#define PROJ_NAME			"G070"

void show_version(void)
{
	cd_printf("---------------------------------------------");
	cd_printf("Software Version: %s", SOFTWARE_VERSION);
	cd_printf("Link Time: %s %s", __DATE__, __TIME__);
	cd_printf("All rights reserved by Damian Chu");
	cd_printf("---------------------------------------------");
}

static void board_init(void)
{
	bsp_init();
	
	LOG_I("BOARD INITED");
}
INIT_BOARD_EXPORT(board_init);

static void middleware_env_init(void)
{
	shell_init();
	cm_backtrace_init(PROJ_NAME, HARDWARE_VERSION, SOFTWARE_VERSION);

//	show_version();
	LOG_I("MIDDLEWARE INITED");
}
INIT_ENV_EXPORT(middleware_env_init);

void reboot(void)
{
    SCB->AIRCR = 0x05FA0004;
}
SHELL_EXPORT_CMD(SHELL_CMD_PERMISSION(0)|SHELL_CMD_TYPE(SHELL_TYPE_CMD_FUNC)|
SHELL_CMD_DISABLE_RETURN, reboot, reboot, system);
