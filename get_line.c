#include "shell.h"

char *get_line(void)
{
        char *my_line = NULL;
        size_t my_len = 0;
        size_t store_line;

        write(STDOUT_FILENO, ">", 2);
        store_line = getline(&my_line, &my_len, stdin);

         if (my_line == NULL)
         {
                 perror("Error reading line.\n");
                 exit(1);
         }
        if(store_line == (size_t) -1 )
        {
        return (NULL);
        free(my_line);
        }

        return (my_line);



}
