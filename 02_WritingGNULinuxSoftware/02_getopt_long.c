#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <sysexits.h>
#include <unistd.h>


const char* program_name;


void print_help(FILE* stream, int exit_code)
{
    fprintf(stream, "Usage: %s options [inputfile ...]\n", program_name);
    fprintf(stream, 
            " -h --help             Display this help information.\n"
            " -o --output filename  Write the output to file.\n"
            " -v --verbose          Show verbose messages.\n");
    exit(exit_code);
}


int main(int argc, char* argv[])
{
    int next_option;

    const char* const short_options = "ho:v";

    const struct option long_options[] = {
        { "help",       0, NULL, 'h' },
        { "output",     1, NULL, 'o' },
        { "verbose",    0, NULL, 'v' },
        { NULL,         0, NULL, 0   }
    };

    const char* output_filename = NULL;

    int verbose = 0;

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

