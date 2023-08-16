typedef struct _FileNamesList *FileNameNodePtr;

int count_number_of_file(const char *DirectoryPath);
FileNameNodePtr enlist_files_name(const char *DirectoryPath);
void free_FNList(FileNameNodePtr currentNode);
void print_FNList(FileNameNodePtr currentNode);
