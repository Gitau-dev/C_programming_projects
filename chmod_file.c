#include <stdio.h>

//Defining permission bits for user
#define u_r (1 << 8)
#define u_w (1 << 7)
#define u_x (1 << 6)

//Defining permission bits for the group
#define g_r (1 << 5)
#define g_w (1 << 4)
#define g_x (1 << 3)

//Defining permission bits for others
#define o_r (1 << 2)
#define o_w (1 << 1)
#define o_x (1 << 0)

//Defination of the function responsible for permission setting
void permission_manager(unsigned short perm) {

//Prints permission if condition is true and OFF if its false
	printf("User: %c%c%c\n", 
	(perm & u_r) ? 'r' : '-', 
	(perm & u_w) ? 'w' : '-', 
	(perm & u_x) ? 'x' : '-');

	printf("Group : %c%c%c\n", 
	(perm & g_r) ? 'r' : '-', 
	(perm & g_w) ? 'w' : '-', 
	(perm & g_x) ? 'x' : '-');

	printf("Others: %c%c%c\n", 
	(perm & o_r) ? 'r' : '-', 
	(perm & o_w) ? 'w' : '-', 
	(perm & o_x) ? 'x' : '-');

}

int main() {
//This means that perm only holds 16 bits therefore its enough for whole permission setting
unsigned short perm = 0;

//Makes this permission be on default always
perm |= u_r | u_w | u_x;
perm |= g_r | g_w;
perm |= o_r;

printf("Current permission\n");
permission_manager(perm);

//Switched ON write permission on others part
perm |= o_w;
permission_manager(perm);

//Switched OFF write permission on group part
perm &= ~g_w;
permission_manager(perm);
return 0;
}
