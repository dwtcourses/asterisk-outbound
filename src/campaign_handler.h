/*
 * campaign_handler.h
 *
 *  Created on: Nov 26, 2015
 *	  Author: pchero
 */

#ifndef SRC_CAMPAIGN_HANDLER_H_
#define SRC_CAMPAIGN_HANDLER_H_

#include "asterisk.h"
#include "asterisk/json.h"

#include <stdbool.h>

typedef enum _E_CAMP_STATUS_T
{
	// static status
	E_CAMP_STOP	 = 0,
	E_CAMP_START	= 1,
	E_CAMP_PAUSE	= 2,
//	E_CAMP_SCHEDULE_STOP = 3,

	// on going status
	E_CAMP_STOPPING = 10,
	E_CAMP_STARTING = 11,
	E_CAMP_PAUSING  = 12,
//	E_CAMP_SCHEDULE_STOPPING  = 13,

	// force status
	E_CAMP_STOPPING_FORCE = 30,
} E_CAMP_STATUS_T;

typedef enum _E_CAMP_SCHEDULE_MODE
{
	E_CAMP_SCHEDULE_OFF = 0,
	E_CAMP_SCHEDULE_ON  = 1,
} E_CAMP_SCHEDULE_MODE;

bool create_campaign(const struct ast_json* j_camp);
bool delete_campaign(const char* uuid);
bool update_campaign(const struct ast_json* j_camp);
bool update_campaign_status(const char* uuid, E_CAMP_STATUS_T status);

struct ast_json* get_campaigns_all(void);
struct ast_json* get_campaigns_schedule_start(void);
struct ast_json* get_campaigns_schedule_end(void);
struct ast_json* get_campaign(const char* uuid);
struct ast_json* get_campaigns_by_status(E_CAMP_STATUS_T status);
struct ast_json* get_campaign_for_dialing(void);
struct ast_json* get_campaign_stat(const char* uuid);
struct ast_json* get_campaigns_stat_all(void);

bool is_stoppable_campgain(struct ast_json* j_camp);
bool is_startable_campgain(struct ast_json* j_camp);

#endif /* SRC_CAMPAIGN_HANDLER_H_ */
