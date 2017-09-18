#include <stdlib.h>
#include <stdio.h>


static void test(void *p1, void *p2, int p3)
{
    p1 = p1;
	    p2 = p2;
		    p3 = p3;
			}

			int main()
			{
			    void *p1 = (void*)1;
				    void *p2 = (void*)2;
					    int p3 = 3;

						    test(p1, p2, p3);

							    return 0;
								}
