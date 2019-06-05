#pragma comment(exestr, "Copyright 1986, 1987, 1988 W. A. Jackson")
#pragma comment(compiler)
#pragma comment(exestr, "Compiled on "__DATE__ "at " __TIME__)
#pragma skip(10)
/*

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
VIDEOCAT

Version 6.0

Source Code

Copyright 1986, 1987, 1988 W. A. Jackson

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
#pragma skip(20)
/*
Requires Microsoft C Version 5.10 or later running under OS/2
Recommended command line options:

cl /Lp /AL /Fb /F F00 videocat.c
*/
#pragma title(__FILE__)
#pragma subtitle("Compiled on " __DATE__ " at " __TIME__)
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv header vvvv*/
/*-----------------------------------------------------------------------------
Header for source file begins here.

(If the program is divided into smaller files for more convenient editing or
more efficient compiler optimizaton, each source file should include the
same header code.)

-----------------------------------------------------------------------------*/

/*------------------------------------------ Compiler-Related Directives ----*/


#define INCL_BASE 1 /* causes all OS/2 base definitions to be included */
#define LINT_ARGS 1 /* causes argument checking for library functions
in Microsoft C; has no effect under other
compilers */

/*---------------------------------------------------------------------------*/

/*-------------------------------------------------------- Include Files ----*/
/*
Include files contain macro and constant definitions, type
definitions, and function declarations:

stdio.h for stream I/O
ctype.h for character classification
dos.h for MS-DOS interface functions
fcntl.h for low-level flag definitions
io.h for low-level I/O
string.h for string manipulation functions
direct.h for directory control functions
malloc.h for memory allocation functions
memory.h for buffer manipulation routines
os2.h top level include file for OS/2 applications
stdlib.h for miscellaneous utilities
sys\stat.h for status information functions
sys\types.h for system-level calls
time.h for time routines

The #include directive causes the contents of an "include" file to be added
to the source file during preprocessing.

*/

#include
#include
#include
#include
#include
#include
#include
#include
#include
#include
#include
#include
#include
#include



/*---------------------------------------------------------------------------*/
#pragma subtitle("Manifest Constants")
#pragma page()

/*--------------------------------------------------- Manifest Constants ----*/

/*
The #define directive is used here to associate meaningful identifiers
to constants frequently used in statements or expressions.
*/

/* Constants */


#define BIGBUFF 0x1000
#define BLANK_LINE " \
"
#define BLACK 0x0
#define BLUE 0x1
#define BROWN 0x6
#define CGACURSNORM 0x0607
#define CODENUMBER 42
#define CURSOFF 0x2000
#define CYAN 0x3
#ifndef FALSE
#define FALSE 00
#endif
#define FIDLENGTH 14
#define FORMLENGTH 16
#define FORMNUMBER 24
#define GREEN 0x2
#define INPUTLENGTH 80
#define LBLACK 0x8
#define LBLUE 0x9
#define LCYAN 0xB
#define LGREEN 0xA
#define LMAGENTA 0xD
#define LOCLENGTH 05
#define LRED 0xC
#define LWHITE 0xF
#define MAGENTA 0x5
#define MAXRECORDS 9999
#define MONOCURSNORM 0x0C0D
#define MPAANUMBER 6
#define NAMELENGTH 31
#define PHRASELENGTH 16
#define RATINGNUMBER 8
#define RED 0x4
#define SUBJLENGTH 16
#define SUBJNUMBER 42
#define TITLELENGTH 41
#ifndef TRUE
#define TRUE 01
#endif
#define WHITE 0x7
#define YEARLENGTH 05
#define YELLOW 0xE

/*---------------------------------------------------------------------------*/

#pragma subtitle("Type Declarations")
#pragma page()

/*---------------------------------------------------- Type Declarations ----*/

/*
The typedef declarations used here establish names for complex
user-defined structure data types used throughout the program.
*/

/* Types */


typedef struct LABELNODE {

char title [TITLELENGTH];
char loc1 [LOCLENGTH];
char loc2 [LOCLENGTH];
SEL sel;
struct LABELNODE *lnode;
struct LABELNODE *rnode;
};

typedef struct LABELDATA {
char *loc1 [LOCLENGTH];
int *line_count;
int *label_count;
};

typedef struct MOVIERECORD {
char title [TITLELENGTH];
char year [YEARLENGTH];
char star1 [NAMELENGTH];
char star2 [NAMELENGTH];
char star3 [NAMELENGTH];
char director [NAMELENGTH];
char subject;
char form;
char rating;
char loc1 [LOCLENGTH];
char loc2 [LOCLENGTH];
char mpaa_code;
};

typedef struct MOVIETRANS {
char transaction;
struct MOVIERECORD moviedata;
SEL sel;
struct MOVIETRANS *ltransnode;
struct MOVIETRANS *rtransnode;
};

typedef struct NAMERECORD {
char name [NAMELENGTH];
int count;
SEL sel;
struct NAMERECORD FAR *last_name_rec;
struct NAMERECORD FAR *next_name_rec;
};

typedef struct YEARRECORD {
char year [YEARLENGTH];
int count;
SEL sel;
struct YEARRECORD FAR *last_year_rec;
struct YEARRECORD FAR *next_year_rec;
};

/*---------------------------------------------------------------------------*/

#pragma subtitle("Argument-type lists")
#pragma page()

/*-------------------------------------------------- argument-type lists ----*/

/*
An argument-type-list establishes the number and types of the
arguments to a function and causes the compiler to perform
type checking between the formal parameters and actual arguments
of a function each time it is used and to generate a warning in
case of inconsistency.
*/
extern void main(void );
extern void change_paths(void );
extern int check_paths(char *base_file_id,char *work_file_id);
extern void clear_screen(int foreground,int background);
extern void cur_size(int size);
extern void disp_rec(USHORT row,struct MOVIERECORD *rec_ptr);
extern void display(USHORT row, struct MOVIETRANS *trans_ptr);
extern void draw_box(char box_type,USHORT left_column,USHORT right_column,
USHORT top_row,USHORT bottom_row);
extern void editLdata(char *data_string,int width);
extern void editRdata(char *data_string,int width);
extern void file_convert(char *base_file_id,char *work_file_id);
extern void file_con_menu(void );
extern void file_con_get_id(char *old_base_file_id);
extern int get_change(struct MOVIETRANS *trans1_ptr,
struct MOVIETRANS *trans2_ptr,char *base_file_id);
extern int get_data(struct MOVIETRANS *trans_ptr);
extern int get_delete(struct MOVIETRANS *trans1_ptr,
struct MOVIETRANS *trans2_ptr,char *base_file_id);
extern void get_form(char *form_ptr);
extern void get_loc(char *loc_ptr,char *loc_for);
extern void get_mpaa_code(char *mpaa_ptr);
extern void get_name(char *name_ptr,char *name_for);
extern void get_rating(char *rate_ptr);
extern void get_subject(char *subj_ptr);
extern void get_title(char *title_ptr);
extern void get_year(char *year_ptr);
extern int has_color(void );
extern int in_order(struct _iobuf *workf_ptr,struct _iobuf *basef_ptr,
struct MOVIETRANS *tree_ptr,struct MOVIETRANS *base_buff,int count);
extern void lbl_hp_box(struct _iobuf *print_pointer,int start_row,
int start_column);
extern void lbl_hp_courier(struct _iobuf *print_pointer);
extern void lbl_hp_line_printer(struct _iobuf *print_pointer);
extern struct LABELDATA *lbl_hp_print(struct LABELNODE *lbltree_node,
struct _iobuf *print_pointer,
int run_number);
extern void lbl_hp_reset(struct _iobuf *print_pointer);
extern void lbl_hp_set_cursor(struct _iobuf *print_pointer,int row,int column);
extern int lbl_loc_comp(struct LABELNODE *loc_node1,
struct LABELNODE *loc_node2);
extern void lbl_make_labels(char *base_file_id);
extern struct LABELDATA *lbl_print(struct LABELNODE *lbltree_node,
struct _iobuf *print_pointer,
int run_number);
extern struct LABELNODE *lbl_search(char *base_file_id,char *min_loc,
char *max_loc);
extern struct LABELNODE *lbl_tree_insert(struct LABELNODE *lbltree_root,
struct LABELNODE *new_node);
extern void main_menu(void );
extern void name_out(char *name_ptr);
extern char outopt(void );
extern char pause(void );
extern void print_rec(struct MOVIERECORD *rec_ptr,
struct _iobuf *print_pointer);
extern char prnopt(void );
extern char qpause(void );
extern int rec_comp(struct MOVIERECORD *rec1,struct MOVIERECORD *rec2);
extern void search(char *base_file_id);
extern char search_key(struct MOVIERECORD *s_key_record);
extern void set_border(int color);
extern void set_cursor(int row,int column,int page);
extern void tally(char *base_file_id);
extern void tally_display (struct NAMERECORD far *dir_name_list,
struct NAMERECORD far *star_name_list,
struct YEARRECORD far *year_list,
char *form_codes, int *form_counts,
char *rating_codes, int *rating_counts,
char *subj_codes, int *subj_counts,
int total_movies);
extern struct NAMERECORD far *tally_list_name(char *new_name,
struct NAMERECORD far *name_list);
extern struct YEARRECORD far *tally_list_year(char *new_year,
struct YEARRECORD far *year_list);
extern void tally_sort(int sort_number,char *sort_codes,int *sort_counts);
extern int trans_comp(struct MOVIETRANS *trans1,struct MOVIETRANS *trans2);
extern int tree_display(struct MOVIETRANS *tree_ptr,int count);
extern struct MOVIETRANS *tree_insert(struct MOVIETRANS *tree_root,
struct MOVIETRANS *new_trans);
extern void trim(char *string_ptr);
extern struct MOVIETRANS *update(struct MOVIETRANS *root,char *base_file_id,
char *work_file_id,struct MOVIETRANS *trans_buff);
extern int verify(void );
extern void welcome(void );
extern void whole_cat(char *base_file_id);
extern void window(int left_column,int right_column,int top_row,
int bottom_row,int foreground,int background);

/*---------------------------------------------------------------------------*/

/*----------------------------------------- External Variable References ----*/

/*
External reference declarations make a variable visible which is
either declared later in the same source file or which is known to
the linker as having been declared in another source file.
*/

/* external reference to global variables */


extern char *subjects[];
extern char *forms[];
extern char *ratings[];
extern char codes[];

/*---------------------------------------------------------------------------*/

/*-----------------------------------------------------------------------------
Header for source file ends here.
-----------------------------------------------------------------------------*/
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ header ^^^^*/

#pragma subtitle("global declarations")
#pragma page()


/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv globals vvvv*/

/*--------------------------------- External Level Variable Declarations ----*/

/*
Variables declared at the external level, i.e. outside a function, are
global, i.e. visible in all functions, throughout the remainder of the
source file and can be made visible earlier in the same source file or
in other source files through external reference declarations.
*/
/* global variable declarations */



char *subjects[] = {

"Action ",
"Adult ",
"Animated ",
"Biographical ",
"Caper ",
"Contemporary ",
"Courtroom ",
"Crime ",
"Dance ",
"Detective ",
"Disaster ",
"Family ",
"Futuristic ",
"Gangster ",
"Historical ",
"Horror ",
"International ",
"Journalism ",
"Military ",
"Medical ",
"Murder ",
"Musical ",
"Period ",
"Police ",
"Political ",
"Prison ",
"Psychological ",
"Religious ",
"Rock ",
"Romantic ",
"Science ",
"Science-Fiction",
"Sex ",
"Social ",
"Sports ",
"Supernatural ",
"Suspense ",
"Terror ",
"War ",
"Western ",
"Youth ",
"Miscellaneous "
};

char *forms[] = {
"Adventure ",
"Classic ",
"Comedy ",
"Comedy-drama ",
"Compilation ",
"Concert ",
"Documentary ",
"Docu-drama ",
"Drama ",
"Epic ",
"Fantasy ",
"Farce ",
"Intrigue ",
"Melodrama ",
"Mystery ",
"One-man-show ",
"Opera ",
"Revue ",
"Romance ",
"Satire ",
"Spoof ",
"Story ",
"Thriller ",
"Variety "
};

char *ratings[] = {
"**** Excellent",
"***+ Very Good",
"*** Good",
"**+ Pretty Good",
"** Fair",
"*+ Poor",
"* Bad",
"+ Abysmal"
};

char *mpaa_codes[] = {
"MPAA G Rated",
"MPAA PG Rated",
"MPAA PG13 Rated",
"MPAA R Rated",
"MPAA X Rated",
"MPAA Not Rated",
};


char codes[CODENUMBER] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
'U', 'V', 'W', 'X', 'Y', 'Z', '1', '2', '3', '4',
'5', '6', '7', '8', '9', '0', '#', '$', '%', '&',
'!', '*'};


/*---------------------------------------------------------------------------*/

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ globals ^^^^*/

#pragma subtitle("main()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv main vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| #include |
| #include |
| #include |
| #include |
| #include |
| #include |
| #include |
| #include |
| #include |
| #include |
| |
| void main(void) |
| |
| FUNCTION |
| ~~~~~~~~ |
| C defines main() as the entry point of the program. Main() in this |
| program is the main control module. It performs certain initialization |
| activities and then calls other principal modules in a while loop which |
| cycles until the user requests exit. At the beginning of each loop |
| the main command menu is displayed and the user is prompted to enter |
| a code for the function desired. Switch selection then calls the |
| appropriate routines according to the code entered by the user. |
| |
| RETURNS |
| ~~~~~~~ |
| |
| Nothing. |
| |
| |
| NOTES |
| ~~~~~ |
| Calls all other functions in the program, many of which use non- |
| standard C extensions. |
| |
| |
+----------------------------------------------------------------------------*/
void main ()

{
char base_file_id [INPUTLENGTH];/*path & name of base file*/
char command = '\0'; /* current user command */
extern void change_paths(); /* func changes file paths */
extern int check_paths(); /* func asks user to verify paths */
extern void clear_screen(); /* func to clear screen & set colors */
extern void cur_size(); /* func sets cursor size */
extern void file_convert (); /* func converts data file format */
extern int get_change(); /* gets data for change transaction */
extern int get_data(); /* func gets data for transaction */
extern int get_delete(); /* gets data for delete transaction */
extern int has_color(); /* func tests for color display */
extern void lbl_make_labels(); /* func makes labels */
char input_command [INPUTLENGTH]; /* user input buffer */
extern void main_menu(); /* func displays main menu */
extern char pause(); /* func to pause for user */
struct MOVIETRANS *root = NULL; /* root of transaction binary tree */
extern void search(); /* func searches base file */
extern void set_border(); /* func to set display border color */
extern void set_cursor(); /* func positions cursor */
extern void tally(); /* func tallys statistics */
extern int tree_display(); /* func displays transactions in tree*/
struct MOVIETRANS *tree_insert(); /* func to insert trans in tree */
extern void trim(); /* func trims lead & trail whitespace*/
struct MOVIETRANS *trans1_buff = NULL; /* transaction work area */
struct MOVIETRANS *trans2_buff = NULL; /* transaction work area */
struct MOVIETRANS *trans1_temp = NULL; /* transaction work area */
struct MOVIETRANS *trans2_temp = NULL; /* transaction work area */
extern struct MOVIETRANS *update(); /* func updates base file */
extern void welcome(); /* func for welecome user routine */
extern void whole_cat(); /* func prints catalog */
char work_file_id [INPUTLENGTH];/*path & name of work file*/

/* start-up routines */
/* allocate memory to buffers */
trans1_buff = (struct MOVIETRANS *)calloc (1, sizeof (struct MOVIETRANS));
trans2_buff = (struct MOVIETRANS *)calloc (1, sizeof (struct MOVIETRANS));
set_border (BLACK); /* set border color */
welcome(); /* call func to welcome user */
while (!(check_paths(base_file_id, work_file_id))) /* verify file paths & */
change_paths (); /* change if not verified */


/* main processing loop */

while (command != 'E') /* loop until exit command - */
{
main_menu(); /* display main menu */
gets (input_command); /* get user input */
trim (input_command); /* trim whitespace from user input */
command = input_command [0]; /* 1st char is command */
command = toupper (command); /* make sure command is upper case */

switch (command) /* select action according to user command */
{
case 'A' : /* if add code - */

trans1_buff = (struct MOVIETRANS *)memset /* zero out buffer */
((char *)trans1_buff, '\0', sizeof(struct MOVIETRANS));
trans1_buff->transaction = command; /* set transaction code */
if (get_data (trans1_buff)) /* call func to get data from user */
{ /* if successful */
root = tree_insert (root, trans1_buff); /* insert trans in tree */
} /* advise user */
break; /* exit from switch selection */

case 'C' : /* if change command */
/* clear buffers */
trans1_buff = (struct MOVIETRANS *)memset
((char *)trans1_buff, '\0', sizeof(struct MOVIETRANS));
trans2_buff = (struct MOVIETRANS *)memset
((char *)trans2_buff, '\0', sizeof (struct MOVIETRANS));
trans1_buff->transaction = command; /* set transaction code */
trans1_temp = trans1_buff; /* use temp variables to pass pointers */
trans2_temp = trans2_buff; /* (avoids bug in get_change()) */
if (get_change (trans1_temp, trans2_temp, base_file_id))
{ /* call func to get change data from user - if successful - */
root = tree_insert (root, trans1_buff); /* insert trans in tree */
root = tree_insert (root, trans2_buff); /* (del old,add changed) */
} /* advise user */
break; /* exit from switch selection */

case 'D' : /* if delete code */
/* clear buffers */
trans1_buff = (struct MOVIETRANS *)memset
((char *)trans1_buff, '\0', sizeof(struct MOVIETRANS));
trans2_buff = (struct MOVIETRANS *)memset
((char *)trans2_buff, '\0', sizeof (struct MOVIETRANS));
trans1_buff->transaction = command; /* set transaction code */
if (get_delete (trans1_buff, trans2_buff, base_file_id))
{ /* get record to be deleted - if found */
root = tree_insert (root, trans2_buff); /* insert trans in tree */
} /* advise user */
break;

case 'F' : /* file conversion command */

file_convert ( base_file_id, work_file_id); /* call func */
break;


case 'L' : /* label maker code */
/* clear screen & set colors */
clear_screen (LWHITE, BLUE); /* call func to make labels */
lbl_make_labels(base_file_id);
break;

case 'R' : /* for review transactions code */


tree_display (root, 0); /* call func to display current transactions */
VioSetCurPos (22,0,0);
printf ("End of current changes. "); /* advise user */
pause(); /* wait for user */
break; /* exit switch selection */

case 'S' : /* for search code */

search (base_file_id); /* call func to conduct search */
break; /* exit from switch selection */

case 'T' : /* for tally statistics command */

clear_screen (LWHITE, BLACK); /* clear screen & set display colors */
set_cursor (11,11,0); /* position cursor */
printf ("COMPILING STATISTICS ..."); /* advise user */
tally (base_file_id); /* call func to tally statistics */
clear_screen (LWHITE, BLUE); /* clear screen & set display colors */
break; /* exit switch selection */

case 'U' : /* for update command code */

root = update (root, base_file_id, work_file_id, trans1_buff);
break;

case 'W' : /* for print catalog command */

whole_cat(base_file_id); /* call func to print catalog */
break; /* exit switch selection */

case 'E' : /* for exit code */

set_border (BLACK);
clear_screen (WHITE,BLACK);
break; /* exit from switch selection */

default : /* if no switch selected, code must be invalid */

printf ("\nINVALID CODE\n"); /* warn user */
pause(); /* wait for user */
break; /* exit switch selection */
}
}
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ main() ^^^^*/

#pragma subtitle("change_paths()")
#pragma page()


/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv change_paths vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| void change_paths(void) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Changes paths of base file and work file both in the strings |
| passed by the calling routine and in the configuration file. |
| |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Calls clear_screen(), pause() and trim() functions. |
| |
| |
| |
| |
| |
+----------------------------------------------------------------------------*/

void change_paths ()

{
USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
char base_path[INPUTLENGTH]; /* base path string */
FILE *cfg_file_ptr; /* ptr to configuration file */
extern void clear_screen(); /* func to clear screen */
HVIO hvio = 0; /* video handle */
extern void set_border(); /* func sets display border color */
extern void trim(); /* func trims lead & trail whitesp */
char work_path[INPUTLENGTH]; /* work path string */

char_buff = (char *)calloc (1, 0x100);
clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,20,LWHITE,BLUE);
window (6,78,9,14,BLACK,BLACK);
window (4,76,8,13,BLACK,WHITE);
set_border (BLUE); /* set screen border color */
VioSetCurPos (22,0,hvio); /* position cursor */
/* get changes from user */

cfg_file_ptr = fopen ("VIDEOCAT.CFG", "w"); /* open config file for write*/
if (cfg_file_ptr == NULL)
{
printf (" Error in attempting to open new configuration file.\n");
pause();
VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioSetCurPos (22,0,hvio);
}
sprintf(char_buff,
" The permanent data base file must be on a hard or floppy disk path. ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,9,6,hvio);
sprintf(char_buff,
" The temporary data file may be on a hard, floppy or RAM disk (VDISK) ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,10,6,hvio);
sprintf(char_buff,
" path. Putting the temporary data file on RAM disk will improve speed ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,11,6,hvio);
sprintf(char_buff,
" but may make it unavilable as a backup to the permanent data file. ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,12,6,hvio);

printf
(" Enter path for permanent data base file (must be a floppy or\n");
printf
(" hard disk path) -> ");
gets (base_path); /* get base path from console*/
trim (base_path); /* trim whitespace */
strupr (base_path);
while (base_path[strlen(base_path) -1] == '\\')/* strip trailing backslash */
base_path [strlen(base_path) -1] = '\0';
if ((fputs(base_path, cfg_file_ptr)) == EOF) /* write base path to config */
{
printf (" Error in writing to configuration file.\n");
pause();
VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioSetCurPos (22,0,hvio);
}
if ((fputs("\n", cfg_file_ptr)) == EOF) /* - write newline to file */
{
printf (" Error in writing to configuration file.\n");
pause();
VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioSetCurPos (22,0,hvio);
}
VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioWrtNChar(" ",80,24,0,hvio);
VioSetCurPos(22,0,hvio);
printf /* prompt user for work path */
(" Enter path for temporary data file (may be \n");
printf
(" RAM, floppy or hard path) -> ");
gets (work_path); /* read user response */
trim (work_path); /* trim whitespace */
strupr (work_path);
VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioWrtNChar(" ",80,24,0,hvio);
VioSetCurPos(22,0,hvio);
while (work_path[strlen(work_path) -1] == '\\')/* strip trailing backslash */
work_path [strlen(work_path) -1] = '\0';
if ((fputs(work_path, cfg_file_ptr)) == EOF) /* write work path to config */
{
printf (" Error in writing to configuration file.\n");
pause();
VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioSetCurPos (22,0,hvio);
}
VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioWrtNChar(" ",80,24,0,hvio);
VioSetCurPos(22,0,hvio);
if ((fputs("\n", cfg_file_ptr)) == EOF) /* - write newline to file */
{
printf (" Error in writing to configuration file.\n");
pause();
VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioSetCurPos (22,0,hvio);
}
fclose (cfg_file_ptr); /* close config file */
set_border (BLACK);
free (char_buff);
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ change_paths ^^^^*/

#pragma subtitle("check_paths()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv check_paths vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| #include |
| int check_paths(char *base_file_id, char *work_file_id); |
| |
| FUNCTION |
| ~~~~~~~~ |
| Checks DOS paths for the files base_file_id and work_file_id. |
| Reads initial settings from configuration file; if not present |
| it creates a configuration file using the path of the current |
| directory. Displays the paths and asks the user if changes are |
| desired; if so the function change_paths() is called. After any |
| path changes have been made, it checks for the presence of the |
| base and work files and attempts to create them if not found. If |
| the files cannot be found or made, the user is prompted for further |
| path changes. |
| |
| |
| RETURNS |
| ~~~~~~~ |
| 1 if successfully completed; 0 if paths invalid. |
| |
| NOTES |
| ~~~~~ |
| Uses getcwd(), an MSC extension which may not be portable accross |
| compilers and operating systems. |
| |
+----------------------------------------------------------------------------*/


int check_paths(base_file_id, work_file_id)

char *base_file_id; /* ptr to base file id */
char *work_file_id; /* ptr to work file id */

{
USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
char base_path [INPUTLENGTH]; /* path to base file */
FILE *basef_ptr; /* pointer to base file */
char *cdir_ptr; /* pointer to current directory */
extern void clear_screen(); /* func to clear screen */
FILE *cfg_file_ptr; /* ptr to config file */
HVIO hvio = 0; /* video handle */
extern char pause(); /* func pauses for user */
char response [INPUTLENGTH]; /* user response */
extern void set_border(); /* func sets display border color */
extern void trim(); /* func trims whitespace */
FILE *workf_ptr; /* work file pointer */
char work_path [INPUTLENGTH]; /* path for work file */


/* open configuration file for read */
/* if not found, create it using current path */


char_buff = (char *) calloc (1, 0x100);
clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,20,LWHITE,BLUE);
window (6,78,9,14,BLACK,BLACK);
window (4,76,8,13,BLACK,WHITE);
set_border (BLUE); /* set screen border color */
VioSetCurPos (22,0,hvio); /* position cursor */




cfg_file_ptr = fopen ("VIDEOCAT.CFG", "r"); /* attempt open for read */
if (cfg_file_ptr == NULL) /* if unsuccessful - */
{
sprintf (char_buff,"Configuration file not found; creating new one.");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,11,9,hvio);
VioSetCurPos (22,0,hvio);
pause(); /* pause for user */
cfg_file_ptr = fopen ("VIDEOCAT.CFG", "w"); /* - open for write */
if (cfg_file_ptr == NULL)
{
printf (" Error in attempting to open new configuration file.\n");
pause();
VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioSetCurPos (22,0,hvio);
}
cdir_ptr = getcwd(NULL,80);
while (cdir_ptr[strlen(cdir_ptr) -1] == '\\')/* strip trailing backslash */
cdir_ptr [strlen(cdir_ptr) -1] = '\0';
if ((fputs(cdir_ptr, cfg_file_ptr)) == EOF) /* - write to file */
{
printf (" Error in writing to configuration file.\n");
pause();
VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioSetCurPos (22,0,hvio);
}
if ((fputs("\n", cfg_file_ptr)) == EOF) /* - write newline to file */
{
printf (" Error in writing to configuration file.\n");
pause();
VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioSetCurPos (22,0,hvio);
}
if ((fputs(cdir_ptr, cfg_file_ptr)) == EOF) /* - write cur. path again */
{
printf (" Error in writing to configuration file.\n");
pause();
VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioSetCurPos (22,0,hvio);
}
if ((fputs("\n", cfg_file_ptr)) == EOF) /* - write another newline */
{
printf (" Error in writing to configuration file.\n");
pause();
VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioSetCurPos (22,0,hvio);
}
fclose (cfg_file_ptr); /* - close config file */
free ((char *)cdir_ptr); /* - free pointer */
VioWrtNChar(" ",80,11,0,hvio);
}
/* read paths for base & work files from config file */

cfg_file_ptr = fopen ("VIDEOCAT.CFG", "r"); /* - open config for read */
fgets (base_path, INPUTLENGTH, cfg_file_ptr); /* read path for base file */
trim (base_path); /* trim whitespace (\n) */
fgets (work_path, INPUTLENGTH, cfg_file_ptr); /* read path for work file */
trim (work_path); /* trim whitespace (\n) */
fclose (cfg_file_ptr); /* close config file */

/* advise user of current paths */

sprintf(char_buff," Current Disk Drive Configuration");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,9,15,hvio);
sprintf(char_buff,"Permanent data base file is on path %s", base_path);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,11,9,hvio);
sprintf(char_buff,"Temporary work files will be on path %s", work_path);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,12,9,hvio);

/* find out if user wants to change paths */

VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioWrtNChar(" ",80,24,0,hvio);
VioSetCurPos(22,0,hvio);
printf /* prompt user */
(" Do you wish to change the current path configuration? (Y/N) -> ");
gets (response); /* get user response */
trim (response); /* trim whitespace from response */
if ((response[0] == 'Y') || (response[0] == 'y')) /* if Y or y - */
{
fcloseall(); /* close all files */
return 0; /* return 0 */
}
/* attempt to open base file */
/* attempt to create if it does not exist */
/* warn user if unsuccessful */

strcpy (base_file_id, base_path); /* copy path */
strcat (base_file_id, "\\BASEFIL5.DAT"); /* append file id */
basef_ptr = fopen (base_file_id, "r"); /* open for read */
VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioWrtNChar(" ",80,24,0,hvio);
VioSetCurPos(22,0,hvio);
if (basef_ptr == NULL) /* if open error */
{ /* - advise user */
printf (" Base file not found; creating new one.\n");
pause();
basef_ptr = fopen (base_file_id, "w"); /* - attempt to create new file */
if (basef_ptr == NULL) /* - if unsuccessful - */
{
printf (" Error in opening new base file.\n");
pause();
fcloseall(); /* close all files */
return 0; /* return 0 */
}
}
fclose (basef_ptr);

/* attempt to open work file */
/* attempt to create if it does not exist */
/* warn user if unsuccessful */

VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioWrtNChar(" ",80,24,0,hvio);
VioSetCurPos(22,0,hvio);
strcpy (work_file_id, work_path); /* copy path */
strcat (work_file_id, "\\WORKFILE.DAT"); /* append file id */
workf_ptr = fopen (work_file_id, "r"); /* attempt to open existing file */
if (workf_ptr == NULL) /* if open error - */
{ /* - warn user */
printf (" Work file not found; creating new one.\n");
pause();
workf_ptr = fopen (work_file_id, "w"); /* - attempt to open new file */
if (workf_ptr == NULL) /* - if open error */
{
printf (" Error in opening new work file.\n"); /* warn user */
pause();
fcloseall(); /* close all files */
return 0; /* return 0 */
}
}
fclose (workf_ptr);

cfg_file_ptr = fopen ("VIDEOCAT.CFG", "r"); /* - open config for read */
basef_ptr = fopen (base_file_id, "r"); /* open for read */
workf_ptr = fopen (work_file_id, "r"); /* attempt to open existing file */
if ((cfg_file_ptr != NULL)
&& (basef_ptr != NULL)
&& (workf_ptr != NULL))
{
fclose (cfg_file_ptr);
fclose (basef_ptr);
fclose (workf_ptr);
return 1;
}
else
{
fclose (cfg_file_ptr);
fclose (basef_ptr);
fclose (workf_ptr);
return 0;
}
free (char_buff);

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ check_paths ^^^^*/

#pragma subtitle("clear_screen()")
#pragma page()


/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv clear_screen vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| void clear_screen (int foreground, int background) |
| |
| |
| FUNCTION |
| ~~~~~~~~ |
| Clears screen, sets specified video attributes (foreground and |
| background colors for blank lines) and homes cursor. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Uses VioScrollDn and VioSetCurPos, MSC extensions which may not be |
| portable accross operating systems and compilers. |

| |
| |
+----------------------------------------------------------------------------*/

void clear_screen (foreground, background)

int foreground, background;

{

int attribute; /* video color attribute */
USHORT usTopRow = 0; /* top row */
USHORT usLeftCol = 0; /* left column */
USHORT usBotRow = 24; /* bottom row */
USHORT usRightCol = 79; /* right column */
USHORT cbLines = 25; /* number of blank lines */
BYTE bCell[2]; /* cell to write */
HVIO hvio = 0; /* video handle */

VioSetCurPos (usTopRow, usLeftCol,hvio); /* home cursor */


/* set space character and color attribute byte for blank lines */

bCell[0] = 0x20; /* space character */

if (has_color()) /* attribute */
attribute = (0x10 * background) + foreground;
else attribute = 0x7;

bCell[1] = (BYTE)attribute; /* character attribute cell */

/* clear screen and set colors */

VioScrollDn (usTopRow, usLeftCol, usBotRow, usRightCol, cbLines,
bCell, hvio);


}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ clear_screen ^^^^*/

#pragma subtitle("cur_size()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv cur_size vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| void cur_size (int size) |
| |
| FUNCTION |
| ~~~~~~~~ |
| This version sets the cursor either off or to normal size. In future |
| versions it may also make other changes. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| This function uses VioGetCurType and VioSetCurType, MSC extensions |
| which may not be portable accross compilers and operating systems. |
| |
| |
+----------------------------------------------------------------------------*/

void cur_size (size) /* set cursor size */

int size; /* size code */

{

VIOCURSORINFO viociCursor;
HVIO hvio = 0;

VioGetCurType (&viociCursor, hvio);

if (size == CURSOFF)
viociCursor.attr = 0xFFFF;
else
viociCursor.attr = 0;

VioSetCurType (&viociCursor, hvio);


}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ cur_size ^^^^*/

#pragma subtitle("disp_rec()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv disp_rec vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| disp_rec (struct MOVIERECORD *rec_ptr) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Displays the data contained in the record pointed to by rec_ptr |
| on the video display. |
| |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Uses a number of functions defined in videocat.c. All use only |
| ANSI standard functions and should be portable. |
| |
| |
| |
| |
+----------------------------------------------------------------------------*/

void disp_rec (row, rec_ptr)

USHORT row; /* screen row */
struct MOVIERECORD *rec_ptr; /* ptr to a record */


{
USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
int count; /* counter */
HVIO hvio = 0; /* video handle */
extern void name_out(); /* func converts name format */
extern void trim(); /* func trims lead & trail whitesp */
char star1_disp [INPUTLENGTH]; /*-----------------------*/
char star2_disp [INPUTLENGTH]; /* buffers in which the */
char star3_disp [INPUTLENGTH]; /* various elements in */
char dir_disp [INPUTLENGTH]; /* a MOVIETRANS struct */
char subj_disp [INPUTLENGTH]; /* are converted from */
char form_disp [INPUTLENGTH]; /* record format to a */
char type_disp [INPUTLENGTH]; /* display format. */
char rating_disp[INPUTLENGTH]; /*-----------------------*/
char mpaa_disp [INPUTLENGTH];


char_buff = (char *) calloc (1, 0x100);
strcpy (star1_disp, rec_ptr->star1); /* get star1 name */
name_out (star1_disp); /* and convert for display */

strcpy (star2_disp, rec_ptr->star2); /* get star2 name */
name_out (star2_disp); /* and convert for display */

strcpy (star3_disp, rec_ptr->star3); /* get star3 name */
name_out (star3_disp); /* and convert for display */

strcpy (dir_disp, rec_ptr->director); /* get director name */
name_out (dir_disp); /* and convert for display */
while (strlen (dir_disp) < 24) /* pad director display name */
strcat (dir_disp, " "); /* with trailing blanks */

for (count = 0; count < CODENUMBER; count++) /* look up subject code */
if (rec_ptr->subject == codes [count]) /* if found, copy */
strcpy (subj_disp, subjects [count]); /* subject */
trim (subj_disp); /* trim subject */

for (count = 0; count < FORMNUMBER; count++) /* look up form code */
if (rec_ptr->form == codes [count]) /* if found, copy */
strcpy (form_disp, forms [count]); /* corresponding form */
trim (form_disp); /* trim form */

strcpy (type_disp, subj_disp); /* copy subject to type buffer */
strcat (type_disp, " "); /* append 1 blank space to type */
strcat (type_disp, form_disp); /* append form to type buffer */
while (strlen (type_disp) < 26) /* pad type bufer with trailing */
strcat (type_disp, " "); /* blanks to width 26 */

strcpy (mpaa_disp, " "); /* initialize mpaa as blank */
for (count = 0; count < MPAANUMBER; count++) /* look up mpaa code */
if (rec_ptr->mpaa_code == codes [count]) /* if found, copy */
strcpy (mpaa_disp, mpaa_codes [count]); /* mpaa */
trim (mpaa_disp); /* trim mpaa */
while (strlen (mpaa_disp) < 20) /* pad type bufer with trailing */
strcat (mpaa_disp, " "); /* blanks to width 20 */


for (count = 0; count < RATINGNUMBER; count++) /* look up rating */
if (rec_ptr->rating == codes [count]) /* if found copy */
strcpy (rating_disp, ratings [count]); /* corresponding rating */
trim (rating_disp);

/* print data in display format */

sprintf (char_buff, BLANK_LINE);
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,row,8,hvio); /* write to screen */
sprintf (char_buff,"%s [%s]",
rec_ptr->title, rec_ptr->year);
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,row,8,hvio); /* write to screen */

