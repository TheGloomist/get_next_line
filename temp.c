#include <fcntl.h>
#include <string.h>
#include "get_next_line.h"


int main()
{
    int to_read;
    int write_to;
    char *line;

    to_read=open("cool.txt", O_RDONLY);
    write_to=open("also_cool.txt", O_CREAT|O_RDWR, 777);

    line = get_next_line(to_read);
    while (line != NULL)
    {
        write(write_to, "|", 1);
        write(write_to, line, strlen(line));
        
        line=get_next_line(to_read);

        write(write_to, "|", 1);
    }
}


// int main ()
// {
//     FILE    *read_from, *write_to;
//     char    buffer;
//     read_from = fopen("cool.txt", );
//     if (read_from == NULL)
//     {
//         printf("Failed to open the file to read from");
//         return (NULL);
//     }
//     write_to = fopen("also_cool.txt", "w");
//     if (write_to == NULL)
//     {
//         printf("Failed to open the file to write to");
//         return (NULL);
//     }
//     printf ("Done.");
//     fclose(read_from);
//     fclose(write_to);
//     return (0);
// }