#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(){
	while(1){
		char s[100];
		char cs[100];
		int no_of_tokens = 0;

		//eventually make this print working directory (pwd)
		printf("prompt>");

		fgets(s,sizeof(s),stdin);
		s[strcspn(s,"\n")] = '\0';
		strcpy(cs,s);

		char* token;
		const char delims[] = " ";
		token = strtok(s,delims);

		if(strcmp(token,"exit")==0){
			break;
		}
		else if(strcmp(token,"cd")==0){
			token = strtok(NULL,delims);
			if(token==NULL){
				//have to make this to take us to home, for now this is fine
				token = "..";
			}
			int result = chdir(token);
			if(result==-1){
				//printf("%s\n",strerror(errno));
				perror("");
			}
		}
		else{
			while(token!=NULL){
				token = strtok(NULL,delims);
				no_of_tokens++;
			}

			int rc = fork();
			if(rc==0){
				char* argv[no_of_tokens+1];
				argv[0] = strtok(cs,delims);
				for(int i = 1;i<no_of_tokens;i++){
					argv[i] = strtok(NULL,delims);
				}
				argv[no_of_tokens] = NULL;
				int result = execvp(argv[0],argv);
				//doesnt matter that im putting an if statement here, because execvp only returns if its an error and thats equal to -1, but whatever i guess
				if(result==-1){
					printf("%s: command not found\n",argv[0]);
				}
				return result;
			}
			else if(rc==-1){
				return rc;
			}
			else{
				wait(NULL);
			}
		}
	}
}
