
#include "cli.h"

static void filter(char *data, t_routes *routes, char **splited)
{

	splited = ft_split(data, ':');
	for(int a = 0; splited[a] != NULL; a++)
	{
		if (strncmp(splited[a],"POST",4) == 0
		|| strncmp(splited[a],"GET",3) == 0
		|| strncmp(splited[a],"DELETE",6) == 0
		|| strncmp(splited[a],"PUT",3) == 0) {
			routes->method = splited[a];
			routes->status = splited[a - 1];
			routes->uri = splited[a + 1];
			routes->data = splited[a + 4];
			return ;
		}
	}
	routes->method = "Unknown";
	routes->status = "500";
	routes->uri = "ERROR";
	routes->data = "ERROR";
}

int main(int argc, char **argv)
{
	FILE *logs = fopen(FileLog, "r");
	char data[300];
	t_routes routes;
	char **splited = NULL;

	if (argc < 2)
	{
		printf("-------------------------------------------------------------------------------------------------\n|\t%-10s\t|\t%-10s\t|\t%-10s\t|\t%-10s\t|\n-------------------------------------------------------------------------------------------------\n","Mehod","HTTP uri","status", "data");
		while(!feof(logs)){
			fgets(data, 300, logs);
			filter(data, &routes, splited);
			memset(data, 0, 300);
			printf("|\t%-10s\t|\t%-10s\t|\t%-10s\t|\t%-10s\t|\n-------------------------------------------------------------------------------------------------\n", routes.method, routes.uri, routes.status , routes.data);
		}
	}
	return(0);
}