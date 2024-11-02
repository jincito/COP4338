//change lines 6-19 to update the following:
// 1. program name (mentioned in the Makefile), 
// 2. # of test-cases
// 3. stdin of each test-case
// 4. and command-line arguments of each test-case
static char DEFAULT_PROGRAM_NAME[] = "railcipher";
#define NUM_TEST_CASES 4
static char* TESTCASES[] = {"encrypt hello world!\nquit\n"//TC#0
								  ,"decrypt HWELLLORDO\nquit\n"//TC#1
								  ,"encrypt hello world!\ndecrypt HWELLLORDO\nquit\n"//TC#2
								  , "encrypt Attack postponed until two A.M.\ndecrypt TTNAAPTMTSUOAODWCOIXKNLYPETZ\nquit\n"//TC#3
								  };
static const char**  TEST_ARGS[] = {"4.5", "-1", "2", ""//TC#0
							  ,"5", "1", "3", "2", "5", "0", ""//TC#1
							  ,"28", "21", "22", "3", "4", "5", ""//TC#2
							  ,"7", "4", "3", "1", "2", "5", "6", "7", ""//TC#3
							 };	
// ------------------------------NO Change After this line ------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <sys/wait.h>
#include <dirent.h> 
#define MAX_STUDENTS 150
#define MAX_INPUT_SIZE 2000
#define MAX_PROGRAM_NAME_LEN 100
#define MAX_BUF 200
#define die(e) do { fprintf(stderr, "%s\n", e); exit(EXIT_FAILURE); } while (0);
typedef enum{
	LIST_FILES,
	UNZIP,
	CLEAN,
	MOSS,
	MAKE,
	RUN
}phase;
static char* CLA_ERROR_MESSAGE = "Fatal error. proper usage: ag [-xu] [-xm] [-xs] [-xc] [-s nn mm... or -s nn-mm] where nn, mm, etc are the submissions that you do not want to test";
char** submissions;
char** submissions_zipped;
int sub_count;
int test_case = 0;
static char *PROGRAM_NAME;
void update_name(char* dir);
void compile_h_c_files(char* dir_path);
int DONT_GRADE[MAX_STUDENTS];
char** get_args(char* file_name, int test_case);
char* str_args(char* file_name, int test_case);