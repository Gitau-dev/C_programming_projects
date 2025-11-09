#include <stdio.h>
#include <string.h>

//Define the permissions
#define read (1 << 0)
#define write (1 << 1)
#define execute (1 << 2)

//Declare a structure
struct file {
	char name[30];
	unsigned char permission;
	};

//Declared functions
void setpermission(struct file *f, unsigned char perm) {
		(*f).permission |= perm;
		}
void removepermission(struct file *f, unsigned char perm) {
		(*f).permission &= ~perm;
		}
void togglepermission(struct file *f, unsigned char perm) {
		(*f).permission ^= perm;
		}
int checkpermission(struct file f, unsigned char perm) {
	return (f.permission & perm) ? 1 : 0;
		}
void showpermission(struct file f) {
		printf("%c", (f.permission & read) ? 'r' : '-');
		printf("%c", (f.permission & write) ? 'w' : '-');
		printf("%c", (f.permission & execute) ? 'x' : '-');
		printf("\n");
		}

int main() {
struct file buffer;
char file_name[20];

printf("Type your file name: ");
scanf("%s", file_name);

strcpy(buffer.name, file_name);
buffer.permission = 0;
printf("Initial permission for %s\n", buffer.name);

showpermission(buffer);
//Menu display
int perm_choice;

printf("==Permission Options==\n");
printf("1. Set Permission\n");
printf("2. Toggle Permission\n");
printf("3. Remove Permission\n");
printf("Choose your option (ie. 1, 2, ..)\n");
scanf("%d", &perm_choice);
//Write a menu for the permissions

//Set permission of desired choice if needed
switch (perm_choice) {
case 1:
char choice[20];
printf("Permission to choose\n");
printf(" read\n");
printf(" write\n");
printf(" execute\n");

printf("Type the permission you want to set:\n");
scanf("%s", choice);

if (strcmp(choice, "read") == 0) {
	setpermission(&buffer, read);
	printf("Permission READ is set successfully!\n");
	}
else if (strcmp(choice, "write") == 0) {
	setpermission(&buffer, write);
	printf("Permission WRITE is set successfully!\n");
	}
else if (strcmp(choice, "execute") == 0) {
	setpermission(&buffer, execute);
	printf("Permission EXECUTE is set successfully!\n");
	}
else {
	printf("::Invalid Choice::\n");
}
printf("Current permission set\n");
showpermission(buffer);
break;

//Switch ON/OFF the permissions
case 2:
char toggle_choice[20];

printf("Type the permission you want to toggle (read,write,execute):\n");
scanf("%s", toggle_choice);
if (strcmp(toggle_choice, "read") == 0) {
	togglepermission(&buffer, read);
	showpermission(buffer);
	}
else if (strcmp(toggle_choice, "write") == 0) {
	togglepermission(&buffer, write);
	showpermission(buffer);
	}
else if (strcmp(toggle_choice, "execute") == 0) {
	togglepermission(&buffer, execute);
	showpermission(buffer);
	}
else {
	printf("==Invalid Toggle Choice==\n");
	}
break;

//Removes permissions whether ON/OFF
case 3:
char remove_choice[20];
printf("Type the permission you want to remove (read,write,execute):\n");
scanf("%s", remove_choice);

if (strcmp(remove_choice, "read") == 0) {
	removepermission(&buffer, read);
	showpermission(buffer);
	}
else if (strcmp(remove_choice, "write") == 0) {
	removepermission(&buffer, write);
	showpermission(buffer);
	}
else if (strcmp(remove_choice, "execute") == 0) {
	removepermission(&buffer, execute);
	showpermission(buffer);
	}
else {
	printf("==Invalid Remove Choice==\n");
	}
break;
default:
	printf("==Invalid Choice==\n");
}

 return 0;

}
