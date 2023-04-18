#include "dog.h"
#include <stdlib.h>

/**
  * free_dog - This is a function
  * @d: param1
  */

void free_dog(dog_t *d)
{
	free(d->name);
	free(d->owner);
	free(d);
}
