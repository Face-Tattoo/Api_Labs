

#include "server.h"

void authenticationController(struct mg_http_message *hm, t_res *res)
{

	if(strncmp(hm->method.ptr, "POST", 4) == 0) {
		authenticationService(hm, res);
		if(res->status >= 400)
			MG_ERROR((":%s:%s:%d:Wrong Login.", strtok((char *)hm->method.ptr, " ") ,strtok((char *)hm->uri.ptr, " "),1));
		else
			MG_INFO((":%s:%s:%d:Login In!", strtok((char *)hm->method.ptr, " ") ,strtok((char *)hm->uri.ptr, " "),2));
	}
	else{
		res->status = 405;
		res->message = calloc(20,sizeof(char));
		sprintf(res->message, "\"Error\": \"Wrong method\"");
		MG_ERROR((":%s:%s:%d:not allowed methor!", "WRONG METHOD" ,"/authentication",1));
	}
}