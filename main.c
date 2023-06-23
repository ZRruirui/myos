#include "tools/floppy.h"
#include "tools/fileinfo.h"
#include "stdio.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
char* ProjectPath(char* path){
    getcwd(path, 100);
    int index = 0;

    for (int i = 0;path[i] != 0;i++){
        if( path[i] == '/'){
            index = i;
        }
    }
    path[index] = 0;
    return path;
}

int main() {
    char* projectPath = malloc(sizeof( char) * 100);
    projectPath = ProjectPath(projectPath);
    char* sub_path = "/build/boot/boot.o";
    char *boot_filepath = malloc(strlen(projectPath)+strlen(sub_path)+1);
    strcpy(boot_filepath, projectPath);
    strcat(boot_filepath, sub_path);
    char* imageSubPath = "/a.img";
    char* imagePath = malloc(strlen(projectPath) + strlen(imageSubPath)+1);
    strcpy(imagePath, projectPath);
    strcat(imagePath, imageSubPath);
    Floppy* floppy = create_floppy();
    Fileinfo* boot_fileinfo = read_file(boot_filepath);
    write_bootloader(floppy, boot_fileinfo);
    create_image(imagePath, floppy);
    printf("%s\n%s\n",boot_filepath,imagePath);
    return 0;
}


