#include "read.h"

int compare(const void *ptr,const void *qtr){
    
    return strcmp(((information*)ptr)->name,((information*)qtr)->name);
}

int sorting(information *ptr){
    if(ptr==NULL)
        return 0;
    qsort(ptr, 4, sizeof(information),compare);
    for(int i=0;i<4;i++){
        printf("%s\n",(ptr+i)->name);
        printf("%s\n",(ptr+i)->email_id);
        printf("%s\n",(ptr+i)->github_link);
        printf("\n");
        free_the_structure((ptr+i));
    }
    return 1;  
}