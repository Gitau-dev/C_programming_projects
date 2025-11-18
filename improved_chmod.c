#include <stdio.h>
#include <string.h>

struct file {
	char name[30];
	unsigned short permission;
	};

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

//Declare a function for switch ON and OFF
void switch_(struct file *f, char perm_choice[10]) {
//User permissions
	if (strcmp(perm_choice, "u_r") == 0) {
	(*f).permission |= u_r;
	}
	else if (strcmp(perm_choice, "u_w") == 0) {
	(*f).permission |= u_w;
	}
	else if (strcmp(perm_choice, "u_x") == 0) {
	(*f).permission |= u_x;
	}
//Group permisions
	else if (strcmp(perm_choice, "g_r") == 0) {
	(*f).permission |= g_r;
	}
	else if (strcmp(perm_choice, "g_w") == 0) {
	(*f).permission |= g_w;
	}
	else if (strcmp(perm_choice, "g_x") == 0) {
	(*f).permission |= g_x;
	}
//Others permissions
	else if (strcmp(perm_choice, "o_r") == 0) {
	(*f).permission |= o_r;
	}
	else if (strcmp(perm_choice, "o_w") == 0) {
	(*f).permission |= o_w;
	}
	else if (strcmp(perm_choice, "o_x") == 0) {
	(*f).permission |= o_x;
	}

   }


//Defination of the function responsible for permission setting
void permission_manager(struct file f) {

//Prints permission if condition is true and OFF if its false
	printf("User: %c%c%c\n", 
	((f).permission & u_r) ? 'r' : '-', 
	((f).permission & u_w) ? 'w' : '-', 
	((f).permission & u_x) ? 'x' : '-');

	printf("Group : %c%c%c\n", 
	((f).permission & g_r) ? 'r' : '-', 
	((f).permission & g_w) ? 'w' : '-', 
	((f).permission & g_x) ? 'x' : '-');

	printf("Others: %c%c%c\n", 
	((f).permission & o_r) ? 'r' : '-', 
	((f).permission & o_w) ? 'w' : '-', 
	((f).permission & o_x) ? 'x' : '-');

}


int main() {
struct file perm_holder;
strcpy(perm_holder.name, "file23.sh");
perm_holder.permission = 0;

char choice[10];

//Makes this permission be on default always


printf("Current permission\n");
permission_manager(perm_holder);

//Switched ON write permission on others part
printf("Type the permission you want to change: \n");
scanf("%s", choice);
switch_(&perm_holder, choice);
//Switched OFF
//write permission on group part
//perm_holder.permission &= ~g_w;
permission_manager(perm_holder);
return 0;
}
