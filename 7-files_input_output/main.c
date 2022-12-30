#include <stdio.h>

int main(void){
    // Creates a file pointer
    FILE *fp;
    int value;
    // Initially was full path, but appears to work as relative path too
    fp = fopen("input.txt", "rb");
    // ALWAYS check to ensure that file exists before doing anything
    if (fp){
        while (1){
            value = fgetc(fp);
            // Check if you have reached the End Of File character
            if (value == EOF) {
                break;
            }
            else {
                printf("%c", value);
            }
        }
        // ALWAYS close file
        fclose(fp);
    }

    // Since we closed the value, we can reuse the pointer
    fp = fopen("output.txt", "wb");
    if (fp) {
        for (value = 48; value < 58; value++){
            fputc(value, fp);
        }
        fclose(fp);
    }
    // Can also use mode "ab" to append instead of overwrite rb+ reads and
    // writes and wb+ writes from new file and allows read.
    fp = fopen("better_output.txt", "wb");
    if (fp) {
        // For even better ways, you should explore, fread, fwrite, fscanf,
        // fputs, or fgets instead of fputc and fgetc.
        fprintf(fp, "A better way to add text to a file\n");
        fclose(fp);
    }
    fp = fopen("better_output.txt", "rb");
    if (fp) {
        // Move the file pointer to 10 bytes ahead of the current location
        // could also use SEEK_END (end of File), SEEK_SET (beginning)
        // Apply and int positive or negative to move relative to one of these
        // locations.
        fseek(fp, 10, SEEK_CUR);
        while(1){
            value = fgetc(fp);
            if (value == EOF) {
                break;
            } else {
                printf("%c", value);
            }
        }
        fclose(fp);
    }
    return 0;
}
