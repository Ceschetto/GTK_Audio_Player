
struct FileNamesList
{
    char *FileName;
    struct FileNamesList *NextFileName;

};
typedef struct FileNamesList *FileNameNodePtr;
typedef struct FileNamesList FileNameNode;
int count_number_of_file(const char *DirectoryPath);
FileNameNodePtr enlist_files_name(const char *DirectoryPath);
void free_FNList(FileNameNodePtr currentNode);
void print_FNList(FileNameNodePtr currentNode);
FileNameNodePtr get_next_file_node(FileNameNodePtr currentFileNode);