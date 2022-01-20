#include<stdio.h>
#include<unistd.h>
#include<getopt.h>
#include<libintl.h>
#include<locale.h> 
#include<libgen.h>
#include<stdlib.h>
#include<string.h>

extern int optind,opterr,optopt;
extern char *optarg;
#define PACKAGE "neospg"
#define LOCALEDIR "/usr/share/locale/"
#define VERSION "0.2"
#define tr(STRING) gettext(STRING)

static struct option long_options[] = 
{
    {"help",no_argument,NULL,'h'},
    {"version",no_argument,NULL,'v'},
    {"number",required_argument,NULL,'n'},
    {"string",required_argument,NULL,'s'},
};

void print_help(char*);
void print_version(void);
void require_argument(char);
void generate(char*,int);
int main(int argc, char* argv[])
{

    setlocale (LC_ALL, ""); // Locale settings
    bindtextdomain (PACKAGE, LOCALEDIR);
    textdomain (PACKAGE);
    int index=0,got=0,returnint=0,number=3600;
    char* string="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$^&*()~[]{}'\";:,./<>?\\|";
    while(EOF != (got = getopt_long(argc,argv,"hn::s::v",long_options,&index)) )
    {
        switch(got)
        {
            case 'h':
                print_help(basename(argv[0]));
                returnint=2;
                break;
            case 'v':
                print_version();
                returnint=2;
                break;
            case 's':
                if(optarg == NULL)
                {
                    require_argument('s');
                    returnint=1;
                }
                else
                {
                    string=optarg;
                }
                break;
            case 'n':
                if(optarg == NULL)
                {
                    require_argument('n');
                    returnint=1;
                }
                else
                {
                    number=atoi(optarg);
                    if(number == 0){
                        require_argument('n');
                        returnint=1;
                    }
                }
                break;
            case '?':
                returnint=1;
                break;
            default:
                returnint=1;
        }
        if(returnint==2){break;}
    }
    if(returnint == 1)
    {
        return 1;
    }
    if(returnint == 2)
    {
        return 0;
    }
    generate(string, number);
    return 0;
    
}


void print_version(void)
{
    printf("neospg version %s, %s\n", VERSION, tr("Released under MIT license"));
    return;
}
void print_help(char* filename)
{
    printf("%s: %s [%s]\n", tr("Usage"), filename, tr("OPTIONS"));
    printf("  %s\n",tr("Print a strong password."));
    printf("%s:\n", tr("OPTIONS"));
    printf("    -h --%-10s %-10s %s\n", "help", " ", tr("Print this help"));
    printf("    -v --%-10s %-10s %s\n", "version", " ", tr("Print version information"));
    printf("    -n --%-10s %-10s %s\n", "number", tr("<integer>"), tr("The number of characters to be printed"));
    printf("    -s --%-10s %-10s %s\n\n", "string", tr("<string>"), tr("The character set which characters will be chosen from"));
    print_version();
    return;
}
void require_argument(char argu)
{
    fprintf(stderr, "%s: %c\n", tr("Option needs an argument"), argu);
    return;
}
void generate(char *genlist, int number)
{
    srand((unsigned)time(NULL)); //random seed
    size_t n = strlen(genlist);
    char genlist2[n+1];
    strncpy(genlist2, genlist, n + 1);
    for(int i=0; i<number; i++)
    {
        printf("%c", genlist2[rand()%n/*To limit the random number size*/]);
    }
    printf("\n");
    return;
}
