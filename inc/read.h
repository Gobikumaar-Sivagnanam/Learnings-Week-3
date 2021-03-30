/**
 * @file read.h
 * @author Gobikumaar Sivagnanam    
 * @brief Headerfile for reading lines from a .csv file
 * @version 0.1
 * @date 2021-03-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#ifndef __READ_H__     ///Header Guard
#define __READ_H__     ///Header File Definition

/**
 * @brief Defining a enum to check the status of the file
 * @SUCCESS To show status as successful opening of the file
 * @FILE_NOT_FOUND To show the status of unsuccesful opening of the file
 */
typedef enum error_t{
    SUCCESS = 0,
    FILE_NOT_FOUND = -1
}error_t;

/**
 * @brief Structure to hold the values of name, email ID and github link
 * @name To hold the name
 * @email_id To hold the email ID
 * @github_link To hold the github link
 */
typedef struct information{
    char *name;
    char *email_id;
    char *github_link;
}information;

/**
 * @brief Function prototype to open the csv file with specified mode
 * 
 * @param [in] address To point to the file address 
 * @param [in] mode To specify the mode for opening the file
 * @param [in] ptr To point toline in a file
 * @return error_t To show the status of the file open
 */
error_t readfile(char* address,char* mode,FILE **ptr);

/**
 * @brief Function prototype to free the memory allocated for the structure
 * 
 * @param [in] ptr to point to the structure
 */
void free_the_structure(information *ptr);

/**
 * @brief Function prototype to read lines from a given .csv file
 * 
 * @param [in] ptr 
 * @param [in] data 
 * @return int To show the status of reading the lines 
 */
int read_lines(FILE **ptr, char *data);

/**
 * @brief Function prototype to allocate memory and store data 
 * 
 * @param [in] data The data to be stored
 * @param [in] token The delimiter for the string 
 */
void store(char **data, char *token);

/**
 * @brief To sort the names
 * 
 * @param ptr Pointer to the information structure
 * @return int 
 */
int sorting(information *ptr);

#endif  ///End of Definition
