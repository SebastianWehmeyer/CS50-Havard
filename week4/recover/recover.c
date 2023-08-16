#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Usage: ./recover IMAGE \n");

        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");

    if (raw_file==NULL)
    {
        printf("Could not open %s \n", argv[1]);

        return 1;
    }

    FILE *output_file = NULL;
    BYTE buffer[512];
    int count = 0;
    char filename[8];

    while (fread(buffer, 512, 1, raw_file) == 1)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count != 0)
            {
                fclose (output_file);
            }

            sprintf(filename, "%03i.jpg", count);
            output_file = fopen(filename, "w");
            count++;
        }

        if (count != 0)
        {
            fwrite(&buffer, 512, 1, output_file);
        }

    }

    if (output_file != NULL)
    {
        fclose(output_file);
    }

    fclose(raw_file);

    return 0;
}
