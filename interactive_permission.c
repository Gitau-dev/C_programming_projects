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
strcpy(buffer.name, "gitau.txt");
buffer.permission = 0;
printf("Initial permission for %s\n", buffer.name);
printf("0 ---\n");
showpermission(buffer);

char choice[20];
printf("Permission to choose\n");
printf("1. READ\n");
printf("2. WRITE\n");
printf("3. EXECUTE\n");

printf("Type the permission you want to set: ");
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

showpermission(buffer);

togglepermission(&buffer, execute);
printf("After toggling execute\n");
showpermission(buffer);

removepermission(&buffer, write);
printf("After removing write permission\n");
showpermission(buffer);

 return 0;

}
