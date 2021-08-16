#define magic_num 'G'  // defining the macro with magic number


#define ADD _IOW(magic_num, 40,int)   /*defining other macros*/
#define SUB _IOW(magic_num,41,int)
#define MUL _IOW(magic_num , 42,int)
#define DIV _IOW(magic_num, 43, int)



