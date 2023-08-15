#include "../inc/file_manager.h"

#include <dirent.h> 
#include <sys/types.h>
#include <stdio.h>

int count_number_of_file(const char  *DirectoryPath)
{

    int FileNumber = 0;

    DIR *directoryPtr;
    struct dirent *DirFileDataPtr;

    if (( directoryPtr = opendir( DirectoryPath ) ) == NULL )
    {
        puts("Directory not found.");
    }
    else
    {
        
        while((DirFileDataPtr = readdir(directoryPtr)) != NULL)
        {
            if(DirFileDataPtr->d_name[0] == '.') continue;
            FileNumber++;
        }  
        
    }

    return FileNumber;
}

