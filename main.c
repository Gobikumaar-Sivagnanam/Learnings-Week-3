#include "read.h"

int main(){
    information info;
    information *arr = malloc(4*sizeof(information));

    FILE *fptr = NULL;

    char hold_data[200]={0};
    char *token;
    int i=0;

    error_t status = readfile("data.csv","r",&fptr);

    if(status == FILE_NOT_FOUND){
        printf("File is not available");
        exit(1);
    }
    else if(status == SUCCESS){
        while(read_lines(&fptr,hold_data)){
            if(feof(fptr))
                break;

            token = strtok(hold_data,",");
            store(&info.name,token);

            token=strtok(NULL,",");
            store(&info.email_id,token);

            token=strtok(NULL,",");
            store(&info.github_link,token);

            store(&arr[i].name,info.name);
            store(&arr[i].email_id,info.email_id);
            store(&arr[i].github_link,info.github_link);
            i++;
            free_the_structure(&info);
        }
        sorting(arr);
    }
    fclose(fptr);
    free(arr);
    return 0;
}