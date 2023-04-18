#ifndef DOH_H
#define DOH_H

/**
 * struct dog - some info about dog
 * @name:First member
 * @age: Second member
 * @owner: Third member
 *
 * dog_t - typdef for struct dog
 */

typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void print_dog(struct dog *d);
dog_t *new_dog(char *name, float age, char *owner);
void free_dog(dog_t *d);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);

#endif