sprintf (char_buff,"%s", BLANK_LINE);
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,(row + 1),8,hvio); /* write to screen */
sprintf (char_buff,"%s%s%s", type_disp, mpaa_disp, rating_disp);
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,(row + 1),8,hvio); /* write to screen */

sprintf (char_buff,"%s", BLANK_LINE);
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,(row + 2),8,hvio); /* write to screen */
sprintf (char_buff,"Starring: %s, %s, %s", star1_disp, star2_disp,
star3_disp);
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,(row + 2),8,hvio); /* write to screen */

sprintf (char_buff,"%s", BLANK_LINE);
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,(row + 3),8,hvio); /* write to screen */
sprintf (char_buff,"Director: %s Cassette: %s Index: %s",
dir_disp, rec_ptr->loc1, rec_ptr->loc2);
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,(row + 3),8,hvio); /* write to screen */

free (char_buff);
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ disp_rec ^^^^*/

#pragma subtitle("display()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv display vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| display (struct MOVIETRANS *trans_ptr) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Displays a transaction, indicating type (add, change or delete) |
| and displaying the content of the record. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| NOTES |
| ~~~~~ |
| |
| Uses VioGetCurPos and VioWrtCharStr, MSC extensions which may not |
| be portable accross compilers and operating systems. |
| |
| |
+----------------------------------------------------------------------------*/

void display (row, trans_ptr) /* displays content of a record */

USHORT row; /* row for start of display */
struct MOVIETRANS *trans_ptr; /* pointer to a transaction */

{
char *buffer; /* storage buffer for output */
USHORT cbString; /* length of string in bytes */
extern void disp_rec(); /* function to display content of record */
HVIO hvio = 0; /* video handle */
struct MOVIERECORD *rec_ptr; /* pointer to record structure */
USHORT usColumn; /* starting position (column) */
USHORT usRow; /* starting position (row) */

buffer = (char *) calloc (1, 0x100);
printf ("\n"); /* advance cursor to next line */

switch (trans_ptr->transaction) /* print transaction description to buffer */
{ /* selected by trans_ptr->transaction */
case 'A': sprintf (buffer, "ADD");
break;
case 'C': sprintf (buffer, "CHANGE");
break;
case 'D': sprintf (buffer, "DELETE");
break;
}

VioGetCurPos (&usRow, &usColumn, hvio); /* get cursor position */
cbString = (USHORT)strlen (buffer); /* get length of string */
VioWrtCharStr (buffer, cbString, row, 0, hvio); /* write to screen */

rec_ptr = &trans_ptr->moviedata; /* get pointer to record */
disp_rec ((row + 1), rec_ptr); /* call function to display record */
free (buffer);
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ display ^^^^*/

#pragma subtitle("draw_box()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv draw_box vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| |
| int draw_box (char box_type, int left_column, int right_column, |
| int top_row, int bottom_row); |
| FUNCTION |
| ~~~~~~~~ |
| Draws double-line bordered box bounded by left_column, right_column, |
| top_row and bottom_row. If box_type is 'p', draws a plain box; |
| otherwise draws a box with a label section at the top. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Uses VioWrtNChar, a MSC extesntion which may not be portable accross |
| operating systems and compilers. |
| |
| |
| |
+----------------------------------------------------------------------------*/

void draw_box (box_type, left_column, right_column, top_row, bottom_row)

char box_type; /* code for box design type */
USHORT left_column; /* left column of box */
USHORT right_column; /* right column of box */
USHORT top_row; /* top row of box */
USHORT bottom_row; /* bottom row of box */

{

USHORT count; /* counter */
HVIO hvio = 0; /* video handle */
USHORT cb = 1; /* number of times to write character */

VioWrtNChar ("\xC9",cb,top_row,left_column,hvio); /* upper left corner */

for (count = (left_column + 1); count < right_column; count++)
{ /* top border */
VioWrtNChar ("\xCD",cb,top_row,count,hvio); /* print horizontal dbl line */
}

VioWrtNChar ("\xBB",cb,top_row,right_column,hvio); /* upper right corner */

for (count = (top_row + 1); count < bottom_row; count++)
{ /* print left border */
VioWrtNChar ("\xBA",cb,count,left_column,hvio); /* left vertical */
}

for (count = (top_row + 1); count < bottom_row; count++)
{ /* print right border */
VioWrtNChar ("\xBA",cb,count,right_column,hvio); /* right vertical */
}

VioWrtNChar ("\xC8",cb,bottom_row,left_column,hvio); /* lower left corner */

for (count = (left_column + 1); count < right_column; count++)
{ /* print bottom border */
VioWrtNChar ("\xCD",cb,bottom_row,count,hvio); /* bottom border */
}

VioWrtNChar ("\xBC",cb,bottom_row,right_column,hvio);/* lower right corner */

if ((box_type == 'p') || (box_type == 'P')) /* if plain box, exit */
return;

VioWrtNChar ("\xC7",cb,(top_row + 4),left_column,hvio); /* left connector */

for (count = (left_column + 1); count < right_column; count++)
{ /* print single horizonal line accross 5th row of box */
VioWrtNChar ("\xC4",cb,(top_row + 4),count,hvio); /* horizontal line */
}

VioWrtNChar ("\xB6",cb,(top_row + 4),right_column,hvio);/* right connector */
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ draw_box ^^^^*/

#pragma subtitle("editLdata()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv editLdata vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| void editLdata (char *data_string, int width) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Edits data at data_string pointer to all upper case and to specified |
| width, padding with trailing spaces if necessary. Left justifies. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| |
| Uses ANSI standard functions only; should be portable. Uses |
| string functions declared in string.h. |
| |
| |
| |
+----------------------------------------------------------------------------*/

void editLdata (data_string, width) /* func to edit data to record format */

char *data_string; /* ptr to data to be edited */
int width; /* edit field width */

{
int char_limit; /* max string length (non_null chars) */
extern void trim(); /* func trims leading & trailing whitespace */

char_limit = width - 1; /* determine max string length */

/* delete leading and trailing white space */

trim (data_string);

/* convert all characters to upper case */

strupr (data_string);

/* truncate to correct length */

if (strlen (data_string) > (char_limit)) /* if data too long - */
data_string [char_limit] = '\0'; /* - terminate at field width */

/* pad with trailing blanks to correct length */

while (strlen (data_string) < (char_limit)) /* while data not long enough */
strcat (data_string, " "); /* - append blanks */

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ editLdata ^^^^*/

#pragma subtitle("editRdata()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv editRdata vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| void editRdata (char *data_string, int width) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Edits data at data_string pointer to all upper case and to specified |
| width, padding with leading spaces if necessary. Right justifies. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| |
| Uses ANSI standard functions only; should be portable. Uses |
| string functions declared in string.h. |
| |
| |
| |
+----------------------------------------------------------------------------*/

void editRdata (data_string, width) /* func to edit data to record format */

char *data_string; /* ptr to data to be edited */
int width; /* edit field width */

{
int char_limit; /* max string length (non_null chars) */
char temp[255]; /* difference */
extern void trim(); /* func trims leading & trailing whitespace */

char_limit = width - 1; /* determine max string length */

/* delete leading and trailing white space */

trim (data_string);

/* convert all characters to upper case */

strupr (data_string);

/* truncate to correct length */

if (strlen (data_string) > (char_limit)) /* if data too long - */
data_string [char_limit] = '\0'; /* - terminate at field width */

/* pad with leading blanks to correct length */


while (strlen (data_string) < (char_limit)) /* while data not long enough */
{
strcpy (temp, data_string); /* copy data to temp */
strcpy (data_string, " "); /* replace data with one blank */
strcat (data_string, temp); /* concatenate temp to data */
}
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ editRdata ^^^^*/

#pragma subtitle("file_convert()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv file_convert vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| void file_convert ( char *base_file_id, char *work_file_id) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Converts a data base file created under version 4.x to the format |
| utilized in version 5.x. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| NOTES |
| ~~~~~ |
| Calls functions which utilize non-standard MSC extensions. |
| May not be portable accross compilers and operating systems. |
| This function is necessary because earlier versions were compiled |
| on a Computer Innovations compiler which does not align records on |
| word boundries and thus constructed a MOVIERECORD to fill one byte less |
| than the Microsoft compiler, which allocated an extra byte to align |
| the end of a record with a word boundry. The definition of MOVIERECORD |
| has now been changed so both compilers use the same number of bytes. |
| |
+----------------------------------------------------------------------------*/


void file_convert ( base_file_id, work_file_id)

char *base_file_id; /* pointer to name of base file */
char *work_file_id; /* pointer to name of work file */

{

FILE *basef_ptr; /* base file stream */
char *buf1;
char *buf2;
USHORT cbString; /* string byte count */
char *char_buff; /* character buffer */
extern void clear_screen(); /* func clears screen & sets colors */
int count; /* counter for records processed */
extern void cur_size(); /* func sets cursor size */
extern void editLdata(); /* func edits data left justified */
extern void editRdata(); /* func edits data right justified */
extern void file_con_get_id(); /* func gets old base file id */
extern void file_con_menu(); /* func to display menu */
extern int has_color(); /* func checks for color display */
int new_size; /* new size of data record */
HVIO hvio = 0; /* video handle */
char old_base_file_id[255]; /* old data file id */
FILE *old_basef_ptr; /* base file stream */
int old_size; /* old size of data record */
struct MOVIERECORD *rec_buff; /* buffer to hold 1 record */
char response [INPUTLENGTH]; /* user response */
extern void set_cursor(); /* func sets cursor position */
FILE *workf_ptr; /* work file stream */

char_buff = (char *) calloc (1, 0x100);
file_con_menu(); /* call func to display menu */
sprintf (char_buff,"Do you wish to continue with file conversion (Y/N -> ");
cbString = (USHORT)strlen(char_buff); /* get string byte count */
VioWrtCharStr (char_buff,cbString,21,5,hvio); /* write user prompt */
VioSetCurPos (21,(5 + cbString),hvio); /* position cursor */
gets (response); /* get user response */
trim (response); /* trim whitespace from response */
if ((response[0] == 'N') || (response[0] == 'n')) /* if N or n - */
return; /* abort */
/* find old base file */

file_con_get_id(old_base_file_id); /* call func to get old base file id */
if (old_base_file_id[0] == '\0') /* if no id returned */
return; /* abort */

/* set up screen and open files */

count = 0;
new_size = sizeof(struct MOVIERECORD);
old_size = new_size - 1;
clear_screen (LRED, BLACK); /* clear screen & set display colors */
sprintf (char_buff, "CONVERTING - READING OLD BASE FILE..");/* advise user */
cbString = (USHORT)strlen(char_buff); /* get string byte count */
VioWrtCharStr (char_buff,cbString,11,11,hvio); /* write message */
VioSetCurPos (11, (11 + cbString), hvio); /* set cursor position */
rec_buff = (struct MOVIERECORD *)calloc (1, sizeof (struct MOVIERECORD));
rec_buff = (struct MOVIERECORD *)memset /* clear buffer */
((char *)rec_buff, '\0', sizeof(struct MOVIERECORD));
buf1 = calloc (1, BIGBUFF);
buf2 = calloc (2, BIGBUFF);
workf_ptr = fopen (work_file_id, "wb"); /* open work file */
setvbuf (workf_ptr, buf1, _IOFBF, BIGBUFF); /* use big buffer for file i/o */
if (workf_ptr == NULL) /* if file not successfully opened - */
{
printf ("\n Error in opening work file.\n"); /* - warn user */
pause(); /* - wait for user */
fcloseall(); /* - close all files */
return;
}
old_basef_ptr = fopen (old_base_file_id, "rb"); /* open base file */
setvbuf (old_basef_ptr, buf2, _IOFBF, BIGBUFF); /* use big buffer for i/o */
if (old_basef_ptr == NULL) /* if file not successfully opened - */
{
printf ("\n Error in opening OLD base file.\n"); /* - warn user */
pause(); /* - wait for user */
fcloseall(); /* - close all files */
return;
}

/* process update from base file and transactions */
/* to work file */

VioSetCurPos (23,0,hvio); /* set cursor position */

while (!(feof (old_basef_ptr))) /* while not at end of work file - */
{
if ((fread ((char *)rec_buff, old_size,
1, old_basef_ptr)) != 1) /* read a record */
{ /* if read error - */
if (feof(old_basef_ptr)) /* - if EOF break loop */
break; /* and continue (normal condition) */
else
{ /* - if other read error - */
printf ("\nError in reading old base file.\n"); /* warn user */
pause(); /* wait for user */
fcloseall(); /* close all files */
return;
}
}
editLdata (rec_buff->title, TITLELENGTH); /* edit fields to */
editLdata (rec_buff->year, YEARLENGTH); /* current standards */
editLdata (rec_buff->star1, NAMELENGTH);
editLdata (rec_buff->star2, NAMELENGTH);
editLdata (rec_buff->star3, NAMELENGTH);
editLdata (rec_buff->director, NAMELENGTH);
editRdata (rec_buff->loc1, LOCLENGTH);
editRdata (rec_buff->loc2, LOCLENGTH);
if ((fwrite ((char *)rec_buff, new_size,
1, workf_ptr)) != 1) /* write record to base file */
{ /* if write error - */
printf ("\nError in writing work file.\n"); /* warn user */
pause(); /* wait for user */
fcloseall(); /* close all files */
return;
}
else /* if record successfully transferred from work to base file - */
{
sprintf (char_buff, "%4d ", count++); /* write count to buffer */
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr (char_buff,cbString,11,50,hvio); /* write to screen */
}
}
if (fclose (workf_ptr)) /* close workfile */
{ /* if close error - */
printf ("\nError in closing work file.\n"); /* warn user */
pause(); /* wait for user */
fcloseall(); /* close all files */
return;
}
if (fclose (old_basef_ptr)) /* close base file */
{ /* if close error - */
printf ("\nError in closing old base file.\n"); /* warn user */
pause(); /* wait for user */
fcloseall(); /* close all files */
return;
}

clear_screen (LGREEN, BLACK); /* clear screen & set display colors */
sprintf (char_buff, "CONVERTING - WRITING NEW BASE FILE..");/* advise user */
cbString = (USHORT)strlen(char_buff); /* get string byte count */
VioWrtCharStr (char_buff,cbString,11,11,hvio); /* write message */
VioSetCurPos (23, 0, hvio); /* set cursor position */
workf_ptr = fopen (work_file_id, "rb"); /* open work file */
setvbuf (workf_ptr, buf1, _IOFBF, BIGBUFF); /* use big buffer for file i/o */
if (workf_ptr == NULL) /* if file not successfully opened - */
{
printf ("\n Error in opening work file.\n"); /* - warn user */
pause(); /* - wait for user */
fcloseall(); /* - close all files */
return;
}
basef_ptr = fopen (base_file_id, "wb"); /* open base file */
setvbuf (basef_ptr, buf2, _IOFBF, BIGBUFF); /* use big buffer for file i/o */
if (basef_ptr == NULL) /* if file not successfully opened - */
{
printf ("\n Error in opening base file.\n"); /* - warn user */
pause(); /* - wait for user */
fcloseall(); /* - close all files */
return;
}


while (!(feof (workf_ptr))) /* while not at end of work file - */
{
if ((fread ((char *)rec_buff, new_size,
1, workf_ptr)) != 1) /* read a record */
{ /* if read error - */
if (feof(workf_ptr)) /* - if EOF break loop */
break; /* and continue (normal condition) */
else
{ /* - if other read error - */
printf ("\nError in reading work file.\n"); /* warn user */
pause(); /* wait for user */
fcloseall(); /* close all files */
}
}
if ((fwrite ((char *)rec_buff, new_size,
1, basef_ptr)) != 1) /* write record to base file */
{ /* if write error - */
printf ("\nError in writing base file.\n"); /* warn user */
pause(); /* wait for user */
fcloseall(); /* close all files */
}
else /* if record successfully transferred from work to base file - */
{
sprintf (char_buff, "%4d ", count--); /* write count to buffer */
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr (char_buff,cbString,11,50,hvio); /* write to screen */
}
}
free ((char *)(rec_buff)); /* free memory allocated to buffer */
free (buf1);
free (buf2);
free (char_buff);
if (fclose (workf_ptr)) /* close workfile */
{ /* if close error - */
printf ("\nError in closing work file.\n"); /* warn user */
pause(); /* wait for user */
fcloseall(); /* close all files */
return;
}
if (fclose (basef_ptr)) /* close base file */
{ /* if close error - */
printf ("\nError in closing base file.\n"); /* warn user */
pause(); /* wait for user */
fcloseall(); /* close all files */
return;
}
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ file_convert ^^^^*/

#pragma subtitle("file_con_menu()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv file_con_menu vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| void file_con_menu() |
| |
| FUNCTION |
| ~~~~~~~~ |
| Displays a menu with an explanation of the file conversion function |
| and user choices. |
| |
| |
| RETURNS |
| ~~~~~~~ |
| |
| Nothing. |
| |
| |
| NOTES |
| ~~~~~ |
| Calls functions which use nonstandard C extensions and may not be |
| portable accross operating systems and compilers. |
| |
| |
| |
| |
+----------------------------------------------------------------------------*/

void file_con_menu()

{
USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
extern void clear_screen(); /* func clears screen & sets colors */
HVIO hvio = 0; /* video handle */
extern void draw_box(); /* func draws box on display */
extern void set_cursor(); /* func sets cursor position */
extern void window(); /* func opens display window */

char_buff = (char *) calloc (1, 0x100);
clear_screen (LWHITE, BLACK); /* clear screen & set colors */
window (10,70,3,18,BLACK,RED); /* open window */
draw_box ('l',11,69,3,18); /* draw box in window */
set_cursor (5,33,0); /* position cursor */
sprintf (char_buff, "FILE CONVERSION"); /* write to buff */
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,5,33,hvio); /* write to screen */
sprintf (char_buff, "This function converts a file created under");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,8,15,hvio); /* write to screen */
sprintf (char_buff, "Version 4.x series versions of this program to");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,9,15,hvio); /* write to screen */
sprintf (char_buff, "a new data file in a format compatible with the");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,10,15,hvio); /* write to screen */
sprintf (char_buff, "Versions 5.x-6.x Series. You will be asked to ");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,11,15,hvio); /* write to screen */
sprintf (char_buff, "enter the path of the old base file (BASEFILE.DAT).");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,12,15,hvio); /* write to screen */
sprintf (char_buff, "The new file (BASEFIL5.DAT) will be created on ");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,13,15,hvio); /* write to screen */
sprintf (char_buff, "the path you previously identified for the ");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,14,15,hvio); /* write to screen */
sprintf (char_buff, "current base file. This procedure is unnecessary");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,15,15,hvio); /* write to screen */
sprintf (char_buff, "if you do not have a file created under Ver. 4.x.");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,16,15,hvio); /* write to screen */

free (char_buff);

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ file_con_menu ^^^^*/

#pragma subtitle("file_con_get_id()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv file_con_get_id vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| #include |
| char *file_con_get_id(); |
| |
| FUNCTION |
| ~~~~~~~~ |
| Gets complete file id for old base file by asking user for path |
| and checking for presence of old base file. |
| |
| RETURNS |
| ~~~~~~~ |
| Pointer to file_id string if successfull; NULL if not successful. |
| |
| NOTES |
| ~~~~~ |
| Uses getcwd(), an MSC extension wihc may not be portable. |
| |
+----------------------------------------------------------------------------*/


void file_con_get_id(old_base_file_id) /* get file id for old base file */

char *old_base_file_id; /* complete file id string */


{

USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
extern void clear_screen(); /* func clears screen & sets colors */
extern void draw_box(); /* func draws box on display */
HVIO hvio = 0; /* video handle */
char old_base_path [INPUTLENGTH]; /* path to old_base file */
FILE *old_basef_ptr; /* pointer to old_base file */
char *cdir_ptr; /* pointer to current directory */
extern char pause(); /* func pauses for user */
char response [INPUTLENGTH]; /* user response */
extern void set_border(); /* func sets display border color */
extern void set_cursor(); /* func sets cursor position */
extern void trim(); /* func trims whitespace */
extern void window(); /* func opens display window */


char_buff = (char *) calloc (1, 0x100);
clear_screen (LWHITE,BLACK); /* clear screen & set display colors */
VioSetCurPos(23,1,hvio);
cdir_ptr = getcwd(NULL,80);

strcpy (old_base_path, cdir_ptr); /* copy current path to old base path */
free ((char *)cdir_ptr); /* - free pointer */
trim (old_base_path); /* trim whitespace (\n) */
/* strip trailing backslash */
while (old_base_path[strlen(old_base_path) -1] == '\\')
old_base_path [strlen(old_base_path) -1] = '\0';

/* advise user of current path */

sprintf (char_buff,"Current path is %s", old_base_path);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,5,5,hvio);

/* find out if user wants to change paths */

sprintf /* prompt user */
(char_buff,"Is the OLD base file on this path? (Y/N) -> ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,7,5,hvio);
VioSetCurPos(7,(5 + strlen(char_buff)),hvio);
gets (response); /* get user response */
trim (response); /* trim whitespace from response */
if ((response[0] == 'N') || (response[0] == 'n')) /* if N or n - */
{
sprintf
(char_buff, "Enter correct path for OLD data base file ->");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,9,5,hvio);
VioSetCurPos(9,(5 + strlen(char_buff)),hvio);
gets (old_base_path); /* get base path from console*/
trim (old_base_path); /* trim whitespace */
/* strip trailing backslash */
while (old_base_path[strlen(old_base_path) -1] == '\\')
old_base_path [strlen(old_base_path) -1] = '\0';
}


/* attempt to open old_base file */
/* warn user if unsuccessful */

strcpy (old_base_file_id, old_base_path); /* copy path */
strcat (old_base_file_id, "\\BASEFILE.DAT"); /* append file id */
old_basef_ptr = fopen (old_base_file_id, "r"); /* open for read */
if (old_basef_ptr == NULL) /* if open error */
{ /* - advise user */
sprintf (char_buff,"%s not found; cannot continue conversion.",
old_base_file_id);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,11,5,hvio);
VioSetCurPos(23,1,hvio);
pause(); /* wait for user */
fcloseall(); /* close all files */
old_base_file_id[0] = '\0'; /* blank out file id string */
return; /* return blank */
}
fclose (old_basef_ptr); /* if successful, close file */
free (char_buff);
return; /* and return file id string */
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ file_con_get_id ^^^^*/

#pragma subtitle("get_change()")
#pragma page()


/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv get_change vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| #include |
| int get_change (struct MOVIETRANS *trans1_ptr, *trans2_ptr, |
| char *base_file_id) |
| FUNCTION |
| ~~~~~~~~ |
| Change an existing record in the base file. Prompts user to identify |
| record to be changed by title and year; searches for record; if found, |
| stores it at trans1_ptr as an add transaction and copies to trans2_ptr |
| as a delete transaction, then prompts user for changes to the add trans. |
| |
| RETURNS |
| ~~~~~~~ |
| TRUE (defined in videocat) if record to be changed is successfully |
| located; otherwise returns FALSE. |
| |
| |
| NOTES |
| ~~~~~ |
| Calls program functions which use MSC extensions; may not be portable |
| accross compilers and operating systems. |
| |
| |
+----------------------------------------------------------------------------*/

get_change (trans1_ptr, trans2_ptr, base_file_id) /* get record & change it */

struct MOVIETRANS *trans1_ptr, *trans2_ptr; /* pointers to trans buffs */
char *base_file_id; /* file id for base file */

{
FILE *basef_ptr; /* ptr to base file */
char *iobuf; /* i/o buffer */
USHORT cbString; /* string byte count */
char *char_buff; /* buffer for string */
extern void clear_screen(); /* func to clear screen & set colors */
char command = '\0'; /* change type command code */
extern void display(); /* func displays contents of record */
extern void draw_box(); /* func draws box */
int found = FALSE; /* boolean flag for record found */
extern void get_form(); /* func gets form from user */
extern void get_loc(); /* func gets location from user */
extern void get_mpaa_code(); /* func gets rating from user */
extern void get_name(); /* func gets name from user */
extern void get_rating(); /* func gets rating from user */
extern void get_subject(); /* func gets subject from user */
extern void get_title(); /* func gets title from user */
extern void get_year(); /* func gets year from user */
HVIO hvio = 0; /* video handle */
char input_command [INPUTLENGTH]; /* user input buffer */
extern char pause(); /* func pauses for user */
struct MOVIERECORD *rec1_ptr; /* pointer to data record */
struct MOVIERECORD *rec2_ptr; /* pointer to data record */
extern void set_border(); /* func sets screen border color */
extern void set_cursor(); /* func sets cursor position */
int tcomp_result = 0; /* result of title comparison */
extern void trim(); /* func trims lead & trail whitespace */
extern int verify(); /* func gets data verification */
int ycomp_result = 0; /* result of year comparison */

rec1_ptr = &trans1_ptr->moviedata; /* set record pointers to point to */
rec2_ptr = &trans2_ptr->moviedata; /* records in transaction structures */
iobuf = calloc (1, BIGBUFF); /* allocate memory to i/o buffer */
char_buff = (char *) calloc (1, 0x100);

/* set up screen display */

clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,21,LWHITE,BLUE);
window (22,61,3,19,BLACK,BLACK);
window (20,59,2,18,BLACK,WHITE);
set_border (BLUE); /* set screen border color */
VioSetCurPos (22,0,hvio); /* position cursor */

/* display message and wait for user */


clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,21,LWHITE,BLUE);
window (6,78,9,14,BLACK,BLACK);
window (4,76,8,13,BLACK,WHITE);
sprintf (char_buff, "Prepare to enter data to change a video record.");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,10,9,hvio);
sprintf (char_buff, "Title and year must match an existing record...");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,11,9,hvio);
set_border (BLUE); /* set screen border color */
VioSetCurPos (22,0,hvio); /* position cursor */
pause();


/* identify record to be changed */

get_title (rec1_ptr->title); /* get title from user */
get_year (rec1_ptr->year); /* get year from user */
basef_ptr = fopen (base_file_id, "rb"); /* open base file */
setvbuf (basef_ptr, iobuf, _IOFBF, BIGBUFF); /* set big i/o buffer */
clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,21,LWHITE,BLUE);
window (6,78,9,14,BLACK,BLACK);
window (4,76,8,13,BLACK,WHITE);
sprintf (char_buff, "Searching for record to be changed.............");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,10,9,hvio);
set_border (BLUE); /* set screen border color */
VioSetCurPos (22,0,hvio); /* position cursor */

/* search base file for record with matching title and year */

if (basef_ptr == NULL) /* if open error - */
{
printf (" Error in attempting to open base file.\n"); /* warn user */
pause();
return FALSE; /* & return error */
}
while ((!(feof (basef_ptr))) && (!(found))) /* while not EOF and not found */
{
if ((fread ((char *)&trans2_ptr->moviedata, sizeof(struct MOVIERECORD),
1, basef_ptr)) != 1) /* read a record */
{ /* if read error - */
if (feof(basef_ptr)) /* - if EOF break loop */
break; /* and continue (normal condition) */
else
{ /* - if other read error - */
printf (" Error in reading base file.\n"); /* warn user */
pause(); /* wait for user */
break; /* break off search (abnormal condition) */
}
}
tcomp_result = strcmp (rec1_ptr->title, /* compare search */
rec2_ptr->title); /* title and record title */
if (tcomp_result < 0) /* if record is past targed in alpha order */
break; /* break, no need to search rest of file */
ycomp_result = strcmp (rec1_ptr->year, /*compare search */
rec2_ptr->year); /* year and record year */
if ((tcomp_result == 0) && (ycomp_result == 0)) /* if both title and */
{ /* year are exact matches */
found = TRUE; /* then target has been found */
break; /* break, no need to search rest of file */
}
}
fclose (basef_ptr); /* close base file */
free (iobuf); /* free memory allocated to i/o buffer */

/* process change of matching record, if found */

if (!(found)) /* if matching record not found */
{
VioSetCurPos(22,0,hvio);
printf (" Record not found.\n"); /* warn user */
pause();
return FALSE; /* return error result */
}
memcpy ((char *)&trans1_ptr->moviedata, (char *)&trans2_ptr->moviedata,
sizeof (struct MOVIERECORD)); /* copy record data to target buffer */
trans2_ptr->transaction = 'D'; /* code buffer 2 as a delete trans */
trans1_ptr->transaction = 'A'; /* code buffer 2 becomes add trans */

while (command != 'Q') /* loop while user has not entered Quit code */
{

clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,21,WHITE,BLUE);
window (0,79,0,0,LWHITE,BLUE);
window (6,78,2,5,BLACK,BLACK);
window (4,76,1,4,BLACK,WHITE);
set_border (BLUE); /* set screen border color */
sprintf (char_buff,"Current content of replacement record:");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,0,3,hvio); /* write to screen */
disp_rec (1,rec1_ptr); /* display current content of add trans */
VioSetCurPos (23,0,hvio); /* position cursor */



draw_box ('L',2,77,6,20);


sprintf (char_buff,"CHANGE MENU"); /* display change menu */
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,8,34,hvio); /* write to screen */

sprintf (char_buff, "T = change Title");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,12,6,hvio); /* write to screen */

sprintf (char_buff, "Y = change Year");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,13,6,hvio); /* write to screen */

sprintf (char_buff, "S = change Subject");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,14,6,hvio); /* write to screen */

sprintf (char_buff, "F = change Form");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,15,6,hvio); /* write to screen */

sprintf (char_buff, "R = change Rating");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,16,6,hvio); /* write to screen */

sprintf (char_buff, "M = change MPAA code");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,17,6,hvio); /* write to screen */

sprintf (char_buff, "1 = change Star 1 name");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,12,40,hvio); /* write to screen */

sprintf (char_buff, "2 = change Star 2 name");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,13,40,hvio); /* write to screen */

sprintf (char_buff, "3 = change Star 3 name");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,14,40,hvio); /* write to screen */

sprintf (char_buff, "D = change Director name");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,15,40,hvio); /* write to screen */

sprintf (char_buff, "C = change Cassette number");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,16,40,hvio); /* write to screen */

sprintf (char_buff, "I = change Index number");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,17,40,hvio); /* write to screen */

sprintf (char_buff, "Q = Quit - changes complete");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,18,22,hvio); /* write to screen */

sprintf (char_buff, " Enter letter for desired function -> ");
cbString = (USHORT)strlen(char_buff); /* get byte count */
VioWrtCharStr(char_buff,cbString,23,0,hvio); /* write to screen */
VioSetCurPos (23,cbString,hvio);

gets (input_command); /* get user input */
trim (input_command); /* trim whitespace from user input */
command = input_command [0]; /* command = 1st char input by user */
command = toupper (command); /* convert lower to upper case */
VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioWrtNChar(" ",80,24,0,hvio);

switch (command) /* take action according to code entered by user */
{
case 'T' :
get_title (rec1_ptr->title);
break;

case 'Y' :
get_year (rec1_ptr->year);
break;

case 'S' :
get_subject (&rec1_ptr->subject);
break;

case 'F' :
get_form (&rec1_ptr->form);
break;

case 'R' :
get_rating (&rec1_ptr->rating);
break;

case 'M' :
get_mpaa_code (&rec1_ptr->mpaa_code);
break;

case '1' :
get_name (rec1_ptr->star1, "Star 1");
break;

case '2' :
get_name (rec1_ptr->star2, "Star 2");
break;

case '3' :
get_name (rec1_ptr->star3, "Star 3");
break;

case 'D' :
get_name (rec1_ptr->director, "Director");
break;

case 'C' :
get_loc (rec1_ptr->loc1, "Cassette No. ");
break;

case 'I' :
get_loc (rec1_ptr->loc2, "Index No. ");
break;

case 'Q' :
break;

default :
VioSetCurPos(22,0,hvio);
printf (" Invalid Code ");
VioSetCurPos(23,0,hvio);
pause();
break;
}
}

VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioWrtNChar(" ",80,24,0,hvio);
VioSetCurPos(22,0,hvio);
free (char_buff);

if (verify ()) /* if verified by user - */
{
VioSetCurPos(23,0,hvio);
printf (" Record VERIFIED - add to transaction list.");
VioSetCurPos(24,0,hvio);
pause();
clear_screen (LWHITE, BLUE); /* - clear screen & reset colors */
set_border (BLACK); /* - reset border color */
return TRUE; /* - return TRUE value */
}
else /* if not verified by user - */
{
VioSetCurPos(23,0,hvio);
printf (" Record NOT verified - discard. ");
VioSetCurPos(24,1,hvio);
pause();
clear_screen (LWHITE, BLUE); /* - clear screen & reset colors */
set_border (BLACK); /* - reset border color */
return FALSE; /* - return FALSE value */

}
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ get_change ^^^^*/

#pragma subtitle("get_data()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv get_data vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| #include |
| int get_data (struct MOVIETRANS *trans_ptr) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Gets data from user to complete content of transaction pointer |
| requests user verification, and returns result of verification. |
| |
| RETURNS |
| ~~~~~~~ |
| TRUE (defined in videocat) if user verifies record; otherwise |
| returns false. |
| |
| |
| NOTES |
| ~~~~~ |
| Calls program functions which use MSC extensions; may not be portable |
| accross compilers and operating systems. |
| |
| |
+----------------------------------------------------------------------------*/

int get_data (trans_ptr) /* get data from user */

struct MOVIETRANS *trans_ptr; /* pointer to transaction */

{
USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
extern void clear_screen(); /* func to clear screen & set colors */
extern void display(); /* func displays contents of record */
extern void get_form(); /* func gets form from user */
extern void get_loc(); /* func gets location from user */
extern void get_mpaa_code(); /* func gets mpaa code */
extern void get_name(); /* func gets name from user */
extern void get_rating(); /* func gets rating from user */
extern void get_subject(); /* func gets subject from user */
extern void get_title(); /* func gets title from user */
extern void get_year(); /* func gets year from user */
HVIO hvio = 0; /* video handle */
extern char pause(); /* func pauses for user */
struct MOVIERECORD *rec_ptr; /* pointer to a data record */
extern void set_border(); /* func sets screen border color */
extern void set_cursor(); /* func sets cursor position */
extern int verify(); /* func gets data verification */

char_buff = (char *) calloc (1, 0x100);
rec_ptr = &trans_ptr->moviedata; /* set pointer to record in trans struct */

/* set up screen display */

clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,21,LWHITE,BLUE);
window (22,61,3,19,BLACK,BLACK);
window (20,59,2,18,BLACK,WHITE);
set_border (BLUE); /* set screen border color */
VioSetCurPos (22,0,hvio); /* position cursor */

/* display message and wait for user */


clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,21,LWHITE,BLUE);
window (6,78,9,14,BLACK,BLACK);
window (4,76,8,13,BLACK,WHITE);
sprintf (char_buff, "Prepare to enter data for a video record...");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,11,9,hvio);
set_border (BLUE); /* set screen border color */
VioSetCurPos (22,0,hvio); /* position cursor */
pause();

/* get data from user */

clear_screen (BLACK, WHITE); /* clear screen */
get_title (rec_ptr->title); /* get title from user */
get_year (rec_ptr->year); /* get year from user */
if (trans_ptr->transaction != 'D') /* if not a delete transaction - */
{
get_name (rec_ptr->star1, "Star 1"); /* get star 1 name */
get_name (rec_ptr->star2, "Star 2"); /* get star 2 name */
get_name (rec_ptr->star3, "Star 3"); /* get star 3 name */
get_name (rec_ptr->director, "Director"); /* director name */
get_subject (&rec_ptr->subject); /* get subject */
get_form (&rec_ptr->form); /* get form */
get_mpaa_code (&rec_ptr->mpaa_code); /* get mpaa code */
get_rating (&rec_ptr->rating); /* get rating */
get_loc (rec_ptr->loc1, "Cassette No. "); /* get cassette # */
get_loc (rec_ptr->loc2, "Index No. "); /* get index no. */
}

/* display data entered & get user verification */

clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,20,LWHITE,BLUE);
window (6,78,9,14,BLACK,BLACK);
window (4,76,8,13,BLACK,WHITE);
set_border (BLUE); /* set screen border color */
VioSetCurPos (21,0,hvio); /* position cursor */
display (8, trans_ptr); /* display record content */

if (verify ()) /* if verified by user - */
{
VioSetCurPos(22,0,hvio);
printf (" Record VERIFIED - add to transaction list.");
VioSetCurPos(23,1,hvio);
pause();
clear_screen (LWHITE, BLUE); /* - clear screen & reset colors */
set_border (BLACK); /* - reset border color */
free (char_buff);
return TRUE; /* - return TRUE value */
}
else /* if not verified by user - */
{
VioSetCurPos(22,0,hvio);
printf (" Record NOT verified - discard. ");
VioSetCurPos(23,1,hvio);
pause();
clear_screen (LWHITE, BLUE); /* - clear screen & reset colors */
set_border (BLACK); /* - reset border color */
free (char_buff);
return FALSE; /* - return FALSE value */
}
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ get_data ^^^^*/

#pragma subtitle("get_delete()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv get_delete vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| #include |
| int get_delete (struct MOVIETRANS *trans1_ptr, *trans2_ptr, |
| char *base_file_id) |
| FUNCTION |
| ~~~~~~~~ |
| Delete an existing record in the base file. Prompts user to identify |
| record to be deleted by title and year; searches for record; if found, |
| stores it at trans2_ptr as a delete transactions. |
| |
| RETURNS |
| ~~~~~~~ |
| TRUE (defined in videocat) if record to be deleted is successfully |
| located and verified by the user; otherwise returns FALSE. |
| |
| |
| NOTES |
| ~~~~~ |
| Calls program functions which use MSC extensions; may not be portable |
| accross compilers and operating systems. |
| |
| |
+----------------------------------------------------------------------------*/

int get_delete (trans1_ptr, trans2_ptr, base_file_id) /* get & delete record */

struct MOVIETRANS *trans1_ptr, *trans2_ptr; /* pointers to trans buffs */
char *base_file_id; /* file id for base file */
{
FILE *basef_ptr; /* ptr to base file */
USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
extern void clear_screen(); /* func to clear screen & set colors */
extern void display(); /* func displays contents of record */
int found = FALSE; /* boolean flag for record found */
extern void get_title(); /* func gets title from user */
extern void get_year(); /* func gets year from user */
HVIO hvio = 0; /* video handle */
char *iobuf; /* buffer for file i/o */
extern char pause(); /* func pauses for user */
struct MOVIERECORD *rec1_ptr; /* pointer to a data record */
struct MOVIERECORD *rec2_ptr; /* pointer to a data record */
extern void set_border(); /* func sets screen border color */
extern void set_cursor(); /* func sets cursor position */
int tcomp_result; /* result of title comparison */
extern int verify(); /* func gets data verification */
int ycomp_result; /*result of year comparison */

char_buff = (char *) calloc (1, 0x100);
rec1_ptr = &trans1_ptr->moviedata; /* set record pointers to data recs */
rec2_ptr = &trans2_ptr->moviedata; /* in transaction structures */
iobuf = calloc (1, BIGBUFF); /* allocate memory to i/o buffer */




/* set up screen display */

clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,21,LWHITE,BLUE);
window (22,61,3,19,BLACK,BLACK);
window (20,59,2,18,BLACK,WHITE);
set_border (BLUE); /* set screen border color */
VioSetCurPos (22,0,hvio); /* position cursor */

/* display message and wait for user */


clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,21,LWHITE,BLUE);
window (6,78,9,14,BLACK,BLACK);
window (4,76,8,13,BLACK,WHITE);
sprintf (char_buff, "Prepare to enter data to delete a video record.");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,10,9,hvio);
sprintf (char_buff, "Title and year must match an existing record...");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,11,9,hvio);
set_border (BLUE); /* set screen border color */
VioSetCurPos (22,0,hvio); /* position cursor */
pause();


/* identify record to be changed */

get_title (rec1_ptr->title); /* get title from user */
get_year (rec1_ptr->year); /* get year from user */
basef_ptr = fopen (base_file_id, "rb"); /* open base file */
setvbuf (basef_ptr, iobuf, _IOFBF, BIGBUFF); /* set big i/o buffer */
clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,21,LWHITE,BLUE);
window (6,78,9,14,BLACK,BLACK);
window (4,76,8,13,BLACK,WHITE);
sprintf (char_buff, "Searching for record to be deleted.............");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,10,9,hvio);
set_border (BLUE); /* set screen border color */
VioSetCurPos (22,0,hvio); /* position cursor */


/* search base file for record with matching title and year */

if (basef_ptr == NULL) /* if open error - */
{
printf (" Error in attempting to open base file.\n"); /* warn user */
pause();
return FALSE; /* & return error */
}
while ((!(feof (basef_ptr))) && (!(found))) /* while not EOF and not found */
{
if ((fread ((char *)&trans2_ptr->moviedata, sizeof(struct MOVIERECORD),
1, basef_ptr)) != 1) /* read a record */
{ /* if read error - */
if (feof(basef_ptr)) /* - if EOF break loop */
break; /* and continue (normal condition) */
else
{ /* - if other read error - */
printf (" Error in reading base file.\n"); /* warn user */
pause(); /* wait for user */
break; /* break off search (abnormal condition) */
}
}
tcomp_result = strcmp (rec1_ptr->title, /* compare search */
rec2_ptr->title); /* title and record title */
if (tcomp_result < 0) /* if record is past targed in alpha order */
break; /* break, no need to search rest of file */
ycomp_result = strcmp (rec1_ptr->year, /*compare search */
rec2_ptr->year); /* year and record year */
if ((tcomp_result == 0) && (ycomp_result == 0)) /* if both title and */
{ /* year are exact matches */
found = TRUE; /* then target has been found */
break; /* break, no need to search rest of file */
}
}
fclose (basef_ptr); /* close base file */
free (iobuf); /* free memory allocated to i/o buffer */

/* process change of matching record, if found */

if (!(found)) /* if matching record not found */
{
printf (" Record not found.\n"); /* warn user */
pause(); /* wait for user */
return FALSE; /* return error result */
}
trans2_ptr->transaction = 'D'; /* code buffer 2 as a delete trans */



clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,21,WHITE,BLUE);
window (0,79,0,0,LWHITE,BLUE);
window (6,78,2,5,BLACK,BLACK);
window (4,76,1,4,BLACK,WHITE);
set_border (BLUE); /* set screen border color */
display (0, trans2_ptr); /* display current content of add trans */
VioSetCurPos (23,0,hvio); /* position cursor */



VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioWrtNChar(" ",80,24,0,hvio);
VioSetCurPos(22,0,hvio);

if (verify ()) /* if verified by user - */
{
VioSetCurPos(23,0,hvio);
printf (" Delete VERIFIED - add to transaction list.");
VioSetCurPos(24,0,hvio);
pause();
free (char_buff);
clear_screen (LWHITE, BLUE); /* - clear screen & reset colors */
set_border (BLACK); /* - reset border color */
return TRUE; /* - return TRUE value */
}
else /* if not verified by user - */
{
VioSetCurPos(23,0,hvio);
printf (" Delete NOT verified - discard. ");
VioSetCurPos(24,0,hvio);
pause();
clear_screen (LWHITE, BLUE); /* - clear screen & reset colors */
set_border (BLACK); /* - reset border color */
free (char_buff);
return FALSE; /* - return FALSE value */

}

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ get_delete ^^^^*/

#pragma subtitle("get_form()")
#pragma page()


/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv get_form vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| #include |
| void get_form (char *form_ptr) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Calls function list_forms () to display form codes and explanations, |
| prompts user to enter a selected code, checks the code entered against |
| the codes in the global array codes[] for validity, repeats prompt if |
| not valid, otherwise puts character in the byte pointed to by form_ptr. |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Accesses the global array codes[]. |
| |
| |
| |
+----------------------------------------------------------------------------*/

void get_form (form_ptr) /* func gets form code from user */

char *form_ptr; /* ptr to storage for form code */

{
USHORT cbString; /* string byte Count */
char *char_buff; /* string buffer */
int count; /* counter */
HVIO hvio = 0; /* video handle */
char input_form [INPUTLENGTH]; /* user input buffer */
extern void trim(); /* func trims lead & trail whitespace */
int valid_code = FALSE; /* validity test flag */
extern void window(); /* function opens screen window */

char_buff = (char *) calloc (1, 0x100);
while (!valid_code) /* while valid code not entered - */
{
clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,21,LWHITE,BLUE);


window (16,39,1,14,BLUE,BLACK);
window (15,38,0,13,BLACK,WHITE);
VioWrtNChar ("\xDC",24,14,16,hvio);

window (42,65,1,14,BLUE,BLACK);
window (41,64,0,13,BLACK,WHITE);
VioWrtNChar ("\xDC",24,14,42,hvio);

set_border (BLUE); /* set screen border color */
VioSetCurPos (22,0,hvio); /* position cursor */

/* print top border of table */

sprintf (char_buff," %c", 201);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,0,0,hvio);
for (count = 0; count < 22; count++)
{
sprintf (char_buff,"%c", 205);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,0,(count + 16),hvio);
}
sprintf (char_buff,"%c %c", 187, 201);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,0,38,hvio);
for (count = 0; count < 22; count++)
{
sprintf (char_buff,"%c", 205);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,0,(count + 42),hvio);
}
sprintf (char_buff,"%c", 187);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,0,64,hvio);

/* print main body of table */

sprintf (char_buff," %c A = Adventure %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,1,0,hvio);
sprintf (char_buff, " %c M = Intrigue %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,1,39,hvio);

sprintf (char_buff," %c B = Classic %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,2,0,hvio);
sprintf (char_buff, " %c N = Melodrama %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,2,39,hvio);

sprintf (char_buff," %c C = Comedy %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,3,0,hvio);
sprintf (char_buff, " %c O = Mystery %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,3,39,hvio);

sprintf (char_buff," %c D = Comedy-Drama %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,4,0,hvio);
sprintf (char_buff, " %c P = One-man-show %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,4,39,hvio);

sprintf (char_buff," %c E = Compilation %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,5,0,hvio);
sprintf (char_buff, " %c Q = Opera %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,5,39,hvio);

sprintf (char_buff," %c F = Concert %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,6,0,hvio);
sprintf (char_buff, " %c R = Revue %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,6,39,hvio);

sprintf (char_buff," %c G = Documentary %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,7,0,hvio);
sprintf (char_buff, " %c S = Romance %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,7,39,hvio);

sprintf (char_buff," %c H = Docu-Drama %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,8,0,hvio);
sprintf (char_buff, " %c T = Satire %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,8,39,hvio);


sprintf (char_buff," %c I = Drama %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString, 9,0,hvio);
sprintf (char_buff, " %c U = Spoof %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString, 9,39,hvio);

sprintf (char_buff," %c J = Epic %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,10,0,hvio);
sprintf (char_buff, " %c V = Story %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,10,39,hvio);

sprintf (char_buff," %c K = Fantasy %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,11,0,hvio);
sprintf (char_buff, " %c W = Thriller %c", 186, 186);

cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,11,39,hvio);

sprintf (char_buff," %c L = Farce %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,12,0,hvio);
sprintf (char_buff, " %c X = Variety %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,12,39,hvio);


/* print bottom border of table */



sprintf (char_buff," %c", 200);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,13,0,hvio);
for (count = 0; count < 22; count++)
{
sprintf (char_buff,"%c", 205);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,13,(count + 16),hvio);
}
sprintf (char_buff,"%c %c", 188, 200);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,13,38,hvio);
for (count = 0; count < 22; count++)
{
sprintf (char_buff,"%c", 205);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,13,(count + 42),hvio);
}
sprintf (char_buff,"%c", 188);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,13,64,hvio);


/* get user response */

VioSetCurPos (23,0,hvio);
printf (" Form code -> "); /* prompt user for input */
gets (input_form); /* get user input */
trim (input_form); /* trim user input */
*form_ptr = toupper (input_form[0]); /* move first character entered */
for (count = 0; count < FORMNUMBER; count++) /* compare with codes */
if (*form_ptr == codes[count]) /* list; if code found, then */
valid_code = TRUE; /* code is valid */
}
set_border (BLACK);
free (char_buff);

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ get_form ^^^^*/

#pragma subtitle("get_loc()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv get_loc vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| void get_loc (char *loc_ptr, *loc_for) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Prompts the user to enter location for location describe by string |
| at *loc_for, gets user input, edits input, and copies to *loc_ptr. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| NOTES |
| ~~~~~ |
| Uses macros defined in Videocat. Otherwise uses only ANSI standard |
| functions and should be portable. Uses string functions declared |
| in string.h. |
| |
| |
| |
+----------------------------------------------------------------------------*/

void get_loc (loc_ptr, loc_for) /* func to get name from user */

char *loc_ptr; /* place where name is to be stored */
char *loc_for; /* whose name requested */

{

USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
extern void editRdata(); /* func edits to record format */
HVIO hvio = 0; /* video handle */
char input_loc [INPUTLENGTH]; /* user input buff */
extern void set_border(); /* func sets border color */
extern void window(); /* func opens screen window */


char_buff = (char *) calloc (1, 0x100);
clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,21,LWHITE,BLUE);
window (6,78,9,14,BLACK,BLACK);
window (4,76,8,13,BLACK,WHITE);
sprintf (char_buff, "Please enter requested data....");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,11,9,hvio);
set_border (BLUE); /* set screen border color */
VioSetCurPos (22,0,hvio); /* position cursor */
printf ("\n %s -> ", loc_for); /* prompt user to enter location */
gets (input_loc); /* get user input */
editRdata (input_loc, LOCLENGTH); /* edit user input to record format */
strcpy (loc_ptr, input_loc); /* copy location to destination */
set_border (BLACK);
free (char_buff);

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ get_loc ^^^^*/

#pragma subtitle("get_mpaa_code()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv get_mpaa_code vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| #include |
| void get_mpaa_code (char *mpaa_ptr) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Calls function list_rates () to display rating codes and explanactions, |
| prompts user to enter a selected code, checks the code entered against |
| the codes in the global array mpaa_codes[] for validity,repeats prompt if |
| not valid, otherwise puts character in the byte pointed to by rate_ptr. |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Accesses the global array mpaa_codes[]. |
| |
| |
| |
+----------------------------------------------------------------------------*/

void get_mpaa_code (mpaa_ptr) /* func gets rating code from user */

char *mpaa_ptr; /* ptr to storage for subj code */

{
USHORT cbString; /* string byte Count */
char *char_buff; /* string buffer */
int count; /* counter */
HVIO hvio = 0; /* video handle */
char input_rate [INPUTLENGTH]; /* user input buffer */
extern void trim(); /* func trims lead & trail whitespace */
int valid_code = FALSE; /* validity test flag */
extern void window(); /* function opens screen window */

char_buff = (char *) calloc (1, 0x100);
while (!valid_code) /* while valid code not entered - */
{
clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,21,LWHITE,BLUE);


window (16,39,1,5,BLUE,BLACK);
window (15,38,0,4,BLACK,WHITE);
VioWrtNChar ("\xDC",24,5,16,hvio);

window (42,65,1,5,BLUE,BLACK);
window (41,64,0,4,BLACK,WHITE);
VioWrtNChar ("\xDC",24,5,42,hvio);

set_border (BLUE); /* set screen border color */
VioSetCurPos (22,0,hvio); /* position cursor */

/* print top border of table */

sprintf (char_buff," %c", 201);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,0,0,hvio);
for (count = 0; count < 22; count++)
{
sprintf (char_buff,"%c", 205);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,0,(count + 16),hvio);
}
sprintf (char_buff,"%c %c", 187, 201);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,0,38,hvio);
for (count = 0; count < 22; count++)
{
sprintf (char_buff,"%c", 205);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,0,(count + 42),hvio);
}
sprintf (char_buff,"%c", 187);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,0,64,hvio);

/* print main body of table */

sprintf (char_buff," %c A = MPAA G Rated %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,1,0,hvio);
sprintf (char_buff, " %c D = MPAA R Rated %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,1,39,hvio);

sprintf (char_buff," %c B = MPAA PG Rated %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,2,0,hvio);
sprintf (char_buff, " %c E = MPAA X Rated %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,2,39,hvio);

sprintf (char_buff," %c C = MPAA PG13 Rated %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,3,0,hvio);
sprintf (char_buff, " %c F = MPAA Not Rated %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,3,39,hvio);



/* print bottom border of table */



sprintf (char_buff," %c", 200);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,4,0,hvio);
for (count = 0; count < 22; count++)
{
sprintf (char_buff,"%c", 205);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,4,(count + 16),hvio);
}
sprintf (char_buff,"%c %c", 188, 200);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,4,38,hvio);
for (count = 0; count < 22; count++)
{
sprintf (char_buff,"%c", 205);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,4,(count + 42),hvio);
}
sprintf (char_buff,"%c", 188);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,4,64,hvio);


/* get user response */

VioSetCurPos (23,0,hvio);
printf (" MPAA code -> "); /* prompt user for input */
gets (input_rate); /* get user input */
trim (input_rate); /* trim user input */
*mpaa_ptr = toupper (input_rate[0]); /* move first character entered */
for (count = 0; count < MPAANUMBER; count++) /* compare with codes */
if (*mpaa_ptr == codes[count]) /* list; if code found, then */
valid_code = TRUE; /* code is valid */
}
set_border (BLACK);
free (char_buff);

}


/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ get_mpaa_code ^^^^*/

#pragma subtitle("get_name()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv get_name vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| void get_name (char *name_ptr, *name_for) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Prompts the user to enter name described by *name_for, gets user |
| input and arranges it in the form LAST,FIRST, in upper case with |
| leading and trailing whitespace deleted (unless embedded within the |
| first or last name). |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Uses macros defined in Videocat and MSC extensions. May not be portable |
| accross operating systems and compilers.string functions declared |
| |
| |
| |
+----------------------------------------------------------------------------*/

void get_name (name_ptr, name_for) /* func to get name from user */

char *name_ptr; /* place where name is to be stored */
char *name_for; /* whose name requested */

{
USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
extern void editLdata(); /* func to edit data to record format */
HVIO hvio = 0; /* video handle */
char input_name [INPUTLENGTH]; /* buff for user input */
char name_data [INPUTLENGTH]; /* data work area */
extern void trim(); /* func strips lead & trail whitespace */
extern void window(); /* func opens screen window */

char_buff = (char *) calloc (1, 0x100);
clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,20,LWHITE,BLUE);
window (6,78,9,14,BLACK,BLACK);
window (4,76,8,13,BLACK,WHITE);
sprintf (char_buff, "Please enter requested data....");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,11,9,hvio);
set_border (BLUE); /* set screen border color */
VioSetCurPos (22,0,hvio); /* position cursor */
printf (" %s LAST name -> ", name_for); /* prompt user for last name */
gets (input_name); /* get user input */
trim (input_name); /* trim input */
strcpy (name_data, input_name); /* copy input to work area */
strcat (name_data, ","); /* append comma to work area */
printf (" %s FIRST name -> ", name_for); /* prompt user for first name */
gets (input_name); /* get user input */
trim (input_name); /* trim input */
strcat (name_data, input_name); /* append first name to work area */
editLdata (name_data, NAMELENGTH); /* edit work area to record format */
strcpy (name_ptr, name_data); /* copy work area to place for name */
set_border (BLACK);
free (char_buff);

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ get_name ^^^^*/

#pragma subtitle("get_rating()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv get_rating vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| #include |
| void get_rating (char *rate_ptr) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Calls function list_rates () to display rating codes and explanactions, |
| prompts user to enter a selected code, checks the code entered against |
| the codes in the global array codes[] for validity, repeats prompt if |
| not valid, otherwise puts character in the byte pointed to by rate_ptr. |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Accesses the global array codes[]. |
| |
| |
| |
+----------------------------------------------------------------------------*/

void get_rating (rate_ptr) /* func gets rating code from user */

char *rate_ptr; /* ptr to storage for subj code */

{
USHORT cbString; /* string byte Count */
char *char_buff; /* string buffer */
int count; /* counter */
HVIO hvio = 0; /* video handle */
char input_rate [INPUTLENGTH]; /* user input buffer */
extern void trim(); /* func trims lead & trail whitespace */
int valid_code = FALSE; /* validity test flag */
extern void window(); /* function opens screen window */

char_buff = (char *) calloc (1, 0x100);
while (!valid_code) /* while valid code not entered - */
{
clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,21,LWHITE,BLUE);


window (16,39,1,6,BLUE,BLACK);
window (15,38,0,5,BLACK,WHITE);
VioWrtNChar ("\xDC",24,6,16,hvio);

window (42,65,1,6,BLUE,BLACK);
window (41,64,0,5,BLACK,WHITE);
VioWrtNChar ("\xDC",24,6,42,hvio);

set_border (BLUE); /* set screen border color */
VioSetCurPos (22,0,hvio); /* position cursor */

/* print top border of table */

sprintf (char_buff," %c", 201);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,0,0,hvio);
for (count = 0; count < 22; count++)
{
sprintf (char_buff,"%c", 205);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,0,(count + 16),hvio);
}
sprintf (char_buff,"%c %c", 187, 201);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,0,38,hvio);
for (count = 0; count < 22; count++)
{
sprintf (char_buff,"%c", 205);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,0,(count + 42),hvio);
}
sprintf (char_buff,"%c", 187);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,0,64,hvio);

/* print main body of table */

sprintf (char_buff," %c A = **** Excellent %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,1,0,hvio);
sprintf (char_buff, " %c E = ** Fair %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,1,39,hvio);

sprintf (char_buff," %c B = ***+ Very Good %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,2,0,hvio);
sprintf (char_buff, " %c F = *+ Poor %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,2,39,hvio);

sprintf (char_buff," %c C = *** Good %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,3,0,hvio);
sprintf (char_buff, " %c G = * Bad %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,3,39,hvio);

sprintf (char_buff," %c D = **+ Pretty Good %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,4,0,hvio);
sprintf (char_buff, " %c H = + Abysmal %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,4,39,hvio);


/* print bottom border of table */



sprintf (char_buff," %c", 200);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,5,0,hvio);
for (count = 0; count < 22; count++)
{
sprintf (char_buff,"%c", 205);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,5,(count + 16),hvio);
}
sprintf (char_buff,"%c %c", 188, 200);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,5,38,hvio);
for (count = 0; count < 22; count++)
{
sprintf (char_buff,"%c", 205);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,5,(count + 42),hvio);
}

sprintf (char_buff,"%c", 188);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,5,64,hvio);


/* get user response */

VioSetCurPos (23,0,hvio);
printf (" Rating code -> "); /* prompt user for input */
gets (input_rate); /* get user input */
trim (input_rate); /* trim user input */
*rate_ptr = toupper (input_rate[0]); /* move first character entered */
for (count = 0; count < RATINGNUMBER; count++) /* compare with codes */
if (*rate_ptr == codes[count]) /* list; if code found, then */
valid_code = TRUE; /* code is valid */
}
set_border (BLACK);

free (char_buff);
}


/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ get_rating ^^^^*/

#pragma subtitle("get_subject()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv get_subject vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| #include |
| void get_subj (char *subj_ptr) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Calls function list_subjs () to display subj codes and explanations, |
| prompts user to enter a selected code, checks the code entered against |
| the codes in the global array codes[] for validity, repeats prompt if |
| not valid, otherwise puts character in the byte pointed to by subj_ptr. |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Accesses the global array codes[]. |
| |
| |
| |
| |
| |
+----------------------------------------------------------------------------*/

void get_subject (subj_ptr) /* func gets subj code from user */

char *subj_ptr; /* ptr to storage for subj code */

{
USHORT cbString; /* string byte Count */
char *char_buff; /* string buffer */
int count; /* counter */
HVIO hvio = 0; /* video handle */
char input_subj [INPUTLENGTH]; /* user input buffer */
extern void trim(); /* func trims lead & trail whitespace */
int valid_code = FALSE; /* validity test flag */
extern void window(); /* function opens screen window */

char_buff = (char *) calloc (1, 0x100);
while (!valid_code) /* while valid code not entered - */
{
clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,23,LWHITE,BLUE);


window (16,39,1,23,BLUE,BLACK);
window (15,38,0,22,BLACK,WHITE);
VioWrtNChar ("\xDC",24,23,16,hvio);

window (42,65,1,23,BLUE,BLACK);
window (41,64,0,22,BLACK,WHITE);
VioWrtNChar ("\xDC",24,23,42,hvio);

set_border (BLUE); /* set screen border color */
VioSetCurPos (22,0,hvio); /* position cursor */

/* print top border of table */

sprintf (char_buff," %c", 201);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,0,0,hvio);
for (count = 0; count < 22; count++)
{
sprintf (char_buff,"%c", 205);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,0,(count + 16),hvio);
}
sprintf (char_buff,"%c %c", 187, 201);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,0,38,hvio);
for (count = 0; count < 22; count++)
{
sprintf (char_buff,"%c", 205);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,0,(count + 42),hvio);
}
sprintf (char_buff,"%c", 187);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,0,64,hvio);

/* print main body of table */

sprintf (char_buff," %c A = Action %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,1,0,hvio);
sprintf (char_buff, " %c V = Musical %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,1,39,hvio);

sprintf (char_buff," %c B = Adult %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,2,0,hvio);
sprintf (char_buff, " %c W = Period %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,2,39,hvio);

sprintf (char_buff," %c C = Animated %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,3,0,hvio);
sprintf (char_buff, " %c X = Police %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,3,39,hvio);

sprintf (char_buff," %c D = Biographical %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,4,0,hvio);
sprintf (char_buff, " %c Y = Political %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,4,39,hvio);

sprintf (char_buff," %c E = Caper %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,5,0,hvio);
sprintf (char_buff, " %c Z = Prison %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,5,39,hvio);

sprintf (char_buff," %c F = Contemporary %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,6,0,hvio);
sprintf (char_buff, " %c 1 = Psychological %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,6,39,hvio);

sprintf (char_buff," %c G = Courtroom %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,7,0,hvio);
sprintf (char_buff, " %c 2 = Religious %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,7,39,hvio);

sprintf (char_buff," %c H = Crime %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,8,0,hvio);
sprintf (char_buff, " %c 3 = Rock %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,8,39,hvio);


sprintf (char_buff," %c I = Dance %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString, 9,0,hvio);
sprintf (char_buff, " %c 4 = Romantic %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString, 9,39,hvio);

sprintf (char_buff," %c J = Detective %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,10,0,hvio);
sprintf (char_buff, " %c 5 = Science %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,10,39,hvio);

sprintf (char_buff," %c K = Disaster %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,11,0,hvio);
sprintf (char_buff, " %c 6 = Science-Fiction %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,11,39,hvio);

sprintf (char_buff," %c L = Family %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,12,0,hvio);
sprintf (char_buff, " %c 7 = Sex %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,12,39,hvio);

sprintf (char_buff," %c M = Futuristic %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,13,0,hvio);
sprintf (char_buff, " %c 8 = Social %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,13,39,hvio);

sprintf (char_buff," %c N = Gangster %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,14,0,hvio);
sprintf (char_buff, " %c 9 = Sports %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,14,39,hvio);

sprintf (char_buff," %c O = Historical %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,15,0,hvio);
sprintf (char_buff, " %c 0 = Supernatural %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,15,39,hvio);

sprintf (char_buff," %c P = Horror %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,16,0,hvio);
sprintf (char_buff, " %c # = Suspense %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,16,39,hvio);

sprintf (char_buff," %c Q = International %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,17,0,hvio);
sprintf (char_buff, " %c $ = Terror %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,17,39,hvio);

sprintf (char_buff," %c R = Journalism %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,18,0,hvio);
sprintf (char_buff, " %c %% = War %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,18,39,hvio);

sprintf (char_buff," %c S = Military %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,19,0,hvio);
sprintf (char_buff, " %c & = Western %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,19,39,hvio);

sprintf (char_buff," %c T = Medical %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,20,0,hvio);
sprintf (char_buff, " %c ! = Youth %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,20,39,hvio);

sprintf (char_buff," %c U = Murder %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,21,0,hvio);
sprintf (char_buff, " %c * = Miscellaneous %c", 186, 186);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,21,39,hvio);

/* print bottom border of table */

sprintf (char_buff," %c", 200);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,22,0,hvio);
for (count = 0; count < 22; count++)
{
sprintf (char_buff,"%c", 205);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,22,(count + 16),hvio);
}
sprintf (char_buff,"%c %c", 188, 200);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,22,38,hvio);
for (count = 0; count < 22; count++)
{
sprintf (char_buff,"%c", 205);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,22,(count + 42),hvio);
}
sprintf (char_buff,"%c", 188);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,22,64,hvio);


/* get user response */

VioSetCurPos (24,0,hvio);
printf (" Subject code -> "); /* prompt user for input */
gets (input_subj); /* get user input */
trim (input_subj); /* trim user input */
*subj_ptr = toupper (input_subj[0]); /* move first character entered */
for (count = 0; count < SUBJNUMBER; count++) /* compare with codes */
if (*subj_ptr == codes[count]) /* list; if code found, then */
valid_code = TRUE; /* code is valid */
}
set_border (BLACK);
free (char_buff);

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ get_subject ^^^^*/

#pragma subtitle("get_title()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv get_title vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| void get_title (char *title_ptr) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Prompts the user to enter title; gets user input, edits to record |
| format, and copies to title_ptr. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| NOTES |
| ~~~~~ |
| Uses macros defined in Videocat and MSC extensions. May not be portable |
| accross operating systems and compilers. String functions declared |
| in string.h. |
| |
| |
| |
+----------------------------------------------------------------------------*/

void get_title (title_ptr)

char *title_ptr; /* ptr to place to store year */

{
USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
extern void editLdata(); /* func to edit data to record format */
HVIO hvio = 0; /* video handle */
char input_title [INPUTLENGTH]; /* title input by user */
extern void window(); /* func opens screen window */

char_buff = (char *) calloc (1, 0x100);
clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,20,LWHITE,BLUE);
window (6,78,9,14,BLACK,BLACK);
window (4,76,8,13,BLACK,WHITE);
sprintf (char_buff, "Please enter requested data....");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,11,9,hvio);
set_border (BLUE); /* set screen border color */
VioSetCurPos (22,0,hvio); /* position cursor */
printf (" Title -> "); /* prompt user to enter title */
gets (input_title); /* get user input */
editLdata (input_title, TITLELENGTH); /* edit user input */
strcpy (title_ptr, input_title); /* copy title to destination */
set_border (BLACK);
free (char_buff);

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ get_title ^^^^*/

#pragma subtitle("get_year()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv get_year vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| void get_year (char *year_ptr) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Prompts the user to enter year; gets user input, edits to record |
| format, and copies to year_ptr. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| NOTES |
| ~~~~~ |
| Uses macros defined in Videocat and MSC extensions. May not be portable |
| accross operating systems and compilers. Uses string functions declared |
| in string.h. |
| |
| |
| |
+----------------------------------------------------------------------------*/

void get_year (year_ptr)

char *year_ptr; /* destination for year */

{

USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
extern void editRdata(); /* func to edit input to record format */
HVIO hvio = 0; /* video handle */
char input_year [INPUTLENGTH]; /* user year input */
extern void window(); /* func opens screen window */

char_buff = (char *) calloc (1, 0x100);
clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,20,LWHITE,BLUE);
window (6,78,9,14,BLACK,BLACK);
window (4,76,8,13,BLACK,WHITE);
sprintf (char_buff, "Please enter requested data....");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,11,9,hvio);
set_border (BLUE); /* set screen border color */
VioSetCurPos (22,0,hvio); /* position cursor */
printf (" Year -> "); /* prompt user to enter year */
gets (input_year); /* get user input */
editRdata (input_year, YEARLENGTH); /* edit input to record format */
strcpy (year_ptr, input_year); /* copy year to destination */
set_border (BLACK);
free (char_buff);

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ get_year ^^^^*/

#pragma subtitle("has_color()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv has_color vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| int has_color() |
| |
| FUNCTION |
| ~~~~~~~~ |
| Determine if the host unit is configured to display colors on the |
| video output. |
| |
| |
| RETURNS |
| ~~~~~~~ |
| 1 if the host is configured for color display, 0 if not. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Used to test for color capability before changing video attributes. |
| Uses VioGetConfig, an MSC extension which may not be portable accross |
| operating systems and compilers. |
| |
+----------------------------------------------------------------------------*/

int has_color() /* func determines if host has color display */

{
VIOCONFIGINFO vioinConfig;
USHORT usReserved = 0;
HVIO hvio;

#ifndef NOCOLOR

VioGetConfig (usReserved, &vioinConfig, hvio);
if (vioinConfig.display == 0)
return 0;
else return 1;

#endif

#ifdef NOCOLOR /* macro for testing monochome mode on color display */

return 0;

#endif
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ has_color ^^^^*/

#pragma subtitle("in_order()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv in_order vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| int in_order (FILE *workf_ptr, FILE *basef_ptr, |
| struct MOVIETRANS *tree_ptr, |
| struct MOVIETRANS *base_buff, int count) |
| |
| |
| FUNCTION |
| ~~~~~~~~ |
| Recursive function performs in order traversal of binary tree of |
| transactions, compares each transaction to the next record in the |
| old base file, and writes new records to the work file as appropriate. |
| |
| RETURNS |
| ~~~~~~~ |
| Updated number of records processed if successful, FALSE if no |
| records processed. |
| |
| |
| NOTES |
| ~~~~~ |
| |
| Uses MSC extensions and may not be portable. |
| |
| |
| |
| |
+----------------------------------------------------------------------------*/


int in_order (workf_ptr, basef_ptr, tree_ptr, base_buff, count)

struct MOVIETRANS *base_buff; /* transaction buffer */
FILE *basef_ptr; /* ptr to base file */
int count; /* counter */
struct MOVIETRANS *tree_ptr; /* ptr to binary tree of adds/deletes */
FILE *workf_ptr; /* ptr to work file */
{

USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
HVIO hvio = 0; /* video handle */
extern char pause(); /* func waits for user */
struct MOVIERECORD *rec_ptr; /* pointer to data record */
extern int trans_comp(); /* func compares transactions */

char_buff = (char *) calloc (1, 0x100);

if (tree_ptr != NULL) /* if pointer to tree is not a null pointer */
{
/* recursive call to process left subtree of transactions */

if (!(count = in_order (workf_ptr, basef_ptr, tree_ptr->ltransnode,
base_buff, count)))
return FALSE; /* if left subtree not sucessfully processed, abort */

/* process a node in the tree */
{
if ((tree_ptr->transaction == 'A') || (tree_ptr->transaction == 'D'))
{ /* if transaction is an add or delete */


/* if base buffer is empty, read a record from the base file */

if (base_buff->transaction == '\0') /* if base buffer is empty */
{ /* read a record from the base file */
if ((fread ((char *)&base_buff->moviedata,
sizeof (struct MOVIERECORD),
1, basef_ptr)) != 1) /* if read is unsuccessful - */
{
if (feof (basef_ptr)) /* - and if eof (normal condition) - */
base_buff->transaction = 'E'; /* - code base buffer for EOF */
else /* otherwise read failure is abnormal - */
{
fcloseall(); /* - close all files */
printf ("\n Error in reading base file.\n"); /* - warn user */
pause(); /* - wait for user */
return FALSE; /* - abort */
}
}
else
{
base_buff->transaction = 'B'; /* otherwise code for base rec */
sprintf (char_buff, "%4d ", count++);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,11,50,hvio);
}
}


/* if base buffer has base record, write to workfile from */
/* base buffer or from current node, whichever is lower */

if (base_buff->transaction == 'B') /* if base buff has base rec code */
{
while (((trans_comp (base_buff, tree_ptr)) < 0) /* while base */
&& (base_buff->transaction == 'B')) /* record is lower - */
{ /* write base record to workfile */
if ((fwrite ((char *)&base_buff->moviedata,
sizeof (struct MOVIERECORD),
1, workf_ptr)) != 1) /* if write unsuccessful */
{
fcloseall(); /* close all files */
printf ("\n Error in writing to work file.\n"); /* warn user */
pause(); /* wait for user */
return FALSE; /* abort */
} /* read a new base record into the base buffer */
if ((fread ((char *)&base_buff->moviedata,
sizeof (struct MOVIERECORD),
1, basef_ptr)) != 1) /* if read unsuccessful - */
{
if (feof (basef_ptr)) /* and if EOF (normal condition) */
base_buff->transaction = 'E'; /* code base buffer for EOF */
else /* otherwise read error is abnormal - */
{
fcloseall(); /* close all files */
printf ("\n Error in reading base file.\n"); /* warn user */
pause(); /* wait for user */
return FALSE; /* abort */
}
} /* otherwise code base buff for base record */
else
{
base_buff->transaction = 'B'; /* otherwise code for base rec */
sprintf (char_buff, "%4d ", count++);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,11,50,hvio);
}
}
if (((trans_comp (base_buff, tree_ptr)) > 0) /* if base record */
&& (base_buff->transaction == 'B'))/* greater than node trans*/
{
if (tree_ptr->transaction == 'D') /* if the node trans is delete */
{
rec_ptr = &tree_ptr->moviedata; /* set rec pointer */
printf ("\n Cannot delete %s - existing record not found.\n",
rec_ptr->title); /* warn user no match */
}
if (tree_ptr->transaction == 'A') /* if the node trans is add */
if ((fwrite ((char *)&tree_ptr->moviedata,
sizeof (struct MOVIERECORD),
1, workf_ptr)) != 1) /* write the node trans to work file */
{ /* if write unsuccessful */
fcloseall(); /* close all files */
printf ("\n Error in writing to work file.\n"); /* warn user */
pause(); /* wait for user */
return FALSE; /* abort */
}
}

/* if node trans equals base rec and is a delete, */
/* discard the base rec and write nothing to the work file */
/* if node trans is an add, save the base rec */

if (((trans_comp (base_buff, tree_ptr)) == 0) /* if base rec = */
&& (base_buff->transaction == 'B')) /* current node rec */
{
if (tree_ptr->transaction == 'D') /* if node rec is a delete */
base_buff->transaction = '\0'; /* trash the base rec */
else /* otherwise add duplicates existing record, don't process */
{ /* warn user of duplication */
rec_ptr = &tree_ptr->moviedata; /* set up ptr to data rec */
printf ("\n Cannot add %s - duplicates existing record\n",
rec_ptr->title);
if ((fwrite ((char *)&base_buff->moviedata,
sizeof (struct MOVIERECORD),
1, workf_ptr)) != 1) /* write base rec to workfile */
{ /* if write unsuccessful - */
fcloseall(); /* close all files */
printf ("\n Error in writing to work file.\n"); /* warn user */
pause(); /* wait for user */
return FALSE; /* abort */
} /* if write successful - */
base_buff->transaction = '\0'; /* code base buff empty */
}
}
}
/* if base file EOF condition, write add trans to workfile */

if ((base_buff->transaction == 'E') /* if base buff coded EOF */
&& (tree_ptr->transaction == 'A')) /* and current node coded add */
{ /* write to the work file from the current node */
if ((fwrite ((char *)&tree_ptr->moviedata,
sizeof (struct MOVIERECORD),
1, workf_ptr)) != 1) /* if write unsuccessful - */
{
fcloseall(); /* close all files */
printf ("\n Error in writing to work file.\n"); /* warn user */
pause(); /* wait for user */
return FALSE; /* abort */
}
}
if ((base_buff->transaction == 'E') /* if base buff coded EOF */
&& (tree_ptr->transaction == 'D')) /* and current node coded del */
{
rec_ptr = &tree_ptr->moviedata; /* set up ptr to data rec */
printf ("\n Cannot delete %s - existing record not found.\n",
rec_ptr->title);
}
}
}

/* recursive call to process right subtree of transactions */


if (!(count = in_order (workf_ptr, basef_ptr, tree_ptr->rtransnode,
base_buff, count)))
{
DosFreeSeg (tree_ptr->sel);
return FALSE; /* if left subtree not sucessfully processed, abort */
}
else
DosFreeSeg (tree_ptr->sel);

}
free (char_buff);
return count; /* successful exit */

}
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ in_order ^^^^*/

#pragma subtitle("lbl_hp_box()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv lbl_hp_box vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| void lbl_hp_box (FILE *print_pointer, int start_row, int start_column) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Sends command to printer stream in Hewlett Packard Printer Control |
| language to print a label box starting at start_row and start_column. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| NOTES |
| ~~~~~ |
| Compatible only with HP Laserjet II and other printers which recognize |
| Hewlett Packard Printer Control Language. |
| |
| |
+----------------------------------------------------------------------------*/


void lbl_hp_box (print_pointer, start_row, start_column)
FILE *print_pointer;
int start_row;
int start_column;
{
int row;
int column;
int count;
row = start_row;
column = start_column;
lbl_hp_set_cursor (print_pointer, row, column);
fprintf (print_pointer, "\x0C9");
for (count = 0; count < 4; count++)
fprintf (print_pointer, "\x0CD");
fprintf (print_pointer, "\x0CD");
for (count = 0; count < 40; count++)
fprintf (print_pointer, "\x0CD");
fprintf (print_pointer, "\x0CB");
for (count = 0; count < 4; count++)
fprintf (print_pointer, "\x0CD");
fprintf (print_pointer, "\x0D1");
for (count = 0; count < 40; count++)
fprintf (print_pointer, "\x0CD");
fprintf (print_pointer, "\x0BB");

row = row + 1;
lbl_hp_set_cursor (print_pointer, row, column);
fprintf (print_pointer, "\x0BA");
for (count = 0; count < 4; count++)
fprintf (print_pointer, "\x020");
fprintf (print_pointer, "\x020");
for (count = 0; count < 40; count++)
fprintf (print_pointer, "\x020");
fprintf (print_pointer, "\x0BA");
for (count = 0; count < 4; count++)
fprintf (print_pointer, "\x020");
fprintf (print_pointer, "\x0B3");
for (count = 0; count < 40; count++)
fprintf (print_pointer, "\x020");
fprintf (print_pointer, "\x0BA");

row = row + 1;
lbl_hp_set_cursor (print_pointer, row, column);
fprintf (print_pointer, "\x0CC");
for (count = 0; count < 4; count++)
fprintf (print_pointer, "\x0CD");
fprintf (print_pointer, "\x0D1");
for (count = 0; count < 40; count++)
fprintf (print_pointer, "\x0CD");
fprintf (print_pointer, "\x0B9");
for (count = 0; count < 4; count++)
fprintf (print_pointer, "\x020");
fprintf (print_pointer, "\x0B3");
for (count = 0; count < 40; count++)
fprintf (print_pointer, "\x020");
fprintf (print_pointer, "\x0BA");

row = row + 1;
lbl_hp_set_cursor (print_pointer, row, column);
fprintf (print_pointer, "\x0BA");
for (count = 0; count < 4; count++)
fprintf (print_pointer, "\x020");
fprintf (print_pointer, "\x0B3");
for (count = 0; count < 40; count++)
fprintf (print_pointer, "\x020");
fprintf (print_pointer, "\x0BA");
for (count = 0; count < 4; count++)
fprintf (print_pointer, "\x020");
fprintf (print_pointer, "\x0B3");
for (count = 0; count < 40; count++)
fprintf (print_pointer, "\x020");
fprintf (print_pointer, "\x0BA");

row = row + 1;
lbl_hp_set_cursor (print_pointer, row, column);
fprintf (print_pointer, "\x0BA");
for (count = 0; count < 4; count++)
fprintf (print_pointer, "\x020");
fprintf (print_pointer, "\x0B3");
for (count = 0; count < 40; count++)
fprintf (print_pointer, "\x020");
fprintf (print_pointer, "\x0BA");
for (count = 0; count < 4; count++)
fprintf (print_pointer, "\x020");
fprintf (print_pointer, "\x0B3");
for (count = 0; count < 40; count++)
fprintf (print_pointer, "\x020");
fprintf (print_pointer, "\x0BA");

row = row + 1;
lbl_hp_set_cursor (print_pointer, row, column);
fprintf (print_pointer, "\x0C8");
for (count = 0; count < 4; count++)
fprintf (print_pointer, "\x0CD");
fprintf (print_pointer, "\x0CF");
for (count = 0; count < 40; count++)
fprintf (print_pointer, "\x0CD");
fprintf (print_pointer, "\x0CA");
for (count = 0; count < 4; count++)
fprintf (print_pointer, "\x0CD");
fprintf (print_pointer, "\x0CF");
for (count = 0; count < 40; count++)
fprintf (print_pointer, "\x0CD");
fprintf (print_pointer, "\x0BC");
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ lbl_hp_box ^^^^*/


#pragma subtitle("lbl_hp_line_printer()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv lbl_hp_line_printer vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| void lbl_hp_line_printer (FILE *print_pointer) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Sends command to printer stream in Hewlett Packard Printer Control |
| language to set font to portrait line printer. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| NOTES |
| ~~~~~ |
| Compatible only with HP Laserjet II and other printers which recognize |
| Hewlett Packard Printer Control Language. |
| |
| |
+----------------------------------------------------------------------------*/


void lbl_hp_line_printer (print_pointer)
FILE *print_pointer;
{
fprintf (print_pointer,
"\x01B&l0O" /* portrait orientation */
"\x01B(10U" /* PC-8 Symbol Set */
"\x01B(s0P" /* fixed spacing */
"\x01B(s16.6H" /* 16.6 cpi pitch */
"\x01B(s8.5V" /* 8.5 point height */
"\x01B&l8D" /* 8 lpi line spacing */
"\x01B(s0S" /* upright style */
"\x01B(s0B" /* medium stroke weight */
"\x01B(s0T"); /* Line Printer typeface */
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ lbl_hp_line_printer ^^^^*/

#pragma subtitle("lbl_hp_print()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv lbl_hp_print vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| struct LABELDATA *lbl_hp_print(LABELDATA *lbltree_node, |
| FILE *print_pointer) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Prints labels from an in order search of the binary tree pointed to by |
| *lbltree_node through the printer stream pointed to by print_pointer. |
| |
| RETURNS |
| ~~~~~~~ |
| Returns a pointer to a record containing labeling status (loc1 for which |
| label is currently being printed and # of lines printed). Return value |
| is used by calling module to complete current label after tree completed. |
| |
| NOTES |
| ~~~~~ |
| Calls other functions which use MSC extensions and may not be portable. |
| Calls itself recursively until the tree is completely traversed. |
| Intended for HP Laserjet and compatibles only. |
| |
+----------------------------------------------------------------------------*/

struct LABELDATA *lbl_hp_print(lbltree_node, print_pointer, run_number)

struct LABELNODE *lbltree_node;
FILE *print_pointer;
int run_number; /* number of label run */


{

static char current_loc [LOCLENGTH]; /* current loc1 */
static int current_run; /* number of current label run */
static int label_count = 0; /* labels printed */
static struct LABELDATA label_status; /* label status */
static int print_count = 0; /* lines printed */


if (current_run != run_number)
{
label_count = 0;
print_count = 0;
current_loc[0] = '\0';
current_run = run_number;
}

if (lbltree_node != NULL) /* if tree pointer is not null pointer, */
{ /* process left subtree first */
lbl_hp_print (lbltree_node->lnode, print_pointer, run_number);
/* recursive invocation */
{
/* if no lines have been printed on the current label */
/* or */
/* if lines have already been printed on the current label */
/* and the current node is a new loc1 - */
/* then */
/* prepare a new label for printing */

if ((!(print_count))
|| ((print_count) && (strcmp (lbltree_node->loc1, current_loc))))
{
if (label_count > 12) /* if page is full */
{
fprintf (print_pointer, "\f"); /* page eject */
label_count = 0; /* reset label count */
}
label_count++; /* increment label count */
print_count = 0; /* reset line count */
lbl_hp_box (print_pointer, (6 * (label_count - 1)), 0);
lbl_hp_set_cursor (print_pointer, ((6 * (label_count - 1)) + 1), 10);
fprintf (print_pointer, "Cassette Number: %s", lbltree_node->loc1);
print_count++;
}

/* in all cases - */

{
strcpy (current_loc, lbltree_node->loc1); /* get current loc1 from */
/* current node */
if (print_count < 3) /* if fewer than 4 lines */
lbl_hp_set_cursor (print_pointer,
((6 * (label_count - 1)) + print_count + 2),
1);
else
lbl_hp_set_cursor (print_pointer,
((6 * (label_count - 1)) + print_count - 2),
47);
fprintf (print_pointer, "%s %s",
lbltree_node->loc2,
lbltree_node->title);
print_count++; /* increment line count */
if (print_count > 6)
print_count = 0;
}
}
lbl_hp_print (lbltree_node->rnode, print_pointer, run_number);
DosFreeSeg (lbltree_node->sel); /* done with current node - free memory */
/* right subtree next*/
}

/* record status of current label and return to calling module */

*label_status.loc1 = (char *)(current_loc); /* pointer to current loc1 */
label_status.line_count = (int *)&print_count; /* # of lines printed */
label_status.label_count = (int *)&label_count;
return (&label_status); /* return values */

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ lbl_hp_print ^^^^*/

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv lbl_hp_reset vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| void lbl_hp_reset (FILE *print_pointer) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Sends command to printer stream in Hewlett Packard Printer Control |
| language to reset printer to user default settings. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| NOTES |
| ~~~~~ |
| Compatible only with HP Laserjet II and other printers which recognize |
| Hewlett Packard Printer Control Language. |
| |
| |
+----------------------------------------------------------------------------*/


void lbl_hp_reset (print_pointer)
FILE *print_pointer;
{
fprintf (print_pointer, "\x01BE");
}


/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ lbl_hp_reset ^^^^*/

#pragma subtitle("lbl_hp_set_cursor()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv lbl_hp_set_cursor vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| void lbl_hp_set_cursor (FILE * print_pointer, int row, int column) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Sends command to printer stream in Hewlett Packard Printer Control |
| language to set printer cursor to row and column + 20 col margin. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| NOTES |
| ~~~~~ |
| Compatible only with HP Laserjet II and other printers which recognize |
| Hewlett Packard Printer Control Language. |
| |
| |
+----------------------------------------------------------------------------*/


void lbl_hp_set_cursor (print_pointer, row, column)
FILE *print_pointer;
int row;
int column;
{
char row_command[80];
char column_command[80];
char num_string[80];

strcpy (row_command, "\x01B&a");
itoa (row, num_string, 10);
strcat (row_command, num_string);
strcat (row_command, "R");
fprintf (print_pointer, row_command);

strcpy (column_command, "\x01B&a");
itoa ((column + 20), num_string, 10);
strcat (column_command, num_string);
strcat (column_command, "C");
fprintf (print_pointer, column_command);

}
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ lbl_hp_set_cursor ^^^^*/

#pragma subtitle("lbl_loc_comp()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv lbl_loc_comp vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| #include |
| int lbl_loc_comp (struct LABELNODE loc_node1, |
| struct LABELNODE loc_node2) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Compares the records pointed to by loc_node1 and loc_node2, first by loc1 |
| (in ASCII collating sequence), then by loc2 if loc1's are equal, |
| then by titles if both loc1 and loc2 are equal. |
| |
| RETURNS |
| ~~~~~~~ |
| less than zero if rec1 is less than rec2 |
| zero if rec1 is equal to rec2 |
| greater than zero if rec1 is greater than rec2 |
| |
| NOTES |
| ~~~~~ |
| Comparison is used to sort records into location sequence. |
| |
+----------------------------------------------------------------------------*/

int lbl_loc_comp (loc_node1, loc_node2)

struct LABELNODE *loc_node1, *loc_node2; /* ptrs to two label nodes */

{
int comp_result; /* result of comparison */

comp_result = strcmp (loc_node1->loc1, loc_node2->loc1); /* compare loc1 */

if (comp_result == 0) /* if same, then compare loc2) */
comp_result = strcmp (loc_node1->loc2, loc_node2->loc2);
if (comp_result == 0) /* if still same, then compare titles */
comp_result = strcmp (loc_node1->title, loc_node2->title);
return (comp_result); /* return result of comparison */

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ lbl_loc_comp ^^^^*/

#pragma subtitle("lbl_make_labels()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv lbl_make_labels vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| void lbl_make_labels (char *base_file_id) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Prompts user to enter range of cassetes to be labeled, calls func to get |
| data from base_file_id, gets printer type, calls func to print labels. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| NOTES |
| ~~~~~ |
| Calls other functions which use MSC extensions and may not be portable. |
| |
| |
+----------------------------------------------------------------------------*/


void lbl_make_labels (base_file_id)
char *base_file_id;
{
static int a_run_number = 0; /* number times this func run */
USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
extern void clear_screen(); /* func to clear screen */
int count; /* counter */
char *current_loc; /* current location */
extern void get_loc(); /* func gets location from user */
char go_ahead = ' '; /* quit or go ahead signal from user */
static int h_run_number = 0; /* number times this func run */
HVIO hvio = 0; /* video handle */
struct LABELNODE *lbltree_root = NULL; /* root for binary tree */
struct LABELDATA *label_data; /* struct holds label data */
extern struct LABELDATA *lbl_hp_print(); /* func prints labels on HPLJ */
extern void lbl_hp_line_printer(); /* func sets HPLJ line printer font */
extern void lbl_hp_reset(); /* func resets HPLJ to user default settings */
extern struct LABELNODE *lbl_search(); /* func gets data for labels */
extern struct LABELDATA *lbl_print(); /* func prints labels std printer */
char min_loc [LOCLENGTH]; /* lowest cassette to label */
char max_loc [LOCLENGTH]; /* highest cassette to label */
extern char prnopt(); /* func gets printer type */
char printer_type = '\0'; /* code for printer type */
int print_count; /* print counter */
int print_handle; /* file handle for printer */
FILE *print_pointer; /* stream for printer */
extern char qpause(); /* func pauses for go-ahead or quit */
extern void set_border(); /* func sets display border color */

char_buff = (char *) calloc (1, 0x100);
clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,20,LWHITE,BLUE);
window (6,78,9,14,BLACK,BLACK);
window (4,76,8,13,BLACK,WHITE);
set_border (BLUE); /* set screen border color */

sprintf(char_buff,
" Enter the range of cassettes for which labels are to be printed. ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,9,6,hvio);
sprintf(char_buff,
" It is not recommended that the range specified for a single run of ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,10,6,hvio);
sprintf(char_buff,
" this function exceed 200 cassettes, so that the amount of RAM which ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,11,6,hvio);
sprintf(char_buff,
" must be allocated for sorting will not exceed available memory. ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,12,6,hvio);
VioSetCurPos (22,0,hvio); /* position cursor */
pause();

get_loc (min_loc, "Lowest cassette to label "); /* get cassette range */
get_loc (max_loc, "Highest cassette to label");

printer_type = prnopt(); /* get printer type */

clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,20,LWHITE,BLUE);
window (6,78,9,14,BLACK,BLACK);
window (4,76,8,13,BLACK,WHITE);
set_border (BLUE); /* set screen border color */

sprintf(char_buff,
" Searching for and sorting data for labels... ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,10,6,hvio);
VioSetCurPos (22,0,hvio); /* position cursor */

lbltree_root = lbl_search (base_file_id, min_loc, max_loc); /* get data */

print_handle = open ("PRN", O_WRONLY); /* open file handle */
if (print_handle == -1) /* test for open error */
perror ("open failed on PRN");
print_pointer = fdopen (print_handle, "w"); /* associate stream */
if (print_pointer == NULL) /* test for error */
perror ("fopen failed on print_handle");

switch (printer_type) /* selection according to printer type */
{
case 'A': /* if ASCII printer */

clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,20,LWHITE,BLUE);
window (6,78,9,14,BLACK,BLACK);
window (4,76,8,13,BLACK,WHITE);
set_border (BLUE); /* set screen border color */

sprintf(char_buff,
" This routine assumes a standard printer, 10 cpi, 6 lpi, controlled ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,9,6,hvio);
sprintf(char_buff,
" by ASCII commands, continuous form 3.5 x 15/16\" labels, 1-wide,");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,10,6,hvio);
sprintf(char_buff,
" with first label positioned so that the first print position would ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,11,6,hvio);
sprintf(char_buff,
" be just within the upper left corner of the first label. ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,12,6,hvio);
VioSetCurPos (22,0,hvio); /* position cursor */
go_ahead = qpause();
if (go_ahead == 'Q')
{
fcloseall();
return;
}

clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,20,LWHITE,BLUE);
window (6,78,9,14,BLACK,BLACK);
window (4,76,8,13,BLACK,WHITE);
set_border (BLUE); /* set screen border color */

sprintf(char_buff,
" Printing labels... ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,10,26,hvio);
VioSetCurPos (22,0,hvio); /* position cursor */

a_run_number++; /* increment run number */
label_data = lbl_print (lbltree_root, print_pointer, a_run_number);
print_count = *label_data->line_count;
current_loc = *label_data->loc1;
if (print_count) /* if lines printed on last label, finish it */
{
for (count = print_count; count <= 4; count++)
{
fprintf (print_pointer, "%c\n", current_loc[count]);
print_count++;
}
while (print_count < 6)
{
fprintf (print_pointer, "\n");
print_count++;
}
print_count = 0;
}
break;

case 'H': /* if HP Laserjet */

sprintf(char_buff,
" This routine assumes a Hewlett Packard Laserjet II printer, ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,9,6,hvio);
sprintf(char_buff,
" printing on 8-1/2 x 11\" label paper, uncut, 1 label per page, ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,10,6,hvio);
sprintf(char_buff,
" (Hewlett Packard Part Number 92285W, Avery Part Number 5353, ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,11,6,hvio);
sprintf(char_buff,
" or equivalent). Cut labels to size after printing. ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,12,6,hvio);
VioSetCurPos (22,0,hvio); /* position cursor */
go_ahead = qpause();
if (go_ahead == 'Q')
{
fcloseall();
return;
}

clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,20,LWHITE,BLUE);
window (6,78,9,14,BLACK,BLACK);
window (4,76,8,13,BLACK,WHITE);
set_border (BLUE); /* set screen border color */

sprintf(char_buff,
" Printing labels... ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,10,26,hvio);
VioSetCurPos (22,0,hvio); /* position cursor */

h_run_number++; /* increment run number */
lbl_hp_reset (print_pointer);
lbl_hp_line_printer (print_pointer);
label_data = lbl_hp_print (lbltree_root, print_pointer, h_run_number);
lbl_hp_reset (print_pointer);
break;

default:

printf (" Error in printer type code.\n");
pause();
return;
}

free (char_buff);

if (fclose (print_pointer) == EOF) /* close stream */
perror ("fclose failed on print_pointer"); /* test for error */

}
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ lbl_make_labels ^^^^*/

#pragma subtitle("lbl_print()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv lbl_print vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| struct LABELDATA *lbl_print(LABELDATA *lbltree_node, FILE *print_pointer) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Prints labels from an in order search of the binary tree pointed to by |
| *lbltree_node through the printer stream pointed to by print_pointer. |
| |
| RETURNS |
| ~~~~~~~ |
| Returns a pointer to a record containing labeling status (loc1 for which |
| label is currently being printed and # of lines printed). Return value |
| is used by calling module to complete current label after tree completed. |
| |
| NOTES |
| ~~~~~ |
| Calls other functions which use MSC extensions and may not be portable. |
| Calls itself recursively until the tree is completely traversed. |
| |
| |
+----------------------------------------------------------------------------*/

struct LABELDATA *lbl_print(lbltree_node, print_pointer, run_number)

struct LABELNODE *lbltree_node; /* ptr to tree structure */
FILE *print_pointer; /* stream for printer */
int run_number; /* number of label run */
{

int count; /* counter */
static int print_count = 0; /* lines printed */
static char current_loc [LOCLENGTH]; /* current loc1 */
static struct LABELDATA label_status; /* label status */
static int current_run; /* number of current label run */

if (current_run != run_number)
{
count = 0;
print_count = 0;
current_loc[0] = '\0';
current_run = run_number;
}
if (lbltree_node != NULL) /* if tree pointer is not null pointer, */
{ /* process left subtree first */
lbl_print (lbltree_node->lnode, print_pointer, current_run);
/* recursive invocation */
{
lbltree_node->title[30] = '\0'; /* truncate title for label width */

/* if lines have already been printed on the current label */
/* and the current node is a new loc1 - */

if ((print_count) && (strcmp (lbltree_node->loc1, current_loc)))
{
for (count = print_count; count <= 4; count++) /* print the rest of */
{ /* the location i.d. */
fprintf (print_pointer, "%c\n", current_loc[count]);
print_count++;
}
while (print_count < 6) /* space to the begin-*/
{ /* ning of the next */
fprintf (print_pointer, "\n"); /* label */
print_count++;
}
print_count = 0; /* reset line count */
}

/* in all cases - */

{
strcpy (current_loc, lbltree_node->loc1); /* get current loc1 from */
/* current node */
if (print_count >= 5) /* if label is full, */
{
fprintf (print_pointer, "\n"); /* skip to next label */
print_count = 0; /* and reset line count */
}
if (print_count < 4) /* if fewer than 4 lines */
{ /* have been printed - */
fprintf (print_pointer, "%c %s\n", /* print the next char in */
current_loc[print_count], lbltree_node->title); /* loc1 i.d. & */
} /* title */
else /* if 4 or more lines */
{ /* have been printed - */
fprintf (print_pointer, "%c %s\n", /* just print title */
' ', lbltree_node->title);
}
print_count++; /* increment line count */
}
}
lbl_print (lbltree_node->rnode, print_pointer, current_run);
DosFreeSeg (lbltree_node->sel); /* done with current node - free memory */
/* right subtree next*/
}

/* record status of current label and return to calling module */

*label_status.loc1 = (char *)(current_loc); /* pointer to current loc1 */
label_status.line_count = (int *)&print_count; /* # of lines printed */
return (&label_status); /* return values */

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ lbl_print ^^^^*/

#pragma subtitle("lbl_search()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv lbl_search vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| void lbl_search (char *base_file_id, *min_loc, *max_loc); |
| |
| FUNCTION |
| ~~~~~~~~ |
| Searches the file whose name is pointed to by base_file_id for records |
| with a loc1 greater than or equal to min_loc and less than or equal |
| to max_loc, and for each such record create a label node and insert it |
| into a binary tree of label nodes. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| NOTES |
| ~~~~~ |
| Calls a number of functions defined in videocat.c which use nonstandard |
| C86Plus extensions and may not be portable accross compilers and |
| operating systems. |
| |
| |

| |
+----------------------------------------------------------------------------*/

struct LABELNODE *lbl_search (base_file_id, min_loc, max_loc)

char *base_file_id; /* path and file name of base file */
char *min_loc; /* minimum location */
char *max_loc; /* maximum location */

{

FILE *basef_pointer; /* stream pointer for base file */
struct MOVIERECORD *base_record; /* record read from base file */
int max_comp_result; /* result of string comparison */
int min_comp_result; /* result of string comparison */
char *iobuf; /* buffer for file i/o */
extern struct LABELNODE *lbl_tree_insert(); /* func inserts node in tree */
struct LABELNODE *lbltree_root = NULL; /* root of a tree structure */
struct LABELNODE *label_record; /* record to contain search key */

/* allocate memory for records */
base_record = (struct MOVIERECORD *)calloc (1,sizeof (struct MOVIERECORD));
label_record = (struct LABELNODE *)calloc (1,sizeof (struct LABELNODE));
iobuf = calloc (1, BIGBUFF);


if ((basef_pointer = fopen (base_file_id, "rb")) == NULL) /* open base file*/
{ /* if unsuccessful - */
printf ("\nUnable to open base file\n"); /* warn user */
pause(); /* wait for user */
return (lbltree_root); /* return root of binary tree */
}

setvbuf (basef_pointer, iobuf,_IOFBF, BIGBUFF); /* big buffer for file i/o */


while (!(feof (basef_pointer))) /* loop while not end of file - */
{

if ((fread ((char *)base_record, sizeof (struct MOVIERECORD),
1, basef_pointer)) != 1) /* read a record from the base file */
{ /* if read error - */
if (!(feof(basef_pointer))) /* - and not end of file (normal term) */
{
printf ("\nError in reading base file\n"); /* warn user */
pause(); /* wait for user */
fcloseall(); /* close all files */
return (lbltree_root); /* return root of binary tree */
}
else break; /* otherwise (normal) exit loop and continue */
}
min_comp_result = strcmp (base_record->loc1, min_loc); /* compare loc1 */
max_comp_result = strcmp (base_record->loc1, max_loc); /* to min & max */
if ((min_comp_result >= 0) && (max_comp_result <= 0)) /* if in range -*/
{
strcpy (label_record->loc1, base_record->loc1); /* copy loc1, loc2 */
strcpy (label_record->loc2, base_record->loc2); /* and title to node*/
strcpy (label_record->title, base_record->title);/* and insert in */
lbltree_root = lbl_tree_insert (lbltree_root, label_record); /* tree */
}
}

/* shutdown after search completed */

free ((char *)base_record); /* free memory allocated to records */
free ((char *)label_record); /* free memory allocated to label record */
free (iobuf); /* free memory allocated to i/o buffer */

if (fclose (basef_pointer) != NULL) /* close base file stream */
printf ("\nError in closing base file\n");

return (lbltree_root); /* return root of binary tree */

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ lbl_search ^^^^*/

#pragma subtitle("lbl_tree_insert()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv lbl_tree_insert vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| struct LABELNODE *lbl_tree_insert (struct LABELNODE *lbltree_root, |
| struct LABELNODE * new_node) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Inserts a transaction pointed to by new_node into a binary tree |
| pointed to by lbltree_root. |
| |
| |
| RETURNS |
| ~~~~~~~ |
| Pointer to the root of the binary tree structure. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Memcpy() is declared in memory.h. LABELNODE is a structure defined |
| in videocat.c. |
| |
| |
| |
| |
+----------------------------------------------------------------------------*/

struct LABELNODE *lbl_tree_insert (lbltree_root, new_node)
/* insert node in lbltree */

struct LABELNODE *lbltree_root; /* root of a tree structure */
struct LABELNODE *new_node; /* ptr to a transaction */

{
int cond; /* comparison condition code */
extern int lbl_loc_comp(); /* func to compare nodes */
static int out_of_memory = FALSE;
SEL sel; /* memory block selector */

if (lbltree_root == NULL) /* if tree root is null pointer */
{
out_of_memory = DosAllocSeg ((sizeof (struct LABELNODE)),&sel,0);
if (out_of_memory)
{
printf ("Running out of memory....\n");
return (lbltree_root); /* return pointer to root */
}
lbltree_root = MAKEP (sel,0); /* make pointer out of selector */
memcpy ((char *)lbltree_root, (char *)new_node,
sizeof(struct LABELNODE)); /* copy node */
lbltree_root->sel = sel;
lbltree_root->lnode = lbltree_root->rnode = NULL; /* nodes = Null */
}
else if ((cond = lbl_loc_comp (new_node, lbltree_root)) < 0)
lbltree_root->lnode = lbl_tree_insert (lbltree_root->lnode, new_node);
else if (cond >= 0) /* if new greater than root insert new at right node */
lbltree_root->rnode = lbl_tree_insert (lbltree_root->rnode, new_node);
return (lbltree_root); /* return pointer to root */

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ lbl_tree_insert ^^^^*/

#pragma subtitle("main_menu()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv main_menu vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| void main_menu() |
| |
| FUNCTION |
| ~~~~~~~~ |
| Clears screen, opens window, draws box, and displays main menu. |
| |
| |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Calls functions using nonstanard C extensions. May not be portable |
| accross operating systems and compilers. |
| |
| |
| |
| |
+----------------------------------------------------------------------------*/

void main_menu() /* display main menu */

{
USHORT cbString; /* string byte count */
char char_buff[256]; /* string buffer */
extern void clear_screen(); /* func clears screen and sets colors */
HVIO hvio = 0; /* video handle */
extern void draw_box(); /* func draws box on screen */
extern void set_cursor(); /* func sets cursor position */
extern void window(); /* func opens window on screen display */

set_border (BLACK);
clear_screen (LWHITE, BLACK); /* clear screen & set colors */
window (10,70,3,20,WHITE,BLUE); /* open window */
draw_box ('l',11,69,3,20); /* draw box in window */

sprintf (char_buff, "MAIN MENU"); /* display menu caption */
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,5,35,hvio);

sprintf (char_buff, "A = Add a new record to the catalog.");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,8,14,hvio);

sprintf (char_buff, "C = Change an existing record in the catalog.");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,9,14,hvio);

sprintf (char_buff, "D = Delete an existing record in the catalog.");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,10,14,hvio);

sprintf (char_buff, "F = File conversion from prior version.");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,11,14,hvio);

sprintf (char_buff, "L = Label maker.");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,12,14,hvio);

sprintf (char_buff, "R = Review current changes not yet updated.");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,13,14,hvio);

sprintf (char_buff, "S = Search catalog.");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,14,14,hvio);

sprintf (char_buff, "T = Tally statistics for catalog content.");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,15,14,hvio);

sprintf (char_buff, "U = Update catalog with current changes.");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,16,14,hvio);

sprintf (char_buff, "W = Whole catalog listing. ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,17,14,hvio);

sprintf (char_buff, "E = Exit from program without further updating.");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,18,14,hvio);

sprintf (char_buff,"Enter code -> ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,22,10,hvio);
VioSetCurPos (22,(10 +cbString), hvio);

}
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ main_menu ^^^^*/

#pragma subtitle("name_out()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv name_out vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| void name_out (char *name_ptr) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Converts the name at name_ptr from record format ["LAST,FIRST"] to |
| output format ["FIRST LAST"]. |
| |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| NOTES |
| ~~~~~ |
| |
| Uses functions declared in string.h and trim(), a function defined |
| in videocat.c. Uses only ANSI standard functions. Should be portable. |
| |
| |
| |
+----------------------------------------------------------------------------*/

void name_out (name_ptr) /* converts name from record format */

char *name_ptr; /* ptr to name to be converted */

{
int f_count = 0; /* first name character count */
char first_name [INPUTLENGTH]; /* first name buffer */
int l_count = 0; /* last name character count */
char last_name [INPUTLENGTH]; /* last name buffer */
int max; /* maximum # chars to be scanned */
extern void trim(); /* func trims lead & trail whitespace*/
int w_count = 0; /* whole name character count */

max = strlen (name_ptr); /* don't scan more chars than in name */

/* extract last name */

while ((w_count <= max) && (name_ptr [w_count] != ',')) /* while no comma- */
{
last_name [l_count] = name_ptr [w_count]; /* copy chars to last name */
l_count++;
w_count++;
}
last_name [l_count] = '\0'; /* append null terminator */
trim (last_name); /* trim last name */

/* extract first name */

w_count++; /* skip over comma */
while (w_count <= max) /* for rest of chars - */
{
first_name [f_count] = name_ptr [w_count]; /* - copy to first name */
f_count++;
w_count++;
}
first_name [f_count] = '\0'; /* append null terminator */
trim (first_name); /* trim first name */

/* assemble converted name */

strcpy (name_ptr, first_name); /* copy first name to name */
strcat (name_ptr, " "); /* append 1 space separator */
strcat (name_ptr, last_name); /* append last name */
trim (name_ptr); /* trim name */

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ name_out ^^^^*/

#pragma subtitle("outopt()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv outopt vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| char outopt(); |
| |
| FUNCTION |
| ~~~~~~~~ |
| Displays menu of output options, gets user choice, and returns |
| character code for choice. |
| |
| |
| RETURNS |
| ~~~~~~~ |
| Character code for output option chosen by user. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| |
| Calls functions which use nonstandard C extensions. May not be |
| portable accross operating systems and compilers. |
| |
| |
| |
+----------------------------------------------------------------------------*/
char outopt()

{

extern void clear_screen();/* func clears screen and sets colors*/
extern void draw_box(); /* func draws box on screen */
char output_type; /* code for output type */
char response [INPUTLENGTH];/* buffer for keyboard input */
extern char search_key();
extern void set_cursor(); /* func sets cursor position */
extern void trim(); /* func trims leading & trailing whitespace */
int valid_code = FALSE; /* boolean flag for valid code */
extern void window(); /* func opens window on screen display */

/* display output option menu and get user choice */

valid_code = FALSE; /* set valid code flag to false */
while (!valid_code) /* loop until valid code selected */
{
clear_screen (LWHITE, BLACK); /* clear screen & set colors */
window (10,70,3,18,LBLUE,BLACK); /* open window */
draw_box ('l',11,69,3,18); /* draw box in window */
set_cursor (5,33,0); /* position cursor */
printf ("OUTPUT OPTIONS"); /* display menu caption */
set_cursor (10,14,0); /* move cursor */
printf ("S = Screen output (pauses when screen full)");/* print choice */
set_cursor (11,14,0); /* move cursor */
printf ("C = Continuous screen output (no pausing). ");/* print choice */
set_cursor (12,14,0); /* move cursor */

printf ("P = Printer output. "); /* print choice */
set_cursor (21, 10, 0); /* move cursor */
printf ("Enter code -> "); /* prompt user to enter choice */
gets (response); /* get user response */
trim (response); /* trim whitespace from user response */
output_type = toupper (response [0]); /* first character is code */
switch (output_type) /* select according to code */
{
case 'S' : /* screen or continuous output selected */
case 'C' :
case 'P' :
valid_code = TRUE; /* set valid code flag to true */
break; /* exit selection */

default : /* no code match */

printf ("\nINVALID CODE\n"); /* warn user */
pause(); /* wait for user */
break; /* exit selection */
}
}
return (output_type);
}
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ outopt ^^^^*/

#pragma subtitle("pause()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv pause vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| char pause(); |
| |
| FUNCTION |
| ~~~~~~~~ |
| Prompts user and pauses program execution until the user enters |
| a carriage return. |
| |
| |
| RETURNS |
| ~~~~~~~ |
| The first character entered by the user. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Used to pause program execution temporarily, permitting the user |
| to signal when ready to continue, such as after reading text |
| displayed on the screen. Although the function returns the first |
| character entered, the return value is not likely to be useful. |
| |
| |
+----------------------------------------------------------------------------*/

char pause() /* pause for user */

{
int fgetc(); /* ANSI func returns one char from stream */
char go_ahead; /* character entered by user */
int printf(); /* ANSI formatted output func */

printf (" Enter/ to continue"); /* prompt user */
go_ahead = (char)fgetc(stdin); /* wait for entry of character */
return (go_ahead); /* return character entered */

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ pause ^^^^*/

#pragma subtitle("print_rec()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv print_rec vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| void print_rec(struct MOVIERECORD *rec_ptr, FILE *print_pointer) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Prints the data contained in the record pointed to by rec_ptr |
| on the printer via the stream print_pointer. |
| |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Uses a number of functions defined in videocat.c. All use only |
| ANSI standard functions and should be portable. |
| |
| |
| |
| |
+----------------------------------------------------------------------------*/

void print_rec (rec_ptr, print_pointer)

struct MOVIERECORD *rec_ptr; /* ptr to a record */
FILE *print_pointer; /* ptr to printer */


{
int count; /* counter */
extern void name_out(); /* func converts name format */
extern void trim(); /* func trims lead & trail whitesp */
char star1_disp [INPUTLENGTH]; /*-----------------------*/
char star2_disp [INPUTLENGTH]; /* buffers in which the */
char star3_disp [INPUTLENGTH]; /* various elements in */
char dir_disp [INPUTLENGTH]; /* a MOVIETRANS struct */
char subj_disp [INPUTLENGTH]; /* are converted from */
char form_disp [INPUTLENGTH]; /* record format to a */
char type_disp [INPUTLENGTH]; /* display format. */
char rating_disp[INPUTLENGTH]; /*-----------------------*/
char mpaa_disp [INPUTLENGTH];


strcpy (star1_disp, rec_ptr->star1); /* get star1 name */
name_out (star1_disp); /* and convert for display */

strcpy (star2_disp, rec_ptr->star2); /* get star2 name */
name_out (star2_disp); /* and convert for display */

strcpy (star3_disp, rec_ptr->star3); /* get star3 name */
name_out (star3_disp); /* and convert for display */

strcpy (dir_disp, rec_ptr->director); /* get director name */
name_out (dir_disp); /* and convert for display */
while (strlen (dir_disp) < 24) /* pad director display name */
strcat (dir_disp, " "); /* with trailing blanks */

for (count = 0; count < CODENUMBER; count++) /* look up subject code */
if (rec_ptr->subject == codes [count]) /* if found, copy */
strcpy (subj_disp, subjects [count]); /* subject */
trim (subj_disp); /* trim subject */

for (count = 0; count < FORMNUMBER; count++) /* look up form code */
if (rec_ptr->form == codes [count]) /* if found, copy */
strcpy (form_disp, forms [count]); /* corresponding form */
trim (form_disp); /* trim form */

strcpy (type_disp, subj_disp); /* copy subject to type buffer */
strcat (type_disp, " "); /* append 1 blank space to type */
strcat (type_disp, form_disp); /* append form to type buffer */
while (strlen (type_disp) < 26) /* pad type bufer with trailing */
strcat (type_disp, " "); /* blanks to width 26 */

strcpy (mpaa_disp, " "); /* initialize mpaa as blank */
for (count = 0; count < MPAANUMBER; count++) /* look up mpaa code */
if (rec_ptr->mpaa_code == codes [count]) /* if found, copy */
strcpy (mpaa_disp, mpaa_codes [count]); /* mpaa */
trim (mpaa_disp); /* trim mpaa */
while (strlen (mpaa_disp) < 20) /* pad type bufer with trailing */
strcat (mpaa_disp, " "); /* blanks to width 20 */


for (count = 0; count < RATINGNUMBER; count++) /* look up rating */
if (rec_ptr->rating == codes [count]) /* if found copy */
strcpy (rating_disp, ratings [count]); /* corresponding rating */


/* print data in display format */
fprintf (print_pointer, " %s [%s]\n",
rec_ptr->title, rec_ptr->year);
fprintf (print_pointer, " %s%s%s\n",
type_disp, mpaa_disp, rating_disp);
fprintf (print_pointer, " Starring: %s, %s, %s\n", star1_disp,
star2_disp, star3_disp);
fprintf(print_pointer," Director: %s Cassette: %s Index: %s\n",
dir_disp, rec_ptr->loc1, rec_ptr->loc2);

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ print_rec ^^^^*/

#pragma subtitle("prnopt()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv prnopt vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| char prnopt(); |
| |
| FUNCTION |
| ~~~~~~~~ |
| Displays menu of printer options, gets user choice, and returns |
| character code for choice. |
| |
| |
| RETURNS |
| ~~~~~~~ |
| Character code for output option chosen by user. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| |
| Calls functions which use nonstandard C extensions. May not be |
| portable accross operating systems and compilers. |
| |
| |
| |
+----------------------------------------------------------------------------*/
char prnopt()

{

extern void clear_screen();/* func clears screen and sets colors*/
extern void draw_box(); /* func draws box on screen */
char output_type; /* code for output type */
char response [INPUTLENGTH];/* buffer for keyboard input */
extern char search_key();
extern void set_cursor(); /* func sets cursor position */
extern void trim(); /* func trims leading & trailing whitespace */
int valid_code = FALSE; /* boolean flag for valid code */
extern void window(); /* func opens window on screen display */

/* display output option menu and get user choice */

valid_code = FALSE; /* set valid code flag to false */
while (!valid_code) /* loop until valid code selected */
{
clear_screen (LWHITE, BLACK); /* clear screen & set colors */
window (10,70,3,18,LBLUE,BLACK); /* open window */
draw_box ('l',11,69,3,18); /* draw box in window */
set_cursor (5,33,0); /* position cursor */
printf ("PRINTER OPTIONS"); /* display menu caption */
set_cursor (10,14,0); /* move cursor */
printf ("A = ASCII (standard) printer"); ;/* print choice */
set_cursor (11,14,0); /* move cursor */
printf ("H = Hewlett Packard Laserjet II"); /* print choice */
set_cursor (21, 10, 0); /* move cursor */
printf ("Enter code -> "); /* prompt user to enter choice */
gets (response); /* get user response */
trim (response); /* trim whitespace from user response */
output_type = toupper (response [0]); /* first character is code */
switch (output_type) /* select according to code */
{
case 'A' : /* screen or continuous output selected */
case 'H' :
valid_code = TRUE; /* set valid code flag to true */
break; /* exit selection */

default : /* no code match */

printf ("\nINVALID CODE\n"); /* warn user */
pause(); /* wait for user */
break; /* exit selection */
}
}
return (output_type);
}
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ prnopt ^^^^*/

#pragma subtitle("qpause()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv qpause vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| char qpause(); |
| FUNCTION |
| ~~~~~~~~ |
| Prompts user and pauses program execution until the user enters |
| a carriage return to continue or Q to pause. |
| |
| |
| RETURNS |
| ~~~~~~~ |
| The first character entered by the user. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Used to pause program execution temporarily, permitting the user |
| to signal when ready to continue, such as after reading text |
| displayed on the screen. If the letter is Q, the return value indicates |
| that the user wishes to quit the current routine. |
| |
| |
+----------------------------------------------------------------------------*/

char qpause() /* pause for user to continue or quit */

{
char go_ahead; /* character entered by user */
char input[80]; /* input buffer */

printf (" to continue - Q to quit -> "); /* prompt user */
gets (input); /* wait for entry of character */
go_ahead = toupper(input[0]); /* convert to uppercase */
return (go_ahead); /* return character entered */

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ qpause ^^^^*/

#pragma subtitle("rec_comp()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv rec_comp vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| #include |
| int rec_comp (struct MOVIERECORD *rec1, struct MOVIERECORD *rec2) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Compares the records pointed to by rec1 and rec2, first by title |
| (in ASCII collating sequence), then by year if titles are equal. |
| |
| |
| RETURNS |
| ~~~~~~~ |
| less than zero if rec1 is less than rec2 |
| zero if rec1 is equal to rec2 |
| greater than zero if rec1 is greater than rec2 |
| |
| NOTES |
| ~~~~~ |
| Comparison is used for sorting records in alphabetical sequence by |
| title. Because of "remakes" two movies are allowed to have the same |
| title and they will be sequenced according to year of production. |
| When both title and year are the same, it is assumed that the records |
| both identify the same movie. |
| |
+----------------------------------------------------------------------------*/

int rec_comp (rec1, rec2)

struct MOVIERECORD *rec1, *rec2; /* ptrs to two records */

{
int comp_result; /* result of comparison */

if ((comp_result = strcmp (rec1->title, rec2->title)) == 0)
comp_result = strcmp (rec1->year, rec2->year);

return (comp_result);
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ rec_comp ^^^^*/

#pragma subtitle("search()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv search vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| #include |
| void search (char *base_file_id); |
| |
| FUNCTION |
| ~~~~~~~~ |
| Prompts the user for the the key to be searched for and the type of |
| output desired (continuous screen, paused screen, or printer), then |
| reads all records in the file identified by base_file_id and displays |
| each record which matches the designated key. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| NOTES |
| ~~~~~ |
| Calls a number of functions defined in videocat.c which use nonstandard |
| MSC extensions and may not be portable accross compilers and |
| operating systems. |
| |
| |
| |
+----------------------------------------------------------------------------*/

void search (base_file_id)

char *base_file_id; /* path and file name of base file */

{

FILE *basef_pointer; /* stream pointer for base file */
struct MOVIERECORD *base_record; /* record read from base file */
USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
extern void clear_screen();/* func clears screen and sets colors*/
char *comp_ptr; /* ptr to substring returned by strstr() */
int comp_result; /* result of string comparison */
extern void disp_rec();
int found; /* boolean flag for search result */
char go_ahead = ' ';/* quit or go ahead signal from user */
HVIO hvio = 0; /* video handle */
char *iobuf; /* buffer for file i/o */
int out_count = 0; /* counter for records output */
char output_type = '\0'; /* code for output type */
extern char outopt(); /* func gets user choice of output type */
extern char pause(); /* func pauses for user */
extern void print_rec(); /* func prints record on printer */
int print_handle; /* file handle for printer */
FILE *print_pointer; /* stream for printer */
extern char qpause(); /* func pauses for go-ahead or quit */
extern char search_key(); /* func gets key record for search */
struct MOVIERECORD *s_key_record; /* record to contain search key */
char s_type = '\0'; /* code for type of search */
extern void set_cursor(); /* func sets cursor position */
long time_1; /* time marker in seconds */
long time_2; /* time marker in seconds */

char_buff = (char *) calloc (1, 0x100);
/* allocate memory for records */
base_record = (struct MOVIERECORD *)calloc (1,sizeof (struct MOVIERECORD));
s_key_record = (struct MOVIERECORD *)calloc (1,sizeof (struct MOVIERECORD));
iobuf = calloc (1, BIGBUFF);

s_type = search_key (s_key_record);
if (s_type == 'E')
return;

VioSetCurPos (22,0,hvio);
output_type = outopt();
if (output_type == 'P')
{
print_handle = open ("PRN", O_WRONLY); /* open file handle */
if (print_handle == -1) /* test for open error */
perror ("open failed on PRN");
print_pointer = fdopen (print_handle, "w"); /* associate stream */
if (print_pointer == NULL) /* test for error */
{
perror ("fopen failed on print_handle");
pause(); /* wait for user */
return; /* return to main module */
}
}
/* search records in base file for key matches */

if ((basef_pointer = fopen (base_file_id, "rb")) == NULL) /* open base file*/
{ /* if unsuccessful - */
printf ("\nUnable to open base file\n"); /* warn user */
pause(); /* wait for user */
return; /* return to main module */
}

setvbuf (basef_pointer, iobuf,_IOFBF, BIGBUFF); /* big buffer for file i/o */

set_border (BLACK);
clear_screen (WHITE,BLACK);
window (0,79,0,0,LGREEN,BLACK);
VioSetCurPos (22,0,hvio);
if (output_type == 'P')
printf ("Search results being printed (printer must be ready)...");
else
printf ("Search results being displayed on screen...");

while ((!(feof (basef_pointer))) /* loop while not end of file - */
&& (go_ahead != 'Q')) /* and no quit signal from user */
{
found = FALSE; /* set found flag to false */

if ((fread ((char *)base_record, sizeof (struct MOVIERECORD),
1, basef_pointer)) != 1) /* read a record from the base file */
{ /* if read error - */
if (!(feof(basef_pointer))) /* - and not end of file (normal term) */
{
printf ("\nError in reading base file\n"); /* warn user */
pause(); /* wait for user */
fcloseall(); /* close all files */
return; /* abort */
}
else break; /* otherwise (normal) exit loop and continue */
}

switch (s_type) /* selection action according to search type code */
{
case 'T' : /* for title search */

comp_ptr = strstr (base_record->title, s_key_record->title);
if (comp_ptr != NULL) /* if search title is substring of base title */
found = TRUE; /* match has been found */
break; /* exit switch selection */

case 'Y' : /* for year search */

if ((comp_result = strcmp (base_record->year, s_key_record->year))
== 0) /* if base year and key year are the same - */
found = TRUE; /* match has been found */
break; /* exit switch selection */

case 'N' : /* for name search */

if ((comp_result = strcmp (base_record->star1, s_key_record->star1))
== 0) /* if key name matches base star 1 */
found = TRUE; /* match has been found */
if ((comp_result = strcmp (base_record->star2, s_key_record->star1))
== 0) /* if key name matches base star 2 */
found = TRUE; /* match has been found */
if ((comp_result = strcmp (base_record->star3, s_key_record->star1))
== 0) /* if key name matches base star 3 */
found = TRUE; /* match has been found */
if ((comp_result = strcmp (base_record->director,
s_key_record->star1)) == 0) /* if key matches base director */
found = TRUE; /* match has been found */
break; /* exit switch selection */

case 'S' : /* for subject search */

if (base_record->subject == s_key_record->subject) /* if key subject */
found = TRUE; /* same as base subject, match has been found */
break; /* exit switch selection */

case 'F' : /* for form search */

if (base_record->form == s_key_record->form) /* if key form same as */
found = TRUE; /* base form, match has been found */
break; /* exit switch selection */

case 'R' : /* for rating search */

if (base_record->rating == s_key_record->rating) /* if key rating */
found = TRUE; /* same as base rating, match has been found */
break; /* exit switch selection */

case 'M' : /* for rating search */

if (base_record->mpaa_code == s_key_record->mpaa_code)/* if key MPAA */
found = TRUE; /* same as base rating, match has been found */
break; /* exit switch selection */

default : /* if not valid search code */

printf ("**** ERROR - Bad Search Code ****"); /* warn user */
}

if (found) /* if matching record has been found */
{
switch (output_type) /* select action according to output code */
{

case 'C' : /* for continuous screen display */

if (out_count == 0)
{
sprintf (char_buff,"Search results being displayed on screen...");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,0,0,hvio);
VioSetCurPos(23,0,hvio);
}
disp_rec ((out_count * 5 + 2),base_record);/* display the record */
if (++out_count == 4) /* if screen full */
{
time(&time_1); /* set time marker */
time_2 = time_1 + (long)2;
while (time_1 <= time_2) /* allow time to read */
time(&time_1);
out_count = 0; /* clear count */
}
break; /* exit switch selection */


case 'S' : /* for paused screen display */

if (out_count == 0) /* if clear screen needed */
{
clear_screen (WHITE,BLACK); /* clear screen & set colors */
window (0,79,0,0,LGREEN,BLACK);
VioSetCurPos (22,0,hvio);
sprintf (char_buff,"Search results being displayed on screen...");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,0,0,hvio);

}
disp_rec ((out_count * 5 + 2),base_record);/* display the record */
if (++out_count == 4) /* if screen full */
{
go_ahead = qpause(); /* wait for user */
out_count = 0; /* clear count */
}
break; /* exit switch selection */


case 'P' : /* for printer output */

if (out_count == 0) /* if new page needed */
fprintf (print_pointer, "\r\f\n"); /* page eject */
print_rec (base_record, print_pointer); /* print record */
if (++out_count == 12) /* if page full */
out_count = 0; /* reset count */
else /* otherwise */
fprintf (print_pointer, "\n"); /* skip a line */
break; /* exit switch selection */

}
}
}

/* shutdown after search completed */

free ((char *)base_record); /* free memory allocated to records */
free ((char *)s_key_record);
free (iobuf);
free (char_buff);

if (fclose (basef_pointer) != NULL) /* close base file stream */
printf ("\nError in closing base file\n");

if (output_type == 'P') /* if printer output */
{
fprintf (print_pointer, "\n\f"); /* eject last page */
if (fclose (print_pointer) == EOF) /* close stream */
perror ("fclose failed on print_pointer"); /* test for error */
}

if ((output_type == 'S')||(output_type == 'C')); /* if screen output */
{
set_cursor (23,0,0);
pause(); /* wait for user */
}
out_count = comp_result; /* useless instruction to avoid TURBO C warning */
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ search ^^^^*/

#pragma subtitle("search_key()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv search_key vvvv/*
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include stdio.h |
| char search_key(stuct MOVIERECORD s_key_record); |
| |
| FUNCTION |
| ~~~~~~~~ |
| Displays menu of search type choices, gets user choice of search type, |
| obtains appropriate search key data for search type and stores it |
| in s_key_record. |
| |
| RETURNS |
| ~~~~~~~ |
| Character code for search type selected by user. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Calls functions which use nonstandard C extensions; may not be portable |
| accross compilers and operating systems. |
| |
| |
| |
| |
+----------------------------------------------------------------------------*/


char search_key (s_key_record)

struct MOVIERECORD *s_key_record; /* record to contain search key */


{
USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
extern void clear_screen();/* func clears screen and sets colors*/
extern void draw_box(); /* func draws box on screen */
extern void get_form(); /* func gets form for record */
extern void get_name(); /* func gets name for record */
extern void get_rating(); /* func gets rating for record */
extern void get_subject(); /* func gets subject for record */
extern void get_title(); /* func gets title for record */
extern void get_year(); /* func gets year for record */
HVIO hvio = 0; /* video handle */
char response [INPUTLENGTH];/* buffer for keyboard input */
char s_type; /* code for type of search */
extern void set_cursor(); /* func sets cursor position */
extern void trim(); /* func trims leading & trailing whitespace */
int valid_code = FALSE; /* boolean flag for valid code */
extern void window(); /* func opens window on screen display */
/* allocate memory for records */
s_type = '\0'; /* initialize codes */
valid_code = FALSE;
char_buff = (char *) calloc (1, 0x100);


/* display search menu and get user choice of search type */

set_border (BLACK); /* set border color */
clear_screen (LWHITE, BLACK); /* clear screen & set colors */
window (10,70,3,19,WHITE,BLUE);
draw_box ('l',11,69,3,19); /* draw box in window */

sprintf (char_buff, "SEARCH MENU"); /* display menu caption */
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,5,34,hvio);

sprintf (char_buff, "T = Title search."); /* print menu choice */
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,9,14,hvio);

sprintf (char_buff, "Y = Year search."); /* print choice */
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,10,14,hvio);

sprintf (char_buff, "N = Name search."); /* print choice */
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,11,14,hvio);

sprintf (char_buff, "S = Subject search."); /* print choice */
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,12,14,hvio);

sprintf (char_buff, "F = Form search."); /* print choice */
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,13,14,hvio);

sprintf (char_buff, "R = Rating search. "); /* print choice */
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,14,14,hvio);

sprintf (char_buff, "M = MPAA code search."); /* print choice */
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,15,14,hvio);

sprintf (char_buff, "E = Exit to Main Menu."); /* print choice */
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,16,14,hvio);


while (!valid_code) /* loop until valid code selected */
{
VioWrtNChar (" ",80,21,0,hvio);
sprintf (char_buff,"Enter code -> "); /* prompt user to enter choice */
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,21,10,hvio);
VioSetCurPos(21,(10 + cbString),hvio);
gets (response); /* get user response */
trim (response); /* trim leading and trailing whitespace */
s_type = toupper (response [0]); /* get first character in upper case */

switch (s_type) /* select according to code */
{
case 'T' :
case 'Y' :
case 'N' :
case 'S' :
case 'F' :
case 'R' :
case 'M' :
case 'E' :

valid_code = TRUE; /* set valid code flag to true */
break; /* exit selection */

default : /* no code match */

valid_code = FALSE;
VioSetCurPos(21,10,hvio); /* move cursor */
printf (" ");
break;
}
}

clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,20,LWHITE,BLUE);
window (6,78,9,14,BLACK,BLACK);
window (4,76,8,13,BLACK,WHITE);
set_border (BLUE); /* set screen border color */
VioSetCurPos (22,0,hvio); /* position cursor */

switch (s_type) /* choose action according to search code */
{
case 'T' : /* for title search */


sprintf(char_buff,
" The title can be complete or partial. The search will");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,9,14,hvio);
sprintf(char_buff,
" report all titles which eactly match the string now ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,10,14,hvio);
sprintf(char_buff,
" entered or which contain the string now entered as a ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,11,14,hvio);
sprintf(char_buff,
" a substring. ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,12,14,hvio);
pause();
VioWrtNChar(" ",80,22,0,hvio);
VioWrtNChar(" ",80,23,0,hvio);
VioWrtNChar(" ",80,24,0,hvio);
VioSetCurPos(22,0,hvio);

get_title (s_key_record->title); /* get full or partial title */
trim (s_key_record->title); /* trim title */
valid_code = TRUE; /* set valid code flag to true */
break; /* exit loop */
/* note: title must be trimmed to avoid */
/* blank padding which would prevent */
/* substring match for partial title */

case 'Y' : /* for year search */

get_year (s_key_record->year); /* get year */
valid_code = TRUE; /* set valid code flag to true */
break; /* exit loop */

case 'N' : /* for name search */

get_name (s_key_record->star1, "Name"); /* get name */
valid_code = TRUE; /* set valid code flag to true */
break; /* exit loop */
/* note: the star1 field is arbitrarily */
/* used to hold the search key name; it */
/* will actually be matched against all */
/* name fields in each base record. */

case 'S' : /* for subject search */

get_subject (&s_key_record->subject); /* get subject */
valid_code = TRUE; /* set valid code flag to true */
break; /* exit loop */

case 'F' : /* for form search */

get_form (&s_key_record->form); /* get form */
valid_code = TRUE; /* set valid code flag to true */
break; /* exit loop */

case 'R' : /* for rating search */

get_rating (&s_key_record->rating); /* get Rating */
valid_code = TRUE; /* set valid code flag to true */
break; /* exit loop */

case 'M' : /* for rating search */

get_mpaa_code (&s_key_record->mpaa_code); /* get MPAA code */
valid_code = TRUE; /* set valid code flag to true */
break; /* exit loop */

case 'E' : /* for exit request */

return (s_type); /* exit from function and return to main module */

default : /* no code match */

valid_code = FALSE; /* set valid code flag to false */
printf ("\nINVALID CODE\n"); /* warn user invalid code selected */
pause(); /* wait for user */
}
free (char_buff);
return (s_type);
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ search_key ^^^^*/

#pragma subtitle("set_border()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv set_border vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| void set_border (int color) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Sets the screen border to the color ID. |
| |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Uses VioSetState to set the overscan. According to the OS/2 |
| Programmer's Toolkit Reference, this is not a family API function; |
| however it seems to work properly. May not be portable accross |
| compilers and operating systems. |
| |
+----------------------------------------------------------------------------*/

void set_border (color) /* set border color */

int color; /* color ID for border color */

{

extern int has_color();
VIOOVERSCAN vio_overscan;
HVIO hvio = 0;

if (has_color())
{
vio_overscan.cb = (USHORT)sizeof(struct _VIOOVERSCAN);
vio_overscan.type = 0x0001;
vio_overscan.color = color;
VioSetState (&vio_overscan, hvio);
}
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ set_border ^^^^*/

#pragma subtitle("set_cursor()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv set_cursor vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| void set_cursor (int row, column, page) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Sets cursor to position at the specified row and column on the |
| specified video page. |
| |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| The page value is an artifact from a prior version which used |
| a DOS interrupt. It no longer serves any function. Eventually |
| all calls to this function will be replaced with VioSetCurPos |
| and it will be eliminated. |
| |
+----------------------------------------------------------------------------*/

void set_cursor (row, column, page) /* set cursor position */

int row, column, page;

{
HVIO hvio = 0;
page = page;
VioSetCurPos (row, column, hvio);

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ set_cursor ^^^^*/

#pragma subtitle("tally ()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv tally vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| void tally(char *base_file_id) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Reads all records in base_file_id, keeping tallies by the subject, |
| form, and rating code for each record. The function tally_sort() |
| is called to sort each tally into descending order. Then a report |
| is displayed for each catagory, showing the number of occurrences |
| and percentage distribution. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| NOTES |
| ~~~~~ |
| Uses only ANSI standard functions and should be portable. |
| |
| |
+----------------------------------------------------------------------------*/

void tally(base_file_id) /* tally statistics for data base */

char *base_file_id; /* string path and file name of base file */

{

FILE *basef_pointer; /* pointer to base file */
struct MOVIERECORD *base_record; /* buffer to hold one base record */
USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
extern void clear_screen(); /* func clears screen & sets colors */
int count; /* counters */
struct NAMERECORD far *dir_name_list = NULL; /* director name list */
char form_codes[FORMNUMBER];/* local array of form codes */
int form_counts [FORMNUMBER]; /* array of form counts */
HVIO hvio = 0; /* video handle */
char *iobuf; /* buffer for file i/o */
struct NAMERECORD far *name_ptr = NULL; /* pointer to name list */
char rating_codes[RATINGNUMBER]; /* local array of codes */
int rating_counts [RATINGNUMBER];/* array of rate counts*/
struct NAMERECORD far *star_name_list = NULL; /* actor name list */
char subj_codes[SUBJNUMBER];/* local array of subj codes */
int subj_counts [SUBJNUMBER];/* array of subject counts */
extern void tally_display(); /* func displays result of tally */
struct YEARRECORD far *tally_list_year(); /* func bulids linked year list */
int total_movies = 0;/* total number of records in base */
struct YEARRECORD far *year_list = NULL; /* year linked list */
struct YEARRECORD far *year_ptr = NULL; /* pointer to year list */
int test_count = 0;


clear_screen (MAGENTA, BLACK);
VioSetCurPos (23, 0, hvio);
char_buff = (char *) calloc (1, 0x100);

/* initialize local arrays */

for (count = 0; count < SUBJNUMBER; count++) /* for each subject code */
{
subj_codes [count] = codes [count]; /* get code from global array */
subj_counts [count] = 0; /* initialize count = 0 */
}
for (count = 0; count < FORMNUMBER; count++) /* for each form code */
{
form_codes [count] = codes [count]; /* get code from global array */
form_counts [count] = 0; /* initialize count = 0 */
}
for (count = 0; count < RATINGNUMBER; count++)
{
rating_codes [count] = codes [count]; /* get code from global array */
rating_counts [count] = 0; /* initialize count = 0 */
}

iobuf = calloc (1, BIGBUFF); /* allocate memory for file i/o buffer */
if ((basef_pointer = fopen (base_file_id, "rb")) == NULL) /* open basef */
{ /* if open error - */
printf ("\Unable to open base file\n"); /* warn user */
pause(); /* wait for user */
fcloseall(); /* close all files */
return; /* abort */
}
setvbuf (basef_pointer, iobuf,_IOFBF, BIGBUFF); /* big buffer for file i/o */

base_record = (struct MOVIERECORD *)calloc (1, sizeof (struct MOVIERECORD));
/* allocate memory to base record buffer */
total_movies = 0; /* initialize record count = 0 */

while (!(feof (basef_pointer))) /* while not EOF base file */
{
if ((fread ((char *)base_record, sizeof (struct MOVIERECORD),
1, basef_pointer)) != 1) /* read a record from the base file */
{ /* if read error - */
if (!(feof(basef_pointer))) /* - and not end of file (normal term) */
{
printf ("\nError in reading base file\n"); /* warn user */
pause(); /* wait for user */
fcloseall(); /* close all files */
return; /* abort */
}
else break; /* otherwise (normal) exit loop and continue */
}

total_movies++; /* increment record counter */

sprintf (char_buff, "Analyzing: %4d %s",
total_movies, base_record->title);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff, cbString, 10, 10, hvio);

for (count = 0; count < SUBJNUMBER; count++) /* check subject code */
if (base_record->subject == subj_codes [count]) /* and increment */
(subj_counts [count])++; /* corresponding count */

for (count = 0; count < FORMNUMBER; count++) /* check form code */
if (base_record->form == form_codes [count]) /* and increment */
(form_counts [count])++; /* corresponding count */

for (count = 0; count < RATINGNUMBER; count++) /* check rating code */
if (base_record->rating == rating_codes [count]) /* and increment */
(rating_counts [count])++; /* corresponding count */

dir_name_list = tally_list_name (base_record->director, dir_name_list);
star_name_list = tally_list_name (base_record->star1, star_name_list);
star_name_list = tally_list_name (base_record->star2, star_name_list);
star_name_list = tally_list_name (base_record->star3, star_name_list);
year_list = tally_list_year (base_record->year, year_list);

if (test_count++ >= MAXRECORDS)
break;
}
tally_display ( dir_name_list, star_name_list, year_list,
form_codes, form_counts, rating_codes, rating_counts,
subj_codes, subj_counts, total_movies);


while (dir_name_list != NULL)
{
name_ptr = dir_name_list;
dir_name_list = dir_name_list->next_name_rec;
DosFreeSeg (name_ptr->sel);
}

while (star_name_list != NULL)
{
name_ptr = star_name_list;
star_name_list = star_name_list->next_name_rec;
DosFreeSeg (name_ptr->sel);
}

while (year_list != NULL)
{
year_ptr = year_list;
year_list = year_list->next_year_rec;
DosFreeSeg (year_ptr->sel);
}

free ((char *)base_record); /* free memory allocated to base record */
if (fclose (basef_pointer) != NULL) /* close base file - if error, */
printf ("\nError in closing base file\n"); /* warn user */
free (iobuf); /* free memory allocated to file i/o buffer */
free (char_buff);
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ tally ^^^^*/

#pragma subtitle("tally_display ()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv tally_display vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| void tally_display (char form_codes[], int form_counts[], |
| char rating_codes[], int rating_counts[], |
| char subj_codes[], int subj_counts[], |
| int total_movies) |
| |
| |
| |
| FUNCTION |
| ~~~~~~~~ |
| |
| Prints a display of the statistics recorded in the arrays for form |
| codes, form counts, subject codes, subject counts, rating codes, and |
| rating counts, using total movies count to calculate percentages. |
| Displays top of actor, director and year frequency lists. |
| |
| RETURNS |
| ~~~~~~~ |
| |
| Nothing. |
| |
| NOTES |
| ~~~~~ |
| Calls functions which use nonstandard C extensions; may not be |
| portable accross compilers and operating systems. |
| |
| |
+----------------------------------------------------------------------------*/

void tally_display (dir_name_list, star_name_list, year_list,
form_codes, form_counts, rating_codes, rating_counts,
subj_codes, subj_counts, total_movies)

struct NAMERECORD far *dir_name_list; /* director name list */
struct NAMERECORD far *star_name_list; /* actor name list */
struct YEARRECORD far *year_list; /* year linked list */
char form_codes[]; /* local array of form codes */
int form_counts[]; /* array of form counts */
char rating_codes[]; /* local array of codes */
int rating_counts []; /* array of rate counts*/
char subj_codes[]; /* local array of subj codes */
int subj_counts[]; /* array of subject counts */
int total_movies; /* total number of records in base */

{

USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
extern void clear_screen(); /* func clears screen & sets colors */
int count; /* counter */
int i, j; /* counters */
double fhundred = 100.0; /* constant 100.0 */
char go_ahead = ' '; /* quit signal */
HVIO hvio = 0; /* video handle */
struct NAMERECORD far *name_ptr = NULL; /* pointer to name list */
extern void name_out(); /* func coverts name form for display */
double percent1, percent2; /* percentages calculated */
extern char qpause(); /* func asks if user wants to quit */
extern void tally_sort(); /* func to sort arrays */
char text1[INPUTLENGTH]; /* text descriptor for table */
char text2[INPUTLENGTH]; /* text descriptor for table */
struct YEARRECORD far *year_ptr = NULL; /* pointer to year list */
extern void window(); /* func opens window */




/* prepare and display analysis by subject code */

char_buff = (char *) calloc (1, 0x100);
clear_screen (BLACK, WHITE);
window (0,79,23,24,WHITE,BLACK);
VioSetCurPos(23,0,hvio);
sprintf (char_buff," Subject Analysis");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,0,0,hvio);
tally_sort (SUBJNUMBER, subj_codes, subj_counts);
for (i = 0; i < (int)(SUBJNUMBER/2); i++)
{
for (j = 0; j < SUBJNUMBER; j++)
{
if (subj_codes [i] == codes[j])
strcpy (text1, subjects[j]);
if (subj_codes [i + (int)(SUBJNUMBER/2)] == codes[j])
strcpy (text2, subjects[j]);
}
percent1 = (double)subj_counts[i] / (double)total_movies;
percent1 = percent1 * fhundred;
percent2 =
(double)subj_counts[i + (int)(SUBJNUMBER/2)] /(double)total_movies;
percent2 = percent2 * fhundred;
sprintf (char_buff," %6d %s %5.2f%% \x0B3 %6d %s %5.2f%%",
subj_counts [i],
text1,
percent1,
subj_counts [i + ((int)(SUBJNUMBER/2))],
text2,
percent2);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,(i +2),0,hvio);
}
pause();
/* prepare and display analysis by form code */

clear_screen (BLACK, WHITE);
window (0,79,23,24,WHITE,BLACK);
VioSetCurPos(23,0,hvio);
sprintf (char_buff," Form Analysis");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,2,0,hvio);
tally_sort (FORMNUMBER, form_codes, form_counts);
for (i = 0; i < (int)(FORMNUMBER/2); i++)
{
for (j = 0; j < FORMNUMBER; j++)
{
if (form_codes [i] == codes[j])
strcpy (text1, forms[j]);
if (form_codes [i + (int)(FORMNUMBER/2)] == codes[j])
strcpy (text2, forms[j]);
}
percent1 = (double)form_counts[i] / (double)total_movies;
percent1 = percent1 * fhundred;
percent2 =
(double)form_counts[i + (int)(FORMNUMBER/2)] /(double)total_movies;
percent2 = percent2 * fhundred;
sprintf (char_buff," %6d %s %5.2f%% \x0B3 %6d %s %5.2f%%",
form_counts [i],
text1,
percent1,
form_counts [i + ((int)(FORMNUMBER/2))],
text2,
percent2);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,(i + 4),0,hvio);
}
pause();

/* prepare and display analysis by rating code */


clear_screen (BLACK, WHITE);
window (0,79,23,24,WHITE,BLACK);
VioSetCurPos(23,0,hvio);
sprintf (char_buff," Rating Analysis");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,5,0,hvio);
tally_sort (RATINGNUMBER, rating_codes, rating_counts);
for (i = 0; i < (int)(RATINGNUMBER/2); i++)
{
for (j = 0; j < RATINGNUMBER; j++)
{
if (rating_codes [i] == codes[j])
strcpy (text1, ratings[j]);
if (rating_codes [i + (int)(RATINGNUMBER/2)] == codes[j])
strcpy (text2, ratings[j]);
}
percent1 = (double)rating_counts[i] / (double)total_movies;
percent1 = percent1 * fhundred;
percent2 =
(double)rating_counts[i +
(int)(RATINGNUMBER/2)] /(double)total_movies;
percent2 = percent2 * fhundred;
sprintf (char_buff, " %6d %s %5.2f%% \x0B3 %6d %s %5.2f%%",
rating_counts [i],
text1,
percent1,
rating_counts [i + ((int)(RATINGNUMBER/2))],
text2,
percent2);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,(i + 7),0,hvio);
}
sprintf (char_buff," Total number = %d", total_movies);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,20,0,hvio);
pause();

/* display actor name list */

name_ptr = star_name_list;
go_ahead = 'Y';

while ((name_ptr != NULL) && (go_ahead != 'Q'))
{
clear_screen (BLACK, WHITE);
window (0,79,23,24,WHITE,BLACK);
sprintf (char_buff, "Actor Name Frequency Analysis");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff, cbString, 1,22, hvio);
VioSetCurPos (24,0,hvio);
for (count = 0; count < 20; count++)
{
if (name_ptr == NULL)
break;
name_out (name_ptr->name);
sprintf (char_buff,"%4d %s", name_ptr->count,name_ptr->name);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff, cbString, (3 + count), 0, hvio);
name_ptr = name_ptr->next_name_rec;
}
for (count = 0; count < 20; count++)
{
if (name_ptr == NULL)
break;
name_out (name_ptr->name);
sprintf (char_buff,"\x0B3 %4d %s", name_ptr->count,name_ptr->name);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff, cbString, (3 + count), 39, hvio);
name_ptr = name_ptr->next_name_rec;
}
go_ahead = qpause();
}

/* Display director name list */

name_ptr = dir_name_list;
go_ahead = 'Y';

while ((name_ptr != NULL) && (go_ahead != 'Q'))
{
clear_screen (BLACK, WHITE);
window (0,79,23,24,WHITE,BLACK);
sprintf (char_buff, "Director Name Frequency Analysis");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff, cbString, 1,22, hvio);
VioSetCurPos (24,0,hvio);
for (count = 0; count < 20; count++)
{
if (name_ptr == NULL)
break;
name_out (name_ptr->name);
sprintf (char_buff,"%4d %s", name_ptr->count,name_ptr->name);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff, cbString, (3 + count), 0, hvio);
name_ptr = name_ptr->next_name_rec;
}
for (count = 0; count < 20; count++)
{
if (name_ptr == NULL)
break;
name_out (name_ptr->name);
sprintf (char_buff,"\x0B3 %4d %s", name_ptr->count,name_ptr->name);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff, cbString, (3 + count), 39, hvio);
name_ptr = name_ptr->next_name_rec;
}
go_ahead = qpause();
}

/* Display Year List */


clear_screen (BLACK, WHITE);
window (0,79,23,24,WHITE,BLACK);
sprintf (char_buff, "Year of Release Frequency Analysis");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff, cbString, 1,22, hvio);
VioSetCurPos (23,0,hvio);
year_ptr = year_list;
for (count = 0; count < 20; count++)
{
if (year_ptr == NULL)
break;
sprintf (char_buff,"\x0B3 %4d %s \x0B3",
year_ptr->count,year_ptr->year);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff, cbString, (3 + count), 0, hvio);
year_ptr = year_ptr->next_year_rec;
}
for (count = 0; count < 20; count++)
{
if (year_ptr == NULL)
break;
sprintf (char_buff,"\x0B3 %4d %s \x0B3",
year_ptr->count,year_ptr->year);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff, cbString, (3 + count), 16, hvio);
year_ptr = year_ptr->next_year_rec;
}
for (count = 0; count < 20; count++)
{
if (year_ptr == NULL)
break;
sprintf (char_buff,"\x0B3 %4d %s \x0B3",
year_ptr->count,year_ptr->year);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff, cbString, (3 + count), 32, hvio);
year_ptr = year_ptr->next_year_rec;
}
for (count = 0; count < 20; count++)
{
if (year_ptr == NULL)
break;
sprintf (char_buff,"\x0B3 %4d %s \x0B3",
year_ptr->count,year_ptr->year);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff, cbString, (3 + count), 48, hvio);
year_ptr = year_ptr->next_year_rec;
}
for (count = 0; count < 20; count++)
{
if (year_ptr == NULL)
break;
sprintf (char_buff,"\x0B3 %4d %s \x0B3",
year_ptr->count,year_ptr->year);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff, cbString, (3 + count), 64, hvio);
year_ptr = year_ptr->next_year_rec;
}

pause();
free (char_buff);
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ tally_display ^^^^*/

#pragma subtitle("tally_list_name ()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv tally_list_name vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| #include |
| void tally_list_name (char *new_name, struct NAMERECORD far *name_list) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Creates a name list if not previously created. Compares new_name to |
| each cell in the list until a name match is found or the end of the |
| list is reached. If a match is found, the count is incremetned. If |
| no match is found, a new cell is added with the new name. The cell |
| for the new name is bubbled up the list to maintain frequency order. |
| |
| RETURNS |
| ~~~~~~~ |
| Pointer to head of doubly-linked name list. |
| |
| |
| NOTES |
| ~~~~~ |
| Uses MSC extenstions and may not be portable. |
| |
| |
+----------------------------------------------------------------------------*/

struct NAMERECORD far *tally_list_name (new_name, name_list)
char *new_name; /* pointer to new name */
struct NAMERECORD far *name_list; /* pointer to head of name list */

{
USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
HVIO hvio = 0; /* video handle */
static int out_of_memory = FALSE; /* out of memory flag */
SEL sel; /* memory block selector */
struct NAMERECORD far *temp_current; /* ptr to current name record */
struct NAMERECORD far *temp_next; /* ptr to next name record */
struct NAMERECORD temp_rec; /* temporary name record */

if (new_name[0] == ',') /* if no new name, do nothing */
return name_list; /* return list unchanged */


/* if no list, establsh one */

if (name_list == NULL) /* if no memory yet allocated to name list - */
{
out_of_memory = DosAllocSeg ((sizeof (struct NAMERECORD)), &sel, 0);
if (out_of_memory) /* allocate memory and test for out of memory */
return name_list;
name_list = MAKEP (sel, 0); /* make a pointer out of the selector */
strcpy (name_list->name, new_name); /* copy name to the list */
name_list->count = 1; /* set count = 1 */
name_list->sel = sel; /* record the selector */
name_list->last_name_rec = NULL; /* set back link to null */
name_list->next_name_rec = NULL; /* set forward link to null */
return name_list; /* return the pointer */
}

/* move down list until name match or end of list */

temp_current = name_list; /* set current ptr to head of list */
while ((temp_current->next_name_rec != NULL) /* while not end of list - */
&& (strcmp (temp_current->name, new_name))) /* and no name match - */
{
temp_current = temp_current->next_name_rec; /* move to next link */
}

/* if match found, increment count */
/* if no match, then add new cell to list */

if ((strcmp (temp_current->name, new_name)) == 0) /* if name match - */
temp_current->count = temp_current->count + 1; /* increment count */
else /* otherwise - */
if (! (out_of_memory)) /* if not out of memory */
{
out_of_memory = DosAllocSeg ((sizeof (struct NAMERECORD)), &sel, 0);
if (out_of_memory) /* allocate memory for new cell and test - */
{
char_buff = (char *) calloc (1, 0x100);
sprintf (char_buff, "All available memory in use.");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,20,5,hvio);
free (char_buff);
return name_list; /* return unchanged if memory allocation failed */
}
temp_next = MAKEP (sel, 0); /* make a pointer from the selector */
strcpy (temp_next->name, new_name); /* copy the new name into the cell */
temp_next->count = 1; /* set count = 1 */
temp_next->sel = sel; /* record the selector */
temp_next->last_name_rec = temp_current; /* back link to last cell */
temp_next->next_name_rec = NULL; /* next link is null */
temp_current->next_name_rec = temp_next; /* next link to new cell */
}

/* bubble cell up the list until above all cells with lower count */

while ((temp_current->last_name_rec != NULL)
&& (temp_current->count > temp_current->last_name_rec->count))
{
strcpy (temp_rec.name, temp_current->name);
temp_rec.count = temp_current->count;
strcpy (temp_current->name, temp_current->last_name_rec->name);
temp_current->count = temp_current->last_name_rec->count;
strcpy (temp_current->last_name_rec->name, temp_rec.name);
temp_current->last_name_rec->count = temp_rec.count;
temp_current = temp_current->last_name_rec;
}

return name_list; /* return pointer to list as modified */
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ tally_list_name ^^^^*/

#pragma subtitle("tally_list_year ()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv tally_list_year vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| #include |
| void tally_list_year (char *new_year, struct YEARRECORD far *year_list) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Creates a year list if not previously created. Compares new_year to |
| each cell in the list until a year match is found or the end of the |
| list is reached. If a match is found, the count is incremented. If |
| no match is found, a new cell is added with the new year. The cell |
| for the new year is bubbled up the list to maintain frequency order. |
| |
| RETURNS |
| ~~~~~~~ |
| Pointer to head of doubly-linked year list. |
| |
| |
| NOTES |
| ~~~~~ |
| Uses MSC extensions and may not be portable. |
| |
| |
+----------------------------------------------------------------------------*/

struct YEARRECORD far *tally_list_year (new_year, year_list)
char *new_year; /*pointer to new year */
struct YEARRECORD far *year_list; /* pointer to head of year list */


{
USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
HVIO hvio = 0; /* video handle */
static int out_of_memory = FALSE; /* out of memory flag */
SEL sel; /* memory block selector */
struct YEARRECORD far *temp_current; /* ptr to current year record */
struct YEARRECORD far *temp_next; /* ptr to next year record */
struct YEARRECORD temp_rec; /* temporary year record */

if (new_year[0] == '\0') /* if no new year, do nothing */
return year_list; /* return list unchanged */

/* if no list, establish one */

if (year_list == NULL) /* if no pointer allocated to list */
{
out_of_memory = DosAllocSeg ((sizeof (struct YEARRECORD)), &sel, 0);
if (out_of_memory) /* allocate memory and test for out of memory */
return year_list; /* return if allocation failed */
year_list = MAKEP (sel, 0); /* make a pointer from the selector */
strcpy (year_list->year, new_year); /* copy the year to the list head */
year_list->count = 1; /* set counter = 1 */
year_list->sel = sel; /* record the selector */
year_list->last_year_rec = NULL; /* set back link to null */
year_list->next_year_rec = NULL; /* set forward link to null */
return year_list; /* return the pointer */
}

/* move down the list until year match found or end of list */

temp_current = year_list; /* set current to head of list */
while ((temp_current->next_year_rec != NULL) /* while not end of list - */
&& (strcmp (temp_current->year, new_year))) /* and no year match - */
{
temp_current = temp_current->next_year_rec; /* move down to next link */
}

/* if match found, increment count */
/* if no match, then add new cell to end of list */

if ((strcmp (temp_current->year, new_year)) == 0) /* if year match - */
temp_current->count = temp_current->count + 1; /* increment count */
else /* otherwise - */
if (! (out_of_memory)) /* if not out of memory */
{
out_of_memory = DosAllocSeg ((sizeof (struct YEARRECORD)), &sel, 0);
if (out_of_memory) /* allocate memory for new cell and test - */
{
char_buff = (char *) calloc (1, 0x100);
sprintf (char_buff, "All available memory in use.");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,20,5,hvio);
free (char_buff);
return year_list; /* return unchanged if memory allocation failed */
}
temp_next = MAKEP (sel, 0); /* make a pointer from the selector */
strcpy (temp_next->year, new_year); /* copy the new year into the cell */
temp_next->count = 1; /* set count = 1 */
temp_next->sel = sel; /* record the selector */
temp_next->last_year_rec = temp_current; /* back link to last cell */
temp_next->next_year_rec = NULL; /* next link is null */
temp_current->next_year_rec = temp_next; /* next link to new cell */
}

/* bubble cell up the list until above all cells with lower counts */

while ((temp_current->last_year_rec != NULL)
&& (temp_current->count > temp_current->last_year_rec->count))
{
strcpy (temp_rec.year, temp_current->year);
temp_rec.count = temp_current->count;
strcpy (temp_current->year, temp_current->last_year_rec->year);
temp_current->count = temp_current->last_year_rec->count;
strcpy (temp_current->last_year_rec->year, temp_rec.year);
temp_current->last_year_rec->count = temp_rec.count;
temp_current = temp_current->last_year_rec;
}

return year_list; /* return pointer to list as modified */
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ tally_list_year ^^^^*/


#pragma subtitle("tally_sort()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv tally_sort vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| include |
| void tally_sort (int sort_number, char sort_codes[], sort_counts[]) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Performs a bubble sort on a two arrays, sort_number elements long, |
| of corresponding pairs of character codes and frequency counts, so |
| that they are ordered highest to lowest according to frequency. |
| |
| RETURNS |
| ~~~~~~~ |
| |
| Nothing. |
| |
| |
| NOTES |
| ~~~~~ |
| |
| Uses ANSI standard functions only; should be portable. |
| |
| |
| |
| |
+----------------------------------------------------------------------------*/

void tally_sort (sort_number, sort_codes, sort_counts)

int sort_number; /* number of pairs to be sorted */
char sort_codes[]; /* array of character codes */
int sort_counts[]; /* array of integer frequency counts */

{
int i, j; /* array index variables */
char temp_code; /* temporary character value holder */
int temp_count; /* temporary integer value holder */



/* bubble sort */
/* (in repeated passes, adjacent elements out of sequence /*
/* are swapped) */

for (i = 0; i <= (sort_number - 2); i++)
for (j = (sort_number - 1); j >= (i + 1); j--)
{
if (sort_counts[j] > sort_counts [j - 1])
{
temp_count = sort_counts [j];
temp_code = sort_codes [j];
sort_counts [j] = sort_counts [ j - 1];
sort_codes [j] = sort_codes [j - 1];
sort_counts [j - 1] = temp_count;
sort_codes [j - 1] = temp_code;
}
}
}



/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ tally_sort ^^^^*/

#pragma subtitle("trans_comp()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv trans_comp vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| #include |
| int trans_comp (struct MOVIETRANS *trans1, *trans2) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Compares the transactions pointed to by trans1 and trans2. Initial |
| comparison is according to the result of comparing the moviedata record |
| portion of each transaction. If the moviedata records are equal, |
| further comparison is by transaction code, to assure that deletes |
| precede adds for change transactions which delete an old record and |
| may add a new one with the same title and year but other data changed. |
| |
| RETURNS |
| ~~~~~~~ |
| less than zero if trans1 is less than trans2 |
| zero if trans1 is equal to trans2 |
| greater than zero if trans1 is greater than trans2 |
| |
| NOTES |
| ~~~~~ |
| Comparison is used for sorting records in alphabetical sequence by |
| title. Because of "remakes" two movies are allowed to have the same |
| title and they will be sequenced according to year of production. |
| When both title and year are the same, it is assumed that the records |
| both identify the same movie. If transaction codes are different, |
| the transactions may represent a change (delete old, add new) |
+----------------------------------------------------------------------------*/

int trans_comp (trans1, trans2)

struct MOVIETRANS *trans1, *trans2; /* pointers to 2 transactions */

{
int comp_result; /* result of comparison */
extern int rec_comp(); /* func compares 2 records */

if ((comp_result = rec_comp (&trans1->moviedata, &trans2->moviedata)) == 0)
{
if ((trans1->transaction == 'D') && (trans2->transaction == 'A'))
comp_result = -1;
if ((trans1->transaction == 'A') && (trans2->transaction == 'D'))
comp_result = 1;
if ((trans1->transaction == 'E') && (trans2->transaction != 'E'))
comp_result = 1;
if ((trans1->transaction != 'E') && (trans2->transaction == 'E'))
comp_result = -1;
if ((trans1->transaction != '\0') && (trans2->transaction == '\0'))
comp_result = 1;
if ((trans1->transaction == '\0') && (trans2->transaction != '\0'))
comp_result = -1;
}

return (comp_result);
}
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ trans_comp ^^^^^*/


#pragma subtitle("tree_display()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv tree_display vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| int tree_display (struct MOVIETRANS *tree_ptr, int count) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Displays transactions in a binary tree structure pointed to by |
| *tree_ptr, where count is the number of transactions already displayed |
| on the screen; pauses for user after 3 transactions have been displayed |
| and waits for signal from user before displaying more transactons. |
| RETURNS |
| ~~~~~~~ |
| Number of transactions displayed on the screen after execution. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Calls other functions which use MSC extensions and may not be portable. |
| Calls itself recursively until the tree is completely traversed, |
| passing the number of transactions currently displayed to each recursive |
| invocation. |
| |
| |
+----------------------------------------------------------------------------*/

int tree_display (tree_ptr, count) /* display transactions in tree */

struct MOVIETRANS *tree_ptr; /* ptr to tree structure */
int count; /* number displayed on screen */
{
extern void clear_screen(); /* func to clear screen */
extern void display(); /* func to display a transaction */
extern char pause(); /* func pauses for user */

if (tree_ptr != NULL) /* if tree pointer is not null pointer, display */
{ /* left subtree first, and get number displayed */
count = tree_display (tree_ptr->ltransnode, count);
{
if (count == 0) /* if no transactions already displayed, clear */
clear_screen (YELLOW, BLACK); /* screen and set display colors */
display ((count * 6),tree_ptr); /* display record at current node */
if (++count >= 3) /* if 3 transactions displayed */
{
VioSetCurPos (23,0,0);
pause(); /* pause for user */
count = 0; /* reset count to zero */
}
}
count = tree_display (tree_ptr->rtransnode, count); /* right subtree next*/
}
return count; /* return number currently displayed */
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ tree_display ^^^^*/

#pragma subtitle("tree_insert()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv tree_insert vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| struct MOVIETRANS *tree_insert (struct MOVIETRANS *tree_root, new_trans) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Inserts a transaction pointed to by new_trans into a binary tree |
| pointed to by tree_root. |
| |
| |
| RETURNS |
| ~~~~~~~ |
| Pointer to the root of the binary tree structure. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Memcpy() is declared in memory.h. MOVIETRANS is a structure defined |
| in videocat.c. |
| |
| |
| |
| |
+----------------------------------------------------------------------------*/

struct MOVIETRANS *tree_insert (tree_root, new_trans)/* insert trans in tree */

struct MOVIETRANS *tree_root; /* root of a tree structure */
struct MOVIETRANS *new_trans; /* ptr to a transaction */

{
int cond; /* comparison condition code */
static int out_of_memory = FALSE; /* out of memory flag */
SEL sel; /* memory block selector */
extern int trans_comp(); /* func to compare transactions */

if (tree_root == NULL) /* if tree root is null pointer */
{
out_of_memory = DosAllocSeg ((sizeof (struct MOVIETRANS)), &sel,0);

tree_root = (struct MOVIETRANS *)calloc(1, sizeof(struct MOVIETRANS));
if (out_of_memory)
{
printf ("Out of memory \n");
return tree_root;
}
memcpy ((char *)tree_root, (char *)new_trans,
sizeof(struct MOVIETRANS)); /* copy trans */
tree_root->sel = sel;
tree_root->ltransnode = tree_root->rtransnode = NULL; /* nodes = Null */
}
else if ((cond = trans_comp (new_trans, tree_root)) == 0) /* if new = root */
{
memcpy ((char *)&tree_root->moviedata, (char *)&new_trans->moviedata,
sizeof(struct MOVIERECORD)); /* copy new data record */
}
else if (cond < 0) /* if new less than root insert new at left node */
tree_root->ltransnode = tree_insert (tree_root->ltransnode, new_trans);
else if (cond > 0) /* if new greater than root insert new at right node */
tree_root->rtransnode = tree_insert (tree_root->rtransnode, new_trans);
return (tree_root); /* return pointer to root */
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ tree_insert ^^^^*/

#pragma subtitle("trim()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv trim vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| #include |
| void trim (char *string_ptr) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Trims leading and trailing whitespace charactrs from a string. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Used to edit console input to delete any leading or trailing |
| spaces. |
| |
| |
+----------------------------------------------------------------------------*/

void trim (string_ptr) /* func trims leading & trailing whitespace */

char *string_ptr; /* pointer to string */

{
int count; /* counter */
int last_char; /* index of last character in string */

/* delete leading white space */

while (isspace (string_ptr [0])) /* while 1st char is whitespace */
/* move rest of string back 1 byte */
for (count = 0; count <= strlen (string_ptr); count++)
string_ptr [count] = string_ptr [count + 1];

/* delete trailing white space */

last_char = strlen (string_ptr) - 1; /* get index of last char */
while (isspace (string_ptr [last_char])) /* while last char is whitespace */
{
string_ptr [last_char] = '\0'; /* change last char to null */
last_char = strlen (string_ptr) - 1; /* get index of new last char */
}
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ trim ^^^^*/


#pragma subtitle("update()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv update vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| struct MOVIETRANS *update (struct MOVIETRANS *root, char *base_file_id, |
| char *work_file_id, struct MOVIETRANS *trans_buff) |
| FUNCTION |
| ~~~~~~~~ |
| Processes transactions contained in a binary tree pointe to by root |
| against records contained in the file whose name is pointed to by |
| base_file_id, writing to a work file whose name is pointed to by |
| work_file_id, and using the buffer trans_buff for processing. |
| RETURNS |
| ~~~~~~~ |
| The pointer to the transaction tree, which is null after a successful |
| update. |
| |
| |
| NOTES |
| ~~~~~ |
| |
| |
| |
| |
| |
| |
+----------------------------------------------------------------------------*/

struct MOVIETRANS *update (root, base_file_id, work_file_id, trans_buff)

struct MOVIETRANS *root; /* pointer to root of binary tree */
char *base_file_id; /* pointer to name of base file */
char *work_file_id; /* pointer to name of work file */
struct MOVIETRANS *trans_buff; /* pointer to transaction buffer */

{

FILE *basef_ptr; /* base file stream */
char *buf1; /* file i/o buffer */
char *buf2; /* file i/o buffer */
USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
extern void clear_screen(); /* func clears screen & sets colors */
int count; /* counter for records processed */
extern void cur_size();
struct MOVIERECORD *current_rec_buf; /* holds current record */
extern void editRdata();
HVIO hvio = 0; /* video handle */
extern int has_color(); /* funct tests if color display */
extern int in_order(); /* func processes transactions in tree */
struct MOVIERECORD *last_rec_buf; /* holds last record read */
extern char pause(); /* func waits for user */
FILE *workf_ptr; /* work file stream */

/* set up screen and open files */

char_buff = (char *) calloc (1, 0x100);
cur_size (CURSOFF); /* call func to turn off cursor */
clear_screen (YELLOW, BLACK); /* clear screen & set display colors */
sprintf (char_buff, "UPDATING - READING OLD BASE FILE ...");/* advise user */
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff, cbString, 11, 11, hvio);
VioSetCurPos (23,0,hvio);
trans_buff = (struct MOVIETRANS *)memset /* clear buffer */
((char *)trans_buff, '\0', sizeof(struct MOVIETRANS));
buf1 = calloc (1, BIGBUFF); /* allocate memory to i/o buffer */
buf2 = calloc (1, BIGBUFF); /* allocate memory to i/o buffer */
current_rec_buf = calloc (1, sizeof (struct MOVIERECORD));
last_rec_buf = calloc (1, sizeof (struct MOVIERECORD));

workf_ptr = fopen (work_file_id, "wb"); /* open work file */
setvbuf (workf_ptr, buf1, _IOFBF, BIGBUFF); /* use big buffer for file i/o */
if (workf_ptr == NULL) /* if file not successfully opened - */
{
printf ("\n Error in opening work file.\n"); /* - warn user */
pause(); /* - wait for user */
fcloseall(); /* - close all files */
if (has_color()) /* restore cursor appropriate for display */
cur_size (CGACURSNORM);
else
cur_size (MONOCURSNORM);
free (char_buff);
return root; /* return pointer unchanged */
}
basef_ptr = fopen (base_file_id, "rb"); /* open base file */
setvbuf (basef_ptr, buf2, _IOFBF, BIGBUFF); /* use big buffer for file i/o */
if (basef_ptr == NULL) /* if file not successfully opened - */
{
printf ("\n Error in opening base file.\n"); /* - warn user */
pause(); /* - wait for user */
fcloseall(); /* - close all files */
if (has_color()) /* restore cursor appropriate for display */
cur_size (CGACURSNORM);
else
cur_size (MONOCURSNORM);
free (char_buff);
return root; /* - return pointer unchanged */
}

/* process update from base file and transactions */
/* to work file */

count = 1; /* initialize counter at 1 */
count = (in_order (workf_ptr, basef_ptr, root, trans_buff, count));
if (count != 0)
{ /* if transactions in binary tree successfully processed - */
root = NULL; /* if successful, all nodes have been freed */
while (!(feof (basef_ptr))) /* - while not end of base file - */
{
if ((trans_buff->transaction == '\0') /* -- if buffer empty - */
&& ((fread ((char *)&trans_buff->moviedata, sizeof(struct MOVIERECORD),
1, basef_ptr)) != 1)) /* read a record */
{ /* if read error - */
if (feof(basef_ptr)) /* - if EOF break loop */
{
trans_buff->transaction = 'E';
break; /* and continue (normal condition) */
}
else
{ /* - if other read error - */
printf ("\nError in reading base file.\n"); /* warn user */
pause(); /* wait for user */
fcloseall();
if (has_color()) /* restore cursor appropriate for display */
cur_size (CGACURSNORM);
else
cur_size (MONOCURSNORM);
free (char_buff);
return root; /* break off search (abnormal condition) */
}
}
else
{
trans_buff->transaction = 'B';/* code buffer to indicate base record */
sprintf (char_buff,"%4d ", count++); /*- display and increment count */
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,11,50,hvio);
}
if ((trans_buff->transaction == 'B') /* if buffer contains base record */
&& ((fwrite ((char *)&trans_buff->moviedata,
sizeof(struct MOVIERECORD),
1, workf_ptr)) != 1)) /* write the record to the work file */
{ /* if write error - */
printf ("\nError in writing work file.\n"); /* warn user */
pause(); /* wait for user */
fcloseall();
if (has_color()) /* restore cursor appropriate for display */
cur_size (CGACURSNORM);
else
cur_size (MONOCURSNORM);
free (char_buff);
return root; /* break off process (abnormal condition) */
}
else trans_buff->transaction = '\0'; /* otherwise code buffer empty */
}
fclose (workf_ptr); /* close work file */
fclose (basef_ptr); /* close base file */

/* transfer updated file from work file to base file */

workf_ptr = fopen (work_file_id, "rb"); /* open work file for read */
setvbuf (workf_ptr, buf1, _IOFBF, BIGBUFF); /* use big buffer */
if (workf_ptr == NULL) /* if file not successfully opened - */
{
printf ("\n Error in opening work file.\n"); /* - warn user */
pause(); /* - wait for user */
fcloseall(); /* close all files */
if (has_color()) /* restore cursor appropriate for display */
cur_size (CGACURSNORM);
else
cur_size (MONOCURSNORM);
free (char_buff);
return root; /* - return pointer to binary tree unchanged */
}
basef_ptr = fopen (base_file_id, "wb"); /* open base file for write */
setvbuf (basef_ptr, buf2, _IOFBF, BIGBUFF); /* use big buffer */
if (basef_ptr == NULL) /* if file not successfully opened - */
{
printf ("\n Error in opening base file.\n"); /* - warn user */
pause(); /* - wait for user */
fcloseall(); /* - close all files */
if (has_color()) /* restore cursor appropriate for display */
cur_size (CGACURSNORM);
else
cur_size (MONOCURSNORM);
free (char_buff);
return root; /* - return root unchanged */
}
count = 1; /* initialize record counter at 1 */
current_rec_buf = (struct MOVIERECORD *)memset /* clears buffers */
((char *)current_rec_buf, '\0', sizeof(struct MOVIERECORD));
last_rec_buf = (struct MOVIERECORD *)memset /* clears buffers */
((char *)last_rec_buf, '\0', sizeof(struct MOVIERECORD));
sprintf (char_buff,"UPDATING - WRITING NEW BASE FILE ...");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,11,11,hvio);
while (!(feof (workf_ptr))) /* while not at end of work file - */
{
if ((fread ((char *)current_rec_buf, sizeof(struct MOVIERECORD),
1, workf_ptr)) != 1) /* read a record */
{ /* if read error - */
if (feof(workf_ptr)) /* - if EOF break loop */
break; /* and continue (normal condition) */
else
{ /* - if other read error - */
printf ("\nError in reading work file.\n"); /* warn user */
pause(); /* wait for user */
fcloseall(); /* close all files */
if (has_color()) /* restore cursor appropriate for display */
cur_size (CGACURSNORM);
else
cur_size (MONOCURSNORM);
free (char_buff);
return root; /* return root unchanged */
}
}
/* correct for justification change from prior versions */

editRdata (current_rec_buf->loc1, LOCLENGTH);
editRdata (current_rec_buf->loc2, LOCLENGTH);
editRdata (current_rec_buf->year, YEARLENGTH);

if ((rec_comp (current_rec_buf, last_rec_buf)) > 0) /* test sequence */
{
if ((fwrite ((char *)current_rec_buf, sizeof(struct MOVIERECORD),
1, basef_ptr)) != 1) /* write record to base file */
{ /* if write error - */
printf ("\nError in writing base file.\n"); /* warn user */
pause(); /* wait for user */
fcloseall(); /* close all files */
if (has_color()) /* restore cursor appropriate for display */
cur_size (CGACURSNORM);
else
cur_size (MONOCURSNORM);
free (char_buff);
return root; /* return root unchanged */
}
else /* if record successfully transferred from work to base file - */
{
sprintf (char_buff, "%4d ", count++); /* - display record count */
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff,cbString,11,50,hvio);
memmove ((char *)last_rec_buf, (char *)current_rec_buf,
sizeof(struct MOVIERECORD));
}
}
else
{
sprintf (char_buff, "Discarding record out of sequence: %s",
current_rec_buf->title);
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr (char_buff, cbString, 20,11,hvio);
}
}
fclose (workf_ptr); /* close work file */
fclose (basef_ptr); /* close base file */
free (current_rec_buf);
free (last_rec_buf);
free (buf1); /* free memory allocated to file i/o buffer */
free (buf2); /* free memory allocated to file i/o buffer */
}

if (has_color()) /* restore cursor appropriate for display */
cur_size (CGACURSNORM);
else
cur_size (MONOCURSNORM);

pause();
free (char_buff);
return root; /* return root (NULL if update successful) */
}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ update ^^^^*/

#pragma subtitle("verify()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv verify vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| int verify() |
| |
| FUNCTION |
| ~~~~~~~~ |
| Asks user to verify data just displayed and enter Y or N according |
| to whether or not it is correct. |
| |
| |
| RETURNS |
| ~~~~~~~ |
| TRUE if first character of user's response is 'Y' or 'y'; otherwise |
| returns FALSE. |
| |
| |
| NOTES |
| ~~~~~ |
| TRUE and FALSE must be defined by macros in the calling program. |
| |
| |
| |
+----------------------------------------------------------------------------*/

int verify() /* func gets user verification of data */

{

char response [INPUTLENGTH]; /* user input buffer */
extern void trim(); /* func trims lead & trail whitespace */

printf (" Is this data correct? (Y/N) -> "); /* prompt user to verify */
gets (response); /* get user response */
trim (response); /* trim user response */
if ((response[0] == 'Y') || (response[0] == 'y')) /* if 1st char of user */
return TRUE; /* is Y or y return TRUE */
else /* otherwise return FALSE */
return FALSE;

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ verify ^^^^*/

#pragma subtitle("welcome()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv welcome vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| void welcome () |
| |
| FUNCTION |
| ~~~~~~~~ |
| Clears screen, opens window, draws box, and displays main menu. |
| |
| |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| |
| |
| |
| |
| |
| |
+----------------------------------------------------------------------------*/

void welcome() /* welcome routine */

{
USHORT cbString; /* string byte count */
char *char_buff; /* string buffer */
extern void clear_screen(); /* func clears screen and sets colors */
extern void draw_box(); /* func draws box on screen */
HVIO hvio = 0; /* video handle */
extern char pause(); /* func pauses for user input */
extern void set_cursor(); /* func sets cursor position */
extern void window(); /* func opens window on screen display */

char_buff = (char *) calloc (1, 0x100);
clear_screen (LBLUE, BLACK); /* clear screen & set colors */
window (10,70,3,18,RED,BLUE); /* open outer window */
window (12,68,5,16,LWHITE,BLUE); /* open innner window */
draw_box ('p',11,69,3,18); /* draw box in window */

sprintf (char_buff, "V I D E O C A T"); /* display program name */
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,7,32,hvio);

sprintf (char_buff,"Video Cassette Catalog");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,9,29,hvio);

sprintf (char_buff,"Version 6.0"); /* display version number */
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,11,33,hvio);

set_cursor (16,14,0); /* position cursor */
sprintf (char_buff,"(C)opyright 1986, 1987, 1988 W.A. Jackson"); /* (C) */
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,16,14,hvio);

set_cursor (22, 10, 0); /* move cursor */
pause(); /* wait for user */
window (12,68,5,16,LWHITE,BLUE); /* clear inner window */

sprintf (char_buff,"This program may be freely copied for personal use and");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,6,12,hvio);

sprintf
(char_buff,"transferred through public bulletin boards and shareware");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,7,12,hvio);

sprintf (char_buff,"distributors making no more than a nominal charge for");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,8,12,hvio);

sprintf (char_buff,"on-line time or diskette reproduction. A voluntary ");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,9,12,hvio);

sprintf (char_buff,"royalty payment to the author, in any amount you deem");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,10,12,hvio);

sprintf
(char_buff,"fair, will encourage further maintenance and enhancement.");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,11,12,hvio);

sprintf (char_buff,"W. A. Jackson");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,13,30,hvio);

sprintf (char_buff,"6529 Matilija Avenue");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,14,30,hvio);

sprintf (char_buff,"Van Nuys, California 91401");
cbString = (USHORT)strlen(char_buff);
VioWrtCharStr(char_buff,cbString,15,30,hvio);

free (char_buff);
set_cursor (22, 10, 0); /* move cursor */
pause(); /* wait for user */

}
/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ welcome ^^^^*/

#pragma subtitle("whole_cat()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv whole_cat vvvv*/
/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| void whole_cat (char *base_file_id); |
| |
| FUNCTION |
| ~~~~~~~~ |
| Prints a complete catalog from the file identified by base_file_id. |
| Output is to printer or screen according to choice entered by user. |
| |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Calls functions which use nonstandard extensions to ANSI C, so may |
| not be portable accross compilers and operating sytsems. |
| |
| |
| |
| |
+----------------------------------------------------------------------------*/

void whole_cat (base_file_id)

char *base_file_id; /* path and file name of base file */

{

FILE *basef_pointer; /* stream pointer for base file */
struct MOVIERECORD *base_record; /* record read from base file */
extern void clear_screen();/* func clears screen and sets colors*/
extern void disp_rec(); /* func displays record on screen */
char go_ahead = ' ';/* quit or go ahead signal from user */
char *iobuf; /* buffer for file i/o */
int out_count = 0; /* counter for records output */
char output_type = '\0'; /* code for output type */
extern void print_rec(); /* func prints record on printer */
int print_handle; /* file handle for printer */
FILE *print_pointer; /* stream for printer */
extern char outopt(); /* func gets user output choice */
extern void set_cursor(); /* func sets cursor position */
long time_1; /* time marker in seconds */
long time_2; /* time marker in seconds */
extern void window(); /* func opens window */

/* allocate memory for records */
base_record = (struct MOVIERECORD *)calloc (1,sizeof (struct MOVIERECORD));
iobuf = calloc (1, BIGBUFF);

output_type = outopt(); /* call func to get output type from user */

if (output_type == 'P') /* if printed output, open stream to printer */
{
print_handle = open ("PRN", O_WRONLY); /* open file handle */
if (print_handle == -1) /* test for open error */
perror ("open failed on PRN");
print_pointer = fdopen (print_handle, "w"); /* associate stream */
if (print_pointer == NULL) /* test for error */
{
perror ("fopen failed on print_handle");
pause(); /* wait for user */
return; /* return to main module */
}

}
/* open base file and set up file i/o buffer */

if ((basef_pointer = fopen (base_file_id, "rb")) == NULL) /* open base file*/
{ /* if unsuccessful - */
printf ("\nUnable to open base file\n"); /* warn user */
pause(); /* wait for user */
return; /* return to main module */
}

setvbuf (basef_pointer, iobuf,_IOFBF, BIGBUFF); /* big buffer for file i/o */
clear_screen (LWHITE,BLACK);
window (0,79,0,0,LBLUE,BLACK);
set_cursor (0,0,0); /* home cursor */
if (output_type == 'P')
printf ("Complete catalog being printed (printer must be ready)...");
else
printf ("Complete catalog being displayed on screen...");

while ((!(feof (basef_pointer))) /* loop while not end of file - */
&& (go_ahead != 'Q')) /* and no quit signal from user */
{
if ((fread ((char *)base_record, sizeof (struct MOVIERECORD),
1, basef_pointer)) != 1) /* read a record from the base file */
{ /* if read error - */
if (!(feof(basef_pointer))) /* - and not end of file (normal term) */
{
printf ("\nError in reading base file\n"); /* warn user */
pause(); /* wait for user */
fcloseall(); /* close all files */
return; /* abort */
}
else break; /* otherwise (normal) exit loop and continue */
}
set_cursor (23,0,0);

switch (output_type) /* select action according to output code */
{
case 'C' : /* for continuous screen display */

disp_rec ((out_count * 5 + 2),base_record); /* display the record */
if (++out_count == 4) /* if screen full */
{
time(&time_1); /* set time marker */
time_2 = time_1 + (long)2;
while (time_1 <= time_2) /* allow time to read */
time(&time_1);
out_count = 0; /* clear count */
}
break; /* exit switch selection */

case 'S' : /* for paused screen display */

if (out_count == 0) /* if clear screen needed */
{
clear_screen (LWHITE,BLACK); /* clear screen & set colors */
window (0,79,0,0,LBLUE,BLACK);
set_cursor (23,0,0); /* home cursor */
printf ("Complete catalog being displayed on screen...");
set_cursor (23,0,0); /* home cursor */
}
disp_rec ((out_count * 5 + 2), base_record); /* display the record */
if (++out_count == 4) /* if screen full */
{
go_ahead = qpause(); /* wait for user */
out_count = 0; /* clear count */
}
break; /* exit switch selection */

case 'P' : /* for printer output */

if (out_count == 0) /* if new page needed */
fprintf (print_pointer, "\r\f\n"); /* page eject */
print_rec (base_record, print_pointer); /* print record */
if (++out_count == 12) /* if page full */
out_count = 0; /* reset count */
else /* otherwise */
fprintf (print_pointer, "\n"); /* skip a line */
break; /* exit switch selection */

}
}

/* shutdown after catalog completed */

free ((char *)base_record); /* free memory allocated to records */
free (iobuf);

if (fclose (basef_pointer) != NULL) /* close base file stream */
printf ("\nError in closing base file\n");

if (output_type == 'P') /* if printer output */
{
fprintf (print_pointer, "\n\f"); /* eject last page */
if (fclose (print_pointer) == EOF) /* close stream */
perror ("fclose failed on print_pointer"); /* test for error */
}

if ((output_type == 'S')||(output_type == 'C')); /* if screen output */
{
set_cursor (23,0,0);
pause(); /* wait for user */
}
}



/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ whole_cat ^^^^*/

#pragma subtitle("window()")
#pragma page()

/*vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv window vvvv*/

/*----------------------------------------------------------------------------+
| |
| SYNOPSIS |
| ~~~~~~~~ |
| #include |
| #include |
| void window (int left_column, int right_columnun, int top_row, |
| int bottom_row, int foreground, int background) |
| |
| FUNCTION |
| ~~~~~~~~ |
| Opens window bounded by lef_column, right_column, top_row, and |
| bottom row, with video attributes foreground color and background color. |
| |
| RETURNS |
| ~~~~~~~ |
| Nothing. |
| |
| |
| |
| NOTES |
| ~~~~~ |
| Uses VioScrollDn, an MSC extenstion which may not be portable accross |
| operating systems and compilers. |
| |
+----------------------------------------------------------------------------*/

void window (left_column, right_column, top_row, bottom_row,
foreground, background)

int left_column; /* left boundry of window */
int right_column; /* right boundy of window */
int top_row; /* top boundry of window */
int bottom_row; /* bottom boundry of window */
int foreground; /* color attribute of foreground in window */
int background; /* color attribute of background in window */

{

int attribute; /* video color attribute */
extern int has_color(); /* func to check if color display present */
USHORT cbLines;
BYTE bCell[2];
HVIO hvio = 0;

/* home cursor within window */

VioSetCurPos (top_row, right_column, hvio);

/* set up color attribute byte for blank lines */

if (has_color()) /* if color display present - */
attribute = (0x10 * background) + foreground; /* - construct attr. byte */
else attribute = 0x7; /* else use mono attribute */
bCell[0] = 0x20;
bCell[1] = (BYTE)attribute;
cbLines = bottom_row - top_row + 1;

/* clear window and set colors */

VioScrollDn (top_row, left_column, bottom_row, right_column,
cbLines, bCell, hvio);

}

/*^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ window ^^^^*/

/* Copyright 1986, 1987, 1988 W. A. Jackson */ 