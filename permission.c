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

setpermission(&buffer, read);
setpermission(&buffer, write);

printf("After adding read and write:\n");
printf("3 rw-\n");
showpermission(buffer);

togglepermission(&buffer, execute);
printf("After toggling execute\n");
printf("7 rwx\n");
showpermission(buffer);

removepermission(&buffer, write);
printf("After removing write permission\n");
printf("5 r-x\n");
showpermission(buffer);

 return 0;

}
