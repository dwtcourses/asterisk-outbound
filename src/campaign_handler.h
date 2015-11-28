/*
 * campaign_handler.h
 *
 *  Created on: Nov 26, 2015
 *      Author: pchero
 */

#ifndef SRC_CAMPAIGN_HANDLER_H_
#define SRC_CAMPAIGN_HANDLER_H_

#include "asterisk.h"
#include "asterisk/json.h"

typedef enum _E_CAMP_STATUS_T
{
    // static status
    E_CAMP_STOP     = 0,
    E_CAMP_START    = 1,
    E_CAMP_PAUSE    = 2,

    // on going status
    E_CAMP_STOPPING = 10,
    E_CAMP_STARTING = 11,
    E_CAMP_PAUSING  = 12,

    // force status
    E_CAMP_STOPPING_FORCE = 30,
} E_CAMP_STATUS_T;

char* gen_uuid(void);

int create_campaign(struct ast_json* j_camp);
int update_campaign_info_status(const char* uuid, E_CAMP_STATUS_T status);
struct ast_json* get_campaign_info_all(void);
struct ast_json* get_campaign_info(const char* uuid);
struct ast_json* get_campaigns_info_by_status(E_CAMP_STATUS_T status);


#endif /* SRC_CAMPAIGN_HANDLER_H_ */