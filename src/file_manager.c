#include "../inc/file_manager.h"

#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>






FileNameNodePtr init_new_node(const char * file_name);



int count_number_of_file(const char *DirectoryPath)
{

    int FileNumber = 0;

    DIR *directoryPtr;
    struct dirent *DirFileDataPtr;

    if ((directoryPtr = opendir(DirectoryPath)) == NULL)
    {
        puts("Directory not found.");
    }
    else
    {

        while ((DirFileDataPtr = readdir(directoryPtr)) != NULL)
        {
            if (DirFileDataPtr->d_name[0] == '.')
                continue;
            FileNumber++;
        }
    }

    return FileNumber;
}



FileNameNodePtr enlist_files_name(const char *DirectoryPath)
{
    DIR *directoryPtr;
    struct dirent *DirFileDataPtr;

    FileNameNodePtr FNListHeader = NULL;

    if ((directoryPtr = opendir(DirectoryPath)) == NULL)
    {
        puts("Directory not found.");
    }
    else
    {

        while ((DirFileDataPtr = readdir(directoryPtr)) != NULL)
        {
            if (DirFileDataPtr->d_name[0] == '.') continue;  // schippiamo i file nascosti

            FileNameNodePtr NewNodePtr = init_new_node(DirFileDataPtr->d_name);

            if(FNListHeader == NULL)
            {
                FNListHeader = NewNodePtr;
            }
            else
            {
                NewNodePtr->NextFileName = FNListHeader;
                FNListHeader = NewNodePtr;
            }
        }
    }
    return FNListHeader;
}



FileNameNodePtr init_new_node(const char * fileName)
{
    FileNameNodePtr NewNode = NULL;
    if( ( NewNode = (FileNameNodePtr) calloc( 1, sizeof(FileNameNode) ) ) == NULL )
    {
        puts("Errore Critico Memoria non allocabile");
        exit(1);
    }
    else
    {
        NewNode->FileName = (char *) calloc(1, strlen(fileName) * sizeof(char));
        memcpy(NewNode->FileName, fileName, strlen(fileName) * sizeof(char));

        NewNode->NextFileName = NULL;
    }
    return NewNode;
}

void free_FNList(FileNameNodePtr currentNode)
{
    FileNameNodePtr trashPtr = NULL;
    while(currentNode != NULL)
    {
        trashPtr = currentNode;
        currentNode = currentNode->NextFileName;
        free(trashPtr);
    }

}

void print_FNList(FileNameNodePtr currentNode)
{
    while(currentNode != NULL)
    {
        puts( currentNode->FileName );
        currentNode = currentNode->NextFileName;
    

    }

}




FileNameNodePtr get_next_file_node(FileNameNodePtr currentFileNode)
{
    return currentFileNode->NextFileName;
}
