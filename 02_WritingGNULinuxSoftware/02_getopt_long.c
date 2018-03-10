#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>
#include <unistd.h>

/**
 * Listing 2.2 (getopt_long.c) Using getopt_long
 */
 
const char* program_name;

/* 
 * Prints usage information for this program to STREAM (typically
 * stdout or stderr), and exit the program with EXIT_CODE. Does not return. 
 */
void print_help(FILE* stream, int exit_code)
{
    fprintf(stream, "Usage: %s options [inputfile ...]\n", program_name);
    fprintf(stream, 
            " -h --help             Display this help information.\n"
            " -o --output filename  Write the output to file.\n"
            " -v --verbose          Show verbose messages.\n");
    exit(exit_code);
}

/* 
 * Main program entry point. 
 * ARGC contains number of argument list elements; 
 * ARGV is an array of pointers to them. 
 */
int main(int argc, char* argv[])
{
    int next_option;

	/* A string listing valid short options letters */
    const char* const short_options = "ho:v";

	/* An array describing valid long options. */
    const struct option long_options[] = {
        { "help",       0, NULL, 'h' },
        { "output",     1, NULL, 'o' },
        { "verbose",    0, NULL, 'v' },
        { NULL,         0, NULL, 0   }
    };

	
	/* The name of the file to receive program output, 
	   or NULL for standard output. */
    const char* output_filename = NULL;

	/* Whether to display verbose messages. */
    int verbose = 0;

	/* Remember the name of the program, to incorporate in messages.
	   The name is stored in argv[0]. */
    program_name = argv[0];

	if (argc == 1) {
		fprintf(stderr, "No arguments!\n");
		exit(EX_USAGE);
	}
    
    do {
        next_option = getopt_long(argc, argv, short_options, long_options, NULL);
        switch(next_option) {
            case 'h':
                print_help(stdout, EX_OK);

            case 'o':
                output_filename = optarg;
                if(access(output_filename, F_OK) != -1 ) {
					// file exists
				} else {
					// file doesn't exist
				}
                break;

            case 'v':
                verbose = 1;
                break;

            case '?':
                print_help(stderr, EX_USAGE);

            case -1:
                break;

            default:
                abort();
        }
    } while(next_option != -1);

    if(verbose) {
        int i;
        for (i = optind; i < argc; i++) {
            printf("Argument: %s\n", argv[i]);
        }
    }

    return 0;
}

