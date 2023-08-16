#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav. \n");

        return 1;
    }

    char *input_name = argv[1];
    char *output_name = argv[2];
    int input_length = (strlen(input_name) -1);
    int output_length = (strlen(output_name) -1);
    bool input_is_wav = false;
    bool output_is_wav = false;

    if (input_name[input_length-3] == '.' && input_name[input_length-2] == 'w' && input_name[input_length-1] == 'a' && input_name[input_length] == 'v')
    {
        input_is_wav = true;
    }

    if (output_name[output_length-3] == '.' && output_name[output_length-2] == 'w' && output_name[output_length-1] == 'a' && output_name[output_length] == 'v')
    {
        output_is_wav = true;
    }

    if (!input_is_wav)
    {
        printf("Input is not a wav file. \n");

        return 1;
    }

    if (!output_is_wav)
    {
        printf("Output is not a wav file. \n");

        return 1;
    }

    FILE *input_file = fopen(input_name, "r");

    WAVHEADER file_header;
    fread(&file_header, sizeof(WAVHEADER), 1, input_file);

    if (check_format(file_header) == 0)
    {
        printf("Invalid WAV Format. \n");

        return 1;
    }

    FILE *output_file = fopen(output_name, "w");
    fwrite(&file_header, sizeof(WAVHEADER), 1, output_file);

    int block_size = get_block_size(file_header);
    BYTE buffer[block_size];

    fseek(input_file, 0, SEEK_END);

    long audio_size = ftell(input_file) - sizeof(WAVHEADER);
    int audio_block = round(audio_size / block_size);

    for (int i = (audio_block - 1); i >= 0; i--)
    {
        fseek(input_file, sizeof(WAVHEADER) + i * block_size, SEEK_SET);
        fread(buffer, block_size, 1, input_file);
        fwrite(buffer, block_size, 1, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}

int check_format(WAVHEADER header)
{
    BYTE check[] = {'W', 'A', 'V', 'E'};

    for (int check_character = 0; check_character < 4; check_character++)
    {
        if (header.format[check_character] != check[check_character])
        {
            return 0;
        }
    }

    return 1;
}

int get_block_size(WAVHEADER header)
{
    WORD byte_per_sample = header.bitsPerSample / 8;

    return (header.numChannels * byte_per_sample);
}
