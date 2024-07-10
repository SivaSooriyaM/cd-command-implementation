#include <stdio.h>
#include <string.h>
#include <unistd.h>

void main(int argc,char **argv)
{	
	char past_dir[2000]="";
	char current_dir[2000];

	if(argc!=2)
	{
		printf("Usage:./mycd filepath\n");
		return;
	}
	
	getcwd(current_dir,sizeof(current_dir));
	
	if(*argv[1]=='-')
	{
		strcpy(past_dir,current_dir);
		if(strlen(past_dir)==0)
		{
			printf("No past directory path available\n");
			return;
		}
		else
		{
		   chdir(past_dir);//changing the working directory to previous directory
		   printf("%s\n",past_dir);
		   return;
		}

	}
	strcpy(past_dir,current_dir);
	strcpy(current_dir,argv[1]);
	if(chdir(argv[1])==0)//changing the working directory to given path
	{	
		printf("directory changed sucessfully\n");
	}
	FILE *fp=fopen("data","w");//for checking path changed,opened a file in that directory
	fprintf(fp,"%s\n",current_dir);//print current directory path in the file named data
	printf("%s\n",current_dir);
	return;

}
