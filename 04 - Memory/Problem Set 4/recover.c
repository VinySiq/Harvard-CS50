// I don't like VSCode, so I use CodeBlocks with C and copy my code there and bring to here.
// This was, for me, a dificult code, so I had searched for solution on YouTube and i've made the code wathcing the video.
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <stdint.h>
#include <ctype.h>

typedef uint8_t byte;

bool isjpg(byte *block);

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        fprintf(stderr, "Usage: recover forensicfilename.raw\n");
        return 1;
    }


    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }

    FILE *JPG;

    byte block[512];

    bool foundjpg = false;
    int readblock;
    int jpgnum = 0;



    while (fread(block, sizeof(block), 1, inptr) == 1)
    {

        if (isjpg(block))
        {

            char filename[8];

            sprintf(filename, "%03.3i.jpg", jpgnum);

            printf("processing file: %s\n", filename);
            if (foundjpg == true)
            {
                fclose(JPG);
            }
            else
            {
                foundjpg = true;
            }

            JPG = fopen(filename, "w");
            fwrite(block, sizeof(block), 1, JPG);
            jpgnum++;
        }
        else
        {
            if (foundjpg == true)
            {
                fwrite(block, sizeof(block), 1, JPG);

            }
        }
    }



    fclose(inptr);
    fclose(JPG);




}
//PUTA QUE PARIU
bool isjpg(byte *block)
{
    if (block[0] == 0xff &&
        block[1] == 0xd8 &&
        block[2] == 0xff &&
        (block[3] & 0xf0) == 0xe0)
    {
        return true;
    }
    else
    {
        return false;
    }
}