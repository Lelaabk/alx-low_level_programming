#ifndef DOH_H
#define DOH_H

/**
 * struct dog - some info about dog
 * @name:First member
 * @age: Second member
 * @owner: Third member
 *
 * Description: Longer description
 */

struct dog
{
	char *name;
	float age;
	char *owner;
};

/**
* typd_dog - typedef for struct dog
*/

typedef struct dog typd_dog;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
typd_dog *new_dog(char *name, float age, char *owner);
void free_dog(typd_dog *d);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif
