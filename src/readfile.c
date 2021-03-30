#include "read.h"
/**
 * @brief The function definition to free the structure
 * 
 * @param [in] ptr is a pointer to point to the structure
 */
void free_the_structure(information *ptr){
    free(ptr->name);
    free(ptr->email_id);
    free(ptr->github_link);
}

/**
 * @brief The function definition to open a file and return status
 * 
 * @param [in] address is the character pointer to point to the file
 * @param [in] mode is the character pointer to show the file opening status
 * @param [in] ptr  is a file pointer to point to the .csv file
 * @return error_t 
 */
error_t readfile(char* address, char* mode, FILE **ptr){
    *ptr = fopen(address,mode);

    if(*ptr == NULL)
        return FILE_NOT_FOUND;

    else
        return SUCCESS;
}

/**
 * @brief Function definition to return a string from the file
 * 
 * @param [in] ptr Pointer to the file 
 * @param [in] data pointer to the data
 * @return int 
 */
int read_lines(FILE **ptr, char* data){
    return fscanf(*ptr,"%s",data);
}

/**
 * @brief Function definition to allocate memory and store the values in a data string 
 * 
 * @param [in] data the data to be stored    
 * @param [in] token the delimiter token
 */
void store(char **data, char *token){
    *data = (char *)malloc(strlen(token)+1);
    strcpy((*data),token);
}