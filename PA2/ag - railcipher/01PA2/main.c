#include "railcipher.h"
int key[MAX_LEN];
int m;//key length
static int is_legal_key(){
	char* seen = (char*) calloc(m+1, 1);
	for(int i = 0; i < m;i++){
		if(key[i] < 1 || key[i] > m)
			return FALSE;
		if(!seen[key[i]])
			seen[key[i]] = TRUE;
		else//duplicate
			return FALSE;
	}
	return TRUE;	
}
static int handle_args(int argc, char* argv[]){
	m = argc - 2;//length of key
	if( m < 2 || m > MAX_LEN){//invalid key length
		printf("Fatal error: too few or too many arguments!\n");
		return INVALID_KEY_LENGTH;//error code for invalid key
	}
	if(atoi(argv[1]) != m){//user did not enter the right CLA combination!
		printf("Fatal error: invalid key length!\n");
		return INVALID_KEY_LENGTH;//error code for invalid key
	}
	for(int i = 0; i < m;i++)
		key[i] = atoi(argv[2 + i]);
	if(!is_legal_key()){//user did not enter the right CLA combination!
		printf("Fatal error: invalid key sequence!\n");
		return INVALID_KEY_SEQ;//error code for invalid key sequence
	}
	return NO_ERROR;
}
int main(int argc, char* argv[]){
	//argv[1]: key length (m) 2-26
	//argv[2:m+1]: key vector: permutaion from 1 to m
	//argv[m+2]: NULL
	//argc: 2 + m where m is the length of key
	int error_code;
	if(error_code = handle_args(argc, argv))
		return error_code;
	//printf("Key is ");
	//for(int i = 0; i < m;i++)
	//	printf("%d ", key[i]);
	//printf("\n");
	//fflush(stdout);
	char command[MAX_COMMAND_LEN];
	while(fgets(command, MAX_COMMAND_LEN, stdin)){
		int len = strlen(command);
		if(command[len-1] == '\n'){
			command[len-1] = '\0';
			len--;
		}
		if(!strcasecmp(command, "quit"))
			break;
		if(!strncmp(command, "encrypt ", 8))
			encrypt(command + 8);
		else if(!strncmp(command, "decrypt ", 8))
			decrypt(command + 8);
		else
			printf("invalid command! try again!\n");
	}
	return NO_ERROR;
}
